#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_PARAMS 4
#define MAX_ITER 10000
#define TOL 1e-8
#define MAX_PUNTOS 100

typedef struct {
    double b[MAX_PARAMS];
    double chi2;
} Resultado;

typedef struct {
    double aw[MAX_PUNTOS];
    double Xe[MAX_PUNTOS];
    int n;
} Dataset;

double modelo_peleg(double aw, double b[]) {
    return b[0] * pow(aw, b[1]) + b[2] * pow(aw, b[3]);
}

double modelo_dlp(double aw, double b[]) {
    if (aw <= 0.0) aw = 1e-6;
    if (aw >= 1.0) aw = 1.0 - 1e-6;
    double x = log(-log(aw));
    return b[0] + b[1]*x + b[2]*x*x + b[3]*x*x*x;
}

double chi2_peleg(double b[], double aw[], double Xe[], int n) {
    double chi2 = 0.0;
    for (int i = 0; i < n; i++) {
        double pred = modelo_peleg(aw[i], b);
        double diff = Xe[i] - pred;
        chi2 += diff * diff;
    }
    return chi2;
}

double chi2_dlp(double b[], double aw[], double Xe[], int n) {
    double chi2 = 0.0;
    for (int i = 0; i < n; i++) {
        double pred = modelo_dlp(aw[i], b);
        double diff = Xe[i] - pred;
        chi2 += diff * diff;
    }
    return chi2;
}

void gradiente_numerico(double (*func)(double[], double[], double[], int), 
                       double b[], double grad[], 
                       double aw[], double Xe[], int n_data) {
    const double h = 1e-6;
    double b_temp[MAX_PARAMS];
    
    for (int j = 0; j < MAX_PARAMS; j++) {
        memcpy(b_temp, b, sizeof(b_temp));
        
        b_temp[j] += h;
        double f_plus = func(b_temp, aw, Xe, n_data);
        
        b_temp[j] = b[j] - h;
        double f_minus = func(b_temp, aw, Xe, n_data);
        
        grad[j] = (f_plus - f_minus) / (2.0 * h);
    }
}

void gradiente_descendente(double (*func)(double[], double[], double[], int), 
                          double b[], 
                          double aw[], double Xe[], int n_data, 
                          double *chi2_final) {
    double learning_rate = 0.001;
    double grad[MAX_PARAMS];
    double chi2_prev = func(b, aw, Xe, n_data);
    
    for (int iter = 0; iter < MAX_ITER; iter++) {
        gradiente_numerico(func, b, grad, aw, Xe, n_data);
        
        for (int j = 0; j < MAX_PARAMS; j++) {
            b[j] -= learning_rate * grad[j];
        }
        
        double chi2_actual = func(b, aw, Xe, n_data);
        
        if (fabs(chi2_actual - chi2_prev) < TOL) {
            break;
        }
        
        if (chi2_actual > chi2_prev) {
            learning_rate *= 0.5;
        } else if (iter % 100 == 0) {
            learning_rate *= 0.95;
        }
        
        chi2_prev = chi2_actual;
    }
    
    *chi2_final = func(b, aw, Xe, n_data);
}

int leer_datos(const char* filename, Dataset* dataset) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: No se pudo abrir el archivo %s\n", filename);
        return -1;
    }
    
    char line[256];
    int count = 0;
    
    if (fgets(line, sizeof(line), file) == NULL) {
        fclose(file);
        return -1;
    }
    
    // Leer datos
    while (fgets(line, sizeof(line), file) != NULL && count < MAX_PUNTOS) {
        char type[50];
        int replicate, temperature;
        double aw, moisture_wet, moisture_dry;
        
        if (sscanf(line, "%49[^|]|%d|%d|%lf|%lf|%lf", 
                  type, &replicate, &temperature, &aw, &moisture_wet, &moisture_dry) == 6) {
            dataset->aw[count] = aw;
            dataset->Xe[count] = moisture_dry;  
            count++;
        }
    }
    
    dataset->n = count;
    fclose(file);
    
    printf("Leídos %d puntos de datos de %s\n", count, filename);
    return 0;
}

void ajustar_modelos(double aw[], double Xe[], int n, const char* nombre) {
    if (n == 0) {
        printf("%s | No hay datos para ajustar\n", nombre);
        return;
    }
    
    Resultado peleg, dlp;
    
    double b_peleg[MAX_PARAMS] = {1.0, 1.0, 1.0, 1.0};
    gradiente_descendente(chi2_peleg, b_peleg, aw, Xe, n, &peleg.chi2);
    memcpy(peleg.b, b_peleg, sizeof(b_peleg));
    
    double b_dlp[MAX_PARAMS] = {1.0, 0.1, 0.01, 0.001};
    gradiente_descendente(chi2_dlp, b_dlp, aw, Xe, n, &dlp.chi2);
    memcpy(dlp.b, b_dlp, sizeof(b_dlp));
    
    printf("%-30s | Peleg: (%.4f, %.4f, %.4f, %.4f)\n", 
           nombre, peleg.b[0], peleg.b[1], peleg.b[2], peleg.b[3]);
    printf("%-30s | DLP:   (%.4f, %.4f, %.4f, %.4f)\n", 
           "", dlp.b[0], dlp.b[1], dlp.b[2], dlp.b[3]);
    printf("Chi2 - Peleg: %.6f, DLP: %.6f\n", peleg.chi2, dlp.chi2);
    
    const char* mejor = (peleg.chi2 < dlp.chi2) ? "Peleg" : "DLP";
    printf("MEJOR MODELO: %s\n", mejor);
    printf("----------------------------------------------------------------\n");
}

int main() {
    printf("================================================================\n");
    printf("AJUSTE DE MODELOS POR GRADIENTE DESCENDENTE\n");
    printf("================================================================\n");
    
    // Lista de archivos a procesar
    const char* archivos[] = {
        "Experimental water adsorption isotherms.xlsx"  
    };
    
    const char* nombres[] = {
        "Roasted beans (25°C)"
    };
    
    int n_archivos = sizeof(archivos) / sizeof(archivos[0]);
    
    for (int i = 0; i < n_archivos; i++) {
        Dataset datos;
        if (leer_datos(archivos[i], &datos) == 0) {
            ajustar_modelos(datos.aw, datos.Xe, datos.n, nombres[i]);
        }
    }
    
    return 0;
}

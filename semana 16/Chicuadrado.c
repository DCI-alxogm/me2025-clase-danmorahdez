#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double calcular_humedad(double aw, double p1, double p2, double p3, double p4) {
    return p1 * pow(aw, p2) + p3 * pow(aw, p4);
}

double funcion_error(double *aw, double *humedad_exp, int num_datos,
                    double p1, double p2, double p3, double p4) {
    double error_total = 0.0;
    
    for (int i = 0; i < num_datos; i++) {
        double diferencia = humedad_exp[i] - calcular_humedad(aw[i], p1, p2, p3, p4);
        error_total += diferencia * diferencia;
    }
    
    return error_total;
}

int main() {
    srand((unsigned int)time(NULL));

    FILE *archivo = fopen("café.txt", "r");
    if (archivo == NULL) {
        printf("Error: No se puede abrir el archivo de datos\n");
        return -1;
    }

    double actividad_agua[5000];
    double humedad_equilibrio[5000];
    int contador_datos = 0;
    
    while (fscanf(archivo, "%lf %lf", 
                  &actividad_agua[contador_datos], 
                  &humedad_equilibrio[contador_datos]) == 2) {
        contador_datos++;
    }
    fclose(archivo);

    printf("Datos cargados: %d registros\n", contador_datos);

    double param1 = 1.0, param2 = 1.0, param3 = 1.0, param4 = 1.0;
    
    double mejor_param1 = param1, mejor_param2 = param2;
    double mejor_param3 = param3, mejor_param4 = param4;
    
    double mejor_error = funcion_error(actividad_agua, humedad_equilibrio, 
                                     contador_datos, param1, param2, param3, param4);

    const int iteraciones = 20000;
    
    for (int iter = 0; iter < iteraciones; iter++) {
        double nuevo_param1 = mejor_param1 + (rand()/(double)RAND_MAX - 0.5) * 2.0;
        double nuevo_param2 = mejor_param2 + (rand()/(double)RAND_MAX - 0.5) * 1.0;
        double nuevo_param3 = mejor_param3 + (rand()/(double)RAND_MAX - 0.5) * 2.0;
        double nuevo_param4 = mejor_param4 + (rand()/(double)RAND_MAX - 0.5) * 1.0;

        double error_actual = funcion_error(actividad_agua, humedad_equilibrio,
                                          contador_datos, nuevo_param1, nuevo_param2, 
                                          nuevo_param3, nuevo_param4);

        if (error_actual < mejor_error) {
            mejor_error = error_actual;
            mejor_param1 = nuevo_param1;
            mejor_param2 = nuevo_param2;
            mejor_param3 = nuevo_param3;
            mejor_param4 = nuevo_param4;
        }
    }

    printf("\nParametros optimos:\n");
    printf("p1 = %f\n", mejor_param1);
    printf("p2 = %f\n", mejor_param2);
    printf("p3 = %f\n", mejor_param3);
    printf("p4 = %f\n", mejor_param4);
    printf("Error minimo: %f\n", mejor_error);

    return 0;
}

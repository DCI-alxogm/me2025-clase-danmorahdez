#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Función para resolver con cualquier vector B
void resolverSistema(int Orden, float L[Orden][Orden], float U[Orden][Orden], float B[Orden]) {
    // Resolver Ly = B
    float Y[Orden];
    for (int i = 0; i < Orden; i++) {
        float suma = 0;
        for (int j = 0; j < i; j++) {
            suma += L[i][j] * Y[j];
        }
        Y[i] = (B[i] - suma) / L[i][i];
    }

    // Resolver Ux = y
    float X[Orden];
    for (int i = Orden - 1; i >= 0; i--) {
        float suma = 0;
        for (int j = i + 1; j < Orden; j++) {
            suma += U[i][j] * X[j];
        }
        X[i] = (Y[i] - suma) / U[i][i];
    }

    // Mostrar resultados
    printf("\nLas soluciones son:\n");
    char* variables[] = {"F_ant", "F_med", "F_post", "F_Gmin", "F_TFL", "J_x", "J_y"};
    for (int i = 0; i < Orden; i++) {
        printf("%s = %f\n", variables[i], X[i]);
    }
}

int main() {
    int Orden = 7;

    // Matriz de coeficientes y vector de valores separados
    float Matriz[7][7] = {
        {0.0129, 0.0275, 0.0402, 0.0275, 0.0154, 0, 0},
        {0.2588, 0.4226, 0.5736, 0.5000, 0.3420, 0, 1},
        {0.9659, 0.9063, 0.8192, 0.8660, 0.9397, 1, 0},
        {1.200, -1.000, 0.000, 0.000, 0.000, 0, 0},
        {-0.800, 0.000, 1.000, 0.000, 0.000, 0, 0},
        {-0.840, 0.000, 0.000, 1.000, 0.000, 0, 0},
        {-0.500, 0.000, 0.000, 0.000, 1.000, 0, 0}
    };

    float B[7] = {105, 700, 0, 0, 0, 0, 0};
    float L[7][7];
    float U[7][7];

    // Inicializar L y U
    for (int i = 0; i < Orden; i++) {
        for (int j = 0; j < Orden; j++) {
            if (i == j)
                L[i][j] = 1.0;
            else
                L[i][j] = 0.0;
            U[i][j] = 0.0;
        }
    }

    // Mostrar sistema
    printf("\nTu sistema de ecuaciones es: \n");
    for (int i = 0; i < Orden; i++) {
        for (int j = 0; j < Orden; j++) {
            printf("%.4f\t", Matriz[i][j]);
        }
        printf("| %.2f\n", B[i]);
    }

    // Factorización LU CON PIVOTEO
    for (int i = 0; i < Orden; i++) {
        // PIVOTEO: Buscar la fila con el máximo valor en la columna i
        int fila_max = i;
        float max_val = fabs(Matriz[i][i]);
        for (int k = i + 1; k < Orden; k++) {
            if (fabs(Matriz[k][i]) > max_val) {
                max_val = fabs(Matriz[k][i]);
                fila_max = k;
            }
        }
        
        // Intercambiar filas si es necesario
        if (fila_max != i) {
            printf("Intercambiando fila %d con fila %d\n", i, fila_max);
            for (int j = 0; j < Orden; j++) {
                // Intercambiar en Matriz
                float temp = Matriz[i][j];
                Matriz[i][j] = Matriz[fila_max][j];
                Matriz[fila_max][j] = temp;
                
                // Intercambiar en L (solo la parte ya calculada)
                if (j < i) {
                    temp = L[i][j];
                    L[i][j] = L[fila_max][j];
                    L[fila_max][j] = temp;
                }
            }
            // Intercambiar en B
            float temp = B[i];
            B[i] = B[fila_max];
            B[fila_max] = temp;
        }

        // Calcular U para la fila i
        for (int j = i; j < Orden; j++) {
            float suma = 0;
            for (int k = 0; k < i; k++) {
                suma += L[i][k] * U[k][j];
            }
            U[i][j] = Matriz[i][j] - suma;
        }

        // Calcular L para las filas debajo de i
        for (int j = i + 1; j < Orden; j++) {
            float suma = 0;
            for (int k = 0; k < i; k++) {
                suma += L[j][k] * U[k][i];
            }
            
            // Verificar que U[i][i] no sea cero antes de dividir
            if (fabs(U[i][i]) < 1e-10) {
                printf("Error: Elemento diagonal U[%d][%d] = %f es muy cercano a cero\n", i, i, U[i][i]);
                printf("El sistema puede no tener solución única\n");
                // Continuar pero con valor pequeño para evitar división por cero
                L[j][i] = (Matriz[j][i] - suma) / 1e-10;
            } else {
                L[j][i] = (Matriz[j][i] - suma) / U[i][i];
            }
        }
    }

    printf("\nMatriz L:\n");
    for (int i = 0; i < Orden; i++) {
        for (int j = 0; j < Orden; j++) {
            printf("%8.4f \t", L[i][j]);
        }
        printf("\n");
    }

    printf("\nMatriz U:\n");
    for (int i = 0; i < Orden; i++) {
        for (int j = 0; j < Orden; j++) {
            printf("%8.4f \t", U[i][j]);
        }
        printf("\n");
    }

    // Guardar matrices L y U para reutilizar
    float L_guardada[7][7];
    float U_guardada[7][7];
    for (int i = 0; i < Orden; i++) {
        for (int j = 0; j < Orden; j++) {
            L_guardada[i][j] = L[i][j];
            U_guardada[i][j] = U[i][j];
        }
    }

    // Resolver sistema inicial
    printf("\n--- SOLUCION INICIAL ---");
    resolverSistema(Orden, L_guardada, U_guardada, B);

    // Calcular determinante
    float mult = 1;
    for (int i = 0; i < Orden; i++) {
        mult = mult * U[i][i];
    }
    printf("El determinante es: %f \n", mult);
    if (fabs(mult) < 1e-10) {
        printf("ADVERTENCIA: El determinante es muy cercano a cero (%e)\n", mult);
        printf("La matriz puede ser singular o mal condicionada\n");
    }

    // Bucle para cambiar vector B
    char opcion;
    do {
        printf("\n¿Desea cambiar el vector B y resolver nuevamente? (s/n): ");
        scanf(" %c", &opcion);

        if (opcion == 's' || opcion == 'S') {
            printf("Ingrese el nuevo vector B:\n");
            float nuevo_B[7];
            for (int i = 0; i < Orden; i++) {
                printf("Valor b[%d]: ", i);
                scanf("%f", &nuevo_B[i]);
            }

            printf("\n--- SOLUCION CON NUEVO VECTOR B ---");
            printf("\nNuevo sistema:\n");
            for (int i = 0; i < Orden; i++) {
                for (int j = 0; j < Orden; j++) {
                    printf("%.4f\t", Matriz[i][j]);
                }
                printf("| %.2f\n", nuevo_B[i]);
            }

            // Reutilizar L y U guardadas
            resolverSistema(Orden, L_guardada, U_guardada, nuevo_B);
        }
    } while (opcion == 's' || opcion == 'S');

    return 0;
}
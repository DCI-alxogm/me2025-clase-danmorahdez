#include <stdio.h>
#include <stdlib.h>

int main() {
    int Orden;
    printf("Porfavor mencione el número de incógnitas\n");
    scanf("%d", &Orden);

    // Matriz de coeficientes y vector de valores separados
    float Matriz[Orden][Orden];
    float B[Orden];
    float L[Orden][Orden];
    float U[Orden][Orden];

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

    // Ingresar matriz de coeficientes
    printf("Porfavor digite los datos de la matriz de coeficientes:\n");
    for (int i = 0; i < Orden; i++) {
        for (int j = 0; j < Orden; j++) {
            printf("De el valor en la coordenada: [%d][%d]: ", i, j);
            scanf("%f", &Matriz[i][j]);
        }
    }

    // Ingresar vector B
    printf("Porfavor digite el vector de valores B:\n");
    for (int i = 0; i < Orden; i++) {
        printf("Valor b[%d]: ", i);
        scanf("%f", &B[i]);
    }

    // Mostrar sistema
    printf("\nTu sistema de ecuaciones es: \n");
    for (int i = 0; i < Orden; i++) {
        for (int j = 0; j < Orden; j++) {
            printf("%.2f\t", Matriz[i][j]);
        }
        printf("| %.2f\n", B[i]);
    }

/*
    // Factorización LU
    for (int i = 0; i < Orden; i++) {
        // Calcular U
        for (int j = i; j < Orden; j++) {
            float suma = 0;
            U[i][j] = Matriz[i][j] - suma;
        }
    }
*/

/*
    // Factorización LU
    for (int i = 0; i < Orden; i++) {
        // Calcular U
        for (int j = i; j < Orden; j++) {
            float suma = 0;
            for (int k = 0; k < i; k++) {
                suma += L[i][k] * U[k][j];
            }
            U[i][j] = Matriz[i][j] - suma;
        }
    }
*/

/*
    // Factorización LU
    for (int i = 0; i < Orden; i++) {
        // Calcular U
        for (int j = i; j < Orden; j++) {
            float suma = 0;
            for (int k = 0; k < i; k++) {
                suma += L[i][k] * U[k][j];
            }
            U[i][j] = Matriz[i][j] - suma;
        }

        // Calcular L
        for (int j = i + 1; j < Orden; j++) {
            float suma = 0;
            L[j][i] = (Matriz[j][i] - suma) / U[i][i];
        }
    }
*/

    // Factorización LU
    for (int i = 0; i < Orden; i++) {
        // Calcular U
        for (int j = i; j < Orden; j++) {
            float suma = 0;
            for (int k = 0; k < i; k++) {
                suma += L[i][k] * U[k][j];
            }
            U[i][j] = Matriz[i][j] - suma;
        }

        // Calcular L
        for (int j = i + 1; j < Orden; j++) {
            float suma = 0;
            for (int k = 0; k < i; k++) {
                suma += L[j][k] * U[k][i];
            }
            L[j][i] = (Matriz[j][i] - suma) / U[i][i];
        }
    }

    printf("\nMatriz L:\n");
    for (int i = 0; i < Orden; i++) {
        for (int j = 0; j < Orden; j++) {
            printf("%f \t", L[i][j]);
        }
        printf("\n");
    }

    printf("\nMatriz U:\n");
    for (int i = 0; i < Orden; i++) {
        for (int j = 0; j < Orden; j++) {
            printf("%f \t", U[i][j]);
        }
        printf("\n");
    }

/*
    // Guardar matrices L y U para reutilizar
    float L_guardada[Orden][Orden];
    float U_guardada[Orden][Orden];
    for (int i = 0; i < Orden; i++) {
        for (int j = 0; j < Orden; j++) {
            L_guardada[i][j] = L[i][j];
        }
    }
*/

    // Guardar matrices L y U para reutilizar
    float L_guardada[Orden][Orden];
    float U_guardada[Orden][Orden];
    for (int i = 0; i < Orden; i++) {
        for (int j = 0; j < Orden; j++) {
            L_guardada[i][j] = L[i][j];
            U_guardada[i][j] = U[i][j];
        }
    }

/*
    // Función para resolver con cualquier vector B
    void resolverSistema(float L[Orden][Orden], float U[Orden][Orden], float B[Orden]) {
        // Resolver Ly = B
        float Y[Orden];
        for (int i = 0; i < Orden; i++) {
            float suma = 0;
            Y[i] = (B[i] - suma) / L[i][i];
        }
    }
*/

/*
    // Función para resolver con cualquier vector B
    void resolverSistema(float L[Orden][Orden], float U[Orden][Orden], float B[Orden]) {
        // Resolver Ly = B
        float Y[Orden];
        for (int i = 0; i < Orden; i++) {
            float suma = 0;
            for (int j = 0; j < i; j++) {
                suma += L[i][j] * Y[j];
            }
            Y[i] = (B[i] - suma) / L[i][i];
        }
    }
*/

/*
    // Función para resolver con cualquier vector B
    void resolverSistema(float L[Orden][Orden], float U[Orden][Orden], float B[Orden]) {
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
            X[i] = (Y[i] - suma) / U[i][i];
        }
    }
*/

    // Función para resolver con cualquier vector B
    void resolverSistema(float L[Orden][Orden], float U[Orden][Orden], float B[Orden]) {
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
        for (int i = 0; i < Orden; i++) {
            printf("x%d = %f\n", i + 1, X[i]);
        }
    }

    // Resolver sistema inicial
    printf("\n--- SOLUCION INICIAL ---");
    resolverSistema(L_guardada, U_guardada, B);

/*
    // Calcular determinante
    float mult = 1;
    for (int i = 0; i < Orden; i++) {
        mult = mult * U[i][i];
    }
*/

    // Calcular determinante
    float mult = 1;
    for (int i = 0; i < Orden; i++) {
        mult = mult * U[i][i];
    }
    printf("El determinante es: %f \n", mult);
    if (mult < 1) {
        printf("Advertencia, el determinante tiene un valor muy bajo (<1)\n");
    }

/*
    // Bucle para cambiar vector B
    char opcion;
    do {
        printf("\n¿Desea cambiar el vector B y resolver nuevamente? (s/n): ");
        scanf(" %c", &opcion);
    } while (opcion == 's' || opcion == 'S');
*/

/*
    // Bucle para cambiar vector B
    char opcion;
    do {
        printf("\n¿Desea cambiar el vector B y resolver nuevamente? (s/n): ");
        scanf(" %c", &opcion);

        if (opcion == 's' || opcion == 'S') {
            printf("Ingrese el nuevo vector B:\n");
            float nuevo_B[Orden];
            for (int i = 0; i < Orden; i++) {
                printf("Valor b[%d]: ", i);
                scanf("%f", &nuevo_B[i]);
            }
        }
    } while (opcion == 's' || opcion == 'S');
*/

    // Bucle para cambiar vector B
    char opcion;
    do {
        printf("\n¿Desea cambiar el vector B y resolver nuevamente? (s/n): ");
        scanf(" %c", &opcion);

        if (opcion == 's' || opcion == 'S') {
            printf("Ingrese el nuevo vector B:\n");
            float nuevo_B[Orden];
            for (int i = 0; i < Orden; i++) {
                printf("Valor b[%d]: ", i);
                scanf("%f", &nuevo_B[i]);
            }

            printf("\n--- SOLUCION CON NUEVO VECTOR B ---");
            printf("\nNuevo sistema:\n");
            for (int i = 0; i < Orden; i++) {
                for (int j = 0; j < Orden; j++) {
                    printf("%.2f\t", Matriz[i][j]);
                }
                printf("| %.2f\n", nuevo_B[i]);
            }

            // Reutilizar L y U guardadas
            resolverSistema(L_guardada, U_guardada, nuevo_B);
        }
    } while (opcion == 's' || opcion == 'S');

    return 0;
}

}


#include <stdio.h>
#include <math.h>

int main(){
  
  int Orden = 7;

  printf("Porfavor digite los datos de la matriz");

  float Matriz[7][8] = {
    {0.0129, 0.0275, 0.0402, 0.0275, 0.0154, 0, 0, 105},
    {0.2588, 0.4226, 0.5736, 0.5000, 0.3420, 0, 1, 700},
    {0.9659, 0.9063, 0.8192, 0.8660, 0.9397, 1, 0, 0},
    {1.200, -1.000, 0.000, 0.000, 0.000, 0, 0, 0},
    {-0.800, 0.000, 1.000, 0.000, 0.000, 0, 0, 0},
    {-0.840, 0.000, 0.000, 1.000, 0.000, 0, 0, 0},
    {-0.500, 0.000, 0.000, 0.000, 1.000, 0, 0, 0}
  };

  printf("Tu matriz es: \n");

  for(int i = 0; i < Orden; i++){
    for (int j = 0; j < Orden + 1; j++){
      printf("%8.4f \t",Matriz[i][j]);
    }
    printf("\n");
  }

  float MatrizIntermedia[7][8];
  
  for(int i = 0; i < Orden; i++){
    for (int j = 0; j < Orden + 1; j++){
      MatrizIntermedia[i][j] = Matriz[i][j];
    }
  }
  
  // Eliminación Gaussiana con pivoteo
  for(int j = 0; j < Orden-1; j++ ){
    // Pivoteo
    int fila_max = j;
    float max_val = fabs(MatrizIntermedia[j][j]);
    for(int i = j+1; i < Orden; i++){
      if(fabs(MatrizIntermedia[i][j]) > max_val){
        max_val = fabs(MatrizIntermedia[i][j]);
        fila_max = i;
      }
    }
    
    if(fila_max != j){
      printf("Intercambiando fila %d con fila %d\n", j, fila_max);
      for(int k = 0; k < Orden + 1; k++){
        float temp = MatrizIntermedia[j][k];
        MatrizIntermedia[j][k] = MatrizIntermedia[fila_max][k];
        MatrizIntermedia[fila_max][k] = temp;
      }
    }
    
    // Eliminación
    for(int i = j+1; i < Orden; i++){
      if(fabs(MatrizIntermedia[j][j]) < 1e-10) {
        printf("Advertencia: Pivote cercano a cero en [%d][%d]\n", j, j);
        continue;
      }
      float factor = MatrizIntermedia[i][j] / MatrizIntermedia[j][j];
      for(int k = j; k < Orden + 1; k++){ 
        MatrizIntermedia[i][k] = MatrizIntermedia[i][k] - (MatrizIntermedia[j][k] * factor);
      }
    }
  }

  printf("\nMatriz después de eliminación:\n");
  for(int i = 0; i < Orden; i++){
    for (int j = 0; j < Orden + 1; j++){
      printf("%8.4f \t",MatrizIntermedia[i][j]);
    }
    printf("\n");
  }

  //Calcular la determinante
  float mult = 1;
  for(int i = 0; i < Orden; i++){
    mult = mult * MatrizIntermedia[i][i];
  }
  printf("\nEl determinante es: %f \n",mult);
  if(fabs(mult) < 1e-10){
    printf("ADVERTENCIA: El determinante es muy cercano a cero\n");
    printf("La matriz puede ser singular\n");
  }

  // Sustitución hacia atrás
  float X[7];
  for(int i = Orden-1; i >= 0; i--){
    float suma = 0;
    for(int j = i+1; j < Orden; j++){
      suma += MatrizIntermedia[i][j] * X[j];
    }
    if(fabs(MatrizIntermedia[i][i]) < 1e-10) {
      printf("Error: División por cero en fila %d\n", i);
      X[i] = 0;
    } else {
      X[i] = (MatrizIntermedia[i][Orden] - suma) / MatrizIntermedia[i][i];
    }
  }
  
  // Mostrar resultados
  printf("\nLas soluciones son:\n");
  char* variables[] = {"F_ant", "F_med", "F_post", "F_Gmin", "F_TFL", "J_x", "J_y"};
  for(int i = 0; i < Orden; i++){
    printf("%s = %f\n", variables[i], X[i]);
  } 

  return 0;
}
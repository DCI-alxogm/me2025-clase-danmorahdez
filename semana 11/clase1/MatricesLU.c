#include <stdio.h>

int main(){
  
  int Orden;
  printf("Porfavor mencione el número de incógnitas\n");
  scanf("%d",&Orden);

  printf("Porfavor digite los datos de la matriz");

  float Matriz[Orden+1][Orden];
  float L[Orden][Orden];
  float U[Orden][Orden];

  // Inicializar L y U
  for(int i = 0; i < Orden; i++){
    for(int j = 0; j < Orden; j++){
      if(i == j)
        L[i][j] = 1.0;
      else
        L[i][j] = 0.0;
      U[i][j] = 0.0;
    }
  }

  for(int i = 0; i < Orden; i++){
    for (int j = 0; j < Orden + 1; j++){
      printf("De el valor en la coordenada: [%d] [%d]",j,i);
      scanf("%f", &Matriz[j][i]);
    }
  }

  printf("Tu matriz es: \n");
  for(int i = 0; i < Orden; i++){
    for (int j = 0; j < Orden + 1; j++){
      printf("%f \t",Matriz[j][i]);
    }
    printf("\n");
  }
  
  /*
  int Orden = 4;
  
  float Matriz[5][4] = {
    {2,1,3,1},{1,3,-1,1},{1,-1,2,-1},{1,2,-1,3},{10,12,8,14}
  };
  */

//Factorización LU
  for(int i = 0; i < Orden; i++){
    // Calcular U
    for(int j = i; j < Orden; j++){
      float suma = 0;
      for(int k = 0; k < i; k++){
        suma += L[i][k] * U[k][j];
      }
      U[i][j] = Matriz[j][i] - suma;
    }
    
    // Calcular L
    for(int j = i+1; j < Orden; j++){
      float suma = 0;
      for(int k = 0; k < i; k++){
        suma += L[j][k] * U[k][i];
      }
      L[j][i] = (Matriz[i][j] - suma) / U[i][i];
    }
  }

  printf("\nMatriz L:\n");
  for(int i = 0; i < Orden; i++){
    for (int j = 0; j < Orden; j++){
      printf("%f \t",L[i][j]);
    }
    printf("\n");
  }

  printf("\nMatriz U:\n");
  for(int i = 0; i < Orden; i++){
    for (int j = 0; j < Orden; j++){
      printf("%f \t",U[i][j]);
    }
    printf("\n");
  }

//Resolver Ly = b
  float Y[Orden];
  for(int i = 0; i < Orden; i++){
    float suma = 0;
    for(int j = 0; j < i; j++){
      suma += L[i][j] * Y[j];
    }
    Y[i] = (Matriz[Orden][i] - suma) / L[i][i];
  }

//Resolver Ux = y
  float X[Orden];
  for(int i = Orden-1; i >= 0; i--){
    float suma = 0;
    for(int j = i+1; j < Orden; j++){
      suma += U[i][j] * X[j];
    }
    X[i] = (Y[i] - suma) / U[i][i];
  }

// Mostrar resultados
  printf("\nLas soluciones son:\n");
  for(int i = 0; i < Orden; i++){
    printf("x%d = %f\n", i+1, X[i]);
  }

//Calcular la determinante
  float mult = 1;
  for(int i = 0; i < Orden; i++){
    mult = mult * U[i][i];
  }
  printf("El determinante es: %f \n",mult);
  if(mult<1){
    printf("Advertencia, el determinante tiene un valor muy bajo (<1)");
  }

}

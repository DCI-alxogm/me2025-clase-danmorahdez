#include <stdio.h>
#include <math.h>

int main(){
  
  int Orden;
  printf("Porfavor mencione el número de incógnitas\n");
  scanf("%d",&Orden);

  printf("Porfavor digite los datos de la matriz\n");

  // Cambiar la estructura para almacenar por filas
  float Matriz[Orden][Orden+1];

  for(int i = 0; i < Orden; i++){
    for (int j = 0; j < Orden + 1; j++){
      printf("De el valor en la coordenada: [%d] [%d]: ",i,j);
      scanf("%f", &Matriz[i][j]);
    }
  }

  printf("Tu matriz es: \n");
  for(int i = 0; i < Orden; i++){
    for (int j = 0; j < Orden + 1; j++){
      printf("%f \t",Matriz[i][j]);
    }
    printf("\n");
  }

//Gauss-Seidel
  float X[Orden];
  float X_anterior[Orden];
  int iteraciones = 100;
  float tolerancia = 0.0001;
  
  //Valores iniciales
  for(int i = 0; i < Orden; i++){
    X[i] = 0;
    X_anterior[i] = 0;
  }

  int convergio = 0;
  for(int iter = 0; iter < iteraciones; iter++){
    //Copiar valores anteriores
    for(int i = 0; i < Orden; i++){
      X_anterior[i] = X[i];
    }
    
    //Calcular nuevos valores
    for(int i = 0; i < Orden; i++){
      float suma = 0;
      for(int j = 0; j < Orden; j++){
        if(j != i){
          suma += Matriz[i][j] * X[j];
        }
      }
      // Verificar que no haya división por cero
      if(Matriz[i][i] == 0){
        printf("Error: Elemento diagonal cero en fila %d\n", i+1);
        return 1;
      }
      X[i] = (Matriz[i][Orden] - suma) / Matriz[i][i];
    }
    
    //Verificar convergencia
    float error = 0;
    for(int i = 0; i < Orden; i++){
      error += fabs(X[i] - X_anterior[i]);
    }
    
    if(error < tolerancia){
      printf("Convergio en %d iteraciones\n", iter+1);
      convergio = 1;
      break;
    }
  }

  if(!convergio){
    printf("No convergio después de %d iteraciones\n", iteraciones);
  }

// Mostrar resultados
  printf("\nLas soluciones son:\n");
  for(int i = 0; i < Orden; i++){
    printf("x%d = %f\n", i+1, X[i]);
  }

//Verificar diagonal dominante
  int dominante = 1;
  for(int i = 0; i < Orden; i++){
    float suma = 0;
    for(int j = 0; j < Orden; j++){
      if(j != i){
        suma += fabs(Matriz[i][j]);
      }
    }
    if(fabs(Matriz[i][i]) <= suma){
      dominante = 0;
      printf("Advertencia: La matriz no es diagonalmente dominante en fila %d\n", i+1);
    }
  }
  
  if(dominante){
    printf("La matriz es diagonalmente dominante\n");
  }

  return 0;
}
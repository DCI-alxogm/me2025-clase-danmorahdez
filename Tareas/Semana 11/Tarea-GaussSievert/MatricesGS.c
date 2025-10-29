#include <stdio.h>
#include <math.h>

int main(){
  
  int Orden;
  printf("Porfavor mencione el número de incógnitas\n");
  scanf("%d",&Orden);

  printf("Porfavor digite los datos de la matriz");

  float Matriz[Orden+1][Orden];

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

/*
  for(int iter = 0; iter < iteraciones; iter++){
    //Copiar valores anteriores
    for(int i = 0; i < Orden; i++){
      X_anterior[i] = X[i];
    }
  }
*/

/*
  for(int iter = 0; iter < iteraciones; iter++){
    //Copiar valores anteriores
    for(int i = 0; i < Orden; i++){
      X_anterior[i] = X[i];
    }
    
    //Calcular nuevos valores
    for(int i = 0; i < Orden; i++){
      float suma = 0;
      X[i] = (Matriz[Orden][i] - suma) / Matriz[i][i];
    }
  }
*/

/*
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
          suma += Matriz[j][i] * X[j];
        }
      }
      X[i] = (Matriz[Orden][i] - suma) / Matriz[i][i];
    }
  }
*/

/*
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
          suma += Matriz[j][i] * X[j];
        }
      }
      X[i] = (Matriz[Orden][i] - suma) / Matriz[i][i];
    }
    
    //Verificar convergencia
    float error = 0;
    for(int i = 0; i < Orden; i++){
      error += fabs(X[i] - X_anterior[i]);
    }
  }
*/

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
          suma += Matriz[j][i] * X[j];
        }
      }
      X[i] = (Matriz[Orden][i] - suma) / Matriz[i][i];
    }
    
    //Verificar convergencia
    float error = 0;
    for(int i = 0; i < Orden; i++){
      error += fabs(X[i] - X_anterior[i]);
    }
    
    if(error < tolerancia){
      printf("Convergio en %d iteraciones\n", iter+1);
      break;
    }
  }

// Mostrar resultados
  printf("\nLas soluciones son:\n");
  for(int i = 0; i < Orden; i++){
    printf("x%d = %f\n", i+1, X[i]);
  }

/*
  int dominante = 1;
  for(int i = 0; i < Orden; i++){
    float suma = 0;
  }
*/

/*
  int dominante = 1;
  for(int i = 0; i < Orden; i++){
    float suma = 0;
    for(int j = 0; j < Orden; j++){
      if(j != i){
        suma += fabs(Matriz[j][i]);
      }
    }
  }
*/

/*
  int dominante = 1;
  for(int i = 0; i < Orden; i++){
    float suma = 0;
    for(int j = 0; j < Orden; j++){
      if(j != i){
        suma += fabs(Matriz[j][i]);
      }
    }
    if(fabs(Matriz[i][i]) <= suma){
      dominante = 0;
    }
  }
*/

//Verificar diagonal dominante
  int dominante = 1;
  for(int i = 0; i < Orden; i++){
    float suma = 0;
    for(int j = 0; j < Orden; j++){
      if(j != i){
        suma += fabs(Matriz[j][i]);
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

}

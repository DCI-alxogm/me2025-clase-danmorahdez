#include <stdio.h>

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

/*
  float b = Matriz[0][1];
  for(int k = 0; k < Orden +1; k++){ 
    Matriz[k][1] = Matriz[k][1]-(Matriz[k][0]*b)/Matriz[0][0];
  }
*/
/*
  for(int i = 0; i < Orden-1; i++){
    float aux = Matriz[0][i+1]/Matriz[0][0];
    for(int k = 0; k < Orden +1; k++){ 
      Matriz[k][i+1] = Matriz[k][i+1]-(Matriz[k][0]*aux);
    }
  }
*/

  float MatrizIntermedia[Orden+1][Orden];
  
  for(int i = 0; i < Orden; i++){
    for (int j = 0; j < Orden + 1; j++){
      MatrizIntermedia[j][i] = Matriz[j][i];
    }
  }
  
  for(int i = 0; i < Orden; i++){
    float max_val = 0;
    for(int j = 0; j < Orden; j++){
      if(MatrizIntermedia[j][i] > max_val){
        max_val = MatrizIntermedia[j][i];
      }
    }
    
    if(max_val > 1e-10){
      for(int j = 0; j < Orden + 1; j++){
        MatrizIntermedia[j][i] /= max_val;
      }
    }
  }
  
  printf("Matriz normalizada:\n");
  for(int i = 0; i < Orden; i++){
    for (int j = 0; j < Orden + 1; j++){
      printf("%f \t",MatrizIntermedia[j][i]);
    }
    printf("\n");
  }

//Superior
  for(int j = 0; j< Orden-1;j++ ){
    //Pivoteo
    int fila_max = j;
    for(int i = j+1; i < Orden; i++){
      if(MatrizIntermedia[j][i] > MatrizIntermedia[j][fila_max]){
        fila_max = i;
      }
    }
    
    if(fila_max != j){
      for(int k = 0; k < Orden + 1; k++){
        float temp = MatrizIntermedia[k][j];
        MatrizIntermedia[k][j] = MatrizIntermedia[k][fila_max];
        MatrizIntermedia[k][fila_max] = temp;
      }
    }
    
    for(int i = j; i < Orden-1; i++){
      float aux = MatrizIntermedia[j][i+1]/MatrizIntermedia[j][j];
      //printf("%f / %f \n",MatrizIntermedia[j][i+1],MatrizIntermedia[j][j]);
      for(int k = j; k < Orden +1; k++){ 
        MatrizIntermedia[k][i+1] = MatrizIntermedia[k][i+1]-(MatrizIntermedia[k][j]*aux);
      }
  }
  }

  printf("Tu nueva matriz es:\n");
  for(int i = 0; i < Orden; i++){
    for (int j = 0; j < Orden + 1; j++){
      printf("%f \t",MatrizIntermedia[j][i]);
    }
    printf("\n");
  }

  //Calcular la determinante

  float mult = 1;
  for(int i = Orden-1;i > -1;i--){
    mult = mult*MatrizIntermedia[i][i];
  }
  printf("El determinante es: %f \n",mult);
  if(mult<1){
    printf("Advertencia, el determinante es tiene un valor muy bajo (<1)");
  }

    //De aquí debo de despejar el resultado
  float R[Orden];
  
  for(int i = Orden-1; i > -1; i--){
    float suma = 0;
    for(int j = i+1; j < Orden; j++){
      suma += MatrizIntermedia[j][i] * R[j];
    }
    R[i] = (MatrizIntermedia[Orden][i] - suma) / MatrizIntermedia[i][i];
  }
  
  // Mostrar resultados
  printf("\nLas soluciones son:\n");
  for(int i = 0; i < Orden; i++){
    printf("x%d = %f\n", i+1, R[i]);
  } 

//Inferior
/*
  float aux = MatrizIntermedia[3][2]/MatrizIntermedia[3][3];
  printf("%f \n",aux);
  for(int k = Orden; k >-1; k--){ 
    MatrizIntermedia[k][2] = MatrizIntermedia[k][2]-(MatrizIntermedia[k][3]*aux);
  }
*/
/*
  for(int j = Orden-2; j > -1; j--){
    float aux = MatrizIntermedia[3][j]/MatrizIntermedia[3][3];
    printf("%f \n",aux);
    for(int k = Orden; k >-1; k--){ 
      MatrizIntermedia[k][j] = MatrizIntermedia[k][j]-(MatrizIntermedia[k][3]*aux);
    }
  }
*/
  for(int m = Orden-1;m>-1;m--){
    //printf("%d \n",m);
    for(int j = m-1; j > -1; j--){
      float aux = MatrizIntermedia[m][j]/MatrizIntermedia[m][m];
      //printf("%f \n",aux);
      for(int k = Orden; k >-1; k--){ 
        MatrizIntermedia[k][j] = MatrizIntermedia[k][j]-(MatrizIntermedia[k][m]*aux);
      }
    }
  }

  printf("Tu matriz final es:\n");
  for(int i = 0; i < Orden; i++){
    for (int j = 0; j < Orden + 1; j++){
      printf("%f \t",MatrizIntermedia[j][i]);
    }
    printf("\n");
  }

  float X[Orden];
  printf("Resultados: \n");
  for(int i = 0; i<Orden;i++){
    X[i]=MatrizIntermedia[Orden][i]/MatrizIntermedia[i][i];
    //printf("%f \n",MatrizIntermedia[Orden][i]);
    printf("X[%d] = %f \n",i,X[i]);
  }

}

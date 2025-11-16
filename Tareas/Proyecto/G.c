#include <stdio.h>

int main(){
  
  int Orden = 7;

  printf("Porfavor digite los datos de la matriz");

  float Matriz[7][8] = {
    {0.0129, 0.0275, 0.0402, 0.0275, 0.0154, 0, 0, 105},
    {0.2588, 0.4226, 0.5736, 0.5000, 0.3420, 0, 1, 700},
    {0.9659, 0.9063, 0.8192, 0.8660, 0.9397, 1, 0, 0},
    {1.000, -1.200, 0.000, 0.000, 0.000, 0, 0, 0},
    {-0.800, 0.000, 1.000, 0.000, 0.000, 0, 0, 0},
    {-0.840, 0.000, 0.000, 1.000, 0.000, 0, 0, 0},
    {-0.500, 0.000, 0.000, 0.000, 1.000, 0, 0, 0}
  };

  printf("Tu matriz es: \n");

  for(int i = 0; i < Orden; i++){
    for (int j = 0; j < Orden + 1; j++){
      printf("%f \t",Matriz[i][j]);
    }
    printf("\n");
  }
  
  /*
  int Orden = 4;
  
  float Matriz[4][5] = {
    {2,1,3,1,10},{1,3,-1,1,12},{1,-1,2,-1,8},{1,2,-1,3,14}
  };
  */

/*
  float b = Matriz[1][0];
  for(int k = 0; k < Orden +1; k++){ 
    Matriz[1][k] = Matriz[1][k]-(Matriz[0][k]*b)/Matriz[0][0];
  }
*/
/*
  for(int i = 0; i < Orden-1; i++){
    float aux = Matriz[i+1][0]/Matriz[0][0];
    for(int k = 0; k < Orden +1; k++){ 
      Matriz[i+1][k] = Matriz[i+1][k]-(Matriz[0][k]*aux);
    }
  }
*/

  float MatrizIntermedia[7][8];
  
  for(int i = 0; i < Orden; i++){
    for (int j = 0; j < Orden + 1; j++){
      MatrizIntermedia[i][j] = Matriz[i][j];
    }
  }
  
  for(int i = 0; i < Orden; i++){
    float max_val = 0;
    for(int j = 0; j < Orden; j++){
      if(MatrizIntermedia[i][j] > max_val){
        max_val = MatrizIntermedia[i][j];
      }
    }
    
    if(max_val > 1e-10){
      for(int j = 0; j < Orden + 1; j++){
        MatrizIntermedia[i][j] /= max_val;
      }
    }
  }
  
  printf("Matriz normalizada:\n");
  for(int i = 0; i < Orden; i++){
    for (int j = 0; j < Orden + 1; j++){
      printf("%f \t",MatrizIntermedia[i][j]);
    }
    printf("\n");
  }

//Superior
  for(int j = 0; j< Orden-1;j++ ){
    //Pivoteo
    int fila_max = j;
    for(int i = j+1; i < Orden; i++){
      if(MatrizIntermedia[i][j] > MatrizIntermedia[fila_max][j]){
        fila_max = i;
      }
    }
    
    if(fila_max != j){
      for(int k = 0; k < Orden + 1; k++){
        float temp = MatrizIntermedia[j][k];
        MatrizIntermedia[j][k] = MatrizIntermedia[fila_max][k];
        MatrizIntermedia[fila_max][k] = temp;
      }
    }
    
    for(int i = j+1; i < Orden; i++){
      float aux = MatrizIntermedia[i][j]/MatrizIntermedia[j][j];
      for(int k = j; k < Orden +1; k++){ 
        MatrizIntermedia[i][k] = MatrizIntermedia[i][k]-(MatrizIntermedia[j][k]*aux);
      }
  }
  }

  printf("Tu nueva matriz es:\n");
  for(int i = 0; i < Orden; i++){
    for (int j = 0; j < Orden + 1; j++){
      printf("%f \t",MatrizIntermedia[i][j]);
    }
    printf("\n");
  }

  //Calcular la determinante

  float mult = 1;
  for(int i = 0;i < Orden;i++){
    mult = mult*MatrizIntermedia[i][i];
  }
  printf("El determinante es: %f \n",mult);
  if(mult<1){
    printf("Advertencia, el determinante es tiene un valor muy bajo (<1)");
  }

    //De aquí debo de despejar el resultado
  float R[7];
  
  for(int i = Orden-1; i > -1; i--){
    float suma = 0;
    for(int j = i+1; j < Orden; j++){
      suma += MatrizIntermedia[i][j] * R[j];
    }
    R[i] = (MatrizIntermedia[i][Orden] - suma) / MatrizIntermedia[i][i];
  }
  
  // Mostrar resultados
  printf("\nLas soluciones son:\n");
  char* variables[] = {"F_ant", "F_med", "F_post", "F_Gmin", "F_TFL", "J_x", "J_y"};
  for(int i = 0; i < Orden; i++){
    printf("%s = %f\n", variables[i], R[i]);
  } 

//Inferior
/*
  float aux = MatrizIntermedia[2][3]/MatrizIntermedia[3][3];
  printf("%f \n",aux);
  for(int k = 0; k < Orden +1; k++){ 
    MatrizIntermedia[2][k] = MatrizIntermedia[2][k]-(MatrizIntermedia[3][k]*aux);
  }
*/
/*
  for(int j = Orden-2; j > -1; j--){
    float aux = MatrizIntermedia[j][3]/MatrizIntermedia[3][3];
    printf("%f \n",aux);
    for(int k = 0; k < Orden +1; k++){ 
      MatrizIntermedia[j][k] = MatrizIntermedia[j][k]-(MatrizIntermedia[3][k]*aux);
    }
  }
*/
  for(int m = Orden-1;m>-1;m--){
    for(int j = m-1; j > -1; j--){
      float aux = MatrizIntermedia[j][m]/MatrizIntermedia[m][m];
      for(int k = 0; k < Orden +1; k++){ 
        MatrizIntermedia[j][k] = MatrizIntermedia[j][k]-(MatrizIntermedia[m][k]*aux);
      }
    }
  }

  printf("Tu matriz final es:\n");
  for(int i = 0; i < Orden; i++){
    for (int j = 0; j < Orden + 1; j++){
      printf("%f \t",MatrizIntermedia[i][j]);
    }
    printf("\n");
  }

  float X[7];
  printf("Resultados: \n");
  for(int i = 0; i<Orden;i++){
    X[i]=MatrizIntermedia[i][Orden]/MatrizIntermedia[i][i];
    printf("X[%d] = %f \n",i,X[i]);
  }

}
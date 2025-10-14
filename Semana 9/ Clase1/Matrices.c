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
  for(int j = 0; j< Orden-1;j++ ){
    for(int i = j; i < Orden-1; i++){
      float aux = Matriz[j][i+1]/Matriz[j][j];
      printf("%f / %f \n",Matriz[j][i+1],Matriz[j][j]);
      for(int k = j; k < Orden +1; k++){ 
        Matriz[k][i+1] = Matriz[k][i+1]-(Matriz[k][j]*aux);
      }
  }
  }

  printf("Tu nueva matriz es:\n");
  for(int i = 0; i < Orden; i++){
    for (int j = 0; j < Orden + 1; j++){
      printf("%f \t",Matriz[j][i]);
    }
    printf("\n");
  }
}

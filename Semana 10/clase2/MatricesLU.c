#include <stdio.h>

int main(){
  /*
  int Orden;
  printf("Porfavor mencione el número de incógnitas\n");
  scanf("%d",&Orden);

  printf("Porfavor digite los datos de la matriz");

  float Matriz[Orden+1][Orden];
*/

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
  int Orden = 3;

  float Matriz[4][3] = {{3,-0.1,-0.2,7.85},{0.1,7,-0.3,-19.3},{0.3,-0.2,10,71.4}}

  for(int m = Orden-1;m>-1;m--){
    //printf("%d \n",m);
    for(int j = m-1; j > -1; j--){
      float aux = Matriz[m][j]/Matriz[m][m];
      //printf("%f \n",aux);
      for(int k = Orden; k >-1; k--){ 
        Matriz[k][j] = Matriz[k][j]-(Matriz[k][m]*aux);
      }
    }
  }

  printf("Tu matriz es: \n");
  for(int i = 0; i < Orden; i++){
    for (int j = 0; j < Orden + 1; j++){
      printf("%f \t",Matriz[j][i]);
    }
    printf("\n");
  }
  }
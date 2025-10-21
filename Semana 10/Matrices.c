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
//Superior
  for(int j = 0; j< Orden-1;j++ ){
    //Pivoteo
    int fila_max = j;
    for(int i = j+1; i < Orden; i++){
      if(Matriz[j][i] > Matriz[j][fila_max]){
        fila_max = i;
      }
    }
    
    if(fila_max != j){
      for(int k = 0; k < Orden + 1; k++){
        float temp = Matriz[k][j];
        Matriz[k][j] = Matriz[k][fila_max];
        Matriz[k][fila_max] = temp;
      }
    }
    
    for(int i = j; i < Orden-1; i++){
      float aux = Matriz[j][i+1]/Matriz[j][j];
      //printf("%f / %f \n",Matriz[j][i+1],Matriz[j][j]);
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

  //Calcular la determinante

  float mult = 1;
  for(int i = Orden-1;i > -1;i--){
    mult = mult*Matriz[i][i];
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
      suma += Matriz[j][i] * R[j];
    }
    R[i] = (Matriz[Orden][i] - suma) / Matriz[i][i];
  }
  
  // Mostrar resultados
  printf("\nLas soluciones son:\n");
  for(int i = 0; i < Orden; i++){
    printf("x%d = %f\n", i+1, R[i]);
  } 

//Inferior
/*
  float aux = Matriz[3][2]/Matriz[3][3];
  printf("%f \n",aux);
  for(int k = Orden; k >-1; k--){ 
    Matriz[k][2] = Matriz[k][2]-(Matriz[k][3]*aux);
  }
*/
/*
  for(int j = Orden-2; j > -1; j--){
    float aux = Matriz[3][j]/Matriz[3][3];
    printf("%f \n",aux);
    for(int k = Orden; k >-1; k--){ 
      Matriz[k][j] = Matriz[k][j]-(Matriz[k][3]*aux);
    }
  }
*/
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



  printf("Tu matriz final es:\n");
  for(int i = 0; i < Orden; i++){
    for (int j = 0; j < Orden + 1; j++){
      printf("%f \t",Matriz[j][i]);
    }
    printf("\n");
  }

  float X[Orden];
  printf("Resultados: \n");
  for(int i = 0; i<Orden;i++){
    X[i]=Matriz[Orden][i]/Matriz[i][i];
    //printf("%f \n",Matriz[Orden][i]);
    printf("X[%d] = %f \n",i,X[i]);
  }

}
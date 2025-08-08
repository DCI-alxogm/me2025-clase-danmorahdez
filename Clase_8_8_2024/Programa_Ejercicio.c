#include<stdio.h>
#include<math.h>
int main(){
  float X[5];
  X[0] = 17;
  X[1] = 3;
  X[2] = 6;
  X[3] = 21;
  X[4] = 14;
printf("Parte 1: Imprimir números dentro de arreglos \n \n");

printf("%f\n",X[0]);
printf("%f\n",X[1]);
printf("%f\n",X[2]);
printf("%f\n",X[3]);
printf("%f\n \n",X[4]);

  float y;
printf("Parte 2: Realizar las funciones propuestas con cada valor de X \n \n");

printf("Funciones con valor x = 17\n");

printf("\n Función 1:\n");
y = pow((float)X[0],2);
printf("%f",y);

printf("\n Función 2:\n");
y = log((float)X[0] + 1);
printf("%f",y);

printf("\n Función 3:\n");
y = exp((float)X[0]) + cos((float)X[0]);
printf("%f",y);

printf("\n \n Funciones con valor x = 3\n");

printf("\n Función 1:\n");
y = pow((float)X[1],2);
printf("%f",y);

printf("\n Función 2:\n");
y = log((float)X[1] + 1);
printf("%f",y);

printf("\n Función 3:\n");
y = exp((float)X[1]) + cos((float)X[1]);
printf("%f",y);

printf("\n \n Funciones con valor x = 6\n");

printf("\n Función 1:\n");
y = pow((float)X[2],2);
printf("%f",y);

printf("\n Función 2:\n");
y = log((float)X[2] + 1);
printf("%f",y);

printf("\n Función 3:\n");
y = exp((float)X[2]) + cos((float)X[2]);
printf("%f",y);

printf("\n \n Funciones con valor x = 21\n");

printf("\n Función 1:\n");
y = pow((float)X[3],2);
printf("%f",y);

printf("\n Función 2:\n");
y = log((float)X[3] + 1);
printf("%f",y);

printf("\n Función 3:\n");
y = exp((float)X[3]) + cos((float)X[3]);
printf("%f",y);

printf("\n \n Funciones con valor x = 14\n");

printf("\n Función 1:\n");
y = pow((float)X[4],2);
printf("%f",y);

printf("\n Función 2:\n");
y = log((float)X[4] + 1);
printf("%f",y);

printf("\n Función 3:\n");
y = exp((float)X[4]) + cos((float)X[4]);
printf("%f",y);

}
#include <stdio.h>
#include <math.h>

int main(){
  float A, B, C;
  printf("Digite los valores de la función Ax**2 + Bx + c = 0 \n");
  printf("Valor de A ????");
  scanf("%f",&A);
  printf("Valor de B ????");
  scanf("%f",&B);
  printf("Valor de C ????");
  scanf("%f",&C);

  // Teorema de Bolzano

  /*Aplicando a una función producto punto en dos intervalo a y b, si 
  en el producto punto observamos que hay un cambio de signo entonces
  por el teorema sabemos que en nuestro intervalo hay una raíz*/
  float a,b;
  printf("Digite el intervalo: \nPunto a: ");
  scanf("%f", &a);
  printf("Punto b: ");
  scanf("%f", &b);

  //Calcular las funciones
  float f1, f2;

  f1 = A*pow(a,2) + B * a + C;
  f2 = A*pow(b,2) + B * b + C;
  while 



}

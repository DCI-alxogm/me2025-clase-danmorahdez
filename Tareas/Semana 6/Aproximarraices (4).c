#include <stdio.h>
#include <math.h>

int main(){
  
  //
  printf("Calcular las raices de la función: \n Sen(10x)-cos(3x)");

  float a,b;
  printf("Digite el intervalo: \nPunto a: ");
  scanf("%f", &a);
  printf("Punto b: ");
  scanf("%f", &b);

  //Calcular las funciones
  float f1, f2;

  f1 = sin(10*a)- cos(3*a);
  f2 = sin(10*b)- cos(3*b);
  
  float k, k_anterior, Error = 100, MaxEr;
  int n, nmax;
  if (f1 * f2 >= 0) {
    printf("Error: No hay cambio de signo en el intervalo [%f, %f]\n", a, b);
    printf("f(%f) = %f, f(%f) = %f\n", a, f1, b, f2);
    printf("El metodo de biseccion no puede aplicarse.\n");
  }
  else{
    MaxEr = 0.01;
    nmax = 100; 
    n = 0;
    k_anterior = a;     
    printf("\nIteracion\t   a\t\t   b\t\t   k\t\t  f(k)\t\t  Error\n");
    printf("--------------------------------------------------------------------------\n");
    
    while(Error > MaxEr && n < nmax){
      k = (a+b)/2;
      float fa = sin(10*a)- cos(3*a);
      float fk = sin(10*k)- cos(3*k);
      
      Error = fabs((k - k_anterior) / k);
      if ((fk = sin(10*k)- cos(3*k)) == 0){
        Error = 0;
      }
      printf("%d\t\t%.6f\t%.6f\t%.6f\t%.6f\t%.6f\n", n+1, a, b, k, fk, Error);
      
      if (fk * fa < 0) {
        b = k; 
      } else {
        a = k; 
      }
      
      k_anterior = k; 
      n++;
    }
    
    printf("\n--------------------------------------------------------------------------");
    printf("\nRESULTADO FINAL:\n");
    printf("Raiz aproximada: %.6f\n", k);
    printf("f(%.6f) = %.6f\n", k, sin(10*k)- cos(3*k));
    printf("Error final: %.6f\n", Error);
    printf("Iteraciones realizadas: %d\n", n);
  }
  
  return 0;
}
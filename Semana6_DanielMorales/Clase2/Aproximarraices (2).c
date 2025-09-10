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
      float fk = A*pow(k,2) + B * k + C;
      float fa = A*pow(a,2) + B * a + C;
      
      Error = fabs((k - k_anterior) / k);
      
      printf("%d\t\t%.6f\t%.6f\t%.6f\t%.6f\t%.6f\n", n+1, a, b, k, fk, (n>0) ? Error : 100.0);
      
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
    printf("f(%.6f) = %.6f\n", k, A*pow(k,2) + B * k + C);
    printf("Error final: %.6f\n", Error);
    printf("Iteraciones realizadas: %d\n", n);
  }
  
  return 0;
}
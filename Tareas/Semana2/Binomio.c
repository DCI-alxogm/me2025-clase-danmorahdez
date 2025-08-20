#include <stdio.h>
#include <math.h>


void func();

int main()
{
    func();   
}

void func()
{
  printf("Digite los valores del polinomio \n");
  printf("\n");
  printf("Digite el valor a: \n");

  float a;
  float b;
  float c;

  float x1;
  float x2;
  scanf("%f", &a);
  printf("Digite el valor b: \n");
  scanf("%f", &b);
  printf("Digite el valor c: \n");
  scanf("%f", &c);

  if (a==0){
    if (b==0){
      printf("Solución trivial");
    }
    else{
      x1 = -c/b;
      printf("La solución es: %f", x1);
    }

  }
  else{
    if(((b*b)-4*a*c)<0){
      printf("Las soluciones son imaginarias \n");
    }
    else{
      x1 = (b+sqrt((b*b)-4*a*c))/(2*a);
      x2 = (b-sqrt((b*b)-4*a*c))/(2*a);

      printf("x1 = %f , x2 = %f", x1,x2);
    }
  }

  printf("Volver a iniciar??? (1 = Sí, 0 = No)");
  int var1; 
  scanf("%d", &var1);

  if(var1 == 1)
  {
      func(); 
  }
  else
  {
      printf("Programa terminado");
  }
}
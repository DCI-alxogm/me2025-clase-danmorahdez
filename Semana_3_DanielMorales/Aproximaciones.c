#include <stdio.h>
#include <math.h>

void func();

int main()
{
    func();   
}

void func()
{
  printf("Introduzca un valor para la exponencial \n");
  printf("\n");

  float numero;
  scanf("%f", &numero);

  float e = exp(numero);
  
  float ec = 1;

  float Er = 100;
  while(Er>0.1){

    
  ec=ec+(pow(numero,1)/1);
  Er = (e-ec)*100;
  printf("%f",Er);

    
  }

  printf("Volver a iniciar??? (1 = Sí, 0 = No)");
  int var1; 
  scanf("%d \n", &var1);
  
  if(var1 == 1)
  {
      func(); 
  }
  else
  {
      printf("Programa terminado");
  }
}
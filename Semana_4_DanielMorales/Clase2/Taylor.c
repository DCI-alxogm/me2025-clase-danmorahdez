#include <stdio.h>
#include <math.h>

void func();

int main()
{
  func();   
}

void func()
{   
  printf("Cual es la función que va a usar??\n");
  printf("1.Exponencial (e**x)\n");
  printf("2.Coseno\n");
  printf("3.Seno\n");
  printf("4.Logaritmo natural\n");
  printf("5.Exponente (a**x)\n");
  
  int operacion;
  scanf("%d", &operacion);
  
  if (operacion == 1){
      printf("Introduzca un valor para la exponencial: ");
      float numero;
      scanf("%f", &numero);

      float e = exp(numero);
      float ec = 1.0;
      float termino = 1.0;
      int n = 1;
      float Er = 100.0;
      
      printf("\nCalculando e^%.2f usando serie de Taylor:\n", numero);
      while(Er > 0.1 && n < 100)
      {
          termino = termino * numero / n;
          ec = ec + termino;
          Er = fabs((e - ec) / e) * 100;
          n++;
          
          printf("Aproximacion: %f, Error: %f%%\n", ec, Er);
      }

      printf("\nValor real: %f\n", e);
      printf("Aproximacion final: %f\n", ec);
      printf("Error final: %f%%\n", Er);
      printf("Terminos usados: %d\n", n);
  }
  else if (operacion == 2) {
      // Coseno
      printf("Introduzca un valor para el coseno (en radianes): ");
      float x;
      scanf("%f", &x);
      
      float real = cos(x);
      float aprox = 1.0;
      float termino = 1.0;
      int n = 1;
      float Er = 100.0;
      
      printf("\nCalculando cos(%.2f) usando serie de Taylor:\n", x);
      while(Er > 0.1 && n < 100)
      {
          termino = termino * (-x * x) / ((2 * n - 1) * (2 * n));
          aprox = aprox + termino;
          Er = fabs((real - aprox) / real) * 100;
          n++;
          
          printf("Aproximacion: %f, Error: %f%%\n", aprox, Er);
      }

      printf("\nValor real: %f\n", real);
      printf("Aproximacion final: %f\n", aprox);
      printf("Error final: %f%%\n", Er);
      printf("Terminos usados: %d\n", n);
  }
  else if (operacion == 3) {
      // Seno
      printf("Introduzca un valor para el seno (en radianes): ");
      float x;
      scanf("%f", &x);
      
      float real = sin(x);
      float aprox = x;
      float termino = x;
      int n = 1;
      float Er = 100.0;
      
      printf("\nCalculando sin(%.2f) usando serie de Taylor:\n", x);
      while(Er > 0.1 && n < 100)
      {
          termino = termino * (-x * x) / ((2 * n) * (2 * n + 1));
          aprox = aprox + termino;
          Er = fabs((real - aprox) / real) * 100;
          n++;
          
          printf("Aproximacion: %f, Error: %f%%\n", aprox, Er);
      }

      printf("\nValor real: %f\n", real);
      printf("Aproximacion final: %f\n", aprox);
      printf("Error final: %f%%\n", Er);
      printf("Terminos usados: %d\n", n);
  }
  else if (operacion == 4) {
      // Logaritmo natural
      printf("Introduzca un valor para el logaritmo natural (x > 0): ");
      float x;
      scanf("%f", &x);
      
      if (x <= 0) {
          printf("Error: El logaritmo natural solo está definido para x > 0\n");
      }
      else {
          float real = log(x);
          float aprox = 0.0;
          float termino;
          int n = 1;
          float Er = 100.0;
          
          // Para mejor convergencia, usamos ln(x) = 2*[(x-1)/(x+1) + 1/3*((x-1)/(x+1))^3 + ...]
          float z = (x - 1) / (x + 1);
          float z_cuadrado = z * z;
          termino = z;
          aprox = 2 * termino;
          
          printf("\nCalculando ln(%.2f) usando serie de Taylor:\n", x);
          while(Er > 0.1 && n < 100)
          {
              termino = termino * z_cuadrado;
              float nuevo_termino = 2 * termino / (2 * n + 1);
              aprox = aprox + nuevo_termino;
              Er = fabs((real - aprox) / real) * 100;
              n++;
              
              printf("Aproximacion: %f, Error: %f%%\n", aprox, Er);
          }

          printf("\nValor real: %f\n", real);
          printf("Aproximacion final: %f\n", aprox);
          printf("Error final: %f%%\n", Er);
          printf("Terminos usados: %d\n", n);
      }
  }
  else if (operacion == 5) {
      // Exponente a^x
      printf("Introduzca la base (a): ");
      float a;
      scanf("%f", &a);
      printf("Introduzca el exponente (x): ");
      float x;
      scanf("%f", &x);
      
      float real = pow(a, x);
      // a^x = e^(x * ln(a))
      float ln_a = log(a);
      float exponente = x * ln_a;
      
      float ec = 1.0;
      float termino = 1.0;
      int n = 1;
      float Er = 100.0;
      
      printf("\nCalculando %.2f^%.2f usando serie de Taylor:\n", a, x);
      while(Er > 0.1 && n < 100)
      {
          termino = termino * exponente / n;
          ec = ec + termino;
          Er = fabs((real - ec) / real) * 100;
          n++;
          
          printf("Aproximacion: %f, Error: %f%%\n", ec, Er);
      }

      printf("\nValor real: %f\n", real);
      printf("Aproximacion final: %f\n", ec);
      printf("Error final: %f%%\n", Er);
      printf("Terminos usados: %d\n", n);
  }
  else {
      printf("Opción no válida\n");
  }

  printf("\nVolver a iniciar??? (1 = Si, 0 = No): ");
  int var1; 
  scanf("%d", &var1);
  
  if(var1 == 1)
  {
      func(); 
  }
  else
  {
      printf("Programa terminado\n");
  }
}
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
    float ec = 1.0;
    float termino = 1.0;
    int n = 1;
    
    float Er = 100.0;
    
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

    printf("Volver a iniciar??? (1 = Si, 0 = No)");
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
#include <stdio.h>
#include <float.h> 
#include <limits.h>


void func();

int main()
{
    func();   
}

void func()
{
    printf("Introduzca un número \n");
    printf("\n");

    int numero;
    scanf("%d", &numero);

    int var = numero % 2;

    if (var == 1)
    {
        printf("es impar \n");
    }
    else
    {
        printf("es par 0\n");
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
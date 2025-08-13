#include <stdio.h>
#include <float.h> 
#include <limits.h>

//este es un programa que imprime los limites de cada tipo de variable

int main( )
{
/*
Esta primera parte del programa trata sobre la cantidad mayor y 
menor representable en cada una de las variables. Por ejemplo, para una variable tipo "int"
se tiene un limite de +- 2147483647
*/
    printf("UINT_MAX = %u \n", UINT_MAX);
    printf("ShortINT_MAX = %i \n", SHRT_MAX);
    printf("ShortINT_MIN = %i \n", SHRT_MIN);
    printf("INT_MAX = %i \n", INT_MAX);
    printf("INT_MIN = %i \n", INT_MIN);
    printf("FLT_MIN      = %e\n", FLT_MIN);
    printf("FLT_MAX      = %e\n", FLT_MAX);
    printf("DBL_MIN      = %e\n", DBL_MIN);
    printf("DBL_MAX      = %e\n", DBL_MAX);
    printf("LDBL_MIN      = %Le\n",LDBL_MIN);
    printf("LDBL_MAX      = %Le\n",LDBL_MAX);
/*
Esta parte del codigo imprime la precisión y el último digito (despues del punto) que se toma como correcto.
*/
    printf("FLT_EPSILON  = %e\n", FLT_EPSILON);
    printf("DBL_EPSILON  = %e\n", DBL_EPSILON);
    printf("LBL_EPSILON  = %Le\n", LDBL_EPSILON);

    printf("FLT_DIG      = %d\n", FLT_DIG);
    printf("DBL_DIG      = %d\n", DBL_DIG);
    printf("LBDL_DIG      = %d\n", LDBL_DIG);
/*
Numero maximo de digitos que se puede representar en la "Mantis", es decir, lo que se puede añadir
antes del punto decimal de una variable tipo float, double, etc.
*/
    printf("FLT_MANT_DIG = %d\n", FLT_MANT_DIG);
    printf("DBL_MANT_DIG = %d\n", DBL_MANT_DIG);
    printf("LDBL_MANT_DIG = %d\n", LDBL_MANT_DIG);

    
}

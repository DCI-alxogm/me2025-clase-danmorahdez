#include<stdio.h>
#include<math.h>

int main(){
  float numeros[5];
  numeros[0]=1;
  numeros[1]=2;
  numeros[2]=3;
  numeros[3]=4;
  numeros[4]=5;

  printf("x \t x**2 \t log(x+1) \t exp(x)+cos(x) \n");

  for(int i=0;i<5;i++){
    printf(" %f %f %f %f", numeros[i], pow(numeros[i],2), log(numeros[i]), exp(numeros[i])+cos(numeros[i]));
    printf("\n");
  }
  printf("\n");
  printf("\n Detectar  numeros impares y pares \n");
  int numero[5];
  numero[0]=1;
  numero[1]=2;
  numero[2]=3;
  numero[3]=4;
  numero[4]=5;
  
  float resultado[5];


  char* a;  

  for (int i = 0; i < 5; i++) {
    if (numero[i] % 2 == 0) {
        a = "Par";   
    }
    else {
        a = "Impar"; 
    }
    printf(" %d \t %d \t %s ", numero[i], numero[i] % 2, a);
    printf("\n");
  }

  printf("\n");
  for(int i=0;i<5;i++){

    if (numero[i]%2<1){
      printf("x= %d, log(x+1)= %f", numero[i], log(numero[i]+1));
      resultado[i]=log(numero[i]+1);
    }
    else{
      printf("x= %d, cos(x)+exp(x)= %f", numero[i], cos(numero[i])+exp(numero[i]));
      resultado[i]=cos(numero[i])+exp(numero[i]);
    }
    printf("\n");
  }
  printf("\n");

  printf("Resultados:");
  for(int i=0;i<5;i++){
    printf("%f \n",resultado[i]);
  }
  

}

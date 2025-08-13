#include <stdio.h>

int main(){
  float a = 3;
  float b = 4;
  float c = 5;
  float d = 7;

printf("Con flotantes \n");

printf("(a+b)*c/d = %f", (a+b)*c/d);
printf("\n");
printf("((a+b)*c)/d = %f", ((a+b)*c)/d);
printf("\n");
printf("a+(b*c)/d = %f", a+(b*c)/d);
printf("\n");
printf("a+b*c/d = %f", a+b*c/d);
printf("\n");
}
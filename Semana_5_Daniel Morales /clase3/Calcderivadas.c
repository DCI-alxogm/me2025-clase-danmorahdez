#include <stdio.h>

float fx(float x);

int main(){
  float a = -2, b = 2, h = 0.25;
  int n = (int)((b-a)/h)+1;
  float x[n], fpa[n];

  for (i = 0; i<n; i++){
    x[i]=a+i*h;
    printf("%f ")
  }
  
  
  
  
  printf("%f %f", a, fx(a));
  



}

float fx(float x){
  float f;
  f = x*x-2*x+4;
  return f;
}
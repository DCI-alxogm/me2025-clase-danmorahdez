#include <stdio.h>

float fx(float x);

int main(){
  int i;
  float a = -2, b = 2, h = 0.25;
  int n = (int)((b-a)/h)+1;
  float x[n], fpa[n], fpb[n], fpc[n];

  
  for (i = 0; i < n; i++){
    x[i] = a + i * h;
  }
  
  printf("x\t\tf'(x) adelante\tf'(x) atrás\tf'(x) centrada\n");
  printf("------------------------------------------------------------\n");
  
  
  for(i = 0; i < n - 1; i++){
    fpa[i] = (fx(x[i+1]) - fx(x[i])) / h;
  }
  fpa[n-1] = 0;
  
  fpb[0] = 0;
  for(i = 1; i < n; i++){
    fpb[i] = (fx(x[i]) - fx(x[i-1])) / h;
  }
  
  fpc[0] = 0; 
  for(i = 1; i < n - 1; i++){
    fpc[i] = (fx(x[i+1]) - fx(x[i-1])) / (2 * h);
  }
  fpc[n-1] = 0; 
  
  for(i = 0; i < n; i++){
    printf("%.4f\t\t", x[i]);
    
    if(i < n - 1) printf("%.4f\t\t", fpa[i]);
    else printf("N/A\t\t");
    
    if(i > 0) printf("%.4f\t\t", fpb[i]);
    else printf("N/A\t\t");
    
    if(i > 0 && i < n - 1) printf("%.4f", fpc[i]);
    else printf("N/A");
    
    printf("\n");
  }
}

float fx(float x){
  float f;
  f = x * x - 2 * x + 4;
  return f;
}
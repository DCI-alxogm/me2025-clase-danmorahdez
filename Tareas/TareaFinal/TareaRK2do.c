#include <stdio.h>
#include <math.h>

int main(){
    
  float k = 0.45;          
  float Cmax = 1.0;        
  float h = 0.1;           
  float t = 0;             
  float C, C_ant = 0.02;   
  float C_temp, k1, k2;
  int iter = 0, iter_max = 250;  // 25 min / 0.1 = 250 pasos
  
  printf("RK2 - Reacción A+B -> 2B\n");
  printf("dC/dt = k*C*(Cmax - C)\n");
  printf("Iter    Tiempo(min)    Conc(mol/L)\n");
  printf("----------------------------------\n");
  
  do{
    // k1 = f(C, t) = k * C * (Cmax - C)
    k1 = k * C_ant * (Cmax - C_ant);
    
    C_temp = C_ant + 0.5 * h * k1;
    
    // k2 = f(C_temp, t + h/2) = k * C_temp * (Cmax - C_temp)
    k2 = k * C_temp * (Cmax - C_temp);
    
    C = (0.5 * k1 + 0.5 * k2) * h + C_ant;
    
    printf("%3d %10.1f %15.6f\n", iter, t, C);
    
    C_ant = C;
    t = t + h;
    iter++;
    
  } while (iter < iter_max);
  
  return 0;
}
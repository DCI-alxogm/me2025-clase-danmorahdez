#include <stdio.h>
#include <math.h>

int main(){
    
    
  float k = 0.45;         
  float Cmax = 1.0;       
  float h = 0.1;           
  float t = 0;             
  float C, C_ant = 0.02;  
  float C_temp1, C_temp2, C_temp3, k1, k2, k3, k4;
  int iter = 0, iter_max = 250;  // 25 min / 0.1 = 250 pasos
  
  printf("RK4 - Reacción A+B -> 2B\n");
  printf("dC/dt = k*C*(Cmax - C)\n");
  printf("Iter    Tiempo(min)    Conc(mol/L)\n");
  printf("----------------------------------\n");
  
  do{
    // k1 = f(C, t)
    k1 = k * C_ant * (Cmax - C_ant);
    
    C_temp1 = C_ant + 0.5 * h * k1;
    // k2 = f(C_temp1, t + h/2)
    k2 = k * C_temp1 * (Cmax - C_temp1);
    
    C_temp2 = C_ant + 0.5 * h * k2;
    // k3 = f(C_temp2, t + h/2)
    k3 = k * C_temp2 * (Cmax - C_temp2);
    
    C_temp3 = C_ant + h * k3;
    // k4 = f(C_temp3, t + h)
    k4 = k * C_temp3 * (Cmax - C_temp3);
    
    C = (h / 6) * (k1 + 2 * k2 + 2 * k3 + k4) + C_ant;
    
    printf("%3d %10.1f %15.6f\n", iter, t, C);
    
    C_ant = C;
    t = t + h;
    iter++;
      
  } while (iter < iter_max);
  
  return 0;
}
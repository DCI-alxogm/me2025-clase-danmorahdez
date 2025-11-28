// Problema de Paracaidas resuelto con Runge-Kutta 4to Orden
#include <stdio.h>
#include <math.h>

int main(){
    
    float c = 12.5, m = 68.1, a = 8.3, b = 2.2, v_max = 46, g = 9.81;
    float h = 0.1, t = 0;
    float v, v_ant = 0, v_temp1, v_temp2, v_temp3, k1, k2, k3, k4;
    int iter = 0, iter_max = 200;
    
    printf("Iter    Tiempo(s)    Velocidad(m/s)\n");
    printf("-----------------------------------\n");
    
    do{
        k1 = g - (c / m) * (v_ant + a * pow((v_ant / v_max), b));
        v_temp1 = v_ant + 0.5 * h * k1;
        k2 = g - (c / m) * (v_temp1 + a * pow((v_temp1 / v_max), b));
        v_temp2 = v_ant + 0.5 * h * k2;
        k3 = g - (c / m) * (v_temp2 + a * pow((v_temp2 / v_max), b));
        v_temp3 = v_ant + h * k3;
        k4 = g - (c / m) * (v_temp3 + a * pow((v_temp3 / v_max), b));
        v = (h / 6) * (k1 + 2 * k2 + 2 * k3 + k4) + v_ant;
        
        printf("%3d %10.1f %15.6f\n", iter, t, v);
        
        v_ant = v;
        t = t + h;
        iter++;
        
    } while (iter < iter_max);
    
    return 0;
}
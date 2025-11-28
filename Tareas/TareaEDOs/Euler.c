// Problema de Paracaidas resuelto con Euler
#include <stdio.h>
#include <math.h>

int main(){
    
    float c = 12.5, m = 68.1, a = 8.3, b = 2.2, v_max = 46, g = 9.81;
    float h = 0.1, t = 0;
    float v, v_ant = 0, phi;
    int iter = 0, iter_max = 200;
    
    printf("Iter    Tiempo(s)    Velocidad(m/s)\n");
    printf("-----------------------------------\n");
    
    do{
        phi = g - (c / m) * (v_ant + a * pow((v_ant / v_max), b));
        v = phi * h + v_ant;
        
        printf("%3d %10.1f %15.6f\n", iter, t, v);
        
        v_ant = v;
        t = t + h;
        iter++;
        
    } while (iter < iter_max);
    
    return 0;
}
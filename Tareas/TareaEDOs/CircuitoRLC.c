// Circuito RLC - Oscilaciones con Runge-Kutta 2do Orden
//El ejemplo para hacer uso de nuestros programas de reslución de EDOs es el de la corriente y el voltaje en un circuito RLC
//Que esta descrito como una EDO de 2do orden, en este caso vamos a usar Runge-Kutta
#include <stdio.h>
#include <math.h>

int main(){
    
    float R = 10;      // Resistencia en ohms
    float L = 0.5;     // Inductancia en henrios
    float C = 0.01;    // Capacitancia en faradios
    float Vo = 10;     // Voltaje inicial del capacitor
    float Io = 0;      // Corriente inicial
    float h = 0.001;   // Paso de tiempo
    float t = 0;
    float I, I_ant = Io, V, V_ant = Vo;
    float k1_I, k2_I, k1_V, k2_V, I_temp, V_temp;
    int iter = 0, iter_max = 2000;
    
    printf("Circuito RLC - Oscilaciones\n");
    printf("Iter    Tiempo(s)    Corriente(A)   Voltaje(V)\n");
    printf("---------------------------------------------\n");
    
    do{
        // dI/dt = (V - R*I)/L
        // dV/dt = -I/C
        
        k1_I = (V_ant - R * I_ant) / L;
        k1_V = -I_ant / C;
        
        I_temp = I_ant + 0.5 * h * k1_I;
        V_temp = V_ant + 0.5 * h * k1_V;
        
        k2_I = (V_temp - R * I_temp) / L;
        k2_V = -I_temp / C;
        
        I = I_ant + h * k2_I;
        V = V_ant + h * k2_V;
        
        printf("%3d %10.3f %12.6f %12.6f\n", iter, t, I, V);
        
        I_ant = I;
        V_ant = V;
        t = t + h;
        iter++;
        
    } while (iter < iter_max);
    
    return 0;

}

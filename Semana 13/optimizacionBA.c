#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double f(double x, double y){
  return y - x - 2*x*x - 2*x*y - y*y;
}

double random_d(double mn, double max){
  return mn + ((double)rand() / RAND_MAX) * (max - mn);
}

int main(){
  srand(time(NULL));

  double x_mn = -2.0, x_max = 2.0;
  double y_mn = 1.0, y_max = 3.0;
  int pruebas = 100;

  double m_x = random_d(x_mn, x_max);
  double m_y = random_d(y_mn, y_max);
  double m_val = f(m_x, m_y);

  printf("Funcion: f(x,y) = y - x - 2x² - 2xy - y²\n");
  printf("Rango x: [%.1f, %.1f]\n", x_mn, x_max);
  printf("Rango y: [%.1f, %.1f]\n", y_mn, y_max);
  printf("Numero de pruebas: %d\n", pruebas);
  printf("\nPunto inicial: x = %f, y = %f\n", m_x, m_y);
  printf("f(x,y) inicial: %f\n\n", m_val);

  printf("Iteracion\t   x\t\t   y\t\t   f(x,y)\n");
  printf("----------------------------------------------------------------\n");

  for(int i = 0; i < pruebas; i++) {
    double x_act = random_d(x_mn, x_max);
    double y_act = random_d(y_mn, y_max);
    double v_act = f(x_act, y_act);

    if(v_act > m_val){
      m_val = v_act;
      m_x = x_act;
      m_y = y_act;
      printf("%d\t\t%f\t%f\t%f\t*\n", i+1, m_x, m_y, m_val);
    }
  }

  printf("----------------------------------------------------------------\n");
  printf("RESULTADO FINAL:\n");
  printf("Puntos optimos: x = %f, y = %f\n", m_x, m_y);
  printf("f(x,y) = %f\n", m_val);

  return 0;
}

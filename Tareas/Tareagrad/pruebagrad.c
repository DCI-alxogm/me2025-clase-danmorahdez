#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double f(double x[], int n) {
  return 2*x[0]*x[1] + 2*x[0] - x[0]*x[0] - 2*x[1]*x[1];
}

void gradiente(double x[], double grad[], int n, double h) {
  double* temp_plus = (double*)malloc(n * sizeof(double));
  double* temp_minus = (double*)malloc(n * sizeof(double));
  
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      temp_plus[j] = x[j];
      temp_minus[j] = x[j];
    }
      
    temp_plus[i] += h;
    temp_minus[i] -= h;
      
    double f_plus = f(temp_plus, n);
    double f_minus = f(temp_minus, n);
      
    grad[i] = (f_plus - f_minus) / (2*h);
  }
  
  free(temp_plus);
  free(temp_minus);
}

int main() {
  int n;
  
  printf("Ingresa numero de dimensiones: ");
  scanf("%d", &n);
  
  double* x = (double*)malloc(n * sizeof(double));
  double* g = (double*)malloc(n * sizeof(double));
  
  printf("Ingresa punto inicial:\n");
  for(int i = 0; i < n; i++) {
    printf("x[%d]: ", i);
    scanf("%lf", &x[i]);
  }
  
  double alpha = 0.01;
  double tol = 0.001;
  int max_iter = 10000;
  
  printf("\nMetodo del Gradiente\n");
  printf("Parametros: alpha=0.01, tol=0.001, max_iter=10000\n");
  printf("Iter\t");
  for(int i = 0; i < n; i++) {
    printf("x%d\t\t", i);
  }
  printf("f(x)\n");
  
  double h = 1e-6;
  int iter;
  
  for(iter = 0; iter < max_iter; iter++) {
    gradiente(x, g, n, h);
    
    double norma_grad = 0.0;
    for(int i = 0; i < n; i++) {
      norma_grad += g[i] * g[i];
    }
    norma_grad = sqrt(norma_grad);
    
    printf("%d\t", iter+1);
    for(int i = 0; i < n; i++) {
      printf("%.6f\t", x[i]);
    }
    printf("%.6f\n", f(x, n));
    
    if(norma_grad < tol) break;
    
    for(int i = 0; i < n; i++) {
      x[i] = x[i] + alpha * g[i];
    }
  }
  
  printf("\nResultado final:\n");
  for(int i = 0; i < n; i++) {
    printf("x[%d] = %.6f\n", i, x[i]);
  }
  printf("f(x) = %.6f\n", f(x, n));
  printf("Iteraciones: %d\n", iter+1);
  
  free(x);
  free(g);
  return 0;
}
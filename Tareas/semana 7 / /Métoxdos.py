import scipy as sp
import numpy as np

f = lambda x: x**2 - 1

raiz_biseccion, info_biseccion = sp.optimize.bisect(f, a=0, b=2, full_output=True)
print(f"Bisección: {raiz_biseccion}, Iteraciones: {info_biseccion.iterations}")

raiz_falsa_pos, info_falsa_pos = sp.optimize.brentq(f, a=0, b=2, full_output=True)
print(f"Falsa Posición: {raiz_falsa_pos}, Iteraciones: {info_falsa_pos.iterations}")

raiz_newton, info_newton = sp.optimize.newton(f, x0=1.5, fprime=lambda x: 2*x, full_output=True)
print(f"Newton-Raphson: {raiz_newton}, Iteraciones: {info_newton.iterations}")

raiz_secante, info_secante = sp.optimize.newton(f, x0=1.5, full_output=True)
print(f"Secante: {raiz_secante}, Iteraciones: {info_secante.iterations}")

g =lambda x: (x + 1/x)/2

raiz_punto_fijo = sp.optimize.fixed_point(g, x0=1.5)
print(f"Punto Fijo: {raiz_punto_fijo}")

raiz_fsolve, info_fsolve, _, _ = sp.optimize.fsolve(f, x0=1.5, full_output=True)
print(f"Fsolve: {raiz_fsolve[0]}, Iteraciones: {info_fsolve['nfev']}")

print(f"\nVerificación f(raíz) ≈ 0: {f(raiz_biseccion)}")

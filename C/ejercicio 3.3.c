//ejercicio 3.3
// Cargamos dos números por teclado y los intercambiamos usando punteros y una variable temporal.
#include <stdio.h>

int main () {
// Declaramos las variables int y los punteros a int.
int a, b, temp;
int*pA = NULL, *pB = NULL;

// Cargamos los dos números por teclado.
printf ("Ingrese el primer numero: ");
scanf ("%d", &a);

printf ("Ingrese el segundo  numero: ");
scanf ("%d", &b);

// Asignamos los punteros a las variables para poder intercambiarlos y mostramos los valores antes del cambio.
pA = &a;
pB = &b;

printf ("los valores antes del intercambio son: %d y %d\n", a, b);

// Hacemos el cambio usando los punteros y la variable temporal, y mostramos los valores actualizados por pantalla.
temp = *pA;
*pA = *pB;
*pB = temp;

printf ("los valores despues del intercambio son: %d y %d\n", *pA, *pB);

return 0;
}


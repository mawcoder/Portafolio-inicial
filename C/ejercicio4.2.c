//ejercicio 4.2
#include <stdio.h>

// Función que toma dos punteros a int y los ordena de menor a mayor, intercambiando el orden si es necesario.
void ordenarAscendente (int *x, int*y) {
if (*x > *y) {
int temp = *x;
*x = *y;
*y = temp;
}
}

int main () {
// Creamos dos variables para guardar los números.
int a, b;

// Cargamos los números por teclado.
printf ("Ingrese el primer numero: ");
scanf ("%d", &a);

printf ("Ingrese el segundo  numero: ");
scanf ("%d", &b);

// Mostramos los números antes del cambio, llamamos a la función ordenarAscendente pasándole las direcciones a los números cargados y mostramos los números nuevamente.
printf ("el valor de los numeros antes de la operacion es: %d y %d\n", a, b);
ordenarAscendente (&a, &b);
printf ("el valor de los numeros despues de la operacion es: %d y %d\n", a, b);

return 0;
}


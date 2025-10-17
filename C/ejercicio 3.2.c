// Ejercicio 4.2
#include <stdio.h>

int main () {
// Declaramos un int y un puntero a int.
int edad = 0;
int *pEdad = NULL;

// Cargamos la edad por teclado con scanf.
printf ("por favor, ingresa tu edad: ");
scanf ("%d", &edad);

// Asignamos el puntero a la variable edad.
pEdad = &edad;

// Mostramos el valor de la variable edad.
printf ("el valor de edad es: %d\n", edad);
// Mostramos el valor apuntado por pEdad.
printf ("el valor al que apunta el puntero pEdad es: %d\n", *pEdad);
// Mostramos la dirección de la variable edad.
printf ("la dirección en memoria de la variable edad es: %p\n", &edad);
// Mostramos el valor contenido por pEdad, es decir la dirección de la variable edad.
printf ("el contenido del puntero pEdad es: %p\n", pEdad);

return 0;
}


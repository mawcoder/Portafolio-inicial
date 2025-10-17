//ejercicio 4.1
#include <stdio.h>

// Creamos una función para duplicar un número usando un puntero.
void duplicar (int *num) {
*num = *num * 2;
}

int main () {
// creamos una variable int para almacenar el número.
int num;

// Cargamos el número por teclado y lo mostramos antes de pasarlo a la función.
printf ("Ingrese el numero a duplicar: ");
scanf ("%d", &num);

printf ("el valor del numero antes de la operacion es: %d\n", num);

// Pasamos la dirección del número en memoria a la función duplicar, lo que es idéntico a pasar un puntero. Luego mostramos el resultado en pantalla.
duplicar (&num);
printf ("el valor del numero despues de la operacion es: %d\n", num);

return 0;
}


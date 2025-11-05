// Ejercicio 6.8
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Se crea una función que genera un número aleatorio entre 1 y 100.
int generarNumero() {
    return rand() % 100 + 1;
}

// Se crea una función que valida si un número está entre 1 y 100.
// Devuelve true si está dentro del rango, false en caso contrario.
bool validarNumero(int *numero) {
    if ((*numero >= 1) && (*numero <= 100))
        return true;
    else
        return false;
}

// Se crea una función que compara el número del jugador con el número generado.
// Devuelve 0 si acierta, -1 si es mayor y 2 si es menor.
int validarJugada(int *numero, int *generado) {
    if (*numero == *generado)
        return 0;
    else if (*numero > *generado)
        return -1;
    else // *numero < *generado
        return 2;
}

int main() {
    // Se declaran variables para almacenar el número del jugador, el número generado y la cantidad de intentos.
    int numero = 0, intentos = 0, generado = 0;
    bool jugando = true;

    srand(time(NULL));  // Se inicializa la semilla del generador de números aleatorios.

    // Se muestran instrucciones al jugador.
    printf("Ingresa un numero entre 1 y 100.\n");
    printf("Pulsa 0 para salir.\n");
    printf("\n");

    // Bucle principal del juego.
    do {
        printf("Tu numero: ");
        scanf("%d", &numero);

        if (validarNumero(&numero)) {
            // Se genera un número aleatorio para comparar con el jugador.
            generado = generarNumero();

            // Se valida la jugada y se da retroalimentación.
            if (validarJugada(&numero, &generado) == 0) {
                intentos++;
                printf("¡Correcto! Lo lograste en %d intentos.\n", intentos);
            } else if (validarJugada(&numero, &generado) == -1) {
                intentos++;
                printf("Incorrecto, el numero es menor...\n");
            } else if (validarJugada(&numero, &generado) == 2) {
                intentos++;
                printf("Incorrecto, el numero es mayor...\n");
            }
        }
        else if (numero == 0) {
            // Salir del juego.
            jugando = false;
        }
        else {
            // Número fuera del rango.
            printf("Numero fuera de rango, intentalo otra vez.\n");
        }
    } while (jugando == true);

    // Mensaje final al salir del juego.
    printf("¡Gracias por jugar, hasta la proxima!\n");

    return 0;
}

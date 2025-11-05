// Ejercicio 7.2
#include <stdio.h>
#include <string.h>

// Se define una estructura libro que contiene título, autor y año de publicación.
typedef struct {
    char titulo[100];
    char autor[50];
    int anio;
} libro;

// Se crea una función para cargar los datos de un libro.
void cargarLibro(libro *l) {
    // Se solicita el título del libro y se elimina el salto de línea al final.
    printf("Ingresa el titulo del libro: ");
    fgets(l->titulo, sizeof(l->titulo), stdin);
    l->titulo[strcspn(l->titulo, "\n")] = '\0';

    // Se solicita el autor del libro y se elimina el salto de línea al final.
    printf("Ingresa el autor del libro: ");
    fgets(l->autor, sizeof(l->autor), stdin);
    l->autor[strcspn(l->autor, "\n")] = '\0';

    // Se solicita el año de publicación.
    printf("Ingresa el anio de publicacion: ");
    scanf("%d", &l->anio);

    // Se limpia el búfer de entrada para evitar problemas con fgets posteriores.
    while (getchar() != '\n'); 
}

// Se crea una función para mostrar los datos de un libro.
void mostrarLibro(libro *l) {
    printf("Titulo del libro: %s, autor: %s, anio de publicacion: %d\n", l->titulo, l->autor, l->anio);
}

int main() {
    // Se declara un arreglo de 3 libros.
    libro libros[3];

    // Se cargan los datos de cada libro usando la función cargarLibro.
    for (size_t i = 0; i < 3; i++) {
        cargarLibro(&libros[i]);
    }

    // Se muestran los datos de cada libro usando la función mostrarLibro.
    for (size_t i = 0; i < 3; i++) {
        mostrarLibro(&libros[i]);
    }

    return 0;
}

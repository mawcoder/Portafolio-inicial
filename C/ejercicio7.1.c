#include <stdio.h>
#include <string.h>

// Se define una estructura persona que contiene nombre, edad y altura.
typedef struct {
    char nombre[50];
    int edad;
    float altura;
} persona;

// Se crea una función para cargar los datos de una persona.
void cargarPersona(persona *p1) {
    // Se solicita el nombre y se elimina el salto de línea al final.
    printf("Ingresa el nombre de una persona: ");
    fgets(p1->nombre, sizeof(p1->nombre), stdin);
    p1->nombre[strcspn(p1->nombre, "\n")] = '\0';

    // Se solicita la edad de la persona.
    printf("Ingresa la edad: ");
    scanf("%d", &p1->edad);

    // Se solicita la altura en metros.
    printf("Ingresa la altura (en metros): ");
    scanf("%f", &p1->altura);

    // Se limpia el búfer de entrada para evitar problemas con fgets posteriores.
    while (getchar() != '\n');
}

// Se crea una función para mostrar los datos de una persona.
void mostrarPersona(persona *p1) {
    printf("Nombre: %s\n", p1->nombre);
    printf("Edad: %d años\n", p1->edad);
    printf("Altura: %.2f m\n", p1->altura);
    printf("-------------------------\n");
}

int main() {
    // Se declara un arreglo de 5 personas.
    persona personas[5];

    // Se cargan los datos de cada persona usando la función cargarPersona.
    for (size_t i = 0; i < 5; i++) {
        printf("Persona %zu:\n", i + 1);
        cargarPersona(&personas[i]);
    }

    // Se muestra el listado completo de personas usando la función mostrarPersona.
    printf("\nListado de personas:\n");
    for (size_t i = 0; i < 5; i++) {
        mostrarPersona(&personas[i]);
    }

    return 0;
}

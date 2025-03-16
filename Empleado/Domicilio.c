#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Domicilio.h"
#include "Errores.h"

Domicilio *crearDomicilio() {
    Domicilio *nuevoDomicilio = malloc(sizeof(Domicilio));
    if (!nuevoDomicilio) {
        printf("Error al reservar memoria para el domicilio\n");
        exit(ERROR_RESERVAR_MEMORIA_DOMICILIO);
    }

    nuevoDomicilio->calle = malloc(40 * sizeof(char));
    if (!nuevoDomicilio->calle) {
        printf("Error al reservar memoria para el domicilio (CALLE)\n");
        free(nuevoDomicilio);
        exit(ERROR_RESERVAR_MEMORIA_DOMICILIO);
    }

    nuevoDomicilio->especificaciones = malloc(40 * sizeof(char));
    if (!nuevoDomicilio->especificaciones) {
        printf("Error al reservar memoria para el domicilio (ESPECIFICACIONES)\n");
        free(nuevoDomicilio->calle);
        free(nuevoDomicilio);
        exit(ERROR_RESERVAR_MEMORIA_DOMICILIO);
    }

    return nuevoDomicilio;
}

void ingresarDomicilio(Domicilio *domicilio) {
    printf("Ingrese Domicilio en formato calle, número, (torre/piso/casa/etc)\n");

    printf("Calle: ");
    scanf(" %[^\n]%*c", domicilio->calle);

    printf("Número: ");
    while (scanf("%d", &domicilio->numero) != 1) {
        printf("Entrada inválida. Ingrese un número válido: ");
        while (getchar() != '\n');  // Limpieza del buffer de entrada
    }
    while (getchar() != '\n');  // Limpieza adicional del buffer

    printf("Tipo de domicilio: ");
    scanf(" %[^\n]%*c", domicilio->especificaciones);
}

void mostrarDomicilio(const Domicilio *domicilio) {
    printf("Domicilio: %s %d, %s\n", domicilio->calle, domicilio->numero, domicilio->especificaciones);
}

void liberarDomicilio(Domicilio *domicilio) {
    if (domicilio) {
        free(domicilio->calle);
        free(domicilio->especificaciones);
        free(domicilio);
    }
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "EstadoCivil.h"
#include "Errores.h"

EstadoCivil *crearEstadoCivil() {
    EstadoCivil *nuevoEstadoCivil = (EstadoCivil *)malloc(sizeof(EstadoCivil));
    if (!nuevoEstadoCivil) {
        printf("Error al reservar memoria para el estado civil\n");
        exit(ERROR_RESERVAR_MEMORIA_ESTADO_CIVIL);
    }

    nuevoEstadoCivil->descripcion = (char *)malloc(10 * sizeof(char));
    if (!nuevoEstadoCivil->descripcion) {
        printf("Error al reservar memoria para la descripcion del estado civil\n");
        free(nuevoEstadoCivil);
        exit(ERROR_RESERVAR_MEMORIA_ESTADO_CIVIL);
    }

    return nuevoEstadoCivil;
}

void ingresarEstadoCivil(EstadoCivil *estadoCivil) {
    printf("Ingrese opción de estado civil \n");
    printf("0: Soltero 1: Casado 2: Divorciado 3: Viudo :: ");

    while (scanf(" %d", &estadoCivil->codigo) != 1 || estadoCivil->codigo < 0 || estadoCivil->codigo > 3) {
        printf("Opción inválida. Intente nuevamente.\n");
        printf("0: Soltero 1: Casado 2: Divorciado 3: Viudo :: ");
        while (getchar() != '\n');
    }

    char *estado[] = {"Soltero", "Casado", "Divorciado", "Viudo"};
    strcpy(estadoCivil->descripcion, estado[estadoCivil->codigo]);
}

void mostrarEstadoCivil(const EstadoCivil *estadoCivil) {
    printf("Estado Civil: %s\n", estadoCivil->descripcion);
}

void liberarEstadoCivil(EstadoCivil *estadoCivil) {
    if (estadoCivil) {
        free(estadoCivil->descripcion);
        free(estadoCivil);
    }
}

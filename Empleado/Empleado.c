#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Empleado.h"
#include "Errores.h"


Empleado *crearEmpleado() {
    Empleado *nuevoEmpleado = (Empleado *)malloc(sizeof(Empleado));
    if (!nuevoEmpleado) {
        printf("Error al reservar memoria para Empleado\n");
        exit(ERROR_RESERVAR_MEMORIA_EMPLEADO);
    }

    nuevoEmpleado->apellido = (char *)malloc(40 * sizeof(char));
    nuevoEmpleado->nombre = (char *)malloc(40 * sizeof(char));
    nuevoEmpleado->telefono = (char *)malloc(15 * sizeof(char));

    if (!nuevoEmpleado->apellido || !nuevoEmpleado->nombre || !nuevoEmpleado->telefono) {
        printf("Error al reservar memoria para los campos del Empleado\n");
        free(nuevoEmpleado);
        exit(ERROR_RESERVAR_MEMORIA_EMPLEADO);
    }

    nuevoEmpleado->domicilio = crearDomicilio();
    nuevoEmpleado->sexo = crearSexo();
    nuevoEmpleado->estudios = crearNivelEstudios();
    nuevoEmpleado->estadoCivil = crearEstadoCivil();

    return nuevoEmpleado;
}

void ingresarEmpleado(Empleado *empleado) {
    printf("Ingrese apellido: ");
    scanf("%39s", empleado->apellido);

    printf("Ingrese nombre: ");
    scanf("%39s", empleado->nombre);

    ingresarDomicilio(empleado->domicilio);

    printf("Ingrese telefono: ");
    scanf("%14s", empleado->telefono);

    ingresarSexo(empleado->sexo);

    do {
        printf("Ingrese edad (18-65): ");
        scanf("%d", &empleado->edad);
    } while (empleado->edad < 18 || empleado->edad > 65);

    ingresarNivelEstudios(empleado->estudios);
    ingresarEstadoCivil(empleado->estadoCivil);
}

void mostrarEmpleado(const Empleado *empleado) {
    printf("\n--- Información del Empleado ---\n");
    printf("Nombre: %s %s\n", empleado->nombre, empleado->apellido);
    mostrarDomicilio(empleado->domicilio);
    printf("Telefono: %s\n", empleado->telefono);
    mostrarSexo(empleado->sexo);
    printf("Edad: %d\n", empleado->edad);
    mostrarNivelEstudios(empleado->estudios);
    mostrarEstadoCivil(empleado->estadoCivil);
}

void liberarEmpleado(Empleado *empleado) {
    if(empleado){
        free(empleado->apellido);
        free(empleado->nombre);
        free(empleado->telefono);
        liberarDomicilio(empleado->domicilio);
        liberarSexo(empleado->sexo);
        liberarNivelEstudios(empleado->estudios);
        liberarEstadoCivil(empleado->estadoCivil);
        free(empleado);
    }
}

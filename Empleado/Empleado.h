#ifndef EMPLEADO_H
#define EMPLEADO_H

#include "Domicilio.h"
#include "Sexo.h"
#include "EstadoCivil.h"
#include "NivelEstudios.h"


typedef struct Empleado{
    char *apellido;
    char *nombre;
    Domicilio *domicilio;
    char *telefono;
    int edad;
    Sexo *sexo;
    NivelEstudios *estudios;
    EstadoCivil *estadoCivil;
} Empleado;

Empleado *crearEmpleado();
void ingresarEmpleado(Empleado *empleado);
void mostrarEmpleado(const Empleado *empleado);
void liberarEmpleado(Empleado *empleado);

#endif // EMPLEADO_H

#ifndef ESTADO_CIVIL_H
#define ESTADO_CIVIL_H

typedef struct {
    int codigo;
    char *descripcion;
} EstadoCivil;

EstadoCivil *crearEstadoCivil();
void ingresarEstadoCivil(EstadoCivil *estadoCivil);
void mostrarEstadoCivil(const EstadoCivil *estadoCivil);
void liberarEstadoCivil(EstadoCivil *estadoCivil);
#endif // ESTADO_CIVIL_H

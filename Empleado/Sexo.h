#ifndef SEXO_H
#define SEXO_H

typedef struct Sexo{
    char codigo;
    char *descripcion;
} Sexo;

Sexo *crearSexo();
void ingresarSexo(Sexo *sexo);
void mostrarSexo(const Sexo *sexo);
void liberarSexo(Sexo *sexo);

#endif // SEXO_H

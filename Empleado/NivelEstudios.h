#ifndef NIVEL_ESTUDIOS_H
#define NIVEL_ESTUDIOS_H

typedef struct NivelEstudios{
    int codigo;
    char *descripcion;
} NivelEstudios;

NivelEstudios *crearNivelEstudios();
void ingresarNivelEstudios(NivelEstudios *nivelEstudios);
void mostrarNivelEstudios(const NivelEstudios *nivelEstudios);
void liberarNivelEstudios(NivelEstudios *nivelEstudios);
#endif // NIVEL_ESTUDIOS_H


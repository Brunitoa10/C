#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED

typedef struct {
        char *nombre;
        char *password;
} usuario_t;

usuario_t *usuario_crear(const char* nombre, const char* password);
int usuario_eliminar(usuario_t *usuario);

#endif // USUARIO_H_INCLUDED

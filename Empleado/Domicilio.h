#ifndef DOMICILIO_H
#define DOMICILIO_H

typedef struct Domicilio{
    char *calle;
    int numero;
    char *especificaciones;
} Domicilio;

Domicilio *crearDomicilio();
void ingresarDomicilio(Domicilio *domicilio);
void mostrarDomicilio(const Domicilio *domicilio);
void liberarDomicilio(Domicilio *domicilio);

#endif // DOMICILIO_H

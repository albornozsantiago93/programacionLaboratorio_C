#ifndef PRESTAMOS_H_INCLUDED
#define PRESTAMOS_H_INCLUDED

typedef struct{
            int dia;
            int mes;
            int anio;
}eFechaPrestamo;

typedef struct{
        int idPrestamo;
        int idLibro;
        int idSocio;
        int isEmpty;
        eFechaPrestamo fecha;
}ePrestamo;

#endif // PRESTAMOS_H_INCLUDED

#define ESTADO_OCUPADO 1
#define ESTADO_LIBRE 0
#include "socios.h"

int prestamo_array_generarProximoId(void);
int prestamo_init(ePrestamo* ,int cantidad);
int prestamo_findIsEmpty(ePrestamo* ,int cantidad);
void prestamo_alta(ePrestamo* prestamos,int cantidadPrestamos,eAutor* autores,eSocio* socios,eLibro* libros,int cantidadAutores,int cantidadLibros,int cantidadSocios);

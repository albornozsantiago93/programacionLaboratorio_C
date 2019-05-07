#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <time.h>
#include "prestamos.h"
#include "funcionesGet.h"

static int idAutoincrementable= 0;


/**
 * \brief Genera un id que se ira autoincrementando
 * \param void
 * \return int, id unico generado
 *
 */
int prestamo_array_generarProximoId(void)
{
    idAutoincrementable ++;
    return idAutoincrementable;
}


/** \brief inicializa el estado de un array
 * \param eAlmuerzos almuerzos, prestamos de almuerzos
 * \param int cantidad, largo de array
 * \return int (-1) Error  - (0)  Ok
 */
int prestamo_init(ePrestamo* prestamos ,int cantidad)
{
    int i, retorno=-1;


    for(i=0; i<cantidad; i++)
    {
        prestamos[i].isEmpty= ESTADO_LIBRE;
    }
    retorno=0;

    return retorno;
}


 /** \brief encuentra un lugar disponible en el array
 * \param eAlmuerzos almuerzos, prestamos de almuerzos
 * \param int cantidad, largo de array
 * \return int  (-1)  - Numero !=-1 (ubicacion disponible en array)
 */
int prestamo_findIsEmpty(ePrestamo* prestamos,int cantidad)
{
    int i,retorno=-1;


    for(i=0; i<cantidad; i++)
    {
        if(prestamos[i].isEmpty==ESTADO_LIBRE)
        {
            retorno= i;
            break;
        }
    }

    return retorno;
}



/** \brief da por alta un almuerzo en la estructura
 * \param ePrestamos
 * \param eAutores
 * \param eLibros
 * \param eSocio
 * \param int cantidadPrestamos, largo de array
 * \param int cantidadAutores, largo de array
 * \param int cantidadLibros, largo de array
 * \param int cantidadSocios, largo de array
 * \return void
 */
void prestamo_alta(ePrestamo* prestamos,int cantidadPrestamos,eAutor* autores,eSocio* socios,eLibro* libros,int cantidadAutores,int cantidadLibros,int cantidadSocios)
{
    int  posicionDisponible;

    posicionDisponible= prestamo_findIsEmpty(prestamos,cantidadPrestamos);

    if(posicionDisponible!=-1)
    {
        prestamos[posicionDisponible].idPrestamo= prestamo_array_generarProximoId();
        printf("\t\t-LIBROS-\n\n");
        libro_listar(libros,cantidadLibros);
        prestamos[posicionDisponible].idLibro= getValidIntOpcion("\nESCOGA LIBRO MEDIANTE CODIGO\n","ERROR\nOPCION no VALIDA\n",0,cantidadLibros);
        prestamos[posicionDisponible].idSocio= getValidIntOpcion("\n\nINGRESE SU ID PARA COMPLETAR LA OPERACION\n","ERROR\nOPCION no VALIDA\n",0,cantidadSocios);
        prestamos[posicionDisponible].isEmpty= ESTADO_OCUPADO;
        system("cls");
        prestamos[posicionDisponible].fecha.anio= getValidIntOpcion("INGRESE ANIO DE INGRESO\n ","\tERROR\nOPCION NO VALIDA",1950,2019);
        prestamos[posicionDisponible].fecha.mes= getValidIntOpcion("INGRESE MES DE INGRESO\n ","\tERROR\nOPCION NO VALIDA",1,12);
        prestamos[posicionDisponible].fecha.dia= getValidIntOpcion("INGRESE DIA DE INGRESO\n ","\tERROR\nOPCION NO VALIDA",1,31);
    }
}


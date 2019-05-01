#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <time.h>
#include "almuerzos.h"
#include "funcionesGet.h"



static int idAutoincrementable= 0;

/**
 * \brief Genera un id que se ira autoincrementando
 * \param void
 * \return int, id unico generado
 *
 */
int array_generarProximoIdAlmuerzos(void)
{
    idAutoincrementable ++;
    return idAutoincrementable;
}

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initAlmuerzos(eAlmuerzo* almuerzos,int cantidadAlmuerzos)
{
    int i, retorno=-1;


        for(i=0;i<cantidadAlmuerzos;i++)
        {
            almuerzos[i].isEmpty=ESTADO_LIBRE;
        }
        retorno=0;

    return retorno;
}


  /** \brief find an Employee by Id en returns the free place position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int almuerzo_findIsEmpty(eAlmuerzo* almuerzos,int cantidadAlmuerzos)
 {
     int i,retorno=-1;


        for(i=0;i<cantidadAlmuerzos;i++)
        {
            if(almuerzos[i].isEmpty==ESTADO_LIBRE)
            {
                retorno= i;
                break;
            }
        }

     return retorno;
 }


void printListMenues(eMenu* menues,int cantidadMenues)
{
    int i;

    printf("CODIGO\tPRECIO\t\tDESCRIPCION\n");

    for(i=0;i<cantidadMenues;i++)
    {
        if(menues[i].isEmpty==ESTADO_OCUPADO)
        {
            printf("%d\t%.2f\t\t%s\n",menues[i].idMenu,menues[i].importe,menues[i].descripcion);
        }
    }
}

int menuesMenores125(eMenu* menues,int cantidadMenues)
{
    int i, contadorMenores125=0;

    for(i=0;i<cantidadMenues;i++)
    {
        if(menues[i].isEmpty==ESTADO_OCUPADO)
        {
            if(menues[i].importe<125)
            {
                contadorMenores125++;
            }
        }
    }
    return contadorMenores125;
}

int menuesMayores125(eMenu* menues,int cantidadMenues)
{
    int i, contadorMayores125=0;

    for(i=0;i<cantidadMenues;i++)
    {
        if(menues[i].isEmpty==ESTADO_OCUPADO)
        {
            if(menues[i].importe>125)
            {
                contadorMayores125++;
            }
        }
    }
    return contadorMayores125;
}


void altaAlmuerzos(eAlmuerzo* almuerzos,int cantidadAlmuerzos,eMenu* menues,eEmployee* empleados,int cantidadMenues,int cantidadEmpleados)
{
    int  posicionDisponible;

    posicionDisponible= almuerzo_findIsEmpty(almuerzos,cantidadAlmuerzos);

    if(posicionDisponible!=-1)
    {
        almuerzos[posicionDisponible].idAlmuerzo= array_generarProximoIdAlmuerzos();
        printListMenues(menues,cantidadMenues);
        almuerzos[posicionDisponible].idMenu= getValidIntOpcion("Escoga almuerzo mediante codigo\n","Error\nOpcion no valida\n",0,cantidadAlmuerzos);
        almuerzos[posicionDisponible].idEmpleado= getValidIntOpcion("\n\nIngrese su ID para completar la operacion\n","Error\nOpcion no valida\n",0,cantidadEmpleados);
        almuerzos[posicionDisponible].isEmpty= ESTADO_OCUPADO;
    }
}




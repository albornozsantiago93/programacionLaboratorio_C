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


    for(i=0; i<cantidadAlmuerzos; i++)
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


    for(i=0; i<cantidadAlmuerzos; i++)
    {
        if(almuerzos[i].isEmpty==ESTADO_LIBRE)
        {
            retorno= i;
            break;
        }
    }

    return retorno;
}

 /** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
void printListMenues(eMenu* menues,int cantidadMenues)
{
    int i;

    printf("CODIGO\tPRECIO\t\tDESCRIPCION\n");

    for(i=0; i<cantidadMenues; i++)
    {
        if(menues[i].isEmpty==ESTADO_OCUPADO)
        {
            printf("%d\t%.2f\t\t%s\n",menues[i].idMenu,menues[i].importe,menues[i].descripcion);
        }
    }
}

 /** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
int menuesMenores125(eMenu* menues,int cantidadMenues)
{
    int i, contadorMenores125=0;

    for(i=0; i<cantidadMenues; i++)
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

 /** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
int menuesMayores125(eMenu* menues,int cantidadMenues)
{
    int i, contadorMayores125=0;

    for(i=0; i<cantidadMenues; i++)
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


 /** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
void altaAlmuerzos(eAlmuerzo* almuerzos,int cantidadAlmuerzos,eMenu* menues,eEmployee* empleados,int cantidadMenues,int cantidadEmpleados)
{
    int  posicionDisponible;

    posicionDisponible= almuerzo_findIsEmpty(almuerzos,cantidadAlmuerzos);

    if(posicionDisponible!=-1)
    {
        almuerzos[posicionDisponible].idAlmuerzo= array_generarProximoIdAlmuerzos();
        printf("\t\t-MENU-\n\n");
        printListMenues(menues,cantidadMenues);
        almuerzos[posicionDisponible].idMenu= getValidIntOpcion("\nESCOGA ALMUERZO MEDIANTE CODIGO\n","ERROR\nOPCION no VALIDA\n",0,cantidadAlmuerzos);
        almuerzos[posicionDisponible].idEmpleado= getValidIntOpcion("\n\nINGRESE SU ID PARA COMPLETAR LA OPERACION\n","ERROR\nOPCION no VALIDA\n",0,cantidadEmpleados);
        almuerzos[posicionDisponible].isEmpty= ESTADO_OCUPADO;
    }
}

 /** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
void listadoEmpleadoMenu(eEmployee* empleados, eMenu* menues, eAlmuerzo* almuerzos, int cantidadEmpleados, int cantidadMenues)
{
    int i, j, k;

    printf("\tLISTADO DE EMPLEADOS - MENU \n\n");

    for(i=0; i<cantidadMenues; i++)
    {
        for(j=0; j<(cantidadEmpleados * cantidadMenues); j++)
        {
            if(menues[i].idMenu == almuerzos[j].idMenu)
            {
                for(k=0; k<cantidadEmpleados; k++)
                {
                    if(empleados[k].isEmpty== ESTADO_OCUPADO && menues[i].isEmpty==ESTADO_OCUPADO && almuerzos[j].idEmpleado == empleados[k].id)
                    {
                        printf("%d  %s %s\t\t-%s\n", empleados[k].id, empleados[k].name,empleados[k].lastName, menues[i].descripcion );
                    }
                }
            }
        }
    }
}


 /** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
void menuesConsumidosEmpleados(eEmployee* empleados, eMenu* menues, eAlmuerzo* almuerzos, int cantidadEmpleados, int cantidadMenues,int idEmpleado)
{
    int i, j, k;

    system("cls");
    printf("EMPLEADO \t MENU \n\n");

    for(i=0; i<cantidadMenues; i++)
    {
        for(j=0; j<(cantidadEmpleados * cantidadMenues); j++)
        {
            if(menues[i].idMenu == almuerzos[j].idAlmuerzo)
            {
                for(k=0; k<cantidadEmpleados; k++)
                {
                    if(empleados[k].isEmpty== ESTADO_OCUPADO && almuerzos[j].idEmpleado == empleados[k].id)
                    {
                        if(empleados[k].id== idEmpleado)
                            printf("%s %s\t-%s\n",empleados[k].name,empleados[k].lastName, menues[i].descripcion );
                    }
                }
            }
        }
    }
}


 /** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
void menuesConsumidosFecha(eEmployee* empleados, eMenu* menues, eAlmuerzo* almuerzos, int cantidadEmpleados, int cantidadMenues,eFechaAlmuerzo fecha)
{
    int i, j, k;

    system("cls");
    printf("\t MENUES \n\n");

    for(i=0; i<cantidadMenues; i++)
    {
        for(j=0; j<(cantidadEmpleados * cantidadMenues); j++)
        {
            if(menues[i].idMenu == almuerzos[j].idAlmuerzo)
            {
                for(k=0; k<cantidadEmpleados; k++)
                {
                    if(empleados[k].isEmpty== ESTADO_OCUPADO && almuerzos[j].idEmpleado == empleados[k].id)
                    {
                        if(almuerzos[j].fechaAlmuerzo.anio== fecha.anio && almuerzos[j].fechaAlmuerzo.mes== fecha.mes && almuerzos[j].fechaAlmuerzo.dia== fecha.dia )
                            printf("%s \n",menues[i].descripcion );
                    }
                }
            }
        }
    }
}


 /** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
void empleadosConsumieronFecha(eEmployee* empleados, eMenu* menues, eAlmuerzo* almuerzos, int cantidadEmpleados, int cantidadMenues,eFechaAlmuerzo fecha)
{
    int i, j, k;

    system("cls");
    printf("\t EMPLEADOS \n\n");

    for(i=0; i<cantidadMenues; i++)
    {
        for(j=0; j<(cantidadEmpleados * cantidadMenues); j++)
        {
            if(menues[i].idMenu == almuerzos[j].idAlmuerzo)
            {
                for(k=0; k<cantidadEmpleados; k++)
                {
                    if(empleados[k].isEmpty== ESTADO_OCUPADO && almuerzos[j].idEmpleado == empleados[k].id)
                    {
                        if(almuerzos[j].fechaAlmuerzo.anio== fecha.anio && almuerzos[j].fechaAlmuerzo.mes== fecha.mes && almuerzos[j].fechaAlmuerzo.dia== fecha.dia )
                            printf("%s %s\n",empleados[k].name,empleados[k].lastName);
                    }
                }
            }
        }
    }
}



 /** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
void administrarAlmuerzos(eEmployee* empleados, eMenu* menues, eAlmuerzo* almuerzos, int cantidadEmpleados, int cantidadMenues,int cantidadAlmuerzos)
{
    int opcion, idAux;
    eFechaAlmuerzo auxiliarFecha;

    do
    {
        system("cls");
        printf("\tMENU -ALMUERZOS-\n\n");
        opcion=getValidIntOpcion("1-ALTA\n2-LISTAR - EMPLEADOS -MENU\n3-LISTAR - MENUES CONSUMIDOS POR UN EMPLEADO\n4-ALMUERZOS CONSUMIDOS POR FECHA\n5-EMPLEADOS QUE CONSUMIERDON ALMUERZO EN FECHA ESPECIFICA\n6-VOLVER\n","ERROR\nOPCION NO VALIDA",1,6);

        switch(opcion)
        {
        case 1:
            system("cls");
            altaAlmuerzos(almuerzos,cantidadAlmuerzos,menues,empleados,cantidadMenues,cantidadEmpleados);
            break;

        case 2:
            system("cls");
            listadoEmpleadoMenu(empleados,menues,almuerzos,cantidadEmpleados,cantidadMenues);
            getChar("\nENTER PARA CONTINUAR\n");
            break;

        case 3:
            system("cls");
            idAux= getValidIntOpcion("INGRESE ID DE EMPLEADO:\n","ERROR\nOPCION NO VALIDA",1,cantidadEmpleados);
            menuesConsumidosEmpleados(empleados,menues,almuerzos,cantidadEmpleados,cantidadMenues,idAux);
            getChar("");
            break;

        case 4:
            system("cls");
            auxiliarFecha.dia= getValidIntOpcion("INGRESE DIA\n","ERROR\nOPCION NO VALIDA",1,31);
            auxiliarFecha.mes= getValidIntOpcion("INGRESE MES\n","ERROR\nOPCION NO VALIDA",1,12);
            auxiliarFecha.anio= getValidIntOpcion("INGRESE ANIO\n","ERROR\nOPCION NO VALIDA",2018,2019);
            menuesConsumidosFecha(empleados,menues,almuerzos,cantidadEmpleados,cantidadMenues,auxiliarFecha);
            getChar("");
            break;

        case 5:
            system("cls");
            auxiliarFecha.dia= getValidIntOpcion("INGRESE DIA\n","ERROR\nOPCION NO VALIDA",1,31);
            auxiliarFecha.mes= getValidIntOpcion("INGRESE MES\n","ERROR\nOPCION NO VALIDA",1,12);
            auxiliarFecha.anio= getValidIntOpcion("INGRESE ANIO\n","ERROR\nOPCION NO VALIDA",2018,2019);
            empleadosConsumieronFecha(empleados,menues,almuerzos,cantidadEmpleados,cantidadMenues,auxiliarFecha);
            getChar("");
            break;
        }
    }while(opcion!=6);
}


 /** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
void hardcodearAlmuerzos(eAlmuerzo* almuerzos,int cantidadAlmuerzos)
{
    int idMenu[]= {1,2,3,4,5,6};
    int idEmpleado[]= {1,2,3,4,5,6};
    int i;
    eFechaAlmuerzo fecha= {5,5,2019};

    for(i=0; i<cantidadAlmuerzos; i++)
    {
        almuerzos[i].idAlmuerzo= array_generarProximoIdAlmuerzos();
        almuerzos[i].idEmpleado= idEmpleado[i];
        almuerzos[i].idMenu= idMenu[i];
        almuerzos[i].isEmpty= ESTADO_OCUPADO;
        almuerzos[i].fechaAlmuerzo= fecha;
    }
}

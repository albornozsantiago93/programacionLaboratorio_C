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

/** \brief inicializa el estado de un array
 * \param eAlmuerzos almuerzos, estructura de almuerzos
 * \param int cantidad, largo de array
 * \return int (-1) Error  - (0)  Ok
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


 /** \brief encuentra un lugar disponible en el array
 * \param eAlmuerzos almuerzos, estructura de almuerzos
 * \param int cantidad, largo de array
 * \return int  (-1)  - Numero !=-1 (ubicacion disponible en array)
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


 /** \brief imprime lista de menues
 * \param eAlmuerzos almuerzos, estructura de almuerzos
 * \param int cantidad, largo de array
 * \return void
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


 /** \brief cuenta la cantidad de menues qe no superan los 125
 * \param eAlmuerzos almuerzos, estructura de almuerzos
 * \param int cantidad, largo de array
 * \return int, cantidad de menues que no superan los 125
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


 /** \brief cuenta la cantidad de menues que superan los 125
 * \param eAlmuerzos almuerzos, estructura de almuerzos
 * \param int cantidad, largo de array
 * \return int, cantidad de menues que superan los 125
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


/** \brief da por alta un almuerzo en la estructura
 * \param eAlmuerzos almuerzos, estructura de almuerzos
 * \param eMenu menues, estructura de menu
 * \param eEmpleados empleados, estructura de empleados
 * \param int cantidadAlmuerzos, largo de array
 * \param int cantidadMenues, largo de array
 * \param int cantidadEmpleados, largo de array
 * \return void
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


  /** \brief imprime por pantalla lista de empleados y su sector correspondiente
 * \param eAlmuerzos almuerzos, estructura de almuerzos
 * \param eMenu menues, estructura de menu
 * \param eEmpleados empleados, estructura de empleados
 * \param eSector sectores, array de sectores
 * \param int cantidadMenues, largo de array
 * \param int cantidadEmpleados, largo de array
 * \return void
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
                    if(empleados[k].isEmpty== 1  && almuerzos[j].idEmpleado == empleados[k].id)
                    {
                        printf("%d  %s %s\t\t-%s\n", empleados[k].id, empleados[k].name,empleados[k].lastName, menues[i].descripcion );
                    }
                }
            }
        }
    }
}


 /** \brief imprime por pantalla los menues consumidos por empleados
 * \param eAlmuerzos almuerzos, estructura de almuerzos
 * \param eMenu menues, estructura de menu
 * \param eEmpleados empleados, estructura de empleados
 * \param eSector sectores, array de sectores
 * \param int cantidadMenues, largo de array
 * \param int cantidadEmpleados, largo de array
 * \param int id, empleado
 * \return void
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
            if(menues[i].idMenu == almuerzos[j].idMenu)
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


 /** \brief imprime por pantalla los menues consumidos por fecha
 * \param eAlmuerzos almuerzos, estructura de almuerzos
 * \param eMenu menues, estructura de menu
 * \param eEmpleados empleados, estructura de empleados
 * \param eSector sectores, array de sectores
 * \param int cantidadMenues, largo de array
 * \param int cantidadEmpleados, largo de array
 * \param  eFecha fecha, fecha buscar
 * \return void
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


 /** \brief imprime por pantalla los empleados que consumieron esa fecha
 * \param eAlmuerzos almuerzos, estructura de almuerzos
 * \param eMenu menues, estructura de menu
 * \param eEmpleados empleados, estructura de empleados
 * \param eSector sectores, array de sectores
 * \param int cantidadMenues, largo de array
 * \param int cantidadEmpleados, largo de array
 * \param  eFecha fecha, fecha buscar
 * \return void
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
                        if(almuerzos[j].fechaAlmuerzo.anio== fecha.anio && almuerzos[j].fechaAlmuerzo.mes== fecha.mes && almuerzos[j].fechaAlmuerzo.dia== fecha.dia)
                            printf("%s %s\n",empleados[k].name,empleados[k].lastName);
                    }
                }
            }
        }
    }
}



/** \brief ordena los elemento de la estructura
 * \param list employee*
 * \param cantidad int
 * \return void
 */
 void menu_ordenarMenues(eMenu* menues,int cantidadMenues)
{
    int i,j;
    eMenu aux;

    for(i=0;i<cantidadMenues-1;i++)
    {
        for(j=i+1;j<cantidadMenues;j++)
        {
            if(menues[i].importe< menues[j].importe)
            {
                aux=menues[i];
                menues[i]=menues[j];
                menues[j]=aux;
            }
        }
    }
}


 /** \brief administra un almuerzo, alta baja modificar y listar
 * \param eAlmuerzos almuerzos, estructura de almuerzos
 * \param eMenu menues, estructura de menu
 * \param eEmpleados empleados, estructura de empleados
 * \param eSector sectores, array de sectores
 * \param int cantidadMenues, largo de array
 * \param int cantidadEmpleados, largo de array
 * \return void
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
            getChar("");
            break;

        case 3:
            system("cls");
            idAux= getValidIntOpcion("INGRESE ID DE EMPLEADO:\n","ERROR\nOPCION NO VALIDA",0,cantidadEmpleados);
            menu_ordenarMenues(menues,cantidadMenues);
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
    }
    while(opcion!=6);
}


 /** \brief carga datos hardcodeados en la estructura de almuerzos
 * \param eAlmuerzo almuerzos, estructura de almuerzos
 * \param int cantidad, largo de array
 * \return void
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
        almuerzos[i].idEmpleado=idEmpleado[i];
        almuerzos[i].idMenu= idMenu[i];
        almuerzos[i].isEmpty= ESTADO_OCUPADO;
        almuerzos[i].fechaAlmuerzo= fecha;
    }
}

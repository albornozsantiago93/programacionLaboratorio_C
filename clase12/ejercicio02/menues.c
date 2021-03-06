#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <time.h>
#include "menues.h"
#include "funcionesGet.h"


 static int idAutoincrementable= 0;

/**
 * \brief Genera un id que se ira autoincrementando
 * \param void
 * \return int, id unico generado
 *
 */
int array_generarProximoIdMenues(void)
{
    idAutoincrementable ++;
    return idAutoincrementable;
}


/** \brief encuentra por id un dato de la estructura
 *
 * \param eEmployee empleado, estructura de empleados
 * \param int cantidad, largo de array
 * \param int id, referencia a buscar
 * \return int  (-1)  - Numero id !=-1
 */
int findMenuById(eMenu* menues,int cantidadMenues,int id)
 {
     int i,retorno=-1;


        for(i=0;i<cantidadMenues;i++)
        {
            if(menues[i].isEmpty==ESTADO_OCUPADO &&  menues[i].idMenu== id)
            {
                retorno= i;
                break;
            }
        }

     return retorno;
 }


 /** \brief encuentra un lugar disponible en el array
 * \param eEmployee empleado, estructura de empleados
 * \param int cantidad, largo de array
 * \return int  (-1)  - Numero !=-1 (ubicacion disponible en array)
 */
int menu_findIsEmpty(eMenu* menues,int cantidad)
 {
     int i,retorno=-1;


        for(i=0;i<cantidad;i++)
        {
            if(menues[i].isEmpty==ESTADO_LIBRE)
            {
                retorno= i;
                break;
            }
        }

     return retorno;
 }


/** \brief inicializa el estado de un array
 * \param eEmployee empleado, estructura de empleados
 * \param int cantidad, largo de array
 * \return int (-1) Error  - (0)  Ok
 */
 int initMenues(eMenu* menues,int cantidadMenues)
 {
     int i,retorno=-1;

     for(i=0;i<cantidadMenues;i++)
     {
         menues[i].isEmpty= ESTADO_LIBRE;
         retorno=0;
     }
     return retorno;
 }


/** \brief ordena los elemento de la estructura
 * \param list employee*
 * \param cantidad int
 * \return void
 */
 void ordenarMenues(eMenu* menues,int cantidadMenues)
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


 /** \brief modifica los datos de un menu en la estructura
 * \param eMenu menues, estructura de empleados
 * \param int cantidad de array
 * \param id int
 * \return int Return (-1)Error o (0) Ok
 *
 */
int modificarMenu(eMenu* menues, int cantidadMenues,int idAux)
{
    int retorno=-1,opcion,posicion;

    posicion= findMenuById(menues,cantidadMenues,idAux);

    if(posicion!= -1)
    {
        do
        {
            opcion= getValidIntOpcion("\tMENU -MODIFICAR-\n\n1-DESCRIPCION\n2-IMPORTE\n3-VOLVER\n","\n\tERROR\nOPCION NO VALIDA\n",1,3);

            switch(opcion)
            {
            case 1:
                system("cls");
                getValidString("INGRESE DESCRIPCION\n","\n\tERROR\nCARACTER NO VALIDO\n",menues[posicion].descripcion);
                break;

            case 2:
                system("cls");
                menues[posicion].importe= getValidFloat("INGRESE IMPORTE\n","\n\tERROR\nCARACTER NO VALIDO\n");
                break;
            }
        }
        while(opcion!=3);
        retorno=0;
    }
    return retorno;
}


 /** \brief realiza una baja logica colocando el estado en LIBRE
 * \param eMenu menues, estructura de empleados
 * \param int cantidad, largo de array
 * \param id int
 * \return int  ERROR(-1)  - (0)  Ok
 */
int removeMenu(eMenu* menues,int cantidadMenues,int id)
 {
     int i, retorno=-1;


         for(i=0;i<cantidadMenues;i++)
         {
             if(menues[i].idMenu==id)
             {
                 menues[i].isEmpty=ESTADO_LIBRE;
                 retorno=0;
                 break;
             }
         }

     return retorno;
 }


/** \brief da por alta un menu en la estructura de eMenu
 * \param eMenu menues, estructura de empleados
 * \param int cantidad, largo de array
 * \return int  (-1)  - (0)  Ok
 */
int addMenu(eMenu* menues,int cantidad)
{
    int posicionAux,retorno=-1;

    if(cantidad>=0)
    {
        posicionAux= menu_findIsEmpty(menues,cantidad);

        if(posicionAux!=-1)
        {
            getValidString("INGRESE DESCRIPCION DEL MENU\n","\n\tERROR\nCARACTER NO VALIDO\n",menues[posicionAux].descripcion);
            menues[posicionAux].importe= getValidFloat("INGRESE IMPORTE DE MENU\n","\n\tERROR\nCARACTER NO VALIDO\n");
            menues[posicionAux].idMenu= array_generarProximoIdMenues();
            menues[posicionAux].isEmpty= ESTADO_OCUPADO;
            system("cls");
            retorno=0;
        }
    }
    return retorno;
}


 /** \brief calcula el total de los importes
 * \param eMenu menues, estructura de menues
 * \param int cantidadMenues, largo de array
 * \return float, importe totales
 *
 */
float totalImporteMenues(eMenu* menues,int cantidadMenues)
{
    int i, acumulador=0;

    for(i=0;i<cantidadMenues;i++)
    {
        if(menues[i].isEmpty==ESTADO_OCUPADO)
        {
            acumulador=acumulador+ menues[i].importe;
        }
    }
    return acumulador;
}


 /** \brief calcula el promedio de los importes
 * \param eMenu menues, estructuras de menues
 * \param int cantidadMenues, largo de array
 * \return float, promedio de los menues
 */
float promedioImporteMenues(eMenu* menues,int cantidadMenues)
{
    int i,contador=0;
    float acumulador=0;

    for(i=0;i<cantidadMenues;i++)
    {
        if(menues[i].isEmpty==ESTADO_OCUPADO)
        {
            acumulador= acumulador+ menues[i].importe;
            contador++;
        }
    }
    return acumulador/(float)contador;
}


 /** \brief administra un menu, alta baja modificar y listar
 * \param eMenu menues, estructura de menu
 * \param int cantidad array de empleados
 * \return void
 */
void administrarMenues(eMenu* menues, int cantidadMenues)
{
    int i, opcion, idAux;

    do
    {
        system("cls");
        printf("\tMENU -MENUES-\n");
        opcion= getValidIntOpcion("\n1-ALTA\n2-MODIFICAR\n3-BAJA\n4-LISTAR\n5-VOLVER\n\n","\n\tERROR\nOPCION NO VALIDA\n",1,5);

        switch(opcion)
        {
            case 1://ALTA MENU
                system("cls");
                if(addMenu(menues,cantidadMenues)==0)
                getChar("MENU CARGADO CORRECTAMENTE\n");

                break;

            case 2://MODIFICAR MENUES
                system("cls");
                printf("ID\tPRECIO\t\tDESCRIPCION\n");
                for(i=0;i<cantidadMenues;i++)
                {
                    if(menues[i].isEmpty==ESTADO_OCUPADO)
                    {
                        printf("%d\t%.2f\t\t%s\n",menues[i].idMenu,menues[i].importe,menues[i].descripcion);
                    }
                }
                idAux= getValidIntOpcion("INGRESE ID A MODIFICAR\n","\n\tERROR\nOPCION NO VALIDA\n",0,cantidadMenues);
                system("cls");
                if(modificarMenu(menues,cantidadMenues,idAux)==0)
                {
                    system("cls");
                    getChar("SE HA MODIFICADO CORRECTAMENTE\n");
                }

                else
                    getChar("NO SE HA PODIDO MODIFICAR");

                break;

            case 3://BAJA
                system("cls");
                printf("ID\tPRECIO\t\tDESCRIPCION\n");
                for(i=0;i<cantidadMenues;i++)
                {
                    if(menues[i].isEmpty==ESTADO_OCUPADO)
                    {
                        printf("%d\t%.2f\t\t%s\n",menues[i].idMenu,menues[i].importe,menues[i].descripcion);
                    }
                }
                idAux= getValidIntOpcion("INGRESE ID A DAR DE BAJA\n","\n\tERROR\nOPCION NO VALIDA\n",0,cantidadMenues);
                if(removeMenu(menues,cantidadMenues,idAux)==0)
                {
                    system("cls");
                    getChar("SE HA DADO DE BAJA\n");
                }

                else
                    getChar("NO SE HA PODIDO DAR DE BAJA");

                break;

            case 4://IMPRIMIR
                system("cls");
                ordenarMenues(menues,cantidadMenues);
                printf("ID\tPRECIO\t\tDESCRIPCION\n\n");
                for(i=0;i<cantidadMenues;i++)
                {
                    if(menues[i].isEmpty==ESTADO_OCUPADO)
                    {
                        printf("%d\t%.2f\t\t%s\n",menues[i].idMenu,menues[i].importe,menues[i].descripcion);
                    }
                }
                getChar("");
                break;
        }
    }while(opcion!=5);
}


 /** \brief carga datos hardcodeados en la estructura de menues
 * \param eMenu menues, estructura de empleados
 * \param int cantidad, largo de array
 * \return void
 */
void hardcodearMenu(eMenu* menu,int cantidad)
{
    int i;
    char descripcionMenu[][40]={"Milanesas","Arroz","Fideos","Estofado","Sopa","Ensalada"};
    float importe[]={135,80,128,130,110,60};

    for(i=0;i<cantidad;i++)
    {
        menu[i].idMenu= array_generarProximoIdMenues();
        strcpy(menu[i].descripcion,descripcionMenu[i]);
        menu[i].importe= importe[i];
        menu[i].isEmpty= ESTADO_OCUPADO;
    }
}

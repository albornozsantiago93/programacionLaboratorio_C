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


 /** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
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


  /** \brief find an Employee by Id en returns the free place position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
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


  /** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
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
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 *
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


 /** \brief modifica datos en el arrey de menues
 * \param list employee*
 * \param cantidad int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
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


 /** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
 *
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


/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 *
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


 /** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
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


 /** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
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


 /** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
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
                printf("ID\tPRECIO\t\tDESCRIPCION\n");
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


 /** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
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

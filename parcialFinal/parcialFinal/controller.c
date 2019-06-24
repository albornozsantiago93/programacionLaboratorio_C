#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"
#include "funcionesGet.h"
#include "controller.h"
#include "parser.h"
#include "entidad.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
 int controller_loadFromText(char* path, LinkedList* pArrayListEntidad)
 {
     int retorno=-1;
     FILE* pFile;

     if(path!=NULL && pArrayListEntidad!=NULL)
     {
         pFile= fopen(path,"r");

         if(pFile!=NULL)
         {
             if(parser_entidadFromText(pFile,pArrayListEntidad)==0)
             {
                 retorno=0;
             }
         }
     }
     fclose(pFile);
     return retorno;
 }

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
 int controller_loadFromBinary(char* path, LinkedList* pArrayListEntidad)
 {
     int retorno=-1;
     FILE* pFile;

     if(path!=NULL && pArrayListEntidad!=NULL)
     {
         pFile= fopen(path,"rb");
         if(pFile!=NULL)
         {
             parser_entidadFromBinary(pFile,pArrayListEntidad);
             retorno=0;
             fclose(pFile);
         }
     }
     return retorno;
 }

 /** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
 int controller_addEntidad(LinkedList* pArrayListEntidad)
 {
     int retorno=-1;
     int horasTrabajadas, sueldo;
     char nombre[26], apellido[26];
     Entidad* entidadAux;

     if(pArrayListEntidad!=NULL)
     {
         getValidString("INGRESE NOMBRE:\n","ERROR",nombre);
         getValidString("INGRESE APELLIDO:\n","ERROR",apellido);
         horasTrabajadas= getValidIntOpcion("INGRESE CANTIDAD DE HORAS TRABAJADAS:\n","ERROR",0,90000);
         sueldo= getValidIntOpcion("INGRESE SUELDO\n","ERROR",100,999999999);
         entidadAux= entidad_new();

         if(entidadAux!=NULL)
         {
             if(entidad_setNombre(entidadAux,nombre)==0)
             {
                 if(entidad_setApellido(entidadAux,apellido)==0)
                 {
                     if(entidad_setHorasTrabajadas(entidadAux,horasTrabajadas)==0)
                     {
                         if(entidad_setId(entidadAux,0)!=-1)
                         {
                             if(entidad_setSueldo(entidadAux,sueldo)==0)
                             {
                                 ll_add(pArrayListEntidad,entidadAux);
                                 retorno=0;
                             }
                         }
                     }
                 }
             }
         }
         else
         {
             entidad_delete(entidadAux);
         }

     }
     return retorno;
 }


/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
 int controller_editEntidad(LinkedList* pArrayListEntidad)
 {
     int retorno=-1;
     int idAux,sueldoAux,cantidadHorasTrabajadasAux,lenght,i,idBuscador;
     char nombreAux[26],apellidoAux[27];
     int opcion=0;
     Entidad* entidadAux;

     if(pArrayListEntidad!=NULL)
     {
         lenght= ll_len(pArrayListEntidad);
         idBuscador= getValidIntOpcion("INGRESE SU ID PARA MODIFICAR:\n","ERROR",0,lenght);

         for(i=0;i<lenght;i++)
         {
             entidadAux= ll_get(pArrayListEntidad,i);
             if(entidad_getId(entidadAux,&idAux)!=-1)
             {
                 if(idAux== idBuscador)
                 {
                     getChar("ID ENCONTRADO\npress Enter\n");

                     do
                     {
                         opcion=getValidIntOpcion("\tMENU MODIFICAR\n\n1-NOMBRE\n2-APELLIDO\n3-SUELDO\n4-HORAS TRABAJADAS\n5-SALIR","ERROR",1,5);

                         switch(opcion)
                         {
                            case 1:
                                system("cls");
                                getValidString("INGRESE NOMBRE:\n","ERROR\n",nombreAux);
                                entidad_setNombre(entidadAux,nombreAux);
                                break;

                            case 2:
                                system("cls");
                                getValidString("INGRESE APELLIDO:\n","ERRO",apellidoAux),
                                entidad_setApellido(entidadAux,apellidoAux);
                                break;

                            case 3:
                                system("cls");
                                sueldoAux= getValidInt("INGRESE SUELDO:","ERROR");
                                entidad_setSueldo(entidadAux,sueldoAux);
                                break;

                            case 4:
                                system("cls");
                                cantidadHorasTrabajadasAux=getValidIntOpcion("INGRESE HS TRABAJADAS:\n","ERROR",1,900000);
                                entidad_setHorasTrabajadas(entidadAux,cantidadHorasTrabajadasAux);
                                break;
                         }

                     }while(opcion!=5);
                     retorno=0;
                 }
             }
         }
     }
     return retorno;
 }


 /** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
 int controller_removeEntidad(LinkedList* pArrayListEntidad)
 {
     int retorno=-1;
     int i,lenght,idAux,idBuscador;
     Entidad* entidadAux;

     if(pArrayListEntidad!=NULL)
     {
         lenght= ll_len(pArrayListEntidad);
         idBuscador= getValidIntOpcion("INGRESE ID PARA DAR DE BAJA\n","ERROR\n",0,lenght);

         for(i=0;i<lenght;i++)
         {
             entidadAux= ll_get(pArrayListEntidad,i);

             if(entidad_getId(entidadAux,&idAux)!=-1)
             {
                 if(idAux==idBuscador)
                 {
                     getChar("ID ENCONTRADO\npressEnter\n");
                     ll_remove(pArrayListEntidad,i);
                     retorno=0;
                     break;
                 }
             }
         }
     }
     return retorno;
 }


 /** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return void
 *
 */
 void controller_listEntidad(LinkedList* pArrayListEntidad)
 {
     int i,lenght,idAux,sueldoAux,horasTrabajadasAux;
     char nombreAux[25],apellidoAux[29];
     Entidad* entidadAux;

     if(pArrayListEntidad!=NULL)
     {
         lenght= ll_len(pArrayListEntidad);

         for(i=0;i<lenght;i++)
         {
             entidadAux= ll_get(pArrayListEntidad,i);
             entidad_getNombre(entidadAux,nombreAux);
             entidad_getApellido(entidadAux,apellidoAux);
             entidad_getSueldo(entidadAux,&sueldoAux);
             entidad_getHorasTrabajadas(entidadAux,&horasTrabajadasAux);
             entidad_getId(entidadAux,&idAux);

             printf("%d- %s %s -%d - %d \n",idAux,nombreAux,apellidoAux,horasTrabajadasAux,sueldoAux);
         }
     }
 }

 /** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
 int controller_saveAsText(char* path, LinkedList* pArrayListEntidad)
 {
     int retorno=-1;
     FILE* pFile;
     int i,lenght,idAux,horasTrabajadasAux,sueldoAux;
     char nombreAux[29], apellidoAux[28];
     Entidad* entidadAux;

     if(path!=NULL && pArrayListEntidad!=NULL)
     {
         pFile= fopen(path,"w");
         lenght= ll_len(pArrayListEntidad);

         if(pFile!=NULL)
         {
             fprintf(pFile,"ID  NOMBRE   APELLIDO   hsTRABAJADAS SUELDO");

             for(i=0;i<lenght;i++)
             {
                 entidadAux= ll_get(pArrayListEntidad,i);
                 entidad_getApellido(entidadAux,apellidoAux);
                 entidad_getNombre(entidadAux,nombreAux);
                 entidad_getId(entidadAux,&idAux);
                 entidad_getHorasTrabajadas(entidadAux,&horasTrabajadasAux);
                 entidad_getSueldo(entidadAux,&sueldoAux);
                 fprintf(pFile,"%d,%s,%s,%d,%d\n",idAux,nombreAux,apellidoAux,horasTrabajadasAux,sueldoAux);
             }
            fclose(pFile);
            retorno=0;
         }
     }
     return retorno;
 }


 /** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEntidad)
{
    int retorno=-1;
    FILE* pFile;
    int i,lenght;
    Entidad* entidadAux;

    if(path!=NULL && pArrayListEntidad!=NULL)
    {
        pFile= fopen(path,"wb");
        lenght= ll_len(pArrayListEntidad);

        if(pFile!=NULL)
        {
            for(i=0;i<lenght;i++)
            {
                entidadAux= ll_get(pArrayListEntidad,i);

                if(entidadAux!=NULL)
                {
                    fwrite(entidadAux,sizeof(Entidad),1,pFile);
                }
            }
            fclose(pFile);
            retorno=0;
        }
    }
    return retorno;
}

 /** \brief Ordena por criterio
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
 int controller_criterioNombre(void* thisA,void* thisB)
{
    int retorno=0;
    char nombreA[1024];
    char nombreB[1024];
    entidad_getNombre((Entidad*)thisA,nombreA);
    entidad_getNombre((Entidad*)thisB,nombreB);
    if(strcmp(nombreA,nombreB)>0)
    {
        retorno=1;
    }else if(strcmp(nombreA,nombreB)<0)
    {
        retorno=-1;
    }
    return retorno;
}

/** \brief Ordenar entidades por nombre
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 0 OK
 *
 */
int controller_sortEntidad(LinkedList* pArrayListEntidad)
{
    int retorno=-1;
    if(pArrayListEntidad!=NULL)
    {
        ll_sort(pArrayListEntidad,controller_criterioNombre,1);
        retorno=0;
    }
    return retorno;
}

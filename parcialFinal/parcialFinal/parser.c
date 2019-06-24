#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"
#include "entidad.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
 int parser_entidadFromText(FILE* pFile, LinkedList* pArrayListEntidad)
 {
     int cantidad;
     int retorno= -1;
     char idAux[25],nombreAux[25],apellidoAux[25],sueldoAux[25],horasTrabajadas[25];
     Entidad* entidadAux;

     if(pFile!=NULL && pArrayListEntidad!=NULL)
     {
         cantidad= fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idAux,nombreAux,apellidoAux,horasTrabajadas,sueldoAux);

         do
         {
             cantidad= fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idAux,nombreAux,apellidoAux,horasTrabajadas,sueldoAux);

             if(cantidad==5)
             {
                entidadAux= entidad_newParametros(idAux,nombreAux,apellidoAux,horasTrabajadas,sueldoAux);

                if(entidadAux!=NULL)
                {
                    ll_add(pArrayListEntidad,entidadAux);
                }
             }
         }while(!feof(pFile));
         retorno=0;
     }
     return retorno;
 }


 /** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
 int parser_entidadFromBinary(FILE* pFile, LinkedList* pArrayListEntidad)
 {
     int retorno=-1;
     Entidad* entidadAux;

     if(pFile!=NULL && pArrayListEntidad!=NULL)
     {
         do
         {
             entidadAux= entidad_new();

             if(fread(entidadAux,sizeof(Entidad),1,pFile)==1)
             {
                 ll_add(pArrayListEntidad,entidadAux);
             }
             else
             {
                 entidad_delete(entidadAux);
             }
         }while(!feof(pFile));
         retorno=0;
     }
     return retorno;
 }

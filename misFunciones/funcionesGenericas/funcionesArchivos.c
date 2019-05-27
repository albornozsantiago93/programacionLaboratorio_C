#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <time.h>
#include "funcionesArchivos.h"
#include "funcionesGet.h"



int generarArchivo(FILE* auxiliar)
{
    FILE* bin;
    int retorno=0;

   if((bin=fopen(ARCH,"rb+"))==NULL)
    {
      if ((bin=fopen(ARCH,"wb+"))==NULL)
      {
         printf("No se pudo abrir el archivo");
         retorno=1;
      }
   }
   return retorno;
}

/**
 * \brief lee archivo de datos bin
 * \param eEstructuraUno
 * \param array, array de la estructira recibida por referencia
 * \param lenght, longitud del array
 * \param mensajeError mensaje al usuario
 * \return 0 OK  o -1 error
 */
 int arrayMovie_leerArchivo(eEstructuraUno* array,char* mensajeError,int lenght)
 {
     FILE* pArchivo;
     int cantLeida,retorno;

     pArchivo=fopen("datos.txt","r");
     rewind(pArchivo);

     if(pArchivo==NULL)
     {
         printf("%s",mensajeError);
     }
     else
     {
         while(!feof(pArchivo))
         {
             cantLeida=fread(&array,sizeof(array),lenght,pArchivo);

             if(cantLeida!= lenght)
             {
                 if(feof(pArchivo))
                 {
                     retorno=0;//se llego al final del archivo, sale
                     break;
                 }
                 else
                 {
                     retorno=-1;//no se pudo llegar a leer el final del archivo
                     break;
                 }
             }
         }
     }
     fclose(pArchivo);
     return retorno;
 }

  /**
 * \brief escribe en el archivo de datos
 * \param arrayMovie, array de la estructira recibida por referencia
 * \param lenght, longitud del array
 * \param mensajeError mensaje al usuario
 * \return 0 OK  o -1 error
 */
int arrayMovie_escribirArchivo(eEstructuraUno* array,char* mensajeError,int lenght)
 {
     FILE* pArchivo;
     int cantEscrita, retorno;

     pArchivo= fopen("datos.txt","w");
     if(pArchivo==NULL)
     {
         printf("%s",mensajeError);
     }

     else
     {
         cantEscrita= fwrite(&array,sizeof(array),lenght,pArchivo);
         if(cantEscrita<lenght)
            retorno=-1;
     }
     fclose(pArchivo);
     return retorno;
 }


   /**
 * \brief escribe en el archivo de datos
 * \param arrayMovie, array de la estructira recibida por referencia
 * \param lenght, longitud del array
 * \param mensajeError mensaje al usuario
 * \return 0 OK  o -1 error
 */
void arrayMovie_imprimir(eEstructuraUno* array,char* mensajeError,int lenght)
{
    int i;

    for(i=0; i<lenght; i++)
    {
        if(array[i].isEmpty== ESTADO_OCUPADO)
        {

        }
    }
}


  /**
 * \brief escribe en el archivo de datos
 * \param arrayMovie, array de la estructira recibida por referencia
 * \param lenght, longitud del array
 * \param mensajeError mensaje al usuario
 * \return 0 OK  o -1 error
 */

 int cargarPersona()
 {
     FILE* pArchivo;
     int retorno=0;
     char nombre[21];
     char* nombreArchivo= "texto";

     pArchivo= fopen(nombreArchivo, "a");//agrega un nombre al final del texto
     if(pArchivo==NULL)
        retorno= -1;

     getValidString("Ingrese nombre:\n","ERROR",nombre);

     fprintf(pArchivo,"%s \n",nombre);

     fclose(pArchivo);
     return retorno;
 }


  /**
 * \brief escribe en el archivo de datos
 * \param arrayMovie, array de la estructira recibida por referencia
 * \param lenght, longitud del array
 * \param mensajeError mensaje al usuario
 * \return 0 OK  o -1 error
 */

 int verPersona()
 {
     FILE* pArchivo;
     char* nombreArchivo= "texto";
     char buffer[200];
     int cantEscrita=0;
     int retorno=0;

     pArchivo= fopen(nombreArchivo, "r");
     if(pArchivo==NULL)
        retorno= -1;

        cantEscrita= fscanf(pArchivo, "%s",buffer);

        while(cantEscrita!=EOF)
        {
            printf("%s\n",buffer);
            cantEscrita= fscanf(pArchivo,"%s",buffer);
        }
     fclose(pArchivo);
     return retorno;
 }

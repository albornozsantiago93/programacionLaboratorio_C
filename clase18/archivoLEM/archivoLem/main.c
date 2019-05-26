#include <stdio.h>
#include <stdlib.h>

#define ARCH	".\\bin.dat"
#define ESC 27

struct a{
		char nombre[31];
		int edad;
		int legajo;
	};

int main (void)
{
   FILE  *bin;
   struct a pers;
   int cant;
   int legajoAux;

   if ((bin=fopen(ARCH,"rb+"))==NULL){
      if ((bin=fopen(ARCH,"wb+"))==NULL){
         printf("No se pudo abrir el archivo");
         exit(1);
      }
   }

   do{
      printf("\nIngrese el nombre: ");
      gets(pers.nombre);

      printf("Ingrese la edad: ");
      scanf("%d",&pers.edad);

      printf("Ingrese la legajo: ");
      scanf("%d",&pers.legajo);

      fflush(stdin);
      fseek(bin , 0L, SEEK_END);//coloca el indicador al final
      fwrite(&pers,sizeof(pers),1,bin);//escribe lo ingresado en la posicion indicada anteriormente

      printf("\nPresione ESC para terminar");
   }while((getche())!=ESC);

   /* Busqueda */
   system("cls");
   printf("Legajo: ");
   scanf("%d", &legajoAux);

   //se lleva el indicador de posición al principio para comenzar a leer
   rewind (bin);//coloca el indicador al inicio del archivo

   while(!feof(bin)){//mientras no llegue al final
      cant = fread(&pers,sizeof(pers),1,bin);//lee la cantidad del archivo, y lo aloja en cant

      if(cant!=1){//si no leyo nada
         if(feof(bin)){//si se llego al final del archivo, sale
			break;
         }
         else{
			printf("No leyo el ultimo registro");//no se pudo llegar al final del archivo
			break;
         }
      }

      if(legajoAux == pers.legajo){//busca la coincidencia de un legajo y modifica los parametros
        printf("\nIngrese nuevo nombre: ");
        fflush(stdin);
        gets(pers.nombre);

        fseek(bin , (long) (-1) * sizeof(pers), SEEK_CUR);//busca en la ocurrencia y coloca el indicador en el inicio de la estructura
        fflush(stdin);
        fwrite(&pers,sizeof(pers),1,bin);//escribe en la estructura
        break;
      }

      //printf("\n%s\t%d",pers.nombre,pers.edad);
   }

   //se lleva el indicador de posición al principio para comenzar a leer
   rewind (bin);

   while(!feof(bin)){
      cant = fread(&pers,sizeof(pers),1,bin);

      if(cant!=1){
         if(feof(bin)){
			break;
         }
         else{
			printf("No leyo el ultimo registro");
			break;
         }
      }

      printf("\n%s\t%d",pers.nombre,pers.edad);
   }

   fclose(bin);
   getch();

   return 0;
}


/*REALIZAR UN ABM,LISTAR
ALTA ESCRIBIR
BAJA LOGICA isEmty, SE AGREGA A LA ESTRUCTURA
LISTAR UNO Y LISTAR TODO*/

#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"
#include "entidad.h"
#include "funcionesGet.h"
#include "controller.h"
#include "parser.h"


int main()
{
    int opcion=0;
    LinkedList* listaEntidad= ll_newLinkedList();

    do
    {
        system("cls");
        opcion=getValidIntOpcion("\tMENU\n\n1-ALTA\n2-BAJA\n3-MODIFICAR\n4-CARGAR\n5-GUARDAR\n6-ORDENAR\n7-LISTAR\n8-SALIR\n","ERROR",1,8);

        switch(opcion)
        {
            case 1:
                system("cls");
                if(controller_addEntidad(listaEntidad)==0)
                {
                    getChar("SE HA DADO DE ALTA\n");
                }
                break;

            case 2:
                system("cls");
                if(controller_removeEntidad(listaEntidad)==0)
                {
                    getChar("SE HA DADO DE BAJA\n");
                }
                break;

            case 3:
                system("cls");
                if(controller_editEntidad(listaEntidad)==0)
                {
                    getChar("SE HA MODIFICADO\n");
                }
                break;

            case 4:
                system("cls");
                if(controller_loadFromBinary("data.bin",listaEntidad)==0)
                {
                    getChar("SE HA CARGADO LISTA\n");
                }
                break;

            case 5:
                system("cls");
                if(controller_saveAsBinary("data.bin",listaEntidad)==0)
                {
                    getChar("SE HA GUARDADO LISTA\n");
                }
                break;

            case 6:
                system("cls");
                if(controller_sortEntidad(listaEntidad)==0)
                {
                    getChar("SE HAN ORDENADO POR NOMBRE\n");
                }
                break;

            case 7:
                system("cls");
                controller_listEntidad(listaEntidad);
                break;
        }


    }while(opcion!=8);

    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <time.h>
#include "estructuraUno.h"
#include "funcionesGet.h"

static int idAutoincrementable= 0;


/**
 * \brief Genera un id que se ira autoincrementando
 * \param void
 * \return int, id unico generado
 *
 */
int genericoUno_array_generarProximoId(void)
{
    idAutoincrementable ++;
    return idAutoincrementable;
}


/** \brief inicializa el estado de un array
 * \param eAlmuerzos almuerzos, estructura de almuerzos
 * \param int cantidad, largo de array
 * \return int (-1) Error  - (0)  Ok
 */
int genericoUno_init(eEstructuraUno* estructura ,int cantidad)
{
    int i, retorno=-1;


    for(i=0; i<cantidad; i++)
    {
        estructura[i].isEmpty= ESTADO_LIBRE;
    }
    retorno=0;

    return retorno;
}


 /** \brief encuentra un lugar disponible en el array
 * \param eAlmuerzos almuerzos, estructura de almuerzos
 * \param int cantidad, largo de array
 * \return int  (-1)  - Numero !=-1 (ubicacion disponible en array)
 */
int genericoUno_findIsEmpty(eEstructuraUno* estructura,int cantidad)
{
    int i,retorno=-1;


    for(i=0; i<cantidad; i++)
    {
        if(estructura[i].isEmpty==ESTADO_LIBRE)
        {
            retorno= i;
            break;
        }
    }

    return retorno;
}


/** \brief encuentra por id un dato de la estructura
 * \param eEmployee empleado, estructura de empleados
 * \param int cantidad, largo de array
 * \param int id, referencia a buscar
 * \return int  (-1)  - Numero id !=-1
 */
int genericoUno_findById(eEstructuraUno* estructura ,int cantidad,int id)
 {
     int i,retorno=-1;


        for(i=0;i<cantidad;i++)
        {
            if(estructura[i].isEmpty== ESTADO_OCUPADO && estructura[i].idUnico== id)
            {
                retorno= i;
                break;
            }
        }

     return retorno;
 }


  /** \brief imprime por pantalla una estructura de empleado
 * \param eEmployee empleado, estructura de empleados
 * \param eSector sectores, array de sectores
 * \param int cantidad de array
 * \return void
 */
void genericoUno_print(eEstructuraUno estructura,eSector* sectores,int cantidad)//IMPRIME UNO A MUCHOS
{
    int i;
    char descripcionAux[31];

    for(i=0; i<cantidad; i++)
    {
        if(estructura.idSector==sectores[i].idSector)
        {
            strcpy(descripcionAux,sectores[i].descripcionSector);
            break;
        }
    }
    printf("%d\t%s\t\t\t%.2f\t%d/%d/%d\t%s\n",estructura.idUnico,estructura.name,estructura.salary,estructura.fechaIngreso.dia,estructura.fechaIngreso.mes,estructura.fechaIngreso.anio,descripcionAux);
 }


 /** \brief imprime por pantalla lista de empleados y su sector correspondiente
 * \param eEmployee empleado, estructura de empleados
 * \param eSector sectores, array de sectores
 * \return int cantidad de array
 * \return void
 */
void genericoUno_printList(eEstructuraUno* estructura,int cantidad,eSector* sectores)
{
    int i;

    for(i=0; i<cantidad; i++)
    {
        if(estructura[i].isEmpty==ESTADO_OCUPADO)
        {
            genericoUno_print(estructura[i],sectores,cantidad);
        }
    }
}


/** \brief realiza una baja logica colocando el estado en LIBRE
 * \param eEmployee empleado, estructura de empleados
 * \param int cantidad, largo de array
 * \param id int
 * \return int  ERROR(-1)  - (0)  Ok
 */
int genericoUno_remove(eEstructuraUno* estructura,int cantidad,int id)
 {
     int i, retorno=-1;


         for(i=0;i<cantidad;i++)
         {
             if(estructura[i].idUnico==id)
             {
                 estructura[i].isEmpty=ESTADO_LIBRE;
                 retorno=0;
                 break;
             }
         }
     return retorno;
 }


 /** \brief da por alta a un empleado en la estructura de eEmpleados
 * \param eEmployee empleado, estructura de empleados
 * \param int cantidad, largo de array
 * \return int  (-1)  - (0)  Ok
 */
int genericoUno_add(eEstructuraUno* estructura,int cantidad)
{
    int posicionAux,retorno=-1;

    if(cantidad>=0)
    {
        posicionAux= genericoUno_findIsEmpty(estructura,cantidad);

        if(posicionAux!=-1)
        {
            getValidString("INGRESE NOMBRE:\n","\tERROR\nCARACTER NO VALIDO",estructura[posicionAux].name);
            estructura[posicionAux].salary= getValidFloat("INGRESE SUELDO\n","\tERROR\nOPCION NO VALIDA");
            estructura[posicionAux].idUnico= genericoUno_array_generarProximoId();
            system("cls");
            estructura[posicionAux].dni= getValidIntOpcion("INGRESE OPCION\n","\tERROR\nCARACTER NO VALIDO",0,20000);
            system("cls");
            estructura[posicionAux].fechaIngreso.anio= getValidIntOpcion("INGRESE ANIO DE INGRESO\n ","\tERROR\nOPCION NO VALIDA",1950,2019);
            estructura[posicionAux].fechaIngreso.mes= getValidIntOpcion("INGRESE MES DE INGRESO\n ","\tERROR\nOPCION NO VALIDA",1,12);
            estructura[posicionAux].fechaIngreso.dia= getValidIntOpcion("INGRESE DIA DE INGRESO\n ","\tERROR\nOPCION NO VALIDA",1,31);
            system("cls");
            estructura[posicionAux].idSector= getValidIntOpcion("\tMENU -SECTORES-\n1-COMPRAS\n2-VENTAS\n3-RRHH\n","\tERROR\nOPCION NO VALIDA",1,3);
            estructura[posicionAux].isEmpty= ESTADO_OCUPADO;
            system("cls");
            retorno=0;
            getChar("SE HA CARGADO EMPLEADO\n\n");
        }
    }
    return retorno;
}


 /** \brief carga datos hardcodeados en la estructura de empleados
 * \param eEmployee empleado, estructura de empleados
 * \param int cantidad, largo de array
 * \return void
 */
void genericoUno_hardcodearDatos(eEstructuraUno* estructura , int cantidad)
{
    int i;
    char nombres[][50]= {"Josue","Maria","Carlos","Pedro","Sofia","Mateo"};
    float sueldosBruto[]= {22000,22000,15000,48000,21000,36000};
    int dni[]={100001,10002,100003,100004,100005,100006};
    int idSector[]= {1,2,3,1,2,2};

    eFecha unaFecha = {22,04,2019};


    for(i=0; i<cantidad; i++)
    {
        estructura[i].idUnico=genericoUno_array_generarProximoId();
        strcpy(estructura[i].name,nombres[i]);
        estructura[i].salary= sueldosBruto[i];
        estructura[i].idSector= idSector[i];
        estructura[i].fechaIngreso= unaFecha;
        estructura[i].isEmpty= ESTADO_OCUPADO;
        estructura[i].dni= dni[i];
    }
}


 /** \brief modifica los datos de un empleado en la estructura
 * \param eEmployee empleado, estructura de empleados
 * \param int cantidad de array
 * \param id int
 * \return int Return (-1)Error o (0) Ok
 */
int genericoUno_modificar(eEstructuraUno* estructura, int cantidad,int id)
{
    int idAux,retorno=-1,opcion;

    idAux= genericoUno_findById(estructura,cantidad,id);

    if(idAux!= -1)
    {
        do
        {
            system("cls");
            printf("\tMENU -MODIFICAR-\n");
            opcion= getValidIntOpcion("\n1-NOMBRE\n2-DNI\n3-SALARIO\n4-FECHA DE INGRESE\n5-SECTOR\n6-VOLVER\n","\tERROR\nOPCION NO VALIDA\n",1,6);

            switch(opcion)
            {
            case 1:
                system("cls");
                getValidString("INGRESE NOMBRE\n","\tERROR\nCARACTER NO VALIDO\n",estructura[idAux].name);
                break;

            case 2:
                system("cls");
                estructura[idAux].dni= getValidInt("INGRESE DNI\n","\tERROR\nCARACTER NO VALIDO");
                break;

            case 3:
                system("cls");
                estructura[idAux].salary= getValidFloat("INGRESE SUELDO \n","\tERRORr\nCARACTER NO VALIDO");
                break;

            case 4:
                system("cls");
                estructura[idAux].fechaIngreso.dia= getValidIntOpcion("INGRESE DIA\n","\tERROR\nOPCION NO VALIDA",1,31);
                estructura[idAux].fechaIngreso.mes= getValidIntOpcion("INGRESE MES\n","\tERROR\nOPCION NO VALIDA",1,12);
                estructura[idAux].fechaIngreso.anio= getValidIntOpcion("INGRESE ANIO\n","\tERROR\nOPCION NO VALIDA",1950,2019);
                break;

            case 5:
                system("cls");
                estructura[idAux].idSector= getValidIntOpcion("\tOPCIONES -SECTORES-\n1-COMPRAS\n2-ENTAS\n3-RRHH\n","\tERROR\nOPCION NO VALIDA",1,3);
                break;
            }
        }
        while(opcion!=6);
        retorno=0;
    }
    return retorno;
}


/** \brief administra un empleado, alta baja modificar y listar
 * \param eEmployee empleado, estructura de empleados
 * \param eSector sectores, array de sectores
 * \param int cantidad array de empleados
 * \return void
 */
void genericoUno_admin(eEstructuraUno* estructura,eSector* sectores,int cantidad)
{
    int opcion,idAux;

    do
    {
        system("cls");
        printf("\tMENU -EMPLEADOS-\n");
        opcion= getValidIntOpcion("\n1-ALTA\n2-MODIFICAR\n3-BAJA\n4-LISTAR\n5-VOLVER\n\n","\tERROR\nOPCION NO VALIDA",1,5);

        switch(opcion)
        {
        case 1://ALTA EMPLEADO
            system("cls");
            genericoUno_add(estructura,cantidad);
            break;

        case 2://MODIFICAR EMPLEADO
            system("cls");
            printf("ID\tNOMBRE\t\tAPELLIDO\tSEXO\t\tSALARIO\t\tFECHA\t\tSECTOR\n");
            genericoUno_printList(estructura,cantidad,sectores);
            idAux=getValidIntOpcion("\nINGRESE ID DE EMPLEADO A MODIFICAR\n","\tERROR\nOPCION NO VALIDA\n",1,cantidad);
            if(genericoUno_modificar(estructura,cantidad,idAux)==0){
                getChar("ID MODIFICADO CORRECTAMENTE\n");}

                else
                    printf("ID NO DISPONIBLE");

                break;

        case 3://BAJA EMPLEADO
            system("cls");
            printf("ID\tNOMBRE\t\tSALARIO\t\tFECHA\t\tSECTOR\n");
            genericoUno_printList(estructura,cantidad,sectores);
            idAux=getValidIntOpcion("\nINGRESE ID DE EMPLEADO A DAR DE BAJA\n","\tERROR\nOPCION NO VALIDA\n",1,cantidad);
            if(genericoUno_remove(estructura,cantidad,idAux)==0){
                getChar("ID DADO DE BAJA\n");}

                else
                    printf("ID NO DISPONIBLE");

                break;

        case 4://IMPRIMIR LISTA EMPLEADO
            system("cls");
            printf("ID\tNOMBRE\t\t\tSALARIO\t\tFECHA\t\tSECTOR\n\n");
            genericoUno_printList(estructura,cantidad,sectores);
            getChar("");
            break;
        }

    }while(opcion!=5);
}


 /** \brief cuenta la cantidad de  qe no superan los 125
 * \param eAlmuerzos almuerzos, estructura de almuerzos
 * \param int cantidad, largo de array
 * \return int, cantidad de  que no superan los 125
 */
int menuesMenores125(eEstructuraUno* estructura,int cantidad)
{
    int i, contadorMenores125=0;

    for(i=0; i<cantidad; i++)
    {
        if(estructura[i].isEmpty==ESTADO_OCUPADO)
        {
            if(estructura[i].salary<125)
            {
                contadorMenores125++;
            }
        }
    }
    return contadorMenores125;
}


 /** \brief cuenta la cantidad de  que superan los 125
 * \param eAlmuerzos almuerzos, estructura de almuerzos
 * \param int cantidad, largo de array
 * \return int, cantidad de  que superan los 125
 */
int menuesMayores125(eEstructuraUno* estructura,int cantidad)
{
    int i, contadorMayores125=0;

    for(i=0; i<cantidad; i++)
    {
        if(estructura[i].isEmpty==ESTADO_OCUPADO)
        {
            if(estructura[i].salary>125)
            {
                contadorMayores125++;
            }
        }
    }
    return contadorMayores125;
}


 /** \brief calcula el total de los importes
 * \param eMenu menues, estructura de menues
 * \param int cantidadMenues, largo de array
 * \return float, importe totales
 *
 */
float totalImporte(eEstructuraUno* estructura,int cantidad)
{
    int i, acumulador=0;

    for(i=0;i<cantidad;i++)
    {
        if(estructura[i].isEmpty==ESTADO_OCUPADO)
        {
            acumulador=acumulador+ estructura[i].salary;
        }
    }
    return acumulador;
}


 /** \brief calcula el promedio de los importes
 * \param eMenu menues, estructuras de menues
 * \param int cantidadMenues, largo de array
 * \return float, promedio de los menues
 */
float promedioImporte(eEstructuraUno* estructura,int cantidad)
{
    int i,contador=0;
    float acumulador=0;

    for(i=0;i<cantidad;i++)
    {
        if(estructura[i].isEmpty==ESTADO_OCUPADO)
        {
            acumulador= acumulador+ estructura[i].salary;
            contador++;
        }
    }
    return acumulador/(float)contador;
}


 /** \brief calcula el valor minimo
 * \param eEstructura, estructuras de numeros a calcular
 * \param int cantidad, largo de array
 * \return int, numero con valor minimo
 */
int genericoUno_calcularMnimo(eEstructuraUno* estructura, int cantidad)
{
    int i;
    int minimo;

    minimo = estructura[0].salary;

    for(i=0; i<cantidad; i++)
    {
        if(estructura[i].salary < minimo)
            minimo = estructura[i].salary;
    }
    return minimo;
}


 /** \brief calcula el valor maximo
 * \param eEstructura, estructuras de numeros a calcular
 * \param int cantidad, largo de array
 * \return int, numero con valor maximo
 */
int genericoUno_calcularMaximo(eEstructuraUno* estructura,int cantidad)
{
  int i;
  int maximo;

  maximo = estructura[0].salary;
  for (i=0;i <cantidad;i++)
  {
    if (estructura[i].salary> maximo)
	  maximo = estructura[i].salary;
  }
  return maximo;
}


/** \brief ordena los elemento de la estructura
 * \param eEstructura
 * \param cantidad int
 * \return void
 */
void genericoUno_ordenar(eEstructuraUno* estructura,int cantidad)
{
    int i,j;
    eEstructuraUno aux;

    for(i=0;i<cantidad-1;i++)
    {
        for(j=i+1;j<cantidad;j++)
        {
            if(estructura[i].salary< estructura[j].salary)
            {
                aux=estructura[i];
                estructura[i]=estructura[j];
                estructura[j]=aux;
            }
        }
    }
}



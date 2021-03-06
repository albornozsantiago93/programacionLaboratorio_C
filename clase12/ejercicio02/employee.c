#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <time.h>
#include "employee.h"
#include "menues.h"
#include "funcionesGet.h"


static int idAutoincrementable= 0;

/**
 * \brief Genera un id que se ira autoincrementando
 * \param void
 * \return int, id unico generado
 */
int array_generarProximoId(void)
{
    idAutoincrementable ++;
    return idAutoincrementable;
}


/** \brief inicializa el estado de un array
 * \param eEmployee empleado, estructura de empleados
 * \param int cantidad, largo de array
 * \return int (-1) Error  - (0)  Ok
 */
int initEmployees(eEmployee* empleados,int cantidad)
{
    int i, retorno=-1;


        for(i=0;i<cantidad;i++)
        {
            empleados[i].isEmpty=ESTADO_LIBRE;
        }
        retorno=0;

    return retorno;
}


/** \brief da por alta a un empleado en la estructura de eEmpleados
 * \param eEmployee empleado, estructura de empleados
 * \param int cantidad, largo de array
 * \return int  (-1)  - (0)  Ok
 */
int addEmployee(eEmployee* empleados,int cantidad)
{
    int posicionAux,retorno=-1;

    if(cantidad>=0)
    {
        posicionAux= findIsEmpty(empleados,cantidad);

        if(posicionAux!=-1)
        {
            getValidString("INGRESE NOMBRE\n","\tERROR\nOPCION NO VALIDA",empleados[posicionAux].name);
            getValidString("INGRESE APELLIDO\n","\tERROR\nOPCION NO VALIDA",empleados[posicionAux].lastName);
            empleados[posicionAux].salary= getValidFloat("INGRESE SUELDO\n","\tERROR\nOPCION NO VALIDA");
            empleados[posicionAux].id= array_generarProximoId();
            system("cls");
            empleados[posicionAux].fechaIngreso.anio= getValidIntOpcion("INGRESE ANIO DE INGRESO\n ","\tERROR\nOPCION NO VALIDA",1950,2019);
            empleados[posicionAux].fechaIngreso.mes= getValidIntOpcion("INGRESE MES DE INGRESO\n ","\tERROR\nOPCION NO VALIDA",1,12);
            empleados[posicionAux].fechaIngreso.dia= getValidIntOpcion("INGRESE DIA DE INGRESO\n ","\tERROR\nOPCION NO VALIDA",1,31);
            system("cls");
            getValidString("\tESCOGA SEXO\n(F)FEMENINO\n(M)MASCULINO\n","CARACTER NO VALIDO\n",empleados[posicionAux].sexo);
            system("cls");
            empleados[posicionAux].idSector= getValidIntOpcion("\tMENU -SECTORES-\n1-COMPRAS\n2-VENTAS\n3-RRHH\n","\tERROR\nOPCION NO VALIDA",1,3);
            empleados[posicionAux].isEmpty= ESTADO_OCUPADO;
            system("cls");
            retorno=0;
            getChar("SE HA CARGADO EMPLEADO\n\n");
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
int findEmployeeById(eEmployee* empleados,int cantidad,int id)
 {
     int i,retorno=-1;


        for(i=0;i<cantidad;i++)
        {
            if(empleados[i].isEmpty== ESTADO_OCUPADO && empleados[i].id== id)
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
int findIsEmpty(eEmployee* empleados,int cantidad)
 {
     int i,retorno=-1;


        for(i=0;i<cantidad;i++)
        {
            if(empleados[i].isEmpty==ESTADO_LIBRE)
            {
                retorno= i;
                break;
            }
        }

     return retorno;
 }


 /** \brief realiza una baja logica colocando el estado en LIBRE
 * \param eEmployee empleado, estructura de empleados
 * \param int cantidad, largo de array
 * \param id int
 * \return int  ERROR(-1)  - (0)  Ok
 */
int removeEmployee(eEmployee* empleados,int cantidad,int id)
 {
     int i, retorno=-1;


         for(i=0;i<cantidad;i++)
         {
             if(empleados[i].id==id)
             {
                 empleados[i].isEmpty=ESTADO_LIBRE;
                 retorno=0;
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
void printEmployee(eEmployee empleado,eSector* sectores,int cantidad)
{
    int i;
    char descripcionAux[31];

    for(i=0; i<cantidad; i++)
    {
        if(empleado.idSector==sectores[i].idSector)
        {
            strcpy(descripcionAux,sectores[i].descripcionSector);
            break;
        }
    }
    printf("%d\t%s\t\t%s\t\t%s\t\t%.2f\t%d/%d/%d\t%s\n",empleado.id,empleado.name,empleado.lastName,empleado.sexo,empleado.salary,empleado.fechaIngreso.dia,empleado.fechaIngreso.mes,empleado.fechaIngreso.anio,descripcionAux);
 }


  /** \brief imprime por pantalla lista de empleados y su sector correspondiente
 * \param eEmployee empleado, estructura de empleados
 * \param eSector sectores, array de sectores
 * \return int cantidad de array
 * \return void
 */
 void printListEmployee(eEmployee* empleados,int cantidadEmpleados,eSector* sectores)
 {
     int i;

     for(i=0;i<cantidadEmpleados;i++)
     {
         if(empleados[i].isEmpty==ESTADO_OCUPADO)
         {
             printEmployee(empleados[i],sectores,cantidadEmpleados);
       }
     }
 }


 /** \brief modifica los datos de un empleado en la estructura
 * \param eEmployee empleado, estructura de empleados
 * \param int cantidad de array
 * \param id int
 * \return int Return (-1)Error o (0) Ok
 */
int modificarEmployee(eEmployee* empleados, int cantidad,int id)
{
    int retorno=-1,opcion;

    id= findEmployeeById(empleados,cantidad,id);

    if(id!= -1)
    {
        do
        {
            system("cls");
            printf("\tMENU -MODIFICAR-\n");
            opcion= getValidIntOpcion("\n1-NOMBRE\n2-APELLIDO\n3-SALARIO\n4-SEXO\n5-FECHA DE INGRESE\n6-SECTOR\n7-VOLVER\n","\tERROR\nOPCION NO VALIDA\n",1,7);

            switch(opcion)
            {
            case 1:
                system("cls");
                getValidString("INGRESE NOMBRE\n","\tERROR\nCARACTER NO VALIDO\n",empleados[id].name);
                break;

            case 2:
                system("cls");
                getValidString("INGRESE APELLIDO\n","\tError\nCARACTER NO VALIDO\n",empleados[id].lastName);
                break;

            case 3:
                system("cls");
                empleados[id].salary= getValidFloat("INGRESE SUELDO \n","\tERRORr\nCARACTER NO VALIDO");
                break;

            case 4:
                system("cls");
                getValidString("\tESCOGA SEXO\n(F) FEMENINO\n(M) MASCULINO\n","\tERROR\nOPCION NO VALIDA",empleados[id].sexo);
                break;

            case 5:
                system("cls");
                empleados[id].fechaIngreso.dia= getValidIntOpcion("INGRESE DIA\n","\tERROR\nOPCION NO VALIDA",1,31);
                empleados[id].fechaIngreso.mes= getValidIntOpcion("INGRESE MES\n","\tERROR\nOPCION NO VALIDA",1,12);
                empleados[id].fechaIngreso.anio= getValidIntOpcion("INGRESE ANIO\n","\tERROR\nOPCION NO VALIDA",1950,2019);
                break;

            case 6:
                system("cls");
                empleados[id].idSector= getValidIntOpcion("\tOPCIONES -SECTORES-\n1-COMPRAS\n2-ENTAS\n3-RRHH\n","\tERROR\nOPCION NO VALIDA",1,3);
                break;
            }
        }
        while(opcion!=7);
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
void administrarEmpleado(eEmployee* empleado,eSector* sectores,int cantidad)
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
            addEmployee(empleado,cantidad);
            break;

        case 2://MODIFICAR EMPLEADO
            system("cls");
            printf("ID\tNOMBRE\t\tAPELLIDO\tSEXO\t\tSALARIO\t\tFECHA\t\tSECTOR\n");
            printListEmployee(empleado,cantidad,sectores);
            idAux=getValidIntOpcion("\nINGRESE ID DE EMPLEADO A MODIFICAR\n","\tERROR\nOPCION NO VALIDA\n",1,cantidad);
            if(modificarEmployee(empleado,cantidad,idAux)==0){
                getChar("ID MODIFICADO CORRECTAMENTE\n");}

                else
                    printf("ID NO DISPONIBLE");

                break;

        case 3://BAJA EMPLEADO
            system("cls");
            printf("ID\tNOMBRE\t\tAPELLIDO\tSEXO\t\tSALARIO\t\tFECHA\t\tSECTOR\n");
            printListEmployee(empleado,cantidad,sectores);
            idAux=getValidIntOpcion("\nINGRESE ID DE EMPLEADO A DAR DE BAJA\n","\tERROR\nOPCION NO VALIDA\n",1,cantidad);
            if(removeEmployee(empleado,cantidad,idAux)==0){
                getChar("ID DADO DE BAJA\n");}

                else
                    printf("ID NO DISPONIBLE");

                break;

        case 4://IMPRIMIR LISTA EMPLEADO
            system("cls");
            printf("ID\tNOMBRE\t\tAPELLIDO\tSEXO\t\tSALARIO\t\tFECHA\t\tSECTOR\n\n");
            printListEmployee(empleado,cantidad,sectores);
            getChar("");
            break;
        }

    }while(opcion!=5);
}


 /** \brief carga datos hardcodeados en la estructura de empleados
 * \param eEmployee empleado, estructura de empleados
 * \param int cantidad, largo de array
 * \return void
 */
void hardcodearDatosEmpleados(eEmployee* empleado, int cantidad)
{
    int i;
    char nombres[][50]= {"Josue","Maria","Carlos","Pedro","Sofia","Mateo"};
    char apellido[][50]= {"Lopez","Dias","Villa","Perez","Baez","Imbert"};
    float sueldosBruto[]= {22000,22000,15000,48000,21000,36000};
    char sexo[][10]= {"M","F","M","M","F","M"};
    int idSector[]= {1,2,3,1,2,2};

    eFecha unaFecha = {22,04,2019};


    for(i=0; i<cantidad; i++)
    {
        empleado[i].id=array_generarProximoId();
        strcpy(empleado[i].name,nombres[i]);
        strcpy(empleado[i].lastName,apellido[i]);
        empleado[i].salary= sueldosBruto[i];
        strcpy(empleado[i].sexo,sexo[i]);
        empleado[i].idSector= idSector[i];
        empleado[i].fechaIngreso= unaFecha;
        empleado[i].isEmpty= ESTADO_OCUPADO;
    }
}









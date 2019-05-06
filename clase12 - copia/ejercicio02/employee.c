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
 *
 */
int array_generarProximoId(void)
{
    idAutoincrementable ++;
    return idAutoincrementable;
}


/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
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


/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 *
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


/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
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


 /** \brief find an Employee by Id en returns the free place position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
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


 /** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
 *
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


 /** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
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


  /** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
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


 /** \brief modifica datos en el arrey de empleados
 * \param list employee*
 * \param cantidad int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 *
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


 /** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
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
            printf("ID\tNOMBRE\t\tAPELLIDO\tSEXO\t\tSALARIO\t\tFECHA\t\tSECTOR\n");
            printListEmployee(empleado,cantidad,sectores);
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
void hardcodearDatosEmpleados(eEmployee* empleado, int cantidad)
{
    int i;
    char nombres[][50]= {"Carlos","Maria","Carlos","Pedro","Carlos","Mateo"};
    char apellido[][50]= {"Lopez","Dias","Villa","Perez","Baez","Imbert"};
    float sueldosBruto[]= {22000,22000,15000,48000,21000,36000};
    char sexo[][10]= {"M","F","M","M","M","M"};
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









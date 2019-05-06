#ifndef ESTRUCTURAUNO_H_INCLUDED
#define ESTRUCTURAUNO_H_INCLUDED

typedef struct{
            int dia;
            int mes;
            int anio;
}eFecha;


typedef struct{
        int idSector;
        char descripcionSector[51];
}eSector;


typedef struct{
        char name[31];
        int isEmpty;
        float salary;
        int idUnico;
        int dni;
        int idSector;
        eFecha fechaIngreso;
}eEstructuraUno;

#endif // ESTRUCTURAUNO_H_INCLUDED

#define ESTADO_OCUPADO 1
#define ESTADO_LIBRE 0


int genericoUno_array_generarProximoId(void);
int genericoUno_init(eEstructuraUno* ,int cantidad);
int genericoUno_findById(eEstructuraUno* ,int cantidad,int id);
int genericoUno_findIsEmpty(eEstructuraUno* ,int cantidad);


int genericoUno_remove(eEstructuraUno* ,int cantidad,int id);
int genericoUno_add(eEstructuraUno* ,int cantidad);
void genericoUno_hardcodearDatos(eEstructuraUno* , int cantidad);
int genericoUno_modificar(eEstructuraUno* , int cantidad,int idAux);
void genericoUno_admin(eEstructuraUno* ,eSector* sectores,int cantidad);


void genericoUno_ordenar(eEstructuraUno* estrutura,int cantidad);

void genericoUno_printList(eEstructuraUno* estructura,int cantidad,eSector* sectores);
void genericoUno_print(eEstructuraUno estructura,eSector* sectores,int cantidad);//IMPRIME UNO A MUCHOS

float genericoUno_totalImporte(eEstructuraUno* ,int cantidad);
float genericoUno_promedioImporte(eEstructuraUno* ,int cantidad);
int genericoUno_importeMayores125(eEstructuraUno*,int cantidad);
int genericoUno_importeMenores125(eEstructuraUno*,int cantidad);
int genericoUno_calcularMnimo(eEstructuraUno*, int cantidad);
int genericoUno_calcularMaximo(eEstructuraUno*, int cantidad);

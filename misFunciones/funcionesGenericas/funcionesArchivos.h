#define ARCH	".\\bin.dat"

#include "estructuraUno.h"


int generarArchivo(FILE* bin);
int arrayMovie_leerArchivo(eEstructuraUno* array,char* mensajeError,int lenght);
 int arrayMovie_escribirArchivo(eEstructuraUno* array,char* mensajeError,int lenght);
void arrayMovie_imprimir(eEstructuraUno* array,char* mensajeError,int lenght);
 int cargarPersona();
 int verPersona();


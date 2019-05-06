#ifndef MENUES_H_INCLUDED
#define MENUES_H_INCLUDED

typedef struct{
            int idMenu;
            char descripcion[31];
            float importe;
            int isEmpty;
}eMenu;

#endif // MENUES_H_INCLUDED

#define ESTADO_OCUPADO 1
#define ESTADO_LIBRE 0


int array_generarProximoIdMenues(void);
int initMenues(eMenu* menues,int cantidadMenues);
int findMenuById(eMenu* menues,int cantidadMenues,int id);
int menu_findIsEmpty(eMenu* menues,int cantidad);
int removeMenu(eMenu* menues,int cantidadMenues,int id);
int modificarMenu(eMenu* menues, int cantidadMenues,int idAux);
void ordenarMenues(eMenu* menues,int cantidadMenues);
void administrarMenues(eMenu* menues, int cantidadMenues);
float totalImporteMenues(eMenu* menues,int cantidadMenues);
float promedioImporteMenues(eMenu* menues,int cantidadMenues);
void hardcodearMenu(eMenu* menu,int cantidad);

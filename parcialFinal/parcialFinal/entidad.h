#ifndef entidad_H_INCLUDED
#define entidad_H_INCLUDED
typedef struct
{
    int idUnico;
    char nombre[28];
    char apellido[28];
    int sueldo;
    int horasTrabajadas;
}Entidad;

#endif // entidad_H_INCLUDED

/**
 * \brief Solicita espacio en memoria para crear una estructura de employee
 * \return Espacio de memoria para tipo de dato employee
 */
Entidad* entidad_new();

/**
 * \brief Parsea y asigna los datos por parametro a Entidad
 * \param char* idStr, id unico de employee
 * \param char* nombreStr, nombre de employee
 * \param char* horasTrabajadasStr, cantidad de horas trabajadas employee
 * \param char* sueldo, sueldo de employee
 * \return Employee* puntero de estructura cargada con datos
 */
Entidad* entidad_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* horasTrabajadasStr,char* sueldoStr);

/**
 * \brief Borra en espacio de memoria reservado
 * \param Employee*, this
 */
void entidad_delete(Entidad* this);

/**
 * \brief setea id unico para employee*
 * \param Employee*, this
 * \return int, -1 error / 0 ok
 * \param int id
 */
int entidad_setId(Entidad* this,int id);

/**
 * \brief get id unico de employee*
 * \param Employee*, this
 * \param int id auxiliar
 * \return int, -1 error / 0 ok
 */
int entidad_getId(Entidad* this,int* id);

/**
 * \brief setea un nombre para employee*
 * \param Employee*, this
 * \param char* nombre que se cargara en employee*
 * \return int, -1 error / 0 ok
 */
int entidad_setNombre(Entidad* this,char* nombre);

/**
 * \brief get get nombre de employee*
 * \param Employee*, this
 * \param char* nombre, auxiliar
 * \return int, -1 error / 0 ok
 */
int entidad_getNombre(Entidad* this,char* nombre);
/**
 * \brief setea un nombre para employee*
 * \param Employee*, this
 * \param char* nombre que se cargara en employee*
 * \return int, -1 error / 0 ok
 */
int entidad_setApellido(Entidad* this,char* apellido);

/**
 * \brief get get nombre de employee*
 * \param Employee*, this
 * \param char* nombre, auxiliar
 * \return int, -1 error / 0 ok
 */
int entidad_getApellido(Entidad* this,char* apellido);
/**
 * \brief set horas trabajadas de employee*
 * \param Employee*, this
 * \param int horas trabajadas
 * \return int, -1 error / 0 ok
 */
int entidad_setHorasTrabajadas(Entidad* this,int horasTrabajadas);

/**
 * \brief get horas trabajadas de employee*
 * \param Employee*, this
 * \param int* horas trabajadas, auxiliar
 * \return int, -1 error / 0 ok
 */
int entidad_getHorasTrabajadas(Entidad* this,int* horasTrabajadas);

/**
 * \brief set sueldo de employee*
 * \param Employee*, this
 * \param int sueldo
 * \return int, -1 error / 0 ok
 */
int entidad_setSueldo(Entidad* this,int sueldo);

/**
 * \brief get sueldo de employee*
 * \param Employee*, this
 * \param int* sueldo, auxiliar
 * \return int, -1 error / 0 ok
 */
int entidad_getSueldo(Entidad* this,int* sueldo);

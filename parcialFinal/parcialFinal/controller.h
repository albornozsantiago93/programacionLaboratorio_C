
int controller_loadFromText(char* path, LinkedList* pArrayListEntidad);
int controller_loadFromBinary(char* path, LinkedList* pArrayListEntidad);
int controller_addEntidad(LinkedList* pArrayListEntidad);
int controller_editEntidad(LinkedList* pArrayListEntidad);
int controller_removeEntidad(LinkedList* pArrayListEntidad);
void controller_listEntidad(LinkedList* pArrayListEntidad);
int controller_saveAsText(char* path, LinkedList* pArrayListEntidad);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEntidad);
int controller_criterioNombre(void* thisA,void* thisB);
int controller_sortEntidad(LinkedList* pArrayListEntidad);

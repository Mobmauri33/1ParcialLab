#ifndef RESIDUOS_H_INCLUDED
#define RESIDUOS_H_INCLUDED
#define TEXT_SIZE 50
///Estructura de Residuos
typedef struct
{
    int tipo; ///(1)HDPE,(2)LDPE,(3)PP
    int isEmpty;
    int estado;
    int kilos;
    int idPedido; ///clave unica de identidad univoca
    int idResiduo; ///clave unica de identidad univoca
}Residuo;

/**
 * \brief Se inicializa el isEmpty en un array de Residuos
 * \param pResiduo o restrument es el array en el cual buscar
 * \param len Indica la logitud del array
 * \return int return (-1) [Si la longitud es invalida o puntero NULL], (0) si se inicializa exitosamente
 *
 */
int res_initResiduo(Residuo* pResiduo,int len);
/** \brief Busca el primer lugar vacio en un array
* \param pResiduo o restrument es el Array de Residuos
* \param len int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Si la longitud es invalida o puntero NULL], (0) si encuentra una posicion vacia
*
*/
int res_findFree(Residuo* pResiduo, int len);
/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param pResiduo o restrument es el Array de Residuos
* \param len int Tamaño del array
* \param pIndex int* indice de puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si dio Error [Si la longitud es invalida o puntero NULL o no hay posiciones vacias], (0) si se agrega un nuevo elemento exitosamente
*
*/
int res_addResiduo(Residuo* pResiduo,int len,int pIndex,char* msgE,int tries);
/** \brief Busca por ID en un array y devuelve la posicion en que se encuentra
* \param restrument es el Array de Residuos
* \param len int Tamaño del array
* \param idE int donde se encuentra el ID buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Si la longitud es invalida o puntero NULL], (0) si encuentra el ID buscado
*
*/
int res_findResiduoById(Residuo* pResiduo, int len, int idE);
/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param restrument es el Array de Residuos
* \param cant int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer], (0) si encuentra el valor buscado
*
*/
int res_buscarID(Residuo *restrument, int cant, int valorBuscado, int* posicion);
/** \brief Borra un elemento del array por ID
* \param restrument es el Array de Residuos
* \param len int Tamaño del array
* \return int Return (-1) si Error [Si la longitud es invalida o puntero NULL o no encuentra elementos con el valor buscado], (0) si se elimina al musico exitosamente
*
*/
int res_removeResiduo(Residuo* pResiduo, int len,char* msgE,int tries);
/** \brief Busca por ID en un array y devuelve la posicion en que se encuentra
* \param restrument es el Array de Residuos
* \param len int Tamaño del array
* \param pResiduo donde se encuentra el ID buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Si la longitud es invalida o puntero NULL], (0) si encuentra el ID buscado
*
*/
int res_getID (Residuo* pResiduo,int len,char* msgE,int tries);
/** \brief Lista los elementos de un array
* \param restrument es el Array de Residuos
* \param len int Tamaño del array
* \return int Return (-1) si Error [Si la longitud es invalida o puntero NULL], (0) si se lista exitosamente
*
*/
int res_printResiduo(Residuo* pResiduo,int len);
/** \brief Ordena los elementos de un array por ID
* \param len int Tamaño del array
* \return int Return (-1) si Error [Si la longitud es invalida o puntero NULL], (0) si se ordena exitosamente
*
*/
int res_orderByID(Residuo* pResiduo, int len);
/** \brief remplaza un numero por una cadena de caracteres
 * \param restrument es el array de Residuos
 * \param posicion int posicion del array de Residuos donde se encuentra el valor a remplazar
 * \param tipoResiduo *char puntero a tipoStr donde se guardara el equivalente al valor unimerico en tipo cadena de caracteres
 * \return void return
 */
void res_tipoStr(Residuo* pResiduo,int posicion, char* tipoResiduo);
/** \brief Limpiar la pantalla
* \param limpia
* \return void return
*/
void limpiar (void);

#endif // Residuo_H_INCLUDED

#ifndef PEDIDO_H_INCLUDED
#define PEDIDO_H_INCLUDED
#define TEXT_SIZE 50
///Estructura de Pedido
typedef struct
{
    int estado;
    int isEmpty;
    int idCliente;
    int kilos;
    int idPedido; ///clave unica de identidad univoca
}Pedido;

/**
 * \brief Se inicializa el isEmpty en un array de Pedido
 * \param pPedido o pedtrument es el array en el cual buscar
 * \param len Indica la logitud del array
 * \return int return (-1) [Si la longitud es invalida o puntero NULL], (0) si se inicializa exitosamente
 *
 */
int ped_initPedido(Pedido* pPedido,int len);
/** \brief Busca el primer lugar vacio en un array
* \param pPedido o pedtrument es el Array de Pedido
* \param len int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Si la longitud es invalida o puntero NULL], (0) si encuentra una posicion vacia
*
*/
int ped_findFree(Pedido* pPedido, int len);
/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param pPedido o pedtrument es el Array de Pedido
* \param len int Tamaño del array
* \param pIndex int* indice de puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si dio Error [Si la longitud es invalida o puntero NULL o no hay posiciones vacias], (0) si se agrega un nuevo elemento exitosamente
*
*/
int ped_addPedido(Pedido* pPedido,int len,int pIndex,char* msgE,int tries);
/** \brief Busca por ID en un array y devuelve la posicion en que se encuentra
* \param pedtrument es el Array de Pedido
* \param len int Tamaño del array
* \param idE int donde se encuentra el ID buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Si la longitud es invalida o puntero NULL], (0) si encuentra el ID buscado
*
*/
int ped_findPedidoById(Pedido* pPedido, int len, int idE);
/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param pedtrument es el Array de Pedido
* \param cant int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer], (0) si encuentra el valor buscado
*
*/
int ped_buscarID(Pedido *pedtrument, int cant, int valorBuscado, int* posicion);
/** \brief Borra un elemento del array por ID
* \param pedtrument es el Array de Pedido
* \param len int Tamaño del array
* \return int Return (-1) si Error [Si la longitud es invalida o puntero NULL o no encuentra elementos con el valor buscado], (0) si se elimina al musico exitosamente
*
*/
int ped_removePedido(Pedido* pPedido, int len,char* msgE,int tries);
/** \brief Busca por ID en un array y devuelve la posicion en que se encuentra
* \param pedtrument es el Array de Pedido
* \param len int Tamaño del array
* \param pPedido donde se encuentra el ID buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Si la longitud es invalida o puntero NULL], (0) si encuentra el ID buscado
*
*/
int ped_getID (Pedido* pPedido,int len,char* msgE,int tries);
/** \brief Lista los elementos de un array
* \param pedtrument es el Array de Pedido
* \param len int Tamaño del array
* \return int Return (-1) si Error [Si la longitud es invalida o puntero NULL], (0) si se lista exitosamente
*
*/
int ped_printPedido(Pedido* pPedido,int len);
/** \brief Ordena los elementos de un array por ID
* \param len int Tamaño del array
* \return int Return (-1) si Error [Si la longitud es invalida o puntero NULL], (0) si se ordena exitosamente
*
*/
int ped_orderByID(Pedido* pPedido, int len);
/** \brief remplaza un numero por una cadena de caracteres
 * \param pedtrument es el array de Pedido
 * \param posicion int posicion del array de Pedido donde se encuentra el valor a remplazar
 * \param tipoPedido *char puntero a tipoStr donde se guardara el equivalente al valor unimerico en tipo cadena de caracteres
 * \return void return
 */
void ped_tipoStr(Pedido* pPedido,int posicion, char* tipoPedido);
/** \brief Limpiar la pantalla
* \param limpia
* \return void return
*/
void limpiar (void);

#endif // Pedido_H_INCLUDED


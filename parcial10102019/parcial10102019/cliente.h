#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
///Estructura de Cliente
typedef struct
{
    char nombreEmpresa[50];
    char direccion[50];
    char localidad[50];
    char cuit[20];
    int cantPedidos;
    int cantPedPendientes;
    int cantPedCompletados;
    int isEmpty;
    int idPedido; ///clave unica de identidad univoca
    int idCliente; ///clave unica de identidad univoca
}Cliente;

/**
 * \brief Se inicializa el isEmpty en un array de Cliente
 * \param pCliente o lista es el array en el cual buscar
 * \param len Indica la logitud del array
 * \return int return (-1) [Si la longitud es invalida o puntero NULL], (0) si se inicializa exitosamente
 *
 */
int cli_initCliente(Cliente* pCliente,int len);
/** \brief Busca el primer lugar vacio en un array
* \param pCliente o lista es el Array de Cliente
* \param len int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Si la longitud es invalida o puntero NULL], (0) si encuentra una posicion vacia
*
*/
int cli_findFree(Cliente* pCliente, int len);
/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param pCliente o lista es el Array de Cliente
* \param len int Tamaño del array
* \param pIndex int* indice de puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si dio Error [Si la longitud es invalida o puntero NULL o no hay posiciones vacias], (0) si se agrega un nuevo elemento exitosamente
*
*/
int cli_addCliente(Cliente* pCliente,int len,int pIndex,char* msgE,int tries);
/** \brief Busca por ID en un array y devuelve la posicion en que se encuentra
* \param lista es el Array de Cliente
* \param len int Tamaño del array
* \param idE int donde se encuentra el ID buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Si la longitud es invalida o puntero NULL], (0) si encuentra el ID buscado
*
*/
int cli_findClienteById(Cliente* pCliente, int len, int idE);
/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param lista es el Array de Cliente
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Si la longitud es invalida o puntero NULL], (0) si encuentra el valor buscado
*
*/
int cli_buscarID(Cliente *lista, int size, int valorBuscado, int* posicion);
/** \brief Borra un elemento del array por ID
* \param lista es el Array de Cliente
* \param len int Tamaño del array
* \return int Return (-1) si Error [Si la longitud es invalida o puntero NULL o no encuentra elementos con el valor buscado], (0) si se elimina la Cliente exitosamente
*
*/
int cli_removeCliente(Cliente* pCliente, int len,char* msgE,int tries);
/** \brief Busca un elemento por ID y modifica sus campos
* \param musicos es el Array de clientes
* \param len int Tamaño del array
* \return int Return (0) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado], (1) si se modifica el elemento exitosamente
*
*/
int cli_alter(Cliente* pCliente, int len,char* msgE,int tries);
/** \brief Busca por ID en un array y devuelve la posicion en que se encuentra
* \param lista es el Array de Cliente
* \param len int Tamaño del array
* \param pCliente donde se encuentra el ID buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Si la longitud es invalida o puntero NULL], (0) si encuentra el ID buscado
*
*/
int cli_getID (Cliente* pCliente,int len,char* msgE,int tries);
/** \brief Lista los elementos de un array
* \param lista es el Array de Cliente
* \param len int Tamaño del array
* \return int Return (-1) si Error [Si la longitud es invalida o puntero NULL], (0) si se lista exitosamente
*
*/
int cli_printCliente(Cliente* pCliente,int len);
/** \brief Ordena los elementos de un array por ID
* \param len int Tamaño del array
* \return int Return (-1) si Error [Si la longitud es invalida o puntero NULL], (0) si se ordena exitosamente
*
*/
int cli_orderByID(Cliente* pCliente, int len);
/** \brief Limpiar la pantalla
* \param limpia
* \return void return
*/
void limpiar (void);
#endif // CLIENTE_H_INCLUDED

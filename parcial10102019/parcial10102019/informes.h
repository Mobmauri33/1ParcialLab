#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED
/** \brief Lista los elementos de un array que se encuentran Pendiente
* \param pPedido es el Array de Pedido
* \param pCliente es el Array de Cliente
* \param len int Tamaño del array
* \return int Return (-1) si Error [Si la longitud es invalida o puntero NULL], (0) si se lista exitosamente
*
*/
int inf_imprimirClienteConPedPendiente(Cliente *pCliente,Pedido *pPedido, int len);
/** \brief Lista los elementos de un array que se encuentran Pendiente
* \param pPedido es el Array de Pedido
* \param pCliente es el Array de Cliente
* \param len int Tamaño del array
* \return int Return (-1) si Error [Si la longitud es invalida o puntero NULL], (0) si se lista exitosamente
*
*/
int inf_imprimirPedPendientes(Cliente *pCliente,Pedido *pPedido, int len);
/** \brief Lista los elementos de un array que se encuentran Procesados
* \param pPedido es el Array de Pedido
* \param pCliente es el Array de Cliente
* \param pResiduo es el Array de Residuo
* \param len int Tamaño del array
* \return int Return (-1) si Error [Si la longitud es invalida o puntero NULL], (0) si se lista exitosamente
*
*/
int inf_imprimirPedProcesados(Cliente *pCliente,Pedido *pPedido,Residuo *pResiduo, int len);
/** \brief Se imprime por pantalla la lista de Clientes que tienen mas Pedidos Pendientes, muestra ID nombre Localidad y Cantidad de Pedidos Pendientes
 * \param pPedido es el array de pedidos en el cual buscar
 * \param pCliente es el array de clientes donde se busca el id y nombre del cliente, se pasa a otra funcion por parametro
 * \param pResiduo es el array de residuos donde se busca el id y tipo de residuo, se pasa a otra funcion por parametro
 * \return (-1) si dio Error [Si la longitud es invalida o puntero NULL], (0) si se lista exitosamente
 *
 */
int inf_mostrarClienteConMasPedPendientes(Cliente *clientes, Pedido *pedidos, int cantCliente, int cantPedido);
/** \brief Se imprime por pantalla la lista de Clientes que tienen mas Pedidos Completados, muestra ID nombre Localidad y Cantidad de Pedidos Completados
 * \param pPedido es el array de pedidos en el cual buscar
 * \param pCliente es el array de clientes donde se busca el id y nombre del cliente, se pasa a otra funcion por parametro
 * \param pResiduo es el array de residuos donde se busca el id y tipo de residuo, se pasa a otra funcion por parametro
 * \return (-1) si dio Error [Si la longitud es invalida o puntero NULL], (0) si se lista exitosamente
 *
 */
int inf_mostrarClienteConMasPedCompletados(Cliente *clientes, Pedido *pedidos, int cantCliente, int cantPedido);
/** \brief Se imprime por pantalla la lista de Clientes que tienen mas Pedidos, muestra ID nombre Localidad y Cantidad de Pedidos
 * \param pPedido es el array de pedidos en el cual buscar
 * \param pCliente es el array de clientes donde se busca el id y nombre del cliente, se pasa a otra funcion por parametro
 * \param pResiduo es el array de residuos donde se busca el id y tipo de residuo, se pasa a otra funcion por parametro
 * \return (-1) si dio Error [Si la longitud es invalida o puntero NULL], (0) si se lista exitosamente
 *
 */
int inf_mostrarClienteConMasPedidos(Cliente *clientes, Pedido *pedidos, int cantCliente, int cantPedido);
/** \brief Se imprime por pantalla la lista de Clientes que tienen mas Kilos Reciclados, muestra ID nombre Localidad y Cantidad de Kilos Reciclados
 * \param clientes es el array de clientes donde se busca el id y nombre del cliente, se pasa a otra funcion por parametro
 * \param residuos es el array de residuos donde se busca el id y tipo de residuo, se pasa a otra funcion por parametro
 * \return (-1) si dio Error [Si la longitud es invalida o puntero NULL], (0) si se lista exitosamente
 *
 */
int inf_mostrarClienteConMasKilosReciclados(Cliente *clientes, Residuo *residuos, int cantCliente, int cantResiduo);
/** \brief Se imprime por pantalla la lista de Clientes que tienen menos Kilos Reciclados, muestra ID nombre Localidad y Cantidad de Kilos Reciclados
 * \param clientes es el array de clientes donde se busca el id y nombre del cliente, se pasa a otra funcion por parametro
 * \param residuos es el array de residuos donde se busca el id y tipo de residuo, se pasa a otra funcion por parametro
 * \return (-1) si dio Error [Si la longitud es invalida o puntero NULL], (0) si se lista exitosamente
 *
 */
int inf_mostrarClienteConMenosKilosReciclados(Cliente *clientes, Residuo *residuos, int cantCliente, int cantResiduo);
/** \brief Se imprime por pantalla la lista de Clientes que tienen mas de 1000 Kilos Reciclados, muestra ID nombre Localidad y Cantidad de Kilos Reciclados
 * \param clientes es el array de clientes donde se busca el id y nombre del cliente, se pasa a otra funcion por parametro
 * \param residuos es el array de residuos donde se busca el id y tipo de residuo, se pasa a otra funcion por parametro
 * \return (-1) si dio Error [Si la longitud es invalida o puntero NULL], (0) si se lista exitosamente
 *
 */
int inf_mostrarCantidadDeClienteQueRecicloMasDe1000Kg(Cliente *clientes,Residuo *residuos, int cantCliente, int cantResiduo);
/** \brief Se imprime por pantalla la lista de Clientes que tienen menos de 100 Kilos Reciclados, muestra ID nombre Localidad y Cantidad de Kilos Reciclados
 * \param clientes es el array de clientes donde se busca el id y nombre del cliente, se pasa a otra funcion por parametro
 * \param residuos es el array de residuos donde se busca el id y tipo de residuo, se pasa a otra funcion por parametro
 * \return (-1) si dio Error [Si la longitud es invalida o puntero NULL], (0) si se lista exitosamente
 *
 */
int inf_mostrarCantidadDeClienteQueRecicloMenosDe100Kg(Cliente *clientes,Residuo *residuos, int cantCliente, int cantResiduo);

int inf_mostrarPedidosCompletadosSegunIdCuitYPorc(Cliente *pCliente,Pedido *pPedido,Residuo *pResiduo, int len);
int inf_mostrarCantidadDePedidosPendientesDeUnaLocalidadDeterminada(Cliente* pCliente,int len);
int inf_mostrarPromedioDeKgDePpPorCliente(Cliente *clientes, Residuo *residuos, int cantCliente, int cantResiduo);
int inf_mostrarCantidadDeKilosDePlasticoDeUnCuitDeterminado(Cliente* pCliente,Residuo* pResiduo,int len);
int inf_mostrarCliente(Cliente *clientes, int posicion);


#endif // INFORMES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "residuos.h"
#include "cliente.h"
#include "pedido.h"
#include "utn_strings.h"
#include "Informes.h"
#define TEXT_SIZE 50
#define SORT_DOWN 0

int inf_imprimirClienteConPedPendiente(Cliente *pCliente,Pedido *pPedido, int len)
{
    int i;
    int flag=1;
    for(i=0;i<len;i++)
    {
        if(pCliente[i].isEmpty!=1)
        {
            printf("\nID: %d\nNombreEmpresa: %s\nDireccion: %s\nLocalidad: %s\nCuit: %s\nCantidad de Pedidos en Pendiente: %d\n-------",
            pCliente[i].idCliente,pCliente[i].nombreEmpresa,pCliente[i].direccion,pCliente[i].localidad,pCliente[i].cuit,pCliente[i].cantPedidos);
            fflush(stdin);
            flag=0;
        }
    }
    if(flag)
    {
        printf("\n----El listado se encuentra vacio----\n");
    }
    system("Pause");
    system("CLS");
    return 0;
}

int inf_imprimirPedPendientes(Cliente *pCliente,Pedido *pPedido, int len)
{
    int i;
    int flag=1;
    for(i=0;i<len;i++)
    {
        if(pCliente[i].isEmpty!=1)
        {
            printf("\nID: %d\nEstado: %d\nCuit del Cliente: %s\nDireccion del Cliente: %s\nCantidad de Kilos a Recolectar: %d\n-------",
                   pPedido[i].idPedido,pPedido[i].estado,pCliente[i].cuit,pCliente[i].direccion,pPedido[i].kilos);
                   fflush(stdin);
            flag=0;
        }
    }
    if(flag)
    {
        printf("\n----El listado se encuentra vacio----\n");
    }
    system("Pause");
    system("CLS");
    return 0;
}

int inf_imprimirPedProcesados(Cliente *pCliente,Pedido *pPedido,Residuo *pResiduo, int len)
{
    int i;
    int flag=1;
    for(i=0;i<len;i++)
    {
        if(pCliente[i].isEmpty!=1)
        {
            printf("\nID: %d\nEstado: %d\nCuit del Cliente: %s\nDireccion del Cliente: %s\nCantidad de Kilos a Reciclados: %d\nTipo de Residuo: %d\n-------",
                   pResiduo[i].idResiduo,pResiduo[i].estado,pCliente[i].cuit,pCliente[i].direccion,pResiduo[i].kilos,pResiduo[i].tipo);
                   fflush(stdin);
            flag=0;
        }
    }
    if(flag)
    {
        printf("\n----El listado se encuentra vacio----\n");
    }
    system("Pause");
    system("CLS");
    return 0;
}

int inf_mostrarClienteConMasPedPendientes(Cliente *clientes, Pedido *pedidos, int cantCliente, int cantPedido)
{
    int retorno=-1;
    int i;
    int j;
    int pedidoPorCliente=0;
    int maximo;
    int flag =1;

    if(clientes!=NULL && cantCliente>=0 && pedidos!=NULL && cantPedido>=0)
    {
        for(i=0;i<cantCliente;i++)
        {
            if(clientes[i].isEmpty==1)
                continue;

            else
            {
                for(j=0,pedidoPorCliente =0;j<cantPedido;j++)
                {
                    if(pedidos[j].isEmpty!=1 && clientes[i].idCliente==pedidos[j].idPedido)
                        pedidoPorCliente++;
                        fflush(stdin);
                }
                if(flag)
                {
                    maximo = pedidoPorCliente;
                    flag =0;
                    fflush(stdin);
                }
                else
                {
                    if(pedidoPorCliente>=maximo)
                        maximo=pedidoPorCliente;
                        fflush(stdin);
                        pedidoPorCliente=clientes[i].cantPedPendientes;
                        printf("\nCliente con mas pedidos Pendientes:\n");
                        printf("\n\n ID: %d -Nombre: %s\n Localidad: %s\n",
                               clientes[i].idCliente,clientes[i].nombreEmpresa,clientes[i].localidad);
                        printf("\n Cantidad de Pedidos Pendientes: %d\n",clientes[i].cantPedPendientes);
                        fflush(stdin);
                        retorno=0;
                }
            }
        }
    }
    return retorno;
}
/*
int inf_mostrarCliente(Cliente *clientes, int posicion)
{
    int retorno=-1;
    char localidadStr[TEXT_SIZE];

    if(clientes!=NULL && posicion>=0 && clientes[posicion].isEmpty==1);
    {
        switch(!clientes[posicion].localidad)
        {
        case 'a':
            strncpy(localidadStr,"Solano",TEXT_SIZE);
            break;
        case 'b':
            strncpy(localidadStr,"Avellaneda",TEXT_SIZE);
            break;
        case 'c':
            strncpy(localidadStr,"Merlo",TEXT_SIZE);
            break;
        }
        printf("\n\n ID: %d -Nombre: %s\n %s\n Localidad: %s\n",
                clientes[posicion].idCliente,clientes[posicion].nombreEmpresa,localidadStr,clientes[posicion].localidad);
        retorno=0;
    }
    return retorno;
}
*/
int inf_mostrarClienteConMasPedCompletados(Cliente *clientes, Pedido *pedidos, int cantCliente, int cantPedido)
{
    int retorno=-1;
    int i;
    int j;
    int pedidoPorCliente=0;
    int maximo;
    int flag =1;

    if(clientes!=NULL && cantCliente>=0 && pedidos!=NULL && cantPedido>=0)
    {
        for(i=0;i<cantCliente;i++)
        {
            if(clientes[i].isEmpty==1)
                continue;

            else
            {
                for(j=0,pedidoPorCliente =0;j<cantPedido;j++)
                {
                    if(pedidos[j].isEmpty!=1 && clientes[i].idCliente==pedidos[j].idPedido)
                        pedidoPorCliente++;
                        fflush(stdin);
                }
                if(flag)
                {
                    maximo = pedidoPorCliente;
                    flag =0;
                    fflush(stdin);
                }
                else
                {
                    if(pedidoPorCliente>=maximo)
                        maximo=pedidoPorCliente;
                        fflush(stdin);
                        pedidoPorCliente=clientes[i].cantPedCompletados;
                        printf("\nCliente con mas pedidos Completados:\n");
                        printf("\n\n ID: %d -Nombre: %s\n Localidad: %s\n",
                               clientes[1].idCliente,clientes[1].nombreEmpresa,clientes[1].localidad);
                        printf("\n Cantidad de Pedidos Completados: %d\n",clientes[1].cantPedCompletados);
                        fflush(stdin);
                        retorno=0;
                }
            }
        }
    }
    return retorno;
}

int inf_mostrarClienteConMasPedidos(Cliente *clientes, Pedido *pedidos, int cantCliente, int cantPedido)
{
   int retorno=-1;
    int i;
    int j;
    int pedidoPorCliente=0;
    int maximo;
    int flag =1;

    if(clientes!=NULL && cantCliente>=0 && pedidos!=NULL && cantPedido>=0)
    {
        for(i=0;i<cantCliente;i++)
        {
            if(clientes[i].isEmpty==1)
                continue;

            else
            {
                for(j=0,pedidoPorCliente =0;j<cantPedido;j++)
                {
                    if(pedidos[j].isEmpty!=1 && clientes[i].idCliente==pedidos[j].idPedido)
                        pedidoPorCliente++;
                        fflush(stdin);
                }
                if(flag)
                {
                    maximo = pedidoPorCliente;
                    flag =0;
                    fflush(stdin);
                }
                else
                {
                    if(pedidoPorCliente>=maximo)
                        maximo=pedidoPorCliente;
                        fflush(stdin);
                        pedidoPorCliente=clientes[i].cantPedidos;
                        printf("\nCliente con mas pedidos:\n");
                        printf("\n\n ID: %d -Nombre: %s\n Localidad: %s\n",
                               clientes[i].idCliente,clientes[i].nombreEmpresa,clientes[i].localidad);
                        printf("\n Cantidad de Pedidos: %d\n",clientes[i].cantPedidos);
                        fflush(stdin);
                        retorno=0;
                }
            }
        }
    }
    return retorno;
}

int inf_mostrarClienteConMasKilosReciclados(Cliente *clientes, Residuo *residuos, int cantCliente, int cantResiduo)
{
    int retorno=-1;
    int i;
    int j;
    int kilosPorCliente=0;
    int maximo;
    int flag =1;

    if(clientes!=NULL && cantCliente>=0 && residuos!=NULL && cantResiduo>=0)
    {
        for(i=0;i<cantCliente;i++)
        {
            if(clientes[i].isEmpty==1)
                continue;

            else
            {
                for(j=0,kilosPorCliente =0;j<cantResiduo;j++)
                {
                    if(residuos[j].isEmpty!=1 && clientes[i].idCliente==residuos[j].idResiduo)
                        kilosPorCliente++;
                        fflush(stdin);
                }
                if(flag)
                {
                    maximo = kilosPorCliente;
                    flag =0;
                    fflush(stdin);
                }
                else
                {
                    if(kilosPorCliente>=maximo)
                        maximo=kilosPorCliente;
                        fflush(stdin);
                        kilosPorCliente=residuos[i].kilos;
                        printf("\nCliente con mas kilos Reciclados:\n");
                        printf("\n\n ID: %d -Nombre: %s\n Localidad: %s\n",
                               clientes[1].idCliente,clientes[1].nombreEmpresa,clientes[1].localidad);
                        printf("\n Cantidad de Kilos: %d\n",residuos[1].kilos);
                        fflush(stdin);
                        retorno=0;
                }
            }
        }
    }
    return retorno;
}

int inf_mostrarClienteConMenosKilosReciclados(Cliente *clientes, Residuo *residuos, int cantCliente, int cantResiduo)
{
    int retorno=-1;
    int i;
    int j;
    int kilosPorCliente=0;
    int maximo;
    int flag =1;

    if(clientes!=NULL && cantCliente>=0 && residuos!=NULL && cantResiduo>=0)
    {
        for(i=0;i<cantCliente;i++)
        {
            if(clientes[i].isEmpty==1)
                continue;

            else
            {
                for(j=0,kilosPorCliente =0;j<cantResiduo;j++)
                {
                    if(residuos[j].isEmpty!=1 && clientes[i].idCliente==residuos[j].idResiduo)
                        kilosPorCliente++;
                        fflush(stdin);
                }
                if(flag)
                {
                    maximo = kilosPorCliente;
                    flag =0;
                    fflush(stdin);
                }
                else
                {
                    if(kilosPorCliente>=maximo)
                        maximo=kilosPorCliente;
                        fflush(stdin);
                        kilosPorCliente=residuos[i].kilos;
                        printf("\nCliente con menos kilos Reciclados:\n");
                        printf("\n\n ID: %d -Nombre: %s\n Localidad: %s\n",
                               clientes[i].idCliente,clientes[i].nombreEmpresa,clientes[i].localidad);
                        printf("\n Cantidad de Kilos: %d\n",residuos[i].kilos);
                        fflush(stdin);
                        retorno=0;
                }
            }
        }
    }
    return retorno;
}

int inf_mostrarCantidadDeClienteQueRecicloMasDe1000Kg(Cliente *clientes,Residuo *residuos, int cantCliente, int cantResiduo)
{
    int retorno=-1;
    int i;
    int posResiduo;

    if(clientes!=NULL && cantCliente>=0 && residuos!=NULL && cantResiduo>=0)
    {
        for(i=0;i<cantResiduo;i++)
        {
            if(residuos[i].isEmpty==1)
                continue;

            else
            {
                if(residuos[i].kilos>1000 && !cli_buscarID(clientes,cantCliente,residuos[i].idResiduo,&posResiduo))
                {
                        printf("Cantidad de Clientes que reciclo mas de 1000 kg:");
                        printf("\nID: %d\n Nombre: %s\n Direccion: %s\n Localidad: %s\n Cuit: %s\n kilos: %d\n-----------------\n",
                        clientes[i].idCliente,clientes[i].nombreEmpresa,clientes[i].direccion,clientes[i].localidad,clientes[i].cuit,residuos[posResiduo].kilos);
                        fflush(stdin);
                        retorno=0;
                }
            }
        }
    }
    return retorno;
}

int inf_mostrarCantidadDeClienteQueRecicloMenosDe100Kg(Cliente *clientes,Residuo *residuos, int cantCliente, int cantResiduo)
{
    int retorno=-1;
    int i;
    int posResiduo;

    if(clientes!=NULL && cantCliente>=0 && residuos!=NULL && cantResiduo>=0)
    {
        for(i=0;i<cantResiduo;i++)
        {
            if(residuos[i].isEmpty==1)
                continue;

            else
            {
                if(residuos[i].kilos<100 && residuos[i].kilos>0 && !cli_buscarID(clientes,cantCliente,residuos[i].idResiduo,&posResiduo))
                {
                        printf("Cantidad de Clientes que reciclo menos de 100 kg:");
                        printf("\nID: %d\n Nombre: %s\n Direccion: %s\n Localidad: %s\n Cuit: %s\n kilos: %d\n-----------------\n",
                        clientes[i].idCliente,clientes[i].nombreEmpresa,clientes[i].direccion,clientes[i].localidad,clientes[i].cuit,residuos[posResiduo].kilos);
                        fflush(stdin);
                        retorno=0;
                }
            }
        }
    }
    return retorno;
}

int inf_mostrarPedidosCompletadosSegunIdCuitYPorc(Cliente *pCliente,Pedido *pPedido,Residuo *pResiduo, int len)
{
    int i;
    int flag=1;
    for(i=0;i<len;i++)
    {
        if(pCliente[i].isEmpty!=1)
        {
            printf("\nID: %d\nCuit del Cliente: %s\n",
                   pResiduo[i].idResiduo,pCliente[i].cuit);
                   printf("Porcentaje de Plastico Reciclado en kg: %d\nPorcentaje de Plastico Total en kg: %d\n-------",
                          pResiduo[i].kilos,pPedido[i].kilos);
                   fflush(stdin);
            flag=0;
        }
    }
    if(flag)
    {
        printf("\n----El listado se encuentra vacio----\n");
    }
    system("Pause");
    system("CLS");
    return 0;
}

int inf_mostrarCantidadDePedidosPendientesDeUnaLocalidadDeterminada(Cliente* pCliente,int len)
{
    int i;
    int j;
    int flag=1;
    char * auxLocalidad = "Lugar0";
    for(i=0; i<len; i++)
    {
        if(pCliente[i].isEmpty!=1)
        {
           if(strcmp(pCliente[i].localidad, auxLocalidad)==1)
            {
                printf("\n%s ***\n",pCliente[i].localidad);
                flag=0;
            }
           auxLocalidad = pCliente[i].localidad;
        }
    }
    if(flag)
    {
        printf("\nLa lista se encuentra VACIA\n");
    }

   char lugarElegido[100];
   fflush(stdin);
   printf("\nEscriba la Localidad: " );
   scanf( "%s", lugarElegido );

    for(j=0; j<len; j++)
    {
        if(strcmp(pCliente[j].localidad, lugarElegido)==0){

            if(pCliente[j].isEmpty!=1)
            {
                printf("\nCantidad de Pedidos Pendientes:");
                printf("\nID - NOMBRE - LOCALIDAD - PEDIDOS PENDIENTES \n");
                printf("\n%d - %10s - %5s - %d\n",pCliente[j].idCliente ,pCliente[j].nombreEmpresa ,pCliente[j].localidad,pCliente[j].cantPedPendientes);
                fflush(stdin);
                flag=0;
            }
        }
    }
    if(flag)
    {
        printf("\nLa lista se encuentra VACIA\n");
        fflush(stdin);
    }
    return 0;
}

int inf_mostrarPromedioDeKgDePpPorCliente(Cliente *clientes, Residuo *residuos, int cantCliente, int cantResiduo)
{
    int retorno=-1;
    int i;
    int j;
    int kilosPorCliente;
    int ClientesActivos;

    if(clientes!=NULL && cantCliente>=0 && residuos!=NULL && cantResiduo>=0)
    {
        for(j=0,ClientesActivos=0;j<cantCliente;j++)
        {
            if(clientes[j].isEmpty!=1)
                ClientesActivos++;
        }
        for(i=0;i<cantCliente;i++)
        {
            if(clientes[i].isEmpty==1)
                continue;
            else
            {
                for(j=0,kilosPorCliente=0;j<cantResiduo;j++)
                {
                    if(residuos[j].isEmpty!=1 && clientes[i].idCliente==residuos[j].idResiduo)
                         kilosPorCliente++;
                }
                printf("\nID %d - %s\nEl Promedio de Plastico PP por cliente es: %.2f\n",clientes[i].idCliente,
                       clientes[i].nombreEmpresa,(float) kilosPorCliente/ClientesActivos);
                       fflush(stdin);
                retorno=0;
            }
        }
    }
    return retorno;
}

int inf_mostrarCantidadDeKilosDePlasticoDeUnCuitDeterminado(Cliente* pCliente,Residuo* pResiduo,int len)
{
    int i;
    int j;
    int flag=1;
    char * auxCuit = "23393334441";
    int auxTipo = 3;
    for(i=0; i<len; i++)
    {
        if(pCliente[i].isEmpty!=1)
        {
           if(strcmp(pCliente[i].cuit, auxCuit)==1 && (pResiduo[i].tipo=auxTipo)==1)
            {
                printf("\n%s ***\n",pCliente[i].cuit);
                printf("\n%i ***\n",pResiduo[i].tipo);
                flag=0;
            }
           auxCuit = pCliente[i].cuit;
        }
    }
    if(flag)
    {
        printf("\nLa lista se encuentra VACIA\n");
    }

   char cuitElegido[100];
   int tipoElegido;
   fflush(stdin);
   printf("\nEscriba el cuit de un Cliente: ");
   scanf( "%s", cuitElegido );
   printf("\nEscribra el tipo de Plastico: ");
   scanf( "%i", &tipoElegido );

    for(j=0; j<len; j++)
    {
        if(strcmp(pCliente[j].cuit,cuitElegido)==0 && (pResiduo[j].tipo=tipoElegido)==0){

            if(pCliente[j].isEmpty!=1)
            {
                printf("\nCantidad de Kilos Reciclados:");
                printf("\nID - NOMBRE - LOCALIDAD - KILOS RECICLADOS \n");
                printf("\n%d - %10s - %5s - %d\n",pCliente[j].idCliente ,pCliente[j].nombreEmpresa ,pCliente[j].localidad,pCliente[j].cantPedCompletados);
                fflush(stdin);
                flag=0;
            }
        }
    }
    if(flag)
    {
        printf("\nLa lista se encuentra VACIA\n");
        fflush(stdin);
    }
    return 0;
}

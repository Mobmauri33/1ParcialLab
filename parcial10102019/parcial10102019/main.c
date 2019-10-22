#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "pedido.h"
#include "residuos.h"
#include "utn_strings.h"
#include "informes.h"
#define REINTENTOS 3
#define LEN_CLIENTES 100
#define LIS_PEDIDOS 1000
#define LES_RESIDUOS 20

int main()
{
    int flag=1;
    int posLibre;
    int opcion=0;
    char opcionL;

    Cliente lista[LEN_CLIENTES];
    Pedido pedidos[LIS_PEDIDOS];
    Residuo residuos[LES_RESIDUOS];

    cli_initCliente(lista,100);
    ped_initPedido(pedidos,1000);
    res_initResiduo(residuos,200);

    /*
    strcpy(residuos[1].nombre,"rest1");
    residuos[1].tipo=1;
    residuos[1].isEmpty=0;
    residuos[1].idResiduo=1;

    strcpy(residuos[2].nombre,"rest2");
    residuos[2].tipo=2;
    residuos[2].isEmpty=0;
    residuos[2].idResiduo=2;

    strcpy(residuos[3].nombre,"rest3");
    residuos[3].tipo=2;
    residuos[3].isEmpty=0;
    residuos[3].idResiduo=3;

    */
    residuos[1].tipo=3;
    residuos[1].estado=2;
    residuos[1].kilos=50;
    residuos[1].isEmpty=0;
    residuos[1].idResiduo=1;

    residuos[2].tipo=3;
    residuos[2].estado=2;
    residuos[2].kilos=30;
    residuos[2].isEmpty=0;
    residuos[2].idResiduo=2;

    strcpy(lista[1].nombreEmpresa,"Cliente1");
    strcpy(lista[1].direccion,"Lugar1");
    strcpy(lista[1].localidad,"Avellaneda");
    strcpy(lista[1].cuit,"23398885550");
    lista[1].cantPedidos=10;
    lista[1].cantPedPendientes=3;
    lista[1].cantPedCompletados=7;
    lista[1].isEmpty=0;
    lista[1].idCliente=1;


    strcpy(lista[2].nombreEmpresa,"Cliente2");
    strcpy(lista[2].direccion,"Lugar2");
    strcpy(lista[2].localidad,"Merlo");
    strcpy(lista[2].cuit,"23393334441");
    lista[2].cantPedidos=20;
    lista[2].cantPedPendientes=15;
    lista[2].cantPedCompletados=5;
    lista[2].isEmpty=0;
    lista[2].idCliente=2;

    /*
    strcpy(lista[3].nombre,"Cliente3");
    strcpy(lista[3].lugar,"Lugar2");
    lista[3].tipo=3;
    lista[3].isEmpty=0;
    lista[3].idCliente=3;

    strcpy(lista[4].nombre,"Cliente4");
    strcpy(lista[4].lugar,"Lugar3");
    lista[4].tipo=2;
    lista[4].isEmpty=0;
    lista[4].idCliente=4;

    */
    pedidos[1].estado=1;
    pedidos[1].kilos=60;
    pedidos[1].isEmpty=0;
    pedidos[1].idCliente=1;
    pedidos[1].idResiduos=1;
    pedidos[1].idPedido=1;

    pedidos[2].estado=1;
    pedidos[2].kilos=35;
    pedidos[2].isEmpty=0;
    pedidos[2].idCliente=2;
    pedidos[2].idResiduos=2;
    pedidos[2].idPedido=2;

    /*
    strcpy(pedidos[3].nombre,"ped3");
    strcpy(pedidos[3].apellido,"Aped3");
    pedidos[3].edad=25;
    pedidos[3].isEmpty=0;
    pedidos[3].idCliente=4;
    pedidos[3].idResiduo=2;
    pedidos[3].idPedido=3;

    strcpy(pedidos[4].nombre,"ped4");
    strcpy(pedidos[4].apellido,"Aped4");
    pedidos[4].edad=27;
    pedidos[4].isEmpty=0;
    pedidos[4].idCliente=4;
    pedidos[4].idResiduo=1;
    pedidos[4].idPedido=4;

    strcpy(pedidos[5].nombre,"ped5");
    strcpy(pedidos[5].apellido,"Aped5");
    pedidos[5].edad=22;
    pedidos[5].isEmpty=0;
    pedidos[5].idCliente=1;
    pedidos[5].idResiduo=3;
    pedidos[5].idPedido=5;

    strcpy(pedidos[6].nombre,"ped6");
    strcpy(pedidos[6].apellido,"Aped6");
    pedidos[6].edad=35;
    pedidos[6].isEmpty=0;
    pedidos[6].idCliente=3;
    pedidos[6].idResiduo=4;
    pedidos[6].idPedido=6;

    */

    while(opcion!=10)
    {
getIntInRange(&opcion,"\n\n*MENU*\n\n1)Alta de Cliente\n2)Modificar datos de Cliente\n3)Baja de Cliente\n"
              "4)Crear Pedido de recoleccion\n5)Procesar Residuos\n6)Imprimir Clientes\n7)Imprimir Pedidos pendientes\n"
              "8)Imprimir Pedidos procesados\n9)Informes\n10)Salir\n\n INGRESE OPCION: ","ERROR\n",1,10,3);
              system("CLS");
        switch(opcion)
        {
            case 1:
            {
                posLibre=cli_findFree(lista,LEN_CLIENTES);
                if(posLibre>=0)
                {
                    printf("\n----Se encontro lugar----\n");
                    if(!cli_addCliente(lista,LEN_CLIENTES,posLibre,"DATO NO VALIDO\n",REINTENTOS))
                    {
                        flag=1;
                        printf("\n----Se dio ALTA de Cliente exitosamente!----\n");
                        system("Pause");
                        system("CLS");
                    }
                    else
                    {
                        printf("\n----No se realizo el ALTA de Cliente!----\n");
                        system("Pause");
                        system("CLS");
                    }
                }
                else
                {
                    printf("\n----No se encontro lugar libre!----\n");
                    system("Pause");
                    system("CLS");
                }
                break;
            }
            case 2:
            {
                if(flag)
                {
                    if(cli_alter(lista,LEN_CLIENTES,"DATO NO VALIDO\n",REINTENTOS))
                    {
                        printf("\n----Se modifico cliente exitosamente----\n");
                        system("Pause");
                        system("CLS");
                    }
                    else
                    {
                        printf("\n----No se modifico cliente!----\n");
                        system("Pause");
                        system("CLS");
                    }
                }
                else
                {
                    printf("\n----No hay ALTAS de clientes en la NOMINA!----\n");
                    system("Pause");
                    system("CLS");
                }
                break;
            }
            case 3:
            {
                if(flag)
                {
                    if(cli_removeCliente(lista,LEN_CLIENTES,"DATO NO VALIDO\n",REINTENTOS))
                    {
                        printf("\n----La BAJA de cliente se realizo con exito!----\n");
                        system("Pause");
                        system("CLS");
                    }
                    else
                    {
                        printf("\n----No se realizo la BAJA de cliente!----\n");
                        system("Pause");
                        system("CLS");
                    }
                }
                else
                {
                    printf("\n----No hay ALTAS de clientes en la NOMINA!----\n");
                    system("Pause");
                    system("CLS");
                }
                break;
            }
            case 4:
            {
                if(flag)
                {
                    cli_printCliente(lista,LEN_CLIENTES);
                    posLibre=ped_findFree(pedidos,LIS_PEDIDOS);
                if(posLibre>=0)
                {
                    printf("\n----Se encontro lugar----\n");
                    if(!ped_addPedido(pedidos,LIS_PEDIDOS,posLibre,"DATO NO VALIDO\n",REINTENTOS))
                    {
                        flag=1;
                        printf("\n----Se dio ALTA de Pedido exitosamente!----\n");
                        system("Pause");
                        system("CLS");
                    }
                    else
                    {
                        printf("\n----No se realizo el ALTA de Pedido!----\n");
                        system("Pause");
                        system("CLS");
                    }
                }
                else
                {
                    printf("\n----No se encontro lugar libre!----\n");
                    system("Pause");
                    system("CLS");
                }
                fflush(stdin);
                break;
            }
        }
            case 5:
            {
                if(flag)
                {
                    ped_printPedido(pedidos,LIS_PEDIDOS);
                    fflush(stdin);
                    posLibre=res_findFree(residuos,LES_RESIDUOS);
                if(posLibre>=0)
                {
                    printf("\n----Se encontro lugar----\n");
                    if(!res_addResiduo(residuos,LES_RESIDUOS,posLibre,"DATO NO VALIDO\n",REINTENTOS))
                    {
                        flag=1;
                        printf("\n----Se dio ALTA de Residuo exitosamente!----\n");
                        system("Pause");
                        system("CLS");
                    }
                    else
                    {
                        printf("\n----No se realizo el ALTA de Residuo!----\n");
                        system("Pause");
                        system("CLS");
                    }
                }
                else
                {
                    printf("\n----No se encontro lugar libre!----\n");
                    system("Pause");
                    system("CLS");
                }
                break;
            }
        }
            case 6:
                inf_imprimirClienteConPedPendiente(lista,pedidos,LEN_CLIENTES);
                fflush(stdin);
                break;
            case 7:
                inf_imprimirPedPendientes(lista,pedidos,LEN_CLIENTES);
                fflush(stdin);
                break;
            case 8:
                inf_imprimirPedProcesados(lista,pedidos,residuos,LEN_CLIENTES);
                fflush(stdin);
                break;
            case 9:
            while(opcionL!='s')
            {
                utn_getChar("\n\n*MENU DE INFORMES*\n\na)Cliente con mas pedidos Pendientes \nb)Cliente con mas pedidos Completados \n"
                             "c)Clientes con mas pedidos \nd)Cliente que reciclo mas kilos \ne)Cliente que reciclo menos kilos \n"
                             "f)Cantidad de Clientes que reciclaron mas de 1000 kilos \ng)Cantidad de Clientes que reciclaron menos de 100 kilos \n"
                             "h)Imprimir los pedidos completados indicando: Id pedido,Cuit cliente,% de plast. reciclado(kilos recicl/kilos totales) \ni)Ingresar una Localidad e indicar la cant de pedidos pendientes para dicha Localidad \n"
                             "j)Cantidad de kilos de polipropileno reciclado promedio por cliente(kilos totales/ cant clientes) \n"
                             "k)Ingresar cuit de un cliente y uno de los tres Tipos de plastico e informar la cantidad de kilos totales reclicadas de dicho tipo \ns)Volver al Menu Principal \n\n"
                             "\nIngrese la opcion: ",
                                   "\nError",'a','s',1,&opcionL);
                                   system("CLS");

                switch(opcionL)
                {
                case 'a':
                    inf_mostrarClienteConMasPedPendientes(lista,pedidos,LEN_CLIENTES,LIS_PEDIDOS);
                    system("Pause");
                    system("CLS");
                    break;
                case 'b':
                    inf_mostrarClienteConMasPedCompletados(lista,pedidos,LEN_CLIENTES,LIS_PEDIDOS);
                    system("Pause");
                    system("CLS");
                    break;
                case 'c':
                    inf_mostrarClienteConMasPedidos(lista,pedidos,LEN_CLIENTES,LIS_PEDIDOS);
                    system("Pause");
                    system("CLS");
                     break;
                case 'd':
                    inf_mostrarClienteConMasKilosReciclados(lista,residuos,LEN_CLIENTES,LES_RESIDUOS);
                    system("Pause");
                    system("CLS");
                    break;
                case 'e':
                    inf_mostrarClienteConMenosKilosReciclados(lista,residuos,LEN_CLIENTES,LES_RESIDUOS);
                    system("Pause");
                    system("CLS");
                    break;
                case 'f':
                    inf_mostrarCantidadDeClienteQueRecicloMasDe1000Kg(lista,residuos,LEN_CLIENTES,LES_RESIDUOS);
                    system("Pause");
                    system("CLS");
                    break;
                case 'g':
                    inf_mostrarCantidadDeClienteQueRecicloMenosDe100Kg(lista,residuos,LEN_CLIENTES,LES_RESIDUOS);
                    system("Pause");
                    system("CLS");
                    break;
                case 'h':
                    inf_mostrarPedidosCompletadosSegunIdCuitYPorc(lista,pedidos,residuos,LEN_CLIENTES);
                    system("Pause");
                    system("CLS");
                    break;
                case 'i':
                    inf_mostrarCantidadDePedidosPendientesDeUnaLocalidadDeterminada(lista,LEN_CLIENTES);
                    system("Pause");
                    system("CLS");
                    break;
                case 'j':
                    inf_mostrarPromedioDeKgDePpPorCliente(lista,residuos,LEN_CLIENTES,LES_RESIDUOS);
                    system("Pause");
                    system("CLS");
                    break;
                case 'k':
                    inf_mostrarCantidadDeKilosDePlasticoDeUnCuitDeterminado(lista,residuos,LEN_CLIENTES);
                    system("Pause");
                    system("CLS");
                    break;
                case 's':
                    break;
                default:
                printf("\nLa opcion no es valida\n");
                system("Pause");
                system("CLS");
            }
        }
    }
}
    return 0;
}

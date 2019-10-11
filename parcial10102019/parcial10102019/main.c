#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "pedido.h"
#include "residuos.h"
#include "utn_strings.h"
//#include "Informes.h"
#define REINTENTOS 3
#define LEN_CLIENTES 50
#define LIS_PEDIDOS 1000
#define LES_RESIDUOS 20

int main()
{
    int flag=0;
    int posLibre;
    int opcion=0;
    //char opcionL;

    Cliente lista[LEN_CLIENTES];
    Pedido pedidos[LIS_PEDIDOS];
    //Residuo residuos[LES_RESIDUOS];

    cli_initCliente(lista,50);
    ped_initPedido(pedidos,1000);
    //res_initResiduo(residuos,20);

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

    strcpy(residuos[4].nombre,"rest4");
    residuos[4].tipo=3;
    residuos[4].isEmpty=0;
    residuos[4].idResiduo=4;

    strcpy(residuos[5].nombre,"rest5");
    residuos[5].tipo=4;
    residuos[5].isEmpty=0;
    residuos[5].idResiduo=5;

    strcpy(lista[1].nombre,"Cliente1");
    strcpy(lista[1].lugar,"Lugar1");
    lista[1].tipo=1;
    lista[1].isEmpty=0;
    lista[1].idCliente=1;

    strcpy(lista[2].nombre,"Cliente2");
    strcpy(lista[2].lugar,"Lugar1");
    lista[2].tipo=2;
    lista[2].isEmpty=0;
    lista[2].idCliente=2;

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

    strcpy(pedidos[1].nombre,"ped1");
    strcpy(pedidos[1].apellido,"Aped1");
    pedidos[1].edad=30;
    pedidos[1].isEmpty=0;
    pedidos[1].idCliente=1;
    pedidos[1].idResiduo=2;
    pedidos[1].idPedido=1;

    strcpy(pedidos[2].nombre,"ped2");
    strcpy(pedidos[2].apellido,"Aped2");
    pedidos[2].edad=20;
    pedidos[2].isEmpty=0;
    pedidos[2].idCliente=2;
    pedidos[2].idResiduo=5;
    pedidos[2].idPedido=2;

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
    flag=1;

    while(opcion!=11)
    {
getIntInRange(&opcion,"\n\n*MENU*\n\n1)Alta de Cliente\n2)Modificar datos de Cliente\n3)Baja de Cliente\n"
              "4)Crear Pedido de recoleccion\n5)Procesar Residuos\n6)Imprimir Clientes\n7)Imprimir Pedidos pendientes\n"
              "8)Imprimir Pedidos procesados\n9)Salir\n\n INGRESE OPCION: ","ERROR\n",1,9,3);
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
                    cli_findClienteById(lista,LEN_CLIENTES,0);
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
                break;
            }
        }
            /*
            case 5:
            {
                if(flag)
                {
                    if(ped_alter(pedidos,LIS_pedidos,"DATO NO VALIDO\n",REINTENTOS))
                    {
                        printf("\n----Se modifico pedidos exitosamente----\n");
                        system("Pause");
                        system("CLS");
                    }
                    else
                    {
                        printf("\n----No se modifico pedidos!----\n");
                        system("Pause");
                        system("CLS");
                    }
                }
                else
                {
                    printf("\n----No hay ALTAS de pedidos en la NOMINA!----\n");
                    system("Pause");
                    system("CLS");
                }
                break;
            }
            case 6:
            {
                if(flag)
                {
                    if(ped_removePedido(pedidos,LIS_pedidos,"DATO NO VALIDO\n",REINTENTOS))
                    {
                        printf("\n----La BAJA de pedidos se realizo con exito!----\n");
                        system("Pause");
                        system("CLS");
                    }
                    else
                    {
                        printf("\n----No se realizo la BAJA de pedidos!----\n");
                        system("Pause");
                        system("CLS");
                    }
                }
                else
                {
                    printf("\n----No hay ALTAS de pedidos en la NOMINA!----\n");
                    system("Pause");
                    system("CLS");
                }
                break;
            }
            case 7:
            {
                if(flag)
                {
                    ped_printPedido(pedidos,LIS_pedidos);
                }
                break;
            }
            case 8:
            {
                posLibre=res_findFree(residuos,LES_RESIDUOS);
                if(posLibre>=0)
                {
                    printf("\n----Se encontro lugar----\n");
                    if(!res_addResiduo(residuos,LES_RESIDUOS,posLibre,"DATO NO VALIDO\n",REINTENTOS))
                    {
                        flag=1;
                        printf("\n----Se dio ALTA de ResiduoS exitosamente!----\n");
                        system("Pause");
                        system("CLS");
                    }
                    else
                    {
                        printf("\n----No se realizo el ALTA de ResiduoS!----\n");
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
            case 9:
            {
                if(flag)
                {
                    res_printResiduo(residuos,LES_RESIDUOS);
                }
                break;
            }
            case 10:
            while(opcionL!='s')
            {
                utn_getChar("\n\n*MENU DE INFORMES*\n\na)Clientes correspondientes a un lugar \nb)pedidos menores de 25 \n"
                             "c)Clientes con menos de 6 pedidos \nd)Residuos de una Cliente \ne)Clientes completas \n"
                             "f)Clientes con la menor cantidad de pedidos \ng)Promedio de Residuos por Cliente \n"
                             "h)pedidos excepto aquellos que toquen Residuos de viento \ns)Volver al Menu Principal \n"
                             "\nIngrese la opcion: ",
                                   "\nError",'a','s',1,&opcionL);
                                   system("CLS");

                switch(opcionL)
                {
                case 'a':
                    inf_mostrarClienteDeUnLugarDeterminado(lista,LEN_CLIENTES);
                    system("Pause");
                    system("CLS");
                    break;
                case 'b':
                    inf_mostrarpedidosDeMenosDe25(pedidos,lista,residuos,LIS_pedidos,LEN_CLIENTES,LES_RESIDUOS);
                    system("Pause");
                    system("CLS");
                    break;
                case 'c':
                    inf_mostrarClienteConMenosDe6pedidos(lista,pedidos,LEN_CLIENTES,LIS_pedidos);
                    system("Pause");
                    system("CLS");
                     break;
                case 'd':
                    inf_mostrarResiduoDeClienteDeterminada(lista,LEN_CLIENTES,residuos,LES_RESIDUOS,pedidos,LIS_pedidos);
                    system("Pause");
                    system("CLS");
                    break;
                case 'e':
                    inf_mostrarClienteCompleta(lista,LEN_CLIENTES,residuos,LES_RESIDUOS,pedidos,LIS_pedidos);
                    system("Pause");
                    system("CLS");
                    break;
                case 'f':
                    inf_mostrarClienteConMenospedidos(lista,pedidos,LEN_CLIENTES,LIS_pedidos);
                    system("Pause");
                    system("CLS");
                    break;
                case 'g':
                    inf_mostrarPromedioDeResiduos(lista,pedidos,LEN_CLIENTES,LIS_pedidos);
                    system("Pause");
                    system("CLS");
                    break;
                case 'h':
                    inf_mostrarpedidosQueNoToquenResiduoDeViento(pedidos,residuos,LIS_pedidos,LES_RESIDUOS);
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
        */
    }
}
    return 0;
}

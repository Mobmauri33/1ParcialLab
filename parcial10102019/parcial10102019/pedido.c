#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "pedido.h"
#include "utn_strings.h"

int ped_initPedido(Pedido* pPedido,int len)
{
    int i;
    if(pPedido!=NULL && len>0)
    {
        for(i=0; i<len;i++)
        {
            pPedido[i].idPedido=i+1;
            pPedido[i].isEmpty=1;
        }
    }
    return 0;
}

int ped_findFree(Pedido* pPedido, int len)
{
    int i;
    int ret=-1;
    for(i=0;i<len;i++)
    {
        if(pPedido[i].isEmpty==1)
        {
            ret=i;
            break;
        }
    }
    return ret;
}

int ped_addPedido(Pedido* pPedido,int len,int pIndex,char* msgE,int tries)
{
    int auxKilos;
    int auxEstado;
    int retorno=-1;
    if((pPedido!=NULL)&&(len>0)&&(pIndex!=-1))
    {
        getInt(&auxKilos,"\nIngrese la cantidad de Kilos totales que se le recolectaran al cliente:","Error");
        getIntInRange(&auxEstado,"\nIngrese Estado:\n 1)(Pendiente): \n 2)(Completado): \n ",msgE,1,2,tries);
        pPedido[pIndex].estado=auxEstado;
        pPedido[pIndex].kilos=auxKilos;
        pPedido[pIndex].isEmpty=0;
        retorno=0;
    }
    return retorno;
}

int ped_findPedidoById(Pedido* pPedido, int len, int idE)
{
    int i;
    int ret=-1;
    for(i=0;i<len;i++)
    {
        if(pPedido[i].idPedido==idE)
        {
            ret=i;
            break;
        }
    }
    return ret;
}

int ped_buscarID(Pedido *pedtrument, int cant, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(pedtrument!= NULL && cant>=0)
    {

        for(i=0;i<cant;i++)
        {
            if(pedtrument[i].isEmpty==1)
            {
                continue;
            }
            else
            {
                if(pedtrument[i].idPedido==valorBuscado)
                {
                retorno=0;
                *posicion=i;
                break;
                }
            }
        }
    }
    return retorno;
}

int ped_removePedido(Pedido* pPedido, int len,char* msgE,int tries)
{
    int auxID;
    int posOfID;
    int retorno=-1;
    if(pPedido!=NULL && len>0)
    {
        auxID=ped_getID(pPedido,len,msgE,tries);
         if(auxID>=0)
        {
            posOfID=ped_findPedidoById(pPedido,len,auxID);
            if(posOfID!=-1)
            {
               pPedido[posOfID].isEmpty=1;
               retorno=0;
            }
        }
     }
    return retorno;
}

int ped_getID (Pedido* pPedido,int len,char* msgE,int tries)
{
    int retorno=-1;
    char bufferID[20];
    int auxID;
    if(pPedido!=NULL && len>0)
    {
        if(!getStringNumeros(bufferID,"\nIngrese ID: ",msgE,tries))
        {
            auxID=atoi(bufferID);
            retorno=auxID;
        }
    }
    return retorno;
}

int ped_printPedido(Pedido* pPedido,int len)
{
    int i;
    int flag=1;
    for(i=0;i<len;i++)
    {
        if(pPedido[i].isEmpty!=1)
        {
            printf("\nID: %d\nEstado: %d\nKilos: %d\n-------",
                   pPedido[i].idPedido,pPedido[i].estado,pPedido[i].kilos);
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

int ped_orderByID(Pedido* pPedido, int len)
{
    int i;
    int j;
    Pedido buffer;
    for(i=0;i<len-1;i++)
    {
        if(pPedido[i].isEmpty==1)
        {
            continue;
        }
        for(j=i+1;j<len;j++)
        {
            if(pPedido[j].isEmpty==1)
            {
                continue;
            }
            if(pPedido[i].idPedido>pPedido[j].idPedido)
            {
                buffer=pPedido[i];
                pPedido[i]=pPedido[j];
                pPedido[j]=buffer;
            }
        }
    }
    return 0;
}
/*
void ped_tipoStr(Pedido* pPedido,int posicion, char* tipoPedido)
{
    if(pPedido!=NULL && tipoPedido!=NULL && posicion>=0)
    {
        switch(pPedido[posicion].tipo)
        {
        case 1:
            strncpy(tipoPedido,"Cuerdas",TEXT_SIZE);
            break;
        case 2:
            strncpy(tipoPedido,"Viento-Madera",TEXT_SIZE);
            break;
        case 3:
            strncpy(tipoPedido,"Viento-Metal",TEXT_SIZE);
            break;
        case 4:
            strncpy(tipoPedido,"Percusion",TEXT_SIZE);
            break;
        }
    }
}
*/

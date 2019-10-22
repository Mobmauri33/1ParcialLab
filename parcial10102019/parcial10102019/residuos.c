#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "residuos.h"
#include "cliente.h"
#include "pedido.h"
#include "utn_strings.h"

int res_initResiduo(Residuo* pResiduo,int len)
{
    int i;
    if(pResiduo!=NULL && len>0)
    {
        for(i=0; i<len;i++)
        {
            pResiduo[i].idResiduo=i+1;
            pResiduo[i].isEmpty=1;
        }
    }
    return 0;
}

int res_findFree(Residuo* pResiduo, int len)
{
    int i;
    int ret=-1;
    for(i=0;i<len;i++)
    {
        if(pResiduo[i].isEmpty==1)
        {
            ret=i;
            break;
        }
    }
    return ret;
}

int res_addResiduo(Residuo* pResiduo,int len,int pIndex,char* msgE,int tries)
{
    char bufferIdPedido[20];
    int auxTipo;
    int auxIdPedido;
    int auxKilos;
    int auxEstado;
    int retorno=-1;
    if((pResiduo!=NULL)&&(len>0)&&(pIndex!=-1))
    {
        getStringNumeros(bufferIdPedido,"\nIngrese el id del Pedido:",msgE,tries);
        getIntInRange(&auxTipo,"\nIngrese Tipo:\n 1)HDPE(Polietileno de alta densidad): \n 2)LDPE(Polietileno de baja densidad): \n 3)PP(Polipropileno): \n ",msgE,1,3,tries);
        getIntInRange(&auxKilos,"\nIngrese la cantidad de Kilos de plastico que se recolectara de este tipo:",msgE,1,100,tries);
        getIntInRange(&auxEstado,"\nEl Estado de su pedido quedara Completado Presione 2 para continuar:\n 2)(Completado): \n ",msgE,2,2,tries);
        auxIdPedido = atoi(bufferIdPedido);
        pResiduo[pIndex].kilos=auxKilos;
        pResiduo[pIndex].estado=auxEstado;
        pResiduo[pIndex].idPedido=auxIdPedido;
        pResiduo[pIndex].tipo=auxTipo;
        pResiduo[pIndex].isEmpty=0;
        retorno=0;
    }
    return retorno;
}

int res_findResiduoById(Residuo* pResiduo, int len, int idE)
{
    int i;
    int ret=-1;
    for(i=0;i<len;i++)
    {
        if(pResiduo[i].idResiduo==idE)
        {
            ret=i;
            break;
        }
    }
    return ret;
}

int res_buscarID(Residuo *pResiduo, int cant, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(pResiduo!= NULL && cant>=0)
    {

        for(i=0;i<cant;i++)
        {
            if(pResiduo[i].isEmpty==1)
            {
                continue;
            }
            else
            {
                if(pResiduo[i].idResiduo==valorBuscado)
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

int res_removeResiduo(Residuo* pResiduo, int len,char* msgE,int tries)
{
    int auxID;
    int posOfID;
    int retorno=-1;
    if(pResiduo!=NULL && len>0)
    {
        auxID=res_getID(pResiduo,len,msgE,tries);
         if(auxID>=0)
        {
            posOfID=res_findResiduoById(pResiduo,len,auxID);
            if(posOfID!=-1)
            {
               pResiduo[posOfID].isEmpty=1;
               retorno=0;
            }
        }
     }
    return retorno;
}

int res_getID (Residuo* pResiduo,int len,char* msgE,int tries)
{
    int retorno=-1;
    char bufferID[20];
    int auxID;
    if(pResiduo!=NULL && len>0)
    {
        if(!getStringNumeros(bufferID,"\nIngrese ID: ",msgE,tries))
        {
            auxID=atoi(bufferID);
            retorno=auxID;
        }
    }
    return retorno;
}

int res_printResiduo(Residuo* pResiduo,int len)
{
    int i;
    int flag=1;
    for(i=0;i<len;i++)
    {
        if(pResiduo[i].isEmpty!=1)
        {
            printf("\nID: %d\nTipo: %d\n-------",
                   pResiduo[i].idResiduo,pResiduo[i].tipo);
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

int res_orderByID(Residuo* pResiduo, int len)
{
    int i;
    int j;
    Residuo buffer;
    for(i=0;i<len-1;i++)
    {
        if(pResiduo[i].isEmpty==1)
        {
            continue;
        }
        for(j=i+1;j<len;j++)
        {
            if(pResiduo[j].isEmpty==1)
            {
                continue;
            }
            if(pResiduo[i].idResiduo>pResiduo[j].idResiduo)
            {
                buffer=pResiduo[i];
                pResiduo[i]=pResiduo[j];
                pResiduo[j]=buffer;
            }
        }
    }
    return 0;
}

void res_tipoStr(Residuo* pResiduo,int posicion, char* tipoResiduo)
{
    if(pResiduo!=NULL && tipoResiduo!=NULL && posicion>=0)
    {
        switch(pResiduo[posicion].tipo)
        {
        case 1:
            strncpy(tipoResiduo,"HDPE",TEXT_SIZE);
            break;
        case 2:
            strncpy(tipoResiduo,"LDPE",TEXT_SIZE);
            break;
        case 3:
            strncpy(tipoResiduo,"PP",TEXT_SIZE);
            break;
        }
    }
}


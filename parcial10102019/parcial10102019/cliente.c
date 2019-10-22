#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "pedido.h"
#include "residuos.h"
#include "utn_strings.h"

int cli_initCliente(Cliente* pCliente,int len)
{
    int i;
    if(pCliente!=NULL && len>0)
    {
        for(i=0; i<len;i++)
        {
            pCliente[i].idCliente=i+1;
            pCliente[i].isEmpty=1;
        }
    }
    return 0;
}

int cli_findFree(Cliente* pCliente, int len)
{
    int i;
    int ret=-1;
    for(i=0;i<len;i++)
    {
        if(pCliente[i].isEmpty==1)
        {
            ret=i;
            break;
        }
    }
    return ret;
}

int cli_addCliente(Cliente* pCliente,int len,int pIndex,char* msgE,int tries)
{
    char bufferNameEmp[50];
    char bufferDireccion[50];
    char bufferLocalidad[50];
    char auxcuit[20];
    int retorno=-1;
    if((pCliente!=NULL)&&(len>0)&&(pIndex!=-1))
    {
        if(((getStringLetras(bufferNameEmp,"\nIngrese Nombre: ",msgE,tries)==0)&&
            (getString(bufferDireccion,"\nIngrese Direccion: ",msgE)==0)&&
            (getStringLetras(bufferLocalidad,"\nIngrese Localidad: ",msgE,tries)==0))&&
           (getStringNumeros(auxcuit,"\nIngrese Cuit:",msgE,3)==0))
        {
            strncpy(pCliente[pIndex].nombreEmpresa,bufferNameEmp,sizeof(bufferNameEmp));
            strncpy(pCliente[pIndex].direccion,bufferDireccion,sizeof(bufferDireccion));
            strncpy(pCliente[pIndex].localidad,bufferLocalidad,sizeof(bufferLocalidad));
            strncpy(pCliente[pIndex].cuit,auxcuit,sizeof(auxcuit));
            pCliente[pIndex].isEmpty=0;
            retorno=0;
            fflush(stdin);
        }
    }
    return retorno;
}

int cli_findClienteById(Cliente* pCliente, int len, int idE)
{
    int i;
    int ret=-1;
    for(i=0;i<len;i++)
    {
        if(pCliente[i].idCliente==idE && pCliente[i].isEmpty==0)
        {
            ret=i;
            break;
        }
    }
    return ret;
}

int cli_buscarID(Cliente *lista, int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(lista!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(lista[i].isEmpty==1)
                continue;
            else if(lista[i].idCliente==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

int cli_alter(Cliente* pCliente, int len,char* msgE,int tries)
{
    int auxID;
    int posOfID;
    int opcion=0;
    char bufferDireccion[50];
    char bufferLocalidad[50];
    int retorno=0;

    if((pCliente!=NULL)&&(len>0))
    {
        cli_printCliente(pCliente,len);
        auxID=cli_getID(pCliente,len,msgE,tries);
        if(auxID>=0)
        {
            posOfID=cli_findClienteById(pCliente,len,auxID);
            if(posOfID!=-1)
            {
                while(opcion!=3)
                {
                    printf("\n1- Modificar Direccion\n");
                    printf("2- Modificar Localidad\n");
                    printf("3- Atras (Menu Principal)\n");
                    getIntInRange(&opcion,"\n   INGRESE OPCION (Menu Modificacion): ",msgE,1,3,tries);
                    system("CLS");
                    switch(opcion)
                    {
                        case 1:
                        {
                            if(!getString(bufferDireccion,"\nIngrese NUEVA Direccion: ",msgE))
                            {
                                strncpy(pCliente[posOfID].direccion,bufferDireccion,sizeof(bufferDireccion));
                                retorno=1;
                                printf("\n\nSe ha modificado la DIRECCION exitosamente!\n\n");
                            }
                            break;
                        }
                        case 2:
                        {
                            if(!getStringLetras(bufferLocalidad,"\nIngrese NUEVA Localidad: ",msgE,tries))
                            {
                                strncpy(pCliente[posOfID].localidad,bufferLocalidad,sizeof(bufferLocalidad));
                                retorno=1;
                                printf("\n\nSe ha modificado la LOCALIDAD exitosamente!\n\n");
                            }
                            break;
                        }

                    }
                }
            }
            else
            {
                printf("\n----No se encontro el ID!-----\n");
            }
        }
    }
    return retorno;
}

int cli_removeCliente(Cliente* pCliente, int len,char* msgE,int tries)
{
    int auxID;
    int posOfID;
    int retorno;

    cli_printCliente(pCliente,len);
    if(pCliente!=NULL && len>0)
    {
        auxID=cli_getID(pCliente,len,msgE,tries);
         if(auxID>=0)
        {
            posOfID=cli_findClienteById(pCliente,len,auxID);
            if(posOfID!=-1)
            {
               pCliente[posOfID].isEmpty=1;
               retorno=1;
            }
            else
            {
                printf("\nNo se encontro la Cliente\n");
                system("Pause");
                system("CLS");
                retorno=-1;
            }
        }
     }
    return retorno;
}

int cli_getID (Cliente* pCliente,int len,char* msgE,int tries)
{
    int retorno=-1;
    char bufferID[20];
    int auxID;
    if(!getStringNumeros(bufferID,"\nIngrese el ID de la Cliente: ",msgE,tries))
        {
            auxID=atoi(bufferID);
            retorno=auxID;
        }
    return retorno;
}

int cli_printCliente(Cliente* pCliente,int len)
{
    int i;
    int flag=1;
    for(i=0;i<len;i++)
    {
        if(pCliente[i].isEmpty!=1)
        {
            printf("\nID: %d\nNombreEmpresa: %s\nDireccion: %s\nLocalidad: %s\ncuit: %s\n-------",
            pCliente[i].idCliente,pCliente[i].nombreEmpresa,pCliente[i].direccion,pCliente[i].localidad,pCliente[i].cuit);
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

int cli_orderByID(Cliente* pCliente, int len)
{
    int i;
    int j;
    Cliente buffer;
    for(i=0;i<len-1;i++)
    {
        if(pCliente[i].isEmpty==1)
        {
            continue;
        }
        for(j=i+1;j<len;j++)
        {
            if(pCliente[j].isEmpty==1)
            {
                continue;
            }
            if(pCliente[i].idCliente>pCliente[j].idCliente)
            {
                buffer=pCliente[i];
                pCliente[i]=pCliente[j];
                pCliente[j]=buffer;
            }
        }
    }
    return 0;
}

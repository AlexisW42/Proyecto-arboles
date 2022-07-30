#include <iostream>
#include "ABB.h"

using namespace std;

ABB::ABB()
{
    raiz=NULL;
}

bool ABB::esVacio()
{
    if (raiz==NULL)
        return true;
    else
        return false;
}

void ABB::insertarNodo(ArbolNodo *nodoNuevo)
{
    if(raiz==NULL)
    {
        raiz=nodoNuevo;
    }
    else
    {
        ArbolNodo *temp =raiz;
        while (temp!=NULL)
        {
            if(nodoNuevo->valor==temp->valor)
            {
                return;
            }
            else if ((nodoNuevo->valor<temp->valor) && (temp->izquierdo==NULL))
            {
                temp->izquierdo=nodoNuevo;
                break;
            }
            else if(nodoNuevo->valor<temp->valor)
            {
                temp=temp->izquierdo;
            }
            else if((nodoNuevo->valor>temp->valor)&&(temp->derecho==NULL))
            {
                temp->derecho=nodoNuevo;
                break;
            }
            else
            {
                temp=temp->derecho;
            }
        } 
    }
}

void ABB::imprimirArbol(ArbolNodo *r, int espacio)
{
    if(r==NULL)
        return;
    espacio+=ESPACIO;
    imprimirArbol(r->derecho, espacio);
    cout<<endl;
    for (int i= ESPACIO; i < espacio; i++)
    {
        cout <<" ";
    }
    cout<<r->valor<<"\n";
    imprimirArbol(r->izquierdo, espacio);
}

void ABB::imprimirPostOrden(ArbolNodo* r)
{
    if(r==NULL)
    return;

    imprimirPostOrden(r->izquierdo);
    imprimirPostOrden(r->derecho);
    cout <<r->valor<<" ";
}

void ABB::imprimirHojas(ArbolNodo* r)
{
    if(r==NULL)
    return;

    imprimirHojas(r->izquierdo);
    imprimirHojas(r->derecho);
    if(r->izquierdo==NULL&&r->derecho==NULL)
        cout <<r->valor<<" ";   
}

int ABB::getAltura(ArbolNodo* r)
{
    if (r==NULL)
        return 0;
    else
    {
        int alturaIzquierda = getAltura(r->izquierdo);
        int alturaDerecha = getAltura(r->derecho);

        if (alturaIzquierda > alturaDerecha)
            return (alturaIzquierda+1);
        else
            return (alturaDerecha+1);
    }
}

int ABB::getMenorAltura(ArbolNodo* r)
{
    if (r==NULL)
        return 0;
    else
    {
        int alturaIzquierda = getAltura(r->izquierdo);
        int alturaDerecha = getAltura(r->derecho);

        if (alturaIzquierda < alturaDerecha)
            return (alturaIzquierda+1);
        else
            return (alturaDerecha+1);
    }
}

bool ABB::getEsBalanceado(ArbolNodo* r)
{
    int mayorAltura = getAltura(r);
    int menorAltura = getMenorAltura(r);

    int diferencia = mayorAltura-menorAltura;

    if (diferencia >= -1 && diferencia <= 1)
        return true;
    
    return false;
}
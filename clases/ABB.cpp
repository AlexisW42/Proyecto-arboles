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
        cout << "valor insertado como raiz" << endl;
    }
    else
    {
        ArbolNodo *temp =raiz;
        while (temp!=NULL)
        {
            if(nodoNuevo->valor==temp->valor)
            {
                cout<<"el valor ya existe, inserta otro"<<endl;
                return;
            }
            else if ((nodoNuevo->valor<temp->valor) && (temp->izquierdo==NULL))
            {
                temp->izquierdo=nodoNuevo;
                cout << "valor insertado en la izquierda" << endl;
                break;
            }
            else if(nodoNuevo->valor<temp->valor)
            {
                temp=temp->izquierdo;
            }
            else if((nodoNuevo->valor>temp->valor)&&(temp->derecho==NULL))
            {
                temp->derecho=nodoNuevo;
                cout << "valor insertado en la derecha" << endl;
                break;
            }
            else
            {
                temp=temp->derecho;
            }
        } 
    }
}

void ABB::imprimir2D(ArbolNodo *r, int espacio)
{
    if(r==NULL)
        return;
    espacio+=ESPACIO;
    imprimir2D(r->derecho, espacio);
    cout<<endl;
    for (int i= ESPACIO; i < espacio; i++)
    {
        cout <<" ";
    }
    cout<<r->valor<<"\n";
    imprimir2D(r->izquierdo, espacio);
}
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
#ifndef ABB_H
#define ABB_H
#define ESPACIO 10
#include "ArbolNodo.h"

class ABB
{
public:
    ArbolNodo*raiz;
    ABB();
    bool esVacio();
    void insertarNodo(ArbolNodo *nodoNuevo);
    void imprimirArbol(ArbolNodo *r, int espacio);
    void imprimirPostOrden(ArbolNodo* r);
};

#endif

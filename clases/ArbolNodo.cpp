#include <iostream>
#include "ArbolNodo.h"

ArbolNodo::ArbolNodo()
{
    valor = "";
    izquierdo = NULL;
    derecho = NULL;
}

ArbolNodo::ArbolNodo(int v)
{
    valor = v;
    izquierdo = NULL;
    derecho = NULL;
}
#ifndef ArbolNodo_H
#define ArbolNodo_H
#include <string>

class ArbolNodo
{
private:
public:
    std::string valor;
    ArbolNodo *izquierdo;
    ArbolNodo * derecho;
    ArbolNodo();
    ArbolNodo(int v);
};

#endif
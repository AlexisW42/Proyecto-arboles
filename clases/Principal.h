#ifndef PRINCIPAL_H
#define PRINCIPAL_H
#include "Principal.h"
#include "ABB.h"
#include <vector>

class Principal
{
private:
    std::vector<ABB> vArboles;

public:
    void leerArchivo();
    void imprimirVector();
};

#endif
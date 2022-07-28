#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "Principal.h"

using namespace std;

void Principal::leerArchivo()
{
    ifstream archivo;
    archivo.open ("datos/arbol.txt");
    if (!archivo.is_open()) return;

       string str;
    while(getline(archivo, str)) 
    {
        istringstream ss(str);
        string palabra;
        ABB obj;
        while(ss >> palabra)
        {
            ArbolNodo *nuevoNodo = new ArbolNodo();
            nuevoNodo->valor=palabra;
            obj.insertarNodo(nuevoNodo);
        }
        vArboles.push_back(obj);
    }
}

void Principal::imprimirVector()
{
    for (size_t i = 0; i < vArboles.size(); ++i)
    {
        vArboles.at(i).imprimir2D(vArboles.at(i).raiz, 5);
        cout<<endl;
        cout<<endl;
    }
}
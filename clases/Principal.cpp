#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

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
        cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
        cout<<setw(36)<<" "<<"Arbol N°"<<setw(3)<<i+1<<setw(36)<<" ";
        vArboles.at(i).imprimirArbol(vArboles.at(i).raiz, 5);
        cout<<endl;
        cout<<"PostOrden: ";
        vArboles.at(i).imprimirPostOrden(vArboles.at(i).raiz);
        cout<<endl;
        cout<<endl;
    }
    cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
}
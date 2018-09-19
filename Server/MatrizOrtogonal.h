#ifndef MATRIZORTOGONAL_H
#define MATRIZORTOGONAL_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Nodo.h"
#include "Cabecera.h"

class MatrizOrtogonal
{
public:
    MatrizOrtogonal();
    MatrizOrtogonal(int size_i, int size_j);

    Cabecera * filas;
    Cabecera * columnas;

    int sizefilas;
    int sizecolumnas;

    void Insertar(int i, int j, std::string& data);
    Nodo * Remover(int i, int j);

    void Imprimir();
    std::string ImprimirFormatNodos();

    std::string ImprimirMatrizNodos();
    std::string ImprimirCabecerasFilasNodos();
    std::string ImprimirCabecerasColumnasNodos();
    std::string ImprimirFilaNodos();
    std::string ImprimirColumnaNodos();

    int Obtener_Min(Cabecera * pivote);
    int Obtener_Max(Cabecera * pivote, int maxsize);

    Nodo * Buscar(int i, int j);
};

#endif // MATRIZORTOGONAL_H

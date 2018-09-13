#ifndef MATRIZDISPERSA_H
#define MATRIZDISPERSA_H

#include <iostream>
#include <cstdlib>
#include "Nodo.h"
#include "Cabecera.h"

class MatrizDispersa
{
public:
    MatrizDispersa();

    Cabecera * filas;
    Cabecera * columnas;

    void Insertar(int i, int j, std::string& data);
    Nodo * Remover(int i, int j);

    void Imprimir();

    int Obtener_Min(Cabecera * pivote);
    int Obtener_Max(Cabecera * pivote);

    Nodo * Buscar(int i, int j);
};

#endif // MATRIZDISPERSA_H

#ifndef MATRIZ_H
#define MATRIZ_H

#include <iostream>
#include <cstdlib>
#include "Nodo.h"
#include "Cabecera.h"

class Matriz
{
public:
    Matriz();

    Cabecera * filas;
    Cabecera * columnas;

    void Insertar(int i, int j, int data);
    Nodo * Remover(int i, int j);

    void Imprimir();

    int Obtener_Min(Cabecera * pivote);
    int Obtener_Max(Cabecera * pivote);

    Nodo * Buscar(int i, int j);
};

#endif // MATRIZ_H

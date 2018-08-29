#ifndef MATRIZ_H
#define MATRIZ_H

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

};

#endif // MATRIZ_H

#ifndef MATRIZHIBRIDA_H
#define MATRIZHIBRIDA_H

#include <iostream>
#include <cstdlib>
#include "Nodo.h"
#include "Cabecera.h"

class MatrizHibrida
{
public:
    MatrizHibrida();
    MatrizHibrida(int sizecolumnas);

    Cabecera * filas;
    Cabecera * columnas;

    int sizecolumnas;

    void Insertar(int i, int j, std::string& data);
    Nodo * Remover(int i, int j);

    void Imprimir();

    int Obtener_Min(Cabecera * pivote);
    int Obtener_Max(Cabecera * pivote);
    int Obtener_Max_Columnas(Cabecera * pivote, int maxsize);

    Nodo * Buscar(int i, int j);
};

#endif // MATRIZHIBRIDA_H

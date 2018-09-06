#ifndef CABECERA_H
#define CABECERA_H

#include <cstdlib>
#include "Nodo.h"

class Cabecera
{
public:
    Cabecera();
    Cabecera(int fila_o_columna);

    Nodo * primero;

    Cabecera * siguiente;
    Cabecera * anterior;

    int fila_o_columna;

    void Insertar_Al_Frente(Cabecera ** primero, Cabecera * nuevo);
    void Insertar_Al_Final(Cabecera ** primero, Cabecera * nuevo);

    Cabecera * Remover_Del_Frente(Cabecera ** primero);
    Cabecera * Remover_Del_Final(Cabecera ** primero);

    Cabecera * Buscar(int criterio);

    Cabecera * Insertar(Cabecera ** primero, int criterio);
    void Remover(Cabecera ** primero, int criterio);
};

#endif // CABECERA_H

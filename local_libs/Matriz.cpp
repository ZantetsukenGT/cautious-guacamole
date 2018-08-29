#include "Matriz.h"

Matriz::Matriz()
{
    filas = columnas = NULL;
}

void Matriz::Insertar(int i, int j, int data)
{
    Cabecera * fila = this->filas->Insertar(&this->filas,i);
    Cabecera * columna = this->columnas->Insertar(&this->columnas,j);

    Nodo * nuevo = new Nodo(i, j, data);

    fila->primero->Insertar_En_Fila(&fila->primero,nuevo);
    columna->primero->Insertar_En_Columna(&columna->primero,nuevo);
}

Nodo * Matriz::Remover(int i, int j)
{
    return NULL;
}


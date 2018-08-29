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

void Matriz::Imprimir()
{
    for(int i = Obtener_Min(filas); i <= Obtener_Max(filas); i++)
    {
        for(int j = Obtener_Min(columnas); j <= Obtener_Max(columnas); j++)
        {
            Nodo * pivote = Buscar(i,j);
            if(pivote != NULL)
                std::cout << pivote->data;
            else
                std::cout << '-';
        }
        std::cout << std::endl;
    }
}

int Matriz::Obtener_Min(Cabecera * pivote)
{
    return pivote->fila_o_columna;
}

int Matriz::Obtener_Max(Cabecera * pivote)
{
    while(pivote->siguiente != NULL)
    {
        pivote = pivote->siguiente;
    }
    return pivote->fila_o_columna;
}

Nodo * Matriz::Buscar(int i, int j)
{
    Cabecera * fila = filas->Buscar(i);

    if(fila != NULL)
    {
        Nodo * pivote = fila->primero->Buscar_En_Fila(j);
        if(pivote != NULL)
            return pivote;
    }
    return NULL;
}

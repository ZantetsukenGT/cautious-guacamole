#include "MatrizOrtogonal.h"

MatrizOrtogonal::MatrizOrtogonal()
{
    filas = columnas = NULL;
}

MatrizOrtogonal::MatrizOrtogonal(int size_i, int size_j)
{
    sizefilas = size_i;
    sizecolumnas = size_j;
    filas = new Cabecera[size_i];
    columnas = new Cabecera[size_j];

    for(int i = 0; i < size_i; i++)
    {
        filas[i] = *(new Cabecera(i));
    }
    for(int j = 0; j < size_j; j++)
    {
        columnas[j] = *(new Cabecera(j));
    }
}

void MatrizOrtogonal::Insertar(int i, int j, std::string& data)
{
    Cabecera * fila = &this->filas[i];
    Cabecera * columna = &this->columnas[j];

    Nodo * nuevo = new Nodo(i, j, data);

    fila->primero->Insertar_En_Fila(&fila->primero,nuevo);
    columna->primero->Insertar_En_Columna(&columna->primero,nuevo);
}

Nodo * MatrizOrtogonal::Remover(int i, int j)
{
    Cabecera * fila = &filas[i];
    Cabecera * columna = &columnas[j];
    Nodo * pivote = NULL;
    if(fila != NULL && columna != NULL)
    {
        pivote = fila->primero->Remover_En_Fila(&fila->primero, j);
        pivote = columna->primero->Remover_En_Columna(&columna->primero, i);
        return pivote;
    }
    return NULL;
}

void MatrizOrtogonal::Imprimir()
{
    for(int i = Obtener_Min(filas); i <= Obtener_Max(filas, sizefilas); i++)
    {
        for(int j = Obtener_Min(columnas); j <= Obtener_Max(columnas,sizecolumnas); j++)
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

int MatrizOrtogonal::Obtener_Min(Cabecera * pivote)
{
    return pivote!=NULL?pivote[0].fila_o_columna:0;
}

int MatrizOrtogonal::Obtener_Max(Cabecera * pivote, int maxsize)
{
    return pivote!=NULL?pivote[maxsize - 1].fila_o_columna:0;
}

Nodo * MatrizOrtogonal::Buscar(int i, int j)
{
    Cabecera * fila = &filas[i];

    if(fila != NULL)
    {
        Nodo * pivote = fila->primero->Buscar_En_Fila(j);
        if(pivote != NULL)
            return pivote;
    }
    return NULL;
}

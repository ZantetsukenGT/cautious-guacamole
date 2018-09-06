#include "MatrizHibrida.h"

MatrizHibrida::MatrizHibrida()
{
    filas = columnas = NULL;
}

MatrizHibrida::MatrizHibrida(int size_j)
{
    sizecolumnas = size_j;
    filas = NULL;
    columnas = new Cabecera[size_j];

    for(int j = 0; j < size_j; j++)
    {
        columnas[j] = *(new Cabecera(j));
    }
}

void MatrizHibrida::Insertar(int i, int j, std::string& data)
{
    Cabecera * fila = this->filas->Insertar(&this->filas,i);
    Cabecera * columna = &columnas[j];

    Nodo * nuevo = new Nodo(i, j, data);

    fila->primero->Insertar_En_Fila(&fila->primero,nuevo);
    columna->primero->Insertar_En_Columna(&columna->primero,nuevo);
}

Nodo * MatrizHibrida::Remover(int i, int j)
{
    Cabecera * fila = filas->Buscar(i);
    Cabecera * columna = &columnas[j];
    Nodo * pivote = NULL;
    if(fila != NULL && columna != NULL)
    {
        pivote = fila->primero->Remover_En_Fila(&fila->primero, j);
        pivote = columna->primero->Remover_En_Columna(&columna->primero, i);
        filas->Remover(&this->filas,i);
        return pivote;
    }
    return NULL;
}

void MatrizHibrida::Imprimir()
{
    for(int i = Obtener_Min(filas); i <= Obtener_Max(filas); i++)
    {
        for(int j = Obtener_Min(columnas); j <= Obtener_Max_Columnas(columnas,sizecolumnas); j++)
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

int MatrizHibrida::Obtener_Min(Cabecera * pivote)
{
    return pivote!=NULL?pivote[0].fila_o_columna:0;
}

int MatrizHibrida::Obtener_Max(Cabecera * pivote)
{
    if(pivote != NULL)
    {
        while(pivote->siguiente != NULL)
        {
            pivote = pivote->siguiente;
        }
        return pivote->fila_o_columna;
    }
    return 0;
}

int MatrizHibrida::Obtener_Max_Columnas(Cabecera * pivote, int maxsize)
{
    return pivote!=NULL?pivote[maxsize - 1].fila_o_columna:0;
}

Nodo * MatrizHibrida::Buscar(int i, int j)
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

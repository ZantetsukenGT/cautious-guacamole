#include "MatrizDispersa.h"

MatrizDispersa::MatrizDispersa()
{
    filas = columnas = NULL;
}

void MatrizDispersa::Insertar(int i, int j, std::string& data)
{
    Cabecera * fila = this->filas->Insertar(&this->filas,i);
    Cabecera * columna = this->columnas->Insertar(&this->columnas,j);

    Nodo * nuevo = new Nodo(i, j, data);

    fila->primero->Insertar_En_Fila(&fila->primero,nuevo);
    columna->primero->Insertar_En_Columna(&columna->primero,nuevo);
}

Nodo * MatrizDispersa::Remover(int i, int j)
{
    Cabecera * fila = filas->Buscar(i);
    Cabecera * columna = columnas->Buscar(j);
    Nodo * pivote = NULL;
    if(fila != NULL && columna != NULL)
    {
        pivote = fila->primero->Remover_En_Fila(&fila->primero, j);
        pivote = columna->primero->Remover_En_Columna(&columna->primero, i);
        filas->Remover(&this->filas,i);
        columnas->Remover(&this->columnas,j);
        return pivote;
    }
    return NULL;
}

void MatrizDispersa::Imprimir()
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

int MatrizDispersa::Obtener_Min(Cabecera * pivote)
{
    return pivote!=NULL?pivote->fila_o_columna:0;
}

int MatrizDispersa::Obtener_Max(Cabecera * pivote)
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

Nodo * MatrizDispersa::Buscar(int i, int j)
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

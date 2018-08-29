#include "Cabecera.h"

Cabecera::Cabecera()
{
    primero = NULL;
    siguiente = anterior = NULL;
    fila_o_columna = 0;
}

Cabecera::Cabecera(int fila_o_columna)
{
    primero = NULL;
    siguiente = anterior = NULL;
    this->fila_o_columna = fila_o_columna;
}

void Cabecera::Insertar_Al_Frente(Cabecera ** primero, Cabecera * nuevo)
{
    if(this == NULL)
    {
        *primero = nuevo;
    }
    else
    {
        nuevo->siguiente = this;
        this->anterior = nuevo;
        *primero = nuevo;
    }
}

void Cabecera::Insertar_Al_Final(Cabecera ** primero,Cabecera * nuevo)
{
    if(this == NULL)
    {
        *primero = nuevo;
    }
    else
    {
        Cabecera * pivote = this;
        while(pivote->siguiente != NULL)
        {
            pivote = pivote->siguiente;
        }
        nuevo->anterior = pivote;
        pivote->siguiente = nuevo;
    }
}

Cabecera * Cabecera::Remover_Del_Frente(Cabecera ** primero)
{
    if(this != NULL)
    {
        Cabecera * pivote = this;
        if(pivote->siguiente == NULL)
        {
            *primero = NULL;
        }
        else
        {
            *primero = this->siguiente;
            this->anterior = NULL;

        }
        return pivote;
    }
    return NULL;
}

Cabecera * Cabecera::Remover_Del_Final(Cabecera ** primero)
{
    if(this != NULL)
    {
        Cabecera * pivote = this;
        if(pivote->siguiente == NULL)
        {
            *primero = NULL;
        }
        else
        {
            Cabecera * pivote2 = NULL;

            while(pivote->siguiente != NULL)
            {
                pivote2 = pivote;
                pivote = pivote->siguiente;
            }
            pivote2->siguiente = NULL;
        }
        return pivote;
    }
    return NULL;
}

Cabecera * Cabecera::Buscar(int criterio)
{
    if(this != NULL)
    {
        Cabecera * pivote = this;
        while(pivote != NULL)
        {
            if(pivote->fila_o_columna == criterio)
            {
                return pivote;
            }
            pivote = pivote->siguiente;
        }
    }
    return NULL;
}

Cabecera * Cabecera::Insertar(Cabecera **primero ,int criterio)
{
    Cabecera * aux = this->Buscar(criterio);

    if(aux != NULL)
    {
        return aux;
    }
    Cabecera * nuevo = new Cabecera(criterio);
    Cabecera * pivote = NULL;

    if(this != NULL)
    {
        if(criterio < this->fila_o_columna)
        {
            Insertar_Al_Frente(primero, nuevo);
            return nuevo;
        }
        pivote = this->siguiente;
        while(pivote != NULL)
        {
            if(criterio < pivote->fila_o_columna)
            {
                pivote->anterior->siguiente = nuevo;
                nuevo->anterior = pivote->anterior;

                pivote->anterior = nuevo;
                nuevo->siguiente = pivote;
                return nuevo;
            }
            pivote = pivote->siguiente;
        }
        Insertar_Al_Final(primero, nuevo);
        return nuevo;
    }
    Insertar_Al_Frente(primero, nuevo);
    return nuevo;
}

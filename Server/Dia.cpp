#include "Dia.h"

Dia::Dia()
{
    //ctor
}

void Dia::Insertar_Al_Frente(Dia ** primero, Dia * nuevo)
{
    if(this == NULL)
    {
        *primero = nuevo;
    }
    else
    {
        nuevo->siguiente = this;
        *primero = nuevo;
    }
}

void Dia::Insertar_Al_Final(Dia ** primero, Dia * nuevo)
{
    if(this == NULL)
    {
        *primero = nuevo;
    }
    else
    {
        Dia * pivote = this;
        while(pivote->siguiente != NULL)
        {
            pivote = pivote->siguiente;
        }
        pivote->siguiente = nuevo;
    }
}

Dia * Dia::Remover_Del_Frente(Dia ** primero)
{
    if(this != NULL)
    {
        Dia * pivote = this;
        if(pivote->siguiente == NULL)
        {
            *primero = NULL;
        }
        else
        {
            *primero = this->siguiente;
        }
        return pivote;
    }
    return NULL;
}

Dia * Dia::Remover_Del_Final(Dia ** primero)
{
    if(this != NULL)
    {
        Dia * pivote = this;
        if(pivote->siguiente == NULL)
        {
            *primero = NULL;
        }
        else
        {
            Dia * pivote2 = NULL;

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

Dia * Dia::Buscar(int criterio)
{
    if(this != NULL)
    {
        Dia * pivote = this;
        while(pivote != NULL)
        {
            if(pivote->dia == criterio)
            {
                return pivote;
            }
            pivote = pivote->siguiente;
        }
    }
    return NULL;
}



Dia * Dia::Insertar(Dia ** primero, Dia * nuevo)
{
    Dia * aux = Buscar(nuevo->dia);
    if(aux != NULL)
    {
        return aux;
    }
    if(*primero != NULL)
    {
        if(nuevo->dia < (*primero)->dia)
        {
            Insertar_Al_Frente(primero,nuevo);
            return nuevo;
        }
        Dia * pivote = (*primero)->siguiente;
        while(pivote != NULL)
        {
            if(nuevo->dia < pivote->dia)
            {
                Dia * pivote2 = *primero;
                while(pivote2->siguiente != pivote)
                {
                    pivote2 = pivote2->siguiente;
                }
                nuevo->siguiente = pivote2->siguiente;
                pivote2->siguiente = nuevo;
                return nuevo;
            }
            pivote = pivote->siguiente;
        }
        Insertar_Al_Final(primero,nuevo);
        return nuevo;
    }
    Insertar_Al_Frente(primero, nuevo);
    return nuevo;
}

Dia * Dia::Remover(Dia ** primero, int criterio)
{
    Dia * aux = Buscar(criterio);
    if(aux != NULL)
    {
        if(aux == this)
        {
            return Remover_Del_Frente(primero);
        }
        else if(aux->siguiente == NULL)
        {
            return Remover_Del_Final(primero);
        }
        Dia * pivote2 = *primero;
        while(pivote2->siguiente != aux)
        {
            pivote2 = pivote2->siguiente;
        }
        pivote2->siguiente = aux->siguiente;
        return aux;
    }
    return NULL;
}

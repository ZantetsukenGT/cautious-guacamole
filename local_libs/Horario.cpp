#include "Horario.h"

Horario::Horario()
{
    //ctor
}

void Horario::Insertar_Al_Frente(Horario ** primero, Horario * nuevo)
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

void Horario::Insertar_Al_Final(Horario ** primero, Horario * nuevo)
{
    if(this == NULL)
    {
        *primero = nuevo;
    }
    else
    {
        Horario * pivote = this;
        while(pivote->siguiente != NULL)
        {
            pivote = pivote->siguiente;
        }
        pivote->siguiente = nuevo;
    }
}

Horario * Horario::Remover_Del_Frente(Horario ** primero)
{
    if(this != NULL)
    {
        Horario * pivote = this;
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

Horario * Horario::Remover_Del_Final(Horario ** primero)
{
    if(this != NULL)
    {
        Horario * pivote = this;
        if(pivote->siguiente == NULL)
        {
            *primero = NULL;
        }
        else
        {
            Horario * pivote2 = NULL;

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

Horario * Horario::Buscar(int criterio)
{
    if(this != NULL)
    {
        Horario * pivote = this;
        while(pivote != NULL)
        {
            if(pivote->YYYY == criterio)
            {
                return pivote;
            }
            pivote = pivote->siguiente;
        }
    }
    return NULL;
}



Horario * Horario::Insertar(Horario ** primero, Horario * nuevo)
{
    Horario * aux = Buscar(nuevo->YYYY);
    if(aux != NULL)
    {
        return aux;
    }
    if(*primero != NULL)
    {
        if(nuevo->YYYY < (*primero)->YYYY)
        {
            Insertar_Al_Frente(primero,nuevo);
            return nuevo;
        }
        Horario * pivote = (*primero)->siguiente;
        while(pivote != NULL)
        {
            if(nuevo->YYYY < pivote->YYYY)
            {
                Horario * pivote2 = *primero;
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

Horario * Horario::Remover(Horario ** primero, int criterio)
{
    Horario * aux = Buscar(criterio);
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
        Horario * pivote2 = *primero;
        while(pivote2->siguiente != aux)
        {
            pivote2 = pivote2->siguiente;
        }
        pivote2->siguiente = aux->siguiente;
        return aux;
    }
    return NULL;
}

#include "Curso.h"

Curso::Curso()
{
    //ctor
}

void Curso::Insertar_Al_Frente(Curso ** primero, Curso * nuevo)
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

void Curso::Insertar_Al_Final(Curso ** primero, Curso * nuevo)
{
    if(this == NULL)
    {
        *primero = nuevo;
    }
    else
    {
        Curso * pivote = this;
        while(pivote->siguiente != NULL)
        {
            pivote = pivote->siguiente;
        }
        pivote->siguiente = nuevo;
    }
}

Curso * Curso::Remover_Del_Frente(Curso ** primero)
{
    if(this != NULL)
    {
        Curso * pivote = this;
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

Curso * Curso::Remover_Del_Final(Curso ** primero)
{
    if(this != NULL)
    {
        Curso * pivote = this;
        if(pivote->siguiente == NULL)
        {
            *primero = NULL;
        }
        else
        {
            Curso * pivote2 = NULL;

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

Curso * Curso::Buscar(int criterio)
{
    if(this != NULL)
    {
        Curso * pivote = this;
        while(pivote != NULL)
        {
            if(pivote->Codigo == criterio)
            {
                return pivote;
            }
            pivote = pivote->siguiente;
        }
    }
    return NULL;
}



Curso * Curso::Insertar(Curso ** primero, Curso * nuevo)
{
    Curso * aux = Buscar(nuevo->Codigo);
    if(aux != NULL)
    {
        return aux;
    }
    if(*primero != NULL)
    {
        if(nuevo->Codigo < (*primero)->Codigo)
        {
            Insertar_Al_Frente(primero,nuevo);
            return nuevo;
        }
        Curso * pivote = (*primero)->siguiente;
        while(pivote != NULL)
        {
            if(nuevo->Codigo < pivote->Codigo)
            {
                Curso * pivote2 = *primero;
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

Curso * Curso::Remover(Curso ** primero, int criterio)
{
    Curso * aux = Buscar(criterio);
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
        Curso * pivote2 = *primero;
        while(pivote2->siguiente != aux)
        {
            pivote2 = pivote2->siguiente;
        }
        pivote2->siguiente = aux->siguiente;
        return aux;
    }
    return NULL;
}

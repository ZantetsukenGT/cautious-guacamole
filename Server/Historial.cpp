#include "Historial.h"

Historial::Historial()
{
    YYYY = -1;

    this->primer_semestre = NULL;
    this->segundo_semestre = NULL;
    this->vacas_junio = NULL;
    this->vacas_diciembre = NULL;

    this->siguiente = NULL;
}

Historial::Historial(int YYYY)
{
    this->YYYY = YYYY;

    this->primer_semestre = NULL;
    this->segundo_semestre = NULL;
    this->vacas_junio = NULL;
    this->vacas_diciembre = NULL;

    this->siguiente = NULL;
}

void Historial::Insertar_Al_Frente(Historial ** primero, Historial * nuevo)
{
    if(*primero == NULL)
    {
        *primero = nuevo;
        (*primero)->siguiente = *primero;
    }
    else
    {
        nuevo->siguiente = *primero;
        Historial * pivote = *primero;
        while(pivote->siguiente != *primero)
        {
            pivote = pivote->siguiente;
        }

        pivote->siguiente = nuevo;
        *primero = nuevo;
    }
}

void Historial::Insertar_Al_Final(Historial ** primero, Historial * nuevo)
{
    if(*primero == NULL)
    {
        *primero = nuevo;
        (*primero)->siguiente = *primero;
    }
    else
    {
        nuevo->siguiente = *primero;
        Historial * pivote = *primero;
        while(pivote->siguiente != *primero)
        {
            pivote = pivote->siguiente;
        }
        pivote->siguiente = nuevo;
    }
}

Historial * Historial::Remover_Del_Frente(Historial ** primero)
{
    if(*primero != NULL)
    {
        Historial * pivote = *primero;
        if(pivote->siguiente == *primero)
        {
            *primero = NULL;
        }
        else
        {
            Historial * pivote2 = *primero;
            while(pivote2->siguiente != *primero)
            {
                pivote2 = pivote2->siguiente;
            }
            pivote2->siguiente = (*primero)->siguiente;
            *primero = (*primero)->siguiente;
        }
        return pivote;
    }
    return NULL;
}

Historial * Historial::Remover_Del_Final(Historial ** primero)
{
    if(this != NULL)
    {
        Historial * pivote = this;
        if(pivote->siguiente == *primero)
        {
            *primero = NULL;
        }
        else
        {
            Historial * pivote2 = NULL;

            while(pivote->siguiente != *primero)
            {
                pivote2 = pivote;
                pivote = pivote->siguiente;
            }
            pivote2->siguiente = *primero;
        }
        return pivote;
    }
    return NULL;
}

Historial * Historial::Buscar(int criterio)
{
    if(this != NULL)
    {
        Historial * pivote = this;
        do{
            if(pivote->YYYY == criterio)
            {
                return pivote;
            }
            pivote = pivote->siguiente;
        }
        while(pivote != this);
    }
    return NULL;
}



Historial * Historial::Insertar(Historial ** primero, Historial * nuevo)
{
    Historial * aux = Buscar(nuevo->YYYY);
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
        Historial * pivote = (*primero)->siguiente;
        while(pivote != *primero)
        {
            if(nuevo->YYYY < pivote->YYYY)
            {
                Historial * pivote2 = *primero;
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

Historial * Historial::Remover(Historial ** primero, int criterio)
{
    Historial * aux = Buscar(criterio);
    if(aux != NULL)
    {
        if(aux == this)
        {
            return Remover_Del_Frente(primero);
        }
        else if(aux->siguiente == this)
        {
            return Remover_Del_Final(primero);
        }
        Historial * pivote2 = *primero;
        while(pivote2->siguiente != aux)
        {
            pivote2 = pivote2->siguiente;
        }
        pivote2->siguiente = aux->siguiente;
        return aux;
    }
    return NULL;
}

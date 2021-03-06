#include "Horario.h"

Horario::Horario()
{
    YYYY = -1;

    this->primer_semestre = NULL;
    this->segundo_semestre = NULL;
    this->vacas_junio = NULL;
    this->vacas_diciembre = NULL;

    this->siguiente = NULL;
}

Horario::Horario(int YYYY)
{
    this->YYYY = YYYY;

    this->primer_semestre = NULL;
    this->segundo_semestre = NULL;
    this->vacas_junio = NULL;
    this->vacas_diciembre = NULL;

    this->siguiente = NULL;
}

void Horario::Insertar_Al_Frente(Horario ** primero, Horario * nuevo)
{
    if(*primero == NULL)
    {
        *primero = nuevo;
        (*primero)->siguiente = *primero;
    }
    else
    {
        nuevo->siguiente = *primero;
        Horario * pivote = *primero;
        while(pivote->siguiente != *primero)
        {
            pivote = pivote->siguiente;
        }

        pivote->siguiente = nuevo;
        *primero = nuevo;
    }
}

void Horario::Insertar_Al_Final(Horario ** primero, Horario * nuevo)
{
    if(*primero == NULL)
    {
        *primero = nuevo;
        (*primero)->siguiente = *primero;
    }
    else
    {
        nuevo->siguiente = *primero;
        Horario * pivote = *primero;
        while(pivote->siguiente != *primero)
        {
            pivote = pivote->siguiente;
        }
        pivote->siguiente = nuevo;
    }
}

Horario * Horario::Remover_Del_Frente(Horario ** primero)
{
    if(*primero != NULL)
    {
        Horario * pivote = *primero;
        if(pivote->siguiente == *primero)
        {
            *primero = NULL;
        }
        else
        {
            Horario * pivote2 = *primero;
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

Horario * Horario::Remover_Del_Final(Horario ** primero)
{
    if(this != NULL)
    {
        Horario * pivote = this;
        if(pivote->siguiente == *primero)
        {
            *primero = NULL;
        }
        else
        {
            Horario * pivote2 = NULL;

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

Horario * Horario::Buscar(int criterio)
{
    if(this != NULL)
    {
        Horario * pivote = this;
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
        while(pivote != *primero)
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
        else if(aux->siguiente == this)
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

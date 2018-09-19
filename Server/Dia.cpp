#include "Dia.h"

Dia::Dia()
{
    this->nombre = "";
    this->HH_inicio = "";
    this->HH_fin = "";

    this->siguiente = NULL;
}

Dia::Dia(std::string nombre, std::string HH_inicio, std::string HH_fin)
{
    this->nombre = nombre;
    this->HH_inicio = HH_inicio;
    this->HH_fin = HH_fin;

    this->siguiente = NULL;
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

Dia * Dia::Buscar(std::string criterio)
{
    if(this != NULL)
    {
        Dia * pivote = this;
        while(pivote != NULL)
        {
            if(pivote->nombre == criterio)
            {
                return pivote;
            }
            pivote = pivote->siguiente;
        }
    }
    return NULL;
}

Dia * Dia::Remover(Dia ** primero, std::string criterio)
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

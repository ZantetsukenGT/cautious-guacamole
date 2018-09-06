#include "Version.h"

Version::Version()
{
    //ctor
}

void Version::Insertar_Al_Frente(Version ** primero, Version * nuevo)
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

Version * Version::Remover_Del_Frente(Version ** primero)
{
    if(this != NULL)
    {
        Version * pivote = this;
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

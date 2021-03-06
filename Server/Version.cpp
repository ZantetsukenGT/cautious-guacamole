#include "Version.h"

Version::Version()
{
    this->nombre_version = "";
    this->primero = NULL;
    this->siguiente = NULL;
}

Version::Version(std::string nombre_version)
{
    this->nombre_version = nombre_version;
    this->primero = NULL;
    this->siguiente = NULL;
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

Version * Version::Buscar(std::string criterio)
{
    if(this != NULL)
    {
        Version * pivote = this;
        while(pivote != NULL)
        {
            if(pivote->nombre_version == criterio)
            {
                return pivote;
            }
            pivote = pivote->siguiente;
        }
    }
    return NULL;
}

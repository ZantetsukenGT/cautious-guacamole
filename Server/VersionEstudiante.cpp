#include "VersionEstudiante.h"

VersionEstudiante::VersionEstudiante()
{
    this->nombre_version = "";
    this->primero = NULL;
    this->siguiente = NULL;
}

VersionEstudiante::VersionEstudiante(std::string nombre_version)
{
    this->nombre_version = nombre_version;
    this->primero = NULL;
    this->siguiente = NULL;
}

void VersionEstudiante::Insertar_Al_Frente(VersionEstudiante ** primero, VersionEstudiante * nuevo)
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

VersionEstudiante * VersionEstudiante::Remover_Del_Frente(VersionEstudiante ** primero)
{
    if(this != NULL)
    {
        VersionEstudiante * pivote = this;
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

VersionEstudiante * VersionEstudiante::Buscar(std::string criterio)
{
    if(this != NULL)
    {
        VersionEstudiante * pivote = this;
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

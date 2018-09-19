#ifndef VERSION_H
#define VERSION_H

#include <string>
#include <cstdlib>
#include "Curso.h"

class Version
{
public:
    Version();
    Version(std::string nombre_version);

    std::string nombre_version;
    Curso * primero;

    Version * siguiente;

    void Insertar_Al_Frente(Version ** primero, Version * nuevo);

    Version * Remover_Del_Frente(Version ** primero);

    Version * Buscar(std::string criterio);
};

#endif // VERSION_H

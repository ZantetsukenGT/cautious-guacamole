#ifndef VERSIONESTUDIANTE_H
#define VERSIONESTUDIANTE_H

#include <string>
#include <cstdlib>
#include "Curso.h"

class VersionEstudiante
{
public:
    VersionEstudiante();
    VersionEstudiante(std::string nombre_version);

    std::string nombre_version;
    Curso * primero;

    VersionEstudiante * siguiente;

    void Insertar_Al_Frente(VersionEstudiante ** primero, VersionEstudiante * nuevo);

    VersionEstudiante * Remover_Del_Frente(VersionEstudiante ** primero);

    VersionEstudiante * Buscar(std::string criterio);
};

#endif // VERSION_H

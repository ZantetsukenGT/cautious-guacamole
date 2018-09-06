#ifndef CURSO_H
#define CURSO_H

#include <string>
#include <cstdlib>
#include "Dia.h"

class Curso
{
public:
    Curso();

    int Codigo;
    std::string Nombre;
    char Seccion;
    std::string Edificio;
    int Salon;
    std::string Catedratico;
    Dia * dias;

    Curso * siguiente;
};

#endif // CURSO_H

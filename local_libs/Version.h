#ifndef VERSION_H
#define VERSION_H

#include <string>
#include <cstdlib>
#include "Curso.h"

class Version
{
public:
    Version();

    std::string nombre_version;
    Curso * primero;

    Version * siguiente;
};

#endif // VERSION_H

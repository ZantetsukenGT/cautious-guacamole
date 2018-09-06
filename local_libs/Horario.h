#ifndef HORARIO_H
#define HORARIO_H

#include <string>
#include <cstdlib>
#include "Version.h"

class Horario
{
public:
    Horario();

    int YYYY;

    Version * primer_semestre;
    Version * segundo_semestre;
    Version * vacas_junio;
    Version * vacas_diciembre;

    Horario * siguiente;
};

#endif // HORARIO_H

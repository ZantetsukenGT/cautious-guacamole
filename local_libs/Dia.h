#ifndef DIA_H
#define DIA_H

#include <string>
#include <cstdlib>

class Dia
{
public:
    Dia();

    std::string dia;
    int HH_inicio;
    int MM_inicio;
    int HH_fin;
    int MM_fin;

    Dia * siguiente;
};

#endif // DIA_H

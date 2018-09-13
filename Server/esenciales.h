#ifndef ESENCIALES_H_INCLUDED
#define ESENCIALES_H_INCLUDED

#include <cstdio>
#include <cstdlib>
#include <string>
#include <ctime>

class Esencial
{
public:
    Esencial();

    void GenerarSeed();

    int Contar_Digitos(int n);

    int randomizer(int Min, int Max);

    int * SplitFecha(std::string cadena);

};

#endif // ESENCIALES_H_INCLUDED

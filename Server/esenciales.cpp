#include "esenciales.h"

Esencial::Esencial()
{

}

void Esencial::GenerarSeed()
{
    srand(time(NULL));
}

int Esencial::Contar_Digitos(int n)
{
    if(n >= 10)
    {
        return 1 + Contar_Digitos(n/10);
    }
    return 1;
}

int Esencial::randomizer(int Min, int Max)
{
    return Min + rand()%(Max-Min+1);
}

int * Esencial::SplitFecha(std::string cadena)
{
    std::string temporal = "";
    int *arr = new int[3];
    int j = 0;
    for(int i = 0; i < (signed int)cadena.length(); i++)
    {
        if(cadena[i] != '/')
        {
            temporal+=cadena[i];
            continue;
        }
        arr[j++] = std::atoi(temporal.c_str());
        temporal = "";
    }
    arr[2] = std::atoi(temporal.c_str());
    return arr;
}


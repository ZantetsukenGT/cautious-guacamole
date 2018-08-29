#include <iostream>

#include "Arbol.h"
#include "Matriz.h"
#include "esenciales.h"



int main()
{
    GenerarSeed();
    Matriz *a1 = new Matriz();
    for(int i = 0; i < 200; i++)
    {
        int j = randomizer(0,20);
        int k = randomizer(0,50);
        a1->Insertar(j,k,randomizer(0,1));
    }

    a1->Imprimir();
    return 0;
}

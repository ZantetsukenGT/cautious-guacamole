#include <iostream>

#include "Arbol.h"
#include "MatrizHibrida.h"
#include "esenciales.h"


int main()
{
    GenerarSeed();
    MatrizDispersa *a1 = new MatrizDispersa();

    for(int i = 0; i < 500; i++)
    {
        std::string value = "sex";
        int j = randomizer(0,10);
        int k = randomizer(0,10);
        a1->Insertar(j,k,value);
    }

    /*a1->Imprimir();
    printf("\n\n");
    for(int i = 0; i < 500; i++)
    {
        int j = randomizer(0,10);
        int k = randomizer(0,a1->sizecolumnas);
        a1->Remover(j,k);
    }

    a1->Imprimir();*/

    Arbol *a2 = new Arbol();
    Estudiante * e1 = new Estudiante();
    e1->Imagen = a1;
    e1->Carnet = 22;//etc

    a2->Insertar(e1);
    a2->PreOrder();

    return 0;
}

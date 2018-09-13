#include <iostream>
#include <fstream>
#include <string>
#include "local_libs/Arbol.h"
#include "local_libs/MatrizHibrida.h"
#include "local_libs/esenciales.h"
int main()
{
    Esencial * e = new Esencial();
    e->GenerarSeed();
    MatrizDispersa *m1 = new MatrizDispersa();

    for(int i = 0; i < 500; i++)
    {
        std::string value = "verde";
        int j = e->randomizer(0,10);
        int k = e->randomizer(0,10);
        m1->Insertar(j,k,value);
    }
    /*
        m1->Imprimir();
        printf("\n\n");
        for(int i = 0; i < 500; i++)
        {
            int j = randomizer(0,10);
            int k = randomizer(0,m1->sizecolumnas);
            m1->Remover(j,k);
        }

        m1->Imprimir();*/

    Arbol *a1 = new Arbol();
    Estudiante * e1 = NULL;
    for(int i = 0; i < 30; i++)
    {
        e1 = new Estudiante();
        e1->Carnet = e->randomizer(0,30);//etc
        if(a1->Insertar(e1))
            std::cout << "correcto" << std::endl;
        else
            std::cout << "incorrecto" << std::endl;
    }


    std::string texto = "digraph G { rankdir = TB; node[shape=circle]; \n\n ";
	texto+= a1->PreOrderFormat();
	texto+= "\n\n";
	texto+= a1->PreOrderLink();
	texto+= "} ";

	std::ofstream f;
	f.open("Arbol.dot");
	f << texto;
	f.close();
    system("dot -Tpng Arbol.dot -o Arbol.png");

    return 0;
}

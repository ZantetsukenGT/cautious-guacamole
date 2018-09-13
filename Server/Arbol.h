#ifndef ARBOL_H
#define ARBOL_H

#include <iostream>
#include <cstdlib>

#include "Estudiante.h"

class NodoArbol
{

public:
    NodoArbol();
    NodoArbol(Estudiante * data);

    NodoArbol * izquierda;
    NodoArbol * derecha;

    int Obtener_Clave();
    Estudiante * Get_Data();

private:
    Estudiante * data;
};

class Arbol
{

public:
    Arbol();
    Arbol(Estudiante * data);

    bool Insertar(Estudiante * data);
    Estudiante * Buscar(int criterio);

    std::string PreOrderFormat();
    std::string PreOrderLink();

    NodoArbol * raiz;

private:

    bool AyudanteInsertar(NodoArbol ** raiz, Estudiante * data);
    Estudiante * AyudanteBuscar(NodoArbol * raiz, int criterio);

    std::string AyudantePreOrderFormat(NodoArbol * raiz);
    std::string AyudantePreOrderLink(NodoArbol * raiz);

    std::string VisitarFormatear(NodoArbol * raiz);
    std::string VisitarLinkear(NodoArbol * raiz);
};

#endif // ARBOL_H

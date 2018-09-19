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

    NodoArbol ** Buscar(int criterio);
    bool Insertar(Estudiante * data);

    Estudiante * Remover(int criterio);
    void Modificar(Estudiante * nuevo, int viejo);

    std::string PreOrderFormat();
    std::string PreOrderLink();

    NodoArbol * raiz;

private:

    NodoArbol * BuscarMenorDeMayores(NodoArbol * raiz);
    bool AyudanteInsertar(NodoArbol ** raiz, Estudiante * data);
    NodoArbol ** AyudanteBuscar(NodoArbol ** raiz, int criterio);

    std::string AyudantePreOrderFormat(NodoArbol * raiz);
    std::string AyudantePreOrderLink(NodoArbol * raiz);

    std::string VisitarFormatear(NodoArbol * raiz);
    std::string VisitarLinkear(NodoArbol * raiz);
};

#endif // ARBOL_H

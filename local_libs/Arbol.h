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

    int Obtener_Data();

private:
    Estudiante * data;
};

class Arbol
{

public:
    Arbol();
    Arbol(Estudiante * data);

    void Insertar(Estudiante * data);

    void PreOrder();
    void InOrder();
    void PostOrder();

    NodoArbol * raiz;

private:

    void AyudanteInsertar(NodoArbol ** raiz, Estudiante * data);

    void AyudantePreOrder(NodoArbol * raiz);
    void AyudanteInOrder(NodoArbol * raiz);
    void AyudantePostOrder(NodoArbol * raiz);

    void Visitar(NodoArbol * raiz);
};

#endif // ARBOL_H

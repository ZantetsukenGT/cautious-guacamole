#ifndef ARBOL_H
#define ARBOL_H

#include <iostream>
#include <cstdlib>


class NodoArbol
{

public:
    NodoArbol();
    NodoArbol(int data);

    NodoArbol * izquierda;
    NodoArbol * derecha;

    int Obtener_Data();

private:
    int data;
};

class Arbol
{

public:
    Arbol();
    Arbol(int data);

    void Insertar(int data);

    void PreOrder();
    void InOrder();
    void PostOrder();

    NodoArbol * raiz;

private:

    void AyudanteInsertar(NodoArbol ** raiz, int data);

    void AyudantePreOrder(NodoArbol * raiz);
    void AyudanteInOrder(NodoArbol * raiz);
    void AyudantePostOrder(NodoArbol * raiz);

    void Visitar(NodoArbol * raiz);
};

#endif // ARBOL_H

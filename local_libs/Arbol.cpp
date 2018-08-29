#include "Arbol.h"

NodoArbol::NodoArbol()
{
    this->izquierda = this->derecha = NULL;
    this->data = 0;
}

NodoArbol::NodoArbol(int data)
{

    this->izquierda = this->derecha = NULL;
    this->data = data;
}

int NodoArbol::Obtener_Data()
{
    return this->data;
}


Arbol::Arbol()
{
    this->raiz = NULL;
}

Arbol::Arbol(int data)
{
    this->raiz = new NodoArbol(data);
}

void Arbol::Insertar(int data)
{
    AyudanteInsertar(&this->raiz, data);
}

void Arbol::PreOrder()
{
    AyudantePreOrder(this->raiz);
}

void Arbol::InOrder()
{
    AyudanteInOrder(this->raiz);
}

void Arbol::PostOrder()
{
    AyudantePostOrder(this->raiz);
}

void Arbol::AyudanteInsertar(NodoArbol ** raiz, int data)
{
    if(*raiz == NULL)
    {
        *raiz = new NodoArbol(data);
    }
    else if(data < (*raiz)->Obtener_Data())
    {
        AyudanteInsertar(&(*raiz)->izquierda, data);
    }
    else if(data > (*raiz)->Obtener_Data())
    {
        AyudanteInsertar(&(*raiz)->derecha, data);
    }
}

void Arbol::AyudantePreOrder(NodoArbol * raiz)
{
    if(raiz == NULL)
        return;
    Visitar(raiz);
    AyudantePreOrder(raiz->izquierda);
    AyudantePreOrder(raiz->derecha);
}

void Arbol::AyudanteInOrder(NodoArbol * raiz)
{
    if(raiz == NULL)
        return;
    AyudanteInOrder(raiz->izquierda);
    Visitar(raiz);
    AyudanteInOrder(raiz->derecha);
}

void Arbol::AyudantePostOrder(NodoArbol * raiz)
{
    if(raiz == NULL)
        return;
    AyudantePostOrder(raiz->izquierda);
    AyudantePostOrder(raiz->derecha);
    Visitar(raiz);
}

void Arbol::Visitar(NodoArbol * raiz)
{
    std::cout << raiz->Obtener_Data() << ", ";
}



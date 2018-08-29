#include "Arbol.h"
template <class T>
Arbol<T>::Arbol()
{
    this->data = 0;
}

template <class T>
Arbol<T>::Arbol(T data)
{
    this->data = data;
}

template <class T>
Arbol<T>::~Arbol()
{
    //dtor
}

template <class T>
T Arbol<T>::getData()
{
    return this->data;
}

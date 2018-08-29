#ifndef ARBOL_H
#define ARBOL_H

template <class T>
class Arbol
{

    public:
        Arbol<T>();
        Arbol<T>(T data);
        virtual ~Arbol<T>();
        T data;
        T getData();
};

template class Arbol<int>;

#endif // ARBOL_H

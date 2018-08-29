#ifndef NODO_H
#define NODO_H

#include <cstdlib>

class Nodo
{
public:
    Nodo();
    Nodo(int i, int j, int dato);

    Nodo * arriba;
    Nodo * abajo;
    Nodo * izquierda;
    Nodo * derecha;

    int i, j;
    int dato;

    void Insertar_Al_Frente_Fila(Nodo ** primero, Nodo * nuevo);
    void Insertar_Al_Final_Fila(Nodo ** primero, Nodo * nuevo);

    Nodo * Remover_Del_Frente_Fila(Nodo ** primero);
    Nodo * Remover_Del_Final_Fila(Nodo ** primero);

    Nodo * Buscar_En_Fila(int criterio);

    void Insertar_Al_Frente_Columna(Nodo ** primero, Nodo * nuevo);
    void Insertar_Al_Final_Columna(Nodo ** primero, Nodo * nuevo);

    Nodo * Remover_Del_Frente_Columna(Nodo ** primero);
    Nodo * Remover_Del_Final_Columna(Nodo ** primero);

    Nodo * Buscar_En_Columna(int criterio);

    void Insertar_En_Fila(Nodo ** primero, Nodo * nuevo);
    void Insertar_En_Columna(Nodo ** primero, Nodo * nuevo);
};

#endif // NODO_H

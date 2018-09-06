#ifndef DIA_H
#define DIA_H

#include <string>
#include <cstdlib>

class Dia
{
public:
    Dia();

    std::string nombre;
    int dia;
    int HH_inicio;
    int MM_inicio;
    int HH_fin;
    int MM_fin;

    Dia * siguiente;

    void Insertar_Al_Frente(Dia ** primero, Dia * nuevo);
    void Insertar_Al_Final(Dia ** primero, Dia * nuevo);

    Dia * Remover_Del_Frente(Dia ** primero);
    Dia * Remover_Del_Final(Dia ** primero);

    Dia * Buscar(int criterio);
///////////////////////////////////////////////////////////////////////
    Dia * Insertar(Dia ** primero, Dia * nuevo);

    Dia * Remover(Dia ** primero, int criterio);
};

#endif // DIA_H

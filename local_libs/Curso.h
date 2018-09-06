#ifndef CURSO_H
#define CURSO_H

#include <string>
#include <cstdlib>
#include "Dia.h"

class Curso
{
public:
    Curso();

    int Codigo;
    std::string Nombre;
    char Seccion;
    std::string Edificio;
    int Salon;
    std::string Catedratico;
    Dia * dias;

    Curso * siguiente;

    void Insertar_Al_Frente(Curso ** primero, Curso * nuevo);
    void Insertar_Al_Final(Curso ** primero, Curso * nuevo);

    Curso * Remover_Del_Frente(Curso ** primero);
    Curso * Remover_Del_Final(Curso ** primero);

    Curso * Buscar(int criterio);
///////////////////////////////////////////////////////////////////////
    Curso * Insertar(Curso ** primero, Curso * nuevo);

    Curso * Remover(Curso ** primero, int criterio);
};

#endif // CURSO_H

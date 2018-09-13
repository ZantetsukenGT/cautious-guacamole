#ifndef HORARIO_H
#define HORARIO_H

#include <string>
#include <cstdlib>
#include "Version.h"

class Horario
{
public:
    Horario();

    int YYYY;

    Version * primer_semestre;
    Version * segundo_semestre;
    Version * vacas_junio;
    Version * vacas_diciembre;

    Horario * siguiente;

    void Insertar_Al_Frente(Horario ** primero, Horario * nuevo);
    void Insertar_Al_Final(Horario ** primero, Horario * nuevo);

    Horario * Remover_Del_Frente(Horario ** primero);
    Horario * Remover_Del_Final(Horario ** primero);

    Horario * Buscar(int criterio);
///////////////////////////////////////////////////////////////////////
    Horario * Insertar(Horario ** primero, Horario * nuevo);

    Horario * Remover(Horario ** primero, int criterio);
};

#endif // HORARIO_H

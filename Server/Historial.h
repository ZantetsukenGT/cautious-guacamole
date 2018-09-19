#ifndef HISTORIALESTUDIANTE_H
#define HISTORIALESTUDIANTE_H

#include <string>
#include <cstdlib>
#include "VersionEstudiante.h"

class Historial
{
public:
    Historial();
    Historial(int YYYY);

    int YYYY;

    VersionEstudiante * primer_semestre;
    VersionEstudiante * segundo_semestre;
    VersionEstudiante * vacas_junio;
    VersionEstudiante * vacas_diciembre;

    Historial * siguiente;

    void Insertar_Al_Frente(Historial ** primero, Historial * nuevo);
    void Insertar_Al_Final(Historial ** primero, Historial * nuevo);

    Historial * Remover_Del_Frente(Historial ** primero);
    Historial * Remover_Del_Final(Historial ** primero);

    Historial * Buscar(int criterio);
///////////////////////////////////////////////////////////////////////
    Historial * Insertar(Historial ** primero, Historial * nuevo);

    Historial * Remover(Historial ** primero, int criterio);
};

#endif // HORARIO_H

#ifndef DIA_H
#define DIA_H

#include <string>
#include <cstdlib>

class Dia
{
public:
    Dia();
    Dia(std::string nombre, std::string HH_inicio, std::string HH_fin);

    std::string nombre;
    std::string HH_inicio;
    std::string HH_fin;

    Dia * siguiente;

    void Insertar_Al_Frente(Dia ** primero, Dia * nuevo);
    void Insertar_Al_Final(Dia ** primero, Dia * nuevo);

    Dia * Remover_Del_Frente(Dia ** primero);
    Dia * Remover_Del_Final(Dia ** primero);

    Dia * Buscar(std::string criterio);

    Dia * Remover(Dia ** primero, std::string criterio);
};

#endif // DIA_H

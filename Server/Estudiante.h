#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <cstdlib>
#include <string>
#include "MatrizDispersa.h"
#include "Horario.h"

class Estudiante
{
public:
    Estudiante();
    Estudiante(int Carnet, int DPI,std::string Nombres,
               std::string Apellidos, int DD_Nacimiento,int MM_Nacimiento,
               int YYYY_Nacimiento,std::string Direccion,int Creditos,
               MatrizDispersa *Imagen, std::string Password, Horario * horarios);
    int Carnet;
    int DPI;
    std::string Nombres;
    std::string Apellidos;
    int DD_Nacimiento;
    int MM_Nacimiento;
    int YYYY_Nacimiento;
    std::string Direccion;
    int Creditos;
    std::string Password;
    MatrizDispersa *Imagen;
    Horario * horarios;

    int ObtenerFechaNacimiento();
};

#endif // ESTUDIANTE_H

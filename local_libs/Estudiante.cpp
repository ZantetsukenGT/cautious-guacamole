#include "Estudiante.h"


Estudiante::Estudiante()
{
    Carnet = DPI = DD_Nacimiento = MM_Nacimiento = YYYY_Nacimiento = Creditos = 0;
    Nombres = Apellidos = Direccion = Password = "";
    Imagen = NULL;
    horarios = NULL;
}

Estudiante::Estudiante(int Carnet, int DPI,std::string Nombres,
                       std::string Apellidos, int DD_Nacimiento,int MM_Nacimiento,
                       int YYYY_Nacimiento,std::string Direccion,int Creditos,
                       MatrizDispersa *Imagen, std::string Password, Horario * horarios)

{
    this->Carnet = Carnet;
    this->DPI = DPI;
    this->Nombres = Nombres;
    this->Apellidos = Apellidos;
    this->DD_Nacimiento = DD_Nacimiento;
    this->MM_Nacimiento = MM_Nacimiento;
    this->YYYY_Nacimiento = YYYY_Nacimiento;
    this->Direccion = Direccion;
    this->Creditos = Creditos;
    this->Password = Password;
    this->Imagen = Imagen;
    this->horarios = horarios;
}

    int Estudiante::ObtenerFechaNacimiento()
    {
        return DD_Nacimiento + 31*MM_Nacimiento + 372*YYYY_Nacimiento;
    }

#include "Arbol.h"

NodoArbol::NodoArbol()
{
    this->izquierda = this->derecha = NULL;
    this->data = NULL;
}

NodoArbol::NodoArbol(Estudiante * data)
{

    this->izquierda = this->derecha = NULL;
    this->data = data;
}

int NodoArbol::Obtener_Clave()
{
    return this->data->Carnet;
}


Estudiante * NodoArbol::Get_Data()
{
    return this->data;
}

Arbol::Arbol()
{
    this->raiz = NULL;
}

Arbol::Arbol(Estudiante * data)
{
    this->raiz = new NodoArbol(data);
}

NodoArbol ** Arbol::Buscar(int criterio)
{
    return AyudanteBuscar(&this->raiz, criterio);
}

bool Arbol::Insertar(Estudiante * data)
{
    return AyudanteInsertar(&this->raiz, data);
}

void Arbol::Modificar(Estudiante * nuevo, int viejo)
{
    Estudiante * old = Remover(viejo);
    nuevo->horarios = old->horarios;
    nuevo->Imagen = old->Imagen;
    Insertar(nuevo);
}

Estudiante * Arbol::Remover(int criterio)
{
    NodoArbol ** remover = Buscar(criterio);
    NodoArbol * pivote = *remover;
    if(*remover != NULL)
    {
        if((*remover)->izquierda && (*remover)->derecha)
        {
            NodoArbol * MenorDeMayores = BuscarMenorDeMayores((*remover)->derecha);

            Remover(MenorDeMayores->Obtener_Clave());

            MenorDeMayores->izquierda = (*remover)->izquierda;
            MenorDeMayores->derecha = (*remover)->derecha;
            *remover = MenorDeMayores;
        }
        else if((*remover)->izquierda && !(*remover)->derecha)
        {
            *remover = (*remover)->izquierda;
        }
        else if(!(*remover)->izquierda && (*remover)->derecha)
        {
            *remover = (*remover)->derecha;
        }
        else
        {
            *remover = NULL;
        }
        return pivote->Get_Data();
    }
    return NULL;
}

NodoArbol * Arbol::BuscarMenorDeMayores(NodoArbol * raiz)
{
    if(raiz->izquierda != NULL)
    {
        return BuscarMenorDeMayores(raiz->izquierda);
    }
    return raiz;
}

NodoArbol ** Arbol::AyudanteBuscar(NodoArbol ** raiz, int criterio)
{
    if((*raiz) == NULL)
    {
        return raiz;
    }
    else if(criterio < (*raiz)->Obtener_Clave())
    {
        return AyudanteBuscar(&(*raiz)->izquierda, criterio);
    }
    else if(criterio > (*raiz)->Obtener_Clave())
    {
        return AyudanteBuscar(&(*raiz)->derecha, criterio);
    }
    return raiz;
}

bool Arbol::AyudanteInsertar(NodoArbol ** raiz, Estudiante * data)
{
    if(*raiz == NULL)
    {
        *raiz = new NodoArbol(data);
        return true;
    }
    else if(data->Carnet < (*raiz)->Obtener_Clave())
    {
        return AyudanteInsertar(&(*raiz)->izquierda, data);
    }
    else if(data->Carnet > (*raiz)->Obtener_Clave())
    {
        return AyudanteInsertar(&(*raiz)->derecha, data);
    }
    return false;
}

std::string Arbol::PreOrderFormat()
{
    std::string text = "Arbol; ";
    if(this->raiz != NULL)
        text += AyudantePreOrderFormat(this->raiz);
    return text;
}

std::string Arbol::PreOrderLink()
{
    std::string text = "";
    if(this->raiz != NULL)
    {
        text += "Arbol->Nodo" + std::to_string(this->raiz->Obtener_Clave()) + "; ";
        text += AyudantePreOrderLink(this->raiz);
    }
    return text;
}

std::string Arbol::VisitarFormatear(NodoArbol * raiz)
{
    std::string clave = std::to_string(raiz->Obtener_Clave());
    std::string text = "Nodo" + clave + "[label=\"" + clave + "\"]; ";
    return text;
}

std::string Arbol::VisitarLinkear(NodoArbol * raiz)
{
	std::string text = "";
    if(raiz->izquierda != NULL)
    {
        text += "Nodo" + std::to_string(raiz->Obtener_Clave());
        text += "->Nodo" + std::to_string(raiz->izquierda->Obtener_Clave()) + "; ";
    }
    if (raiz->derecha != NULL)
    {
        text += "Nodo" + std::to_string(raiz->Obtener_Clave());
        text += "->Nodo" + std::to_string(raiz->derecha->Obtener_Clave()) + "; ";
    }
    return text;
}


std::string Arbol::AyudantePreOrderFormat(NodoArbol * raiz)
{
    std::string a = "";
    if(raiz == NULL) return a;
    a += VisitarFormatear(raiz);
    a += AyudantePreOrderFormat(raiz->izquierda);
    a += AyudantePreOrderFormat(raiz->derecha);
    return a;
}

std::string Arbol::AyudantePreOrderLink(NodoArbol * raiz)
{
    std::string a = "";
    if(raiz == NULL) return a;
    a += VisitarLinkear(raiz);
    a += AyudantePreOrderLink(raiz->izquierda);
    a += AyudantePreOrderLink(raiz->derecha);
    return a;
}


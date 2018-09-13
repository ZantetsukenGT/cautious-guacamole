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

bool Arbol::Insertar(Estudiante * data)
{
    return AyudanteInsertar(&this->raiz, data);
}

Estudiante * Arbol::Buscar(int criterio)
{
    return AyudanteBuscar(raiz, criterio);
}

Estudiante * Arbol::AyudanteBuscar(NodoArbol * raiz, int criterio)
{
    if(raiz == NULL)
    {
        return NULL;
    }
    else if(criterio < raiz->Obtener_Clave())
    {
        return AyudanteBuscar(raiz->izquierda, criterio);
    }
    else if(criterio > raiz->Obtener_Clave())
    {
        return AyudanteBuscar(raiz->derecha, criterio);
    }
    return raiz->Get_Data();
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


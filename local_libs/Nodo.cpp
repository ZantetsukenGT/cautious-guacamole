#include "Nodo.h"

Nodo::Nodo()
{
    arriba = abajo = izquierda = derecha = NULL;
    i = j = 0;
    data = "";
}

Nodo::Nodo(int i, int j, std::string& data)
{
    arriba = abajo = izquierda = derecha = NULL;
    this->i = i;
    this->j = j;
    this->data = data;
}

void Nodo::Insertar_Al_Frente_Fila(Nodo ** primero, Nodo * nuevo)
{
    if(this == NULL)
    {
        *primero = nuevo;
    }
    else
    {
        nuevo->derecha = this;
        this->izquierda = nuevo;
        *primero = nuevo;
    }
}

void Nodo::Insertar_Al_Final_Fila(Nodo ** primero, Nodo * nuevo)
{
    if(this == NULL)
    {
        *primero = nuevo;
    }
    else
    {
        Nodo * pivote = this;
        while(pivote->derecha != NULL)
        {
            pivote = pivote->derecha;
        }
        nuevo->izquierda = pivote;
        pivote->derecha = nuevo;
    }
}

Nodo * Nodo::Remover_Del_Frente_Fila(Nodo ** primero)
{
    if(this != NULL)
    {
        Nodo * pivote = this;
        if(pivote->derecha == NULL)
        {
            *primero = NULL;
        }
        else
        {
            *primero = this->derecha;
            (*primero)->izquierda = NULL;

        }
        return pivote;
    }
    return NULL;
}

Nodo * Nodo::Remover_Del_Final_Fila(Nodo ** primero)
{
    if(this != NULL)
    {
        Nodo * pivote = this;
        if(pivote->derecha == NULL)
        {
            *primero = NULL;
        }
        else
        {
            Nodo * pivote2 = NULL;

            while(pivote->derecha != NULL)
            {
                pivote2 = pivote;
                pivote = pivote->derecha;
            }
            pivote2->derecha = NULL;
        }
        return pivote;
    }
    return NULL;
}

Nodo * Nodo::Buscar_En_Fila(int criterio)
{
    if(this != NULL)
    {
        Nodo * pivote = this;
        while(pivote != NULL)
        {
            if(pivote->j == criterio)
            {
                return pivote;
            }
            pivote = pivote->derecha;
        }
    }
    return NULL;
}

void Nodo::Insertar_Al_Frente_Columna(Nodo ** primero, Nodo * nuevo)
{
    if(this == NULL)
    {
        *primero = nuevo;
    }
    else
    {
        nuevo->abajo = this;
        this->arriba = nuevo;
        *primero = nuevo;
    }
}

void Nodo::Insertar_Al_Final_Columna(Nodo ** primero, Nodo * nuevo)
{
    if(this == NULL)
    {
        *primero = nuevo;
    }
    else
    {
        Nodo * pivote = this;
        while(pivote->abajo != NULL)
        {
            pivote = pivote->abajo;
        }
        nuevo->arriba = pivote;
        pivote->abajo = nuevo;
    }
}

Nodo * Nodo::Remover_Del_Frente_Columna(Nodo ** primero)
{
    if(this != NULL)
    {
        Nodo * pivote = this;
        if(pivote->abajo == NULL)
        {
            *primero = NULL;
        }
        else
        {
            *primero = this->abajo;
            (*primero)->arriba = NULL;

        }
        return pivote;
    }
    return NULL;
}

Nodo * Nodo::Remover_Del_Final_Columna(Nodo ** primero)
{
    if(this != NULL)
    {
        Nodo * pivote = this;
        if(pivote->abajo == NULL)
        {
            *primero = NULL;
        }
        else
        {
            Nodo * pivote2 = NULL;

            while(pivote->abajo != NULL)
            {
                pivote2 = pivote;
                pivote = pivote->abajo;
            }
            pivote2->abajo = NULL;
        }
        return pivote;
    }
    return NULL;
}

Nodo * Nodo::Buscar_En_Columna(int criterio)
{
    if(this != NULL)
    {
        Nodo * pivote = this;
        while(pivote != NULL)
        {
            if(pivote->i == criterio)
            {
                return pivote;
            }
            pivote = pivote->abajo;
        }
    }
    return NULL;
}



void Nodo::Insertar_En_Fila(Nodo ** primero, Nodo * nuevo)
{
    if(*primero != NULL)
    {
        if(nuevo->j == (*primero)->j)
        {
            return;
        }
        if(nuevo->j < (*primero)->j)
        {
            Insertar_Al_Frente_Fila(primero,nuevo);
            return;
        }
        Nodo * pivote = (*primero)->derecha;
        while(pivote != NULL)
        {
            if(nuevo->j == pivote->j)
            {
                return;
            }
            if(nuevo->j < pivote->j)
            {
                nuevo->derecha = pivote;
                nuevo->izquierda = pivote->izquierda;

                pivote->izquierda->derecha = nuevo;
                pivote->izquierda = nuevo;
                return;
            }
            pivote = pivote->derecha;
        }
        Insertar_Al_Final_Fila(primero,nuevo);
        return;
    }
    Insertar_Al_Frente_Fila(primero, nuevo);
}

void Nodo::Insertar_En_Columna(Nodo ** primero, Nodo * nuevo)
{
    if(*primero != NULL)
    {
        if(nuevo->i == (*primero)->i)
        {
            return;
        }
        if(nuevo->i < (*primero)->i)
        {
            Insertar_Al_Frente_Columna(primero,nuevo);
            return;
        }
        Nodo * pivote = (*primero)->abajo;
        while(pivote != NULL)
        {
            if(nuevo->i == pivote->i)
            {
                return;
            }
            if(nuevo->i < pivote->i)
            {
                nuevo->abajo = pivote;
                nuevo->arriba = pivote->arriba;

                pivote->arriba->abajo = nuevo;
                pivote->arriba = nuevo;
                return;
            }
            pivote = pivote->abajo;
        }
        Insertar_Al_Final_Columna(primero,nuevo);
        return;
    }
    Insertar_Al_Frente_Columna(primero, nuevo);
}

Nodo * Nodo::Remover_En_Fila(Nodo ** primero, int criterio)
{
    Nodo * aux = this->Buscar_En_Fila(criterio);
    if(aux != NULL)
    {
        if(aux == this)
        {
            return Remover_Del_Frente_Fila(primero);
        }
        else if(aux->derecha == NULL)
        {
            return Remover_Del_Final_Fila(primero);
        }
        aux->izquierda->derecha = aux->derecha;
        aux->derecha->izquierda = aux->izquierda;
        return aux;
    }
    return NULL;
}

Nodo * Nodo::Remover_En_Columna(Nodo ** primero, int criterio)
{
    Nodo * aux = this->Buscar_En_Columna(criterio);
    if(aux != NULL)
    {
        if(aux == this)
        {
            return Remover_Del_Frente_Columna(primero);
        }
        else if(aux->abajo == NULL)
        {
            return Remover_Del_Final_Columna(primero);
        }
        aux->arriba->abajo = aux->abajo;
        aux->abajo->arriba = aux->arriba;
        return aux;
    }
    return NULL;
}

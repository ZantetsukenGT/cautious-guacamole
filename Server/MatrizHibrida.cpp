#include "MatrizHibrida.h"

MatrizHibrida::MatrizHibrida()
{
    filas = columnas = NULL;
}

MatrizHibrida::MatrizHibrida(int size_j)
{
    sizecolumnas = size_j;
    filas = NULL;
    columnas = new Cabecera[size_j];

    for(int j = 0; j < size_j; j++)
    {
        columnas[j] = *(new Cabecera(j));
    }
}

void MatrizHibrida::Insertar(int i, int j, std::string& data)
{
    Cabecera * fila = this->filas->Insertar(&this->filas,i);
    Cabecera * columna = &columnas[j];

    Nodo * nuevo = new Nodo(i, j, data);

    fila->primero->Insertar_En_Fila(&fila->primero,nuevo);
    columna->primero->Insertar_En_Columna(&columna->primero,nuevo);
}

Nodo * MatrizHibrida::Remover(int i, int j)
{
    Cabecera * fila = filas->Buscar(i);
    Cabecera * columna = &columnas[j];
    Nodo * pivote = NULL;
    if(fila != NULL && columna != NULL)
    {
        pivote = fila->primero->Remover_En_Fila(&fila->primero, j);
        pivote = columna->primero->Remover_En_Columna(&columna->primero, i);
        filas->Remover(&this->filas,i);
        return pivote;
    }
    return NULL;
}

void MatrizHibrida::Imprimir()
{
    for(int i = Obtener_Min(filas); i <= Obtener_Max(filas); i++)
    {
        for(int j = Obtener_Min(columnas); j <= Obtener_Max_Columnas(columnas,sizecolumnas); j++)
        {
            Nodo * pivote = Buscar(i,j);
            if(pivote != NULL)
                std::cout << pivote->data;
            else
                std::cout << '-';
        }
        std::cout << std::endl;
    }
}

std::string MatrizHibrida::ImprimirFormatNodos()
{
    std::string result = "";
    Cabecera * pivote = NULL;
    for(int i = 0; i < sizecolumnas; i++)
    {
        pivote = &columnas[i];
        result += "\tCabeceraColumna" + std::to_string(pivote->fila_o_columna);
        result += "[label = \"x"+ std::to_string(pivote->fila_o_columna) +"\"];\n";
    }

    result += "\n";
    pivote = this->filas;
    while(pivote != NULL)
    {
        result += "\tCabeceraFila" + std::to_string(pivote->fila_o_columna);
        result += "[label = \"y"+ std::to_string(pivote->fila_o_columna) +"\"];\n";
        pivote = pivote->siguiente;
    }
    result += "\n";
    pivote = this->filas;
    while(pivote != NULL)
    {
        Nodo * pivote2 = pivote->primero;
        if(pivote2 != NULL)
        {
            std::string x = std::to_string(pivote2->j);
            std::string y = std::to_string(pivote2->i);
            std::string data = pivote2->data;
            while(pivote2 != NULL)
            {
                x = std::to_string(pivote2->j);
                y = std::to_string(pivote2->i);
                data = pivote2->data;

                result += "\tNodoX" + x +"Y"+ y;
                result += "[label = \"xy:" + x + "," + y +"\n#"+ data + "\"];\n";
                pivote2 = pivote2->derecha;
            }
        }
        pivote = pivote->siguiente;
    }
    result += "\n";
    return result;
}

std::string MatrizHibrida::ImprimirMatrizNodos()
{
    std::string result = "digraph g\n{\n\tdpi = \"100\";\n\tsize = \"15\";\n\trankdir = \"TB\";\n\tnode[shape = box];\n\t";
    result += "Matriz;\n\n";

    result += ImprimirFormatNodos();

    result += ImprimirCabecerasFilasNodos();
    result += ImprimirCabecerasColumnasNodos();

    result += ImprimirFilaNodos();
    result += ImprimirColumnaNodos();

    result += "}";
    return result;
}

std::string MatrizHibrida::ImprimirCabecerasFilasNodos()
{
    Cabecera * pivote = this->filas;
    std::string result = "";
    if(pivote != NULL)
    {
        result += "\tsubgraph cabeceras_filas";
        result += "\n\t{\n";
        result += "\n\tMatriz->";
        while(pivote != NULL)
        {
            if(pivote->siguiente != NULL)
            {
                result += "CabeceraFila" + std::to_string(pivote->fila_o_columna);
                result += "->";
            }
            else
            {
                result += "CabeceraFila" + std::to_string(pivote->fila_o_columna);
                result += ";\n\t";
            }
            pivote = pivote->siguiente;
        }
        result += "}\n\n";
    }
    return result;
}

std::string MatrizHibrida::ImprimirCabecerasColumnasNodos()
{
    Cabecera * pivote = NULL;
    std::string result = "";
    result += "\tsubgraph cabeceras_columnas";
    result += "\n\t{\n\trank = \"same\"\n\n";
    result += "\n\tMatriz->";
    for(int i = 0; i < sizecolumnas; i++)
    {
        pivote = &columnas[i];
        if(i != sizecolumnas - 1)
        {
            result += "CabeceraColumna" + std::to_string(pivote->fila_o_columna);
            result += "->";
        }
        else
        {
            result += "CabeceraColumna" + std::to_string(pivote->fila_o_columna);
            result += ";\n\t";
        }
    }
    result += "}\n\n";
    return result;
}

std::string MatrizHibrida::ImprimirFilaNodos()
{
    std::string result = "";
    Cabecera * pivote = this->filas;
    while(pivote != NULL)
    {
        result += "\tsubgraph y" + std::to_string(pivote->fila_o_columna) + "_fila";
        result += "\n\t{\n\trank = \"same\"\n\n";
        Nodo * pivote2 = pivote->primero;
        if(pivote2 != NULL)
        {
            std::string x = std::to_string(pivote2->j);
            std::string y = std::to_string(pivote2->i);
            result += "\n\tCabeceraFila" + std::to_string(pivote->fila_o_columna) + "->";
            while(pivote2 != NULL)
            {
                x = std::to_string(pivote2->j);
                y = std::to_string(pivote2->i);

                if(pivote2->derecha != NULL)
                {
                    result += "NodoX" + x +"Y"+ y;
                    result += "->";
                }
                else
                {
                    result += "NodoX" + x +"Y"+ y;
                    result += ";\n\t";
                    break;
                }
                pivote2 = pivote2->derecha;
            }

            while(pivote2 != NULL)
            {
                x = std::to_string(pivote2->j);
                y = std::to_string(pivote2->i);

                if(pivote2->izquierda != NULL)
                {
                    result += "NodoX" + x +"Y"+ y;
                    result += "->";
                }
                else
                {
                    result += "NodoX" + x +"Y"+ y;
                    result += ";\n\t";
                }
                pivote2 = pivote2->izquierda;
            }
        }
        result += "}\n\n";
        pivote = pivote->siguiente;
    }
    return result;
}

std::string MatrizHibrida::ImprimirColumnaNodos()
{
    std::string result = "";
    Cabecera * pivote = NULL;
    for(int i = 0; i < sizecolumnas; i++)
    {
        pivote = &columnas[i];
        result += "\tsubgraph x" + std::to_string(pivote->fila_o_columna) + "_columna";
        result += "\n\t{\n\n";
        Nodo * pivote2 = pivote->primero;
        if(pivote2 != NULL)
        {
            std::string x = std::to_string(pivote2->j);
            std::string y = std::to_string(pivote2->i);

            result += "\n\tCabeceraColumna" + std::to_string(pivote->fila_o_columna) + "->";
            while(pivote2 != NULL)
            {
                x = std::to_string(pivote2->j);
                y = std::to_string(pivote2->i);

                if(pivote2->abajo != NULL)
                {
                    result += "NodoX" + x +"Y"+ y;
                    result += "->";
                }
                else
                {
                    result += "NodoX" + x +"Y"+ y;
                    result += ";\n\t";
                    break;
                }
                pivote2 = pivote2->abajo;
            }

            while(pivote2 != NULL)
            {
                x = std::to_string(pivote2->j);
                y = std::to_string(pivote2->i);

                if(pivote2->arriba != NULL)
                {
                    result += "NodoX" + x +"Y"+ y;
                    result += "->";
                }
                else
                {
                    result += "NodoX" + x +"Y"+ y;
                    result += ";\n\t";
                }
                pivote2 = pivote2->arriba;
            }
        }
        result += "}\n";
    }
    return result;
}

int MatrizHibrida::Obtener_Min(Cabecera * pivote)
{
    return pivote!=NULL?pivote[0].fila_o_columna:0;
}

int MatrizHibrida::Obtener_Max(Cabecera * pivote)
{
    if(pivote != NULL)
    {
        while(pivote->siguiente != NULL)
        {
            pivote = pivote->siguiente;
        }
        return pivote->fila_o_columna;
    }
    return 0;
}

int MatrizHibrida::Obtener_Max_Columnas(Cabecera * pivote, int maxsize)
{
    return pivote!=NULL?pivote[maxsize - 1].fila_o_columna:0;
}

Nodo * MatrizHibrida::Buscar(int i, int j)
{
    Cabecera * fila = filas->Buscar(i);

    if(fila != NULL)
    {
        Nodo * pivote = fila->primero->Buscar_En_Fila(j);
        if(pivote != NULL)
            return pivote;
    }
    return NULL;
}

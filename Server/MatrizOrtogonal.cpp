#include "MatrizOrtogonal.h"

MatrizOrtogonal::MatrizOrtogonal()
{
    filas = columnas = NULL;
}

MatrizOrtogonal::MatrizOrtogonal(int size_i, int size_j)
{
    sizefilas = size_i;
    sizecolumnas = size_j;
    filas = new Cabecera[size_i];
    columnas = new Cabecera[size_j];

    for(int i = 0; i < size_i; i++)
    {
        filas[i] = *(new Cabecera(i));
    }
    for(int j = 0; j < size_j; j++)
    {
        columnas[j] = *(new Cabecera(j));
    }
}

void MatrizOrtogonal::Insertar(int i, int j, std::string& data)
{
    Cabecera * fila = &this->filas[i];
    Cabecera * columna = &this->columnas[j];

    Nodo * nuevo = new Nodo(i, j, data);

    fila->primero->Insertar_En_Fila(&fila->primero,nuevo);
    columna->primero->Insertar_En_Columna(&columna->primero,nuevo);
}

Nodo * MatrizOrtogonal::Remover(int i, int j)
{
    Cabecera * fila = &filas[i];
    Cabecera * columna = &columnas[j];
    Nodo * pivote = NULL;
    if(fila != NULL && columna != NULL)
    {
        pivote = fila->primero->Remover_En_Fila(&fila->primero, j);
        pivote = columna->primero->Remover_En_Columna(&columna->primero, i);
        return pivote;
    }
    return NULL;
}

void MatrizOrtogonal::Imprimir()
{
    for(int i = Obtener_Min(filas); i <= Obtener_Max(filas, sizefilas); i++)
    {
        for(int j = Obtener_Min(columnas); j <= Obtener_Max(columnas,sizecolumnas); j++)
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

std::string MatrizOrtogonal::ImprimirFormatNodos()
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
    for(int i = 0; i < sizefilas; i++)
    {
        pivote = &filas[i];
        result += "\tCabeceraFila" + std::to_string(pivote->fila_o_columna);
        result += "[label = \"y"+ std::to_string(pivote->fila_o_columna) +"\"];\n";
    }
    result += "\n";
    for(int i = 0; i < sizefilas; i++)
    {
        pivote = &filas[i];
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
    }
    result += "\n";
    return result;
}

std::string MatrizOrtogonal::ImprimirMatrizNodos()
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

std::string MatrizOrtogonal::ImprimirCabecerasFilasNodos()
{
    Cabecera * pivote = NULL;
    std::string result = "";
    result += "\tsubgraph cabeceras_filas";
    result += "\n\t{\n";
    result += "\n\tMatriz->";
    for(int i = 0; i < sizefilas; i++)
    {
        pivote = &filas[i];
        if(i != sizefilas - 1)
        {
            result += "CabeceraFila" + std::to_string(pivote->fila_o_columna);
            result += "->";
        }
        else
        {
            result += "CabeceraFila" + std::to_string(pivote->fila_o_columna);
            result += ";\n\t";
        }
    }
    result += "}\n\n";
    return result;
}

std::string MatrizOrtogonal::ImprimirCabecerasColumnasNodos()
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

std::string MatrizOrtogonal::ImprimirFilaNodos()
{
    std::string result = "";
    Cabecera * pivote = NULL;
    for(int i = 0; i < sizefilas; i++)
    {
        pivote = &filas[i];
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
    }
    return result;
}

std::string MatrizOrtogonal::ImprimirColumnaNodos()
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

int MatrizOrtogonal::Obtener_Min(Cabecera * pivote)
{
    return pivote!=NULL?pivote[0].fila_o_columna:0;
}

int MatrizOrtogonal::Obtener_Max(Cabecera * pivote, int maxsize)
{
    return pivote!=NULL?pivote[maxsize - 1].fila_o_columna:0;
}

Nodo * MatrizOrtogonal::Buscar(int i, int j)
{
    Cabecera * fila = &filas[i];

    if(fila != NULL)
    {
        Nodo * pivote = fila->primero->Buscar_En_Fila(j);
        if(pivote != NULL)
            return pivote;
    }
    return NULL;
}

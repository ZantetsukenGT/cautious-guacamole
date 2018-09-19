#include "MatrizDispersa.h"

MatrizDispersa::MatrizDispersa()
{
    filas = columnas = NULL;
}

void MatrizDispersa::Insertar(int i, int j, std::string& data)
{
    Cabecera * fila = this->filas->Insertar(&this->filas,i);
    Cabecera * columna = this->columnas->Insertar(&this->columnas,j);

    Nodo * nuevo = new Nodo(i, j, data);

    fila->primero->Insertar_En_Fila(&fila->primero,nuevo);
    columna->primero->Insertar_En_Columna(&columna->primero,nuevo);
}

Nodo * MatrizDispersa::Remover(int i, int j)
{
    Cabecera * fila = filas->Buscar(i);
    Cabecera * columna = columnas->Buscar(j);
    Nodo * pivote = NULL;
    if(fila != NULL && columna != NULL)
    {
        pivote = fila->primero->Remover_En_Fila(&fila->primero, j);
        pivote = columna->primero->Remover_En_Columna(&columna->primero, i);
        filas->Remover(&this->filas,i);
        columnas->Remover(&this->columnas,j);
        return pivote;
    }
    return NULL;
}

std::string MatrizDispersa::GenerarGrafo(int criterio)
{
    std::string result = "";
    std::string input = "";
    if(criterio == -1)
    {
        input = this->ImprimirMatrizNodos();
        std::ofstream f;
        f.open("public/temporalMatrizNodos.dot");
        f << input;
        f.close();
    	system("dot -Tpng public/temporalMatrizNodos.dot -o public/temporalMatrizNodos.png");
    	result = "public/temporalMatrizNodos.png";
    	return result;
    }
    else if(criterio == -2)
    {
        input = this->ImprimirMatrizImagen();
        std::ofstream f;
        f.open("public/temporalMatrizImagen.dot");
        f << input;
        f.close();
    	system("neato -n -Tpng public/temporalMatrizImagen.dot -o public/temporalMatrizImagen.png");
    	result = "public/temporalMatrizImagen.png";
    	return result;
    }
    else
    {
        input = this->ImprimirMatrizImagen();
        std::ofstream f;
        f.open("public/Imagen" + std::to_string(criterio) +".dot");
        f << input;
        f.close();
        std::string cmd = "neato -n -Tpng public/Imagen" + std::to_string(criterio) +".dot -o public/Imagen" + std::to_string(criterio) +".png";
    	system(cmd.c_str());
    	result = "public/Imagen" + std::to_string(criterio) +".png";
    	return result;
    }
}

void MatrizDispersa::Imprimir()
{
    for(int i = Obtener_Min(filas); i <= Obtener_Max(filas); i++)
    {
        for(int j = Obtener_Min(columnas); j <= Obtener_Max(columnas); j++)
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

std::string MatrizDispersa::ImprimirFormatNodos()
{
    std::string result = "";
    Cabecera * pivote = this->columnas;
    while(pivote != NULL)
    {
        result += "\tCabeceraColumna" + std::to_string(pivote->fila_o_columna);
        result += "[label = \"x"+ std::to_string(pivote->fila_o_columna) +"\"];\n";
        pivote = pivote->siguiente;
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

std::string MatrizDispersa::ImprimirMatrizNodos()
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

std::string MatrizDispersa::ImprimirCabecerasFilasNodos()
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

std::string MatrizDispersa::ImprimirCabecerasColumnasNodos()
{
    Cabecera * pivote = this->columnas;
    std::string result = "";
    if(pivote != NULL)
    {
        result += "\tsubgraph cabeceras_columnas";
        result += "\n\t{\n\trank = \"same\"\n\n";
        result += "\n\tMatriz->";
        while(pivote != NULL)
        {
            if(pivote->siguiente != NULL)
            {
                result += "CabeceraColumna" + std::to_string(pivote->fila_o_columna);
                result += "->";
            }
            else
            {
                result += "CabeceraColumna" + std::to_string(pivote->fila_o_columna);
                result += ";\n\t";
            }
            pivote = pivote->siguiente;
        }
        result += "}\n\n";
    }
    return result;
}

std::string MatrizDispersa::ImprimirFilaNodos()
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

std::string MatrizDispersa::ImprimirColumnaNodos()
{
    std::string result = "";
    Cabecera * pivote = this->columnas;
    while(pivote != NULL)
    {
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
        pivote = pivote->siguiente;
    }
    return result;
}

std::string MatrizDispersa::ImprimirMatrizImagen()
{
    std::string result = "digraph g\n{\n\tdpi = 100;\n\tsize = 300;\n\tnode";
    result += "[shape = point, height = 0.01, width = 0.01];\n\t";
    Cabecera * pivote = this->filas;
    while(pivote != NULL)
    {
        result += ImprimirFilaImagen(pivote,Obtener_Max(this->filas));
        pivote = pivote->siguiente;
    }

    result += "}";
    return result;
}
std::string MatrizDispersa::ImprimirFilaImagen(Cabecera * fila, int MaxFilas)
{
    std::string result = "";
    Nodo * pivote = fila->primero;
    while(pivote != NULL)
    {
        std::string x = std::to_string(pivote->j);
        std::string y = std::to_string(MaxFilas - pivote->i);
        std::string data = pivote->data;

        result += "NodoX" + x +"Y"+ y;
        result += "[pos = \""+ x +","+ y +"\", color = \"#" + data + "\"];\n\t";

        pivote = pivote->derecha;
    }
    return result;
}

int MatrizDispersa::Obtener_Min(Cabecera * pivote)
{
    return pivote!=NULL?pivote->fila_o_columna:0;
}

int MatrizDispersa::Obtener_Max(Cabecera * pivote)
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

Nodo * MatrizDispersa::Buscar(int i, int j)
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

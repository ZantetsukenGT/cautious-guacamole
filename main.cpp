#include <iostream>
#include "Arbol.h"

int main()
{
    Arbol<int> *a1 = new Arbol<int>(21);
    std::cout << a1->getData();
    return 0;
}

// menu.cpp

#include <iostream>

// Definición de códigos ANSI para colores
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m" //"\033[40m\033[34m"

void mostrarMenu() {
    std::cout << BLUE << "\n\nPARQUEADERO" << RESET << std::endl;
    std::cout << BLUE << "1- Ingresar vehículo" << RESET << std::endl;
    std::cout << BLUE << "2- Retirar Vehículo"<< RESET << std::endl;
    std::cout << BLUE << "3- Ver capacidad libre y ocupada"<< RESET << std::endl;
    std::cout << RED <<  "4- Terminar\n" << RESET << std::endl;
}

int obtenerOpcion() {
    int opcion;
    std::cout << GREEN << "Ingrese la opción: "<< RESET;
    std::cin >> opcion;
    std::cout << RESET;
    return opcion;
}


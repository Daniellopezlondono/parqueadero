// main.cpp

/*
Para compilar: 
   g++ main.cpp nodo.cpp vehiculo.cpp -o programa

Para ejecutar:
   ./programa
*/

#include <Windows.h>

#include <iostream>
#include "nodo.h"
#include "vehiculo.h"1
#include "menu.cpp"  // Incluye el archivo externo

//==============================================

// Definición de códigos ANSI para colores
#define RESET   "\033[0m"
#define RED     "\033[31m"


const int MAX_VEHICULOS = 8;
const double TARIFA_HORA = 255.0;
int plazasOcupadas = 0;
Nodo* parqueadero[MAX_VEHICULOS];



//void atenderMenu(int opcion, Nodo* (&parqueadero)[10]) {
void atenderMenu(int opcion) {
    switch (opcion) {
        case 1: {
            std::cout << "Ingresar vehículo\n";

            // Solicitar datos al usuario
            std::string placa;
            int horaIngreso;
            std::string porteria;

            std::cout << "Ingrese la placa del vehículo: (texto) ";
            std::cin >> placa;

            std::cout << "Ingrese la hora de ingreso del vehículo: (hora militar e. 8:05 -> 805  4:30 pm -> 1630) ";
            std::cin >> horaIngreso;

            std::cout << "Ingrese la porteria del vehículo: (texto) ";
            std::cin >> porteria;


            // Crear un objeto Vehiculo con los datos ingresados y adicionarlo al parqueadero
            parqueadero[plazasOcupadas]=new Nodo(Vehiculo(placa, horaIngreso, porteria));
            plazasOcupadas = plazasOcupadas+1;

            //validar si se supera el limité
            break;
        }

        case 2:
            std::cout << "Retirar Vehículo\n";
            // Aquí puedes agregar la lógica para retirar un vehículo
            break;

        case 3:
            std::cout << "\n VER CAPADIDAD DEL PARQUEADERO\n";

            std::cout << "     Capacidad Total: " << std::to_string(MAX_VEHICULOS) << std::endl;
            std::cout << "     Capacidad Ocupada: " << std::to_string(plazasOcupadas) << std::endl;
            std::cout << std::endl << " DETALLE" << std::endl;
            for (int i = 0; i < MAX_VEHICULOS; ++i) {
                Nodo* item = parqueadero[i];
                if (item != nullptr) {
                    std::cout << "     ["<< std::to_string(i) <<"] " << "Vehiculo: " << parqueadero[i]->vehiculo.to_string() << std::endl;
                } else {
                    std::cout << "     ["<< std::to_string(i) <<"] "<< RED << "Libre" << RESET << std::endl;
                }
            }
            break;

        default:
            std::cout << "Opcion no valida\n";
            break;
    }
}



//===============================================

int main() {
    SetConsoleOutputCP(CP_UTF8); //para ver las tildes en el terminal
    int opcion;
    bool terminar = false;

    //Inicializar espacios
    for(int i = 0; i<MAX_VEHICULOS ; ++i){
        parqueadero[i]=nullptr;
    }

    while (!terminar) {
        mostrarMenu();  // Llama a la función del archivo externo para mostrar el menú
        opcion = obtenerOpcion();  // Llama a la función para obtener la opción

        if (opcion == 4) {
            terminar = true;
        } else {
            atenderMenu(opcion);  // Llama a la función para atender la opción seleccionada
        }
    }

    return 0;
}

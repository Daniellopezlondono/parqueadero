// nodo.h
#ifndef NODO_H
#define NODO_H

#include <iostream>
#include <string>
#include <ctime>
#include "vehiculo.h"

// Definición de la clase Nodo
class Nodo {
    public:
        Vehiculo vehiculo;  // Objeto Vehiculo como dato del Nodo
        
        // Constructor de la clase Nodo
        Nodo(Vehiculo vehiculo) : vehiculo(vehiculo) {}
};

#endif // NODO_H

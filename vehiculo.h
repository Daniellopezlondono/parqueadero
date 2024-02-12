// vehiculo.h
#ifndef VEHICULO_H
#define VEHICULO_H

#include <string>

class Vehiculo {
public:
    // Constructor de la clase Vehiculo
    Vehiculo(std::string placa, int horaIngreso, std::string porteria);
    // Método para calcular el tiempo al retirar el vehículo con la hora actual
    void calcularTiempoAlRetirar();
    // Método para obtener una representación en formato de cadena de texto del vehículo
    std::string to_string();

private:
    std::string placa;
    int horaIngreso;
    std::string porteria;

    // Método privado para obtener la hora actual en formato militar
    int obtenerHoraActualMilitar();
};

#endif // VEHICULO_H

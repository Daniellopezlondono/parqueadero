// vehiculo.cpp
#include "vehiculo.h"
#include <iostream>
#include <ctime>
#include <sstream>

// Constructor de la clase Vehiculo
Vehiculo::Vehiculo(std::string placa, int horaIngreso, std::string porteria)
    : placa(placa), horaIngreso(horaIngreso), porteria(porteria) {}

// Método privado para obtener la hora actual en formato militar
int Vehiculo::obtenerHoraActualMilitar() {
    time_t Ahora = time(0);
    struct tm* now = localtime(&Ahora);
    return now->tm_hour * 100 + now->tm_min; // Formato militar: HHMM
}

// Método para calcular el tiempo al retirar el vehículo con la hora actual
void Vehiculo::calcularTiempoAlRetirar() {
    int horaActual = obtenerHoraActualMilitar();

    // Calcular la diferencia de tiempo en formato militar
    int diferencia = horaActual - horaIngreso;

    // Mostrar el tiempo que ha permanecido el vehículo
    std::cout << "Tiempo en el parqueadero: " << diferencia / 100 << " horas, " << diferencia % 100 << " minutos." << std::endl;
}

// Método para obtener una representación en formato de cadena de texto del vehículo
std::string Vehiculo::to_string() {
    std::stringstream ss;
    ss << "Placa: " << placa << ", Hora de ingreso: " << horaIngreso << ", Porteria: " << porteria;
    return ss.str();
}

#include "medico.h"
#include <iostream>

std::vector<Medico> medicos;


void altaMedico() {
    std::string nombre, apellidos, DNI, especialidad, disponibilidad;

    std::cout << "Nombre: ";
    std::cin >> nombre;
    std::cout << "Apellidos: ";
    std::cin >> apellidos;
    std::cout << "DNI: ";
    std::cin >> DNI;
    std::cout << "Especialidad: ";
    std::cin >> especialidad;
    std::cout << "Disponibilidad: ";
    std::cin >> disponibilidad;

    Medico nuevoMedico(nombre, apellidos, DNI, especialidad, disponibilidad);
    medicos.push_back(nuevoMedico);

    std::cout << "El m�dico " << nombre << " " << apellidos << " con DNI: " << DNI
        << " ha sido dado de alta correctamente.\n";
}

void mostrarMedicos() {
    if (medicos.empty()) {
        std::cout << "No hay m�dicos registrados.\n";
        return;
    }
    for (size_t i = 0; i < medicos.size(); i++) {
        std::cout << "M�dico " << i + 1 << ":\n";
        std::cout << "Nombre: " << medicos[i].nombre << " " << medicos[i].apellidos << "\n";
        std::cout << "DNI: " << medicos[i].DNI << "\n";
        std::cout << "Especialidad: " << medicos[i].especialidad << "\n";
        std::cout << "Disponibilidad: " << medicos[i].disponibilidad << "\n";
    }
}

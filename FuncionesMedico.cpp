#include "medico.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

std::vector<Medico> medicos;

void cargarMedicos() {
    std::ifstream file("medicos.txt");
    if (!file) {
        std::cout << "No se pudo abrir el archivo de m�dicos.\n";
        return;
    }
    std::string nombre, apellidos, DNI, especialidad, disponibilidad;
    while (file >> nombre >> apellidos >> DNI >> especialidad >> disponibilidad) {
        medicos.push_back(Medico(nombre, apellidos, DNI, especialidad, disponibilidad));
    }
    file.close();
}

void guardarMedicos() {
    std::ofstream file("medicos.txt", std::ios::trunc);
    if (!file) {
        std::cout << "Error al abrir el archivo para guardar m�dicos.\n";
        return;
    }
    for (const Medico& medico : medicos) {
        file << medico.nombre << " " << medico.apellidos << " " << medico.DNI << " "
            << medico.especialidad << " " << medico.disponibilidad << "\n";
    }
    file.close();
}

void altaMedico() {
    std::string nombre, apellidos, DNI, especialidad, disponibilidad;

    std::cout << "Introduce los datos del m�dico:\n";
    std::cout << "Nombre: ";
    std::cin.ignore();
    std::getline(std::cin, nombre);
    std::cout << "Apellidos: ";
    std::getline(std::cin, apellidos);
    std::cout << "DNI: ";
    std::cin >> DNI;
    std::cout << "Especialidad: ";
    std::cin >> especialidad;
    std::cout << "Disponibilidad: ";
    std::cin >> disponibilidad;

    Medico nuevoMedico(nombre, apellidos, DNI, especialidad, disponibilidad);
    medicos.push_back(nuevoMedico);
    guardarMedicos();

    std::cout << "El m�dico " << nombre << " " << apellidos << " con DNI: " << DNI
        << " ha sido dado de alta correctamente.\n";
}

void mostrarMedicos() {
    if (medicos.empty()) {
        std::cout << "No hay m�dicos registrados.\n";
        return;
    }
    std::cout << "========================================\n";
    for (size_t i = 0; i < medicos.size(); i++) {
        std::cout << "M�dico " << i + 1 << " | "
            << "Nombre: " << medicos[i].nombre << " " << medicos[i].apellidos << " | "
            << "DNI: " << medicos[i].DNI << " | "
            << "Especialidad: " << medicos[i].especialidad << " | "
            << "Disponibilidad: " << medicos[i].disponibilidad << "\n";
    }
    std::cout << "========================================\n";
}

void buscarMedicoDNI() {
    std::string DNI;
    std::cout << "Introduce el DNI del m�dico: ";
    std::cin >> DNI;

    for (const Medico& medico : medicos) {
        if (medico.DNI == DNI) {
            std::cout << "M�dico encontrado:\n";
            std::cout << "Nombre: " << medico.nombre << " " << medico.apellidos << " | "
                << "DNI: " << medico.DNI << " | "
                << "Especialidad: " << medico.especialidad << " | "
                << "Disponibilidad: " << medico.disponibilidad << "\n";
            return;
        }
    }
    std::cout << "No se encontr� un m�dico con ese DNI.\n";
}

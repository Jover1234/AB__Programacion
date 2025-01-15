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

    std::cout << "El médico " << nombre << " " << apellidos << " con DNI: " << DNI
        << " ha sido dado de alta correctamente.\n";
}

void mostrarMedicos() {
    if (medicos.empty()) {
        std::cout << "No hay médicos registrados.\n";
        return;
    }
    for (size_t i = 0; i < medicos.size(); i++) {
        std::cout << "Médico " << i + 1 << ":\n";
        std::cout << "Nombre: " << medicos[i].nombre << " " << medicos[i].apellidos << "\n";
        std::cout << "DNI: " << medicos[i].DNI << "\n";
        std::cout << "Especialidad: " << medicos[i].especialidad << "\n";
        std::cout << "Disponibilidad: " << medicos[i].disponibilidad << "\n";
    }
}

void modificarMedico(Medico& medico) {
    std::cout << "Nombre: ";
    std::cin >> medico.nombre;
    std::cout << "Apellidos: ";
    std::cin >> medico.apellidos;
    std::cout << "DNI: ";
    std::cin >> medico.DNI;
    std::cout << "Especialidad: ";
    std::cin >> medico.especialidad;
    std::cout << "Disponibilidad: ";
    std::cin >> medico.disponibilidad;

    std::cout << "Datos modificados con éxito.\n";
}

void bajaMedico(size_t indice) {
    std::string respuesta;
    std::cout << "¿Quieres dar de baja (eliminar) al médico? (si/no): ";
    std::cin >> respuesta;

    if (respuesta == "si") {
        std::cout << "El médico " << medicos[indice].nombre << " " << medicos[indice].apellidos
            << " con DNI " << medicos[indice].DNI << " ha sido dado de baja.\n";
        medicos.erase(medicos.begin() + indice); // Eliminar médico del vector
    }
    else {
        std::cout << "No se realizaron cambios.\n";
    }
}

void buscarMedicoDNI() {
    std::string BuscarDNI;
    std::cout << "DNI: ";
    std::cin >> BuscarDNI;

    for (size_t i = 0; i < medicos.size(); i++) {
        if (medicos[i].DNI == BuscarDNI) {
            std::cout << "Médico " << i + 1 << ":\n";
            std::cout << "Nombre: " << medicos[i].nombre << " " << medicos[i].apellidos << "\n";
            std::cout << "DNI: " << medicos[i].DNI << "\n";
            std::cout << "Especialidad: " << medicos[i].especialidad << "\n";
            std::cout << "Disponibilidad: " << medicos[i].disponibilidad << "\n";

            int opcion;
            std::cout << "¿Qué acción desea realizar?\n";
            std::cout << "1. Modificar datos del médico\n";
            std::cout << "2. Dar de baja al médico\n";
            std::cout << "3. Cancelar\n";
            std::cout << "Elija una opción: ";
            std::cin >> opcion;

            switch (opcion) {
            case 1:
                modificarMedico(medicos[i]);
                break;
            case 2:
                bajaMedico(i);
                break;
            case 3:
                std::cout << "Operación cancelada.\n";
                break;
            default:
                std::cout << "Opción inválida.\n";
            }
            return; // Salir tras manejar el médico
        }
    }

    std::cout << "Médico con DNI " << BuscarDNI << " no encontrado.\n";
}


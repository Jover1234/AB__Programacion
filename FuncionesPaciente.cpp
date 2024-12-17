#include "paciente.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits>
#include <sstream>

std::vector<Paciente> pacientes;

void cargarPacientes() {
    std::ifstream file("pacientes.txt");
    if (!file) {
        std::cout << "No se pudo abrir el archivo de pacientes.\n";
        return;
    }
    std::string nombre, apellidos, DNI, sexo, FechaNacimiento, FechaIngreso, FechaBaja;
    int edad;
    while (file >> nombre >> apellidos >> DNI >> sexo >> edad >> FechaNacimiento >> FechaIngreso >> FechaBaja) {
        pacientes.push_back(Paciente(nombre, apellidos, DNI, sexo, edad, FechaNacimiento, FechaIngreso, FechaBaja));
    }
    file.close();
}

void guardarPacientes() {
    std::ofstream file("pacientes.txt", std::ios::trunc);
    if (!file) {
        std::cout << "Error al abrir el archivo para guardar pacientes.\n";
        return;
    }
    for (const Paciente& paciente : pacientes) {
        file << paciente.nombre << " " << paciente.apellidos << " " << paciente.DNI << " "
            << paciente.sexo << " " << paciente.edad << " " << paciente.FechaNacimiento << " "
            << paciente.FechaIngreso << " " << paciente.fechaBaja << "\n";
    }
    file.close();
}

void altaPaciente() {
    std::string nombre, apellidos, DNI, sexo, FechaNacimiento, FechaIngreso, FechaBaja;
    int edad;

    std::cout << "Introduce los datos del paciente:\n";
    std::cout << "Nombre: ";
    std::cin.ignore();
    std::getline(std::cin, nombre);
    std::cout << "Apellidos: ";
    std::getline(std::cin, apellidos);
    std::cout << "DNI: ";
    std::cin >> DNI;
    std::cout << "Sexo (M/F): ";
    std::cin >> sexo;

    // Validar edad
    while (true) {
        std::cout << "Edad (en años): ";
        std::cin >> edad;
        if (std::cin.fail() || edad <= 0) {
            std::cout << "Por favor, ingresa una edad válida.\n";
            std::cin.clear();  // Limpiar el error de entrada
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignorar la línea incorrecta
        }
        else {
            break;
        }
    }

    std::cout << "Fecha de Nacimiento (DD/MM/AAAA): ";
    std::cin >> FechaNacimiento;
    std::cout << "Fecha de Ingreso (DD/MM/AAAA): ";
    std::cin >> FechaIngreso;
    std::cout << "Fecha de Baja (DD/MM/AAAA): ";
    std::cin >> FechaBaja;

    Paciente nuevoPaciente(nombre, apellidos, DNI, sexo, edad, FechaNacimiento, FechaIngreso, FechaBaja);
    pacientes.push_back(nuevoPaciente);
    guardarPacientes();

    std::cout << "El paciente " << nombre << " " << apellidos << " con DNI: " << DNI
        << " se ha dado de alta correctamente.\n";
}

void BajaPaciente(size_t indice) {
    std::string respuesta;
    std::cout << "¿Quieres dar de baja (eliminar) al paciente? (si/no): ";
    std::cin >> respuesta;

    if (respuesta == "si") {
        std::cout << "El paciente " << pacientes[indice].nombre << " " << pacientes[indice].apellidos
            << " con DNI " << pacientes[indice].DNI << " ha sido dado de baja.\n";
        pacientes.erase(pacientes.begin() + indice); // Eliminar paciente del vector
        guardarPacientes(); // Actualizar archivo
    }
    else {
        std::cout << "No se realizaron cambios.\n";
    }
}

void mostrarPacientes() {
    if (pacientes.empty()) {
        std::cout << "No hay pacientes registrados.\n";
        return;
    }
    std::cout << "========================================\n";
    for (size_t i = 0; i < pacientes.size(); i++) {
        std::cout << "Paciente " << i + 1 << " | "
            << "Nombre: " << pacientes[i].nombre << " " << pacientes[i].apellidos << " | "
            << "DNI: " << pacientes[i].DNI << " | "
            << "Sexo: " << pacientes[i].sexo << " | "
            << "Edad: " << pacientes[i].edad << " | "
            << "Fecha de Nacimiento: " << pacientes[i].FechaNacimiento << " | "
            << "Fecha de Ingreso: " << pacientes[i].FechaIngreso << " | "
            << "Fecha de Baja: " << pacientes[i].fechaBaja << "\n";
    }
    std::cout << "========================================\n";
}

void modificarPaciente(Paciente& paciente) {
    std::cout << "Nombre: ";
    std::cin >> paciente.nombre;
    std::cout << "Apellidos: ";
    std::cin >> paciente.apellidos;
    std::cout << "DNI: ";
    std::cin >> paciente.DNI;
    std::cout << "Sexo: ";
    std::cin >> paciente.sexo;
    std::cout << "Edad: ";
    std::cin >> paciente.edad;
    std::cout << "Fecha de Nacimiento: ";
    std::cin >> paciente.FechaNacimiento;
    std::cout << "Fecha de Ingreso: ";
    std::cin >> paciente.FechaIngreso;
    std::cout << "Fecha de Baja: ";
    std::cin >> paciente.fechaBaja;

    std::cout << "Datos modificados con éxito.\n";
    guardarPacientes(); // Guardar cambios al archivo
}

void buscarPacienteDNI() {
    std::string BuscarDNI;
    std::cout << "DNI: ";
    std::cin >> BuscarDNI;

    for (size_t i = 0; i < pacientes.size(); i++) {
        if (pacientes[i].DNI == BuscarDNI) {
            std::cout << "Paciente " << i + 1 << ":\n";
            std::cout << "Nombre: " << pacientes[i].nombre << " " << pacientes[i].apellidos << "\n";
            std::cout << "DNI: " << pacientes[i].DNI << "\n";
            std::cout << "Sexo: " << pacientes[i].sexo << "\n";
            std::cout << "Edad: " << pacientes[i].edad << "\n";
            std::cout << "Fecha de Nacimiento: " << pacientes[i].FechaNacimiento << "\n";
            std::cout << "Fecha de Ingreso: " << pacientes[i].FechaIngreso << "\n";
            std::cout << "Fecha de Baja: " << pacientes[i].fechaBaja << "\n";

            int opcion;
            std::cout << "¿Qué acción desea realizar?\n";
            std::cout << "1. Modificar datos del paciente\n";
            std::cout << "2. Dar de baja al paciente\n";
            std::cout << "3. Cancelar\n";
            std::cout << "Elija una opción: ";
            std::cin >> opcion;

            switch (opcion) {
            case 1:
                modificarPaciente(pacientes[i]);
                break;
            case 2:
                BajaPaciente(i);
                break;
            case 3:
                std::cout << "Operación cancelada.\n";
                break;
            default:
                std::cout << "Opción inválida.\n";
            }
            return; // Salir tras manejar el paciente
        }
    }

    std::cout << "Paciente con DNI " << BuscarDNI << " no encontrado.\n";
}

void buscarPacienteNombre() {
    std::string BuscarNombre;
    std::cout << "Nombre: ";
    std::cin >> BuscarNombre;

    for (size_t i = 0; i < pacientes.size(); i++) {
        if (pacientes[i].nombre == BuscarNombre) {
            std::cout << "Paciente " << i + 1 << ":\n";
            std::cout << "Nombre: " << pacientes[i].nombre << " " << pacientes[i].apellidos << "\n";
            std::cout << "DNI: " << pacientes[i].DNI << "\n";
            std::cout << "Sexo: " << pacientes[i].sexo << "\n";
            std::cout << "Edad: " << pacientes[i].edad << "\n";
            std::cout << "Fecha de Nacimiento: " << pacientes[i].FechaNacimiento << "\n";
            std::cout << "Fecha de Ingreso: " << pacientes[i].FechaIngreso << "\n";
            std::cout << "Fecha de Baja: " << pacientes[i].fechaBaja << "\n";

            int opcion;
            std::cout << "¿Qué acción desea realizar?\n";
            std::cout << "1. Modificar datos del paciente\n";
            std::cout << "2. Dar de baja al paciente\n";
            std::cout << "3. Cancelar\n";
            std::cout << "Elija una opción: ";
            std::cin >> opcion;

            switch (opcion) {
            case 1:
                modificarPaciente(pacientes[i]);
                break;
            case 2:
                BajaPaciente(i);
                break;
            case 3:
                std::cout << "Operación cancelada.\n";
                break;
            default:
                std::cout << "Opción inválida.\n";
            }
            return; // Salir tras manejar el paciente
        }
    }

    std::cout << "Paciente con Nombre " << BuscarNombre << " no encontrado.\n";
}

void buscarPacienteFechaIngreso() {
    std::string BuscarFechaIngreso;
    std::cout << "FechaIngreso: ";
    std::cin >> BuscarFechaIngreso;

    for (size_t i = 0; i < pacientes.size(); i++) {
        if (pacientes[i].FechaIngreso == BuscarFechaIngreso) {
            std::cout << "Paciente " << i + 1 << ":\n";
            std::cout << "Nombre: " << pacientes[i].nombre << " " << pacientes[i].apellidos << "\n";
            std::cout << "DNI: " << pacientes[i].DNI << "\n";
            std::cout << "Sexo: " << pacientes[i].sexo << "\n";
            std::cout << "Edad: " << pacientes[i].edad << "\n";
            std::cout << "Fecha de Nacimiento: " << pacientes[i].FechaNacimiento << "\n";
            std::cout << "Fecha de Ingreso: " << pacientes[i].FechaIngreso << "\n";
            std::cout << "Fecha de Baja: " << pacientes[i].fechaBaja << "\n";

            int opcion;
            std::cout << "¿Qué acción desea realizar?\n";
            std::cout << "1. Modificar datos del paciente\n";
            std::cout << "2. Dar de baja al paciente\n";
            std::cout << "3. Cancelar\n";
            std::cout << "Elija una opción: ";
            std::cin >> opcion;

            switch (opcion) {
            case 1:
                modificarPaciente(pacientes[i]);
                break;
            case 2:
                BajaPaciente(i);
                break;
            case 3:
                std::cout << "Operación cancelada.\n";
                break;
            default:
                std::cout << "Opción inválida.\n";
            }
            return; // Salir tras manejar el paciente
        }
    }

    std::cout << "Paciente con Fecha de Ingreso de " << BuscarFechaIngreso << " no encontrado.\n";
}
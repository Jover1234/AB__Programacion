#include "paciente.h"
#include <iostream>

std::vector<Paciente> pacientes;



void altaPaciente() {
    std::string nombre, apellidos, DNI, sexo, FechaNacimiento, FechaIngreso, FechaBaja;
    int edad;

    std::cout << "Nombre: ";
    std::cin >> nombre;
    std::cout << "Apellidos: ";
    std::cin >> apellidos;
    std::cout << "DNI: ";
    std::cin >> DNI;
    std::cout << "Sexo: ";
    std::cin >> sexo;
    std::cout << "Edad: ";
    std::cin >> edad;
    std::cout << "Fecha de Nacimiento: ";
    std::cin >> FechaNacimiento;
    std::cout << "Fecha de Ingreso: ";
    std::cin >> FechaIngreso;
    std::cout << "Fecha de Baja: ";
    std::cin >> FechaBaja;

    Paciente nuevoPaciente(nombre, apellidos, DNI, sexo, edad, FechaNacimiento, FechaIngreso, FechaBaja);
    pacientes.push_back(nuevoPaciente);

    std::cout << "El paciente " << nombre << " " << apellidos << " con DNI: " << DNI
        << " se ha dado de alta correctamente.\n";
}

void mostrarPacientes() {
    if (pacientes.empty()) {
        std::cout << "No hay pacientes registrados.\n";
        return;
    }
    for (size_t i = 0; i < pacientes.size(); i++) {
        std::cout << "Paciente " << i + 1 << ":\n";
        std::cout << "Nombre: " << pacientes[i].nombre << " " << pacientes[i].apellidos << "\n";
        std::cout << "DNI: " << pacientes[i].DNI << "\n";
        std::cout << "Sexo: " << pacientes[i].sexo << "\n";
        std::cout << "Edad: " << pacientes[i].edad << "\n";
        std::cout << "Fecha de Nacimiento: " << pacientes[i].FechaNacimiento << "\n";
        std::cout << "Fecha de Ingreso: " << pacientes[i].FechaIngreso << "\n";
        std::cout << "Fecha de Baja: " << pacientes[i].fechaBaja << "\n";
    }
};

void modificarPaciente(Paciente& paciente) {
    std::cout << "Nombre: ";
    std::cin >> paciente.nombre;
    std::cout << "Apellidos: ";
    std::cin >> paciente.apellidos;
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

            std::string respuesta;
            std::cout << "¿Quieres modificar los datos de este paciente? (si/no): ";
            std::cin >> respuesta;

            if (respuesta == "si") {
                modificarPaciente(pacientes[i]);
            }
            return;
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

            std::string respuesta;
            std::cout << "¿Quieres modificar los datos de este paciente? (si/no): ";
            std::cin >> respuesta;

            if (respuesta == "si") {
                modificarPaciente(pacientes[i]);
            }
            return;
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

            std::string respuesta;
            std::cout << "¿Quieres modificar los datos de este paciente? (si/no): ";
            std::cin >> respuesta;

            if (respuesta == "si") {
                modificarPaciente(pacientes[i]);
            }
            return;
        }
    }
    std::cout << "Paciente con FechaIngreso " << BuscarFechaIngreso << " no encontrado.\n";
}

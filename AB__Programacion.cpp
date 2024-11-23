// AB__Programacion.cpp: define el punto de entrada de la aplicación.
//

#include "AB__Programacion.h"
#include <iostream>
#include <vector>

class Paciente {
public:
    std::string nombre;
    std::string apellidos;
    std::string DNI;
    std::string sexo;
    int edad;
    std::string FechaNacimiento;
    std::string FechaIngreso;
    std::string fechaBaja;

    // Constructor
    Paciente(std::string nombre, std::string apellidos, std::string DNI, std::string sexo, int edad,
        std::string FechaNacimiento, std::string FechaIngreso, std::string FechaBaja)
        : nombre(nombre), apellidos(apellidos), DNI(DNI), sexo(sexo), edad(edad),
        FechaNacimiento(FechaNacimiento), FechaIngreso(FechaIngreso), fechaBaja(FechaBaja) {
    }
};

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
}

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



class Medico {
public:
    std::string nombre;
    std::string apellidos;
    std::string DNI;
    std::string especialidad;
    std::string disponibilidad;

    Medico(std::string nombre, std::string apellidos, std::string DNI, std::string especialidad,
        std::string disponibilidad)
        : nombre(nombre), apellidos(apellidos), DNI(DNI), especialidad(especialidad), disponibilidad(disponibilidad) {
    }
};

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

int main() {
    int opcion;
    do {
        std::cout << "\n¿Qué quieres hacer?\n";
        std::cout << "1. Gestionar Pacientes\n";
        std::cout << "2. Gestionar Médicos\n";
        std::cout << "3. Salir\n";
        std::cout << "Elige una opción: ";
        std::cin >> opcion;

        switch (opcion) {
        case 1: {
            int opcionPaciente;
            do {
                std::cout << "\n--- Gestión de Pacientes ---\n";
                std::cout << "1. Dar de alta un paciente\n";
                std::cout << "2. Mostrar pacientes\n";
                std::cout << "3. Buscar paciente por DNI\n";
                std::cout << "4. Volver al menú principal\n";
                std::cout << "Elige una opción: ";
                std::cin >> opcionPaciente;

                switch (opcionPaciente) {
                case 1:
                    altaPaciente();
                    break;
                case 2:
                    mostrarPacientes();
                    break;
                case 3:
                    int opcionBusqueda;
                    std::cout << "\n¿Qué tipo de búsqueda deseas realizar?\n";
                    std::cout << "1. Buscar por DNI\n";
                    std::cout << "2. Buscar por nombre\n";
                    std::cout << "3. Buscar por fecha de ingreso\n";
                    std::cout << "Elige una opción: ";
                    std::cin >> opcionBusqueda;

                    switch (opcionBusqueda) {
                    case 1:
                        buscarPacienteDNI();
                        break;
                    case 2:
                        buscarPacienteNombre();
                        break;
                    case 3:
                        buscarPacienteFechaIngreso();
                        break;
                    default:
                        std::cout << "Opción no válida.\n";
                    }
                    break;
                case 4:
                    std::cout << "Volviendo al menú principal...\n";
                    break;
                default:
                    std::cout << "Opción no válida.\n";
                }
            } while (opcionPaciente != 4);
            break;
        }
        case 2: {
            int opcionMedico;
            do {
                std::cout << "\n--- Gestión de Médicos ---\n";
                std::cout << "1. Dar de alta un médico\n";
                std::cout << "2. Mostrar médicos\n";
                std::cout << "3. Volver al menú principal\n";
                std::cout << "Elige una opción: ";
                std::cin >> opcionMedico;

                switch (opcionMedico) {
                case 1:
                    altaMedico();
                    break;
                case 2:
                    mostrarMedicos();
                    break;
                case 3:
                    std::cout << "Volviendo al menú principal...\n";
                    break;
                default:
                    std::cout << "Opción no válida.\n";
                }
            } while (opcionMedico != 3);
            break;
        }
        case 3:
            std::cout << "Saliendo del programa...\n";
            break;
        default:
            std::cout << "Opción no válida.\n";
        }
    } while (opcion != 3);

    return 0;
}


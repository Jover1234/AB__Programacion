#include "SistemaHospital.h"
#include <algorithm>

void SistemaHospital::altaPaciente() {
    std::string nombre, apellidos, dni;
    std::cout << "Nombre: ";
    std::cin >> nombre;
    std::cout << "Apellidos: ";
    std::cin >> apellidos;
    std::cout << "DNI: ";
    std::cin >> dni;
    pacientes.push_back(Paciente(nombre, apellidos, dni));
    std::cout << "Paciente dado de alta.\n";
}

void SistemaHospital::bajaPaciente() {
    std::string dni;
    std::cout << "DNI del paciente a dar de baja: ";
    std::cin >> dni;
    auto it = std::find_if(pacientes.begin(), pacientes.end(),
        [dni](const Paciente& p) { return p.dni == dni; });
    if (it != pacientes.end()) {
        time_t now = time(0);
        it->fechaBaja = ctime(&now);
        it->historialClinico.push_back("Baja: " + it->fechaBaja);
        pacientes.erase(it);
        std::cout << "Paciente dado de baja.\n";
    }
    else {
        std::cout << "Paciente no encontrado.\n";
    }
}




void mostrarPacientes() {
    std::ifstream archivo("pacientes.txt");
    if (!archivo.is_open()) {
        std::cout << "No se pudo abrir el archivo o no hay pacientes registrados.\n";
        return;
    }

    std::string linea;
    size_t contador = 0;

    while (std::getline(archivo, linea)) {
        contador++;
        std::istringstream stream(linea);
        std::string nombre, apellidos, DNI, sexo, FechaNacimiento, FechaIngreso, FechaBaja;
        int edad;

        std::getline(stream, nombre, '|');
        std::getline(stream, apellidos, '|');
        std::getline(stream, DNI, '|');
        std::getline(stream, sexo, '|');
        stream >> edad;
        stream.ignore(); // Ignorar el delimitador '|'
        std::getline(stream, FechaNacimiento, '|');
        std::getline(stream, FechaIngreso, '|');
        std::getline(stream, FechaBaja, '|');

        std::cout << "Paciente " << contador << ":\n";
        std::cout << "Nombre: " << nombre << " " << apellidos << "\n";
        std::cout << "DNI: " << DNI << "\n";
        std::cout << "Sexo: " << sexo << "\n";
        std::cout << "Edad: " << edad << "\n";
        std::cout << "Fecha de Nacimiento: " << FechaNacimiento << "\n";
        std::cout << "Fecha de Ingreso: " << FechaIngreso << "\n";
        std::cout << "Fecha de Baja: " << FechaBaja << "\n";
        std::cout << "-------------------------\n";
    }

    archivo.close();
}


void SistemaHospital::modificarPaciente() {
    std::string dni;
    std::cout << "DNI del paciente a modificar: ";
    std::cin >> dni;
    auto it = std::find_if(pacientes.begin(), pacientes.end(),
        [dni](const Paciente& p) { return p.dni == dni; });
    if (it != pacientes.end()) {
        std::cout << "Nuevo nombre (deje en blanco para no cambiar): ";
        std::string nombre;
        std::cin.ignore();
        std::getline(std::cin, nombre);
        if (!nombre.empty()) it->nombre = nombre;

        std::cout << "Nuevos apellidos (deje en blanco para no cambiar): ";
        std::string apellidos;
        std::getline(std::cin, apellidos);
        if (!apellidos.empty()) it->apellidos = apellidos;

        std::cout << "Paciente modificado.\n";
    }
    else {
        std::cout << "Paciente no encontrado.\n";
    }
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

#include "medico.h"
#include <iostream>

std::vector<Medico> medicos;


void SistemaHospital::altaMedico() {
    std::string nombre, apellidos, dni, especialidad;
    std::cout << "Nombre: ";
    std::cin >> nombre;
    std::cout << "Apellidos: ";
    std::cin >> apellidos;
    std::cout << "DNI: ";
    std::cin >> dni;
    std::cout << "Especialidad: ";
    std::cin >> especialidad;
    medicos.push_back(Medico(nombre, apellidos, dni, especialidad));
    std::cout << "Médico dado de alta.\n";
}

void SistemaHospital::bajaMedico() {
    std::string dni;
    std::cout << "DNI del médico a dar de baja: ";
    std::cin >> dni;
    auto it = std::find_if(medicos.begin(), medicos.end(),
        [dni](const Medico& m) { return m.dni == dni; });
    if (it != medicos.end()) {
        medicos.erase(it);
        std::cout << "Médico dado de baja.\n";
    }
    else {
        std::cout << "Médico no encontrado.\n";
    }
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

void  modificarMedico(Medico& medico) {
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


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

    //Construcor
public:
    Paciente(std::string nombre, std::string apellidos, std::string DNI, std::string sexo, int edad,
    std::string FechaNacimiento, std::string FechaIngreso, std::string FechaBaja) : nombre(nombre),
    apellidos(apellidos), DNI(DNI), sexo(sexo), edad(edad), FechaNacimiento(FechaNacimiento),
    FechaIngreso(FechaIngreso), fechaBaja(FechaBaja) {};


};

std::vector<Paciente> pacientes;
void altaPaciente() {
    //declaracion de variable en la funcion
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

    // Crear un constructor de la clase Paciente
    Paciente nuevoPaciente(nombre, apellidos, DNI, sexo, edad, FechaNacimiento, FechaIngreso,
        FechaBaja);

    // Agregar el paciente al vector
    pacientes.push_back(nuevoPaciente);

    std::cout << "el Paciente " << nombre << " " << apellidos << " con DNI: " << DNI << " se ha dado de alta correctamente\n";
}

void MostarPacientes() {
    std::cout << "\nPacientes: \n";
    for (int i = 0; i < pacientes.size(); i++) {
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


void BuscarPacientesDNI() {
    std::string BuscarDNI;
    std::cout << "DNI : ";
    std::cin >> BuscarDNI;
    for (int i = 0; i < pacientes.size(); i++) {
        if (pacientes[i].DNI == BuscarDNI) {
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
};

void BuscarPacientesNombre() {
    std::string BuscarNombre;
    std::cout << "Nombre : ";
    std::cin >> BuscarNombre;
    for (int i = 0; i < pacientes.size(); i++) {
        if (pacientes[i].nombre == BuscarNombre) {
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
};

void BuscarPacientesFechaIngreso() {
    std::string BuscarFechaIngreso;
    std::cout << "FechaIngreso : ";
    std::cin >> BuscarFechaIngreso;
    for (int i = 0; i < pacientes.size(); i++) {
        if (pacientes[i].FechaIngreso == BuscarFechaIngreso) {
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
};

class Medico {
public:
    std::string nombre;
    std::string apellidos;
    std::string DNI;
    std::string especialidad;
    std::string disponibilidad;

    // Constructor
    Medico(std::string nombre, std::string apellidos, std::string DNI, std::string especialidad, std::string disponibilidad)
        : nombre(nombre), apellidos(apellidos), DNI(DNI), especialidad(especialidad), disponibilidad(disponibilidad) {
    }
};

// Vector para almacenar los médicos
std::vector<Medico> medicos;

// Función para dar de alta a un médico
void altaMedico() {
    std::string nombre, apellidos, DNI, especialidad,disponibilidad;


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


    // Crear un nuevo médico
    Medico nuevoMedico(nombre, apellidos, DNI, especialidad, disponibilidad);

    // Agregar el médico al vector
    medicos.push_back(nuevoMedico);

    std::cout << "El médico " << nombre << " " << apellidos << " con DNI: " << DNI << " ha sido dado de alta correctamente.\n";
}

void MostrarMedicos() {
    std::cout << "\nMédicos: \n";
    for (size_t i = 0; i < medicos.size(); i++) {
        std::cout << "Médico " << i + 1 << ":\n";
        std::cout << "Nombre: " << medicos[i].nombre << " " << medicos[i].apellidos << "\n";
        std::cout << "DNI: " << medicos[i].DNI << "\n";
        std::cout << "Especialidad: " << medicos[i].especialidad << "\n";
        std::cout << "Disponibilidad: " << medicos[i].disponibilidad << "\n";
    };
};
int main() {
    std::string respuesta;
    do {
        altaPaciente();
        std::cout << "¿Quieres añadir otro paciente? (si/no): ";
        std::cin >> respuesta;
        while (respuesta != "si" && respuesta != "no") {
            std::cout << "Por favor, responde con 'si' o 'no': ";
            std::cin >> respuesta;
        }
    } while (respuesta == "si");

    std::cout << "Has decidido no agregar más pacientes.\n";
    MostarPacientes();
    BuscarPacientesDNI();
    BuscarPacientesNombre();
    BuscarPacientesFechaIngreso();
    do {
        altaMedico();
        std::cout << "¿Quieres añadir otro medico? (si/no): ";
        std::cin >> respuesta;
        while (respuesta != "si" && respuesta != "no") {
            std::cout << "Por favor, responde con 'si' o 'no': ";
            std::cin >> respuesta;
        }
    } while (respuesta == "si");

    std::cout << "Has decidido no agregar más medicos.\n";
    MostrarMedicos();
    return 0;
};

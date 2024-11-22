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


int main() {
    altaPaciente();
    return 0;
};

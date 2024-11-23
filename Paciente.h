#ifndef PACIENTE_H
#define PACIENTE_H

#include <string>
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

    Paciente(std::string nombre, std::string apellidos, std::string DNI, std::string sexo, int edad,
        std::string FechaNacimiento, std::string FechaIngreso, std::string FechaBaja)
        : nombre(nombre), apellidos(apellidos), DNI(DNI), sexo(sexo), edad(edad),
        FechaNacimiento(FechaNacimiento), FechaIngreso(FechaIngreso), fechaBaja(FechaBaja) {
    }
};

void altaPaciente();
void mostrarPacientes();
void buscarPacienteDNI();
void buscarPacienteNombre();
void buscarPacienteFechaIngreso();

#endif // PACIENTE_H

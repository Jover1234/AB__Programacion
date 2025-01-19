#include <iostream>
#include "paciente.h"
#include "medico.h"
#include <wchar.h>

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
                std::cout << "3. Buscar paciente \n";
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
                std::cout << "3. Buscar medico\n";
                std::cout << "4. Volver al menú principal\n";
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
                    buscarMedicoDNI();
                case 4:
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

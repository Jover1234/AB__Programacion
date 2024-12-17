#include <iostream>
#include "paciente.h"
#include "medico.h"

int main() {
    cargarPacientes(); // Cargar los pacientes desde el archivo

    int opcion;
    do {
        std::cout << "\n?Qu? quieres hacer?\n";
        std::cout << "1. Gestionar Pacientes\n";
        std::cout << "2. Gestionar M?dicos\n";
        std::cout << "3. Salir\n";
        std::cout << "Elige una opci?n: ";
        std::cin >> opcion;

        switch (opcion) {
        case 1: {
            int opcionPaciente;
            do {
                std::cout << "\n--- Gesti?n de Pacientes ---\n";
                std::cout << "1. Dar de alta un paciente\n";
                std::cout << "2. Mostrar pacientes\n";
                std::cout << "3. Buscar paciente \n";
                std::cout << "4. Volver al men? principal\n";
                std::cout << "Elige una opci?n: ";
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
                    std::cout << "\n?Qu? tipo de b?squeda deseas realizar?\n";
                    std::cout << "1. Buscar por DNI\n";
                    std::cout << "2. Buscar por nombre\n";
                    std::cout << "3. Buscar por fecha de ingreso\n";
                    std::cout << "Elige una opci?n: ";
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
                        std::cout << "Opci?n no v?lida.\n";
                    }
                    break;
                case 4:
                    std::cout << "Volviendo al men? principal...\n";
                    break;
                default:
                    std::cout << "Opci?n no v?lida.\n";
                }
            } while (opcionPaciente != 4);
            break;
        }
        case 2: {
            int opcionMedico;
            do {
                std::cout << "\n--- Gesti?n de M?dicos ---\n";
                std::cout << "1. Dar de alta un m?dico\n";
                std::cout << "2. Mostrar m?dicos\n";
                std::cout << "3. Buscar medico\n";
                std::cout << "4. Volver al men? principal\n";
                std::cout << "Elige una opci?n: ";
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
                    break;
                case 4:
                    std::cout << "Volviendo al men? principal...\n";
                    break;
                default:
                    std::cout << "Opci?n no v?lida.\n";
                }
            } while (opcionMedico != 4);
            break;
        }
        case 3:
            std::cout << "Saliendo del programa...\n";
            break;
        default:
            std::cout << "Opci?n no v?lida.\n";
        }
    } while (opcion != 3);

    return 0;
};
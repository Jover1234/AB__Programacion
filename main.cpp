#include "SistemaHospital.h"
#include <locale>

int main() {
    setlocale(LC_ALL, ""); // Configura la localizaci�n seg�n el entorno del sistema
    SistemaHospital sistema;
    sistema.cargarDatos("hospital_data.txt");

    int opcion;
    do {
        std::cout << "\n--- Sistema de Gesti�n Hospitalaria ---\n";
        std::cout << "1. Gesti�n de Pacientes\n";
        std::cout << "2. Gesti�n de M�dicos\n";
        std::cout << "3. Gesti�n de Citas\n";
        std::cout << "4. Generaci�n de Reportes\n";
        std::cout << "5. Manejo de Archivos\n";
        std::cout << "0. Salir\n";
        std::cout << "Seleccione una opci�n: ";
        std::cin >> opcion;

        switch (opcion) {
        case 1:
            // Men� de Gesti�n de Pacientes
            int opcionPacientes;
            do {
                std::cout << "\n--- Gesti�n de Pacientes ---\n";
                std::cout << "1. Alta de paciente\n";
                std::cout << "2. Baja de paciente\n";
                std::cout << "3. Modificar datos de paciente\n";
                std::cout << "4. Buscar paciente\n";
                std::cout << "5. Modificar historial cl�nico\n";
                std::cout << "0. Volver al men� principal\n";
                std::cout << "Seleccione una opci�n: ";
                std::cin >> opcionPacientes;

                switch (opcionPacientes) {
                case 1: sistema.altaPaciente(); break;
                case 2: sistema.bajaPaciente(); break;
                case 3: sistema.modificarPaciente(); break;
                case 4: sistema.buscarPaciente(); break;
                case 5: sistema.modificarHistorialClinico(); break;
                }
            } while (opcionPacientes != 0);
            break;

        case 2:
            // Men� de Gesti�n de M�dicos
            int opcionMedicos;
            do {
                std::cout << "\n--- Gesti�n de M�dicos ---\n";
                std::cout << "1. Alta de m�dico\n";
                std::cout << "2. Baja de m�dico\n";
                std::cout << "3. Modificar especialidad\n";
                std::cout << "4. Cambiar disponibilidad\n";
                std::cout << "5. Listar m�dicos por especialidad\n";
                std::cout << "6. Listar m�dicos por disponibilidad\n";
                std::cout << "0. Volver al men� principal\n";
                std::cout << "Seleccione una opci�n: ";
                std::cin >> opcionMedicos;

                switch (opcionMedicos) {
                case 1: sistema.altaMedico(); break;
                case 2: sistema.bajaMedico(); break;
                case 3: sistema.modificarEspecialidad(); break;
                case 4: sistema.cambiarDisponibilidad(); break;
                case 5: sistema.listarMedicosPorEspecialidad(); break;
                case 6: sistema.listarMedicosPorDisponibilidad(); break;
                }
            } while (opcionMedicos != 0);
            break;

        case 3:
            // Men� de Gesti�n de Citas
            int opcionCitas;
            do {
                std::cout << "\n--- Gesti�n de Citas ---\n";
                std::cout << "1. Asignar cita\n";
                std::cout << "2. Cancelar cita\n";
                std::cout << "3. Modificar cita\n";
                std::cout << "4. Listar citas por fecha\n";
                std::cout << "5. Listar citas por urgencia\n";
                std::cout << "0. Volver al men� principal\n";
                std::cout << "Seleccione una opci�n: ";
                std::cin >> opcionCitas;

                switch (opcionCitas) {
                case 1: sistema.asignarCita(); break;
                case 2: sistema.cancelarCita(); break;
                case 3: sistema.modificarCita(); break;
                case 4: sistema.listarCitasPorFecha(); break;
                case 5: sistema.listarCitasPorUrgencia(); break;
                }
            } while (opcionCitas != 0);
            break;

        case 4:
            // Men� de Generaci�n de Reportes
            int opcionReportes;
            do {
                std::cout << "\n--- Generaci�n de Reportes ---\n";
                std::cout << "1. Reporte de pacientes atendidos\n";
                std::cout << "2. Reporte de citas pendientes por m�dico\n";
                std::cout << "3. Reporte de citas pendientes por especialidad\n";
                std::cout << "4. Reporte de pacientes con enfermedades cr�nicas\n";
                std::cout << "0. Volver al men� principal\n";
                std::cout << "Seleccione una opci�n: ";
                std::cin >> opcionReportes;

                switch (opcionReportes) {
                case 1: sistema.reportePacientesAtendidos(); break;
                case 2: sistema.reporteCitasPendientesMedico(); break;
                case 3: sistema.reporteCitasPendientesEspecialidad(); break;
                case 4: sistema.reportePacientesEnfermedadesCronicas(); break;
                }
            } while (opcionReportes != 0);
            break;

        case 5:
            // Men� de Manejo de Archivos
            int opcionArchivos;
            do {
                std::cout << "\n--- Manejo de Archivos ---\n";
                std::cout << "1. Guardar datos\n";
                std::cout << "2. Cargar datos\n";
                std::cout << "3. Hacer backup\n";
                std::cout << "0. Volver al men� principal\n";
                std::cout << "Seleccione una opci�n: ";
                std::cin >> opcionArchivos;

                switch (opcionArchivos) {
                case 1: sistema.guardarDatos("hospital_data.txt"); break;
                case 2: sistema.cargarDatos("hospital_data.txt"); break;
                case 3: sistema.hacerBackup("hospital_data.txt"); break;
                }
            } while (opcionArchivos != 0);
            break;
        }
    } while (opcion != 0);

    sistema.guardarDatos("hospital_data.txt");
    return 0;
}

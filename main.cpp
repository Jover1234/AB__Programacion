#include "SistemaHospital.h"
#include <locale>

int main() {
    setlocale(LC_ALL, ""); // Configura la localización según el entorno del sistema
    SistemaHospital sistema;
    sistema.cargarDatos("hospital_data.txt");

    int opcion;
    do {
        std::cout << "\n--- Sistema de Gestión Hospitalaria ---\n";
        std::cout << "1. Gestión de Pacientes\n";
        std::cout << "2. Gestión de Médicos\n";
        std::cout << "3. Gestión de Citas\n";
        std::cout << "4. Generación de Reportes\n";
        std::cout << "5. Manejo de Archivos\n";
        std::cout << "0. Salir\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        switch (opcion) {
        case 1:
            // Menú de Gestión de Pacientes
            int opcionPacientes;
            do {
                std::cout << "\n--- Gestión de Pacientes ---\n";
                std::cout << "1. Alta de paciente\n";
                std::cout << "2. Baja de paciente\n";
                std::cout << "3. Modificar datos de paciente\n";
                std::cout << "4. Buscar paciente\n";
                std::cout << "5. Modificar historial clínico\n";
                std::cout << "0. Volver al menú principal\n";
                std::cout << "Seleccione una opción: ";
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
            // Menú de Gestión de Médicos
            int opcionMedicos;
            do {
                std::cout << "\n--- Gestión de Médicos ---\n";
                std::cout << "1. Alta de médico\n";
                std::cout << "2. Baja de médico\n";
                std::cout << "3. Modificar especialidad\n";
                std::cout << "4. Cambiar disponibilidad\n";
                std::cout << "5. Listar médicos por especialidad\n";
                std::cout << "6. Listar médicos por disponibilidad\n";
                std::cout << "0. Volver al menú principal\n";
                std::cout << "Seleccione una opción: ";
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
            // Menú de Gestión de Citas
            int opcionCitas;
            do {
                std::cout << "\n--- Gestión de Citas ---\n";
                std::cout << "1. Asignar cita\n";
                std::cout << "2. Cancelar cita\n";
                std::cout << "3. Modificar cita\n";
                std::cout << "4. Listar citas por fecha\n";
                std::cout << "5. Listar citas por urgencia\n";
                std::cout << "0. Volver al menú principal\n";
                std::cout << "Seleccione una opción: ";
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
            // Menú de Generación de Reportes
            int opcionReportes;
            do {
                std::cout << "\n--- Generación de Reportes ---\n";
                std::cout << "1. Reporte de pacientes atendidos\n";
                std::cout << "2. Reporte de citas pendientes por médico\n";
                std::cout << "3. Reporte de citas pendientes por especialidad\n";
                std::cout << "4. Reporte de pacientes con enfermedades crónicas\n";
                std::cout << "0. Volver al menú principal\n";
                std::cout << "Seleccione una opción: ";
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
            // Menú de Manejo de Archivos
            int opcionArchivos;
            do {
                std::cout << "\n--- Manejo de Archivos ---\n";
                std::cout << "1. Guardar datos\n";
                std::cout << "2. Cargar datos\n";
                std::cout << "3. Hacer backup\n";
                std::cout << "0. Volver al menú principal\n";
                std::cout << "Seleccione una opción: ";
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

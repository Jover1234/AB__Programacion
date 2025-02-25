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

void SistemaHospital::buscarPaciente() {
	std::string criterio;
	std::cout << "Buscar por (nombre/dni/fecha): ";
	std::cin >> criterio;
	std::string valor;
	std::cout << "Valor a buscar: ";
	std::cin.ignore(); // Ignorar el salto de l�nea anterior
	std::getline(std::cin, valor); // Usar getline para permitir espacios

	for (const auto& p : pacientes) {
		if ((criterio == "nombre" && p.nombre == valor) ||
			(criterio == "dni" && p.dni == valor) ||
			(criterio == "fecha" && p.fechaIngreso == valor)) { // Comparaci�n exacta
			std::cout << "Paciente encontrado: " << p.nombre << " " << p.apellidos << " (DNI: " << p.dni << ")\n";
		}
	}
}




void SistemaHospital::modificarHistorialClinico() {
	std::string dni;
	std::cout << "DNI del paciente: ";
	std::cin >> dni;
	auto it = std::find_if(pacientes.begin(), pacientes.end(),
		[dni](const Paciente& p) { return p.dni == dni; });
	if (it != pacientes.end()) {
		std::string entrada;
		std::cout << "Nueva entrada para el historial cl�nico: ";
		std::cin.ignore();
		std::getline(std::cin, entrada);
		it->historialClinico.push_back(entrada);

		// A�adir opci�n para registrar enfermedad cr�nica
		char respuesta;
		std::cout << "�Tiene enfermedad cr�nica? (S/N): ";
		std::cin >> respuesta;

		if (respuesta == 'S' || respuesta == 's') {
			it->tieneEnfermedadCronica = true;
			std::cout << "Ingrese el nombre de la enfermedad cr�nica: ";
			std::cin.ignore();
			std::getline(std::cin, it->enfermedadCronica);
		}
		else {
			it->tieneEnfermedadCronica = false;
			it->enfermedadCronica = "";
		}

		std::cout << "Historial cl�nico actualizado.\n";
	}
	else {
		std::cout << "Paciente no encontrado.\n";
	}
}


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
	std::cout << "M�dico dado de alta.\n";
}

void SistemaHospital::bajaMedico() {
	std::string dni;
	std::cout << "DNI del m�dico a dar de baja: ";
	std::cin >> dni;
	auto it = std::find_if(medicos.begin(), medicos.end(),
		[dni](const Medico& m) { return m.dni == dni; });
	if (it != medicos.end()) {
		medicos.erase(it);
		std::cout << "M�dico dado de baja.\n";
	}
	else {
		std::cout << "M�dico no encontrado.\n";
	}
}

void SistemaHospital::modificarEspecialidad() {
	std::string dni;
	std::cout << "DNI del m�dico: ";
	std::cin >> dni;
	auto it = std::find_if(medicos.begin(), medicos.end(),
		[dni](const Medico& m) { return m.dni == dni; });
	if (it != medicos.end()) {
		std::cout << "Nueva especialidad: ";
		std::cin >> it->especialidad;
		std::cout << "Especialidad actualizada.\n";
	}
	else {
		std::cout << "M�dico no encontrado.\n";
	}
}

void SistemaHospital::cambiarDisponibilidad() {
	std::string dni;
	std::cout << "DNI del m�dico: ";
	std::cin >> dni;
	auto it = std::find_if(medicos.begin(), medicos.end(),
		[dni](const Medico& m) { return m.dni == dni; });
	if (it != medicos.end()) {
		it->disponible = !it->disponible;
		std::cout << "Disponibilidad actualizada a: " << (it->disponible ? "Disponible" : "No disponible") << "\n";
	}
	else {
		std::cout << "M�dico no encontrado.\n";
	}
}

void SistemaHospital::listarMedicosPorEspecialidad() {
	std::string especialidad;
	std::cout << "Especialidad: ";
	std::cin >> especialidad;
	for (const auto& m : medicos) {
		if (m.especialidad == especialidad) {
			std::cout << m.nombre << " " << m.apellidos << " (DNI: " << m.dni << ")\n";
		}
	}
}

void SistemaHospital::listarMedicosPorDisponibilidad() {
	bool disponible;
	std::cout << "Disponibilidad (1 para disponible, 0 para no disponible): ";
	std::cin >> disponible;
	for (const auto& m : medicos) {
		if (m.disponible == disponible) {
			std::cout << m.nombre << " " << m.apellidos << " (DNI: " << m.dni << ")\n";
		}
	}
}

void SistemaHospital::asignarCita() {
	std::string dniPaciente, dniMedico, fecha;
	bool urgente;
	std::cout << "DNI del paciente: ";
	std::cin >> dniPaciente;
	std::cout << "DNI del m�dico: ";
	std::cin >> dniMedico;
	std::cout << "Fecha (DD/MM/YYYY): ";
	std::cin >> fecha;
	std::cout << "Urgente (1 para s�, 0 para no): ";
	std::cin >> urgente;
	citas.push_back(Cita(dniPaciente, dniMedico, fecha, urgente));
	std::cout << "Cita asignada.\n";
}

void SistemaHospital::cancelarCita() {
	std::string dniPaciente, fecha;
	std::cout << "DNI del paciente: ";
	std::cin >> dniPaciente;
	std::cout << "Fecha de la cita (DD/MM/YYYY): ";
	std::cin >> fecha;
	auto it = std::find_if(citas.begin(), citas.end(),
		[dniPaciente, fecha](const Cita& c) { return c.dniPaciente == dniPaciente && c.fecha == fecha; });
	if (it != citas.end()) {
		citas.erase(it);
		std::cout << "Cita cancelada.\n";
	}
	else {
		std::cout << "Cita no encontrada.\n";
	}
}

void SistemaHospital::modificarCita() {
	std::string dniPaciente, fecha;
	std::cout << "DNI del paciente: ";
	std::cin >> dniPaciente;
	std::cout << "Fecha de la cita (DD/MM/YYYY): ";
	std::cin >> fecha;
	auto it = std::find_if(citas.begin(), citas.end(),
		[dniPaciente, fecha](const Cita& c) { return c.dniPaciente == dniPaciente && c.fecha == fecha; });
	if (it != citas.end()) {
		std::cout << "Nueva fecha (DD/MM/YYYY): ";
		std::cin >> it->fecha;
		std::cout << "Urgente (1 para s�, 0 para no): ";
		std::cin >> it->urgente;
		std::cout << "Cita modificada.\n";
	}
	else {
		std::cout << "Cita no encontrada.\n";
	}
}

void SistemaHospital::listarCitasPorFecha() {
	std::string fecha;
	std::cout << "Fecha (DD/MM/YYYY): ";
	std::cin >> fecha;
	for (const auto& c : citas) {
		if (c.fecha >= fecha) {
			std::cout << "Paciente: " << c.dniPaciente << ", M�dico: " << c.dniMedico
				<< ", Fecha: " << c.fecha << ", Urgente: " << (c.urgente ? "S�" : "No") << "\n";
		}
	}
}

void SistemaHospital::listarCitasPorUrgencia() {
	bool urgente;
	std::cout << "Urgente (1 para s�, 0 para no): ";
	std::cin >> urgente;
	for (const auto& c : citas) {
		if (c.urgente == urgente) {
			std::cout << "Paciente: " << c.dniPaciente << ", M�dico: " << c.dniMedico
				<< ", Fecha: " << c.fecha << "\n";
		}
	}
}

void SistemaHospital::reportePacientesAtendidos() {
	std::string fechaInicio, fechaFin;
	std::cout << "Fecha de inicio (DD/MM/YYYY): ";
	std::cin >> fechaInicio;
	std::cout << "Fecha de fin (DD/MM/YYYY): ";
	std::cin >> fechaFin;
	for (const auto& c : citas) {
		if (c.fecha >= fechaInicio && c.fecha <= fechaFin) {
			std::cout << "Paciente: " << c.dniPaciente << ", M�dico: " << c.dniMedico
				<< ", Fecha: " << c.fecha << "\n";
		}
	}
}

void SistemaHospital::reporteCitasPendientesMedico() {
	std::string dniMedico, fecha;
	std::cout << "DNI del m�dico: ";
	std::cin >> dniMedico;
	std::cout << "Fecha actual (DD/MM/YYYY): ";
	std::cin >> fecha;
	for (const auto& c : citas) {
		if (c.dniMedico == dniMedico && c.fecha >= fecha) {
			std::cout << "Paciente: " << c.dniPaciente << ", Fecha: " << c.fecha
				<< ", Urgente: " << (c.urgente ? "S�" : "No") << "\n";
		}
	}
}

void SistemaHospital::reporteCitasPendientesEspecialidad() {
	std::string especialidad, fecha;
	std::cout << "Especialidad: ";
	std::cin >> especialidad;
	std::cout << "Fecha actual (DD/MM/YYYY): ";
	std::cin >> fecha;
	for (const auto& c : citas) {
		auto medico = std::find_if(medicos.begin(), medicos.end(),
			[&c](const Medico& m) { return m.dni == c.dniMedico; });
		if (medico != medicos.end() && medico->especialidad == especialidad && c.fecha >= fecha) {
			std::cout << "Paciente: " << c.dniPaciente << ", M�dico: " << c.dniMedico
				<< ", Fecha: " << c.fecha << ", Urgente: " << (c.urgente ? "S�" : "No") << "\n";
		}
	}
}

void SistemaHospital::reportePacientesEnfermedadesCronicas() {
	std::cout << "--- Reporte de Pacientes con Enfermedades Cr�nicas ---\n";
	for (const auto& p : pacientes) {
		if (p.tieneEnfermedadCronica) {
			std::cout << "Paciente: " << p.nombre << " " << p.apellidos
				<< " (DNI: " << p.dni << ")\n"
				<< "Enfermedad Cr�nica: " << p.enfermedadCronica << "\n\n";
		}
		else {
			std::cout << "Paciente: " << p.nombre << " " << p.apellidos
				<< " (DNI: " << p.dni << ")\n"
				<< "No tiene enfermedad cr�nica\n\n";
		}
	}
}

void SistemaHospital::guardarDatos(const std::string& archivo) {
	std::ofstream file(archivo);
	if (file.is_open()) {
		for (const auto& p : pacientes) {
			file << "P," << p.nombre << "," << p.apellidos << "," << p.dni << "," << p.fechaIngreso;
			for (const auto& h : p.historialClinico) {
				file << "," << h;
			}
			file << "\n";
		}
		for (const auto& m : medicos) {
			file << "M," << m.nombre << "," << m.apellidos << "," << m.dni << "," << m.especialidad << "," << m.disponible << "\n";
		}
		for (const auto& c : citas) {
			file << "C," << c.dniPaciente << "," << c.dniMedico << "," << c.fecha << "," << c.urgente << "\n";
		}
		file.close();
		std::cout << "Datos guardados correctamente.\n";
	}
	else {
		std::cout << "No se pudo abrir el archivo para guardar.\n";
	}
}

void SistemaHospital::cargarDatos(const std::string& archivo) {
	std::ifstream file(archivo);
	if (file.is_open()) {
		std::string line;
		while (std::getline(file, line)) {
			std::istringstream iss(line);
			std::string tipo;
			std::getline(iss, tipo, ',');
			if (tipo == "P") {
				std::string nombre, apellidos, dni, fechaIngreso;
				std::getline(iss, nombre, ',');
				std::getline(iss, apellidos, ',');
				std::getline(iss, dni, ',');
				std::getline(iss, fechaIngreso, ',');
				Paciente p(nombre, apellidos, dni);
				p.fechaIngreso = fechaIngreso;
				std::string entrada;
				while (std::getline(iss, entrada, ',')) {
					p.historialClinico.push_back(entrada);
				}
				pacientes.push_back(p);
			}
			else if (tipo == "M") {
				std::string nombre, apellidos, dni, especialidad;
				bool disponible;
				std::getline(iss, nombre, ',');
				std::getline(iss, apellidos, ',');
				std::getline(iss, dni, ',');
				std::getline(iss, especialidad, ',');
				iss >> disponible;
				Medico m(nombre, apellidos, dni, especialidad);
				m.disponible = disponible;
				medicos.push_back(m);
			}
			else if (tipo == "C") {
				std::string dniPaciente, dniMedico, fecha;
				bool urgente;
				std::getline(iss, dniPaciente, ',');
				std::getline(iss, dniMedico, ',');
				std::getline(iss, fecha, ',');
				iss >> urgente;
				citas.push_back(Cita(dniPaciente, dniMedico, fecha, urgente));
			}
		}
		file.close();
		std::cout << "Datos cargados correctamente.\n";
	}
	else {
		std::cout << "No se pudo abrir el archivo para cargar.\n";
	}
}

void SistemaHospital::hacerBackup(const std::string& archivo) {
	std::string backupFile = archivo + ".bak";
	std::ifstream src(archivo, std::ios::binary);
	std::ofstream dst(backupFile, std::ios::binary);
	dst << src.rdbuf();
	std::cout << "Backup realizado correctamente.\n";
};



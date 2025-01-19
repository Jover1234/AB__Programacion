#include "Medico.h"

Medico::Medico(std::string n, std::string a, std::string d, std::string e)
    : nombre(n), apellidos(a), dni(d), especialidad(e), disponible(true) {
}

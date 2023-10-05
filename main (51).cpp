#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <ctime>
#include <limits> // Necesario para std::numeric_limits

struct Nota {
    int id;
    std::string mensaje;
    int fechadias;
    int fechameses;
    int fechaanios;
    int horap;
    int horaenMinutos;
};

class AgendaNotas {
private:
    std::vector<Nota> notas;
    int idCounter = 1;

public:
    void programarNota() {
        Nota nuevaNota;
        std::cin.ignore();

        nuevaNota.id = idCounter++;
        std::cout << "Escribe tu nota: ";
        std::getline(std::cin, nuevaNota.mensaje);

        nuevaNota.fechadias = pedirNumeroValido("Fecha (en días 1-31): ", 1, 31);
        nuevaNota.fechameses = pedirNumeroValido("Mes (en meses de 1-12): ", 1, 12);
        nuevaNota.fechaanios = pedirNumeroValido("Año (<2023): ", 2023, 4000); // Cambiar el rango si es necesario
        nuevaNota.horap = pedirNumeroValido("Hora (formato de 24 horas): ", 0, 23);
        nuevaNota.horaenMinutos = pedirNumeroValido("Minutos (0-59): ", 0, 59);

        notas.push_back(nuevaNota);
        std::cout << "Nota añadida con éxito." << std::endl;
    }

    void mostrarNotas() {
        std::cout << "Lista de notas:" << std::endl;
        for (const auto& nota : notas) {
            std::cout << "ID: " << nota.id << std::endl;
            std::cout << "Mensaje: " << nota.mensaje << std::endl;
            std::cout << "Fecha: " << nota.fechadias << "/" << nota.fechameses << "/" << nota.fechaanios << std::endl;
            std::cout << "Hora: " << nota.horap << ":" << nota.horaenMinutos << std::endl;
            std::cout << "Tiempo restante: " << calcularTiempoRestante(nota) << " minutos" << std::endl;
            std::cout << "-------------------------" << std::endl;
        }
    }

    void editarNota(int id) {
        for (auto& nota : notas) {
            if (nota.id == id) {
                std::cin.ignore();
                std::cout << "Escribe la nueva nota: ";
                std::getline(std::cin, nota.mensaje);
                std::cout << "Nota editada con éxito." << std::endl;
                return;
            }
        }
        std::cout << "Nota no encontrada." << std::endl;
    }

    void eliminarNota(int id) {
        for (auto it = notas.begin(); it != notas.end(); ++it) {
            if (it->id == id) {
                notas.erase(it);
                std::cout << "Nota eliminada con éxito." << std::endl;
                return;
            }
        }
        std::cout << "Nota no encontrada." << std::endl;
    }

    int calcularTiempoRestante(const Nota& nota) {
        std::tm eventoFecha = {};
        eventoFecha.tm_year = nota.fechaanios - 1900;
        eventoFecha.tm_mon = nota.fechameses - 1;
        eventoFecha.tm_mday = nota.fechadias;
        eventoFecha.tm_hour = nota.horap;
        eventoFecha.tm_min = nota.horaenMinutos;
        eventoFecha.tm_sec = 0;

        std::time_t eventoTime = std::mktime(&eventoFecha);
        std::time_t now = std::time(nullptr);

        if (eventoTime < now) {
            return 0;  // El evento ya ha ocurrido.
        } else {
            double diff = std::difftime(eventoTime, now);
            return static_cast<int>(diff / 60);  // Diferencia en minutos.
        }
    }

private:
    int pedirNumeroValido(const std::string& mensaje, int min, int max) {
        int numero;
        while (true) {
            std::cout << mensaje;
            if (std::cin >> numero && numero >= min && numero <= max) {
                break;
            } else {
                std::cout << "El valor ingresado no es válido. Ingrese otro número dentro del rango (" << min << "-" << max << "): ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
        return numero;
    }
};

bool esNumero(const std::string& str) {
    std::istringstream ss(str);
    int num;
    ss >> num;
    return !ss.fail() && ss.eof();
}

int main() {
    AgendaNotas agenda;
    int opcion;

    do {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Programar nota" << std::endl;
        std::cout << "2. Mostrar notas" << std::endl;
        std::cout << "3. Editar nota" << std::endl;
        std::cout << "4. Eliminar nota" << std::endl;
        std::cout << "5. Salir" << std::endl;
        std::cout << "Seleccione una opción: ";
        std::string entrada;
        std::cin >> entrada;

        if (esNumero(entrada)) {
            opcion = std::stoi(entrada);

            switch (opcion) {
                case 1:
                    agenda.programarNota();
                    break;
                case 2:
                    agenda.mostrarNotas();
                    break;
                case 3:
                    int idEditar;
                    std::cout << "Ingrese el ID de la nota a editar: ";
                    std::cin >> idEditar;
                    agenda.editarNota(idEditar);
                    break;
                case 4:
                    int idEliminar;
                    std::cout << "Ingrese el ID de la nota a eliminar: ";
                    std::cin >> idEliminar;
                    agenda.eliminarNota(idEliminar);
                    break;
                case 5:
                    std::cout << "Saliendo del programa." << std::endl;
                    break;
                default:
                    std::cout << "Opción no válida. Intente de nuevo." << std::endl;
                    break;
            }
        } else {
            std::cout << "Ingrese una opción válida (números)." << std::endl;
            opcion = 0;
        }

    } while (opcion != 5);

    return 0;
}


#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <ctime>
#include <limits> // Necesario para std::numeric_limits

struct Nota {
    int id;
    std::string nomdoc;
    std::string nompas;
    std::string diagnostico;

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
        std::cout << "Escribe el nombre del doctor : ";
        std::getline(std::cin, nuevaNota.nomdoc);

        nuevaNota.id = idCounter++;
        std::cout << "Escribe el nombre del pasiente : ";
        std::getline(std::cin, nuevaNota.nompas);

        nuevaNota.id = idCounter++;
        std::cout << "Escribe el diagnostico del pasiente : ";
        std::getline(std::cin, nuevaNota.diagnostico);





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
            std::cout << "Mensaje: " << nota.nomdoc << std::endl;
            std::cout << "Mensaje: " << nota.nompas << std::endl;
            std::cout << "Mensaje: " << nota.diagnostico << std::endl;

            std::cout << "Fecha: " << nota.fechadias << "/" << nota.fechameses << "/" << nota.fechaanios << std::endl;
            std::cout << "Hora: " << nota.horap << ":" << nota.horaenMinutos << std::endl;
            std::cout << "Tiempo restante: " << calcularTiempoRestante(nota) << " minutos" << std::endl;
            std::cout << "-------------------------" << std::endl;
        }
    }

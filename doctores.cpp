#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <ctime>
#include <limits> // Necesario para std::numeric_limits

struct Nota {
    int id;
    std::string nomdoc,nompas,diagnostico,direccion; 
    int fechadias,fechameses,fechaanios,horap,horaenMinutos,edad,consultorio;
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
       std::cout << "Escribe el nombre del doctor (máximo 40 caracteres): ";
     std::string inputNomDoc;
     std::getline(std::cin, inputNomDoc);

     if (inputNomDoc.length() > 40) {
        std::cout << "El nombre del doctor excede los 40 caracteres permitidos. Por favor, inténtalo de nuevo." << std::endl;
        return;
     }
     nuevaNota.nomdoc = inputNomDoc;

       std::cout << "Escribe el nombre del paciente (máximo 40 caracteres): ";
     std::string inputNomPas;
     std::getline(std::cin, inputNomPas);

     if (inputNomPas.length() > 40) {
        std::cout << "El nombre del paciente excede los 40 caracteres permitidos. Por favor, inténtalo de nuevo." << std::endl;
        return;
     }
     nuevaNota.nompas = inputNomPas;
     
     std::cout <<" escribe el diagnostico del pasiente :";
     std::string inputdiagnostico;
     std::getline(std::cin,inputdiagnostico);
     
     if (inputdiagnostico.length()>500){
        return;
     }
        nuevaNota.diagnostico =inputdiagnostico;

     std::cout <<"escriba la direccion del pasiente :";
     std::string inputdireccion;
     std::getline(std::cin,inputdireccion);

     if (inputdireccion.length()>50){
     return;
     }
     nuevaNota.direccion = inputdireccion;

        nuevaNota.fechadias = pedirNumeroValido("Fecha (en días 1-31): ", 1, 31);
        nuevaNota.fechameses = pedirNumeroValido("Mes (en meses de 1-12): ", 1, 12);
        nuevaNota.fechaanios = pedirNumeroValido("Año (<2023): ", 2023, 4000); // Cambiar el rango si es necesario
        nuevaNota.horap = pedirNumeroValido("Hora (formato de 24 horas): ", 7, 21);
        nuevaNota.horaenMinutos = pedirNumeroValido("Minutos (0-59): ", 0, 59);
        nuevaNota.edad=pedirNumeroValido("edad (1-120 ):",0,120);
        nuevaNota.consultorio=pedirNumeroValido("CONSULTORIO (1-30 ):",0,30);

        notas.push_back(nuevaNota);
        std::cout << "Nota anadida con éxito." << std::endl;
    }

    void mostrarNotas() {
        std::cout << "Lista de notas:" << std::endl;
        for (const auto& nota : notas) {
            std::cout << "ID : " << nota.id << std::endl;
            std::cout << "nombre del doc: " << nota.nomdoc << std::endl;
            std::cout << "nombre del pasiente: " << nota.nompas << std::endl;
            std::cout << "diagnostico: " << nota.diagnostico << std::endl;
            std::cout << "direccion del paciente : " <<nota.direccion << std::endl;
        
            std::cout << "consultorio"<<nota.consultorio<< std::endl;
            std::cout << "edad: " << nota.edad << std::endl;


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
                std::cout << "Escribe el nombre del doctor : ";
                std::getline(std::cin, nota.nomdoc ) ;
                std::cout <<"escibre el nom del pasiente: ";
                std::getline(std::cin,nota.nompas );
                std::cout << "escribe el nuevo diagnostico : ";
                std::getline (std::cin,nota.diagnostico ) ;
                std::cout <<"escribe la direccin del pasiente : ";
                std::getline (std::cin,nota.direccion ); 

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
    int pedirNumeroValido(const std::string&nomdoc , int min, int max) {
        int numero;
        while (true) {
            std::cout <<nomdoc;
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
        std::cout << "1. Programar cita" << std::endl;
        std::cout << "2. Mostrar citas" << std::endl;
        std::cout << "3. Editar cita" << std::endl;
        std::cout << "4. Eliminar cita" << std::endl;
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


#include <iostream>
#include <vector>
#include <string>
#include<sstream>


struct Nota {
    int id;
    std::string mensaje;
    float fechadias; // Usamos float para la fecha en dias
    float fechameses; // Usamos float para la fecha en meses
    float fechaanios; // Usamos float para la fecha ena años
    float horap;  // Usamos float para la hora ().
    float horaenMinutos;  // Usamos float para la hora  en segundos).
};

class AgendaNotas {
private:         
    std::vector<Nota> notas;       
    int idCounter = 1;          // usamos un id para identificar cada nota

public:
    void programarNota() {
        Nota nuevaNota;
        std::cin.ignore();


        // se solisitan y guardan los datos ingresados por el usuario

        nuevaNota.id = idCounter++;         
        std::cout << "Escribe tu nota: ";
        std::getline(std::cin, nuevaNota.mensaje);

        std::cout << "Fecha (en dias 1-31): ";    // solicitamos al usuario que ingrese la fecha
         std::cin >> nuevaNota.fechadias;
         while (nuevaNota.fechadias < 1 || nuevaNota.fechadias > 31) {
        std::cout << "El valor ingresado está fuera del rango permitido. Ingrese otro numero (1-31): ";
        std::cin >> nuevaNota.fechadias;
    }

         std::cout << "Fecha (en meses de 1-12): "; // solicitamos al usuario que ingrese la fecha
        std::cin >> nuevaNota.fechameses;
         while (nuevaNota.fechameses < 1 || nuevaNota.fechameses > 12) {   // no le permitimos al usuario ingresar un numero no coherente como 13 en meses
        std::cout << "El valor ingresado está fuera del rango permitido. Ingrese otro numero (1-31): ";
        std::cin >> nuevaNota.fechameses;
    }

         std::cout << "Fecha (en años <2023): ";  // solicitamos al usuario que ingrese la fecha
        std::cin >> nuevaNota.fechaanios;


        std::cout << "Hora sin minutos : ";  // solicitamos al usuario la hora 
        std::cin >> nuevaNota.horap;
 while (nuevaNota.horap < 1 || nuevaNota.horap > 24) {      // no nos deja ingresar una hora incorrecta 
        std::cout << "la hora es en formato de 24 horas ingrese otro num: ";  // le explica al usuario que es en formato de 24 horas 
        std::cin >> nuevaNota.horap;
    }

        std::cout << "Hora en minutos: ";  // solicitamos al usuario la hora 
        std::cin >> nuevaNota.horaenMinutos;
         while (nuevaNota.horaenMinutos < 1 || nuevaNota.horaenMinutos > 59) {  // ase que e usuario no pueda meter mas de 59 minutos a una hora 
        std::cout << "las horas solo tien 60 minutos ingrese otro numero(1-60): ";  // le imprime esto en pantalla al usuario si ingresa un dato no coherente 
        std::cin >> nuevaNota.horaenMinutos;
    }

        notas.push_back(nuevaNota);
        std::cout << "Nota anadida con exito." << std::endl;
    }
    

    void mostrarNotas() {                                 // muestra la informacion de la nota 
        std::cout << "Lista de notas:" << std::endl;     // endl salto de linia 
        for (const auto& nota : notas) {
            std::cout << "ID: " << nota.id << std::endl;
            std::cout << "Mensaje: " << nota.mensaje << std::endl;
            std::cout << "Fecha (fecha completa): " << nota.fechadias<<"/"<<nota.fechameses<<"/"<<nota.fechaanios<< std::endl;

            std::cout << "Hora (------hora-------   ): " << nota.horap<<":"<<nota.horaenMinutos << std::endl;

            std::cout << "-------------------------" << std::endl;
        }
    }

    void editarNota(int id) {
        for (auto& nota : notas) {
            if (nota.id == id) {
                std::cin.ignore();   // este es capaz de ignorar una serie de caracteres(separadores)

                std::cout << "Escribe la nueva nota: ";   // edita la nota solo la nota y no la fecha 
                std::getline(std::cin, nota.mensaje);     //
               

                std::cout << "Nota editada con exito." << std::endl;
                return;
            }
              }
        std::cout << "Nota no encontrada." << std::endl;
    }

    void eliminarNota(int id) {
        for (auto it = notas.begin(); it != notas.end(); ++it) {    // elimina la nota 
            if (it->id == id) {     // usamos un if para asegurarnos de que ingrese un id coherente 
                notas.erase(it);
                std::cout << "Nota eliminada con exito." << std::endl;    // nos confirma que la nota se a eliminado
                return;
            }
        }
        std::cout << "Nota no encontrada." << std::endl;
    }
};
bool esNumero(const std::string& str) {
    std::istringstream ss(str);
    float num;
    ss >> num;
    return !ss.fail() && ss.eof();
}
int main() {
    AgendaNotas agenda;
     int opcion ;

    do {


        std::cout << "Menu:" << std::endl;                // nos muestra este menu en pantalla
        std::cout << "1. Programar nota" << std::endl;   
        std::cout << "2. Mostrar notas" << std::endl;
        std::cout << "3. Editar nota" << std::endl;
        std::cout << "4. Eliminar nota" << std::endl;
        std::cout << "5. Salir" << std::endl;
        std::cout << "Seleccione una opcion: ";
        std::string entrada;
        std::cin >> entrada;

        if (esNumero(entrada)) {
            opcion = std::stoi(entrada);
     
        switch (opcion) {                                  // este es el menu 
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
                std::cout << "Opcion no valida. Intente de nuevo." << std::endl;
                break;
          

        }
    } else {
        std::cout << "ingresa una opcion valida(numros)." << std::endl;  // le dise al usuario que no sea manco e ingrese un numero
     opcion = 0;
    }
          
    } while (opcion != 5);
     
    return 0;
}

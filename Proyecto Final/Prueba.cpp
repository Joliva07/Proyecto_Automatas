#include <iostream>
#include <fstream>
#include <string>
#include <limits> // Se agrega para limpiar el buffer de entrada

bool isXML(const std::string& filename) {
    // Verifica si el archivo tiene extensión .xml
    return filename.size() >= 4 && filename.substr(filename.size() - 4) == ".xml";
}

void createAFN() {
    // Aquí puedes agregar la lógica para crear un AFN (Automaton Finite State Network)
    // Por ahora, esta función está vacía
    std::cout << "Opción 'Crear AFN' seleccionada. Funcionalidad en desarrollo." << std::endl;
}

int main() {
    std::cout << "Bienvenido al programa de manejo de archivos y operaciones AFN." << std::endl;

    while (true) {
        std::cout << "\nMenu:\n";
        std::cout << "1. Encontrar archivo XML\n";
        std::cout << "2. Crear AFN\n";
        std::cout << "3. Salir\n";
        std::cout << "Seleccione una opción: ";

        int choice;
        std::cin >> choice;

        // Limpiar el buffer de entrada para evitar problemas con la lectura de enteros
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 1: {
                std::string filePath;
                std::cout << "Introduce la ruta del archivo: ";
                std::getline(std::cin, filePath);

                if (!isXML(filePath)) {
                    std::cerr << "Error: El archivo no es un archivo XML válido." << std::endl;
                } else {
                    std::ifstream fileStream(filePath);
                    if (!fileStream.is_open()) {
                        std::cerr << "Error: No se pudo abrir el archivo." << std::endl;
                    } else {
                        std::cout << "Archivo XML encontrado y abierto correctamente." << std::endl;
                        fileStream.close();
                    }
                }
                break;
            }
            case 2: {
                createAFN();
                break;
            }
            case 3: {
                std::cout << "Saliendo del programa. ¡Hasta luego!" << std::endl;
                return 0;
            }
            default: {
                std::cerr << "Opción inválida. Por favor, selecciona una opción válida." << std::endl;
                break;
            }
        }
    }

    return 0;
}

#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <algorithm>
#include <chrono>
#include <thread>

#ifdef _WIN32
#include <cstdlib>
#endif

bool isXML(const std::string& filename) {
    // Verifica si el archivo tiene extensión .xml
    if (filename.size() >= 4 && filename.substr(filename.size() - 4) == ".xml") {
        std::ifstream fileStream(filename);
        if (fileStream.is_open()) {
            bool containsOpeningTag = false;
            bool containsClosingTag = false;
            std::string line;
            while (std::getline(fileStream, line)) {
                if (line.find('<') != std::string::npos) {
                    containsOpeningTag = true;
                }
                if (line.find('>') != std::string::npos) {
                    containsClosingTag = true;
                }
            }
            return containsOpeningTag && containsClosingTag;
        }
    }
    return false;
}

void createAFN() {
    // Aquí puedes agregar la lógica para crear un AFN (Automaton Finite State Network)
    // Por ahora, esta función está vacía
    std::cout << "Opcion 'Crear AFN' seleccionada. Funcionalidad en desarrollo." << std::endl;
}

std::string extractFileName(const std::string& filePath) {
    size_t lastSlash = filePath.find_last_of("/\\");
    if (lastSlash != std::string::npos) {
        return filePath.substr(lastSlash + 1);
    }
    return filePath;
}

int main() {
    std::cout << "Bienvenido al programa de manejo de archivos y operaciones AFN." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(5)); // Espera de 2 segundos

    std::string currentFile;
    std::string currentFilePath;

    while (true) {
#ifdef _WIN32
        std::system("cls");
#else
        std::system("clear");
#endif

        std::cout << "\nMenu:\n";
        std::cout << "1. Encontrar archivo XML\n";
        std::cout << "2. Previsualizar archivo XML y trabajar con el\n";
        std::cout << "3. Crear AFN\n";
        std::cout << "4. Salir\n";
        std::cout << "Seleccione una opcion: ";

        int choice;
        std::cin >> choice;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 1: {
                std::string filePath;
                std::cout << "Introduce la ruta del archivo: ";
                std::getline(std::cin, filePath);

                if (!isXML(filePath)) {
                    std::cerr << "Error: El archivo no es Valido, porfavor vuelva a intentarlo." << std::endl;
                } else {
                    currentFile = extractFileName(filePath);
                    currentFilePath = filePath;
                    std::cout << "Archivo XML seleccionado: " << currentFile << std::endl;
                }
                break;
            }
            case 2: {
                if (!currentFilePath.empty()) {
                    std::ifstream fileStream(currentFilePath);
                    if (fileStream.is_open()) {
                        std::cout << "Previsualizacion del contenido del archivo:\n";
                        std::string line;
                        while (std::getline(fileStream, line)) {
                            std::cout << line << std::endl;
                        }
                        fileStream.close();
                    }
                } else {
                    std::cerr << "Error: No se ha seleccionado un archivo XML." << std::endl;
                }
                break;
            }
            case 3: {
                createAFN();
                break;
            }
            case 4: {
                std::cout << "Saliendo del programa. ¡Hasta luego!" << std::endl;
                return 0;
            }
            default: {
                std::cerr << "Opcion invalida. Por favor, selecciona una opcion valida." << std::endl;
                break;
            }
        }

        std::cout << "Presiona Enter para continuar...";
        std::cin.get(); // Espera hasta que el usuario presione Enter
    }

    return 0;
}
#include <iostream>
#include <fstream>
#include <string>

bool isXML(const std::string& filename) {
    // Verifica si el archivo tiene extensión .xml
    return filename.size() >= 4 && filename.substr(filename.size() - 4) == ".xml";
}

int main() {
    while (true) {
        std::string filePath;
        std::cout << "Introduce la ruta del archivo (o escribe 'salir' para terminar): ";
        std::cin >> filePath;

        if (filePath == "salir") {
            std::cout << "Saliendo del programa." << std::endl;
            break;
        }

        if (!isXML(filePath)) {
            std::cerr << "Error: El archivo no es un archivo XML válido." << std::endl;
            continue;
        }

        std::ifstream fileStream(filePath);
        if (!fileStream.is_open()) {
            std::cerr << "Error: No se pudo abrir el archivo." << std::endl;
            continue;
        }

        // Aquí puedes realizar operaciones con el archivo XML
        std::cout << "Archivo XML encontrado y abierto correctamente." << std::endl;

        fileStream.close();
    }

    return 0;
}

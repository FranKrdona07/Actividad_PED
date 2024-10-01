#include <iostream>
#include <string>
#include <queue>

struct Documento {
    std::string nombre;
    int paginas;
  };

void anadirDocumento(std::queue<Documento>& cola, const std::string& nombre, int paginas);
void imprimirDocumento(std::queue<Documento> &documentos);
void mostrarEstado(const std::queue<Documento> documentos);


int main() {
    std::queue<Documento> colaImpresion;
    int opcion;
    std::string nombre;
    int paginas = 0;

    do {
      std::cout << "\n1. Añadir documento\n";
      std::cout << "2. Imprimir documento\n";
      std::cout << "3. Mostrar\n";
      std::cout << "4. Salir\n";
      std::cout << "Seleccione una opción: ";
      std::cin >> opcion;

      switch (opcion) {
        case 1:
          std::cout << "Nombre del documento: ";
          std::cin.ignore();
          std::cin >> nombre;
          std::cout << "Número de páginas: ";
          std::cin.ignore();
          std::cin >> paginas;
          anadirDocumento(colaImpresion, nombre, paginas);
          break;
        case 2:
          imprimirDocumento(colaImpresion);
          break;
        case 3:
          std::cout << "Mostrando...\n";
          mostrarEstado(colaImpresion);
          break;
        case 4:
          std::cout << "Saliendo...\n";
          break;  
        default:
          std::cout << "Opción no válida, ingresa una opcion valida (1,2,3).\n";
          break;
      }
    } while (opcion != 4);

    return 0;
}


void anadirDocumento(std::queue<Documento>& cola, const std::string& nombre, int paginas) {
    Documento doc = {nombre, paginas};
    cola.push(doc);
    std::cout << "Documento " << nombre << " añadido a la cola de impresión.\n";
}

void imprimirDocumento(std::queue<Documento> &documentos) {
    if(documentos.empty()) {
        std::cout << "No hay documentos para imprimir.";
    } else {
        std::cout << "Imprimiendo " << documentos.front().nombre << std::endl;
    }
    documentos.pop();
}

void mostrarEstado(const std::queue<Documento> documentos) {
    if(documentos.empty()) {
        std::cout << "No hay documentos en la cola.\n";
    } else {
        std::queue<Documento> temporal = documentos;

        std::cout << "Documentos en la cola: \n";
        while(!temporal.empty()) {
            std::cout << temporal.front().nombre << std::endl;
            temporal.pop();
        }
    }
}
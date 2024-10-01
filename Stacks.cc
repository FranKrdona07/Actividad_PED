#include <iostream>
#include <stack>

void PedirDatos(int &pila_numeros);
int main(int argc, char *argv[]){
  int pila_numeros;
  PedirDatos(pila_numeros);


  return 0;
}
void PedirDatos(int &pila_numeros){
  std::stack<char> pila;
    char valor;

    // Solicitando al usuario que ingrese valores para apilar
    std::cout << "Ingrese los valores que desea operar (0 para terminar): " << std::endl;
    do
    {
      std::stack<std::char> temp = valor;
      std::cout << "Valor: ";
        std::cin >> valor;
        if (valor == 0) break;
        pila.push(valor);  // Apilando el valor

        if (valor == '+')
        {
          
        }
        
    } while (valor !=0);

  return;
}
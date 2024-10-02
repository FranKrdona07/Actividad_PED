#include <iostream>
#include <stack>
int Calculadora(std::string expresion);


int main() {
  std::string expresion;
  std::cout << "Introduce una expresion postfija: ";
  std::getline(std::cin, expresion);
  return 0;
}

int Calculadora(std::string expresion) {
  std::stack<int> pila_numeros;

  for (int i = 0; i < expresion.size();++i) {  
    char c = expresion[i];

    if (c == ' ') continue;

    if (c >= '0' && c <= '9') {
      pila_numeros.push(c -'0');  
    }
  }
  
  return pila_numeros.top();
}
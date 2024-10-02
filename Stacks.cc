#include <iostream>
#include <stack>
int Calculadora(std::string expresion);

int main() {
  std::string expresion;
  std::cout << "Introduce una expresion postfija: ";
  std::getline(std::cin, expresion);

  int resultado = Calculadora(expresion);
  std::cout << "Resultado: " << resultado << std::endl;
  return 0;
}

int Calculadora(std::string expresion) {
  std::stack<int> pila_numeros;

  for (int i = 0; i < expresion.size(); ++i) {
    char c = expresion[i];

    if (c == ' ') continue;

    if (c >= '0' && c <= '9') {
      pila_numeros.push(c - '0');
    } else {
      int op2 = pila_numeros.top();
      pila_numeros.pop();
      int op1 = pila_numeros.top();
      pila_numeros.pop();

      switch (c) {
        case '+':
          pila_numeros.push(op1 + op2);
          break;

        case '-':
          pila_numeros.push(op1 - op2);
          break;

        case '*':
          pila_numeros.push(op1 * op2);
          break;

        case '/':
          pila_numeros.push(op1 / op2);
          break;
      }
    }
  }

  return pila_numeros.top();
}
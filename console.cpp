#include "console.hpp"

#include <iostream>
#include <limits>
#include <cstdlib>

void ClearScreen () {
    #ifndef _WIN32
      system("cls");
    #else
      system("clear");
    #endif
}

void ShowMenu () {
    std::cout << "=========================" << "\n";
    std::cout << "|||   CALCULADORA C++ |||" << "\n";
    std::cout << "||| ===== Menu ====== |||" << "\n";
    std::cout << "|||   [1].Soma        |||" << "\n";
    std::cout << "|||   [2].Subtração   |||" << "\n";
    std::cout << "|||   [3].Multiplicar |||" << "\n";
    std::cout << "|||   [4].Divisão     |||" << "\n";
    std::cout << "|||   [5].Potenciação |||" << "\n";
    std::cout << "|||   [6].Média       |||" << "\n";
    std::cout << "|||   [7].Raíz        |||" << "\n";     
    std::cout << "|||   [0].Sair        |||" << "\n";
    std::cout << "=========================" << "\n";
}

void Pause () {
    std::cout << "Pressione ENTER para continuar";

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cin.get();
}

void EndProgram () {
    std::cout << "Fechando Programa..." << '\n';
    std::cout << "Pressione ENTER para continuar";

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cin.get();
}

int Read_Option () {
  int option;

  while(true) {
    
    std::cout << "Escolha uma opção: ";

    if(std::cin >> option) {
      if(option >= 0 && option <= 7) {
        return option;
    }

      std::cout << "Opção inválida! Escolha um número de 0 a 7 " << "\n";

    } else {
      std::cout << "Entrada inválida! Digite apenas números. " << "\n";
      std::cin.clear();
    }

      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
   }
}

long double Read_Number (const char* message) {
  long double number;

  while(true) {
    std::cout << message;

    if(std::cin >> number) {
      return number;
    }

    std::cout << "Entrada inválida! Digite apenas números.\n";

    std::cin.clear();

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
}
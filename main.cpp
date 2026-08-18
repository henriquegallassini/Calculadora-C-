#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>
#include <cstdlib>
#include <clocale>

void ClearScreen();
void ShowMenu();
void Pause();
void EndProgram();

int Read_Option();
long double Read_Number();

long double Soma (long double n1, long double n2);
long double Subtracao (long double n1, long double n2);
long double Multiplicacao (long double n1, long double n2);
long double Divisao (long double n1, long double n2);
long double Potencia (long double base, long double expoente);
long double Media (long double n1, long double n2);
long double Raiz_Quadrada (long double numero);

int main() {
    
   std::setlocale(LC_ALL, "pt_BR.UTF-8");

   std::cout << std::fixed << std::setprecision(2); //Ao invés de printar todas as casas decimais ele impre 2 após a vírgula
    
   int option = -1; // inicializado — usar variável sem valor é comportamento indefinido n
   long double n1, n2;
   
   while(option!=0){
     
     ClearScreen();
     ShowMenu();

     option = Read_Option();

     if(option == 0) break;

     std::cout << "Digite o primeiro número: ";

     n1 = Read_Number();

     std::cout << "Digite o segundo número: ";
     
     n2 = Read_Number();

     switch (option){
       case 1:
         std::cout << "Soma: " << Soma(n1, n2) << "\n";
         break;

       case 2:
         std::cout << "Subtração: " << Subtracao(n1, n2) << "\n";
         break;

       case 3:
         std::cout << "Multiplicação: " << Multiplicacao(n1, n2) << "\n";
         break;

       case 4:
         while(n2 == 0){
          std::cout << "Impossível divisão por 0, digite outro segundo número." << "\n";
          std::cout << "Digite um segundo número: ";
          std::cin >> n2;
        }

        std::cout << "Divisão: " << Divisao(n1, n2)<< "\n";
        break;

      case 5:
      {
        std::cout << "Potência: " << Potencia(n1, n2) << "\n";
        break;
      }

      case 6:
        std::cout << "Média: " << Media(n1, n2) << "\n";
        break;

      case 7:
        while(n1 < 0){
         std::cout << "Operação impossível, não exite raíz de número negativo tente novamente" << "\n";
         std::cout << "Digite o primeiro número: ";
         std::cin >> n1;
         }

         std::cout << "Raíz Quadrada de " << Raiz_Quadrada(n1) << "\n";

         break;

      default:
       std::cout << "Opção escolhida é inválida, tente novamente" << "\n";
       break;
    }

    Pause();
  }

    EndProgram();
    return 0;
}

void ClearScreen () {
    #ifdef _WIN32
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
    std::cout << "Pressione Enter para continuar" << "\n";

    std::cin.ignore(
        std::numeric_limits<std::streamsize>::max(),'\n');

    std::cin.get();
}

void EndProgram () {
    std::cout << "Finalizando Programa..." << "\n";
    std::cout << "Pressione Enter para continuar" << "\n";

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

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

long double Read_Number() {
  long double number;

  while(!(std::cin >> number)) {
    std::cout << "Entrada inválida! Digite apenas números" << "\n";

    std::cin.clear();

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

    std::cout << "Digite novamente: ";
  }
  return number;
}


long double Soma (long double n1, long double n2) {
  return n1 + n2;
}

long double Subtracao (long double n1, long double n2) {
  return n1 - n2;
}

long double Multiplicacao (long double n1, long double n2) {
  return n1 * n2;
}

long double Divisao (long double n1, long double n2) {
  return n1/n2;
}

long double Potencia (long double base, long double expoente) {
  return std::pow(base, expoente);
}

long double Media (long double n1, long double n2) {
  return (n1+n2)/2.0L;
}

long double Raiz_Quadrada (long double numero) {
  return std::sqrt(numero);
}
#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>
#include <cstdlib>
#include <clocale>

int main() {
    
   std::setlocale(LC_ALL, "pt_BR.UTF-8");

   std::cout << std::fixed << std::setprecision(2); //Ao invés de printar todas as casas decimais ele impre 2 após a vírgula
    
   int option = -1; // inicializado — usar variável sem valor é comportamento indefinido
   long double n1, n2;
   
   while(option!=0){

    #ifdef _WIN32
      system("cls");
    #else
      system("clear");
    #endif
     
     std::cout << "=========================" << std::endl;
     std::cout << "|||   CALCULADORA C++ |||" << std::endl;
     std::cout << "||| ===== Menu ====== |||" << std::endl;
     std::cout << "|||   [1].Soma        |||" << std::endl;
     std::cout << "|||   [2].Subtração   |||" << std::endl;
     std::cout << "|||   [3].Multiplicar |||" << std::endl;
     std::cout << "|||   [4].Divisão     |||" << std::endl;
     std::cout << "|||   [5].Potenciação |||" << std::endl;
     std::cout << "|||   [6].Média       |||" << std::endl;
     std::cout << "|||   [7].Raíz        |||" << std::endl;     
     std::cout << "|||   [0].Sair        |||" << std::endl;
     std::cout << "=========================" << std::endl;

     std::cout << "Escolha uma opção: ";

     while(!(std::cin >> option)){
        std::cout << "Entrada inválida! Digite apenas números " << std::endl;

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Escolha uma opção: ";
        std::cin >> option;
     }

      if(option == 0) break;

     std::cout << "Digite o primeiro número: ";

     while(!(std::cin >> n1)){
        std::cout << "Entrada inválida! Digite apenas números " << std::endl;

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Digite o primeiro número: ";
        std::cin >> n1;
     }

     std::cout << "Digite o segundo número: ";

     while(!(std::cin >> n2)){
        std::cout << "Entrada inválida! Digite apenas números " << std::endl;

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Digite o segundo número: ";
        std::cin >> n2;
     }
     
    
     switch (option){
       case 1:
         std::cout << "Soma: " << n1 + n2 << std::endl;
         break;

       case 2:
         std::cout << "Subtração: " << n1 - n2 << std::endl;
         break;

       case 3:
         std::cout << "Multiplicação: " << n1 * n2 << std::endl;
         break;

       case 4:
         while(n2 == 0){
          std::cout << "Impossível divisão por 0, digite outro segundo número." << std::endl;
          std::cout << "Digite um segundo número: ";
          std::cin >> n2;
        }

        std::cout << "Divisão: " << n1 / n2 << std::endl;
        break;

      case 5:
      {
        long long int potencia = 1;
        for(int i=1; i<=n2; i++){
          potencia = (long double)potencia * n1;
        }
        std::cout << "Potência: " << potencia << std::endl;
        break;
      }

      case 6:
        std::cout << "Média: " << (n1+n2)/2 << std::endl;
        break;

      case 7:
        while(n1 < 0){
         std::cout << "Operação impossível, não exite raíz de número negativo tente novamente" << std::endl;
         std::cout << "Digite o primeiro número" << std::endl;
         std::cin >> n1;
         }

         while(n2 < 0){
         std::cout << "Operação impossível, não exite raíz de número negativo tente novamente" << std::endl;
         std::cout << "Digite o segundo número" << std::endl;
         std::cin >> n2;
         }

         std::cout << "Raíz Quadrada de " << n1 << " = " << sqrt(n1) << std::endl;
         std::cout << "Raíz Quadrada de " << n2 << " = " << sqrt(n2) << std::endl;
         break;

      default:
       std::cout << "Opção escolhida é inválida, tente novamente" << std::endl;
       break;
    }
    
    std::cout << "Pressione Enter para continuar" << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();

  }
    return 0;
}

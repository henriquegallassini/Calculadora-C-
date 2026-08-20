#include <iostream>
#include <iomanip>
#include <clocale>

#include "calculator.hpp"
#include "console.hpp"

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

     switch (option){
       case 1:
        n1 = Read_Number("Digite o primeiro número: ");
        n2 = Read_Number("Digite o segundo número: ");

        std::cout << "Soma: " << Soma(n1, n2) << "\n";
        break;

       case 2:
        n1 = Read_Number("Digite o primeiro número: ");
        n2 = Read_Number("Digite o segundo número: ");

        std::cout << "Subtração: " << Subtracao(n1, n2) << "\n";
        break;

       case 3:
        n1 = Read_Number("Digite o primeiro número: ");
        n2 = Read_Number("Digite o segundo número: ");

        std::cout << "Multiplicação: " << Multiplicacao(n1, n2) << "\n";
        break;

       case 4:
        n1 = Read_Number("Digite o primeiro número: ");
        n2 = Read_Number("Digite o segundo número: ");

        while(n2 == 0){
          std::cout << "Impossível! Divisão por 0 é inválido, tente de novo" << "\n";
          n2 = Read_Number("Digite o segundo número: ");
        }

        std::cout << "Divisão: " << Divisao(n1, n2)<< "\n";
        break;

      case 5:
        n1 = Read_Number("Digite o primeiro número: ");
        n2 = Read_Number("Digite o segundo número: ");

        std::cout << "Potência: " << Potencia(n1, n2) << "\n";
        break;

      case 6:
        n1 = Read_Number("Digite o primeiro número: ");
        n2 = Read_Number("Digite o segundo número: ");

        std::cout << "Média: " << Media(n1, n2) << "\n";
        break;

      case 7:
        n1 = Read_Number("Digite o primeiro número: ");

        while(n1 < 0){
          std::cout << "Impossível! Não existe raiz de número negativo, tente de novo" << "\n";
          n1 = Read_Number("Digite o primeiro número: ");
        }

         std::cout << "Raíz Quadrada de " << n1 << ": " << Raiz_Quadrada(n1) << "\n";

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
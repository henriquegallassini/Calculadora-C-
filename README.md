🧮 Calculadora C++
Calculadora de terminal desenvolvida em C++ com menu interativo, validação de entradas e operações matemáticas essenciais.

✨ Funcionalidades
Opção	Operação
1	Soma
2	Subtração
3	Multiplicação
4	Divisão (com proteção contra divisão por zero)
5	Potenciação
6	Média
7	Raiz Quadrada
0	Sair

🛡️ Validações
Entrada inválida (letras no lugar de números) é detectada e o usuário é solicitado a digitar novamente
Divisão por zero é bloqueada com reentrada
Raiz quadrada de número negativo é bloqueada com reentrada
🚀 Como compilar e rodar
Pré-requisitos
Compilador G++ com suporte a C++17
Windows, Linux ou macOS
Compilar
bash
g++ -std=c++17 -o calculadora calculadora.cpp
Rodar
bash
# Windows
calculadora.exe

# Linux / macOS
./calculadora
🔧 Tecnologias utilizadas
C++17
<cmath> — funções matemáticas (sqrt)
<iomanip> — formatação de casas decimais
<limits> — validação de entradas
<cstdlib> — limpeza de tela multiplataforma
Diretiva #ifdef _WIN32 para compatibilidade Windows/Linux/macOS
📁 Estrutura do projeto
📦 calculadora-cpp
 ┗ 📜 calculadora.cpp
 ┗ 📜 README.md
👨‍💻 Autor
Feito com 💻 e muito std::cout


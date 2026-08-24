#include <QApplication>
#include <QWidget>
#include <QLineEdit> // Visor da calculadora
#include <QVBoxLayout> // Organiza os componentes dentro da janela

int main(int argc, char *argv[]) { 
    QApplication app(argc, argv); // Cria a Aplicação Qt
    
    QWidget window; // Cria uma janela

    window.setWindowTitle("Calculadora");
    window.resize(360, 520);

    // DISPLAY:

    QLineEdit display; // Visor/Campo de digitação do usuário

    display.setText("0");
    display.setReadOnly(true);
    display.setAlignment(Qt::AlignRight);

    display.setMinimumHeight(70); // Tamanho do Visor

    // LAYOUT:

    QVBoxLayout layout;

    layout.addWidget(&display);

    window.setLayout(&layout);

    // EXIBIR A JANELA:

    window.show(); // Mostra a Janela

    return app.exec(); // Inicia o event loop
}
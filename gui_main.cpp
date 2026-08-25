#include <QApplication>
#include <QWidget>
#include <QLineEdit> // Visor da calculadora
#include <QVBoxLayout> // Organiza os componentes dentro da janela
#include <QGridLayout> // Cria uma grade
#include <QPushButton> // Cria os botões
#include <QString>
#include <QObject>

#include <array>

void ConfigDisplay(QLineEdit& display);
void ConfigNumberButton(QPushButton& button);
void AppendDigit(QLineEdit& display, const QString& digit);
void ConnectNumberButton(QPushButton& button, QLineEdit& display);

int main(int argc, char *argv[]) { 
    QApplication app(argc, argv); // Cria a Aplicação Qt
  
    
    // JANELA:

    QWidget window;

    window.setWindowTitle("Calculadora");
    window.resize(360, 520);

    // DISPLAY:

    QLineEdit display; // Visor/Campo de digitação do usuário

    ConfigDisplay(display);



    // BOTÕES: 

    QPushButton button7("7", &window);
    QPushButton button8("8", &window);
    QPushButton button9("9", &window);
    
    QPushButton button4("4", &window);
    QPushButton button5("5", &window);
    QPushButton button6("6", &window);

    QPushButton button1("1", &window);
    QPushButton button2("2", &window);
    QPushButton button3("3", &window);

    QPushButton button0("0", &window);



    // ARRAY DOS BOTÕES:

    std::array<QPushButton*, 10> numberButtons = {
        &button0,
        &button1,
        &button2,
        &button3,
        &button4,
        &button5,
        &button6,
        &button7,
        &button8,
        &button9
    };


    // CONFIGURA OS BOTÕES: 

    for(QPushButton* button : numberButtons) {
        ConfigNumberButton(*button);

        ConnectNumberButton(*button, display);
    }



    // GRID DOS BOTÕES:

    QGridLayout buttonLayout;

    buttonLayout.addWidget(&button7, 0, 0);
    buttonLayout.addWidget(&button8, 0, 1);
    buttonLayout.addWidget(&button9, 0, 2);

    buttonLayout.addWidget(&button4, 1, 0);
    buttonLayout.addWidget(&button5, 1, 1);
    buttonLayout.addWidget(&button6, 1, 2);

    buttonLayout.addWidget(&button1, 2, 0);
    buttonLayout.addWidget(&button2, 2, 1);
    buttonLayout.addWidget(&button3, 2, 2);

    buttonLayout.addWidget(&button0, 3, 0, 1, 3);



    // LAYOUT PRINCIPAL:

    QVBoxLayout mainLayout;

    mainLayout.addWidget(&display);

    mainLayout.addStretch(); // cria um espaço expansível entre o display e os botões.

    mainLayout.addLayout(&buttonLayout);

    window.setLayout(&mainLayout);



    // EXIBIR A JANELA:

    window.show(); // Mostra a Janela

    return app.exec(); // Inicia o event loop
}

// CONFIGURAÇÃO DO DISPLAY
void ConfigDisplay(QLineEdit& display) {
    display.setText("0");
    display.setReadOnly(true);
    display.setAlignment(Qt::AlignRight);
    
    display.setMinimumHeight(80); // Tamanho do Visor
}

// CONFIGURAÇÃO DOS BOTÕES
void ConfigNumberButton(QPushButton& button) {
    button.setMinimumHeight(60);
}

// ADICIONAR DÍGITO
void AppendDigit(QLineEdit& display, const QString& digit) {

    if(display.text() == "0" ) {
        display.setText(digit);
    } else {
        display.setText(display.text() + digit);
    }
}

// CONECTAR BOTÃO NUMÉRICO
void ConnectNumberButton(QPushButton& button, QLineEdit& display) {
    
    // Pega automaticamente o número escrito no botão
    const QString digit = button.text();

    QObject::connect (
        &button,
        &QPushButton::clicked,
        [&display, digit]() {
            AppendDigit(display, digit);
        }
    );
}
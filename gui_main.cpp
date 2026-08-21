#include <QApplication>
#include <QWidget>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    
    QWidget window;

    window.setWindowTitle("Calculadora");
    window.resize(360, 520);

    window.show();

    return app.exec();
}
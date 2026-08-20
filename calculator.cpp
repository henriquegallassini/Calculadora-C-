#include "calculator.hpp"
#include <cmath>

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
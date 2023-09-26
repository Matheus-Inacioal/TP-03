#include "ponto.h"
#include <math.h>

Ponto criarPonto(float x, float y) {
    Ponto ponto;
    ponto.X = x;
    ponto.Y = y;
    return ponto;
}

float calcularDistancia(Ponto ponto1, Ponto ponto2) {
    float dx = ponto1.X - ponto2.X;
    float dy = ponto1.Y - ponto2.Y;
    return sqrt(dx * dx + dy * dy);
}

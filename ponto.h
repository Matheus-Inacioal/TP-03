#ifndef PONTO_H
#define PONTO_H

typedef struct {
    float X;
    float Y;
} Ponto;

Ponto criarPonto(float x, float y);
float calcularDistancia(Ponto ponto1, Ponto ponto2);

#endif

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ponto.h"

float calcularAreaTriangulo(Ponto A, Ponto B, Ponto C) {
    return 0.5 * fabs(A.X * (B.Y - C.Y) + B.X * (C.Y - A.Y) + C.X * (A.Y - B.Y));
}

float calcularAreaPoligono(Ponto *vertices, int numVertices) {
    float area = 0.0;
    for (int i = 1; i < numVertices - 1; i++) {
        area += calcularAreaTriangulo(vertices[0], vertices[i], vertices[i + 1]);
    }
    return area;
}

int main() {
    int numVertices;

    FILE *arquivo = fopen("vertices.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de entrada.\n");
        return 1;
    }

    
    if (fscanf(arquivo, "%d", &numVertices) != 1) {
        printf("Erro ao ler o número de vértices do arquivo.\n");
        fclose(arquivo);
        return 1;
    }

  
    Ponto *vertices = (Ponto *)malloc(numVertices * sizeof(Ponto));


    for (int i = 0; i < numVertices; i++) {
        float x, y;
        if (fscanf(arquivo, "%f %f", &x, &y) != 2) {
            printf("Erro ao ler os vértices do arquivo.\n");
            fclose(arquivo);
            free(vertices);
            return 1;
        }
        vertices[i] = criarPonto(x, y);
    }

    fclose(arquivo);

        
    float area = calcularAreaPoligono(vertices, numVertices);

    printf("A área do polígono é %.2f\n", area);

    free(vertices);

    return 0;
}

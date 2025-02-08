#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\nTabuleiro:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

void aplicarHabilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int x, int y, char tipo) {
    if (tipo == 'C') { // Cone
        if (x - 2 >= 0) tabuleiro[x - 2][y] = 1;
        if (x - 1 >= 0) {
            if (y - 1 >= 0) tabuleiro[x - 1][y - 1] = 1;
            tabuleiro[x - 1][y] = 1;
            if (y + 1 < TAMANHO_TABULEIRO) tabuleiro[x - 1][y + 1] = 1;
        }
        if (y - 2 >= 0) tabuleiro[x][y - 2] = 1;
        if (y - 1 >= 0) tabuleiro[x][y - 1] = 1;
        tabuleiro[x][y] = 1;
        if (y + 1 < TAMANHO_TABULEIRO) tabuleiro[x][y + 1] = 1;
        if (y + 2 < TAMANHO_TABULEIRO) tabuleiro[x][y + 2] = 1;
    } else if (tipo == 'O') { // Octaedro
        if (x - 1 >= 0) tabuleiro[x - 1][y] = 1;
        if (y - 1 >= 0) tabuleiro[x][y - 1] = 1;
        tabuleiro[x][y] = 1;
        if (y + 1 < TAMANHO_TABULEIRO) tabuleiro[x][y + 1] = 1;
        if (x + 1 < TAMANHO_TABULEIRO) tabuleiro[x + 1][y] = 1;
    } else if (tipo == 'X') { // Cruz
        if (x - 1 >= 0) tabuleiro[x - 1][y] = 1;
        if (y - 2 >= 0) tabuleiro[x][y - 2] = 1;
        if (y - 1 >= 0) tabuleiro[x][y - 1] = 1;
        tabuleiro[x][y] = 1;
        if (y + 1 < TAMANHO_TABULEIRO) tabuleiro[x][y + 1] = 1;
        if (y + 2 < TAMANHO_TABULEIRO) tabuleiro[x][y + 2] = 1;
        if (x + 1 < TAMANHO_TABULEIRO) tabuleiro[x + 1][y] = 1;
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Aplicação das habilidades no tabuleiro
    aplicarHabilidade(tabuleiro, 4, 4, 'C'); // Cone
    aplicarHabilidade(tabuleiro, 7, 7, 'O'); // Octaedro
    aplicarHabilidade(tabuleiro, 2, 2, 'X'); // Cruz

    // Exibir tabuleiro com habilidades aplicadas
    exibirTabuleiro(tabuleiro);
    
    return 0;
}

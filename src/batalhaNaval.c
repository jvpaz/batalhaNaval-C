#include <stdio.h>
#include "tabuleiro.h"
#include "navios.h"
#include "jogada.h"

int main(void)
{
    int tabuleiro[JOGADORES][TAM_TABULEIRO][TAM_TABULEIRO], gabarito[JOGADORES][TAM_TABULEIRO][TAM_TABULEIRO], pontuacao[2][2] = {0};

        criarTabuleiros(tabuleiro, gabarito);
        jogada(tabuleiro, gabarito, barcos, pontuacao);
        mostrarGabarito(gabarito);
        
    return 0;
}

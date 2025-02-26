#include <stdio.h>
#include <stdlib.h>
#include "tabuleiro.h"
#include "navios.h"
#include "jogada.h"

static void limparTela();
static void decidirGanhador();

void jogada(int tabuleiro[JOGADORES][TAM_TABULEIRO][TAM_TABULEIRO], int gabarito[JOGADORES][TAM_TABULEIRO][TAM_TABULEIRO], char *barco[], int pontuacao[2][2])
{
    char *nomeEmbarcacao;
    int coordenadaX = 0, coordenadaY = 0, jogador = 0;
    
    while (pontuacao[0][0] != 15 && pontuacao[1][1] != 15)
    {
        mostrarTabuleiro(tabuleiro);
        printf("\nJogador %d realiza jogada nos quadrantes: ", jogador + 1);
        scanf("%d %d", &coordenadaX, &coordenadaY);

        coordenadaX--;
        coordenadaY--;
        
        nomeEmbarcacao = barco[gabarito[jogador][coordenadaX][coordenadaY]];
        limparTela();
        printf("\nJogador %d acertou %s", jogador + 1, nomeEmbarcacao);

        tabuleiro[jogador][coordenadaX][coordenadaY] = gabarito[jogador][coordenadaX][coordenadaY];

        if (gabarito[jogador][coordenadaX][coordenadaY] != 0 && gabarito[jogador][coordenadaX][coordenadaY] != 1)
        {
            pontuacao[jogador][jogador] += 1;
        }

        jogador = 1 - jogador;
    }
    limparTela();
    decidirGanhador(pontuacao);
}

static void decidirGanhador(int pontuacao[2][2])
{
    if (pontuacao[0][0] == 15)
            printf("\n\nJogador 1 ganhou!");
        else
            printf("\n\nJogador 2 ganhou!");
}

static void limparTela(){
    #if defined(__linux__) || defined(__unix__)
        system("clear");
    #endif

    #if defined(_WIN32)
        system("cls");
    #endif
}
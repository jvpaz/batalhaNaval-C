#include <stdio.h>
#include <string.h>
#include "tabuleiro.h"
#include "navios.h"
#include "jogada.h"

void criarTabuleiros(int tabuleiro[JOGADORES][TAM_TABULEIRO][TAM_TABULEIRO], int gabarito[JOGADORES][TAM_TABULEIRO][TAM_TABULEIRO])
{
    memset(tabuleiro, -1, sizeof(int) * JOGADORES * TAM_TABULEIRO * TAM_TABULEIRO); 
    memset(gabarito, 0, sizeof(int) * JOGADORES * TAM_TABULEIRO * TAM_TABULEIRO);

    verificarNavios(gabarito);
}
void mostrarTabuleiro(int tabuleiro[JOGADORES][TAM_TABULEIRO][TAM_TABULEIRO])
{
    for (int i = 0; i < JOGADORES - 1; i++) 
    {
        for (int j = 0; j < TAM_TABULEIRO; j++)
        {
            printf("\n");
            for (int h = 0; h < TAM_TABULEIRO; h++)
            {
                    printf("%02d ", tabuleiro[i][j][h]);
            }
            printf("\t");
            for (int m = 0; m < TAM_TABULEIRO; m++)
            {
                    printf("%02d ", tabuleiro[i + 1][j][m]);
            }
            
        }
    }
}
void mostrarGabarito(int gabarito[JOGADORES][TAM_TABULEIRO][TAM_TABULEIRO])
{
    for (int i = 0; i < JOGADORES - 1; i++)
    {
        printf("\n");
        for (int j = 0; j < TAM_TABULEIRO; j++)
        {
            printf("\n");
            for (int h = 0; h < TAM_TABULEIRO; h++)
            {  
                printf("%02d ", gabarito[i][j][h]);
            }
            printf("\t");
            for (int  m = 0; m < TAM_TABULEIRO; m++)
            {
                printf("%02d ", gabarito[i + 1][j][m]);
            }
        }
    }
}
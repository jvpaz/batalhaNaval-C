#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tabuleiro.h"
#include "navios.h"

char *barcos[] = {"Agua", "Porta-Avioes", "Navio-Tanque", "ContraTorpedeiro", "Submarino"};

static void inicializarNavios(int gabarito[JOGADORES][TAM_TABULEIRO][TAM_TABULEIRO], int x, int y, int embarcacao, int orientacao, int jogador);

void verificarNavios(int gabarito[JOGADORES][TAM_TABULEIRO][TAM_TABULEIRO])
{
    srand(time(NULL));

    int x, y, embarcacao = 0, orientacao = 0;

    for (int jogador = 0; jogador < 2; jogador++)
    {
 
    while(embarcacao < 5)
    {
       x = rand() % TAM_TABULEIRO;
       y = rand() % TAM_TABULEIRO;

        orientacao = rand() % 2;

        int podeInserir = 1;

        if (orientacao == 0 && (y + (6 - embarcacao - 1) < TAM_TABULEIRO)) //Verifica quadrantes horizontalmente
            {
                
                for (int i = 0; i < 6 - embarcacao; i++)
                {
                    if (gabarito[jogador][x][y + i] != 0)
                    {
                        podeInserir = 0;
                        break;
                    }
                }
                if (podeInserir)
                {
                    inicializarNavios(gabarito, x, y, embarcacao, orientacao, jogador);
                    embarcacao++;
                }
            }
            else if (orientacao == 1 && (x + (6 - embarcacao - 1) < TAM_TABULEIRO)) //Verifica quadrantes verticalmente
            {
                for (int i = 0; i < 6 - embarcacao; i++)
                {
                    if (gabarito[jogador][x + i][y] != 0)
                    {
                        podeInserir = 0;
                        break;
                    }
                }
                if (podeInserir)
                {
                    inicializarNavios(gabarito, x, y, embarcacao, orientacao, jogador);
                    embarcacao++;
                }
            }
        }
        embarcacao = 0;
    }
}

void inicializarNavios(int gabarito[JOGADORES][TAM_TABULEIRO][TAM_TABULEIRO], int x, int y, int embarcacao, int orientacao, int jogador)
{
    if (orientacao == 0) //Insere as embarcações horizontalmente
    {
        for (int i = 0; i < 6 - embarcacao; i++)
        {
            gabarito[jogador][x][y + i] = embarcacao;
        }
    }
    else //Insere as embarcações verticalmente
    {
        for (int i = 0; i < 6 - embarcacao; i++)
        {
            gabarito[jogador][x + i][y] = embarcacao;
        }
    }
}
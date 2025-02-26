#ifndef TABULEIRO_H
#define TABULEIRO_H

#define TAM_TABULEIRO 10
#define JOGADORES 2

void criarTabuleiros(int tabuleiro[JOGADORES][TAM_TABULEIRO][TAM_TABULEIRO], int gabarito[JOGADORES][TAM_TABULEIRO][TAM_TABULEIRO]);
void mostrarTabuleiro(int tabuleiro[JOGADORES][TAM_TABULEIRO][TAM_TABULEIRO]);
void mostrarGabarito(int gabarito[JOGADORES][TAM_TABULEIRO][TAM_TABULEIRO]);

#endif
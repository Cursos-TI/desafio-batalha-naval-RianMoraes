#include <stdio.h>
#include <stdlib.h>
#define Linhas 10
#define Colunas 10
#define TAM_HAB 5 // tamanho fixo das habilidades 5x5

// ================= FUNÇÃO PARA SOBREPOR HABILIDADE =================
void aplicarHabilidade(int tabuleiro[Linhas][Colunas],
                       int habilidade[TAM_HAB][TAM_HAB],
                       int origemLinha,
                       int origemColuna)
{
    int offset = TAM_HAB / 2;

    for (int i = 0; i < TAM_HAB; i++)
    {
        for (int j = 0; j < TAM_HAB; j++)
        {
            if (habilidade[i][j] == 1)
            {
                int linhaTab = origemLinha + (i - offset);
                int colunaTab = origemColuna + (j - offset);

                // valida limite do tabuleiro
                if (linhaTab >= 0 && linhaTab < Linhas &&
                    colunaTab >= 0 && colunaTab < Colunas)
                {
                    if (tabuleiro[linhaTab][colunaTab] == 0)
                        tabuleiro[linhaTab][colunaTab] = 5;
                }
            }
        }
    }
}

// ================= MAIN =================
int main()
{
    int tabuleiro[Linhas][Colunas] = {0};

    // ================= POSICIONANDO NAVIOS =================
    for (int i = 0; i < 3; i++)
        tabuleiro[0][2 + i] = 3;

    for (int i = 0; i < 3; i++)
        tabuleiro[7 + i][4] = 3;

    for (int i = 0; i < 3; i++)
        tabuleiro[i][i] = 3;

    for (int i = 0; i < 3; i++)
        tabuleiro[5 + i][7 - i] = 3;

    // ================= MATRIZES DE HABILIDADE =================

    int cone[TAM_HAB][TAM_HAB] = {0};
    int cruz[TAM_HAB][TAM_HAB] = {0};
    int octaedro[TAM_HAB][TAM_HAB] = {0};

    int centro = TAM_HAB / 2;

    // -------- CONE (apontado para baixo) --------
    for (int i = 0; i < TAM_HAB; i++)
    {
        for (int j = 0; j < TAM_HAB; j++)
        {
            if (j >= centro - i && j <= centro + i)
                cone[i][j] = 1;
        }
    }

    // -------- CRUZ --------
    for (int i = 0; i < TAM_HAB; i++)
    {
        for (int j = 0; j < TAM_HAB; j++)
        {
            if (i == centro || j == centro)
                cruz[i][j] = 1;
        }
    }

    // -------- OCTAEDRO (losango) --------
    for (int i = 0; i < TAM_HAB; i++)
    {
        for (int j = 0; j < TAM_HAB; j++)
        {
            if (abs(i - centro) + abs(j - centro) <= centro)
                octaedro[i][j] = 1;
        }
    }

    // ================= APLICANDO HABILIDADES =================
    aplicarHabilidade(tabuleiro, cone, 4, 4);
    aplicarHabilidade(tabuleiro, cruz, 2, 7);
    aplicarHabilidade(tabuleiro, octaedro, 7, 2);

    // ================= EXIBIÇÃO DO TABULEIRO =================
    printf("    A B C D E F G H I J\n");

    for (int i = 0; i < Linhas; i++)
    {
        printf("%d | ", i);

        for (int j = 0; j < Colunas; j++)
        {
            if (tabuleiro[i][j] == 0)
                printf("0 ");
            else if (tabuleiro[i][j] == 3)
                printf("3 ");
            else if (tabuleiro[i][j] == 5)
                printf("5 ");
        }
        printf("\n");
    }

    return 0;
}
#include <stdio.h>

#define Linhas 10
#define Colunas 10

// Desafio Batalha Naval - MateCheck

int podePosicionar(int tabuleiro[Linhas][Colunas], int linha, int coluna, int tamanho, char direcao) // valida se pode posicionar no tabuleiro
{
    // validar limites básicos
    if (linha < 0 || linha >= Linhas || coluna < 0 || coluna >= Colunas)
        return 0;
    // condicional para validação limite horizontal
    if (direcao == 'H')
    {
        if (coluna + tamanho > Colunas)
            return 0;

        for (int i = 0; i < tamanho; i++)
        {
            if (tabuleiro[linha][coluna + i] != 0)
                return 0;
        }
    }
    // condicional para validação limite horizontal
    else if (direcao == 'V')
    {
        if (linha + tamanho > Linhas)
            return 0;

        for (int i = 0; i < tamanho; i++)
        {
            if (tabuleiro[linha + i][coluna] != 0)
                return 0;
        }
    }
    // condicional para validação limite Diagonal
    else if (direcao == 'D')
    {
        if (linha + tamanho > Linhas || coluna + tamanho > Colunas)
            return 0;

        for (int i = 0; i < tamanho; i++)
        {
            if (tabuleiro[linha + i][coluna + i] != 0)
                return 0;
        }
    }
    else
        return 0;

    return 1;
}

int main()
{
    // declaração de variaveis
    char coluna[Colunas] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int linha[Linhas] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int tabuleiro[Linhas][Colunas] = {0};
    int navioUm[3] = {3, 3, 3};
    int navioDois[3] = {3, 3, 3};

    // posiciona navio1
    if (podePosicionar(tabuleiro, 0, 2, 3, 'H'))
    {
        for (int i = 0; i < 3; i++)
        {
            tabuleiro[0][2 + i] = 3;
        }
    }
    else
    {
        printf("Não pode inserir navio aqui!\n");
        return 0;
    }
    // posiciona navio2
    if (podePosicionar(tabuleiro, 7, 4, 3, 'V'))
    {
        for (int i = 0; i < 3; i++)
        {
            tabuleiro[7 + i][4] = 3;
        }
    }
    else
    {
        printf("Não pode inserir navio aqui!\n");
        return 0;
    }

    // posiciona navio3
    if (podePosicionar(tabuleiro, 0, 0, 3, 'D'))
    {
        for (int i = 0; i < 3; i++)
        {
            tabuleiro[i + 0][0 + i] = 3;
        }
    }
    else
    {
        printf("Não pode inserir navio aqui!\n");
        return 0;
    }
    // posiciona navio4
    if (podePosicionar(tabuleiro, 5, 7, 3, 'D'))
    {
        for (int i = 0; i < 3; i++)
        {
            tabuleiro[i + 5][7 - i] = 3;
        }
    }
    else
    {
        printf("Não pode inserir navio aqui!\n");
        return 0;
    }

    // exibição
    printf("    ");                   // alinhamento
    for (int i = 0; i < Colunas; i++) // exibe as colunas de A a Z
    {
        printf("%c ", coluna[i]);
    }
    printf("\n");

    for (int i = 0; i < Linhas; i++) // exibe o tabuleiro 10x10 + linhas 1 a 10
    {
        printf("%d | ", linha[i]);
        for (int j = 0; j < Colunas; j++)
        {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}

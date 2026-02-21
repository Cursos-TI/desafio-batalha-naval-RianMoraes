#include <stdio.h>

int podePosicionar(int tabuleiro[10][10], int linha, int coluna, int tamanho, char direcao)
{
    // validar limites básicos
    if (linha < 0 || linha >= 10 || coluna < 0 || coluna >= 10)
        return 0;

    if (direcao == 'H')
    {
        if (coluna + tamanho > 10)
            return 0;

        for (int i = 0; i < tamanho; i++)
        {
            if (tabuleiro[linha][coluna + i] != 0)
                return 0;
        }
    }
    else if (direcao == 'V')
    {
        if (linha + tamanho > 10)
            return 0;

        for (int i = 0; i < tamanho; i++)
        {
            if (tabuleiro[linha + i][coluna] != 0)
                return 0;
        }
    }
    else
        return 0;

    return 1;
}

// Desafio Batalha Naval - MateCheck

int main()
{
    // Nível Novato - Posicionamento dos Navios

    // declaração de variaveis
    char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int coluna[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int tabuleiro[10][10] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    int navioUm[3] = {3, 3, 3};
    int navioDois[3] = {3, 3, 3};

    // validações

    // inserção dos navios
    // navioUm
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

// navioDois
    if (podePosicionar(tabuleiro, 7, 4, 3, 'V'))
    {
        for (int i = 0; i < 3; i++)
        {
            tabuleiro[6 + i][4] = 3;
        }
    } 
    else
    {
        printf("Não pode inserir navio aqui!\n");
        return 0;
    }

    // exibição  no console
    printf("    ");
    for (char k = 0; k < 10; k++)
    {
        printf("%c ", linha[k]);
    }
    printf("\n");

    for (int forColuna = 0; forColuna < 10; forColuna++)
    {
        printf("%d | ", coluna[forColuna]);
        for (int forLinha = 0; forLinha < 10; forLinha++)
        {
            printf("%d ", tabuleiro[forColuna][forLinha]);
        }
        printf("\n");
    }

    return 0;
}

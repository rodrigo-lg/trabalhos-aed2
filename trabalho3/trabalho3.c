//Aluno: Rodrigo Lemos Godinho
//RA: 759020
//Curso: Engenharia de Computação

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int busca(char *a, int m, char *b, int n, int *posicoes)
{
    int l = 0;
    for (int k = m; k <= n; ++k)
    {
        int i = m - 1, j = k - 1;
        while (i >= 0 && a[i] == b[j])
            --i, --j;
        if (i < 0)
            posicoes[l++] = j + 1;
    }
    return l;
}

int main(int argc, char *argv[])
{
    int comprimentoS, comprimentoR;
    int *posicoes;
    char *sequencia, *ruido;
    FILE *arquivo;
    char nome[MAX];
    scanf("%s", nome);
    arquivo = fopen(nome, "r");
    fscanf(arquivo, "%d %d", &comprimentoS, &comprimentoR);
    posicoes = (int *)malloc(comprimentoS / comprimentoR * sizeof(int));
    sequencia = (char *)malloc(comprimentoS * sizeof(char));
    ruido = (char *)malloc(comprimentoR * sizeof(char));
    fscanf(arquivo, "%s %s", sequencia, ruido);
    fclose(arquivo);

    for (int i = 0; i < busca(ruido, comprimentoR, sequencia, comprimentoS, posicoes); i++)
    {
        printf("%d\n", posicoes[i]);
    }

    return 0;
}

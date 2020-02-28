//Aluno: Rodrigo Lemos Godinho
//RA: 759020
//Curso: Engenharia de Computacao

#include <iostream>
#include <cstdlib>

using namespace std;

#define MAX 100

double selection(double *, int, int, int);
int divide(double *, int, int);
void change(double *, double *);

int main(int argc, char *argv[])
{
    srand(time(NULL));
    int n, k;
    double l;
    int outliers = 0;
    FILE *input;
    char name[MAX];
    cin >> name;
    input = fopen(name, "r");
    fscanf(input, "%d %d %lf", &n, &k, &l);
    double **elements = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++)
        elements[i] = (double *)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            fscanf(input, "%lf", &elements[i][j]);
    fclose(input);
    for (int i = 0; i < n; i++)
        if (selection(elements[i], 0, n - 1, k + 1) > l)
            outliers++;
    cout << outliers << endl;
}

double selection(double *elements, int begin, int end, int k)
{
    int random, current;
    current = -1;
    while (current != k)
    {
        random = rand() % (end - begin + 1);
        change(&elements[begin + random], &elements[end]);
        current = divide(elements, begin, end);
        if (current > k)
            end = current - 1;
        else if (current < k)
            begin = current + 1;
    }
    return elements[current];
}

int divide(double *elements, int begin, int end)
{
    int i, j;
    i = begin;
    for (j = begin; j < end; j++)
        if (elements[j] <= elements[end])
            change(&elements[i++], &elements[j]);
    change(&elements[i], &elements[end]);
    return i;
}

void change(double *a, double *b)
{
    double aux = *a;
    *a = *b;
    *b = aux;
}

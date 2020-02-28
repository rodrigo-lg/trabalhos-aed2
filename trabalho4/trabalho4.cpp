//Aluno: Rodrigo Lemos Godinho
//RA: 759020
//Curso: Engenharia de Computação

#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

class Grafo
{
public:
    Grafo(int, int);
    ~Grafo();
    void insere_vertice(int, int, int);
    int Dijkstra(int, int);

private:
    int vertices;
    int arestas;
    vector<pair<int, int>> *grafo;
};

int main(int argc, char *argv[])
{
    int v, e, i, a, b, w;
    cin >> v >> e;
    Grafo crush(v, e);
    for (i = 0; i < e; i++)
    {
        cin >> a >> b >> w;
        crush.insere_vertice(a, b, w);
    }
    cout << crush.Dijkstra(0, v - 1) << endl;
    return 0;
}

Grafo::Grafo(int vertices, int arestas)
{
    this->vertices = vertices;
    this->arestas = arestas;
    this->grafo = new vector<pair<int, int>>[vertices];
}

Grafo::~Grafo()
{
    delete[] grafo;
}

void Grafo::insere_vertice(int inicio, int fim, int peso)
{
    this->grafo[inicio].push_back(make_pair(fim, peso));
}

int Grafo::Dijkstra(int origem, int destino)
{
    int i, v, u, w;
    int distancia[this->vertices];
    queue<pair<int, int>> fila;
    for (i = 0; i < this->vertices; i++)
        distancia[i] = numeric_limits<int>::max();
    distancia[origem] = 0;
    fila.push(make_pair(origem, 0));
    while (!fila.empty())
    {
        v = fila.front().first;
        fila.pop();
        for (unsigned int i = 0; i < this->grafo[v].size(); i++)
        {
            u = this->grafo[v][i].first;
            w = this->grafo[v][i].second;
            if (distancia[u] > distancia[v] + w)
            {
                distancia[u] = distancia[v] + w;
                fila.push(make_pair(u, distancia[u]));
            }
        }
    }
    return distancia[destino];
}
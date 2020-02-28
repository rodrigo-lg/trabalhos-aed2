//Nome: Rodrigo Lemos Godinho
//RA: 759020
//Curso: Engenharia de Computação

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

void operacao(char comando, string nome, string numero, unordered_map<string, string> &listaDeContatinhos)
{
    switch (comando)
    {
    case 'I':
        if (listaDeContatinhos.find(nome) != listaDeContatinhos.end())
            cout << "Contatinho ja inserido" << endl;
        else
            listaDeContatinhos.insert(pair<string, string>(nome, numero));
        break;
    case 'P':
        if (listaDeContatinhos.find(nome) != listaDeContatinhos.end())
            cout << "Contatinho encontrado: telefone " << listaDeContatinhos.find(nome)->second << endl;
        else
            cout << "Contatinho nao encontrado" << endl;
        break;
    case 'R':
        if (listaDeContatinhos.find(nome) != listaDeContatinhos.end())
            listaDeContatinhos.erase(listaDeContatinhos.find(nome));
        else
            cout << "Operacao invalida: contatinho nao encontrado" << endl;
        break;
    case 'A':
        if (listaDeContatinhos.find(nome) != listaDeContatinhos.end())
            listaDeContatinhos.find(nome)->second = numero;
        else
            cout << "Operacao invalida: contatinho nao encontrado" << endl;
        break;
    }
}

int main(int argc, char *argv[])
{
    unordered_map<string, string> listaDeContatinhos;
    char comando;
    string nome;
    string numero;
    int end = 0;
    while (!end)
    {
        cin >> comando;
        if (comando != '0')
        {
            cin >> nome;
            if (comando != 'P' && comando != 'R')
                cin >> numero;
            operacao(comando, nome, numero, listaDeContatinhos);
        }
        else
            end = 1;
    }
}
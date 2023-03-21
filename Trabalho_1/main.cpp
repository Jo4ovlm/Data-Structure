#include <iostream>
#include "LISTA.h"

using namespace std;

int main()
{
    ListaSimplesmenteEncadeada<string> listaAlunos;
    string nome, disciplina;
    int posicao, opcao;
    cria(listaAlunos);
    do{
        do{
            cout<<"---------Menu----------\n"
                  " 1 - Novo Aluno\n"
                  " 2 - Nova Disciplina\n"
                  " 3 - Retirar Aluno\n"
                  " 4 - Retirar Disciplina\n"
                  " 5 - Mostrar Todos\n"
                  " 6 - Mostrar Um\n"
                  " 7 - Sair\n"
                  "-----------------------\n"
                  "Opcao: ";
            cin>>opcao;
            cin.ignore();
            system("CLS");
        }while(opcao<1 or opcao>7);
        switch(opcao){
        case 7:
            cout<<"Saindo..."<<endl;
            break;

        case 1:
            cout<<"Nome do aluno: ";
            getline(cin, nome);
            cout<<"Qual posicao? ";
            cin>>posicao;
            cin.ignore();
            insere(listaAlunos, nome, posicao);
            system("CLS");
            break;

        case 2:
            cout<<"Nome do aluno: ";
            getline(cin, nome);
            cout<<"Disciplina: ";
            getline(cin, disciplina);
            cout<<"Qual posicao? ";
            cin>>posicao;
            insereAssociado(listaAlunos, nome, disciplina, posicao);
            system("CLS");
            break;

        case 3:
            cout<<"Nome do aluno: ";
            getline(cin, nome);
            cout<<"Qual posicao? ";
            cin>>posicao;
            retira(listaAlunos, nome, posicao);
            system("CLS");
            break;

        case 4:
            cout<<"Nome do aluno: ";
            getline(cin, nome);
            cout<<"Qual a posicao da disciplina? ";
            cin>>posicao;
            retiraAssociado(listaAlunos, nome, posicao);
            system("CLS");
            break;

        case 5:
            mostra(listaAlunos);
            system("pause");
            system("CLS");
            break;

        case 6:
            cout<<"Informe o nome: ";
            getline(cin, nome);
            mostraAssociado(listaAlunos, nome);
            system("pause");
            system("CLS");
            break;
        }
    }while(opcao!=7);
    destroi(listaAlunos);
    return 0;
}

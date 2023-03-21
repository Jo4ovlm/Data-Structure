#include <iostream>
#include "FilaDuplamenteEncadeada.h"
//Atividade 02, Joao Vitor Loch Martins e Vinicius Hostins Pereira
using namespace std;

void menu(){
    cout<<"--------- Menu ---------"<<endl;
    cout<<"1 - Insere elemento"<<endl;
    cout<<"2 - Retira elemento"<<endl;
    cout<<"3 - Verifica elemento"<<endl;
    cout<<"4 - Mostra"<<endl;
    cout<<"-1 - Sair"<<endl;
    cout<<"------------------------"<<endl;
    cout<<"Opcao: ";
}

int main()
{
    FilaDinamicaGenerica<int> fila;
    int op=0, elemento=0, prior=0;
    cria(fila);
    do{
        do{
            menu();
            cin>>op;
        }while(op==0);
        system("cls");
        switch(op){
        case 1:
            cout<<"Elemento: ";
            cin>>elemento;
            cout<<"Qual a prioridade? ";
            cin>>prior;
            insere(fila, elemento, prior);
            cout<<"Elemento inserido com sucesso!"<<endl;
            system("pause");
            break;
        case 2:
            retira(fila);
            cout<<"Elemento retirado com sucesso!"<<endl;
            system("pause");
            break;
        case 3:
            cout<<"Elemento: ";
            cin>>elemento;
            verificaElemento(fila, elemento) ? cout<<"O elemento esta na fila"<<endl : cout<<"O elemento nao esta na fila"<<endl;
            system("pause");
            break;
        case 4:
            mostra(fila);
            system("pause");
            break;
        }
        system("cls");
    }while(op != -1);
    destroi(fila);
    cout<<"Saindo..."<<endl;
    return 0;
}

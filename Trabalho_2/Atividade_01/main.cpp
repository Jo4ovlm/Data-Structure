#include <iostream>
#include "Fila_Estatica_Generica.h"

//Trabalho 2 - Atividade 01 Joao Vitor Loch Martins e Vinicius Hostins Pereira
using namespace std;

int main()
{
    FilaEstaticaGenerica<int, 100> fila;
    int op=0, elemento=0, pos=0, resp=0;
    cria(fila);
    do{
        system("cls");
        cout<<"--------- Menu ---------"<<endl;
        cout<<"1 - Insere"<<endl;
        cout<<"2 - Retira"<<endl;
        cout<<"3 - Verifica elemento"<<endl;
        cout<<"4 - Verifica posicao"<<endl;
        cout<<"5 - Retorna elemento"<<endl;
        cout<<"6 - Retorna posicao"<<endl;
        cout<<"7 - Eh vazia"<<endl;
        cout<<"8 - Tem espaco"<<endl;
        cout<<"9 - Numero de elementos"<<endl;
        cout<<"10 - Mostra fila"<<endl;
        cout<<"-1 - Sair"<<endl;
        cout<<"------------------------"<<endl;
        cout<<"Opcao: ";
        cin>>op;
        system("cls");
        switch(op)
        {
        case 1:
            do{
                cout<<"Inserir em qual extremidade?"<<endl<<"(1)ESQUERDA"<<endl<<"(2)DIREITA"<<endl;
                cin>>resp;
            }while(resp != 1 and resp != 2);
            cout<<"Elemento a ser inserido: ";
            cin>>elemento;
            insere(fila, elemento, resp);
            cout<<"Inserido com sucesso!"<<endl;
            system("pause");
            break;
        case 2:
            do{
                cout<<"Retirar de qual extremidade?"<<endl<<"(1)ESQUERDA"<<endl<<"(2)DIREITA"<<endl;
                cin>>resp;
            }while(resp != 1 and resp != 2);
            retira(fila, resp);
            cout<<"Retirado com sucesso!"<<endl;
            system("pause");
            break;
        case 3:
            cout<<"Elemento a ser verificado: ";
            cin>>elemento;
            existeElemento(fila, elemento) ? cout<<"Elemento esta na lista"<<endl : cout<<"Elemento nao esta na lista"<<endl;
            system("pause");
            break;
        case 4:
            cout<<"Posicao: ";
            cin>>pos;
            posicao(fila, pos) ? cout<<"Posicao valida"<<endl : cout<<"Posicao invalida"<<endl;
            system("pause");
            break;
        case 5:
            cout<<"Posicao: ";
            cin>>pos;
            cout<<"Elemento da posicao "<<pos<<": "<<umElemento(fila, pos)<<endl;
            system("pause");
            break;
        case 6:
            cout<<"Elemento: ";
            cin>>elemento;
            cout<<"Posicao do elemento: "<<elemento<<" : "<< posicao(fila, elemento)<<endl;
            system("pause");
            break;
        case 7:
            (ehVazia(fila)) ? cout<<"Eh vazia"<<endl : cout<<"Nao eh vazia"<<endl;
            system("pause");
            break;
        case 8:
            (temEspaco(fila)) ? cout<<"Tem espaco"<<endl : cout<<"Esta cheia"<<endl;
            system("pause");
            break;
        case 9:
            cout<<"Fila com "<<numeroDeElementos(fila)<<" elementos"<<endl;
            system("pause");
            break;
        case 10:
            mostra(fila);
            cout<<endl;
            system("pause");
            break;
        }
    }while(op != -1);
    cout<<"Saindo...";
    return 0;
}

#ifndef PILHADUPLAMENTEENCADEADA_H_INCLUDED
#define PILHADUPLAMENTEENCADEADA_H_INCLUDED

using namespace std;

template<typename T>
struct nodo
{
    T elemento;
    struct nodo* proximo;
    struct nodo* anterior;
};

template<typename T>
using Nodo = struct nodo<T>;

template<typename T>
struct pilhaDuplamenteEncadeada
{
    int cardinalidade;
    Nodo<T>* base;
    Nodo<T>* topo;
};

template<typename T>
using PilhaDuplamenteEncadeada = struct pilhaDuplamenteEncadeada<T>;

template<typename T>
void cria(PilhaDuplamenteEncadeada<T> &pilha)
{
    pilha.cardinalidade = 0;
    pilha.base = NULL;
    pilha.topo = NULL;
}

template<typename T>
void destroi(PilhaDuplamenteEncadeada<T> &pilha)
{
    Nodo<T>* p;
    while(pilha.base != NULL)
    {
        p = pilha.base;
        pilha.base = pilha.base->proximo;
        delete p;
        p = p->proximo;
    }
    pilha.cardinalidade = 0;
}

template<typename T>
T retornaTopo(PilhaDuplamenteEncadeada<T> pilha)
{
    return pilha.topo->elemento;
}

template<typename T>
void insere(PilhaDuplamenteEncadeada<T> &pilha, T elemento)
{
    Nodo<T>* p = new Nodo<T>;
    p->elemento = elemento;
    p->proximo = NULL;
    p->anterior = NULL;
    if(pilha.cardinalidade == 0)
    {
        pilha.base = p;
        pilha.topo = p;
    }
    else
    {
        p->anterior = pilha.topo;
        pilha.topo->proximo = p;
        pilha.topo = p;
    }
    pilha.cardinalidade++;
}

template<typename T>
void retira(PilhaDuplamenteEncadeada<T> &pilha)
{
    if(pilha.base == NULL)
    {
        cout<<"PILHA VAZIA"<<endl;
        system("pause");
        return;
    }
    Nodo<T>* p = pilha.topo;
    if(pilha.cardinalidade == 1)
    {
        delete p;
        pilha.base = NULL;
        pilha.topo = NULL;
    }
    else
    {
        pilha.topo = p->anterior;
        pilha.topo->proximo = NULL;
        delete p;
    }
    pilha.cardinalidade--;
}

template<typename T>
void mostra(PilhaDuplamenteEncadeada<T> pilha)
{
    if(pilha.cardinalidade == 0)
    {
        cout<<"PILHA VAZIA"<<endl;
        system("pause");
        return;
    }
    Nodo<T>* p = pilha.topo;
    while(p != NULL)
    {
        cout<<p->elemento<<endl;
        p = p->anterior;
    }
}


#endif // PILHADUPLAMENTEENCADEADA_H_INCLUDED

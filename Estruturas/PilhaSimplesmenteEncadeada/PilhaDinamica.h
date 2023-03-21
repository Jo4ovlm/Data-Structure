#ifndef PILHADINAMICA_H_INCLUDED
#define PILHADINAMICA_H_INCLUDED

using namespace std;

template<typename T>
struct nodo
{
    T elemento;
    struct nodo* proximo;
};

template<typename T>
using Nodo = struct nodo<T>;

template<typename T>
struct pilhaDinamica
{
    int cardinalidade;
    Nodo<T>* base;
    Nodo<T>* topo;
};

template<typename T>
using PilhaDinamica = struct pilhaDinamica<T>;

template<typename T>
void cria(PilhaDinamica<T> &pilha)
{
    pilha.cardinalidade = 0;
    pilha.base = NULL;
    pilha.topo = NULL;
}

template<typename T>
void destroi(PilhaDinamica<T> &pilha)
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
T retornaTopo(PilhaDinamica<T> pilha)
{
    return pilha.topo->elemento;
}

template<typename T>
void insere(PilhaDinamica<T> &pilha, T elemento)
{
    Nodo<T>* p = new Nodo<T>;
    p->elemento = elemento;
    p->proximo = NULL;
    if(pilha.cardinalidade == 0)
    {
        pilha.base = p;
        pilha.topo = p;
    }
    else
    {
        pilha.topo->proximo = p;
        pilha.topo = p;
    }
    pilha.cardinalidade++;
}

template<typename T>
void retira(PilhaDinamica<T> &pilha)
{
    if(pilha.base == NULL)
    {
        cout<<"PILHA VAZIA"<<endl;
        system("pause");
        return;
    }
    Nodo<T>* p = pilha.base;
    if(pilha.cardinalidade == 1)
    {
        delete p;
        pilha.base = NULL;
        pilha.topo = NULL;
    }
    else
    {
        while(p->proximo != pilha.topo)
        {
            p = p->proximo;
        }
        Nodo<T>* q = p->proximo;
        p->proximo = NULL;
        pilha.topo = p;
        delete q;
    }
    pilha.cardinalidade--;
}

template<typename T>
void mostra(PilhaDinamica<T> pilha)
{
    if(pilha.cardinalidade == 0)
    {
        cout<<"PILHA VAZIA"<<endl;
        system("pause");
        return;
    }
    Nodo<T>* p = pilha.base;
    while(p != NULL)
    {
        cout<<p->elemento<<endl;
        p = p->proximo;
    }
}

#endif // PILHADINAMICA_H_INCLUDED

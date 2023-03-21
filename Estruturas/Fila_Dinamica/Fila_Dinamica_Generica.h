#ifndef FILA_DINAMICA_GENERICA_H_INCLUDED
#define FILA_DINAMICA_GENERICA_H_INCLUDED

#include <iostream>

using namespace std;

template<typename T>
struct nodo
{
    T elemento;
    int prioridade;
    struct nodo* proximo;
    struct nodo* anterior;
};

template<typename T>
using Nodo = struct nodo<T>;

template<typename T>
struct FilaDinamicaGenerica{
    int cardinalidade;
    Nodo<T> *inicio;
    Nodo<T> *fim;
};

template<typename T>
using FilaDinamicaGenerica = struct FilaDinamicaGenerica<T>;

template<typename T>
void cria(FilaDinamicaGenerica<T> &fila)
{
    fila.cardinalidade = 0;
    fila.inicio = NULL;
    fila.fim = NULL;
}

template<typename T>
void destroi(FilaDinamicaGenerica<T> &fila)
{
    Nodo<T> *p;
    while (fila.inicio != NULL)
    {
        destroiAssociado(fila, p->elemento);
        p = fila.inicio;
        fila.inicio = fila.inicio->proximo;
        delete p;
    }
    fila.cardinalidade = 0;
}


template<typename T>
bool verificaElemento(FilaDinamicaGenerica<T> fila, T elemento)
{
    Nodo<T> *p = fila.inicio;
    while(p != NULL)
    {
        if(p->elemento == elemento)
            return true;
        p = p->proximo;
    }
    return false;
}

template<typename T>
void insere(FilaDinamicaGenerica<T> &fila, T elemento, int prioridade){
    Nodo<T>* q = new Nodo<T>;
    q->elemento = elemento;
    q->prioridade = prioridade;
    q->proximo = NULL;
    q->anterior = NULL;
    if (fila.inicio == NULL){
        fila.inicio = q;
        fila.fim = q
        }else{
            Nodo<T>* p = fila.fim;
            p->proximo = q;
            q->anterior = p;
            fila.fim = q;
        }
    fila.cardinalidade++;
}

template<typename T>
int verificaPrioridade(FilaDinamicaGenerica<T> fila){
    Nodo<T>* p = fila.inicio;
    int maiorPrioridade = 0;
    while(p != NULL){
        if(p->prioridade > maiorPrioridade)
            maiorPrioridade = p->prioridade;
        p = p->proximo;
    }
    return maiorPrioridade;
}

template<typename T>
void retira(FilaDinamicaGenerica<T> &fila){
    if(fila.cardinalidade == 0){
        cout<<"Fila Vazia"<<endl;
        system("pause");
        return;
    }
    int prioridade = verificaPrioridade(fila);
    Nodo<T>* p = fila.inicio;
    while(p != NULL){
        if(p->prioridade == prioridade){
            if(p->proximo == NULL){
                fila.fim = p->anterior;
            }
            p->anterior->proximo = p->proximo;
            p->proximo->anterior = p->anterior;
            delete p;
            fila.cardinalidade--;
            return;
        }
    }
}

template<typename T>
void mostra(FilaDinamicaGenerica<T> fila){
    if(fila.cardinalidade == 0){
        cout<<"Fila Vazia"<<endl;
        system("pause");
        return;
    }
    Nodo<T>* p = fila.inicio;
    while(p != NULL){
        cout<<p->elemento<<" | "<<p->prioridade<<endl;
        p = p->proximo;
    }
    system("pause");
}

#endif // FILA_DINAMICA_GENERICA_H_INCLUDED

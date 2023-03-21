#ifndef LISTADUPLAMENTEENCADEADA_H_INCLUDED
#define LISTADUPLAMENTEENCADEADA_H_INCLUDED
#include <iostream>


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
struct listaSimplesmenteEncadeada
{
    int cardinalidade;
    Nodo<T>* inicio;
    Nodo<T>* fim;
};
template<typename T>
using ListaSimplesmenteEncadeada = struct listaSimplesmenteEncadeada<T>;
// ListaSimplesmenteEncadeada<T> é agora um alias para struct listaSimplesmenteEncadeada<T>
template<typename T>
void cria(ListaSimplesmenteEncadeada<T> &lista)
{
    lista.cardinalidade = 0;
    lista.inicio = NULL;
    lista.fim = NULL;
}
template<typename T>
void destroi(ListaSimplesmenteEncadeada<T> &lista)
{
    Nodo<T> *p;
    while (lista.inicio != NULL)
    {
        p = lista.inicio;
        lista.inicio = lista.inicio->proximo;
        delete p;
    }
    lista.cardinalidade = 0;
}
template<typename T>
bool ehVazia(ListaSimplesmenteEncadeada<T> lista)
{
    return lista.cardinalidade == 0;
}
template<typename T>
int numeroDeElementos(ListaSimplesmenteEncadeada<T> lista)
{
    return lista.cardinalidade;
}
template<typename T>
bool existeElemento(ListaSimplesmenteEncadeada<T> lista, T elemento)
{
    Nodo<T> *p = lista.inicio;
    bool encontrou = false;
    while ((p != NULL) && (! encontrou))
    {
        if (p->elemento == elemento)
            encontrou = true;
        p = p->proximo;
    }
    return encontrou;
}
template<typename T>
bool existePosicao (ListaSimplesmenteEncadeada<T> lista, int posicao)
{
    return ((posicao >= 1) && (posicao <= lista.cardinalidade));
}
template<typename T>
T umElemento(ListaSimplesmenteEncadeada<T> lista, int posicao)
{
    if(posicao < 1 || posicao > lista.cardinalidade)
    {
        throw "POSICAO INVALIDA";
    }
    int contador = 1;
    Nodo<T>* p = lista.inicio;
    while (contador < posicao)
    {
        contador++;
        p = p->proximo;
    }
    return p->elemento;
}
template<typename T>
int posicao(ListaSimplesmenteEncadeada<T> lista, T elemento)
{
    if (!existeElemento(lista, elemento))
    {
        throw "ELEMENTO NAO ESTA NA LISTA";
    }
    int contador = 1;
    Nodo<T>* p = lista.inicio;
    while (p->elemento != elemento)
    {
        contador++;
        p = p->proximo;
    }
    return contador;
}
template<typename T>
void insere(ListaSimplesmenteEncadeada<T> &lista, T elemento, int posicao)
{
    if(posicao < 1 || posicao > lista.cardinalidade + 1)
    {
        throw "POSICAO INVALIDA";
    }
    Nodo<T>* q = new Nodo<T>;
    q->elemento = elemento;
    q->proximo = NULL;
    q->anterior = NULL;
    if (lista.inicio == NULL)
        lista.inicio = q;
    else
    {
        if (posicao == 1)
        {
            q->proximo = lista.inicio;
            lista.inicio = q;
        }
        else if(posicao != lista.cardinalidade + 1)
        {
            Nodo<T>* p = lista.inicio;
            int contador = 1;
            while (contador != posicao - 1)
            {
                p = p->proximo;
                contador++;
            }
            q->proximo = p->proximo;
            p->proximo->anterior = q;
            q->anterior = p;
            p->proximo = q;
        }else{
             Nodo<T>* p = lista.inicio;
            int contador = 1;
            while (contador != posicao - 1)
            {
                p = p->proximo;
                contador++;
            }
            q->proximo = p->proximo;
            q->anterior = p;
            p->proximo = q;
            lista.fim = q;
        }
    }
    lista.cardinalidade++;
}
template<typename T>
void retira (ListaSimplesmenteEncadeada<T> &lista, int posicao)
{
    if(lista.cardinalidade == 0)
    {
        throw "UNDERFLOW";
    }
    if(posicao < 1 || posicao > lista.cardinalidade)
    {
        throw "POSICAO INVALIDA";
    }
    Nodo<T>* q = lista.inicio;
    if (posicao == 1){
        lista.inicio = lista.inicio->proximo;
        lista.inicio->anterior = NULL;}
    else if(posicao != lista.cardinalidade)
    {
        Nodo<T>* p = lista.inicio;
        int contador = 1;
        while (contador != posicao - 1)
        {
            p = p->proximo;
            contador++;
        }
        q = p->proximo;
        q->proximo->anterior = p;
        p->proximo = q->proximo;
    }else{
        Nodo<T>* p = lista.inicio;
        int contador = 1;
        while (contador != posicao - 1)
        {
            p = p->proximo;
            contador++;
        }
        q = p->proximo;
        p->proximo = NULL;
        lista.fim = p;
    }
    delete q;
    lista.cardinalidade--;
}
template<typename T>
void mostra(ListaSimplesmenteEncadeada<T> lista)
{
    for (Nodo<T>* p = lista.inicio; p != NULL; p = p->proximo)
        cout << p->elemento << " ";
    cout << endl;
}


#endif // LISTADUPLAMENTEENCADEADA_H_INCLUDED

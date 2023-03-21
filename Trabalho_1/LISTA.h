#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <iostream>

using namespace std;

template<typename T>
struct nodoDentro{
    T elemento;
    struct nodoDentro* proximo;
};

template<typename T>
using NodoDentro = nodoDentro<T>;

template<typename T>
struct nodo
{
    T elemento;
    int qntMateria;
    NodoDentro<T>* inicio;
    struct nodo* proximo;
};

template<typename T>
using Nodo = struct nodo<T>;

template<typename T>
struct listaSimplesmenteEncadeada
{
    int cardinalidade;
    Nodo<T>* inicio;
};

template<typename T>
using ListaSimplesmenteEncadeada = struct listaSimplesmenteEncadeada<T>;

template<typename T>
void cria(ListaSimplesmenteEncadeada<T> &lista)
{
    lista.cardinalidade = 0;
    lista.inicio = NULL;
}

template<typename T>
void destroi(ListaSimplesmenteEncadeada<T> &lista)
{
    Nodo<T> *p;
    while (lista.inicio != NULL)
    {
        destroiAssociado(lista, p->elemento);
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
int numeroElementos(ListaSimplesmenteEncadeada<T> lista)
{
    return lista.cardinalidade;
}

template<typename T>
bool verificaElemento(ListaSimplesmenteEncadeada<T> lista, T elemento)
{
    Nodo<T> *p = lista.inicio;
    while(p != NULL)
    {
        if(p->elemento == elemento)
            return true;
        p = p->proximo;
    }
    return false;
}

template<typename T>
bool verificaPosicao(listaSimplesmenteEncadeada<T> lista, int posicao)
{
    return ((posicao >= 1) && (posicao <= lista.cardinalidade));
}

template<typename T>
T recuperaElemeto(ListaSimplesmenteEncadeada<T> lista, int posicao)
{
    if(posicao < 1 || posicao > lista.cardinalidade)
    {
        throw "POSICAO INVALIDA";
    }
    int i = 1;
    Nodo<T> *p = lista.inicio;
    while (i < posicao)
    {
        i++;
        p = p->proximo;
    }
    return p->elemento;
}

template<typename T>
int recuperaPosicao(ListaSimplesmenteEncadeada<T> lista, T elemento)
{
    if (!existeElemento(lista, elemento))
    {
        throw "ELEMENTO NAO ESTA NA LISTA";
    }
    int i = 1;
    Nodo<T>* p = lista.inicio;
    while (p->elemento != elemento)
    {
        i++;
        p = p->proximo;
    }
    return i;
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
    if (lista.inicio == NULL)
        lista.inicio = q;
    else
    {
        if (posicao == 1)
        {
            q->proximo = lista.inicio;
            lista.inicio = q;
        }
        else
        {
            Nodo<T>* p = lista.inicio;
            int i = 1;
            while (i != posicao - 1)
            {
                p = p->proximo;
                i++;
            }
            q->proximo = p->proximo;
            p->proximo = q;
        }
    }
    criaAssociado(lista, q->elemento);
    lista.cardinalidade++;
}

template<typename T>
void retira(ListaSimplesmenteEncadeada<T> &lista, T elemento, int posicao)
{
    if(lista.cardinalidade == 0){
        throw "UNDERFLOW";
    }
    if(posicao < 1 || posicao > lista.cardinalidade){
        throw "POSICAO INVALIDA";
    }
    Nodo<T>* q = lista.inicio;
    if (posicao == 1)
        lista.inicio = lista.inicio->proximo;
    else{
        Nodo<T>* p = lista.inicio;
        int contador = 1;
        while (contador != posicao - 1){
            p = p->proximo;
            contador++;
        }
        q = p->proximo;
        p->proximo = q->proximo;
    }
    delete q;
    lista.cardinalidade--;
}

template<typename T>
void mostra(ListaSimplesmenteEncadeada<T> lista)
{
    Nodo<T> *p = lista.inicio;
    while(p != NULL)
    {
        cout<<p->elemento<<endl<<"Materias Matriculadas: "<<endl;
        mostraAssociado(lista, p->elemento);
        p = p->proximo;
    }
}

template<typename T>
void criaAssociado(ListaSimplesmenteEncadeada<T> &lista, T nome){
    bool achou = false;
    Nodo<T> *p = lista.inicio;
    while(p!= NULL and achou == false){
        if (p->elemento == nome){
        if(achou == false) achou = true;
        }
        if(achou == false) p = p->proximo;
    }
    p->qntMateria = 0;
    p->inicio = NULL;
}

template<typename T>
void insereAssociado(ListaSimplesmenteEncadeada<T> &lista, T nome, T materia, int posicao){ // Os parametros em ordem sao, a lista, o nome do aluno que vai cadastrar a materia, o nome da materia, e a posição da lista que a materia vai entrar
    bool achou = false;
    Nodo<T> *p = lista.inicio;
    while(p!= NULL and achou == false){
        if (p->elemento == nome) achou = true;
        if(achou == false) p = p->proximo;
    }
    if(achou == false){
        cout<< "Nao Encontrado";
        system("pause");
    }
    if(posicao < 1 or posicao > p->qntMateria + 1){
        throw "Posicao Invalida";
    }
    NodoDentro<T> *q = new NodoDentro<T>;
    q->elemento = materia;
    q->proximo = NULL;
    if (p->inicio == NULL)
        p->inicio = q;
    else
    {
        if (posicao == 1)
        {
            q->proximo = p->inicio;
            p->inicio = q;
        }
        else
        {
            NodoDentro<T>* r = p->inicio;
            int i = 1;
            while (i != posicao - 1)
            {
                p = p->proximo;
                i++;
            }
            q->proximo = r->proximo;
            r->proximo = q;
        }
    }
    p->qntMateria++;
}


template<typename T>
void retiraAssociado(ListaSimplesmenteEncadeada<T> &lista, T nome, int posicao){ // parametros em ordem sao, nome da lista, nome do aluno de que vai tirar a materia, posicao da materia
    bool achou = false;
    Nodo<T> *p = lista.inicio;
    while(p!= NULL and achou == false){
        if (p->elemento == nome) achou = true;
        if(achou == false) p = p->proximo;
    }
    if(achou == false){
        throw "Nao Encontrado";
    }
    if(posicao < 1 or posicao > p->qntMateria){
        throw "Posicao Invalida";
    }
    if(p->qntMateria == 0){
        throw "UNDERFLOW";
    }
    NodoDentro<T>* q = p->inicio;
    if (posicao == 1)
        p->inicio = p->inicio->proximo;
    else{
        NodoDentro<T>* r = p->inicio;
        int contador = 1;
        while (contador != posicao - 1){
            r = r->proximo;
            contador++;
        }
        q = r->proximo;
        r->proximo = q->proximo;
    }
    delete q;
    p->qntMateria--;
}

template<typename T>
void mostraAssociado(ListaSimplesmenteEncadeada<T> lista, T nome){ // parametros em ordem sao, nome da lista e nome do aluno
    bool achou = false;
    Nodo<T> *p = lista.inicio;
    while(p!= NULL and achou == false){
        if (p->elemento == nome) achou = true;
        if(achou == false)p = p->proximo;
    }
    if(achou == false){
        throw "Nao Encontrado";
    }
    if(p->qntMateria == 0){
        cout<<"Sem materias matriculadas!"<<endl;
        return;
    }
    NodoDentro<T> *q = p->inicio;
    while(q != NULL){
        cout<<q->elemento<<endl;
        q = q->proximo;
    }
}

template<typename T>
bool verificaAssociado(ListaSimplesmenteEncadeada<T> lista, T nome, T elemento)
{
    bool achou = false;
    Nodo<T> *q = lista.inicio;
    while(q!= NULL and achou == false){
        if (q->elemento == nome) achou = true;
        if(achou == false)q = q->proximo;
    }
    if(achou == false){
        throw "Nao Encontrado";
    }
    NodoDentro<T> *p = lista.inicio;
    while(p != NULL)
    {
        if(p->elemento == elemento)
            return true;
        p = p->proximo;
    }
    return false;
}

template<typename T>
int numeroAssociado(ListaSimplesmenteEncadeada<T> lista, T nome)
{
    bool achou = false;
    Nodo<T> *q = lista.inicio;
    while(q!= NULL and achou == false){
        if (q->elemento == nome) achou = true;
        if(achou == false)q = q->proximo;
    }
    if(achou == false){
        throw "Nao Encontrado";
    }
    return q->qntMateria;
}

template<typename T>
void destroiAssociado(ListaSimplesmenteEncadeada<T> &lista, T nome){
    bool achou = false;
    Nodo<T> *p = lista.inicio;
    while(p!= NULL and achou == false){
        if (p->elemento == nome) achou = true;
        if(achou == false)p = p->proximo;
    }
    if(achou == false){
        throw "Nao Encontrado";
    }
    NodoDentro<T> *q;
    while (p->inicio != NULL)
    {
        q = p->inicio;
        p->inicio = p->inicio->proximo;
        delete q;
    }
    p->qntMateria = 0;
}

#endif // LISTA_H_INCLUDED

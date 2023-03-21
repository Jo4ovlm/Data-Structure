#ifndef FILA_ESTATICA_GENERICA_H_INCLUDED
#define FILA_ESTATICA_GENERICA_H_INCLUDED

using namespace std;

template<typename T, int MAX>
struct FilaEstaticaGenerica
{
    int cardinalidade;
    int inicio;
    int fim;
    T elementos [MAX];
};

template<typename T, int MAX>
void cria(FilaEstaticaGenerica<T, MAX> &fila)
{
    fila.cardinalidade = 0;
    fila.inicio = 0;
    fila.fim = 0;
}

template<typename T, int MAX>
bool ehVazia (FilaEstaticaGenerica<T, MAX> fila)
{
    return fila.cardinalidade == 0;
}

template<typename T, int MAX>
bool temEspaco (FilaEstaticaGenerica<T, MAX> fila)
{
    return fila.cardinalidade < MAX;
}

template<typename T, int MAX>
int numeroDeElementos (FilaEstaticaGenerica<T, MAX> fila)
{
    return fila.cardinalidade;
}

template<typename T, int MAX>
bool existeElemento (FilaEstaticaGenerica<T, MAX> fila, T elemento)
{
    int i=0;
    for(i=0;i<fila.cardinalidade;i++){
        if(fila.elementos[i] == elemento)
            return true;
    }
    return false;
}

template<typename T, int MAX>
int existePosicao (FilaEstaticaGenerica<T, MAX> fila, int posicao)
{
    return (posicao >= 1) && (posicao <= fila.cardinalidade);
}

template<typename T, int MAX>
T umElemento (FilaEstaticaGenerica<T, MAX> fila, int posicao)
{
    if(posicao < 1 || posicao > fila.cardinalidade)
    {
        throw "POSICAO INVALIDA";
    }
    for(int i=0;i<fila.cardinalidade;i++){
        if(i == posicao - 1)
            return fila.elementos[i];
    }
}

template<typename T, int MAX>
int posicao(FilaEstaticaGenerica<T, MAX> fila, T elemento) //Retorna posiçao logica
{
    if (!existeElemento(fila, elemento))
    {
        throw "ELEMENTO NAO ESTA NA fila";
    }
    int i;
    for(i=0;i<fila.cardinalidade;i++){
        if(fila.elementos[i] == elemento)
            return i+1;
    }
}

template<typename T, int MAX>
T primeiro (FilaEstaticaGenerica<T, MAX> fila)
{
    return fila.elementos[fila.inicio];
}

template<typename T, int MAX>
T ultimo (FilaEstaticaGenerica<T, MAX> fila)
{
    return fila.elementos[fila.fim];
}

template<typename T, int MAX>
void insere (FilaEstaticaGenerica<T, MAX> &fila, T elemento, int seletor)
{
    if(fila.cardinalidade == MAX)
    {
        throw "OVERFLOW";
    }
    int i;
    if(seletor == 1){
        for(i = fila.cardinalidade; i>0;i--){
            fila.elementos[i] = fila.elementos[i-1];
        }
        fila.elementos[0] = elemento;
    }else{
        fila.elementos[fila.fim] = elemento;
    }
    fila.cardinalidade++;
    fila.fim++;
}

template<typename T, int MAX>
void retira (FilaEstaticaGenerica<T, MAX> &fila, int seletor)
{
    if(fila.cardinalidade == 0)
    {
        throw "UNDERFLOW";
    }
    int i;
    if(seletor == 1){
        for(i=0;i<fila.cardinalidade;i++){
            fila.elementos[i] = fila.elementos[i+1];
        }
    }
    fila.cardinalidade--;
    fila.fim--;
}

template<typename T, int MAX>
void mostra (FilaEstaticaGenerica<T, MAX> fila)
{
    int i;
    for(i=0; i<fila.cardinalidade; i++){
        cout<<fila.elementos[i]<<" ";
    }
}

#endif // FILA_ESTATICA_GENERICA_H_INCLUDED

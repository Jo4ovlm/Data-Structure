#include <iostream>
#include "PilhaDinamica.h"

using namespace std;

int main()
{
    PilhaDinamica<int> numeros;

    cria(numeros);

    insere(numeros, 1);
    insere(numeros, 2);
    mostra(numeros);
    cout<<retornaTopo(numeros)<<endl;
    insere(numeros, 43);
    cout<<retornaTopo(numeros)<<endl;
    retira(numeros);
    cout<<retornaTopo(numeros)<<endl;
    retira(numeros);
    cout<<retornaTopo(numeros)<<endl;
    retira(numeros);
    mostra(numeros);
    destroi(numeros);
    return 0;
}

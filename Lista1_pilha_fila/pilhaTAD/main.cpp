#include <iostream>
using namespace std;

template <typename Agregado, typename Tipo>
concept bool
        PilhaTAD = requires(Agregado a, Tipo t){

    {a.topo()};
    {a.empilha(t)};
    {a.desempilha()};
    {a.topo()};

};

class NoPilha1{
    public:
        char dado;
        NoPilha1 *prox;
};

class PilhaEncadeada{
    public:

    NoPilha1 *pilha;
    int N;


    void cria(){
        this->N = 0;
        this->pilha = 0;
    }

    void empilha(char dado){
        auto *no = new NoPilha1 {.dado = dado, .prox = pilha}; //Malloc vibes c
        pilha = no;
        N++;
    }

    char desempilha(){
        NoPilha1 *aux = this->pilha->prox;
        char retorno = this->pilha->dado;
        delete pilha;
        pilha = aux;
        N--;
        return retorno;
    }

    char topo(){
        return pilha->dado;
    }
};

static_assert(PilhaTAD<PilhaEncadeada, char>);


int main(){


    PilhaEncadeada teste;

    teste.cria();

    teste.empilha('A');
    teste.empilha('B');
    teste.empilha('C');
    teste.empilha('D');

    cout << teste.topo() << endl;

    while(teste.N > 0){
        cout << teste.desempilha() << endl;
    }

}
//Questão 1.b
//Implemente uma estrutura PilhaDeque para tipo ‘char’, utilizando somente um Deque como
//armazenamento interno e mais espaço auxiliar constante:

#include <iostream>
using namespace std;

template<typename Agregado, typename Tipo>
concept bool
        DequeTAD = requires(Agregado a, Tipo t){
    { a.inicio() };
    { a.fim() };
    { a.insereInicio(t) };
    { a.insereFim(t) };
    { a.removeInicio() };
    { a.removeFim() };
};

//capacidade maxima do deque
constexpr int MAXN = 100'000;

class Deque {
public:

    char elementos[MAXN];
    int N;
    int inicioFila, topo ;

// inicializa o deque
//Complexidade: O(1)
    void inicio(){
        this-> N = 0;
        this-> inicioFila = 0;
        this-> topo = 0;
    }

// libera o deque
    void fim(){

    }

//Complexidade: O(1)
    void insereInicio(char dado){
        this->elementos[this->inicioFila] = dado;
        this->inicioFila = (this->inicioFila + 1) % MAXN;
        this->N++;
    }


    //Complexidade: O(1)
    void insereFim(char dado){
        this->elementos[this->topo] = dado;
        this->topo = (this->topo + 1) % MAXN;
        this->N++;
    }
    //Complexidade: O(1)
    char removeInicio(){
        inicioFila = (inicioFila + 1) % MAXN;
        N--;
        return this->elementos[N];
    }

    //Complexidade: O(1)
    char removeFim(){
        this->topo = (MAXN - 1);
        this->N--;
        return elementos[N];
    }
};


template<typename Agregado, typename Tipo>
concept bool
        PilhaTAD = requires(Agregado a, Tipo t)
{
    { a.topo() };
    { a.empilha(t) };
    { a.desempilha() };
};

class PilhaDeque{
public:
    Deque d;

    //Complexidade: O(1)
    void cria (){
        d.N = 0;
        d.inicioFila = 0;
        d.topo = 0;
    }

    void libera (){
        //Nada para liberar
    }

    //Complexidade: O(1)
    char topo(){
        return d.elementos[d.topo-1];
    }

    //Complexidade: O(1)
    void empilha(char data){
        d.insereFim(data);
    }

    //Complexidade: O(1)
    char desempilha(){
        d.removeFim();
    }

};

static_assert(DequeTAD<Deque, char>);
static_assert(PilhaTAD<PilhaDeque, char>);

int main(){

    PilhaDeque pilha;
    pilha.cria();

    pilha.empilha('A');
    cout << pilha.topo() << endl;

    pilha.empilha('B');
    cout << pilha.topo() << endl;

    pilha.empilha('C');
    cout << pilha.topo() << endl << endl;

    //Complexidade: O(n) -- imprime pilha desempilhada
    while (pilha.d.N > 0)
        cout << pilha.desempilha() << endl;

    pilha.libera();

    return 0;
}

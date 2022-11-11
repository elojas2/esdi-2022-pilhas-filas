//QUESTÃO 1.c Implemente uma estrutura FilaDeque para tipo ‘char’, utilizando somente um Deque como
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
constexpr int MAXN = 100'000;

class Deque {
public:

    char elementos[MAXN];
    int N;
    int inicioFila, topo ;

    //Complexidade: O(1)
    void inicio(){
        this-> N = 0;
        this-> inicioFila = 0;
        this-> topo = 0;
    }
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

//=============================================

template<typename Agregado, typename Tipo>
concept bool
    FilaTAD = requires(Agregado a, Tipo t)
{
        { a.inicializa() };
        { a.primeiroFila() };
        { a.enfileira(t) };
        { a.desenfileira() };
};

class FilaDeque{

public:
    Deque d;
    //Complexidade: O(1)
    void inicializa(){
        d.N = 0;
        d.inicioFila = 0;
        d.topo = 0;
    }
    //Complexidade: O(1)
    char primeiroFila(){
        return this->d.elementos[d.inicioFila];
    }
    //Complexidade: O(1)
    void enfileira(char dado){
        this->d.elementos[d.N] = dado;
        this->d.N++;
    }
    //Complexidade: O(1)
    char desenfileira(){
        d.removeInicio();
    }

};
static_assert(DequeTAD<Deque, char>);
//static_assert(PilhaTAD<PilhaDeque, char>);
static_assert(FilaTAD<FilaDeque, char>);

int main(){
    FilaDeque pd;

    pd.inicializa();
    pd.enfileira('A');
    pd.enfileira('B');
    pd.enfileira('C');

    //Testes
    cout <<pd.primeiroFila()<< endl;
    pd.desenfileira();
    cout <<pd.primeiroFila()<< endl;
    pd.desenfileira();
    cout <<pd.primeiroFila()<< endl<<endl;
    pd.desenfileira();

    return 0;
}
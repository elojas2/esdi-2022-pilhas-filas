//QUESTÃO 1.a
//Fila Sequencial 2 -> slide de filas; página 19


#include <iostream>

using namespace std;
template<typename Agregado, typename Tipo>

concept bool
        DequeTAD = requires(Agregado a, Tipo t){
{ a.inicio() };
{ a.libera() };
{ a.insereInicio(t) };
{ a.insereFim(t) };
{ a.removeInicio() };
{ a.removeFim() };
};

    constexpr int MAXN = 100'000;

class Deque {
public:

    //Elementos da fila
    char elementos[MAXN];
    int N; //numero/posicao de elementos da fila
    int inicioFila, topo ; //inicio e final da fila

    //Complexidade: O(1)
    void inicio(){
        this-> N = 0;
        this-> inicioFila = 0;
        this-> topo = 0;
    }

    void libera(){
        //não é dinamico, logo não há o que liberar
    }
    //Complexidade: O(1)
    void insereInicio(char dado){
        //Insere dado no elemento inicio ou fim
        //Metodo circular
        //Incrementa ou decrementa
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
        //circular
        //Decrementa
        //retorna
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
static_assert(DequeTAD<Deque, char>);


int main()
{
    Deque deque;
    deque.inicio();
        //Insere
        deque.insereFim('A');
        deque.insereFim('B');
        deque.insereFim('C');

        //Imprime --- Complexidade: O(n)
        while (deque.N > 0)
            cout << deque.removeFim() << endl;

    return 0;

}
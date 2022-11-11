#include <iostream>
using namespace std;

template<typename Agregado, typename Tipo>
concept bool PilhaTAD = requires(Agregado a, Tipo t){

    { a.topo() };
    { a.empilha(t) };
    { a.desempilha() };
    { a.cria() };
    { a.obterMin() };

};
constexpr int MAXN = 100'000;

class Pilha{
public:

    int elementos[MAXN];
    int N;

    void cria(){
        this->N = 0;
    };
    //Complexidade: O(1)
    int topo(){
        return this->elementos[N-1];
    };

    void empilha(int dado){
        //Complexidade: O(1)
        this->elementos[N] = dado;
        this->N++;
    };

    int desempilha(){
        //Complexidade: O(1)
        this->N--;
        return elementos[N];
    }

    int obterMin(){

        int menor = INT_MAX;

        int cont = N-1;
        //Complexidade: O(n)
        while(cont > 0){
            //Complexidade: O(1)
            if(elementos[cont] < menor){
                menor = elementos[cont];
            }
            //Complexidade: O(1)
            cont--;
        }

        return menor;
    }


};
static_assert(PilhaTAD<Pilha, int>);

int main(){

    Pilha pilha;

    pilha.empilha(2);
    pilha.empilha(10);
    pilha.empilha(1);
    cout << pilha.obterMin() << endl;
    //saída é 1

    return 0;
}
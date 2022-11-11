//QUESTAO 4.c
//Escreva um algoritmo que dada uma pilha P, inverta a ordem dos
//elementos de P. Seu algoritmo deve usar espaço auxiliar constante
//(somente variáveis locais e nenhum vetor extra) e:
//c) uma pilha

#include <queue>
#include <iostream>
#include <stack>
using namespace std;

//O(n)
void inverte(std::stack<char>pilhaPrincipal) {

    //pilhaPrincipal A B C
    std::stack<char> p1;

    //Recebe C B A
    //Complexidade: O(n)
    while(pilhaPrincipal.size()){
        p1.push(pilhaPrincipal.top());
        pilhaPrincipal.pop();
    }

    // A B C
    //Complexidade: O(n)
    while(p1.size()){
        pilhaPrincipal.push(p1.top());
        p1.pop();
    }

    //C B A - IMPRIMIR
    /*while(pilhaPrincipal.size()) {
        cout << pilhaPrincipal.top() << endl;
        pilhaPrincipal.pop();
    }*/

}


int main(){

    std::stack<char> pilha;

    pilha.push('A');
    pilha.push('B');
    pilha.push('C');

    inverte(pilha);

    return 0;

}

/*
#include <queue>
#include <iostream>

using namespace std;
template<typename Agregado, typename Tipo>
concept bool
        PilhaTAD = requires(Agregado a, Tipo t){

    { a.topo() };
    { a.empilha(t) };
    { a.desempilha() };

};

class NoPilha{
public:
    char dado;
    NoPilha *prox;
};

class PilhaEncad{
public:

    NoPilha* inicio;
    NoPilha* fim;

    int N;
//inicia agregado
    void cria (){
        this->N = 0;
        this->inicio = 0;
        this->fim = 0;
    }

    char topo(){
        //cout<< "topo: " << fim->dado << endl;
        //return this->fim->dado;
        return this->inicio->dado;
    }


    void empilha(char v){

        auto *no = new NoPilha{.dado = v, .prox = this->inicio};
        this->inicio = no;
        this->N++;

    }

    char desempilha(){

        NoPilha* p = this->inicio->prox;
        char r = this->inicio->dado;
        delete this->inicio;
        this->inicio = p;
        this->N--;
        return r;
    }

};




static_assert(PilhaTAD<PilhaEncad, char>);

int main(){

    PilhaEncad pilhaPrincipal;
    PilhaEncad pilhaFinal;

    pilhaPrincipal.cria();
    pilhaFinal.cria();

    pilhaPrincipal.empilha('A');
    pilhaPrincipal.empilha('B');
    pilhaPrincipal.empilha('C');

    cout << "topo: " << pilhaPrincipal.topo() << endl;
    pilhaFinal.empilha(pilhaPrincipal.topo());

    cout << "desempilha: " << pilhaPrincipal.desempilha() <<endl;

    pilhaFinal.empilha(pilhaPrincipal.topo());
    cout << "desempilha: " << pilhaPrincipal.desempilha() <<endl;

    pilhaFinal.empilha(pilhaPrincipal.topo());
    cout << "desempilha: " << pilhaPrincipal.desempilha() <<endl;

    //cout << "topo: " << pilhaFinal.topo() << endl;

    while(pilhaFinal.N > 0)
        cout << "pilha: " << pilhaFinal.desempilha() << endl;

    //Fazer o Libera()

    return 0;
}
*/
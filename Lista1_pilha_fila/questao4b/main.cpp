//QUESTAO 4.b
//Escreva um algoritmo que dada uma pilha P, inverta a ordem dos
//elementos de P. Seu algoritmo deve usar espaço auxiliar constante
//(somente variáveis locais e nenhum vetor extra) e:
//b) duas pilha

#include <queue>
#include <iostream>
#include <stack>
using namespace std;

void inverte(std::stack<char>pilhaPrincipal) {

    //pilhaPrincipal A B C
    std::stack<char> p1;
    std::stack<char> p2;

    //Complexidade: O(n)
    while(pilhaPrincipal.size()){
        p1.push(pilhaPrincipal.top()); // C B
        pilhaPrincipal.pop();
    }

    //Complexidade: O(n)
    while(p1.size()){
        p2.push(p1.top());
        p1.pop();
    }

    while(p2.size()){
        pilhaPrincipal.push(p2.top());
        p2.pop();
    }


    while(pilhaPrincipal.size()){
        cout << pilhaPrincipal.top() << endl;
        pilhaPrincipal.pop();
    }

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

    int N;
//inicia agregado
    void cria (){
        this->N = 0;
        this->inicio = 0;
    }

    char topo(){
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
    PilhaEncad pilhaAux;
    PilhaEncad pilhaFinal;

    pilhaPrincipal.cria();
    pilhaAux.cria();
    pilhaFinal.cria();

    pilhaPrincipal.empilha('A');
    pilhaPrincipal.empilha('B');
    pilhaPrincipal.empilha('C');



    pilhaAux.empilha(pilhaPrincipal.topo());
    cout << "desempilha: " << pilhaPrincipal.desempilha() <<endl;
    pilhaAux.empilha(pilhaPrincipal.topo());
    cout << "desempilha: " << pilhaPrincipal.desempilha() <<endl;
    pilhaAux.empilha(pilhaPrincipal.topo());
    cout << "desempilha: " << pilhaPrincipal.desempilha() <<endl;



    pilhaFinal.empilha(pilhaAux.topo());
    cout << "desempilha: " << pilhaAux.desempilha() <<endl;

    pilhaFinal.empilha(pilhaAux.topo());
    cout << "desempilha: " << pilhaAux.desempilha() <<endl;

    pilhaFinal.empilha(pilhaAux.topo());
    cout << "desempilha: " << pilhaAux.desempilha() <<endl;

    while(pilhaFinal.N > 0)
        cout << "pilha: " << pilhaFinal.desempilha() << endl;

    //Fazer o Libera()

    return 0;
}*/
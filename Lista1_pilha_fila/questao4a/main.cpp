//QUESTAO 4.a
//Escreva um algoritmo que dada uma pilha P, inverta a ordem dos
//elementos de P. Seu algoritmo deve usar espaço auxiliar constante
//(somente variáveis locais e nenhum vetor extra) e:
//a) uma fila

#include <queue>
#include <iostream>
#include <stack>
using namespace std;

void inverte(std::stack<char>p) {

    std::queue<char> f;

    //Complexidade: O(n)
    while(p.size()){
        f.push(p.top());
        p.pop();
    }
    //Complexidade: O(n)
    while(f.size()){
        p.push(f.front());
        f.pop();
    }
}


int main(){

    std::stack<char> pilha;

    pilha.push('A');
    pilha.push('B');
    pilha.push('C');


    inverte(pilha);

    while(pilha.size()){
        cout<<pilha.top() << endl;
        pilha.pop();
    }


}

/*

using namespace std;
template<typename Agregado, typename Tipo>
concept bool
        FilaTAD = requires(Agregado a, Tipo t){

    { a.frente() };
    { a.enfileira(t) };
    { a.desenfileira() };

};

class NoFila{
public:
    char dado;
    NoFila *prox;
};

class Fila2P{
public:

    NoFila* inicio;
    NoFila* fim;


    int FilaN;

    void cria (){
        this->FilaN = 0;
        this->inicio = 0;
        this->fim = 0;
    }

    char frente(){
        //return this->inicio->dado;
        return this->fim->dado;
    }


    void enfileira(char v){

        auto *no = new NoFila{.dado = v, .prox = 0};
        if(FilaN == 0)
            inicio = fim = no;
        else{
            fim->prox = no;
            fim = no;
        }
        FilaN++;
    }

    char desenfileira(){

        NoFila* p = this->inicio;
        inicio = inicio->prox;
        //delete this->inicio;
        char r = p->dado;
        delete p;
        FilaN--;
        return r;
    }

};





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
static_assert(FilaTAD<Fila2P, char>);

int main(){

    PilhaEncad p;
    Fila2P fila;
    p.cria();


    p.empilha('A');
    p.empilha('B');
    p.empilha('C');

    //cout << p.topo()<< endl;

    fila.cria();

    //Pilha no topo da fila
    fila.enfileira(p.topo());
    cout << p.desempilha()<<endl;
    fila.enfileira(p.topo());
    cout << p.desempilha()<<endl;
    fila.enfileira(p.topo());
    cout << p.desempilha()<<endl;

    while(fila.FilaN > 0){
        cout << "fila desenfileirada: " << fila.desenfileira() << endl;
    }
    return 0;
}
*/

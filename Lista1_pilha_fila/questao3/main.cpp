//QUESTÃO 3
//Implemente uma estrutura que satisfaz o TAD Fila para o tipo ‘char’ e somente utiliza duas Pilhas como
//armazenamento interno (mais espaço constante):

#include <iostream>
#include <stack>
#include <queue>


using namespace std;

template<typename Agregado, typename Tipo>
concept bool
        FilaTAD = requires(Agregado a, Tipo t){

    { a.enfileira(t) };
    { a.desenfileira() };
    { a.tamanho() };

};

class Fila2P{
public:

    std::stack<char> pilha1;
    std::stack<char> pilha2;

    void enfileira(char data){
        //Complexidade: O(n)
        while(!pilha1.empty()){
            pilha2.push(pilha1.top());
            pilha1.pop();
        }
        pilha1.push(data);

        //Complexidade: O(n)
        while(!pilha2.empty()){
            pilha1.push(pilha2.top());
            pilha2.pop();
        }
    }

    char desenfileira(){

        //Complexidade: O(1)
        if(!pilha1.empty()){
            char r = pilha1.top();
            pilha1.pop();
            return r;
        }

    }

    int tamanho(){
        if(!pilha1.empty())
            return pilha1.size();
    }



};

static_assert(FilaTAD<Fila2P, char>);

int main(){

    Fila2P fila;

    fila.enfileira('A');
    fila.enfileira('B');
    fila.enfileira('C');


    cout << fila.desenfileira() << endl;
    cout << fila.desenfileira() << endl;
    cout << fila.desenfileira() << endl;
    //cout << fila.desenfileira() << endl;

    return 0;

}


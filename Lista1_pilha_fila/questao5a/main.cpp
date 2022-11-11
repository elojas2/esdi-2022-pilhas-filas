//5) Escreva um algoritmo que dada uma fila padrão F externa passada como parâmetro, inverte o conteúdo de
//F. Somente utilize as estruturas extras permitidas como armazenamento externo (mais espaço constante)
//a) Uma Pilha

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void inverte(std::queue<char> f){

    std::stack<char> pilha;

    //Complexidade: 0(n)
    while(f.size()){
        pilha.push(f.front());
        f.pop();
    }

    //Complexidade: O(n)
    while(pilha.size()){
        f.push(pilha.top());
        pilha.pop();
    }

    //Imprime
    /*while(f.size()){
        cout<< f.front() << endl;
        f.pop();

    }*/

}

int main(){

    std::queue<char> fila;
    fila.push('A');
    fila.push('B');
    fila.push('C');
    fila.push('D');
    fila.push('E');

    inverte(fila);

    return 0;

}
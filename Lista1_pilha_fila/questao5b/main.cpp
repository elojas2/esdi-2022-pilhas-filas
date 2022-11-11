//5.b
//dada fila F inverte F usando duas filas auxiliares

#include<iostream>
#include<queue>
using namespace std;

void inverte(std::queue<char> f){

    std::queue<char> fila1;
    std::queue<char> fila2;

    //Complexidade: O(n²)
    while(true){
        int tamanho = f.size();

        //Complexidade: O(1)
        if (tamanho != 0) {
            //Complexidade: O(n)
            for (int i = 0; i < tamanho - 1; i++) {
                fila1.push(f.front());
                f.pop();
            }
            fila2.push(f.front());
            f.pop();
        }else{
            break;
        }

        int tamanho2 = fila1.size();
        //Complexidade: O(1)
        if (tamanho2 != 0) {
            //Complexidade: O(n)
            for (int i = 0; i < tamanho2 - 1; i++) {
                f.push(fila1.front());
                fila1.pop();
            }
            fila2.push(fila1.front());
            fila1.pop();
        } else {
            break;
        }
    }

    while(fila2.size() > 0){
        cout << fila2.front() << endl;
        fila2.pop();
    }
}

int main(){

    std::queue<char>fila;
    fila.push('A');
    fila.push('B');
    fila.push('C');

    inverte(fila);

return 0;
}

/*
count_vetor = 1;
polones = 0;
topo = 0;


enquanto count_vetor ≤ fim faça
    se expressao[count_vetor] é operando então
        polones = polones + 1
        pol[count_polones] := expressao[count_vetor]

        senão se expressao[count_vetor] é operador então
            topo = topo+1
            pilha[topo] = expressao[count_vetor]
        se não se expressao[count_vetor] = ")" então:
                se topo != 0 então
                operador = pilha[topo]
                        topo = topo - 1;
                        count_polones = count_polones + 1;
                        pol[count_polones] = operador
                se não "expressao errada"
    count_vetor = count_vetor + 1




 topo := topo + 1
 pilha[ topo ] := exp[ count_vetor ]
 senão se exp[ count_vetor ] = ")" então
 se topo ≠ 0 então
 operador := pilha[ topo ]
 topo := topo - 1
polones := polones


*/

#include <iostream>
//Implementação de Fila
using namespace std;

template<typename Agregado, typename Tipo>
concept bool

    FilaTAD = requires(Agregado a, Tipo t){
    {a.cria()};
    {a.fronte()};
    {a.enfileirar(t)};
    {a.desenfileirar()};
    {a.imprime()};
};

class Fila{
public:
    char dado;
    Fila *prox;
};

class FilaEncadeada{
public:

    Fila *inicio;
    Fila *fim;
    int N;

    void cria(){
        this->inicio = 0;
        this->fim = 0;
        this->N = 0;
    }
    char fronte(){
        return inicio->dado;
    }

    void enfileirar(char dado){
        Fila *no = new Fila{.dado = dado, .prox = 0};
        if(this->N == 0){ //se não tiver nenhum dado na fila o inicio e o fim serão o mesmo
            inicio = fim = no;
        }else{ //Se já tiver algum dado na fila
            fim->prox = no; //prox do fim irá receber o local de memória que foi armazenado
            fim = no; //fim recebe o dado
        }
        N++;
    }

    char desenfileirar(){
        Fila *f = this->inicio; //Recebe o inicio
        inicio = inicio->prox;  //recebe o prox dado que se tornará o novo inicio
        char r = f->dado;
        delete f;
        N--;
        return r;
    }

    void imprime(){
        int count = N - 1;
        printf("%c\n", this->inicio->dado);

        while(count > 0){

                Fila *f = inicio->prox;
                printf("%c\n", f->dado);
                inicio = inicio->prox;

            count--;
        }
    }

};

static_assert(FilaTAD<FilaEncadeada, char>);



int main() {

    FilaEncadeada teste;
    teste.cria();

    teste.enfileirar('a');
    teste.enfileirar('b');
    teste.enfileirar('c');
    teste.imprime();
    teste.imprime();

    /*cout << teste.fronte() << endl;
    while(teste.N > 0){
        cout<<teste.desenfileirar() << endl;
    }*/

}

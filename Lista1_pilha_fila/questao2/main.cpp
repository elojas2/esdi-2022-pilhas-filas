#include <iostream>
#include <queue>

using namespace std;
template<typename Agregado, typename Tipo>
concept bool
        PilhaTAD = requires(Agregado a, Tipo t)
{
    { a.topo() };
    { a.empilha(t) };
    { a.desempilha() };
};
class Pilha {
    std::queue<char> fila1;
    std::queue<char> fila2;

public:
    //Complexidade: O(1)
    char topo()
    {
        //Complexidade: O(1)
        if (!fila1.empty())
            return fila1.front();
    }

    void empilha(char data)
    {
        fila2.push(data);
        //Complexidade: O(n)
        while (!fila1.empty()) {
            fila2.push(fila1.front());
            fila1.pop();
        }
        std::queue<char> f = fila1;
        fila1 = fila2;
        fila2 = f;
    }

    void desempilha()
    {
        //Complexidade: O(1)
        if (!fila1.empty()){
            fila1.pop();
        }
    }

};

static_assert(PilhaTAD<Pilha, char>);

int main()
{
    Pilha p;
    p.empilha('A');
    p.empilha('B');
    p.empilha('C');

    cout << p.topo() << endl;
    p.desempilha();
    cout << p.topo() << endl;
    p.desempilha();
    cout << p.topo() << endl;
    return 0;
}
//Estudo de Arvore binária
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int info;
    struct node *left, *right;

}Node;

Node* insertNewVersionTwo(Node *root, int value){
    if(root == NULL){
        Node *new = (Node *) malloc(sizeof(Node));
        new->info = value;
        new->left = NULL;
        new->right = NULL;
        return new;
    }else{
        if(value < root->info){
            root->left = insertNewVersionTwo(root->left, value);
        }
        if(value > root->info){
            root->right = insertNewVersionTwo(root->right, value);
        }
        return root;
    }
}

Node* insertNewVersion(Node *root, int value){
    //Verifica se é null
    if(root == NULL){
        //caso seja, se cria um novo node -> malloca memória nova
        Node *new = (Node *) malloc(sizeof(Node));
        //Insere o valor desejado e atribue null para os nós esquerdo e direito e retorna logo em seguida
        new->info = value;
        new->left = NULL;
        new->right = NULL;
        return new;
    }else{
        //caso já exista, verifica se o valor é maior ou menor que o valor já inserido anterior
        if(value < root->info){
            root->left = insertNewVersion(root->left, value);
        }
        if(value > root->info){
            root->right = insertNewVersion(root->right, value);
        }
        return root;
    }
}

void write(Node *root){

    if(root != NULL) {
        write(root->left);
        printf("%d ", root->info);
        write(root->right);

    }
}

Node* copy(Node *c){

    if(c == NULL){
        return NULL;
    }
    Node *new = (Node *) malloc(sizeof(Node));
    new->info = c->info;
    new->left = copy(c->left);
    new->right = copy(c->right);
    return new;
}

int lenght(Node *root){
    if(root == NULL){
        return 0;
    }else{
        return 1 + lenght(root->left) + lenght(root->right);
    }

}

Node *mirrored(Node *root){

    if(root == NULL){
        return NULL;
    }
    Node *mirror = (Node*) malloc(sizeof (Node));
    mirror->info = root->info;
    mirror->left = mirrored(root->right);
    mirror->right = mirrored(root->left);
    return mirror;

}

//Maior num
Node *higherNum(Node *root){

    //Os maiores valores estão na direita

    if((root != NULL) && (root->right > root->info )) {
        root->info = higherNum(root->right);
    }
    return root->info;
}

//Menor num
Node* smallestNum(Node *root){
    if((root != NULL) && (root->left < root->info)){
        root->info = smallestNum(root->left);
    }
    return root->info;
}

//Search arvore
int search(Node *root, int key){

    if(root == NULL){
        return 0;
    }else{
        if(root->info == key){
            return 1;
        }else{

            if(key < root->info){
                return search(root->left, key);
            }else{
                return search(root->right, key);
            }
        }
    }
}

int quantidadeNodes(Node *root){

    if(root == NULL){
        return 0;
    }
    else if(root->left == NULL && root->right == NULL) {
        return 1;

    }else{
        return quantidadeNodes(root->left) + quantidadeNodes(root->right);
    }

}
//delete
Node *delete(Node*root, int key){

    if(root == NULL){
        return NULL;
    }else{

        if(root->info == key){
            //remove nós folhas
            if(root->left == NULL && root->right == NULL){
                free(root);
                return NULL;
            }else{
                //remove nós que possuem apenas 1 filho
                if(root->left == NULL || root->right == NULL){
                    Node* aux;
                    if(root->left != NULL)
                        aux = root->left;
                    else
                        aux = root->right;
                    free(root);
                    return aux;
                }else{
                    Node *aux = root->left; //Aponta para a subarvore da esquerda

                    //While para pegar o maior resultado a direita da subarvore da esquerda
                    while(aux->right != NULL){
                        aux = aux->right;
                    }
                    root->info = aux->info;
                    aux->info = key;
                    root->left = delete(root->left, key);
                    return root;
                }
            }
        }
        else{

            if(key < root->info){
                root->left = delete(root->left, key);
            }else{
                root->right = delete(root->right,key);
            }

            return root;
        }
    }
}


//Q10) Escreva uma função em C para testar se uma árvore é zigue-zague, isto é, se todos
//       os nós internos possuem exatamente uma sub-árvore vazia: int zz(TAB *a)

int zz(Node *root){

    int zigue = 0;

    if(root == NULL) return 0;

    if(root->left != NULL && root->right != NULL){
        return 0;
    }
    else if(root->right == NULL && root->left != NULL){
        zigue = 1;
        zz(root->left);
    }else if(root->left == NULL  && root->right != NULL){
        zigue = 1;
        zz(root->right);

    }
    return zigue;
}

//Verifica se as arvores são iguais
int iguais(Node *rootA, Node *rootB){

    if((rootA == NULL) && (rootB == NULL)) {
        return 1;
    }

    else if((rootA != NULL) && (rootB == NULL)){
        return 0;
    }else if((rootA == NULL) && (rootB != NULL)){
        return 0;
    }else{


        if(rootA->info == rootB->info && iguais(rootA->left, rootB->left) && iguais(rootA->right, rootB->right)){
            return 1;
        }else{
            return 0;
        }
    }
}

//Retira numeros pares
Node *retira_pares(Node *root){

    if(root == NULL) return 0;

    if((root->info % 2 ) == 0){
        return retira_pares(delete(root, root->info));
    }

    root->left = retira_pares(root->left);
    root->right = retira_pares(root->right);

    return root;

}

//É uma arvore binaria
int ehbin(Node *root){

    int bin = 0;
    if(root == NULL) return 0;

    if(root->left != NULL && root->right != NULL){
        bin = 1;
        ehbin(root->right);
        ehbin(root->left);

    }else if(root->left && root->right){
        bin = 1;
    }else{
        bin = 0;
    }
    return bin;
}


//Questões lista 2
//3.(a) Escreva um algoritmo para computar a soma das folhas
int somaDaArvore(Node* root){
    if(root == NULL)
        return 0;
    return (root->info + somaDaArvore(root->left) + somaDaArvore(root->right));
}

//(b) Pós-Ordem
void posOrdem(Node* root){

    if(root == NULL)
        return;

    posOrdem(root->left);
    posOrdem(root->right);
    printf("%d ", root->info);


}

//(c)Em-Ordem
void emOrdem(Node* root){

    if(root == NULL)
        return;

    emOrdem(root->left);
    printf("%d ", root->info);
    emOrdem(root->right);
}

//(d)Pre Ordem
void preOrdem(Node* root){

    if(root == NULL)
        return;

    printf("%d ", root->info);
    preOrdem(root->left);
    preOrdem(root->right);
}
//(e) Altura de um dado nó


Node* buscarNo(Node* root, int value){

    if(root == NULL)
        return NULL;
    else{
        if(root->info == value)
            return root;
        else{
            if(value < root->info)
                return buscarNo(root->left, value);
            else
                return buscarNo(root->right, value);
        }
    }
}


int altura(Node* root){
    if(root == NULL || root->left == NULL && root->right == NULL)
        return 0;
    else{
        int altura_esquerda = altura(root->left) + 1;
        int altura_direita = altura(root->right) + 1;

        if(altura_esquerda > altura_direita)
            return altura_esquerda;
        else
            return altura_direita;
    }
}

int alturaArv(Node *root, int value){

    Node *node = buscarNo(root, value);
    if(node){
        return altura(node);
    }else
        return -1;
}
//(f)fator de balanceamento dado um nó

int balanceamento(Node *root){
    if(root){
        return altura(root->right) - altura(root->left);
    }else{
        return 0;
    }

}


//(g) Escreva um algoritmo para percorrer a árvore em níveis

int nivel(Node* root){
    if(!root)
        return 0;
    else{
        int altura_esquerda = nivel(root->left);
        int altura_direita = nivel(root->right);

        if(altura_esquerda >= altura_direita)
            return altura_esquerda+1;
        else
            return altura_direita+1;
    }
}



void percorreNiveis(Node* root, int nivel){

    if(root == NULL)
        return;
    if(nivel == 0)
        printf("%d -> ", root->info);
    else{
        percorreNiveis(root->left, nivel - 1);
        percorreNiveis(root->right, nivel - 1);
    }
}

void escreveEmNivel(Node* root){

    int altura1 = nivel(root);

    for(int i = 0; i < altura1; i++) {
        printf("Nivel %d: ", i);
        percorreNiveis(root, i);
        printf("\n");
    }
}



//3.(h) Escreva um algoritmo para computar o produto dos nós
int produto(Node* root){
    if(root == NULL)
        return 1;
    return (root->info * produto(root->left) * produto(root->right));
}


int main() {

    Node *mirror = NULL;
    Node *clone = NULL;
    Node *root = NULL;
    Node *root1 = NULL;

    int op;
    int value;
    int zero = 0;
    int quant = 0;

    do{

        printf("\n---------------MENU---------------\n");
        printf("\n0 - Exit\n1 - Insert\n2 - Show Binary Tree\n3 - Insert a second binary tree \n4 - Mirror Binary Tree\n"
               "5 - Higher number  \n6 - Smallest number\n7 - Delete\n8 - Search\n9 - Compare binary trees\n10 - Copy\n11 - Nodes\n12 - Zigue\n13 - "
               "Its binary\n14 -  Retira pares\n15 - Soma dos elementos da arvore\n16 - Produto dos elementos da arvore\n17 - Percorre em nivel"
               "\n18 - Balanceamento\n19 - Print em ordem\n20 - Print pos ordem\n21 - Print pre orden\n22 - Altura de um no especifico\n");
        printf("Choice a number: ");
        printf("\n");
        scanf("%d", &op);

        switch(op){

            case 0:
                printf("Leaving....\n Bye!\n");
                break;
            case 1:
                printf("\nWrite a number to insert in binary tree, pls:");
                scanf("%d", &value);
                root = insertNewVersion(root, value);
                break;
            case 2:
                write(root);
                printf("\n");
                printf("Size: %d\n", lenght(root));
                break;
            case 3:
                printf("\nWrite a number to insert in second binary tree, pls:");
                scanf("%d", &value);
                root1 = insertNewVersionTwo(root, value);
                break;

            case 4:
                mirror = mirrored(root);
                printf("Mirror binary tree:\n");
                write(mirror);
                break;
            case 5:
                printf("The largest number in binary tree: %d\n", higherNum(root));
                break;
            case 6:
                printf("The smallest number in binary tree: %d\n", smallestNum(root));
                break;

            case 7:
                printf("Choice a number to delete: ");
                scanf("%d", &value);
                root = delete(root, value);
                printf("\nNumber deleted!!!\n");
                break;

            case 8:
                printf("Choice a number to search in binary tree: ");
                scanf("%d", &value);
                int result = search(root, value);
                if(result == 0)
                    printf("\nSorry, not found in binary tree, try other number!:D\n");
                else
                    printf("\nNumber found!!!\n:D\n");
                break;

            case 9:
                zero = iguais(root, root1);

                if(zero == 0){
                    printf("Not yet\n");
                }else{
                    printf("Yes, are the same tree\n");
                }
                break;

            case 10:
                clone = copy(root);
                printf("Clone binary tree:\n");
                write(clone);
                break;

            case 11:
                quant = quantidadeNodes(root);
                printf("Quantidade: %d\n", quant);
                break;

            case 12:
                zero = zz(root);
                if(zero == 1){
                    printf("Eh zigue zague\n");
                }else{
                    printf("Nao eh zigue zague\n");
                }
                break;
            case 13:
                zero = ehbin(root);
                if(zero == 0) printf("Nao eh binaria\n");

                else printf("Eh binaria\n");

                break;
            case 14:
                root = retira_pares(root);
                write(root);
                printf("\n\n");

                break;
            case 15:

                write(root);
                printf("\nsoma: %d\n", somaDaArvore(root));
                printf("\n\n");

                break;

            case 16:
                write(root);
                printf("\nProduto: %d\n", produto(root));
                printf("\n\n");

                break;

            case 17:
                write(root);
                printf("\n");
                escreveEmNivel(root);

                break;

            case 18:
                write(root);
                printf("\n");
                balanceamento(root);

                break;
            case 19:
                emOrdem(root);
                printf("\n");
                break;
            case 20:
                posOrdem(root);
                printf("\n");

                break;
            case 21:
                preOrdem(root);
                printf("\n");

                break;
            case 22:
                printf("escolha o no: ");
                int i = 0;
                scanf("%d", &i);
                printf("\n%d", alturaArv(root, i));
                printf("\n");
                break;

            case 23:
                printf("%d", balanceamento(root));
                printf("\n");

                break;

            default:
                printf("Invalid option ;(\n");
        }

    }while(op != 0 );


    return 0;
}


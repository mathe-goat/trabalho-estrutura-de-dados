#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define TAM_MAX 50000

int tamanho;

typedef struct _lista {
    int vetor[TAM_MAX];
    int fim;
} Lista;

typedef struct _retornolista {
    Lista lista;
    int elemento;
} RetornoLista;

Lista inicializar() {
    Lista l;
    l.fim = 0;
    return l;
}

int estaVazia(Lista l) {
    return (l.fim == 0);
}

int estaCheia(Lista l) {
    return (l.fim == TAM_MAX);
}

Lista inserir(Lista l, int elemento) {
    if (estaCheia(l)) {
        printf("\nLista cheia!");
    } else {
        l.vetor[l.fim] = elemento;
        l.fim++;
    }
    return l;
}

RetornoLista remover(Lista l, int posicao) {
    RetornoLista r;
    if (estaVazia(l) || posicao < 0 || posicao >= l.fim) {
        printf("\nPosicao invalida ou lista vazia!");
        r.elemento = -1;
        r.lista = l;
    } else {
        r.elemento = l.vetor[posicao];
        for (int i = posicao; i < l.fim - 1; i++) {
            l.vetor[i] = l.vetor[i + 1];
        }
        l.fim--;
        r.lista = l;
    }
    return r;
}

void imprimir(Lista l) {
    if (estaVazia(l)) {
        printf("\nLista vazia!");
    } else {
        printf("\nLista: ");
        for (int i = 0; i < l.fim; i++) {
            printf("%d ", l.vetor[i]);
        }
    }
}

int numeroAleatorio(int low, int high) {
    int k;
    double d;
    d = (double) rand () / ((double) tamanho + 1);
    k = d * (high - low + 1);
    return low + k;
}

int obterDado() {
    return numeroAleatorio(0, tamanho);
}

void exibirDado(int p) {
    printf("\nElemento: %i", p);
}

int main() {
    Lista l;
    RetornoLista ret;
    double start, finish, elapsed;
    int quantidade;
    int opcao, val;

    printf("Digite a quantidade de elementos para testar: ");
    scanf("%d", &quantidade);
    tamanho = quantidade;

    do {
        printf("\n--- MENU LISTA ---\n");
        printf("1. Inserir\n");
        printf("2. Remover (da posicao 0)\n");
        printf("3. Imprimir\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                l = inicializar();
                start = (double) clock();
                for (int i = 0; i < quantidade; i++) {
                    val = obterDado();
                    l = inserir(l, val);
                    exibirDado(val);
                }
                finish = (double) clock();
                elapsed = finish - start;
                printf("\nForam utilizados %.2f clocks", elapsed);
                break;

            case 2:
                l = inicializar();
                for (int i = 0; i < quantidade; i++) {
                    l = inserir(l, obterDado());
                }

                start = (double) clock();
                for (int i = 0; i < quantidade; i++) {
                    ret = remover(l, 0);
                    l = ret.lista;
                    val = ret.elemento;
                    exibirDado(val);
                }
                finish = (double) clock();
                elapsed = finish - start;
                printf("\nForam utilizados %.2f clocks", elapsed);
                break;

            case 3:
                l = inicializar();
                for (int i = 0; i < quantidade; i++) {
                    l = inserir(l, obterDado());
                }

                start = (double) clock();
                imprimir(l);
                finish = (double) clock();
                elapsed = finish - start;
                printf("\nForam utilizados %.2f clocks", elapsed);
                break;

            case 4:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }
    } while(opcao != 4);

    return 0;
}
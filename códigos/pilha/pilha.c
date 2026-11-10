#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define TAM_MAX 50000

int tamanho;

typedef struct _pilha {
    int vetor[TAM_MAX];
    int topo;
} Pilha;

typedef struct _retornopilha {
    Pilha pilha;
    int elemento;
} RetornoPilha;

Pilha inicializar() {
    Pilha p;
    p.topo = -1;
    return p;
}

int estaVazia(Pilha p) {
    return (p.topo == -1);
}

int estaCheia(Pilha p) {
    return (p.topo == TAM_MAX - 1);
}

Pilha inserir(Pilha p, int elemento) {
    if (estaCheia(p)) {
        printf("\nPilha cheia!");
    } else {
        p.topo++;
        p.vetor[p.topo] = elemento;
    }
    return p;
}

RetornoPilha remover(Pilha p) {
    RetornoPilha r;
    if (estaVazia(p)) {
        printf("\nPilha vazia!");
        r.elemento = -1;
        r.pilha = p;
    } else {
        r.elemento = p.vetor[p.topo];
        p.topo--;
        r.pilha = p;
    }
    return r;
}

void imprimir(Pilha p) {
    if (estaVazia(p)) {
        printf("\nPilha vazia!");
    } else {
        printf("\nPilha (topo para base): ");
        for (int i = p.topo; i >= 0; i--) {
            printf("%d ", p.vetor[i]);
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
    Pilha p;
    RetornoPilha ret;
    double start, finish, elapsed;
    int quantidade;
    int opcao, val;

    printf("Digite a quantidade de elementos para testar: ");
    scanf("%d", &quantidade);
    tamanho = quantidade;

    do {
        printf("\n--- MENU PILHA ---\n");
        printf("1. Inserir (Empilhar)\n");
        printf("2. Remover (Desempilhar)\n");
        printf("3. Imprimir\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                p = inicializar();
                start = (double) clock();
                for (int i = 0; i < quantidade; i++) {
                    val = obterDado();
                    p = inserir(p, val);
                    exibirDado(val);
                }
                finish = (double) clock();
                elapsed = finish - start;
                printf("\nForam utilizados %.2f clocks", elapsed);
                break;

            case 2:
                p = inicializar();
                for (int i = 0; i < quantidade; i++) {
                    p = inserir(p, obterDado());
                }
                
                start = (double) clock();
                for (int i = 0; i < quantidade; i++) {
                    ret = remover(p);
                    p = ret.pilha;
                    val = ret.elemento;
                    exibirDado(val);
                }
                finish = (double) clock();
                elapsed = finish - start;
                printf("\nForam utilizados %.2f clocks", elapsed);
                break;

            case 3:
                p = inicializar();
                for (int i = 0; i < quantidade; i++) {
                    p = inserir(p, obterDado());
                }

                start = (double) clock();
                imprimir(p);
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
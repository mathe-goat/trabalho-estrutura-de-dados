#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define TAM_MAX 50000

int tamanho;

typedef struct _fila {
    int vetor[TAM_MAX];
    int inicio;
    int fim;
    int total;
} Fila;

typedef struct _retornofila {
    Fila fila;
    int elemento;
} RetornoFila;

Fila inicializar() {
    Fila f;
    f.inicio = 0;
    f.fim = 0;
    f.total = 0;
    return f;
}

int estaVazia(Fila f) {
    return (f.total == 0);
}

int estaCheia(Fila f) {
    return (f.total == TAM_MAX);
}

Fila inserir(Fila f, int elemento) {
    if (estaCheia(f)) {
        printf("\nFila cheia!");
    } else {
        f.vetor[f.fim] = elemento;
        f.fim++;
        f.total++;
    }
    return f;
}

RetornoFila remover(Fila f) {
    RetornoFila r;
    if (estaVazia(f)) {
        printf("\nFila vazia!");
        r.elemento = -1;
        r.fila = f;
    } else {
        r.elemento = f.vetor[f.inicio];
        for (int i = 0; i < f.fim - 1; i++) {
            f.vetor[i] = f.vetor[i + 1];
        }
        f.fim--;
        f.total--;
        r.fila = f;
    }
    return r;
}

void imprimir(Fila f) {
    if (estaVazia(f)) {
        printf("\nFila vazia!");
    } else {
        printf("\nFila: ");
        for (int i = 0; i < f.fim; i++) {
            printf("%d ", f.vetor[i]);
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
    Fila f;
    RetornoFila ret;
    double start, finish, elapsed;
    int quantidade;
    int opcao, val;

    printf("Digite a quantidade de elementos para testar: ");
    scanf("%d", &quantidade);
    tamanho = quantidade;

    do {
        printf("\n--- MENU FILA ---\n");
        printf("1. Inserir (Enfileirar)\n");
        printf("2. Remover (Desenfileirar)\n");
        printf("3. Imprimir\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                f = inicializar();
                start = (double) clock();
                for (int i = 0; i < quantidade; i++) {
                    val = obterDado();
                    f = inserir(f, val);
                    exibirDado(val);
                }
                finish = (double) clock();
                elapsed = finish - start;
                printf("\nForam utilizados %.2f clocks", elapsed);
                break;

            case 2:
                f = inicializar();
                for (int i = 0; i < quantidade; i++) {
                    f = inserir(f, obterDado());
                }

                start = (double) clock();
                for (int i = 0; i < quantidade; i++) {
                    ret = remover(f);
                    f = ret.fila;
                    val = ret.elemento;
                    exibirDado(val);
                }
                finish = (double) clock();
                elapsed = finish - start;
                printf("\nForam utilizados %.2f clocks", elapsed);
                break;

            case 3:
                f = inicializar();
                for (int i = 0; i < quantidade; i++) {
                    f = inserir(f, obterDado());
                }

                start = (double) clock();
                imprimir(f);
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
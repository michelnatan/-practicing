#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

#define TAM 31
#define TAMFILA 100

// CRIANDO A ESTRUTURA DO AVIÃO
struct aviao {
    char prefixo[TAM];
    char nome[TAM];
    char cia[TAM];
};
typedef struct aviao TipoAviao;

// CRIANDO A ESTRUTURA DA FILA DE AVIÕES
struct filaaviao {
    TipoAviao avioes[TAMFILA];
    int inicio;
    int fim;
    int tam;
};
typedef struct filaaviao TipoFilaAviao;

/* INICIALIZA FILA */
TipoFilaAviao inicializar(TipoFilaAviao fila) {
    fila.inicio = 0;
    fila.fim = 0;
    fila.tam = -1;
    return fila;
}

/* VERIFICA SE A FILA ESTÁ VAZIA */
int estaVazia(TipoFilaAviao fila) {
    if (fila.tam == -1)
        return TRUE;
    else
        return FALSE;
}

/* INSERINDO UM AVIÃO NA FILA */
TipoFilaAviao entraFila(TipoAviao aviao, TipoFilaAviao fila) {
    if (fila.tam < TAMFILA)
        fila.avioes[fila.fim++] = aviao;
    else
        printf("Overflow !!!\n");
    fila.tam++;
    return fila;
}

/* REMOVENDO UM AVIÃO DA FILA */
TipoFilaAviao saiFila(TipoFilaAviao fila) {
    if (estaVazia(fila))
        printf("Fila Vazia !!!");
    else
        printf("Avião que saiu da fila: %s\n", fila.avioes[fila.inicio++].prefixo);
    fila.tam--;
    return fila;
}

void imprimir(TipoFilaAviao fila) {
    int i = fila.inicio;
    printf("FILA ATUAL\n");
    while (i < fila.fim)
        printf("%s\n", fila.avioes[i++].prefixo);
}

int main () {
    TipoFilaAviao fila;
    TipoAviao aviao;
    fila = inicializar(fila);

    strcpy(aviao.prefixo, "A");strcpy(aviao.nome, "AA");strcpy(aviao.cia, "AAA");
    fila = entraFila(aviao, fila);
    imprimir(fila);
    getchar();

    strcpy(aviao.prefixo, "B");strcpy(aviao.nome, "BB");strcpy(aviao.cia, "BBB");
    fila = entraFila(aviao, fila);
    imprimir(fila);
    getchar();

    strcpy(aviao.prefixo, "C");strcpy(aviao.nome, "CC");strcpy(aviao.cia, "CCC");
    fila = entraFila(aviao, fila);
    imprimir(fila);
    getchar();

    fila = saiFila(fila);
    imprimir(fila);
    getchar();

    strcpy(aviao.prefixo, "D");strcpy(aviao.nome, "DD");strcpy(aviao.cia, "DDD");
    fila = entraFila(aviao, fila);
    imprimir(fila);

    fila = saiFila(fila);
    imprimir(fila);
    getchar();

    fila = saiFila(fila);
    imprimir(fila);
    getchar();

    fila = saiFila(fila);
    imprimir(fila);
    getchar();

    fila = saiFila(fila);
    getchar();
    imprimir(fila);

    getchar();
    return 0;
}

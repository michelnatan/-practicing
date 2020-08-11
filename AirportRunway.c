#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define TAM 30
#define QTD 5

struct aviao
{
    char prefixo[TAM];
    char nome[TAM];
    char cia[TAM];
};
typedef struct aviao TipoAviao;

struct fila
{
    TipoAviao p[TAM];
    int primeiro;
    int ultimo;
    int tam;
};
typedef struct fila TipoFila;

TipoFila inicializar(TipoFila fila);
TipoFila le_aviao (TipoAviao aviao,TipoFila fila);
TipoAviao insere_aviao (TipoAviao aviao);
TipoFila qtd_aviao(TipoFila fila);
TipoFila imprimir (TipoFila fila);
TipoFila decolar (TipoFila fila);

int main()
{
    TipoFila fila;
    TipoAviao aviao;
    int menu;
    char continuar = 'S';

    fila = inicializar(fila);

    while(continuar == 's' || continuar == 'S')
    {
    printf("\t## MENU ##\n\n");
    printf("(1) Adicionar aviao a pista de decolagem\n");
    printf("(2) Verificar quantidade de avioes aguardando na pista\n");
    printf("(3) Autorizar a decolagem do primeiro aviao da fila\n");
    printf("(4) Listar os dados de todos os avioes que estao na pista de decolagem\n");

    printf("\nQual opcao voce deseja ?");
    scanf("%d",&menu);
    fflush(stdin);

    system("cls");

    switch (menu)
    {
        case 1:
            fila = le_aviao(aviao,fila);
            break;
        case 2:
            qtd_aviao(fila);
            break;
        case 3:
            fila = decolar(fila);
            break;
        case 4:
            imprimir(fila);
            break;

    }

    printf("Deseja voltar ao menu ?\t (S/s - Sim | N/n - Nao) ");
    scanf("%s",&continuar);
    fflush(stdin);

    system("cls");

    }

}
// Iniciando a Fila
TipoFila inicializar(TipoFila fila)
{
    fila.primeiro = 0;
    fila.ultimo = 0;
    fila.tam = -1;
    return fila;
}

/*
// Verifica se a Fila esta Vazia
int estaVazia(TipoFila fila)
{
    if (fila.primeiro == -1)
        return TRUE;
    else
        return FALSE;
}
*/

// Inserindo Aviao na Pista
TipoFila le_aviao (TipoAviao aviao,TipoFila fila)
{
    int aux=0;
    if(fila.ultimo < QTD ){
        aux = fila.ultimo;
    }
        if (fila.ultimo == QTD)
        {
            if(fila.ultimo == fila.primeiro)
            {
                aux = fila.ultimo;
            }
            else
            {
                aux = 0;
            }
        }
        if(aux != fila.primeiro || fila.tam == -1)
        {
            fila.ultimo = aux;
            aviao = insere_aviao(aviao); // Chama Funcao para Usuario Preencher os Dados do Aviao
            fila.p[fila.ultimo++] = aviao;
            fila.tam++;
            aux++;
        }
        else
        {
            printf("Overflow !!!\n\n");
        }
    return fila;
}
// Inserindo Dados do Aviao
TipoAviao insere_aviao (TipoAviao aviao)
{
    printf("PREFIXO: ");
    scanf("%[^\n]",aviao.prefixo);
    fflush(stdin);
    printf("NOME: ");
    scanf("%[^\n]",aviao.nome);
    fflush(stdin);
    printf("CIA: ");
    scanf("%[^\n\n]",aviao.cia);
    fflush(stdin);
    return aviao;
}
// Verifica quantidade de avioes da fila
TipoFila qtd_aviao(TipoFila fila)
{
    int i;
    if(fila.tam >= 0)
    {
        i = fila.tam;
        printf("\n%d avioes estao aguardando na pista de decolagem no momento\n\n", ++i);
    }
    else
    {
        printf("\nA pista de decolagem esta vazia\n\n");
    }
    return fila;
}
// Imprime Fila de Avioes
TipoFila imprimir (TipoFila fila)
{
    int i = -1;
    int aux = fila.primeiro;
    int aux2 = fila.primeiro;

    if(fila.tam == -1 )
    {
        printf("\nA pista de decolagem esta vazia\n\n");
    }
    else
    {
        while (i < fila.tam)
        {
            if(fila.primeiro == QTD)
            {
                aux = 0;
            }
            if(aux != fila.primeiro || fila.tam != -1 )
            {
                    fila.primeiro = aux;
                    i++;
                    printf("#%d\t Prefixo: %s\tNome: %s\tCia: %s\n\n",i+1,fila.p[fila.primeiro].prefixo,fila.p[fila.primeiro].nome,fila.p[fila.primeiro].cia);
                    fila.primeiro++;
                    aux++;
            }
        }
    }
}
// Libera a Decolagem do Primeiro Aviao da Fila
TipoFila decolar (TipoFila fila)
{
    int aux=0;
    int i = fila.primeiro;
    if (fila.tam == -1)
    {
        printf("\nFila Vazia !!!\n\n");
    }
    else
    {
        if(fila.primeiro < QTD)
        {
            aux = fila.primeiro;
        }
        if(fila.primeiro == QTD)
        {
            aux = 0;
        }
        if(aux != fila.ultimo || fila.tam != -1 )
        {
            fila.primeiro = aux;
            printf("Aviao decolando...\n#%d\t Prefixo: %s\tNome: %s\tCia: %s\n\n",i+1,fila.p[fila.primeiro].prefixo,fila.p[fila.primeiro].nome,fila.p[fila.primeiro].cia);
            fila.primeiro++;
            fila.tam--;
            aux++;
            if(fila.tam == -1)
            {
                fila.primeiro = 0;
                fila.ultimo = 0;
                fila.tam = -1;
            }
        }
    }
    return fila;
}



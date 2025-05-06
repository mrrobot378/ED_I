#include <stdio.h>
#include <stdlib.h>

    typedef struct no
    {
        char c;
        struct no *prox;
    }No;
    
    void push(No** topo, char dado)
    {
        No* novo_no = malloc(sizeof(No));
        if (novo_no)
        {
            novo_no->c = dado;
            novo_no->prox = *topo;
            *topo = novo_no;
        }else
        {
            printf("Alocacao mal sucedida!!");
        }
    }

    void imprimir_invertido(No *topo)
    {   
        if (topo != NULL)
        {
            printf("Sequencia invertida: ");
        No* atual = topo;
        while(atual != NULL)
        {    
        printf(" %c", atual->c);
        atual = atual->prox;
        }
        }else
        {
            printf("\nPilha vazia!!\n");
        }
        
        
    }


int main()
{
    No* topo = NULL;
    int opcao;
    char entrada;

    do
    {   printf("\n\t0 - Sair\n\t1 - Empilhar\n\t2 - Imprimir inverso\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
           printf("Digite o caractere que deseja empilhar: ");
           getchar();
           scanf("%c", &entrada);
           push(&topo,entrada);
            break;
        case 2:
           imprimir_invertido(topo);
            break;
        default:
            printf("\nOpcao invalida!!\n");
            break;
        }

    }while(opcao != 0);

    No *atual = topo;
    No *proximo;
    while (atual != NULL) {
        proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
    topo = NULL;

    return 0;
}
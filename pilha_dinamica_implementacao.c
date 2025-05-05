#include <stdio.h>
#include <stdlib.h>

    typedef struct no
    {
        int valor;
        struct no *prox;
    }No;

    void push(No **topo,int n)
    {
        No *novo_no = malloc(sizeof(No));
        if (novo_no)
        {
            novo_no->valor = n;
            novo_no->prox = *topo;
            *topo = novo_no;
        }
    }

    No* pop(No **topo)
    {
        if(*topo)
        {   
            No *remover = *topo;
            *topo = remover->prox;
            return remover;
        }else
        {
            printf("\nSem valores para desempilhar!!\n");
        }
    }

    void imprimir(No *topo)
    {
        if(topo)
        {
            printf("\n---------- PILHA ----------\n");
           
            while(topo)
            {
                printf("%d ", topo->valor);
                topo = topo->prox;
            } 
            printf("\n---------- FIM PILHA ----------\n");
        }else
        {
            printf("\nPilha vazia!!\n");
        }
    }

int main()
{
    No *remover;
    No *topo = NULL;
    int opcao,valor;

    do
    {
        printf("\n0 - Sair\n1 - Empilhar\n2 - Desempilhar\n3 - Imprimir\n");
        scanf("%d",&opcao);
        getchar();

        switch (opcao)
        {
        case 1:
            printf("\nDigite o valor a ser empilhado: ");
            scanf("%d", &valor);
            push(&topo,valor);
            break;
        case 2:
           remover = pop(&topo);
            if(remover)
            {
                printf("\nElemento removido com sucesso!\n");
                printf("%d", remover->valor);
            }else
            {
                printf("Sem no a remover!!");
            }
            break;
        case 3:
            imprimir(topo);
            break;    
        
        default:
            break;
        }

    } while (opcao != 0);
    

    return 0;
}

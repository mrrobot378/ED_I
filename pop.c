#include <stdio.h>
#include <stdlib.h>

    typedef struct No
    {
        int dado;
        struct No *prox;
    }No;
    
    No* desempilhar(No **topo)
    {
        if(*topo)
        {
            No *remover = *topo;
            *topo = remover->prox;
            return remover;
        }else
        {
            printf("Pilha vazia!");
            return NULL;
        }
    }

int main()
{
    No *remover, *topo = NULL;
    int opcao;
    scanf("%d", &opcao);
    
    switch(opcao)
    {
        case 1:
        remover = desempilhar(&topo);
        if (remover)
        {
            printf("%d",remover->dado);
        }else
        {
            printf("\nSem no a remover\n");
        }
    }
    
    return 0;
}

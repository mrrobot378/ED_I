/*Faça uma pilha*/

#include <stdio.h>
#include <stdlib.h>

    typedef struct no
    {
        int dado;
        struct no *prox;
    }No;
    
    No* push(No *topo)
    {
        No *novo_no = malloc(sizeof(No));
        
        if(novo_no)
        {
            novo_no->dado = 5;
            novo_no->prox = topo;
            return novo_no;
        }else
        {
            printf("Erro ao alocar memória!");
            return NULL;
        }
    }

int main()
{
    No *topo = NULL;
    int opcao;
    scanf("%d", &opcao);
    
    switch(opcao)
    {
        case 1:
        topo = push(topo);
    }
    
    printf("%d",topo->dado);
    printf("\n%p",topo->prox);

    return 0;
}

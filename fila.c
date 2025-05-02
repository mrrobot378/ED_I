#include <stdio.h>
#include <stdlib.h>

    typedef struct no
    {
        int dado;
        struct no *prox;
    }No;
    
    void inserir_na_fila(No **fila, int valor)
    {
        No *aux, *novo = malloc(sizeof(No));

        if(novo)
        {
            novo->dado = valor;
            novo->prox = NULL;
            if (*fila == NULL)
            {
                *fila = novo;
            }else
            {
                aux = *fila;
                while (aux->prox)
                {
                    aux = aux->prox;
                }
                aux->prox = novo;
            }

        }else{
            printf("Erro ao alocar memoria\n");
        }

    }

    No *remover_da_fila(No **fila)
    {
        No *remover = NULL;

        if (*fila)
        {   
            remover = *fila;
            *fila = remover->prox;
        }else
        {
            printf("A fila esta vazia, nenhum elemento removido!");
        }
        return remover;
    }

    void imprimir_fila(No *fila)
    {

        if (fila)
        {
            printf("\t------- FILA --------\n\t");
            while(fila)
            {
                printf("%d ", fila->dado);
                fila = fila->prox; 
            }
            printf("\n\t------- FIM FILA --------\n");
        }

    }

    int main(){
        No *r, *fila = NULL;
        int opcao, valor;
    
        do{
            printf("\t0 - Sair\n\t1 - Inserir\n\t2 - Remover\n\t3 - Imprimir\n");
            scanf("%d", &opcao);
    
            switch(opcao){
            case 1:
                printf("Digite um valor: ");
                scanf("%d", &valor);
                inserir_na_fila(&fila, valor);
                break;
            case 2:
                r = remover_da_fila(&fila);
                if(r){
                    printf("Removido: %d\n", r->dado);
                    free(r);
                }
                break;
            case 3:
                imprimir_fila(fila);
                break;
            default:
                if(opcao != 0)
                    printf("\nOpcao invalida!\n");
            }
    
        }while(opcao != 0);
    
        return 0;
    }
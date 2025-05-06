/*
    Implementação tabela hash com lista encadeada
*/

#include <stdio.h>
#include <stdlib.h>

    #define TAM 19 //5 elementos = 10 * 2 = 20, 19 primo mais próximo de 20

    typedef struct no
    {
        int dado;
        struct no *prox;
    }No;
    
    typedef struct lista
    {
        No* inicio;
        int tamanho;
    }Lista;
    
    int funcaoHash(int valor)
    {
        return valor % TAM;
    }
    
    void inicializar_lista(Lista *l)
    {
        l->inicio = NULL;
        l->tamanho = 0;
    }
    
    void inicializar_tabela(Lista tabela[])
    {
        for (int i = 0; i < TAM; i++)
        {
            inicializar_lista(&tabela[i]);
        }
    }
    
    void inserir_na_lista(Lista *l,int valor)
    {
        No* novo_no = malloc(sizeof(No));
        if (novo_no)
        {
            novo_no->dado = valor;
            novo_no->prox = l->inicio;
            l->inicio = novo_no;
            l->tamanho++;
        }
    }
    
    void inserir_na_tabela(Lista tabela[], int valor)
    {
        int id = funcaoHash(valor);
        inserir_na_lista(&tabela[id],valor);
    }
    
    int buscar_na_lista(Lista *l,int valor)
    {
        No* aux = l->inicio;
        while(aux != NULL && aux->dado != valor)
        {
            aux = aux->prox;
        }
        if(aux->dado == valor)
            {
                return aux->dado;
            }else{
                 return 0;
            }
       
    }
    
    int buscar_na_tabela(Lista tabela[], int valor)
    {
        int id = funcaoHash(valor);
        return buscar_na_lista(&tabela[id],valor);
    }
    
    void imprimir_lista(Lista *l)
    {
        No *aux = l->inicio;
        while(aux != NULL)
        {
            printf("%d ", aux->dado);
            aux = aux->prox;
        }
    }
    
    void imprimir_tabela(Lista *tabela)
    {
        for(int i = 0; i < TAM; i++)
        {
            printf("\nIndice: %d, Lista: ", i);
            imprimir_lista(&tabela[i]);
            printf("\n");
        }
    }

int main()
{
    Lista tabela[TAM];
    int opcao,retorno,valor;
    
    inicializar_tabela(tabela);
    
      do
    {
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Buscar\n\t3 - Imprimir\n");
        scanf("%d", &opcao);
        
        switch(opcao)
        {
        case 1:
            printf("\nDigite o valor a ser adicionado na tabela: ");
            scanf("%d", &valor);
            inserir_na_tabela(tabela, valor);
            break;
        case 2:
            printf("\nDigite o valor a ser procurado na tabela: ");
            scanf("%d", &valor);
            retorno = buscar_na_tabela(tabela, valor);
            if (retorno != 0)
            {
                printf("\nValor encontrado: %d!\n", retorno);
            }else{
                printf("\nValor não encontrado na tabela!\n");
            }
            break;
        case 3:
            imprimir_tabela(tabela);
            break;    
        }
        
    }while(opcao != 0);

    return 0;
}
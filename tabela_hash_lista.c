#include <stdio.h>
#include <stdlib.h>

    #define TAM 19

    typedef struct no
    {
        int chave;
        struct no *prox;
    }No;

    typedef struct lista
    {
        No *inicio;
        int tam;
    }Lista;

    

    int funcaoHash(int chave)
    {
        return chave % TAM;
    }

    void inicializar_lista(Lista *l)
    {
        l->inicio = NULL;
        l->tam = 0;
    }

    void inicializar_tabela(Lista tabela[])
    {
        for (int i = 0; i < TAM; i++)
            inicializar_lista(&tabela[i]);
    }

    void inserir_na_lista(Lista *l, int valor)
    {
        No *novo_no = malloc(sizeof(No));
        if(novo_no)
        {
            novo_no->chave = valor;
            novo_no->prox = l->inicio;
            l->inicio = novo_no;
            l->tam++;
        }else{
            printf("\nErro ao alocar memoria!\n");
        }
    }

    void inserir_na_tabela(Lista tabela[], int valor)
    {
        int id = funcaoHash(valor);
        inserir_na_lista(&tabela[id],valor);
    }

    int buscar_na_lista(Lista *l, int valor)
    {
        No *aux = l->inicio;
        while (aux != NULL && aux->chave != valor)
        {
            aux = aux->prox;
        }
        if(aux)
        {
            return aux->chave;
        }else
        {
            return 0;
        }
    }

    int buscar_na_tabela(Lista tabela[], int valor)
    {
        int id = funcaoHash(valor);
        printf("\nIndice gerado: %d\n", id);
        return buscar_na_lista(&tabela[id],valor);
    }

    void imprimir_lista(Lista *l)
    {
        No *aux = l->inicio;
        printf(" Tamanho da lista: %d ", l->tam);
        while (aux)
        {
            printf("%d ", aux->chave);
            aux = aux->prox;
        }
    }

    void imprimir(Lista tabela[])
    {
        for(int i = 0; i < TAM; i++)
        {
            printf("%2d = ", i);
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

        switch (opcao)
        {
        case 1:
            printf("\tInsira o valor a ser inserido: ");
            scanf("%d",&valor);
            inserir_na_tabela(tabela,valor);
            break;
        case 2:
            printf("\tInsira o valor a ser buscado: ");
            scanf("%d",&valor);
            retorno = buscar_na_tabela(tabela,valor);
            if(retorno != 0)
            {
                printf("\tValor encontrado: %d\n", retorno);
            }else{
                printf("\tValor nao encontrado\n");
            }
            break;
        case 3:
            imprimir(tabela);
            break;
        
        default:
            printf("Opcao invalida!");
            break;
        }

    } while (opcao != 0);

    return 0; 
}
#include <stdio.h>
#include <stdlib.h>

    #define TAM 31

    void inicializar_tabela(int t[]){
        int i;

        for (i = 0; i < TAM; i++)
            t[i] = 0;
    }

    int funcaoHash(int chave){
        return chave % TAM;
    }

    void inserir(int t[],int valor)
    {
        int id = funcaoHash(valor);
        while (t[id] != 0) //0 indica que a posição está vazia
        {
             id = funcaoHash(id + 1);
        }    
        t[id] = valor; 
    }

    int busca(int t[],int chave)
    {
        int id = funcaoHash(chave);
        while(t[id] != 0){
            if (t[id] == chave)
            {
                return t[id];
            }else
            {
                id = funcaoHash(id + 1);
            }
        }
        return 0;
    }

    void imprimir(int t[])
    {
        for(int i = 0; i < TAM; i++)
        {
            printf("%d = %d\n", i, t[i]);
        }
    }


int main()
{
    int tabela[TAM], opcao,retorno,valor;

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
            inserir(tabela,valor);
            break;
        case 2:
            printf("\tInsira o valor a ser buscado: ");
            scanf("%d",&valor);
            retorno = busca(tabela,valor);
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
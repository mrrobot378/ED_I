/*
    Escreva uma rotina que receba uma lista e retorne duas listas onde uma possui os valores impares e
    a outra os valores pares da lista.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int dado;
    struct No* prox;
} No;


void detectar_impar_par(No* lista, No* lista_impar, No* lista_par)
{
    No* atual_par = lista_par;
    No* atual_impar = lista_impar;

    while (lista != NULL)
    {
        if ((lista->dado) % 2 == 0)
        {
            atual_par->dado = lista->dado;
            atual_par->prox = (No*)malloc(sizeof(No));
            atual_par = atual_par->prox;
        } else if ((lista->dado % 2 != 0))
        {
            atual_impar->dado = lista->dado;
            atual_impar->prox = (No*)malloc(sizeof(No));
            atual_impar = atual_impar->prox;
        }
        lista = lista->prox;
    }
    // Marcar o final das listas
    if (atual_par != NULL) {
        atual_par->prox = NULL;
    }
    if (atual_impar != NULL) {
        atual_impar->prox = NULL;
    }
}

void imprimir_lista(No* lista)
{
    printf("\n--- Lista ---\n");
    while (lista != NULL)
    {
        printf("%d\n", lista->dado);
        lista = lista->prox;
    }
    printf("-------------\n");
}

void liberar_lista(No* lista)
{
    No* atual = lista;
    No* proximo;
    while (atual != NULL)
    {
        proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
}

int main()
{
    No* lista = (No*)malloc(sizeof(No));
    if (lista == NULL) return 1;
    lista->dado = 2;
    lista->prox = (No*)malloc(sizeof(No));
    if (lista->prox == NULL) { free(lista); return 1; }
    lista->prox->dado = 5;
    lista->prox->prox = (No*)malloc(sizeof(No));
    if (lista->prox->prox == NULL) { free(lista->prox); free(lista); return 1; }
    lista->prox->prox->dado = 6;
    lista->prox->prox->prox = (No*)malloc(sizeof(No));
    if (lista->prox->prox->prox == NULL) { free(lista->prox->prox); free(lista->prox); free(lista); return 1; }
    lista->prox->prox->prox->dado = 7;
    lista->prox->prox->prox->prox = NULL;

    No* lista_par = (No*)malloc(sizeof(No));
    if (lista_par == NULL) { liberar_lista(lista); return 1; }
    No* lista_impar = (No*)malloc(sizeof(No));
    if (lista_impar == NULL) { liberar_lista(lista); free(lista_par); return 1; }

    detectar_impar_par(lista, lista_impar, lista_par);

    printf("Lista Original:\n");
    imprimir_lista(lista);

    printf("\nLista de Pares:\n");
    imprimir_lista(lista_par);

    printf("\nLista de Ímpares:\n");
    imprimir_lista(lista_impar);

    liberar_lista(lista);
    liberar_lista(lista_par);
    liberar_lista(lista_impar);

    return 0;
}

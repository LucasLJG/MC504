#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

void* encontrarPalavra(void* palavra){
    printf("Lucas, se calma !!!\n%i\n", (char*) palavra);
}

// declaracao das variaveis globais:
char matriz[6][6];
int tamanhoMatriz = 6;
int quantidadePalavras;

// funcao para inicializar as variaveis:
char*  initialize () {
    // Pega o numero de palavras para fazer o array.
    printf("Digite a quantidade de palavras a ser encontradas:\n");
    scanf("%d", &quantidadePalavras);
    // Pega as palvras e guarda em um vetor.
    char palavras[quantidadePalavras][tamanhoMatriz];
    printf("Digite as palavras do caça-palavras:\n");
    for(int i = 0; i < quantidadePalavras; i ++){
        scanf("%s", palavras[i]);
    }
    printf("Digite as letras da matriz:\n");
    for(int i = 0; i < 5; i ++){
        scanf("%s", matriz[i]);
        printf("OI");
    }
    printf("OI");
    return palavras;
}

// Funcao Main 
int main(){
    int* ptr;
    char* palavras;

    // Inicializa a matriz e o vetor com palavras e retorna a quantidade de palavras.
    palavras = initialize();
    printf("OI");
    // Cria as threads
    pthread_t id[quantidadePalavras];
    for(int i = 0; i < quantidadePalavras; i ++)
    {
        pthread_create(&id[i], NULL, encontrarPalavra, (void*) palavras[i]);
    }
    for(int i = 0; i < 5; i ++)
    {
        pthread_join(id[i], (void**)&ptr);
    }
    return 0;
}
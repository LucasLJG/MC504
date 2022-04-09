#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_SIZE 25

char matriz[MAX_SIZE][MAX_SIZE], palavras[MAX_SIZE][MAX_SIZE];
int tamanhoMatriz, quantidadePalavras;

void initialize(){
    printf("BEM-VINDO AO JOGO DE CACA-PALAVRAS\nDigite o tamanho N da matriz NxN: ");
    
    //Contstruir a matriz
    scanf("%d", &tamanhoMatriz);

    printf("\nDigite as linhas da matriz:\n");
    for(int i = 0; i < tamanhoMatriz; i ++){
        scanf("%s", matriz[i]);
    }

    //Construir o vetor de palavras buscadas
    printf("\nDigite a quantidade de palavras a ser encontradas:\n");
    scanf("%d", &quantidadePalavras);

    printf("\nDigite as palavras do caça-palavras:\n");
    for(int i = 0; i < quantidadePalavras; i ++){
        scanf("%s", palavras[i]);
    }
}

void* encontrarPalavra(void* arg){

    char* palavra = (char*) arg;
    int palavraEncontrada = 0;
    int i, j; //contadores

    for(i = 0; i < tamanhoMatriz; i++){ //Para cada linha da matriz
        for(j = 0; j < tamanhoMatriz; j++){ //Para cada coluna da matriz

            if(palavra[0] == matriz[i][j]){ //Se a primeira letra for encontrada
                if(palavra[1] == matriz[i - 1][j]){ //Se a segunda letra for encontrada acima (Norte)
                    
                    palavraEncontrada = 1;
                    
                    for (int m = 0; m < strlen(palavra); m++)
                        if (palavra[m] != matriz[i - m][j])
                                palavraEncontrada = 0;
                    
                    if (palavraEncontrada)
                        break; 
                }

                if (palavra[1] == matriz[i + 1][j]){ //Se a segunda letra for encontrada abaixo (Sul)
                        
                    palavraEncontrada = 1;
                        
                    for (int m = 0; m < strlen(palavra); m++)
                        if (palavra[m] != matriz[i + m][j])
                            palavraEncontrada = 0; 
                        
                    if (palavraEncontrada)
                        break;    
                }

                if (palavra[1] == matriz[i][j + 1]){ //Se a segunda letra for encontrada a direita (Leste)
                    
                    palavraEncontrada = 1;
                    
                    for (int m = 0; m < strlen(palavra); m++)
                        if (palavra[m] != matriz[i][j + m])
                            palavraEncontrada = 0;
                    
                    if (palavraEncontrada)
                        break;
                }
                
                if (palavra[1] == matriz[i][j - 1]){ //Se a segunda letra for encontrada a esquerda (Oeste)
                    
                    palavraEncontrada = 1;

                    for (int m = 0; m < strlen(palavra); m++)
                        if (palavra[m] != matriz[i][j - m])
                            palavraEncontrada = 0;

                    if (palavraEncontrada)
                        break;
                }

                if (palavra[1] == matriz[i - 1][j + 1]) { // A segunda letra é encontrada no sentido (Nordeste)
                    
                    palavraEncontrada = 1;
                    
                    for (int m = 0; m < strlen(palavra); m++)
                        if (palavra[m] != matriz[i - m][j + m])
                            palavraEncontrada = 0;
                    
                    if (palavraEncontrada)
                        break;
                }
                
                if (palavra[1] == matriz[i - 1][j - 1]) { // A segunda letra é encontrada no sentido (Noroeste)
                    
                    palavraEncontrada = 1;
                    
                    for (int m = 0; m < strlen(palavra); m++)
                        if (palavra[m] != matriz[i - m][j - m])
                            palavraEncontrada = 0;
                    
                    if (palavraEncontrada)
                        break;
                }
                
                if (palavra[1] == matriz[i + 1][j + 1]) { // A segunda letra é encontrada no sentido (Sudeste)
                    
                    palavraEncontrada = 1;
                    
                    for (int m = 0; m < strlen(palavra); m++)
                        if (palavra[m] != matriz[i + m][j + m])
                            palavraEncontrada = 0;
                    
                    if (palavraEncontrada)
                        break;
                }

                if (palavra[1] == matriz[i + 1][j - 1]) { // A segunda letra é encontrada no sentido (Sudoeste)
                    
                    palavraEncontrada = 1;
                    
                    for (int m = 0; m < strlen(palavra); m++)
                        if (palavra[m] != matriz[i + m][j - m])
                            palavraEncontrada = 0;
                    
                    if (palavraEncontrada)
                        break;
                }
            }
        }

        if (palavraEncontrada)
            break;
    }

    if (palavraEncontrada)
        printf("%s - PALAVRA ENCONTRADA\n", palavra);
    else
        printf("%s - PALAVRA NAO ENCONTRADA\n", palavra);
}

int main(){

    initialize();
    
    // Cria as threads
    pthread_t threads[quantidadePalavras];

    for(int i = 0; i < quantidadePalavras; i ++)
    {
        pthread_create(&threads[i], NULL, encontrarPalavra, palavras[i]);
    }
    for(int i = 0; i < quantidadePalavras; i ++)
    {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
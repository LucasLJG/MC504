#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

void* leitura_de_dados(void* arg){
    do {
    
   // Leitores desejam entrar na area critica.
   wait(mutex);

   // contador do numero de leitores é incrementado em 1
   contador_de_leitores++;                          

   // Se tiver pelo menos um leitor na area critica, então nenhum escritor poderá entrar, portanto, a preferência fica com o leitor.
   if (contador_de_leitores == 1)     
      wait(wrt);                    

   // enquanto esse leitor atual está dentro da area critica, outros leitores conseguem entrar tambem.
   signal(mutex);                   

   // o leitor atual realiza a leitura
   wait(mutex);   // um leitor deseja sair 

   contador_de_leitores--;

   // Nenhum leitor é deixado na area critica
   if (contador_de_leitores == 0) 
       signal(wrt);         // escritores estao autorizados a entrar

   signal(mutex); // leitor sai da area critica

    } while(true);
}

void* escrita_de_dados(void* arg){
    do {
    // escritores solicitam a entrada na area critica.
    wait(wrt);  
   
    // realiza a escrita

    // saida da area critica
    signal(wrt);

    } while(true);
}





int main(){
    sem_t mutex, wrt;
    int contador_de_leitores;
    char[];
    for(int i = 0; i < 10; i++){
        
    }
    pthread_t threads[6];
    for(int i = 0; i < 2; i++){
        pthread_create(&threads[i], NULL, escrita_de_dados ,); // escrita dos dados
    }
    for(int i = 2; i < 6; i++){
        pthread_create(&threads[i], NULL, leitura_de_dados, ); // leitura dos dados
    }
    for(int i = 0; i < 6; i++){
        pthread_join(threads[i], NULL);
    }
    return 0;
}
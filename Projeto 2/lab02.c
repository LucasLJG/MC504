#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include <stdbool.h> 

char matriz[20][72] = {"O importante não é vencer todos os dias, mas lutar sempre.",
 "Maior que a tristeza de não haver vencido é a vergonha ...!", 
 "É melhor conquistar a si mesmo do que vencer mil batalhas.", 
 "Quem ousou conquistar e saiu pra lutar, chega mais longe!", 
 "Enquanto houver vontade de lutar haverá esperança de vencer.",
 "Difícil é ganhar um amigo em uma hora ...",
 "O medo de perder tira a vontade de ganhar.",
 "Aquele que não tem confiança nos outros ...", 
 "Escolher o seu tempo é ganhar tempo.",
 "Perder para a razão, sempre é ganhar.", 
 "Arriscamo-nos a perder quando queremos ganhar demais.",
 "Muitos sabem ganhar dinheiro, mas poucos sabem gastá-lo.", 
 "Se você pretende ser rico, pense em economizar tanto quanto em ganhar.",
 "O homem digno ganha para viver; o menos honesto vive para ganhar.",
 "Para ganhar aquilo que vale a pena ter ...",
 "A maior caridade é habilitar o pobre a ganhar a sua vida.", 
 "O mundo está perdido para aqueles que o querem ganhar.", 
 "Quem sabe o que se pode ganhar num dia jamais furta.", 
 "Loteria: acho que, jogando ou não, você tem a mesma chance de ganhar",
 "A avareza perde tudo ao pretender ganhar tudo."}; 
char nuvem[20][72]; // matriz que receberá as frases dos escritores
int contador_de_leitores;
sem_t mutex, wrt; // declaracao dos semaforos

void* leitura_de_dados(void* arg){
    do {
    
   // Leitores desejam entrar na area critica.
   sem_wait(&mutex);

   // contador do numero de leitores é incrementado em 1
   contador_de_leitores++;                          

   // Se tiver pelo menos um leitor na area critica, então nenhum escritor poderá entrar, portanto, a preferência fica com o leitor.
   if (contador_de_leitores == 1){
      sem_wait(&wrt);  
   }                         

   // enquanto esse leitor atual está dentro da area critica, outros leitores conseguem entrar tambem.
   sem_post(&mutex);                   

   // o leitor atual realiza a leitura
    int pos =  (rand() % 19); // posicao do vetor
    if (nuvem[pos] == NULL){
        printf("Não há nada a ser lido.");
    }
    else{
        printf("%s", nuvem[pos]);
    }

   sem_wait(&mutex);;   // um leitor deseja sair 

   contador_de_leitores--;

   // Nenhum leitor é deixado na area critica
   if (contador_de_leitores == 0) 
       sem_post(&wrt);         // escritores estao autorizados a entrar

   sem_post(&mutex); // leitor sai da area critica

    } while(true);
}

void* escrita_de_dados(void* arg){
    do {
    // escritores solicitam a entrada na area critica.
    sem_wait(&wrt);  
   
    // realizam a escrita
    srand(time(NULL)); // inicializa o gerador de numeros aleatorios com o valor da funcao time(NULL)
  
    // gerando valores aleatórios na faixa de 0 a 19
    int pos =  (rand() % 19); // posicao do vetor
    strcpy (nuvem[pos], matriz[pos]);	/* Copia str1 em str2 */
    // saida da area critica
    sem_post(&wrt);

    } while(true);
}

int main(){
    sem_init(&mutex, 0, 1); // inicializando semaforo
    sem_init(&wrt, 0, 1);
    pthread_t threads[6];
    for(int i = 0; i < 2; i++){
        pthread_create(&threads[i], NULL, escrita_de_dados , matriz); // escrita dos dados
    }
    for(int i = 2; i < 6; i++){
        pthread_create(&threads[i], NULL, leitura_de_dados, matriz); // leitura dos dados
    }
    for(int i = 0; i < 6; i++){
        pthread_join(threads[i], NULL);
    }

    sem_destroy(&mutex); // destruindo o semaforo
    sem_destroy(&wrt);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h> 

char matriz[20][70]; // matriz com as frases
char nuvem[20][70]; // matriz que receberá as frases dos escritores
int contador_de_leitores;
sem_t mutex, wrt; // declaracao dos semaforos

void initialize(){
    matriz[0] = "O importante não é vencer todos os dias, mas lutar sempre."
    matriz[1] = "Maior que a tristeza de não haver vencido é a vergonha de não ter lutado!"
    matriz[2] = "É melhor conquistar a si mesmo do que vencer mil batalhas."
    matriz[3] = "Quem ousou conquistar e saiu pra lutar, chega mais longe!"
    matriz[4] = "Enquanto houver vontade de lutar haverá esperança de vencer."
    matriz[5] = "Difícil é ganhar um amigo em uma hora; fácil é ofendê-lo em um minuto."
    matriz[6] = "O medo de perder tira a vontade de ganhar."
    matriz[7] = "Aquele que não tem confiança nos outros, não lhes pode ganhar a confiança."
    matriz[8] = "Escolher o seu tempo é ganhar tempo."
    matriz[9] = "Perder para a razão, sempre é ganhar."
    matriz[10] = "Arriscamo-nos a perder quando queremos ganhar demais."
    matriz[11] = "Muitos sabem ganhar dinheiro, mas poucos sabem gastá-lo."
    matriz[12] = "Se você pretende ser rico, pense em economizar tanto quanto em ganhar."
    matriz[13] = "O homem digno ganha para viver; o menos honesto vive para ganhar."
    matriz[14] = "Para ganhar aquilo que vale a pena ter, pode ser necessário perder tudo mais."
    matriz[15] = "A maior caridade é habilitar o pobre a ganhar a sua vida."
    matriz[16] = "O mundo está perdido para aqueles que o querem ganhar."
    matriz[17] = "Quem sabe o que se pode ganhar num dia jamais furta."
    matriz[18] = "Loteria: acho que, jogando ou não, você tem a mesma chance de ganhar"
    matriz[19] = "A avareza perde tudo ao pretender ganhar tudo."
}

void* leitura_de_dados(void* arg){
    do {
    
   // Leitores desejam entrar na area critica.
   sem_wait(sem_t *mutex);

   // contador do numero de leitores é incrementado em 1
   contador_de_leitores++;                          

   // Se tiver pelo menos um leitor na area critica, então nenhum escritor poderá entrar, portanto, a preferência fica com o leitor.
   if (contador_de_leitores == 1){
      sem_wait(sem_t *wrt);  
   }                         

   // enquanto esse leitor atual está dentro da area critica, outros leitores conseguem entrar tambem.
   sem_post(sem_t *mutex);                   

   // o leitor atual realiza a leitura
    int pos =  (rand() % 19); // posicao do vetor
    if (nuvem[pos] == NULL){
        printf("Não há nada a ser lido.");
    }
    else{
        printf("%s", nuvem[pos]);
    }

   sem_wait(sem_t *mutex);;   // um leitor deseja sair 

   contador_de_leitores--;

   // Nenhum leitor é deixado na area critica
   if (contador_de_leitores == 0) 
       sem_post(sem_t *wrt);         // escritores estao autorizados a entrar

   sem_post(sem_t *mutex); // leitor sai da area critica

    } while(true);
}

void* escrita_de_dados(void* arg){
    do {
    // escritores solicitam a entrada na area critica.
    sem_wait(sem_t *wrt);  
   
    // realizam a escrita
    srand(time(NULL)); // inicializa o gerador de numeros aleatorios com o valor da funcao time(NULL)
  
    // gerando valores aleatórios na faixa de 0 a 19
    int pos =  (rand() % 19); // posicao do vetor
    nuvem[pos] = matriz[pos]; // realizando a escrita da frase
    // saida da area critica
    sem_post(sem_t *wrt);

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

    sem_destroy(sem_t *mutex); // destruindo o semaforo
    sem_destroy(sem_t *wrt);
    return 0;
}
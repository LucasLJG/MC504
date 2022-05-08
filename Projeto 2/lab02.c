#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include <stdbool.h> 
#include <unistd.h>

#define N_LEITORES 4
#define N_ESCRITORES 2

//Guardar o estado de atividade da pessoa (lendo/escrevendo ou inativo)
typedef enum {inativo, ativo} estado_pessoa;
estado_pessoa estadoLeitor[N_LEITORES];
estado_pessoa estadoEscritor[N_ESCRITORES];

int linhas_preenchidas = 0, posicoes[4] = {0,0,0,0}; // Variavel para ajudar a preencher a nuvem em ordem.
char texto_leitores[4][20][75] = {{"                                                                      ",
 "                                                                      ", 
 "                                                                      ",
 "                                                                      ",
 "                                                                      ",
 "                                                                      ",
 "                                                                      ",
 "                                                                      ", 
 "                                                                      ",
 "                                                                      ",
 "                                                                      ",
 "                                                                      ",
 "                                                                      ",
 "                                                                      ",
 "                                                                      ",
 "                                                                      ",
 "                                                                      ",
 "                                                                      ",
 "                                                                      ",
 "                                                                      "}, 
 {"                                                                      ",
 "                                                                      ", 
 "                                                                      ",
 "                                                                      ",
 "                                                                      ",
 "                                                                      ",
 "                                                                      ",
 "                                                                      ", 
 "                                                                      ",
 "                                                                      ",
 "                                                                      ",
 "                                                                      ",
 "                                                                      ",
 "                                                                      ",
 "                                                                      ",
 "                                                                      ",
 "                                                                      ",
 "                                                                      ",
 "                                                                      ",
 "                                                                      "}, 
 {"                                                                      ",
 "                                                                      ", 
 "                                                                      ",
 "                                                                      ",
 "                                                                      ",
 "                                                                      ",
 "                                                                      ",
 "                                                                      ", 
 "                                                                      ",
 "                                                                      ",
 "                                                                      ",
 "                                                                      ",
 "                                                                      ",
 "                                                                      ",
 "                                                                      ",
 "                                                                      ",
 "                                                                      ",
 "                                                                      ",
 "                                                                      ",
 "                                                                      "},
 {"                                                                      ",
 "                                                                      ", 
 "                                                                      ",
 "                                                                      ",
 "                                                                      ",
 "                                                                      ",
 "                                                                      ",
 "                                                                      ", 
 "                                                                      ",
 "                                                                      ",
 "                                                                      ",
 "                                                                      ",
 "                                                                      ",
 "                                                                      ",
 "                                                                      ",
 "                                                                      ",
 "                                                                      ",
 "                                                                      ",
 "                                                                      ",
 "                                                                      "}};

char textos[20][75] = {"O importante não é vencer todos os dias, mas lutar sempre.            ",
 "Maior que a tristeza de não haver vencido é a vergonha ...!           ", 
 "É melhor conquistar a si mesmo do que vencer mil batalhas.            ", 
 "Quem ousou conquistar e saiu pra lutar, chega mais longe!             ", 
 "Enquanto houver vontade de lutar haverá esperança de vencer.          ",
 "Difícil é ganhar um amigo em uma hora ...                             ",
 "O medo de perder tira a vontade de ganhar.                            ",
 "Aquele que não tem confiança nos outros ...                           ", 
 "Escolher o seu tempo é ganhar tempo.                                  ",
 "Perder para a razão, sempre é ganhar.                                 ", 
 "Arriscamo-nos a perder quando queremos ganhar demais.                 ",
 "Muitos sabem ganhar dinheiro, mas poucos sabem gastá-lo.              ", 
 "Se você pretende ser rico, pense em economizar tanto quanto em ganhar.",
 "O homem digno ganha para viver; o menos honesto vive para ganhar.     ",
 "Para ganhar aquilo que vale a pena ter ...                            ",
 "A maior caridade é habilitar o pobre a ganhar a sua vida.             ", 
 "O mundo está perdido para aqueles que o querem ganhar.                ", 
 "Quem sabe o que se pode ganhar num dia jamais furta.                  ", 
 "Loteria: acho que, jogando ou não, você tem a mesma chance de ganhar  ",
 "A avareza perde tudo ao pretender ganhar tudo.                        "}; //Repositorio a ser feito upload na nuvem
char cloud[20][75] = {"                                                                      ",
 "                                                                      ", 
 "                                                                      ",
 "                                                                      ",
 "                                                                      ",
 "                                                                      ",
 "                                                                      ",
 "                                                                      ", 
 "                                                                      ",
 "                                                                      ",
 "                                                                      ",
 "                                                                      ",
 "                                                                      ",
 "                                                                      ",
 "                                                                      ",
 "                                                                      ",
 "                                                                      ",
 "                                                                      ",
 "                                                                      ",
 "                                                                      "}; // matriz que receberá as frases dos escritores
char phrase[75];


int cnt_leitores_ativos;
sem_t sem_leitor, sem_escritor, sem_animation; // declaracao dos semaforos

// Na funcao animacao, sera printada as caixas que seriam os Translators, a Cloud e os Readers
void animation(){


    // Começando pelas caixas dos Translators, primeiro printamos os seus nomes.
    for (int i = 0; i < 2; i ++)
        printf("\t\t\t\t\t\tTranslator %d", i + 1);
    printf("\n");

    // Depois printamos as partes de cima das caixas.
    for (int i = 0; i < 2; i ++)
        printf("\t{----------------------------------------------------------------------}\t\t");
    printf("\n");

    // Em seguida, printamos o status dos Translators.
    if (estadoEscritor[0] == inativo && estadoEscritor[1] == inativo)
        printf("\t{Translating .....                                                     }\t\t\t{Translating .....                                                     }\n");
    else if (estadoEscritor[0] == inativo && estadoEscritor[1] == ativo)
        printf("\t{Translating .....                                                     }\t\t\t{%s}\n", phrase);
    else 
        printf("\t{%s}\t\t\t{Translating .....                                                     }\n", phrase);

    // Por fim, printamos a parte de baixo das caixas.
    for (int i = 0; i < 2; i ++)
        printf("\t{----------------------------------------------------------------------}\t\t");
    printf("\n\n\n\n\n\n");

    // Printa o caixa da Cloud
    printf("\t\t\t\t\t\t                                      Cloud                                 \n");
    printf("\t\t\t\t\t\t    {^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^}\n");
    for (int i = 0; i < 20; i ++){
        if (estadoEscritor[0] == ativo && estadoEscritor[1] == inativo)
            printf("\t\t\t\t\t\t    {UPLOANDING.........                                                   }\n");
        else if (estadoEscritor[0] == inativo && estadoEscritor[1] == ativo)
            printf("\t\t\t\t\t\t    {UPLOANDING.........                                                   }\n");
        else 
            printf("\t\t\t\t\t\t    {%s}\n", cloud[i]);
    }
    printf("\t\t\t\t\t\t    {~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~}\n\n\n\n\n");


    // Comecando as caixas dos Readers, primeiro printamos os nomes dos dois primeiros.
    printf("\t\t\t                Reader 1                            \t\t\t\t                                Reader 2\n");

    // Depois printamos as partes de cima das caixas dos dois primeiros.
    for (int i = 0; i < 2; i ++)
        printf("\t{----------------------------------------------------------------------}\t\t");
    printf("\n");

    // Em seguida, printamos o status dos dois primeiros Readers.
    for (int i = 0; i < 20; i ++){
        if (estadoLeitor[0] == ativo && estadoLeitor[1] == ativo)
            printf("\t{Downloading .....                                                     }\t\t\t{Downloading .....                                                     }\n");
        else if (estadoLeitor[0] == ativo && estadoLeitor[1] == inativo)
            printf("\t{Downloading .....                                                     }\t\t\t{%s}\n", texto_leitores[1][i]);
        else if (estadoLeitor[0] == inativo && estadoLeitor[1] == ativo)
            printf("\t{%s}\t\t\t{Downloading .....                                                     }\n", texto_leitores[0][i]);
        else
            printf("\t{%s}\t\t\t{%s}\n", texto_leitores[0][i], texto_leitores[1][i]);
    }

    // Por fim, printamos a parte de baixo das caixas dos dois ultimos Readers.
    for (int i = 0; i < 2; i ++)
        printf("\t{----------------------------------------------------------------------}\t\t");
    printf("\n");

    // Comecando as caixas dos Readers, primeiro printamos os nomes dos dois ultimos.
    printf("\t\t\t                Reader 3                            \t\t\t\t                                Reader 4\n");

    // Depois printamos as partes de cima das caixas dos dois primeiros.
    for (int i = 0; i < 2; i ++)
        printf("\t{----------------------------------------------------------------------}\t\t");
    printf("\n");

    // Em seguida, printamos o status dos dois ultimos Readers.
    for (int i = 0; i < 20; i ++){
        if (estadoLeitor[2] == ativo && estadoLeitor[3] == ativo)
            printf("\t{Downloading .....                                                     }\t\t\t{Downloading .....                                                     }\n");
        else if (estadoLeitor[2] == ativo && estadoLeitor[3] == inativo)
            printf("\t{Downloading .....                                                     }\t\t\t{%s}\n", texto_leitores[3][i]);
        else if (estadoLeitor[2] == inativo && estadoLeitor[3] == ativo)
            printf("\t{%s}\t\t\t{Downloading .....                                                     }\n", texto_leitores[2][i]);
        else
            printf("\t{%s}\t\t\t{%s}\n", texto_leitores[2][i], texto_leitores[3][i]);
    }

    // Por fim, printamos a parte de baixo das caixas dos dois ultimos Readers.
    for (int i = 0; i < 2; i ++)
        printf("\t{----------------------------------------------------------------------}\t\t");
    printf("\n\n\n\n");

}

void* leitura_de_dados(void* arg){
    long int id = (long int) arg;

    while (posicoes[id - 2] < 20){

        // Leitores desejam entrar na area critica.
        sem_wait(&sem_leitor);


        // contador do numero de leitores é incrementado em 1
        cnt_leitores_ativos ++;                          

        // Se tiver pelo menos um leitor na area critica, então nenhum escritor poderá entrar, portanto, a preferência fica com o leitor.
        if (cnt_leitores_ativos == 1){
            sem_wait(&sem_escritor);
        }                         

        // enquanto esse leitor atual está dentro da area critica, outros leitores conseguem entrar tambem.
        sem_post(&sem_leitor);

        // o leitor atual realiza a leitura
        // Condicao para garantir que o leitor vai ler uma posicao que nao seja vazia.
        if (posicoes[id - 2] <= linhas_preenchidas) {
            sem_wait(&sem_animation);
            estadoLeitor[id - 2] = ativo;
            animation(); 
            strcpy (texto_leitores[id - 2][posicoes[id - 2]], cloud[posicoes[id - 2]]);
            posicoes[id - 2] ++;
        
            estadoLeitor[id - 2] = inativo;
            animation(); 
            sem_post(&sem_animation);

        }
        sem_wait(&sem_leitor);   // um leitor deseja sair 

        cnt_leitores_ativos--;

        // Nenhum leitor é deixado na area critica
        if (cnt_leitores_ativos == 0) 
            sem_post(&sem_escritor);         // escritores estao autorizados a entrar
        sem_post(&sem_leitor); // leitor sai da area critica

    }
}

void* escrita_de_dados(void* arg){
    long int id = (long int) arg;

    while (linhas_preenchidas < 20){

        // escritores solicitam a entrada na area critica.
        sem_wait(&sem_escritor);
        if (linhas_preenchidas < 20){
            estadoEscritor[id] = ativo;
            
            // realizam a escrita
            srand(time(NULL)); // inicializa o gerador de numeros aleatorios com o valor da funcao time(NULL)
        
            // gerando valores aleatórios na faixa de 0 a 19
            int pos =  (rand() % 19); // posicao do vetor
            strcpy (cloud[linhas_preenchidas], textos[pos]);	/* Copia str1 em str2 */
            linhas_preenchidas ++;
            strcpy (phrase, textos[pos]);
            animation();
            estadoEscritor[id] = inativo;
            animation();
        }
        // saida da area critica
        sem_post(&sem_escritor);
    }
}

int main(){
    pthread_t threads[6];
    long int id;

    sem_init(&sem_leitor, 0, 1); // inicializando semaforo
    sem_init(&sem_escritor, 0, 1);

    sem_init(&sem_animation, 0, 1); 

    animation();

    for(id = 0; id < 2; id++){
        estadoEscritor[id] = inativo;
        pthread_create(&threads[id], NULL, escrita_de_dados, (void *)id); // escrita dos dados
    }
    for(id = 2; id < 6; id++){
        estadoLeitor[id] = inativo;
        pthread_create(&threads[id], NULL, leitura_de_dados, (void *)id); // leitura dos dados
    }
    for(int i = 0; i < 6; i++){
        pthread_join(threads[i], NULL);
    }

    sem_destroy(&sem_leitor); // destruindo o semaforo
    sem_destroy(&sem_escritor);
    sem_destroy(&sem_animation);
    return 0;
}
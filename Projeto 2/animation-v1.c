#include <stdio.h>
#include <string.h>

// Na funcao animacao, sera printada as caixas que seriam os Translators, a Cloud e os Readers
void animation(char cloud[3][250], int phrases, int translators_status[1], int readers_status[3]){

    // Começando pelas caixas dos Translators, primeiro printamos os seus nomes.
    for (int i = 0; i < 2; i ++)
        printf("\t\t\t\t\t\tTranslator %d", i + 1);
    printf("\n");

    // Depois printamos as partes de cima das caixas.
    for (int i = 0; i < 2; i ++)
        printf("\t\t\t\t\t{----------------------}");
    printf("\n");

    // Em seguida, printamos o status dos Translators.
    for (int i = 0; i < 2; i ++){
        if (translators_status[i] == 1)
            printf("\t\t\t\t\t{     Uploading ....   }");
        else
            printf("\t\t\t\t\t{    Translating ....  }");
    }
    printf("\n");

    // Por fim, printamos a parte de baixo das caixas.
    for (int i = 0; i < 2; i ++)
        printf("\t\t\t\t\t{----------------------}");
    printf("\n\n\n\n\n");

    // Printa o caixa da Cloud
    printf("\t\t\t\t\t\t                                      Cloud                                 \n");
    printf("\t\t\t\t\t\t    {^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^}\n");
    for (int i = 0; i < phrases; i ++){
        printf("\t\t\t\t\t\t    {%s}\n", cloud[i]);
    }
    printf("\t\t\t\t\t\t    {~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~}\n\n\n\n\n");


    // Terminado pelas caixas dos Readers, primeiro printamos os seus nomes.
    for (int i = 0; i < 4; i ++)
        printf("\t\t          Readers %d        ", i + 1);
    printf("\n");

    // Depois printamos as partes de cima das caixas.
    for (int i = 0; i < 4; i ++)
        printf("\t\t{----------------------}");
    printf("\n");

    // Em seguida, printamos o status dos Readers.
    for (int i = 0; i < 4; i ++){
        if (readers_status[i] == 1)
            printf("\t\t{   Downloading .....  }");
        else
            printf("\t\t{      Reading .....   }");
    }
    printf("\n");

    // Por fim, printamos a parte de baixo das caixas.
    for (int i = 0; i < 4; i ++)
        printf("\t\t{----------------------}");
    printf("\n");
}

int main (){
    char cloud[20][250] = {
        "O lucas é muito chato                                                 ", 
        "O lucas é muito chato                                                 ",
        "O lucas é muito chato                                                 ", 
        "O lucas é muito chato                                                 ",
        "O lucas é muito chato                                                 ", 
        "O lucas é muito chato                                                 ",
        "O lucas é muito chato                                                 ", 
        "O lucas é muito chato                                                 ", 
        "O lucas é muito chato                                                 ", 
        "O lucas é muito chato                                                 ",
        "O lucas é muito chato                                                 ", 
        "O lucas é muito chato                                                 ",
        "O lucas é muito chato                                                 ", 
        "O lucas é muito chato                                                 ",
        "O lucas é muito chato                                                 ", 
        "O lucas é muito chato                                                 ",
        "O lucas é muito chato                                                 ", 
        "O lucas é muito chato                                                 ",
        "O lucas é muito chato                                                 ", 
        "O lucas é muito chato                                                 ", 
        "O lucas é muito chato                                                 "};
    int phrases = 20;
    int translators_status[1] = {0, 0};
    int readers_status[3] = {0, 0, 0, 0}; 
    animation(cloud, phrases, translators_status, readers_status);
}

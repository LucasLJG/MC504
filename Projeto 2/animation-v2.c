#include <stdio.h>
#include <string.h>

// Na funcao animacao, sera printada as caixas que seriam os Translators, a Cloud e os Readers
void animation(char cloud[20][72], char phrase[72], int translators_status[1], int readers_status[3], char reader_1[20][72], char reader_2[20][72], char reader_3[20][72], char reader_4[20][72]){

    // Começando pelas caixas dos Translators, primeiro printamos os seus nomes.
    for (int i = 0; i < 2; i ++)
        printf("\t\t\t\t\t\tTranslator %d", i + 1);
    printf("\n");

    // Depois printamos as partes de cima das caixas.
    for (int i = 0; i < 2; i ++)
        printf("\t{----------------------------------------------------------------------}\t\t");
    printf("\n");

    // Em seguida, printamos o status dos Translators.
    if (translators_status[0] == 0 && translators_status[1] == 0)
        printf("\t{Translating .....                                                     }\t\t\t{Translating .....                                                     }\n");
    else if (translators_status[0] == 0 && translators_status[1] == 1)
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
        if (translators_status[0] == 1 && translators_status[1] == 0)
            printf("\t\t\t\t\t\t{UPLOANDING.........                                                   }\n");
        else if (translators_status[0] == 0 && translators_status[1] == 1)
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
        if (readers_status[0] == 1 && readers_status[1] == 1)
            printf("\t{Downloading .....                                                     }\t\t\t{Downloading .....                                                     }\n");
        else if (readers_status[0] == 1 && readers_status[1] == 0)
            printf("\t{Downloading .....                                                     }\t\t\t{%s}\n", reader_2[i]);
        else if (readers_status[0] == 0 && readers_status[1] == 1)
            printf("\t{%s}\t\t\t{Downloading .....                                                     }\n", reader_1[i]);
        else
            printf("\t{%s}\t\t\t{%s}\n", reader_1[i], reader_2[i]);
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
        if (readers_status[2] == 1 && readers_status[3] == 1)
            printf("\t{Downloading .....                                                     }\t\t\t{Downloading .....                                                     }\n");
        else if (readers_status[2] == 1 && readers_status[3] == 0)
            printf("\t{Downloading .....                                                     }\t\t\t{%s}\n", reader_4[i]);
        else if (readers_status[2] == 0 && readers_status[3] == 1)
            printf("\t{%s}\t\t\t{Downloading .....                                                     }\n", reader_3[i]);
        else
            printf("\t{%s}\t\t\t{%s}\n", reader_3[i], reader_4[i]);
    }

    // Por fim, printamos a parte de baixo das caixas dos dois ultimos Readers.
    for (int i = 0; i < 2; i ++)
        printf("\t{----------------------------------------------------------------------}\t\t");
    printf("\n");
}

int main (){
    char cloud[20][72] = {
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
        "Eu escrevi isso aqui                                                  "};
    char reader_1[20][72] = {
        "O lucas é muito chato                                                 ", 
        "O lucas é muito chato                                                 ",
        "O lucas é muito chato                                                 ", 
        "O lucas é muito chato                                                 ",
        "O lucas é muito chato                                                 ", 
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
        "                                                                      "};
    char reader_2[20][72] = {
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
        "                                                                      ", 
        "                                                                      ",
        "                                                                      ",
        "                                                                      ", 
        "                                                                      ",
        "                                                                      ",
        "                                                                      "};
    char reader_3[20][72] = {
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
        "                                                                      ", 
        "                                                                      ",
        "                                                                      ",
        "                                                                      ", 
        "                                                                      ",
        "                                                                      ",
        "                                                                      ", 
        "                                                                      ",
        "                                                                      ",
        "                                                                      "};
    char reader_4[20][72] = {
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
        "                                                                      ", 
        "                                                                      ",
        "                                                                      ",
        "                                                                      "};
    char phrase[71] = "O lucas é muito chato                                                 ";
    int translators_status[2] = {0, 1};
    int readers_status[4] = {0, 0, 0, 0}; 
    animation(cloud, phrase, translators_status, readers_status, reader_1, reader_2, reader_3, reader_4);
}

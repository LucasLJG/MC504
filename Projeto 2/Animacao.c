#include <stdio.h>
#include <string.h>

void output(char cloud[], char* computers, int number_computers){
    size_t n = sizeof(cloud) / sizeof(cloud[0]);
    printf("\t\t\t      Cloud           \n");
    printf("\t\t\t{~~~~~~~~~~~}\n");
    printf("\t\t\t{           }\n");
    printf("\t\t\t{     %s    }\n", cloud);
    printf("\t\t\t{           }\n");
    printf("\t\t\t{~~~~~~~~~~~}\n");

    for (int i = 0; i < number_computers; i ++){
        printf("          Computador t       \n");
        printf("{---------------------------}\n");
        printf("{                           }\n");
        printf("{                           }\n");
        printf("{                           }\n");
        printf("{                           }\n");
        printf("{                           }\n");
        printf("{---------------------------}\n");
    }
}

int main (){
    char cloud[250] = "Codigo errado";
    char computers[4][250] = {{'P', 'C', '1'}, {'P', 'C', '2'}, {'P', 'C', '3'}, {'P', 'C', '4'}, {'P', 'C', '5'}};
    int numer_computers = 5;
    output(cloud, computers, numer_computers);
}

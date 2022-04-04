void* encontrarPalavra(char* matriz[][], char* palavra[][], int n){
    int palavraEncontrada = 0;
    int i = 0, j = 0;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(palavra[0] == matriz[i][j]){ // A primeira letra da palavra é encontrada.
                if(palavra[1] == matriz[(i-1)][j]){ // A segunda letra da palavra é encontrada.
                    palavraEncontrada = 1;
                        for (int m = 0; m < strlen(palavra[][]); m++){
                            if (palavra[m] != matriz[i-m][j])
                                palavraEncontrada = 0;
                        }
                        if (palavraEncontrada == 1){
                           break; 
                        }
                }
                if (palavra[1] == matriz[i + 1][j]){ // A segunda letra encontrada no sentido Sul. 
                        palavraEncontrada = 1;
                        for (int m = 0; m < strlen(palavra[][]); m++)
                            if (palavra[m] != matriz[i+m][j])
                                palavraEncontrada = 0; 
                        if (palavraEncontrada == 1){
                            break;
                        }
                }
                if (palavra[1] == matriz[i][j + 1]){ // A segunda letra é encontrada no sentido Leste.
                        palavraEncontrada = 1;
                        for (int m = 0; m < strlen(palavra[][]); m++)
                            if (palavra[m] != matriz[i][j+m])
                                palavraEncontrada = 0;
                        if (encontrada == 1){
                            break;
                        }
                    }
                
                if (palavra[1] == matriz[i][(j-1)]){ // A segunda letra é encontrada no sentido Oeste.
                        palavraEncontrada = 1;
                        for (int m = 0; m < strlen(palavra[][]); m++)
                            if (palavra[m] != matriz[i][(j-m)])
                                palavraEncontrada = 0;
                        if (palavraEncontrada == 1)
                            break;
                    }

                if (palavra[1] == matriz[i-1][j+1]) { // A segunda letra é encontrada no sentido Nordeste.
                        palavraEncontrada = 1;
                        for (int m = 0; m < strlen(palavra[][]); m++)
                            if (palavra[m] != matriz[i-m][j+m])
                                palavraEncontrada = 0;
                        if (palavraEncontrada == 1)
                            break;
                    }
                
                if (palavra[1] == matriz[(i-1)][(j-1)]) { // A segunda letra é encontrada no sentido Noroeste.
                        palavraEncontrada = 1;
                        for (int m = 0; m < strlen(palavra[][]); m++)
                            if (palavra[m] != matriz[i-m][j-m])
                                palavraEncontrada = 0;
                        if (palavraEncontrada == 1)
                            break;
                    }
                
                if (palavra[1] == matriz[i+1][j+1]) { // A segunda letra é encontrada no sentido Sudeste.
                          palavraEncontrada = 1;
                        for (int m = 0; m < strlen(palavra[][]); m++)
                            if (palavra[m] != matriz[i+m][j+m])
                                palavraEncontrada = 0;
                        if (palavraEncontrada == 1)
                            break;
                    }

                if (palavra[1] == matriz[i+1][j-1]) { // A segunda letra é encontrada no sentido Sudoeste.
                        palavraEncontrada = 1;
                        for (int m = 0; m < strlen(palavra[][]); m++)
                            if (palavra[m] != matriz[i+m][j-m])
                                palavraEncontrada = 0;
                        if (palavraEncontrada == 1)
                            break;
                    }
            }
        }
        if (palavraEncontrada == 1){
            break;
        }

        if (palavraEncontrada == 1)
            printf("%s - A palavra foi encontrada \n", palavra);
        else
            printf("A palavra não foi encontrada \n");
    }
}
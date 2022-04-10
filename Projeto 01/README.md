## Tema
* Caça-palavras

## Integrantes
* Lucas Jacinto Gonçalves     RA: 240013
* Leonardo Novaes do Nascimento     RA: 220142
* Fernando Dos Reis Santos Filho                    RA: 234471

## Descrição
O projeto consiste no processamento de uma matriz quadrada (orden n) que será fornecida como entrada pelo usuário. As palavras a serem buscadas, caso estejam na matriz, serão fornecidas pelo usuário também e com a utilização de threads iremos percorrer a matriz a procura das palavras fornecidas pelo usuário. Cada thread ficará encarregada da busca na matriz de uma única palavra. Ao final do processo será informado para o usuário a palavra que ele solicitou a busca e se ela foi encontrada na matriz ou não. A sincronização das threads é realizado através do método join da biblioteca pthread no qual estamos utilizando para este projeto.

## Divisão do trabalho
O trabalho foi dividido da seguinte maneira: Os membros Lucas e Leonardo fizeram a construção da função no qual as threads iriam chamar, ou seja, a função de processamento da matriz para a busca das palavras do caça-palavra. O Fernando criou a função main, no qual ele organizou as threads e fez a apresentação do vídeo mostrando o funcionamento do algoritmo e uma breve explicação do mesmo. Por fim, Lucas e Leonardo fizeram a documentação da equipe para a entrega.


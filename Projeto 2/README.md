## Tema

* Leitura e Escrita de Dados Compartilhados

## Integrantes
* Lucas Jacinto Gonçalves     RA: 240013
* Leonardo Novaes do Nascimento     RA: 220142
* Fernando Dos Reis Santos Filho                    RA: 234471

## Descrição

O projeto consiste na construção de um sistema compartilhado de leitura e escrita de dados utilizando o conceito de threads e semáforos para a sincronização das threads.
A ideia do projeto baseia-se na escrita de dados por uma determinada thread, sendo que esses dados estão contidos em um vetor de tamanho 20 que guarda 20 frases nos quais uma thread escolherá para escrever na nuvem que será apresentado para o usuário através de uma animação. A escolha das frases por uma thread utiliza uma função randômica para termos aleatoriedade nas escolhas das frases pelas threads.
A thread que realiza a leitura dos dados da nuvem, após o processo de escrita da thread escritora, permite que outras threads realizam a leitura em simultâneo, porém não permite que nenhuma thread de escrita realize o processo de escrita enquanto pelo menos uma thread de leitura estiver sendo executada. Esse processo de leitura e escrita de dados é mostrado ao usuário através de uma animação no qual temos a nuvem (cloud) que representa os dados que vão ser enviados para serem armazenados (uploding) e a leitura dos dados é feito pelas threads assim que elas baixam esses dados para lerem (downloading). A animação é apresentada pelo usuário via terminal utilizando os caracteres ASCII.

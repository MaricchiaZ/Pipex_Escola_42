# Pipex Escola 42


## Como funciona a Pipe line |

Essa linha redireciona a saída de um comando para a entrada do próximo comando

ex: `ls | wc`
- o comando `ls`lista os arquivos e pastas no diretório atual
- o comando `wc`conta as palavras em um arquivo

então usando a pipe line redirecionamos a lista de arquivos para p comando contador, e teremos a quantidade de arquivos + pastas no diretório atual

### Entendendo os conceitos
Input - é o que eu estou recebendo, é a entrada de dados, é o caminho de entrada dos dados
StdIn (0) - é a entrada de dados do terminal, toda vez que um comando é digitado no terminal ele estamos colocando o comando no StdIn (0) (Standard input) do terminal

Output - é o que eu estou renviando, é a saída dos dados que eu produzi, é o caminho de saída dos dados
StdOut(1) - saída normal do terminal, tudo que aparece escrito no terminal, foi enviado para o StdOut (1) (Standard outut) do terminal

Erro - quando algum comando é digitado errado, ou não encontrou o arquivo sobre o qual deveria rodar, essa info é enviada para uma saída pré definida para casos de erros
Stderr (2) - saída padrão para casos de erros

A saída do comando1, em vez de ir para o terminal, é encaminhada para a entrada do segundo comando

```
file1 -> stdin(0) -> comando 1  | comando 2 -> stdout(1) -> file2
                           |          |
                      stdout(1) -> stdin(0)
```

### Entendendo os conceitos
Base de estudo: https://www.youtube.com/playlist?list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY
múltiplas threads:
múltiplos processos: Um processo (linha de execução de código) acontece duplicado toda vez que usamos um fork, um fork pode ser usado dentro de outro fork. Os processos pai e filho podem atuar diferentemente se as funções chamadas dentro de if que consultem o ID.
Diferença entre processo e threads:

`Função fork`: ela duplica a linha de execução.... tudo o que for executado depois dela, será executado 2 vezes, cria variável duas vezes, aloca duas vezes... Faz com que um programa tenha 2 processos em execussão, um processo da main(processo pai), mais um processo criado pela bifurcação, clone exato do principal, (processo filho).
`Retorno da função fork`: um int que será o ID do processo, para cada um dos processos: entao teremos um ID do processo pai, e um ID do processo filho. 
O ID do processo pai será um int positivo de valor variável (só será -1 se der errado o fork), o ID do processo filho *sempre será zero*.
Então: ID == 0 (processo filho)
       ID > 0 (processo pai)
       ID == -1 (falha no fork)

Sabendo o ID, pode-se pedir para cada processo executar uma função diferente, um dos processos pode até receber um segundo fork, e assim por diante.

`Função wait`: possibilita esperar o processo filho acabar para então executar o processo pai/main. Isso evita que os eventos ocorram simultâneamente, evitando que funções que imprimam coisas no terminal misturem a saída

`Função pipe`: cria um canal de dados unidirecional que pode ser usado para comunicação entre os processos. A função pipe pede uma matriz de ints de 2 posições (int pipefd[2]). Essa matriz é usada para retornar dois descritores de arquivo referentes às extremidades do pipe. O pipefd[0] refere-se à extremidade lida e o pipefd[1] refere-se à extremidade de gravação do pipe. Os dados gravados na extremidade de gravação do pipe são armazenados em buffer pelo kernel até serem lidos na extremidade de leitura do pipe.
pipefd[0] = é lido (O que tiver no pipefd[0] pode ser lido pelo pipefd[1 ])
pipefd[1] = é escrito.
`Retorno da função pipe`:Em caso de sucesso, zero é retornado. Em caso de erro, -1 é retornado, errno é definido para indicar o erro e o pipefd permanece inalterado. 





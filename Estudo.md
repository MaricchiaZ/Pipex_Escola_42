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
múltiplas threads:
múltiplos processos:
Diferença entre processo e threads:

Função fork: ela duplica a linha de execução.... tudo o que for executado depois dela, será executado 2 vezes






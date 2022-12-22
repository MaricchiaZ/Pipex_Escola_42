
# include <unistd.h> // para usar a função fork, read, close
# include <stdlib.h>
# include <fcntl.h> // open
# include <stdio.h> // fflush
# include <string.h>
# include <time.h>
# include <sys/wait.h> // wait

// entendendo o fork
// o fork duplica tudo que ocorre abaixo dele.... criando um processo filho.... retornando 0 para o processo filho e outro valor de int para o processo pai/processo main.
int main(int argc, char *argv[])
{
    int id = fork();  // a partir daqui tudo ocorrerá 2 vezes
    if (id == 0) // se o retorno do fork for 0, estará rodando o processo filho
        printf("Child process");
    else //caso contrário, estará rodando o processo pai/main
        printf("Parent/Main process");
    printf("\n"); // como não está sob nenhuma condição, os dois processos executação esta linha
    return (0);
}

//  gcc test0.c
//  ./a.out



# include <unistd.h> // para usar a função fork, read, close
# include <stdlib.h>
# include <fcntl.h> // open
# include <stdio.h> // fflush
# include <string.h>
# include <time.h>
# include <sys/wait.h> // wait

// usando o fork, mas pausando um dos processos
int main(int argc, char *argv[])
{
    int id = fork(); // o fork duplica tudo o que ocorre daqui para baixo
    int n;
    if (id == 0) // no processo filho
        n = 1; // n vale 1
    else // no processo pai 
        n = 6; // o n vale 
     if (id != 0) // o processo pai
        sleep(1); // pausa por 1 segundo
    int i;
    for(i = n; i < n + 5; i++) // i recebe o valor de n, por vezes, imprime i, depois soma mais 1
    {
        printf("%d ", i); // imprime o valor de i
//        fflush(stdout);
    }
    if (id != 0) // o processo pai
        printf("\n"); // imprime a quebra de linha
    return (0);
}

//  gcc test1.c
//  ./a.out
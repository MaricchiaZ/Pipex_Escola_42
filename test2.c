
# include <unistd.h> // para usar a função fork, read, close
# include <stdlib.h>
# include <fcntl.h> // open
# include <stdio.h> // fflush
# include <string.h>
# include <time.h>
# include <sys/wait.h> // wait

int main(int argc, char *argv[])
{
    int arr[] = {1, 2, 3, 4, 1, 2};
    int fd[2];
    if (pipe[fd] == -1)
    {
        printf("Error pipe function\n");
        return (1);
    }
    //fd[0] = read
    //fd[1] = write
    if(pipe(fd) == -1)
    {
        printf("Error, with openin pipe");
        return 1;
    }
    int id = fork();
    if (id == 0) // no processo filho...
    {
        close(fd[0]); //fechamos clone do fd[0] que será usado pelo processo pai
        int x;
        printf("Input a number: "); // pedimos um número e armazenar no int x
        scanf("%d", &x);
        write(fd[1], &x, sizeof(int)); // escrevemos esse número no fd[1]...
        close(fd[1]);// e fechamos o fd1
    }
    else
    {
        close(fd[1]); // fechamos clone do fd[1] usado pelo processo filho
        int y; // vai armazenar o "buffer" de leitura da func read
        read(fd[0], &y, sizeof(int)); // y recebe o conteúdo do fd[0]
        close(fd[0]); // fechamos o fd[0]
        printf("Got from process child process: %d\n", y);// imprimimos no processo pai o y obtido do processo filho
    }
    if (id != 0)
        printf("\n");
    return (0);
}

//  gcc test2.c
//  ./a.out

// x -> fd[1] -> fd[0] -> y

# include <unistd.h> // para usar a função fork, read, close
# include <stdlib.h>
# include <fcntl.h> // open
# include <stdio.h> // fflush
# include <string.h>
# include <time.h>
# include <sys/wait.h> // wait
# include <sys/stat.h>
# include <sys/types.h> //
# include <errno.h> // errno

// somar os elementos de um array de maneira mais rápida.
// 1/2 array é somado em um processo e a outra 1/2 no outro, gastando menos tempo assim
int main(int argc, char *argv[])
{
    if (mkfifo("myfifo1", 0777) == -1) // cria um file chamado myfifo1 com todas as permissóes (chmod 777)
    {
        if (errno != EEXIST)
        {
        printf("Could not create fifo file\n");
        return (1);
        }
        int fd = open("myfifo1", O_WRONLY);
        int x = 97;
        write(fd, &x, sizeof(x));
        close(fd);
    }
    // int fd[2]; 
    // if(pipe(fd) == -1)
    //     return 1;
    return 0;
}

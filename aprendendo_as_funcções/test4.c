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


int main(int argc, char *argv[])
{
    if (mkfifo("myfifo1", 0777) == -1) // cria um file chamado myfifo1 com todas as permissóes (chmod 777)
    {
        if (errno != EEXIST) // se o fifo n funcionar corretamente
        {
        printf("Could not create fifo file\n"); // imprimimos a mensagem de erro
        return (1);
        }
        int fd = open("myfifo1", O_WRONLY); // abre 
        int x = 97; // em ascii 97 = a
        write(fd, &x, sizeof(x)); // escreve no fd
        close(fd); // fecha o fd
    }
    // int fd[2]; 
    // if(pipe(fd) == -1)
    //     return 1;
    return 0;
}

// Se vc quiser que os arquivos tanto sejam lidos como sejam escritos, vc deve usar 2 fds;
// Nunca use o mesmo fd pra escrita nos dois arquivos, isso dá erro.
// int pair1_fd[2]; // C -> P
// int pair2_fd[2]; // P -> C


# include <unistd.h> // para usar a função fork, read, close
# include <stdlib.h>
# include <fcntl.h> // open
# include <stdio.h> // fflush
# include <string.h>
# include <time.h>
# include <sys/wait.h> // wait

// somar os elementos de um array de maneira mais rápida.
// 1/2 array é somado em um processo e a outra 1/2 no outro, gastando menos tempo assim
int main(int argc, char *argv[])
{
    int arr[] = {1, 2, 3, 4, 1, 2};
    int fd[2];
    int start; // para dividir o array
    int end; // para dividir o array
    int arrSize = sizeof(arr) / sizeof(int);
    if (pipe(fd) == -1) // função pipe é usada pra conectar dois fds
    {
       printf("Error pipe function\n"); // se a pipe falhar, retorna -1
       return (1);
    }
    int id = fork(); // duplica os processos
    if (id == 0) // no processo filho...
    {
        start = 0; // vai do iníci do array
        end = arrSize / 2; // até a metade dele
    }
    else // o processo pai
    {
        start = arrSize / 2; // vai da metade do array
        end = arrSize; // até o fim dele
    }
    int sum = 0;
    int i;
    for (i = start; i < end; i++) // soma a sua parte 
        sum += arr[i];
    printf("Partial sum: %d\n", sum);// imprime soma parcial

    if (id == 0) // no processo filho
    {
        close(fd[0]); // fecha a porta de lida
        write(fd[1], &sum, sizeof(sum)); // usa a porta de escrira, e escreve no fd
        close(fd[1]); // fecha o fd;
    }
    else // processo pai
    {
        int childsum = 0;
        close(fd[1]); // fecha a porta de escrita
        read(fd[0], &childsum, sizeof(childsum)); // usa a porta de leitura, e salva o que foi lido na var childsum
        close(fd[0]); // fecha a porta de leitura
        int total = sum + childsum; // total soma os dois valores
        printf("Total sum: %d", total);
        wait(NULL);
    }
    if (id != 0) // só o processo pai
        printf("\n"); // imprime a quebra de linha
    return (0);
}

//  gcc test3.c
//  ./a.out

// x -> fd[1] -> fd[0] -> y

//file1 cmd1 fd[1] cmd2 file2
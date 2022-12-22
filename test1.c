
# include <unistd.h> // para usar a função fork, read, close
# include <stdlib.h>
# include <fcntl.h> // open
# include <stdio.h> // fflush
# include <string.h>
# include <time.h>
# include <sys/wait.h> // wait

int main(int argc, char *argv[])
{
    int id = fork();
    int n;
    if (id == 0)
        n = 1;
    else
        n = 6;
     if (id != 0) // pausando o processo pai
        sleep(1);
    int i;
    for(i = n; i < n + 5; i++)
    {
        printf("%d ", i);
        fflush(stdout);
    }
    if (id != 0)
        printf("\n");
    return (0);
}

//  gcc test1.c
//  ./a.out
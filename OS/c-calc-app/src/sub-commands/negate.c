#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <num1>", argv[0]);
        return EXIT_FAILURE;
    }

    int num1 = atoi(argv[1]);

    printf("%d\n", -num1);
    printf("Process with pid: %d has completed negation., ppid: %d\n", getpid(), getppid());
    return EXIT_SUCCESS;
}
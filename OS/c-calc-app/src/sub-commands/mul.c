#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        perror("Insufficient number of arguments");
        fprintf(stderr, "Usage: %s <num1> <num2>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);

    printf("%d\n", num1 * num2);
    printf("Process with pid: %d has completed multiplication., ppid: %d\n", getpid(), getppid());
    return EXIT_SUCCESS;
}
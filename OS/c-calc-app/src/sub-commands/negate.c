#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <num1>", argv[0]);
        return EXIT_FAILURE;
    }

    int num1 = atoi(argv[1]);

    printf("%d\n", -num1);
    return EXIT_SUCCESS;
}
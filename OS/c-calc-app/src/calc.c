#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>

int main()
{
    printf("calc> ");

    // reading input from user
    char line[100];
    char command[7] = {0};
    int arg1 = 0, arg2 = 0;

    fgets(line, sizeof(line), stdin);
    sscanf(line, "%6s %d %d", command, &arg1, &arg2);

    // flow-control
    if (strcmp(command, "add") == 0)
    {
        printf("%d\n", arg1 + arg2);
    }
    else if (strcmp(command, "sub") == 0)
    {
        printf("%d\n", arg1 - arg2);
    }
    else if (strcmp(command, "mul") == 0)
    {
        printf("%d\n", arg1 * arg2);
    }
    else if (strcmp(command, "div") == 0)
    {
        printf("%d\n", arg1 / arg2);
    }
    else if (strcmp(command, "negate") == 0)
    {
        printf("%d\n", -arg1);
    }
    else
    {
        printf("Invalid command\n");
    }
}
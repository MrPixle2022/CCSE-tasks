#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>

int main()
{
    while (1)
    {
        printf("calc> ");

        // reading input from user
        char line[100];
        char command[7] = {0};
        int arg1 = 0, arg2 = 0;

        fgets(line, sizeof(line), stdin);
        sscanf(line, "%6s %d %d", command, &arg1, &arg2);

        if (strcmp(command, "quit") == 0)
        {
            printf("Exiting the calculator.\n");
            exit(0);
        }

        // fork a child proccess
        pid_t pid = fork();

        // fork failed
        if (pid < 0)
        {
            perror("fork failed");
            exit(1);
        }

        // child process
        else if (pid == 0)
        {
            char arg1_str[32];
            char arg2_str[32];
            snprintf(arg1_str, sizeof(arg1_str), "%d", arg1);
            snprintf(arg2_str, sizeof(arg2_str), "%d", arg2);

            if (strcmp(command, "add") == 0)
            {
                execl("./.build/add", "add", arg1_str, arg2_str, NULL);
                perror("execlp failed");
                exit(1);
            }
            else if (strcmp(command, "sub") == 0)
            {
                execl("./.build/sub", "sub", arg1_str, arg2_str, NULL);
                perror("execlp failed");
                exit(1);
            }
            else if (strcmp(command, "mul") == 0)
            {
                execl("./.build/mul", "mul", arg1_str, arg2_str, NULL);
                perror("execlp failed");
                exit(1);
            }
            else if (strcmp(command, "negate") == 0)
            {
                execl("./.build/negate", "negate", arg1_str, NULL);
                perror("execlp failed");
                exit(1);
            }
            else
            {
                fprintf(stderr, "Unknown command: %s\n", command);
                continue;
            }
        }
        else
        {
            int status;
            waitpid(pid, &status, 0);

            if (WIFEXITED(status))
            {
                printf("Child process with pid: %d has exited with status: %d\n", pid, WEXITSTATUS(status));
            }
            else if (WIFSIGNALED(status))
            {
                printf("Child process with pid: %d was terminated by signal: %d\n", pid, WTERMSIG(status));
            }
        }
    }
}

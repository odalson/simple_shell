#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ARG_SIZE 64

void read_input(char *input) {
    printf("shell> ");
    fgets(input, MAX_INPUT_SIZE, stdin);

    // Remove the trailing newline character
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }
}

void parse_input(char *input, char **args, int *num_args) {
    *num_args = 0;
    char *token = strtok(input, " ");
    
    while (token != NULL) {
        args[(*num_args)++] = token;
        token = strtok(NULL, " ");
    }

    args[*num_args] = NULL;
}

int execute_command(char **args) {
    pid_t pid, wait_pid;
    int status;

    pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0)
    {
        if (execvp(args[0], args) == -1) {
            perror("shell");
        }
        exit(EXIT_FAILURE);
    } else {
	    do {
            wait_pid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));

        return 1;  
    }
}

int main() {
    char input[MAX_INPUT_SIZE];
    char *args[MAX_ARG_SIZE];
    int num_args;

    while (1) {
        read_input(input);

        if (strcmp(input, "exit") == 0) {
            break; 
        }

        parse_input(input, args, &num_args);

        if (num_args > 0) {
            execute_command(args);
        }
    }

    return 0;
}


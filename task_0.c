/*
 * This is a program that passes betty checks.
 */
#include "shell.h"
#include <stdio.h>

#define CMD_NORM 0
#define CMD_OR   1
#define CMD_AND  2
#define CMD_CHAIN 3

/*
 * Function: main
 * The main function of the program.
 * Returns: 0 on success.
 */
int main(void)
{
    int command = CMD_NORM;

    switch (command) {
        case CMD_NORM:
            printf("Normal command\n");
            break;
        case CMD_OR:
            printf("Logical OR command\n");
            break;
        case CMD_AND:
            printf("Logical AND command\n");
            break;
        case CMD_CHAIN:
            printf("Chaining command\n");
            break;
        default:
            fprintf(stderr, "Unknown command\n");
            return 1;
    }

    return 0;
}


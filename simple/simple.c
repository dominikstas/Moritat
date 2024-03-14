#include "simple.h"

void execute(char *command) {
    if (strncmp(command, "echo ", 4) == 0) {
        char *text = command + 5; 
        if (strlen(text) > 0) {
            echo(text);
        } else {
            printf("Usage: echo [text]\n");
        }
    } else if (strcmp(command, "exit") == 0) {
        exitS();
    } else if (strcmp(command, "help") == 0) {
        help();
    } else if (strncmp(command, "cd ", 3) == 0) {
        char *dir = command + 3;
        if(chdir(dir) != 0) {
            perror("cd");
        }
    } else if (strcmp(command, "ls") == 0) {
        DIR *d;
        struct dirent *dir;
        d = opendir(".");
        if (d) {
            while ((dir = readdir(d)) != NULL) {
                printf("%s\n", dir->d_name);
            }
            closedir(d);
        }
    } else if (strncmp(command, "mkdir ", 6) == 0) {
        char *dir = command + 6;
        if(mkdir(dir, 0777) != 0) {
            perror("mkdir");
        }
    } else {
        printf("Unknown command: %s\n", command);
    }
}

void echo(char *text) {
    printf("%s\n", text);
}

void exitS() {
    printf("Thanks for using\n");
    exit(0);
}

void help() {
    printf("--------------------------------------\n");
    printf("All commands:\n");
    printf("help - show all commands\n");
    printf("echo [text] - write a text\n");
    printf("cd [directory] - change directory\n");
    printf("ls - list directory contents\n");
    printf("mkdir [directory] - create a directory\n");
    printf("exit - exit the terminal\n");
    printf("--------------------------------------\n");
}

void init(){
    system("clear");
    printf("Welcome!\n");
}

char* getInput(){
    char *input = NULL;
    size_t bufferSize = 0;

    getline(&input, &bufferSize, stdin);
    input[strcspn(input, "\n")] = '\0';

    return input;
}

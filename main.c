#include "simple/simple.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>

#define MAX_PATH_LENGTH 256

void displayWelcomeMessage() {
    printf("Welcome to Moritat - Your compiling best friend!\n");
}

void changeToUserHomeDirectory() {
    if (chdir(getenv("HOME")) != 0) {
        perror("Error changing to home directory");
    }
}

void listFilesInCurrentDirectory() {
    DIR *dir;
    struct dirent *entry;

    dir = opendir(".");
    if (dir == NULL) {
        perror("Error opening directory");
        return;
    }

    printf("Files in current directory:\n");
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    closedir(dir);
}

void displayHelp() {
    printf("Available commands:\n");
    printf("  compile <filename.adb|filename.c|filename.cpp> - Compile the specified file\n");
    printf("  ls - List files in the current directory\n");
    printf("  cd <directory> - Change current directory\n");
    printf("  help - Display this help message\n");
    printf("  exit - Exit Moritat\n");
}

void compileAdaFile(const char *filename) {
    char compileCommand[MAX_PATH_LENGTH + 20];
    snprintf(compileCommand, sizeof(compileCommand), "gnatmake %s", filename);
    int result = system(compileCommand);

    if (result == 0) {
        printf("Compilation successful. You can run the Ada project using: ./%s\n", filename);
    } else {
        printf("Error during Ada compilation.\n");
    }
}

void compileCFile(const char *filename) {
    char compileCommand[MAX_PATH_LENGTH + 20];
    snprintf(compileCommand, sizeof(compileCommand), "gcc %s -o %s.out", filename, filename);
    int result = system(compileCommand);

    if (result == 0) {
        printf("Compilation successful. You can run the executable using: ./%s.out\n", filename);
    } else {
        printf("Error during C compilation.\n");
    }
}

void compileCPPFile(const char *filename) {
    char compileCommand[MAX_PATH_LENGTH + 20];
    snprintf(compileCommand, sizeof(compileCommand), "g++ %s -o %s.out", filename, filename);
    int result = system(compileCommand);

    if (result == 0) {
        printf("Compilation successful. You can run the executable using: ./%s.out\n", filename);
    } else {
        printf("Error during C++ compilation.\n");
    }
}

void compileAndRun(const char *filename) {
    const char *extension = strrchr(filename, '.');
    if (extension == NULL) {
        fprintf(stderr, "Invalid file format. Please provide a file with a recognized extension.\n");
        return;
    }

    if (strcmp(extension, ".adb") == 0) {
        compileAdaFile(filename);
    } else if (strcmp(extension, ".py") == 0) {
        printf("You can run the Python script using: python %s\n", filename);
    } else if (strcmp(extension, ".c") == 0) {
        compileCFile(filename);
    } else if (strcmp(extension, ".cpp") == 0) {
        compileCPPFile(filename);
    } else {
        fprintf(stderr, "Unsupported file extension. Moritat currently supports Ada, C, C++, and Python.\n");
    }
}

void executeCommand(const char *userCommand) {
    if (strncmp(userCommand, "compile", 7) == 0) {
        char filename[MAX_PATH_LENGTH];
        sscanf(userCommand, "compile %s", filename);
        compileAndRun(filename);
    } else if (strcmp(userCommand, "ls") == 0) {
        listFilesInCurrentDirectory();
    } else if (strncmp(userCommand, "cd", 2) == 0) {
        char directory[MAX_PATH_LENGTH];
        sscanf(userCommand, "cd %s", directory);
        if (chdir(directory) != 0) {
            perror("Error changing directory");
        }
    } else if (strcmp(userCommand, "help") == 0) {
        displayHelp();
    } else if (strcmp(userCommand, "exit") == 0) {
        exit(0);
    } else {
        fprintf(stderr, "Unknown command: %s\n", userCommand);
    }
}

int main(int argc, char *argv[]) {
    displayWelcomeMessage();
    changeToUserHomeDirectory();

    while (1) {
        char userCommand[MAX_PATH_LENGTH];
        printf("Moritat> ");
        if (fgets(userCommand, sizeof(userCommand), stdin) == NULL) {
            perror("Error reading input");
            continue;
        }

        userCommand[strcspn(userCommand, "\n")] = 0;
        executeCommand(userCommand);
    }

    return 0;
}

#include "simple/simple.h"

#define MAX_PATH_LENGTH 256

void displayWelcomeMessage() {
    printf("Welcome to Moritat - Your compiling best friend!\n");
}

void changeToUserHomeDirectory() {
    chdir(getenv("HOME"));
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
    printf("  compile <filename.adb|filename.py|filename.c|filename.cpp> - Compile the specified file\n");
    printf("  ls - List files in the current directory\n");
    printf("  cd <directory> - Change current directory\n");
    printf("  help - Display this help message\n");
    printf("  exit - Exit Moritat\n");
}

void compileAndRun(char *filename) {
    const char *extension = strrchr(filename, '.');
    if (extension == NULL) {
        fprintf(stderr, "Invalid file format. Please provide a file with a recognized extension.\n");
        return;
    }

    if (strcmp(extension, ".adb") == 0) {
        // Ada compilation
        char compileCommand[MAX_PATH_LENGTH + 20];
        snprintf(compileCommand, sizeof(compileCommand), "gnatmake %s", filename);
        int result = system(compileCommand);

        // Check if compiled correctly
        if (result == 0) {
            printf("Compilation successful. You can run the Ada project using: ./%s\n", filename);
        } else {
            printf("Error during Ada compilation.\n");
        }
    } else if (strcmp(extension, ".py") == 0) {
        // Python run
        printf("You can run the Python script using: python %s\n", filename);
    } else if (strcmp(extension, ".c") == 0) {
        // C code
        char compileCommand[MAX_PATH_LENGTH + 20];
        snprintf(compileCommand, sizeof(compileCommand), "gcc %s -o %s.out", filename, filename);
        int result = system(compileCommand);

        // Check if compiled correctly
        if (result == 0) {
            printf("Compilation successful. You can run the executable using: ./%s.out\n", filename);
        } else {
            printf("Error during C compilation.\n");
        }

    } else if (strcmp(extension, ".cpp") == 0) {
        // C++ code
        char compileCommand[MAX_PATH_LENGTH + 20];
        snprintf(compileCommand, sizeof(compileCommand), "g++ %s -o %s.out", filename, filename);
        int result = system(compileCommand);

        // Check if compiled correctly
        if (result == 0) {
            printf("Compilation successful. You can run the executable using: ./%s.out\n", filename);
        } else {
            printf("Error during C++ compilation.\n");
        }

    } else {
        fprintf(stderr, "Unsupported file extension. Moritat currently supports Ada, Python, C, and C++.\n");
    }
}

int main(int argc, char *argv[]) {
    // Display welcome message
    displayWelcomeMessage();

    // Change to user's home directory
    changeToUserHomeDirectory();

    // Infinite loop for user interaction
    while (1) {
        char userCommand[MAX_PATH_LENGTH];
        printf("Moritat> ");
        fgets(userCommand, sizeof(userCommand), stdin);

        // Remove trailing newline character
        userCommand[strcspn(userCommand, "\n")] = 0;

        // Check for various commands
        if (strncmp(userCommand, "compile", 7) == 0) {
            // Extract the file name
            char filename[MAX_PATH_LENGTH];
            sscanf(userCommand, "compile %s", filename);

            // Compile and run based on the file extension
            compileAndRun(filename);
        } else if (strncmp(userCommand, "ls", 2) == 0) {
            // List files in the current directory
            listFilesInCurrentDirectory();
        } else if (strncmp(userCommand, "cd", 2) == 0) {
            // Change current directory
            char directory[MAX_PATH_LENGTH];
            sscanf(userCommand, "cd %s", directory);
            if (chdir(directory) != 0) {
                perror("Error changing directory");
            }
        } else if (strncmp(userCommand, "help", 4) == 0) {
            // Display help
            displayHelp();
        } else if (strncmp(userCommand, "exit", 4) == 0) {
            // Exit the program
            break;
        } else {
            // Handle other commands or provide feedback
            execute(userCommand);
        }
    }

    return 0;
}

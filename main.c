#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>

#define MAX_PATH_LENGTH 256

void displayWelcomeMessage() {
    printf("Welcome to Moritat - Your Ada best friend!\n");
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
    printf("  compile <filename.adb> - Compile Ada file\n");
    printf("  ls - List files in the current directory\n");
    printf("  cd <directory> - Change current directory\n");
    printf("  help - Display this help message\n");
    printf("  exit - Exit Moritat\n");
}

int main(int argc, char *argv[]) {
    // Display welcome message
    displayWelcomeMessage();

    // Change to user's home directory
    changeToUserHomeDirectory();

    // Infinite loop for user interaction
    while (1) {
        char userCommand[100];
        printf("Moritat> ");
        fgets(userCommand, sizeof(userCommand), stdin);

        // Remove trailing newline character
        userCommand[strcspn(userCommand, "\n")] = 0;

        // Check for various commands
        if (strncmp(userCommand, "compile", 7) == 0) {
            // Extract the Ada file name
            char adaFileName[MAX_PATH_LENGTH];
            sscanf(userCommand, "compile %s", adaFileName);

            // Check the extension
            const char *extension = ".adb";
            if (strstr(adaFileName, extension) == NULL) {
                fprintf(stderr, "Invalid file format. Please provide a file with the .adb extension.\n");
            } else {
                // Compile
                char compileCommand[MAX_PATH_LENGTH + 20];
                snprintf(compileCommand, sizeof(compileCommand), "gnatmake %s", adaFileName);
                int result = system(compileCommand);

                // Check if compiled correctly
                if (result == 0) {
                    printf("Compilation successful. You can run the project using: ./%s\n", adaFileName);
                    break; // Exit the loop and terminate the program
                } else {
                    printf("Error during compilation.\n");
                }
            }
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
            printf("Unknown command or invalid syntax.\n");
        }
    }

    return 0;
}

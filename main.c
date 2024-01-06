#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // Check the arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    // Get Ada file name (with .adb)
    const char* adaFileName = argv[1];

    // Check the extension
    const char* extension = ".adb";
    if (strstr(adaFileName, extension) == NULL) {
        fprintf(stderr, "Invalid file format. Please provide a file with the .adb extension.\n");
        return 1;
    }

    // Get Ada file name without .adb
    char executableName[100];
    snprintf(executableName, sizeof(executableName), "./%.*s", (int)(strlen(adaFileName) - strlen(extension)), adaFileName);

    // Compile
    char compileCommand[100];
    snprintf(compileCommand, sizeof(compileCommand), "gnatmake %s", adaFileName);
    int result = system(compileCommand);

    // Check if compile correctly
    if (result == 0) {
        printf("Compilation successful. Run '%s'\n", executableName);
    } else {
        printf("Error during compilation.\n");
    }

    return 0;
}

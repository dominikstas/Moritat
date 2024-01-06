#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // Sprawdzenie, czy podano poprawną liczbę argumentów
    if (argc != 2) {
        fprintf(stderr, "Uzycie: %s <plik>\n", argv[0]);
        return 1;
    }

    // Pobranie nazwy pliku Ada z argumentów
    const char* adaFileName = argv[1];

    // Sprawdzenie czy podany plik ma rozszerzenie .adb
    const char* extension = ".adb";
    if (strstr(adaFileName, extension) == NULL) {
        fprintf(stderr, "Bledny format pliku. Podaj plik z rozszerzeniem .adb.\n");
        return 1;
    }

    // Usunięcie rozszerzenia .adb
    char executableName[100];
    snprintf(executableName, sizeof(executableName), "./%.*s", (int)(strlen(adaFileName) - strlen(extension)), adaFileName);

    // Komenda do kompilacji programu w Ada
    char compileCommand[100];
    snprintf(compileCommand, sizeof(compileCommand), "gnatmake %s", adaFileName);

    // Uruchomienie komendy za pomocą funkcji system
    int result = system(compileCommand);

    // Sprawdzenie wyniku wykonania komendy
    if (result == 0) {
        printf("Kompilacja zakonczona pomyslnie. Uruchom '%s'\n", executableName);
    } else {
        printf("Blad podczas kompilacji.\n");
    }

    return 0;
}

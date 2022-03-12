#include "readfile.h"

char *readFile(char *path) {
    FILE* ptr = NULL;
    char ch = '\0';
    char *input = malloc(sizeof(char));

    memset(input, 0, sizeof(char));
    ptr = fopen(path, "r");

    if (ptr == NULL) {
        return NULL;
    }

    int i = 0;

    do {
        ch = fgetc(ptr);
        input[i++] = ch;
        input = realloc(input, ((strlen(input)) + 1) * sizeof(char));
        input[i] = '\0';
    } while (ch != EOF);

    fclose(ptr);

    return input;
}

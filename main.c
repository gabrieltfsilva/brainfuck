/*
 * Instructions
 *
 * > = Moves memory pointer to the right by 1 block.
 * < = Moves memory pointer to the left by 1 block.
 * + = Increases the memory value by 1.
 * - = Decreases the memory value by 1.
 * [ = Starts a loop.
 * ] = If current blocks's value is not zero, goes to [.
 * , = Input 1 character from the console.
 * . = Print 1 character to the console.
 *
 * Memory map
 *
 * Addresses: 0 - 60,000 (0x0000 - 0xEA60)
 * Starting Address: 30,000 (0x7530)
 *
 * */

#include "brainfuck.h"
#include "readfile.h"

#define NUM_PARAMETERS 3

/* #define DEBUG 1 */

void howToUse();

int main(int argc, char *argv[]) {

    #ifdef DEBUG

        brainfuckInterpreter(
            "<++++++++++++++++++"
            "+++++++++++++++++++"
            "+++++++++++++++++++"
            "++++++++++++++++.+."
        );

        printf("\n");

    #else

        char *input;

        if (argc < NUM_PARAMETERS) {
            printf("Missing arguments for parameters in call.\n\n");
            howToUse();
            return 0;
        } else if (argc > NUM_PARAMETERS) {
            printf("Too much arguments for parameters in call.\n\n");
            howToUse();
            return 0;
        } else if (strcmp(argv[1], "-s") && strcmp(argv[1], "-f")) {
            printf("Incorrect arguments for parameters in call.\n\n");
            howToUse();
            return 0;
        } else if (!strcmp(argv[1], "-s")) {
            input = argv[2];

            if (strlen(input) > 100) {
                printf("The string is too long. Use a file.\n\n");
                howToUse();
                return 0;
            } else if (strlen(input) == 0) {
                printf("The string is too short.\n\n");
                howToUse();
                return 0;
            }
        } else if (!strcmp(argv[1], "-f")) {
            input = readFile(argv[2]);

            if (input == NULL) {
                printf("Could not open input file.\n\n");
                howToUse();
                return 0;
            }

            if (strlen(input) > 50000) {
                printf("The file is too long.\n\n");
                howToUse();
                return 0;
            } else if (strlen(input) == 0) {
                printf("The file is too short.\n\n");
                howToUse();
                return 0;
            }
        }

        brainfuckInterpreter(input);

    #endif // DEBUG

    return 0;
}

void howToUse() {
    printf("How to use:\n");
    printf("brainfuck.exe -s \"string\"\n");
    printf("brainfuck.exe -f \"file.bf\"\n");
    printf("String: maximum 100 characters.\n");
    printf("File: maximum 50,000 characters.\n\n");
}

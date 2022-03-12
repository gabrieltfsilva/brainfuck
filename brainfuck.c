#include "brainfuck.h"

bool brainfuckInterpreter(char *input) {
    cells = malloc(sizeof(MemoryCell));
    memset(cells, 0, sizeof(MemoryCell));
    cells->index = START_ADDRESS;
    cells->value = 0;
    cells->previous = NULL;
    cells->next = NULL;

    currentCell = cells;

    int i = 0;

    for (i = 0; i < strlen(input); i++)
        doInstruction(input[i], &i, cells);

    return true;
}

bool doInstruction(char input, ushort *stringPosition, MemoryCell *cell) {
    static ushort lastAddress = 0;
    static ushort cellsPointer = 0;
    static ushort strintPointer = 0;

    switch (input) {
        case '>':
            instruction1(currentCell, &cellsPointer, &lastAddress);
            break;
        case '<':
            instruction2(currentCell, &cellsPointer);
            break;
        case '+':
            instruction3(currentCell);
            break;
        case '-':
            instruction4(currentCell);
            break;
        case '[':
            instruction5(currentCell, stringPosition, &strintPointer);
            break;
        case ']':
            instruction6(currentCell, stringPosition, strintPointer);
            break;
        case ',':
            instruction7(currentCell);
            break;
        case '.':
            instruction8(currentCell);
            break;
        default:
            return false; /* Any other character is ignored. Comments */
    }

    return true;
}

bool instruction1(MemoryCell *cell, ushort *cellsPointer, ushort *lastAddress) { /* > */
    if (*cellsPointer < (MAX_MEMORY_SIZE - 1)) {
        (*cellsPointer)++;
        if (*lastAddress < *cellsPointer) {
            *lastAddress = *cellsPointer;
            cells = realloc(cells, sizeof(MemoryCell));
            MemoryCell *newCell = malloc(sizeof(MemoryCell));
            memset(newCell, 0, sizeof(MemoryCell));
            newCell->index = currentCell + 1;
            newCell->value = 0;
            newCell->previous = currentCell;
            newCell->next = NULL;
            currentCell->next = newCell;
            currentCell = newCell;
        } else {
            currentCell = currentCell->next;
        }
    } else {
        return false;
    }

    return true;
}

bool instruction2(MemoryCell *cell, ushort *cellsPointer) { /* < */
    if (*cellsPointer > 0) {
        (*cellsPointer)--;
        currentCell = currentCell->previous;
    } else {
        return false;
    }

    return true;
}

void instruction3(MemoryCell *cell) { /* + */
    cell->value++;
}

void instruction4(MemoryCell *cell) { /* - */
    cell->value--;
}

void instruction5(MemoryCell *cell, ushort *stringPosition, ushort *stringPointer) { /* [ */
    *stringPointer = *stringPosition;
}

void instruction6(MemoryCell *cell, ushort *stringPosition, ushort stringPointer) { /* ] */
    *stringPosition = (cell->value != 0) ? stringPointer : *stringPosition;
}

void instruction7(MemoryCell *cell) { /* , */
    cell->value = getchar();
}

void instruction8(MemoryCell *cell) { /* . */
    putchar(cell->value);
}

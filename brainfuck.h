#ifndef BRAINFUCK_H_INCLUDED
#define BRAINFUCK_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define MAX_MEMORY_SIZE 0xEA60 /* 60,000 */
#define START_ADDRESS   0xEA60 /* 30,000 */

typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;
typedef enum {false, true} bool;

struct memoryCell {
    ushort index;
    uchar value;
    struct memoryCell *previous;
    struct memoryCell *next;
};

typedef struct memoryCell MemoryCell;

MemoryCell *cells;
MemoryCell *currentCell;

bool brainfuckInterpreter(char *);

bool doInstruction(char, ushort *, MemoryCell *);

bool instruction1(MemoryCell *, ushort *, ushort *);

bool instruction2(MemoryCell *, ushort *);

void instruction3(MemoryCell *);

void instruction4(MemoryCell *);

void instruction5(MemoryCell *, ushort *, ushort *);

void instruction6(MemoryCell *, ushort *, ushort);

void instruction7(MemoryCell *);

void instruction8(MemoryCell *);

#endif // BRAINFUCK_H_INCLUDED

#ifndef GAME_ARM9_OS_ALLOC_H
#define GAME_ARM9_OS_ALLOC_H

#include "../types.h"
#include "../sdk_os.h"

/* Heap bookkeeping of the OS allocator. */

typedef struct Cell Cell;

struct Cell {
    Cell *prev;
    Cell *next;
    long size;
};

typedef struct HeapDesc {
    long size;
    Cell *free;
    Cell *allocated;
} HeapDesc;

typedef struct OSHeapInfo {
    volatile int currentHeap;
    int numHeaps;
    void *arenaStart;
    void *arenaEnd;
    HeapDesc *heapArray;
} OSHeapInfo;

Cell *DLAddFront(Cell *r0, Cell *r1);
Cell *DLExtract(Cell *list, Cell *node);
Cell *DLInsert(Cell *list, Cell *cell);
void *OS_AllocFromHeap(int id, int heap, int size);
void OS_FreeToHeap(int id, int heap, void *ptr);
void *OS_InitAlloc(OSArenaId id, void *arenaStart, void *arenaEnd, int maxHeaps);
int OS_CreateHeap(OSArenaId id, void *start, void *end);
int OS_CreateExtraHeap(OSArenaId id);
long OS_ReferentSize(int id, void *ptr);
BOOL OS_IsOnExtendedMainMemory(void *ptr);
int OS_IsOnVram(void *ptr);

#endif

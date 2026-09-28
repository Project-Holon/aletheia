/*
 * function: func_02086AF8
 * address:  0x02086AF8
 * packet:   pkt_02086AF8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      OS_CreateHeap (os_alloc.o)
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   OSiHeapInfo           0x0215126C  data
 */

typedef unsigned long u32;
typedef long s32;
typedef unsigned char u8;
typedef int BOOL;
typedef u32 OSIntrMode;

typedef enum OSArenaId {
    OS_ARENA_MAIN = 0,
    OS_ARENA_MAIN_SUBPRIV = 1,
    OS_ARENA_MAINEX = 2,
    OS_ARENA_ITCM = 3,
    OS_ARENA_DTCM = 4,
    OS_ARENA_SHARED = 5,
    OS_ARENA_WRAM_MAIN = 6,
    OS_ARENA_WRAM_SUB = 7,
    OS_ARENA_WRAM_SUBPRIV = 8,
    OS_ARENA_MAX = 9
} OSArenaId;

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

extern OSHeapInfo *OSiHeapInfo[OS_ARENA_MAX];

extern OSIntrMode OS_DisableInterrupts(void);
extern OSIntrMode OS_RestoreInterrupts(OSIntrMode state);

#define OSi_ROUND(n, a)     (((u32)(n) + (a) - 1) & ~((a) - 1))
#define OSi_TRUNC(n, a)     (((u32)(n)) & ~((a) - 1))

int func_02086AF8(OSArenaId id, void *start, void *end)
{
    OSIntrMode enabled;
    OSHeapInfo *heapInfo;
    int heap;
    HeapDesc *hd;
    Cell *cell;

    enabled = OS_DisableInterrupts();
    heapInfo = OSiHeapInfo[id];

    start = (void *)OSi_ROUND(start, 32);
    end = (void *)OSi_TRUNC(end, 32);

    for (heap = 0; heap < heapInfo->numHeaps; heap++) {
        hd = &heapInfo->heapArray[heap];
        if (hd->size < 0) {
            hd->size = (u8 *)end - (u8 *)start;

            cell = (Cell *)start;
            cell->prev = 0;
            cell->next = 0;
            cell->size = hd->size;

            hd->free = cell;
            hd->allocated = 0;

            (void)OS_RestoreInterrupts(enabled);
            return heap;
        }
    }

    (void)OS_RestoreInterrupts(enabled);
    return -1;
}

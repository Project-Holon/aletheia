/*
 * function: func_02086A50
 * address:  0x02086A50
 * packet:   pkt_02086A50
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      OS_InitAlloc (os_alloc.o)
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

void *func_02086A50(OSArenaId id, void *arenaStart, void *arenaEnd, int maxHeaps)
{
    OSHeapInfo *heapInfo;
    u32 arraySize;
    int i;
    OSIntrMode enabled;

    enabled = OS_DisableInterrupts();

    heapInfo = (OSHeapInfo *)arenaStart;
    OSiHeapInfo[id] = heapInfo;

    arraySize = sizeof(HeapDesc) * maxHeaps;
    heapInfo->heapArray = (HeapDesc *)((u32)arenaStart + sizeof(OSHeapInfo));
    heapInfo->numHeaps = maxHeaps;

    for (i = 0; i < heapInfo->numHeaps; i++) {
        HeapDesc *hd = &heapInfo->heapArray[i];

        hd->size = -1;
        hd->free = hd->allocated = 0;
    }

    heapInfo->currentHeap = -1;

    arenaStart = (void *)((u32)heapInfo->heapArray + arraySize);
    heapInfo->arenaStart = (void *)OSi_ROUND(arenaStart, 32);
    heapInfo->arenaEnd = (void *)OSi_TRUNC(arenaEnd, 32);

    (void)OS_RestoreInterrupts(enabled);
    return heapInfo->arenaStart;
}

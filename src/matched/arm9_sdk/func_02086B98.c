/*
 * function: OS_CreateExtraHeap
 * address:  0x02086B98
 * packet:   pkt_02086B98
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      OS_CreateExtraHeap (os_alloc.o)
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   OS_IsRunOnTwl         0x02085D3C  arm
 *   OSiHeapInfo           0x0215126C  data
 *   g_020A86AC            0x020A86AC  data
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

/* os_alloc.o .data from 0x020A86AC, addressed from one pool word. */
typedef struct OsAllocData {
    int OSi_ExtraHeapHandle;
    OSArenaId OSi_ExtraHeapArenaId;
} OsAllocData;

extern OsAllocData g_020A86AC;
extern BOOL OS_IsRunOnTwl(void);

int OS_CreateExtraHeap(OSArenaId id)
{
    OSHeapInfo *heapInfo;
    int heap;
    HeapDesc *hd;
    OSIntrMode enabled;

    enabled = OS_DisableInterrupts();
    heapInfo = OSiHeapInfo[id];

    if (!OS_IsRunOnTwl() && g_020A86AC.OSi_ExtraHeapHandle < 0) {
        for (heap = 0; heap < heapInfo->numHeaps; heap++) {
            hd = &heapInfo->heapArray[heap];
            if (hd->size < 0) {
                Cell *cell = (Cell *)0x02000000;

                hd->size = 0x4000;
                cell->prev = 0;
                cell->next = 0;
                cell->size = 0x4000;
                hd->free = cell;
                hd->allocated = 0;

                g_020A86AC.OSi_ExtraHeapHandle = heap;
                g_020A86AC.OSi_ExtraHeapArenaId = id;

                (void)OS_RestoreInterrupts(enabled);
                return heap;
            }
        }
    }

    (void)OS_RestoreInterrupts(enabled);
    return -1;
}

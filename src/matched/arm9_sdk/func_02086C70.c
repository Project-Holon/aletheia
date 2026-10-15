/*
 * function: OS_IsOnExtendedMainMemory
 * address:  0x02086C70
 * packet:   pkt_02086C70
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      OS_IsOnExtendedMainMemory (os_alloc.o)
 *
 * symbols:
 *   OS_IsRunOnTwl  0x02085D3C  arm
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

extern BOOL OS_IsRunOnTwl(void);

BOOL OS_IsOnExtendedMainMemory(void *ptr)
{
    if (OS_IsRunOnTwl()) {
        if (0x0D000000 <= (u32)ptr && (u32)ptr < 0x0E000000) {
            return 1;
        }
        return 0;
    } else {
        if (0x02400000 <= (u32)ptr && (u32)ptr < 0x02800000) {
            return 1;
        }
        return 0;
    }
}

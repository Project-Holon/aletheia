/*
 * function: func_020864FC
 * address:  0x020864FC
 * packet:   pkt_020864FC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      OS_InitArenaEx (os_arena.o)
 *
 * symbols:
 *   OS_GetConsoleType         0x02085CBC  arm
 *   OS_GetInitArenaHi         0x02086594  arm
 *   OS_SetArenaHi             0x02086760  arm
 *   OS_GetInitArenaLo         0x02086694  arm
 *   OS_SetArenaLo             0x02086774  arm
 *   OS_IsRunOnTwl             0x02085D3C  arm
 *   OS_SetProtectionRegionEx  0x02086DB0  arm
 *   OSi_InitArenaEx_ltdmain   0x027312B4  arm
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

extern u32 OS_GetConsoleType(void);
extern void *OS_GetInitArenaHi(OSArenaId id);
extern void *OS_GetInitArenaLo(OSArenaId id);
extern void OS_SetArenaHi(OSArenaId id, void *newHi);
extern void OS_SetArenaLo(OSArenaId id, void *newLo);
extern BOOL OS_IsRunOnTwl(void);
extern void OS_SetProtectionRegionEx(int regionNo, u32 address, u32 sizeDef);
extern void OSi_InitArenaEx_ltdmain(void);

void func_020864FC(void)
{
    (void)OS_GetConsoleType();

    OS_SetArenaHi(OS_ARENA_MAINEX, OS_GetInitArenaHi(OS_ARENA_MAINEX));
    OS_SetArenaLo(OS_ARENA_MAINEX, OS_GetInitArenaLo(OS_ARENA_MAINEX));

    if (!OS_IsRunOnTwl()) {
        OS_SetProtectionRegionEx(1, 0x02000000, 0x2A);
        OS_SetProtectionRegionEx(2, 0x027FF000, 0x16);
    } else {
        OSi_InitArenaEx_ltdmain();
    }
}

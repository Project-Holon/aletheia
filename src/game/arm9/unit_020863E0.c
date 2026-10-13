/*
 * file:     unit_020863E0.c
 * unit:     yes
 * function: func_020863E0, func_020864FC, func_0208656C, func_02086580, func_02086594, func_02086694, func_02086760, func_02086774, func_02086788
 * address:  0x020863E0
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_02151264  0x02151264  data
 *   OS_GetConsoleType         0x02085CBC  arm
 *   OS_SetArenaHi             0x02086760  arm
 *   OS_SetArenaLo             0x02086774  arm
 *   OS_IsRunOnTwl             0x02085D3C  arm
 *   OS_SetProtectionRegionEx  0x02086DB0  arm
 *   OSi_InitArenaEx_ltdmain   0x027312B4  arm
 *   func_02085D3C 0x02085D3C arm
 *   func_02085CBC 0x02085CBC arm
 *   SDK_SYS_STACKSIZE             0x00001800  data
 *   SDK_IRQ_STACKSIZE             0x00000800  data
 *   SDK_AUTOLOAD_DTCM_START       0x02FE0000  data
 *   SDK_SECTION_ARENA_DTCM_START  0x02FE00C0  data
 *   SDK_LTDMAIN_ARENA_LO          0x02735B40  data
 *   SDK_MAIN_ARENA_LO             0x02213D20  data
 *   SDK_LTDMAIN_EX_ARENA_LO       0x0D000000  data
 *   SDK_SECTION_ARENA_EX_START    0x02400060  data
 *   SDK_SECTION_ARENA_ITCM_START  0x01FF8820  data
 */
typedef unsigned int u32_020863E0;

typedef unsigned long u32_020864FC;

typedef long s32;

typedef unsigned char u8;

typedef int BOOL;

typedef u32_020864FC OSIntrMode;

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

typedef unsigned int u32_0208656C;

typedef unsigned int u32_02086580;

typedef unsigned int   u32_4;

typedef unsigned int   u32_5;

typedef unsigned int u32_02086760;

typedef unsigned int u32_02086774;

typedef unsigned int u32_02086788;

extern u32_020863E0  func_02086594(u32_020863E0 a0);
extern u32_020863E0  func_02086694(u32_020863E0 a0);
extern OSIntrMode OS_DisableInterrupts(void);
extern OSIntrMode OS_RestoreInterrupts(OSIntrMode state);
extern u32_020864FC OS_GetConsoleType(void);
extern void OS_SetArenaHi(OSArenaId id, void *newHi);
extern void OS_SetArenaLo(OSArenaId id, void *newLo);
extern BOOL OS_IsRunOnTwl(void);
extern void OS_SetProtectionRegionEx(int regionNo, u32_020864FC address, u32_020864FC sizeDef);
extern void OSi_InitArenaEx_ltdmain(void);
extern int func_02085D3C(void);
extern u32_4 func_02085CBC(void);
void func_020863E0(void);
void func_020864FC(void);
u32_0208656C func_0208656C(u32_0208656C idx);
u32_02086580 func_02086580(u32_02086580 idx);
void *OS_GetInitArenaHi(int id);
void *OS_GetInitArenaLo(int id);
void func_02086760(u32_02086760 idx, u32_02086760 val);
void func_02086774(u32_02086774 idx, u32_02086774 val);
u32_02086788 func_02086788(u32_02086788 r7, u32_02086788 r6, u32_02086788 r5);
typedef struct OsArenaBss {
    u32_020863E0 isInitialized;
    u32_020863E0 exArenaEnabled;
} OsArenaBss;

extern OsArenaBss g_02151264;
extern char SDK_AUTOLOAD_DTCM_START[];
extern char SDK_SYS_STACKSIZE[];
extern char SDK_IRQ_STACKSIZE[];
extern char SDK_SECTION_ARENA_DTCM_START[];
extern char SDK_LTDMAIN_ARENA_LO[];
extern char SDK_MAIN_ARENA_LO[];
extern char SDK_LTDMAIN_EX_ARENA_LO[];
extern char SDK_SECTION_ARENA_EX_START[];
extern char SDK_SECTION_ARENA_ITCM_START[];
extern OSHeapInfo *OSiHeapInfo[OS_ARENA_MAX];


void func_020863E0(void)
{
    u32_020863E0 r5;
    u32_020863E0 r4;

    if (g_02151264.isInitialized != 0) {
        return;
    }
    r5 = 0;
    g_02151264.isInitialized = 1;

    func_02086760(r5, func_02086594(r5));
    func_02086774(r5, func_02086694(r5));

    r4 = 2;
    func_02086774(r4, r5);
    func_02086760(r4, r5);

    r4 = 3;
    func_02086760(r4, func_02086594(r4));
    func_02086774(r4, func_02086694(r4));

    r4 = 4;
    func_02086760(r4, func_02086594(r4));
    func_02086774(r4, func_02086694(r4));

    r4 = 5;
    func_02086760(r4, func_02086594(r4));
    func_02086774(r4, func_02086694(r4));

    r4 = 6;
    func_02086760(r4, func_02086594(r4));
    func_02086774(r4, func_02086694(r4));
}


#define OSi_ROUND(n, a)     (((u32_020864FC)(n) + (a) - 1) & ~((a) - 1))

#define OSi_TRUNC(n, a)     (((u32_020864FC)(n)) & ~((a) - 1))


/*
 * sdk:      OS_InitArenaEx (os_arena.o)
 */
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


u32_0208656C func_0208656C(u32_0208656C idx)
{
    return *(u32_0208656C *)((idx << 2) + 0x02FFFDC4);
}


u32_02086580 func_02086580(u32_02086580 idx)
{
    return *(u32_02086580 *)((idx << 2) + 0x02FFFDA0);
}


void *OS_GetInitArenaHi(int id)
{
    switch (id) {
    case OS_ARENA_MAIN:
        return func_02085D3C() ? (void *)0x02F80000 : (void *)0x023E0000;
    case OS_ARENA_MAINEX:
        {
            void *arena;
            u32_020863E0 type;

            if (g_02151264.exArenaEnabled == 0) {
                return 0;
            }
            type = func_02085CBC() & 0xF;
            if (func_02085D3C()) {
                arena = 0;
                if (type != 4) {
                    arena = (void *)0x0DF00000;
                }
            } else {
                arena = 0;
                if (type != 1) {
                    arena = (void *)0x02700000;
                }
            }
            return arena;
        }
    case OS_ARENA_ITCM:
        return (void *)0x02000000;
    case OS_ARENA_DTCM:
        {
            u32_020863E0 start = (u32_020863E0)SDK_AUTOLOAD_DTCM_START;
            u32_020863E0 end = start + 0x3F80;
            u32_020863E0 top = end - (u32_020863E0)SDK_IRQ_STACKSIZE;
            s32 sysStack = (s32)SDK_SYS_STACKSIZE;

            if (sysStack == 0) {
                u32_020863E0 arena = start;

                if (arena < (u32_020863E0)SDK_SECTION_ARENA_DTCM_START) {
                    arena = (u32_020863E0)SDK_SECTION_ARENA_DTCM_START;
                }
                return (void *)arena;
            }
            if (sysStack < 0) {
                return (void *)((u32_020863E0)SDK_SECTION_ARENA_DTCM_START - sysStack);
            }
            return (void *)(top - sysStack);
        }
    case OS_ARENA_SHARED:
        return (void *)0x02FFF680;
    case OS_ARENA_WRAM_MAIN:
        return (void *)0x03040000;
    default:
        return 0;
    }
}


void *OS_GetInitArenaLo(int id)
{
    switch (id) {
    case OS_ARENA_MAIN:
        return func_02085D3C() ? (void *)SDK_LTDMAIN_ARENA_LO : (void *)SDK_MAIN_ARENA_LO;
    case OS_ARENA_MAINEX:
        {
            void *arena;
            u32_020863E0 type;

            if (g_02151264.exArenaEnabled == 0) {
                return 0;
            }
            type = func_02085CBC() & 0xF;
            if (func_02085D3C()) {
                arena = 0;
                if (type != 4) {
                    arena = (void *)SDK_LTDMAIN_EX_ARENA_LO;
                }
            } else {
                arena = 0;
                if (type != 1) {
                    arena = (void *)SDK_SECTION_ARENA_EX_START;
                }
            }
            return arena;
        }
    case OS_ARENA_ITCM:
        return (void *)SDK_SECTION_ARENA_ITCM_START;
    case OS_ARENA_DTCM:
        return (void *)SDK_SECTION_ARENA_DTCM_START;
    case OS_ARENA_SHARED:
        return (void *)0x02FFF000;
    case OS_ARENA_WRAM_MAIN:
        return (void *)0x03040000;
    default:
        return 0;
    }
}


void func_02086760(u32_02086760 idx, u32_02086760 val)
{
    *(u32_02086760 *)((idx << 2) + 0x02FFFDC4) = val;
}


void func_02086774(u32_02086774 idx, u32_02086774 val)
{
    *(u32_02086774 *)((idx << 2) + 0x02FFFDA0) = val;
}


u32_02086788 func_02086788(u32_02086788 r7, u32_02086788 r6, u32_02086788 r5)
{
    u32_02086788 r0 = func_02086580(r7);
    u32_02086788 r1, r2, r4;

    if (r0 == 0) {
        return 0;
    }
    r1 = r5 - 1;
    r2 = ~r1;
    r0 = r0 + r5 - 1;
    r4 = r2 & r0;

    r0 = r4 + r6;
    r0 = r0 + r5 - 1;
    r5 = r2 & r0;

    if (r5 > func_0208656C(r7)) {
        return 0;
    }

    func_02086774(r7, r5);
    return r4;
}

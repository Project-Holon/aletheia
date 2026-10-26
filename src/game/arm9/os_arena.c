/*
 * file:     os_arena.c
 * unit:     yes
 * function: OS_InitArena, OS_InitArenaEx, OS_GetArenaHi, OS_GetArenaLo, OS_GetInitArenaHi, OS_GetInitArenaLo, OS_SetArenaHi, OS_SetArenaLo, OS_AllocFromArenaLo
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
 *   OS_IsRunOnTwl 0x02085D3C arm
 *   OS_GetConsoleType 0x02085CBC arm
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
#include "../types.h"
#include "../sdk_ioreg.h"

#include "../sdk_os.h"

#include "os_alloc.h"

#include "os_system.h"
#include "os_emulator.h"
extern void OS_SetArenaHi(u32 arenaId, void *newHi);
extern void OS_SetArenaLo(u32 arenaId, void *newLo);
#include "os_protectionregion.h"
#include "../twl/os_arena.h"
void OS_InitArena(void);
void OS_InitArenaEx(void);
void *OS_GetArenaHi(u32 idx);
void *OS_GetArenaLo(u32 idx);
void *OS_GetInitArenaHi(int id);
void *OS_GetInitArenaLo(int id);
void *OS_AllocFromArenaLo(int r7, u32 r6, int r5);
typedef struct OsArenaBss {
    u32 isInitialized;
    u32 exArenaEnabled;
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

void OS_InitArena(void)
{
    u32 mainArenaId;
    u32 arenaId;

    if (g_02151264.isInitialized != 0) {
        return;
    }
    mainArenaId = 0;
    g_02151264.isInitialized = 1;

    OS_SetArenaHi(mainArenaId, OS_GetInitArenaHi((int)(mainArenaId)));
    OS_SetArenaLo(mainArenaId, OS_GetInitArenaLo((int)(mainArenaId)));

    arenaId = 2;
    OS_SetArenaLo(arenaId, (void *)(uptr)mainArenaId);
    OS_SetArenaHi(arenaId, (void *)(uptr)mainArenaId);

    arenaId = 3;
    OS_SetArenaHi(arenaId, OS_GetInitArenaHi((int)(arenaId)));
    OS_SetArenaLo(arenaId, OS_GetInitArenaLo((int)(arenaId)));

    arenaId = 4;
    OS_SetArenaHi(arenaId, OS_GetInitArenaHi((int)(arenaId)));
    OS_SetArenaLo(arenaId, OS_GetInitArenaLo((int)(arenaId)));

    arenaId = 5;
    OS_SetArenaHi(arenaId, OS_GetInitArenaHi((int)(arenaId)));
    OS_SetArenaLo(arenaId, OS_GetInitArenaLo((int)(arenaId)));

    arenaId = 6;
    OS_SetArenaHi(arenaId, OS_GetInitArenaHi((int)(arenaId)));
    OS_SetArenaLo(arenaId, OS_GetInitArenaLo((int)(arenaId)));
}

#define OSi_ROUND(n, a)     (((u32)(n) + (a) - 1) & ~((a) - 1))

#define OSi_TRUNC(n, a)     (((u32)(n)) & ~((a) - 1))

/*
 * sdk:      OS_InitArenaEx (os_arena.o)
 */
void OS_InitArenaEx(void)
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

void *OS_GetArenaHi(u32 arenaId)
{
    return *(void **)((arenaId << 2) + IOREG_ADDR(0x02FFFDC4));
}

void *OS_GetArenaLo(u32 arenaId)
{
    return *(void **)((arenaId << 2) + IOREG_ADDR(0x02FFFDA0));
}

void *OS_GetInitArenaHi(int arenaId)
{
    switch (arenaId) {
    case OS_ARENA_MAIN:
        return OS_IsRunOnTwl() ? (void *)0x02F80000 : (void *)0x023E0000;
    case OS_ARENA_MAINEX:
        {
            void *arena;
            u32 type;

            if (g_02151264.exArenaEnabled == 0) {
                return 0;
            }
            type = OS_GetConsoleType() & 0xF;
            if (OS_IsRunOnTwl()) {
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
            uptr start = (uptr)SDK_AUTOLOAD_DTCM_START;
            uptr end = start + 0x3F80;
            uptr top = end - (uptr)SDK_IRQ_STACKSIZE;
            s32 sysStack = (sptr)SDK_SYS_STACKSIZE;

            if (sysStack == 0) {
                uptr arena = start;

                if (arena < (uptr)SDK_SECTION_ARENA_DTCM_START) {
                    arena = (uptr)SDK_SECTION_ARENA_DTCM_START;
                }
                return (void *)arena;
            }
            if (sysStack < 0) {
                return (void *)((uptr)SDK_SECTION_ARENA_DTCM_START - sysStack);
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

void *OS_GetInitArenaLo(int arenaId)
{
    switch (arenaId) {
    case OS_ARENA_MAIN:
        return OS_IsRunOnTwl() ? (void *)SDK_LTDMAIN_ARENA_LO : (void *)SDK_MAIN_ARENA_LO;
    case OS_ARENA_MAINEX:
        {
            void *arena;
            u32 type;

            if (g_02151264.exArenaEnabled == 0) {
                return 0;
            }
            type = OS_GetConsoleType() & 0xF;
            if (OS_IsRunOnTwl()) {
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

void OS_SetArenaHi(u32 arenaId, void *newHi)
{
    *(void **)((arenaId << 2) + IOREG_ADDR(0x02FFFDC4)) = newHi;
}

void OS_SetArenaLo(u32 arenaId, void *newLo)
{
    *(void **)((arenaId << 2) + IOREG_ADDR(0x02FFFDA0)) = newLo;
}

void *OS_AllocFromArenaLo(int arenaId, u32 size, int alignment)
{
    uptr lo = (uptr)OS_GetArenaLo(arenaId);
    u32 inv;
    u32 mask;
    uptr result;
    uptr newLo;

    if (lo == 0) {
        return 0;
    }
    inv = alignment - 1;
    mask = ~inv;
    lo = lo + alignment - 1;
    result = mask & lo;

    lo = result + size;
    lo = lo + alignment - 1;
    newLo = mask & lo;

    if (newLo > (uptr)OS_GetArenaHi(arenaId)) {
        return 0;
    }

    OS_SetArenaLo(arenaId, (void *)newLo);
    return (void *)result;
}

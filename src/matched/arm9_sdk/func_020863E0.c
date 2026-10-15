/*
 * function: OS_InitArena
 * address:  0x020863E0
 * packet:   pkt_02086374
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02151264  0x02151264  data
 *   OS_SetArenaHi  0x02086760  arm
 *   OS_SetArenaLo  0x02086774  arm
 */

typedef unsigned int u32;

extern u32 g_02151264;

extern u32  func_02086594(u32 a0);
extern void OS_SetArenaHi(u32 a0, u32 a1);
extern u32  func_02086694(u32 a0);
extern void OS_SetArenaLo(u32 a0, u32 a1);

void OS_InitArena(void)
{
    u32 r5;
    u32 r4;

    if (g_02151264 != 0) {
        return;
    }
    r5 = 0;
    g_02151264 = 1;

    OS_SetArenaHi(r5, func_02086594(r5));
    OS_SetArenaLo(r5, func_02086694(r5));

    r4 = 2;
    OS_SetArenaLo(r4, r5);
    OS_SetArenaHi(r4, r5);

    r4 = 3;
    OS_SetArenaHi(r4, func_02086594(r4));
    OS_SetArenaLo(r4, func_02086694(r4));

    r4 = 4;
    OS_SetArenaHi(r4, func_02086594(r4));
    OS_SetArenaLo(r4, func_02086694(r4));

    r4 = 5;
    OS_SetArenaHi(r4, func_02086594(r4));
    OS_SetArenaLo(r4, func_02086694(r4));

    r4 = 6;
    OS_SetArenaHi(r4, func_02086594(r4));
    OS_SetArenaLo(r4, func_02086694(r4));
}

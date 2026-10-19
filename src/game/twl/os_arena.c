/*
 * file:     os_arena.c
 * unit:     yes
 * function: OSi_InitArenaEx_ltdmain
 * address:  0x027312B4
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      libos.TWL.HYB.a os_arena.o
 *
 * symbols:
 *   OS_GetConsoleType  0x02085CBC  arm  arm9
 *   OS_SetProtectionRegionEx  0x02086DB0  arm  arm9
 */

#include "../types.h"

extern unsigned int OS_GetConsoleType(void);
extern void OS_SetProtectionRegionEx(int regionNo, unsigned int address, unsigned int sizeDef);

void OSi_InitArenaEx_ltdmain(void)
{
    OS_GetConsoleType();
    OS_SetProtectionRegionEx(3, 0x8000000, 0x32);
}

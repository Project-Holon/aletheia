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
 */

typedef unsigned int u32;

extern void func_02085CBC(void);
extern void func_02086DB0(u32, u32, u32);

void OSi_InitArenaEx_ltdmain(void)
{
    func_02085CBC();
    func_02086DB0(3, 0x8000000, 0x32);
}

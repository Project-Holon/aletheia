/*
 * file:     os_interrupt.c
 * unit:     yes
 * function: OSi_EnterNDmaCallback_ltdmain
 * address:  0x0273126C
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      libos.TWL.HYB.a os_interrupt.o
 *
 * symbols:
 *   OS_EnableIrqMask  0x02084968  arm  arm9
 */

typedef unsigned int u32;

struct Slot {
    u32 f0;
    u32 f4;
    u32 f8;
};

extern u32 OS_EnableIrqMask(u32);
extern struct Slot data_02150F68[];

void OSi_EnterNDmaCallback_ltdmain(u32 a, u32 b, u32 c)
{
    u32 bit = 1 << (a + 28);
    data_02150F68[a].f0 = b;
    data_02150F68[a].f8 = c;
    data_02150F68[a].f4 = OS_EnableIrqMask(bit) & bit;
}

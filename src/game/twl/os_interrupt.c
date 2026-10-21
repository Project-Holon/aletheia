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
 *   data_02150F68                0x02150F68  data
 */

#include "../types.h"

struct Slot {
    u32 callback;
    u32 prevEnabled;
    u32 arg;
};

#include "../arm9/os_interrupt.h"
extern struct Slot data_02150F68[];

void OSi_EnterNDmaCallback_ltdmain(u32 ndmaNo, u32 callback, u32 arg)
{
    u32 bit = 1 << (ndmaNo + 28);
    data_02150F68[ndmaNo].callback = callback;
    data_02150F68[ndmaNo].arg = arg;
    data_02150F68[ndmaNo].prevEnabled = OS_EnableIrqMask(bit) & bit;
}

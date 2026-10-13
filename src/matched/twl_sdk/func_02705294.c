/*
 * function: DSP_ClearSemaphoreCore
 * address:  0x02705294
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

typedef unsigned int u32;
typedef unsigned short u16;

void DSP_ClearSemaphoreCore(u16 v)
{
    *(volatile u16 *)0x04004318 = v;
}

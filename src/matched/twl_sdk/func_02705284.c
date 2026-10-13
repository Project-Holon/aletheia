/*
 * function: DSP_GetSemaphoreCore
 * address:  0x02705284
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

u16 DSP_GetSemaphoreCore(void)
{
    return *(volatile u16 *)0x0400431C;
}

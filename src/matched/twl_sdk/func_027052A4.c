/*
 * function: DSP_MaskSemaphoreCore
 * address:  0x027052A4
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

void DSP_MaskSemaphoreCore(u16 v)
{
    *(volatile u16 *)0x04004314 = v;
}

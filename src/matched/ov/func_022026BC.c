/*
 * function: func_022026BC
 * address:  0x022026BC
 * packet:   pkt_022026BC
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *

 *
 * Tail-call thunk to the thumb routine at 0x020185F4.
 */

typedef unsigned int u32;

extern void *func_020185F4(void *a);

u32 func_022026BC(void *mon)
{
    return (u32)func_020185F4(mon);
}

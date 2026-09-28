/*
 * function: func_02157954
 * address:  0x02157954
 * packet:   pkt_ov010_02157954
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf setter (hidden in a .word run); filed as a helper because
 * its address is the witness for the tail-call thunk at 0x02157960.
 */

typedef unsigned char u8;
typedef unsigned int u32;

void func_02157954(u8 *p, u32 v)
{
    *(u32 *)(p + 0x678) = v;
}

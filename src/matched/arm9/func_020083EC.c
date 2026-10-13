/*
 * function: CONFIG_SetAppliedFlag
 * address:  0x020083EC
 * packet:   pkt_020083EC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf: set (or clear) bit 9 of the u16 at *p from the low
 * bit of v, re-read that bit, and tail-call func_020461D4 with it as a byte.
 * Mask pool word 0xFFFFFEFF, tail-target pool word 0x020461D4.
 *
 * symbols:
 *   CONFIG_SetAppliedFlag  0x020083EC  thumb
 *   func_020461D4  0x020461D4  arm
 */

extern void func_020461D4(unsigned char);

void CONFIG_SetAppliedFlag(unsigned short *p, unsigned int v)
{
    unsigned short w = (unsigned short)v;

    *p = (*p & 0xFFFFFEFF) | (((unsigned int)w << 31) >> 23);

    func_020461D4((unsigned char)(((unsigned int)*p << 23) >> 31));
}

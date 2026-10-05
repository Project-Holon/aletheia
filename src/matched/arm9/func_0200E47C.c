/*
 * function: func_0200E47C
 * address:  0x0200E47C
 * packet:   pkt_0200E47C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf in the ARM9 module: word array at +0xDC, index i.
 * Filed by wave D4 lane 12 (blocked ov217 func_021BFC60).
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned int u32;

u32 func_0200E47C(u8 *p, int i)
{
    return *(u32 *)(p + i * 4 + 0xdc);
}

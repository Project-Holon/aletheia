/*
 * function: func_02176870
 * address:  0x02176870
 * packet:   pkt_ov011_02176870
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf: bit 1 of the byte at +0x8F8 of the argument.
 *
 * symbols:
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

u32 func_02176870(u8 *p)
{
    return (u32)(p[0x8F8] << 30) >> 31;
}

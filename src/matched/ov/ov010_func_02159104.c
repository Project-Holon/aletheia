/*
 * function: func_02159104
 * address:  0x02159104
 * packet:   pkt_ov010_02159104
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Store of a word at +0x140.
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

void func_02159104(u8 *p, u32 v)
{
    *(u32 *)(p + 0x140) = v;
}

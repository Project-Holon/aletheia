/*
 * function: func_02050848
 * address:  0x02050848
 * packet:   pkt_02050848
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Leaf witness for ov021 0x0219F058 and siblings (lane wA1-06).
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u16 func_02050848(u8 *p, int i)
{
    return *(u16 *)(*(u8 **)(p + 0x18) + i * 40 + 0xe);
}

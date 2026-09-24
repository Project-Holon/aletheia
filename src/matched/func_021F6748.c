/*
 * function: func_021F6748
 * address:  0x021F6748
 * packet:   pkt_021F6748
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *

 * Store the query byte at +3 of the second argument.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern u32 func_02018438(u32 a, u8 *q);

void func_021F6748(u32 a, u8 *q)
{
    q[3] = func_02018438(a, q);
}

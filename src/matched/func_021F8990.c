/*
 * function: func_021F8990
 * address:  0x021F8990
 * packet:   pkt_021F8990
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
 * Clear the two ten-entry u16 tables at +4 and +0x18 and the two header words.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
void func_021F8990(u8 *p)
{
    int i;
    u16 z = 0;

    for (i = 0; i < 10; i++) {
        *(u16 *)(p + i * 2 + 4) = z;
        *(u16 *)(p + i * 2 + 0x18) = z;
    }
    *(u16 *)(p + 0) = z;
    *(u16 *)(p + 2) = z;
}

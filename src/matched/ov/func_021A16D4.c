/*
 * function: func_021A16D4
 * address:  0x021A16D4
 * packet:   pkt_021A16D4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Field setter at +0x8.
 *
 * symbols:

 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

void func_021A16D4(u8 *p, u32 v)
{
    *(u32*)(p + 8) = v;
}

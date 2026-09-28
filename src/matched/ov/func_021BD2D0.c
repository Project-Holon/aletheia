/*
 * function: func_021BD2D0
 * address:  0x021BD2D0
 * packet:   pkt_021BD2D0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Field setter at +0x48 through a displaced pointer.
 *
 * symbols:

 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

void func_021BD2D0(u8 *p, u16 v)
{
    *(u16*)(p + 72) = v;
}

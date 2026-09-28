/*
 * function: func_021C7E50
 * address:  0x021C7E50
 * packet:   pkt_021C7E50
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Field setter at +0x1e.
 *
 * symbols:

 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

void func_021C7E50(u8 *p, u16 v)
{
    *(u16*)(p + 30) = v;
}

/*
 * function: func_021C7EF4
 * address:  0x021C7EF4
 * packet:   pkt_021C7EF4
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Loads the byte at +0x4 of the object.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u8 func_021C7EF4(u8 *p)
{
    return *(u8 *)(p + 0x4);
}


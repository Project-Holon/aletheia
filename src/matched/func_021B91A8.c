/*
 * function: func_021B91A8
 * address:  0x021B91A8
 * packet:   pkt_021B91A8
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Loads the 16-bit halfword at +0x2 of the object.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u16 func_021B91A8(u8 *p)
{
    return *(u16 *)(p + 0x2);
}


/*
 * function: func_021B8038
 * address:  0x021B8038
 * packet:   pkt_021B8038
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Loads the byte at byte +0x32 of the object.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u8 func_021B8038(u8 *p)
{
    return *(u8 *)(p + 0x32);
}


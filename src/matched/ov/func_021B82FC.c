/*
 * function: func_021B82FC
 * address:  0x021B82FC
 * packet:   pkt_021B8038
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Loads the 32-bit word at byte +0x10 of the object.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u32 func_021B82FC(u8 *p)
{
    return *(u32 *)(p + 0x10);
}


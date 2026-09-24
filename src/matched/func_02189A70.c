/*
 * function: func_02189A70
 * address:  0x02189A70
 * packet:   pkt_02189A00
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Loads the 32-bit word at byte +0x150 of the object.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u32 func_02189A70(u8 *p)
{
    return *(u32 *)(p + 0x150);
}


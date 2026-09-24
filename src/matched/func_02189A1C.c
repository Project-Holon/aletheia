/*
 * function: func_02189A1C
 * address:  0x02189A1C
 * packet:   pkt_02189A00
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Stores the 32-bit word into byte +0x138 of the object.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

void func_02189A1C(u8 *p, u32 v)
{
    *(u32 *)(p + 0x138) = v;
}


/*
 * function: func_02189A00
 * address:  0x02189A00
 * packet:   pkt_02189A00
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Loads the 32-bit word at byte +0x124 of the object.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

void *func_02189A00(u8 *p)
{
    return *(void **)(p + 0x124);
}


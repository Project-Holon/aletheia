/*
 * function: func_02188C7C
 * address:  0x02188C7C
 * packet:   pkt_02188C54
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Loads the 32-bit word at byte +0x38 of the object.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

void *func_02188C7C(u8 *p)
{
    return *(void **)(p + 0x38);
}


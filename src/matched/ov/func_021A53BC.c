/*
 * function: func_021A53BC
 * address:  0x021A53BC
 * packet:   pkt_021A53BC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   func_021A5318  0x021A5318  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern int func_021A5318(u32 *p, u32 m);

int func_021A53BC(u32 a)
{
if (func_021A5318((u32 *)a, 16) != 0) {
    return 1;
}
return 0;
}


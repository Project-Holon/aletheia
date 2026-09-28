/*
 * function: func_021AB140
 * address:  0x021AB140
 * packet:   pkt_ov021_021AB140
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 *
 * symbols:

 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

int func_021AB140(u16 x)
{
    if ((u16)(x + 0xFFF8) <= 1)
        return 1;
    return 0;
}

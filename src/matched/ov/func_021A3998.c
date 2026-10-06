/*
 * function: func_021A3998
 * address:  0x021A3998
 * packet:   pkt_021A3998
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   func_021A3974  0x021A3974  thumb  ov021
 *   func_021A3B3C  0x021A3B3C  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_021A3974(u8 *p);
extern u32 func_021A3B3C(u32, u32);

int func_021A3998(u8 *a)
{
    u32 b;
    u32 c;
    u32 d;
return func_021A3B3C((u32)a, func_021A3974(a));
}


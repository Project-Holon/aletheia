/*
 * function: func_02210234
 * address:  0x02210234
 * packet:   pkt_02210234
 * region:   ov198
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02210C88  0x02210C88  thumb  ov198
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_02210C88(u32, u32);

u32 func_02210234(u32 a)
{
    if (func_02210C88(a, 7) == 0) {
        return 0x11;
    }
    return 0x1a;
}


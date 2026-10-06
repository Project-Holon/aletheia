/*
 * function: func_021F4DA4
 * address:  0x021F4DA4
 * packet:   pkt_021F4DA4
 * region:   ov194
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F4D9C  0x021F4D9C  thumb  ov194
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u16 func_021F4D9C(const u16 *p);

u32 func_021F4DA4(u8 *p, u16 a, u16 b)
{
    return *(u16 *)(p + ((a + b * func_021F4D9C((const u16 *)p)) << 1) + 4);
}


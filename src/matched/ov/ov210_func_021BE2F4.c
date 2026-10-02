/*
 * function: func_021BE2F4
 * address:  0x021BE2F4
 * packet:   pkt_ov210_021BE2F4
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:

 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef signed int     s32;
u32 func_021BE2F4(u8 *p, u32 a, u32 b, u32 c)
{
    p[0x2c0] = a;
    p[0x2c1] = b;
    p[0x2c2] = 0;
    p[0x2c3] = 0;
    *(u32 *)(p + 0x1c) = c;
    return 25;
}

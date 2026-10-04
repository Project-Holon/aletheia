/*
 * function: func_021BC270
 * address:  0x021BC270
 * packet:   pkt_021BC270
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BCF50  0x021BCF50  thumb  ov210
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_021BCF50(u8 *p);

u32 func_021BC270(u32 a, u32 b, u32 c, u32 d)
{
    return func_021BCF50((u8 *)d) == 0;
}


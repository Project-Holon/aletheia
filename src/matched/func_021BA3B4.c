/*
 * function: func_021BA3B4
 * address:  0x021BA3B4
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BA434  0x021BA434  thumb  ov217
 *
 * Returns 1 unless a1 is zero and func_021BA434() reports more than one.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 func_021BA434();
u32 func_021BA3B4(u32 a0, u32 a1)
{
    if (a1 == 0) {
    if (func_021BA434() > 1) {
    return 1;
    }
    return 0;
    }
    return 1;
}

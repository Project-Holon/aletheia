/*
 * function: func_0218FDF0
 * address:  0x0218FDF0
 * packet:   pkt_ov021_0218FDF0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   _s32_div_f  0x0209C0A4  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

u16 func_0218FDF0(u16 *a, u16 *b, s32 d, s32 n)
{
    u16 x, delta, rem;
    if (d == 0)
        return *b;
    x = *a;
    delta = *b - x;
    rem = 0x10000 - delta;
    if (delta <= rem)
        return x + (u16)(delta * n / d);
    return x - (u16)(rem * n / d);
}

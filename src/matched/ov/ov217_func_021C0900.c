/*
 * function: func_021C0900
 * address:  0x021C0900
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Clamp the argument into 0..0xff as a byte.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

u32 func_021C0900(s32 v)
{
    if (v < 0)
        return 0;
    if (v > 0xff)
        return 0xff;
    return (u8)v;
}

/*
 * function: func_021BBF04
 * address:  0x021BBF04
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BBC50  0x021BBC50  thumb  ov217
 *
 * Returns 2, or 1 when func_021BBC50() reports the caller's own a1.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u8 func_021BBC50(u8 *p);
u32 func_021BBF04(u32 a0, u32 a1)
{
    u8 v = 2;
    if (a1 == func_021BBC50((u8 *)a0)) {
    v -= 1;
    }
    return v;
}

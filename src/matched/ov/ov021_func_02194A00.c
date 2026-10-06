/*
 * function: func_02194A00
 * address:  0x02194A00
 * packet:   pkt_ov021_02194A00
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02194A94  0x02194A94  thumb  ov021
 *   func_02195E54  0x02195E54  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern u32 func_02194A94(u32 a, u32 b, u32 c, u32 d, u8 e);
extern void func_02195E54(u32 a, u32 b, u8 c, u32 d);

u32 func_02194A00(u32 a, u8 b, u8 c, u8 d, u8 e, u32 f)
{
    u32 r;

    r = func_02194A94(a, b, c, d, e);
    func_02195E54(a, r, f, 0);
    return r;
}

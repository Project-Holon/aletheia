/*
 * function: func_02190ACC
 * address:  0x02190ACC
 * packet:   pkt_ov021_02190ACC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02190A74  0x02190A74  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

extern u32 func_02190A74(u32 *obj, u32 *tab, u32 *out, u32 key);

u32 func_02190ACC(u32 *obj, u32 *tab, u32 unused, u32 key)
{
    u32 tmp;
    u32 x;
    u32 r;

    x = func_02190A74(obj, tab, &tmp, key);
    x += key + 0x10;
    r = x >> 3;
    if (x & 7)
        r++;
    return r;
}

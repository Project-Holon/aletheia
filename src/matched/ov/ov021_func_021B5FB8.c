/*
 * function: func_021B5FB8
 * address:  0x021B5FB8
 * packet:   pkt_ov021_021B5FB8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0201891C  0x0201891C  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_0201891C(u32 a, u32 b);

int func_021B5FB8(u32 a, int sel)
{
    switch (sel) {
    case 1:
        if (func_0201891C(a, 3))
            return 1;
        if (func_0201891C(a, 4))
            return 1;
        if (func_0201891C(a, 5))
            return 1;
        return 0;
    case 0:
        if (func_0201891C(a, 6))
            return 1;
        return 0;
    case 2:
        if (func_0201891C(a, 0))
            return 1;
        if (func_0201891C(a, 1))
            return 1;
        if (func_0201891C(a, 2))
            return 1;
        return 0;
    }
    return 0;
}

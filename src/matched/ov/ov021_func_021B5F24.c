/*
 * function: func_021B5F24
 * address:  0x021B5F24
 * packet:   pkt_ov021_021B5F24
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201891C  0x0201891C  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_0201891C(u32 a, u32 b);

int func_021B5F24(u32 a, int sel)
{
    switch (sel) {
    case 1:
        if (func_0201891C(a, 3))
            return 0x152;
        if (func_0201891C(a, 4))
            return 0x133;
        if (func_0201891C(a, 5))
            return 0x134;
        break;
    case 0:
        return 0x1b2;
    case 2:
        if (func_0201891C(a, 0))
            return 0x208;
        if (func_0201891C(a, 1))
            return 0x207;
        if (func_0201891C(a, 2))
            return 0x206;
        break;
    }
    return 0x133;
}

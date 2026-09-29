/*
 * function: func_02196BF8
 * address:  0x02196BF8
 * packet:   pkt_ov021_02196BF8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Handler: stores the request at +0x300 and dispatches on it.
 *
 * symbols:
 *   func_02196034  0x02196034  thumb  ov021
 *   func_02196B28  0x02196B28  thumb  ov021
 *   func_02196B94  0x02196B94  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_02196034(u8 *p, void *fn, u32 n);
extern void func_02196B28(void);
extern void func_02196B94(void);
extern void func_020061E4(int n);

int func_02196BF8(u32 v, u8 *p)
{
    int r = 1;

    *(u32 *)(p + 0x300) = v;
    switch (v) {
    case 0:
        func_020061E4(0x73B);
        func_02196034(p, func_02196B28, 0x4A3);
        break;
    case 1:
        func_020061E4(0x73B);
        *(u32 *)(p + 8) = 5;
        func_02196034(p, func_02196B28, 0x4A9);
        break;
    case 2:
        func_020061E4(0x73C);
        *(u32 *)(p + 8) = 0xC;
        func_02196034(p, func_02196B94, 0x4AF);
        break;
    default:
        r = 1;
        break;
    }
    return r;
}

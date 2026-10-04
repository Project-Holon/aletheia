/*
 * function: func_021A48A4
 * address:  0x021A48A4
 * packet:   pkt_021A48A4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   func_021A56C0  0x021A56C0  thumb  ov021
 *   func_021A54B4  0x021A54B4  thumb  ov021
 *   func_021A53A4  0x021A53A4  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void func_021A53A4(u32 *p, int on);
extern void func_021A54B4(u8 *p);
extern u32 func_021A56C0(u32, u32, u32, u32);

int func_021A48A4(u32 a, u32 b, u32 c, u32 d)
{
if (func_021A56C0(a, b, c, d) == 1) {
    func_021A54B4((u8 *)a);
    func_021A53A4((u32 *)a, 0);
    return 1;
}
return 9;
}


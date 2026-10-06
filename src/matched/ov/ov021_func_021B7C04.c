/*
 * function: func_021B7C04
 * address:  0x021B7C04
 * packet:   pkt_ov021_021B7C04
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B94C0  0x021B94C0  thumb ov021
 *   func_021B9478  0x021B9478  thumb ov021
 *   func_021B949C  0x021B949C  thumb ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_021B94C0(u16 *p, u16 v);
extern void func_021B9478(u16 *p, u16 v);
extern void func_021B949C(u16 *p, u16 v);

void func_021B7C04(u8 *o, int k, int flag)
{
    if (flag == 0) {
        if (func_021B94C0((u16 *)(o + 0x50), k) == 0) {
            func_021B9478((u16 *)(o + 0x50), k);
        }
    } else {
        func_021B949C((u16 *)(o + 0x50), k);
    }
}

/*
 * function: func_021B2E80
 * address:  0x021B2E80
 * packet:   pkt_ov021_021B2E80
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0218BA98  0x0218BA98  thumb  ov021
 *   func_0218C8D8  0x0218C8D8  thumb  ov021
 *   func_0218C9A4  0x0218C9A4  thumb  ov021
 *   func_021B2BD8  0x021B2BD8  thumb  ov021
 *   d_021EE720     0x021EE720  data  a2
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern u16 d_021EE720;
extern int func_021B2BD8(u32 a);
extern u32 func_0218BA98(u32, u32);
extern u32 func_0218C8D8(u32);
extern u32 func_0218C9A4(u32);

int func_021B2E80(u32 a, u32 b)
{
    u32 o = func_0218BA98(func_021B2BD8(b), d_021EE720);

    if (o == 0) {
        return 1;
    }
    if (func_0218C8D8(o) == 0) {
        return 0;
    }
    if (func_0218C9A4(o) == 0) {
        return 1;
    }
    return 0;
}

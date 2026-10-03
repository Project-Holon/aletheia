/*
 * function: func_021B16F0
 * address:  0x021B16F0
 * packet:   pkt_ov021_021B16F0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020113D0  0x020113D0  thumb
 *   func_021B16DC  0x021B16DC  thumb  ov021
 */

typedef unsigned int u32;

extern void func_020113D0(u32, u32);
extern int func_021B16DC(u32 a, u32 b, u32 c, u32 d);

int func_021B16F0(u32 a)
{
    func_020113D0(a, (u32)func_021B16DC);
    return 1;
}

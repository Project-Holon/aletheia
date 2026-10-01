/*
 * function: func_021B2A90
 * address:  0x021B2A90
 * packet:   pkt_ov021_021B2A90
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020113D0  0x020113D0  thumb
 *   func_021B2860  0x021B2860  thumb  ov021
 */

typedef unsigned int u32;

extern void func_020113D0(u32, u32);
extern void func_021B2860();

int func_021B2A90(u32 a)
{
    func_020113D0(a, (u32)func_021B2860);
    return 1;
}

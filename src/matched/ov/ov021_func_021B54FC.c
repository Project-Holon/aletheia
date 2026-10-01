/*
 * function: func_021B54FC
 * address:  0x021B54FC
 * packet:   pkt_ov021_021B54FC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_021B55F0  0x021B55F0  thumb  ov021
 */

typedef unsigned int u32;

extern u32 func_0215A5F4(u32);
extern u32 func_0215A5DC(u32);
extern u32 func_020122C0(u32, u32, u32, u32);
extern void func_0215897C(u32, u32);
extern int func_021B55F0(u32);

int func_021B54FC(u32 a, u32 b)
{
    u32 s = func_0215A5F4(b);
    u32 d = func_0215A5DC(b);

    func_0215897C(s, func_020122C0(d, 0, (u32)func_021B55F0, 0));
    return 1;
}

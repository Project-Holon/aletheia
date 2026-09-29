/*
 * function: ov021_func_021A1244
 * address:  0x021A1244
 * packet:   pkt_ov021_021A1244
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F8  0x020120F8  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_0201296C  0x0201296C  thumb
 *   func_021A8B18  0x021A8B18  thumb  ov021
 *   func_02024DCC  0x02024DCC  thumb
 *   func_021A84BC  0x021A84BC  thumb  ov021
 *   func_020403F4  0x020403F4  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
extern u32 func_02188C80(u32);
extern u32 func_020120F8(u32);
extern u32 func_02012AC8(u32);
extern u32 func_020120F4(u32);
extern u32 func_0201296C(u32);
extern u32 func_021A8B18(u32, u32, u32);
extern void func_02024DCC(void);
extern void func_021A84BC(u32);
extern void func_020403F4(u32);

void ov021_func_021A1244(u32 *p)
{
    u32 a, b, c;
    a = func_02188C80(p[5]);
    b = func_02012AC8(func_020120F8(a));
    c = func_020120F4(a);
    if (func_021A8B18(c, func_0201296C(c), b) != 1)
        func_02024DCC();
    func_021A84BC(p[8]);
    func_020403F4(4);
}

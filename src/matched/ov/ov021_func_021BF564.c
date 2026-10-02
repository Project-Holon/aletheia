/*
 * function: func_021BF564
 * address:  0x021BF564
 * packet:   pkt_ov021_021BF564
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02043658  0x02043658  arm
 *   func_02043668  0x02043668  arm
 *   func_02188DA0  0x02188DA0  thumb  ov021
 *   func_02043534  0x02043534  arm
 *   func_020435F4  0x020435F4  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern u32 func_02043658(void);
extern u32 func_02043668(void);
extern void func_02188DA0(void);
extern void func_02043534(u32 v);
extern void func_020435F4(u32 v);

void func_021BF564(void)
{
    u32 a = func_02043658();
    u32 b = func_02043668();

    func_02188DA0();
    func_02043534(a);
    func_020435F4(b);
}

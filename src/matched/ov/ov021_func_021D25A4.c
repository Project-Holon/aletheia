/*
 * function: func_021D25A4
 * address:  0x021D25A4
 * packet:   pkt_ov021_021D25A4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020450F0  0x020450F0  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_0201F73C  0x0201F73C  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

typedef unsigned char  u8;
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern u32 func_02045770(void);
extern void func_02043B5C(u32 a, u32 b);
extern void func_02045334(u32 w);
extern void func_02045374(u32 w);
extern void func_0201F73C(u32 a, u32 b, u32 c, u32 d);

void func_021D25A4(u32 *p)
{
    p[0] = func_020450F0(1, 10, 3, 12, 12, 13, 1);
    func_02043B5C(func_02045770(), 17);
    func_02045334(p[0]);
    func_02045374(p[0]);
    func_0201F73C(p[0], 1, 1, 13);
}

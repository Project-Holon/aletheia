/*
 * function: func_021D20BC
 * address:  0x021D20BC
 * packet:   pkt_ov021_021D20BC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0201F548  0x0201F548  thumb
 *   func_02049B90  0x02049B90  arm
 *   func_020450F0  0x020450F0  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_0201F73C  0x0201F73C  thumb
 *   func_021D1F78  0x021D1F78  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

typedef unsigned short u16;
typedef unsigned char  u8;
extern u8 func_0201F548(int i);
extern void func_02049B90(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(u32 a, u32 b);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(u32 a);
extern void func_0201F73C(u32 a, u32 b, u32 c, u32 d);
extern void func_021D1F78(u32 *w);

void func_021D20BC(u32 *w)
{
    func_02049B90(5, func_0201F548(0), 0, 0, 0, 0x20, 0x15);
    w[0x30 / 4] = func_020450F0(1, 10, 3, 12, 12, 0, 1);
    func_02043B5C((u32)func_02045770((struct Descriptor *)w[0x30 / 4]), 0x11);
    func_02045334((struct Descriptor *)w[0x30 / 4]);
    func_02045374(w[0x30 / 4]);
    func_0201F73C(w[0x30 / 4], 1, 1, 0);
    func_021D1F78(w);
}

/*
 * function: func_021F0168
 * address:  0x021F0168
 * packet:   pkt_ov035_021F0168
 * region:   ov035
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021F0168 0x021F0168 thumb
 *   func_02049B40 0x02049B40 arm
 *   func_0201F5DC 0x0201F5DC thumb
 *   func_020450F0 0x020450F0 arm
 *   func_02045790 0x02045790 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_0203101C 0x0203101C arm
 *   func_02028590 0x02028590 thumb
 */

extern void func_02049B40(int, int, int, int, int, int);
extern int func_0201F5DC(int, int, int, int);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void func_02045790(int, int);
struct Descriptor;
extern void *func_02045770(struct Descriptor *);
extern void func_02043B5C(int, int);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(int);
extern int func_0203101C(int, int, int, int);
extern int func_02028590(int, int, int, int);

void func_021F0168(int *p, int a1)
{
    func_02049B40(0x17, 5, 4, 0x20, 0x20, a1);
    p[5] = func_0201F5DC(5, 2, 0, a1);
    p[6] = func_020450F0(5, 1, 1, 0x1E, 6, 1, 1);
    p[7] = func_020450F0(5, 1, 0xD, 0x1E, 0xA, 1, 1);
    func_02045790(p[6], 4);
    func_02043B5C((int)func_02045770((struct Descriptor *)p[6]), 0xF);
    func_02045334((struct Descriptor *)p[6]);
    func_02045374(p[6]);
    func_02043B5C((int)func_02045770((struct Descriptor *)p[7]), 0xF);
    func_02045334((struct Descriptor *)p[7]);
    func_02045374(p[7]);
    p[8] = func_0203101C(a1, a1, 1, 4);
    p[0xC] = func_02028590(0xF, 0, 1, a1);
}

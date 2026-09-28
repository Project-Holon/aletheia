/*
 * function: func_021BEB0C
 * address:  0x021BEB0C
 * packet:   pkt_021BEB0C
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045770  0x02045770  arm
 *   func_021BE44C  0x021BE44C  thumb ov210
 *   func_021BE49C  0x021BE49C  thumb ov210
 *   func_021BEB8C  0x021BEB8C  thumb ov210
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void func_02043B5C(u32, u32);
extern u32  func_02045770(u32);
extern void func_021BE44C(void *, int, int, int, int, int, int);
extern void func_021BE49C(void *);
extern void func_021BEB8C(void *);

void func_021BEB0C(u8 *p)
{
    func_021BE49C(p + 0x14C);
    func_02043B5C(func_02045770(*(u32 *)(p + 0x154)), 0);
    func_021BE44C(p, 1, 8, 0, 4, 0x440, 0);
    func_021BE49C(p + 0x154);
    func_02043B5C(func_02045770(*(u32 *)(p + 0x1AC)), 0);
    func_021BE44C(p, 0xC, 0xF, 0x28, 0, 0x3C40, 2);
    func_021BE49C(p + 0x1AC);
    func_021BEB8C(p);
}

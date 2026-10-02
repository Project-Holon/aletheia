/*
 * function: func_021BEBE8
 * address:  0x021BEBE8
 * packet:   pkt_ov210_021BEBE8
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_021BE44C 0x021BE44C thumb ov210
 *   func_021BE49C 0x021BE49C thumb ov210
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
struct Descriptor;
struct CharBuf;
extern void *func_02045770(struct Descriptor *);
extern void func_02043B5C(struct CharBuf *, u8);
extern void func_021BE44C(u8 *, int, unsigned, int, int, unsigned short, unsigned);
extern void func_021BE49C(u8 *);

void func_021BEBE8(u8 *p)
{
    func_021BE49C(p + 0x14c);
    func_02043B5C(func_02045770(*(struct Descriptor **)(p + 0x154)), 0);
    func_021BE44C(p, 1, 7, 0, 4, 0x440, 0);
    func_021BE49C(p + 0x154);
    func_02043B5C(func_02045770(*(struct Descriptor **)(p + 0x1ac)), 0);
    func_021BE44C(p, 12, 16, 40, 0, 0x3c40, 2);
    func_021BE49C(p + 0x1ac);
}

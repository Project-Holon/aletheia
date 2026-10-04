/*
 * function: func_021C53E0
 * address:  0x021C53E0
 * packet:   pkt_021C53E0
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *
 * Forwards its second argument to func_0204B3B4 and then the first to
 * func_0204A8D4.
 */

struct Obj;
extern void func_0204B3B4(struct Obj *p);
typedef unsigned int   u32;
extern void func_0204A8D4(u32 i);

void func_021C53E0(int a, int b)
{
    func_0204B3B4((struct Obj *)b);
    func_0204A8D4(a);
}

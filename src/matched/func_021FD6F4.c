/*
 * function: func_021FD6F4
 * address:  0x021FD6F4
 * packet:   pkt_021FD6F4
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02202858  0x02202858  thumb  ov135

 * Tear the object down: unhook the two sub-objects, release the +0xd40 resource, wire the 0/1/2 quad, then drain the four engine hooks.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern void func_02045CAC(u32 a, u32 b, u32 c);
extern u32 func_02045770(u32 v);
extern void func_02043B5C(u32 v, u32 k);
extern void func_0201F73C(u32 a, u32 b, u32 c, u32 d);
extern void func_02202858(u32 a, u32 b, u32 c, u32 d, u32 e, u8 *f);
extern void func_02045334(u32 v);
extern void func_02045374(u32 v);
extern u32 func_02045730(u32 v);
extern void func_020409B4(u32 v);

void func_021FD6F4(u8 *p, u32 k)
{
    u32 v;

    func_02045CAC(*(u32 *)(p + 0xb6c), k, *(u32 *)(p + 0xb6c + 0x1c));
    func_02043B5C(func_02045770(*(u32 *)(p + 0xd40)), 0xf);
    func_0201F73C(*(u32 *)(p + 0xd40), 0, 1, 0x2);
    func_02202858(*(u32 *)(p + 0xd40), 0, *(u32 *)(p + 0xb6c + 0x1c), 0, 0, p + 0xfa0);
    v = *(u32 *)(p + 0xd40);
    func_02045334(v);
    func_02045374(v);
    func_020409B4(func_02045730(v));
}

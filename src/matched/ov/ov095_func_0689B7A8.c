/*
 * function: func_0689B7A8
 * address:  0x0689B7A8
 * packet:   pkt_ov095_0689B7A8
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Handed at 0x0689B7AA (the second label after `push {r0-r3}` at 0x0689B7A8).
 * The fifth argument is read through &c ((&c)[2], the first stack slot):
 * taking the address of c is what pushes r0-r3 and makes c reload from its
 * home slot; a plain fifth parameter gives an ordinary push instead.
 *
 * symbols:
 *   func_0689B7EC  0x0689B7EC  thumb  ov095
 *   func_0689BF3C  0x0689BF3C  thumb  ov095
 *   func_0689B7FC  0x0689B7FC  thumb  ov095
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_0689B7EC(u32 a);
extern void func_0689BF3C(u32 e, u32 a, u32 x, u32 b, u32 c);
extern void func_0689B7FC(u32 e, u32 a, u32 x, u32 b);

void func_0689B7A8(u32 a, u32 b, u32 c, int d)
{
    u32 x;

    x = func_0689B7EC(a);
    if (d != 0)
        func_0689BF3C((&c)[2], a, x, b, c);
    else
        func_0689B7FC((&c)[2], a, x, b);
}

/*
 * unit:     yes
 * function: func_020222A8
 * address:  0x020222A8
 * packet:   pkt_020222A8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0207E3D0  0x0207E3D0  arm
 *   func_0207E468  0x0207E468  arm
 */

typedef unsigned int u32;

extern void func_0207E3D0(u32 *p, u32 b, u32 c);
extern void func_0207E468(u32 *p, u32 b, u32 c);

void func_020222A8(u32 a)
{
    u32 *p = &a;

    func_0207E3D0(p, 0, 2);
    func_0207E468(p, 0, 2);
}

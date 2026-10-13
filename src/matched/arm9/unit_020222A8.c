/*
 * unit:     yes
 * function: WIPE_SetBackColor
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
 *   GX_LoadBGPltt  0x0207E3D0  arm
 *   func_0207E468  0x0207E468  arm
 */

typedef unsigned int u32;

extern void GX_LoadBGPltt(u32 *p, u32 b, u32 c);
extern void func_0207E468(u32 *p, u32 b, u32 c);

void WIPE_SetBackColor(u32 a)
{
    u32 *p = &a;

    GX_LoadBGPltt(p, 0, 2);
    func_0207E468(p, 0, 2);
}

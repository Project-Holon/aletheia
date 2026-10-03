/*
 * function: func_021C06CC
 * address:  0x021C06CC
 * packet:   pkt_ov021_021C06CC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Spawns the func_021C06E0 task with no work area.
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_021C06E0  0x021C06E0  thumb  ov021
 */

typedef unsigned int   u32;
struct Desc;
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
int func_021C06E0(u32 a, int *st);

void func_021C06CC(void *p)
{
    func_020122C0(p, 0, func_021C06E0, 0);
}

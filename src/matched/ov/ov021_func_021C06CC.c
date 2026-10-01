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

void *func_020122C0(void *p, int a, void (*cb)(void), int n);
void func_021C06E0(void);

void func_021C06CC(void *p)
{
    func_020122C0(p, 0, func_021C06E0, 0);
}

/*
 * function: func_021EF630
 * address:  0x021EF630
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *
 * Spin up the 0x0204162C resource, arm channel 6 with tag 0x20,
 *   then hand row 6 of the 0x540 span.
 */
#include "../include/Obj01558.h"


typedef unsigned int u32;
struct WinMgr;
extern u32 func_0204162C(int channel);
extern void func_0202CA3C(struct WinMgr *mgr, u32 idx, u32 bg, u32 w, u32 h);
extern void func_0202CAC4(struct WinMgr *mgr, u32 idx, const void *src);
void func_021EF630(char *p)
{
    int x = func_0204162C(0);
    func_0202CA3C(*(struct WinMgr **)(*(int *)&((struct Obj01558 *)p)->f2C + 0x74), 6, 0, 0x20, 3);
    func_0202CAC4(*(struct WinMgr **)(*(int *)&((struct Obj01558 *)p)->f2C + 0x74), 6, (const void *)(x + 0x540));
}

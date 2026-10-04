/*
 * function: func_021EB7C8
 * address:  0x021EB7C8
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021EB6F0  0x021EB6F0  thumb  ov170
 *   func_021EB708  0x021EB708  thumb  ov170
 *
 * Stage 0x17/0x46 then hand the 0x14C word over with index 0xb.
 */
#include "../include/Obj01558.h"


struct WinMgr;
extern void func_021EB6F0(int a, int b, int c);
extern void func_021EB708(void *m, unsigned i, void *d);
void func_021EB7C8(char *p)
{
    func_021EB6F0((int)p, 0x17, 0x46);
    func_021EB708(*(struct WinMgr **)(*(int *)&((struct Obj01558 *)p)->f2C + 0x74), 0xb,
                  (void *)(*(int *)(*(int *)&((struct Obj01558 *)p)->f2C + 0x14C)));
}

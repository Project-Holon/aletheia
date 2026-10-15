/*
 * function: BATTLE_CHAMPIONSHIP_FLOW_SetOption
 * address:  0x0217B93C
 * packet:   pkt_0217B93C
 * region:   ov176
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021E8738  0x021E8738  thumb  ov177
 */
#include "../include/Obj01762.h"

extern void func_021E8738(int *p, int a, int b, int c);

void BATTLE_CHAMPIONSHIP_FLOW_SetOption(int *p, int b)
{
    func_021E8738((int *)(*(int *)&((struct Obj01762 *)p)->f18), *(int *)&((struct Obj01762 *)p)->f20, b, 1);
}

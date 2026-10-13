/*
 * function: COLOSSEUM_RecvParty
 * address: 0x02174D64
 * packet: pkt_ov012_02174D64
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: (w+a)[0x158] preserves the base-plus-index store address;
 *        w[a+0x158] produced an 8-byte concrete scheduling/addressing DIFF.
 * symbols:
 *   func_02082D44 0x02082D44 arm
 */
#include "../include/Obj19288.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_02082D44(void *,void *,u32);
void COLOSSEUM_RecvParty(u32 a, u32 b, void *c, u8 *d)
{
    u8 *w = *(u8 * *)&((struct Obj19288 *)d)->f355C;
    if (w == 0) return;
    if (*(void **)(w + a * 4 + 0x148) == 0) return;
    func_02082D44(c, *(void **)(w + a * 4 + 0x148), b);
    (w + a)[0x158] = 1;
}

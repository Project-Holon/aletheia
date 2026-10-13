/*
 * function: func_021CF58C
 * address: 0x021CF58C
 * packet: pkt_ov093_021CF58C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BTL_CALC_PeekMoveTarget 0x021D81F8 thumb ov093
 *   BTL_ACTION_SetFight 0x021D82D0 thumb ov093
 */
#include "../include/Obj01894.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct Unk021D82D0 { u32 kind : 4; u32 sub : 3; u32 id : 16; u32 rest : 9; };
extern u32 BTL_CALC_PeekMoveTarget(void *, void *, void *, u32, void *);
extern void BTL_ACTION_SetFight(struct Unk021D82D0 *, u32, u32);
void func_021CF58C(struct Unk021D82D0 *out, u8 *p, void *q)
{
    u32 v;
    v = BTL_CALC_PeekMoveTarget(((struct Obj01894 *)p)->f0, ((struct Obj01894 *)p)->f4, q, 165, p+0x38);
    BTL_ACTION_SetFight(out, 165, v);
}

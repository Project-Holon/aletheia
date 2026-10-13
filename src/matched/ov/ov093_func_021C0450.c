/*
 * function: BTL_SERVER_FLOW_ProcMoveExecuteFail
 * address: 0x021C0450
 * packet: pkt_ov093_021C0450
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Raw u32 lock return avoids an aggregate frame word; Slot remains a one-word aggregate.
 * symbols:
 *   BTL_SERVER_FLOW_ProcConfusionDamage 0x021C63D0 thumb ov093
 *   BTL_SERVER_FLOW_ProcFaintedPoke 0x021C4F64 thumb ov093
 *   BTL_SERVER_FLOW_CheckShowdown 0x021BC2B0 thumb ov093
 *   BTL_SERVER_FLOW_PushMoveFailMessage 0x021C0520 thumb ov093
 *   BTL_CALC_MakeDefaultSickCont 0x021D7D18 thumb ov093
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTL_SERVER_CMD_Push 0x021CD4B0 thumb ov093
 *   BTL_SERVER_FLOW_SetSickCont 0x021C5C1C thumb ov093
 *   BTL_SERVER_FLOW_PushPokeEffectAnim 0x021C5480 thumb ov093
 *   func_021CC8D8 0x021CC8D8 thumb ov093
 *   BTL_SERVER_FLOW_DispatchMoveDoneEvent 0x021C6564 thumb ov093
 *   func_021CC95C 0x021CC95C thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
union Slot { u32 raw; struct { u32 kind:3; u32 lo:6; u32 hi:6; u32 rest:17; } s; };
struct Lock { u32 a:10; u32 b:9; u32 c:9; u32 d:1; u32 e:1; u32 f:1; u32 g:1; };
extern u32 BTL_SERVER_FLOW_ProcConfusionDamage(u8 *, u8 *);
extern int BTL_SERVER_FLOW_ProcFaintedPoke(u8 *, u8 *);
extern int BTL_SERVER_FLOW_CheckShowdown(u8 *);
extern void BTL_SERVER_FLOW_PushMoveFailMessage(u8 *, u8 *, u16, u32);
extern union Slot BTL_CALC_MakeDefaultSickCont(int);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_SERVER_CMD_Push(void *w, volatile u32 id, ...);
extern void BTL_SERVER_FLOW_SetSickCont(u8 *, u8 *, int, union Slot);
extern void BTL_SERVER_FLOW_PushPokeEffectAnim(u8 *, u8 *, int);
extern u32 func_021CC8D8(void *, int);
extern void BTL_SERVER_FLOW_DispatchMoveDoneEvent(u8 *, u8 *, u32, u32);
extern void func_021CC95C(u32 *p, u32 v, int line);
void BTL_SERVER_FLOW_ProcMoveExecuteFail(u8 *p, u8 *q, u16 c, int k)
{
    u32 old;
    if (k == 5) {
        BTL_SERVER_FLOW_ProcConfusionDamage(p, q);
        if (BTL_SERVER_FLOW_ProcFaintedPoke(p, q) && BTL_SERVER_FLOW_CheckShowdown(p)) return;
    } else {
        BTL_SERVER_FLOW_PushMoveFailMessage(p, q, c, k);
        switch (k) {
        case 2: BTL_SERVER_FLOW_PushPokeEffectAnim(p, q, 598); break;
        case 3: BTL_SERVER_FLOW_PushPokeEffectAnim(p, q, 602); break;
        case 4: BTL_SERVER_FLOW_PushPokeEffectAnim(p, q, 601); break;
        case 23: {
            union Slot s = BTL_CALC_MakeDefaultSickCont(2);
            BTL_SERVER_CMD_Push(((struct Obj00003 *)p)->fC, 49, BTL_POKEPARAM_GetPokeId(q), 0);
            BTL_SERVER_FLOW_SetSickCont(p, q, 2, s);
            BTL_SERVER_FLOW_PushPokeEffectAnim(p, q, 598);
            break;
        }
        }
    }
    old = func_021CC8D8(p + 0x1d74, 5728);
    BTL_SERVER_FLOW_DispatchMoveDoneEvent(p, q, c, k);
    func_021CC95C((u32 *)(p + 0x1d74), old, 5730);
}

/*
 * function: BTL_SERVER_FLOW_ProcSickAdded
 * address: 0x021C2910
 * packet: pkt_ov093_021C2910
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_SERVER_FLOW_SetSickCont 0x021C5C1C thumb ov093
 *   BTL_SERVER_FLOW_PushPokeEffectAnim 0x021C5480 thumb ov093
 *   func_021C2AA0 0x021C2AA0 thumb ov093
 *   BTL_SERVER_FLOW_PushMsgRecord 0x021C99A0 thumb ov093
 *   BTL_SERVER_FLOW_ClearMsgRecord 0x021C8810 thumb ov093
 *   BTL_POKEPARAM_GetSpecies 0x021D5444 thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   HAND_TOKUSEI_RemoveAbilityHandlers 0x021D8510 thumb ov093
 *   BTL_POKEPARAM_ChangeForm 0x021D66D8 thumb ov093
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTL_SERVER_CMD_Push 0x021CD4B0 thumb ov093
 *   HAND_TOKUSEI_AddAbilityHandlers 0x021D8484 thumb ov093
 *   BTL_SERVER_FLOW_PushMsgSetPoke 0x021C5D88 thumb ov093
 *   BTL_SERVER_FLOW_BeginHandExScope 0x021CC8D8 thumb ov093
 *   BTL_CALC_HasDefaultSickCont 0x021D7D6C thumb ov093
 *   BTL_SERVER_FLOW_RunSickAddedContEvent 0x021C2BF0 thumb ov093
 *   BTL_SERVER_FLOW_RunSickEndEvent 0x021C2CA8 thumb ov093
 *   BTL_SERVER_FLOW_RecheckOpponentAbilityEffects 0x021C3FDC thumb ov093
 *   BTL_SERVER_FLOW_RunSickAddedEvent 0x021C2C50 thumb ov093
 *   BTL_SERVER_FLOW_EndHandExScope 0x021CC95C thumb ov093
 *   BTL_SERVER_FLOW_ProcDamagedItemReaction 0x021C195C thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { int x; } S;
struct Msg { u16 a; u16 kind:8; u16 n:7; u16 flag:1; u8 data[0x1c]; u32 w20; };
extern void BTL_SERVER_FLOW_SetSickCont(u8 *, u8 *, int, S);
extern void BTL_SERVER_FLOW_PushPokeEffectAnim(u8 *, u8 *, int);
extern void func_021C2AA0(int, S, u8 *, struct Msg *);
extern int BTL_SERVER_FLOW_PushMsgRecord(void *, const struct Msg *);
struct QF;
extern void BTL_SERVER_FLOW_ClearMsgRecord(u8 *p);
extern u16 BTL_POKEPARAM_GetSpecies(struct QF *p);
extern int func_021D59B4(u8 *p, int k);
extern void HAND_TOKUSEI_RemoveAbilityHandlers(void *p);
extern void BTL_POKEPARAM_ChangeForm(void *, u8);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_SERVER_CMD_Push(void *w, volatile u32 id, ...);
extern void *HAND_TOKUSEI_AddAbilityHandlers(void *a);
extern void BTL_SERVER_FLOW_PushMsgSetPoke(u8 *, u8 *, int);
extern u32 BTL_SERVER_FLOW_BeginHandExScope(void *, int);
extern int BTL_CALC_HasDefaultSickCont(int);
extern void BTL_SERVER_FLOW_RunSickAddedContEvent(u8 *, u8 *, u8 *, u32, u32);
extern void BTL_SERVER_FLOW_RunSickEndEvent(u8 *p, u8 *a);
extern void BTL_SERVER_FLOW_RecheckOpponentAbilityEffects(u8 *, u8 *);
extern void BTL_SERVER_FLOW_RunSickAddedEvent(u8 *, u8 *, u8 *, u32);
extern void BTL_SERVER_FLOW_EndHandExScope(u32 *p, u32 v, int line);
extern void BTL_SERVER_FLOW_ProcDamagedItemReaction(u8 *p, u8 *q, u32 n);
void BTL_SERVER_FLOW_ProcSickAdded(u8 *p, u8 *a, u8 *b, int kind, S value, int f, int g, const struct Msg *m)
{
    u32 lock;
    BTL_SERVER_FLOW_SetSickCont(p, a, kind, value);
    switch (kind) {
    case 5: BTL_SERVER_FLOW_PushPokeEffectAnim(p, a, 599); break;
    case 4: BTL_SERVER_FLOW_PushPokeEffectAnim(p, a, 600); break;
    case 1: BTL_SERVER_FLOW_PushPokeEffectAnim(p, a, 602); break;
    case 3: BTL_SERVER_FLOW_PushPokeEffectAnim(p, a, 601); break;
    case 2: BTL_SERVER_FLOW_PushPokeEffectAnim(p, a, 598); break;
    case 6: BTL_SERVER_FLOW_PushPokeEffectAnim(p, a, 603); break;
    case 7: BTL_SERVER_FLOW_PushPokeEffectAnim(p, a, 604); break;
    case 0: break;
    }
    if (f) {
        func_021C2AA0(kind, value, a, (struct Msg *)(p + 0x1ae4));
        BTL_SERVER_FLOW_PushMsgRecord(p, (struct Msg *)(p + 0x1ae4));
        BTL_SERVER_FLOW_ClearMsgRecord((u8 *)(p + 0x1ae4));
    } else if (m) BTL_SERVER_FLOW_PushMsgRecord(p, m);
    if (kind == 3 && BTL_POKEPARAM_GetSpecies((struct QF *)a) == 492 && func_021D59B4(a, 19) == 1) {
        HAND_TOKUSEI_RemoveAbilityHandlers(a);
        BTL_POKEPARAM_ChangeForm(a, 0);
        BTL_SERVER_CMD_Push(((struct Obj00003 *)p)->fC, 79, BTL_POKEPARAM_GetPokeId(a), 0);
        HAND_TOKUSEI_AddAbilityHandlers(a);
        BTL_SERVER_FLOW_PushMsgSetPoke(p, a, 222);
    }
    lock = BTL_SERVER_FLOW_BeginHandExScope(p + 0x1d74, 7936);
    if (BTL_CALC_HasDefaultSickCont(kind)) {
        BTL_SERVER_FLOW_RunSickAddedContEvent(p, a, b, kind, value.x);
    } else if (kind == 16) {
        BTL_SERVER_FLOW_RunSickEndEvent(p, (u8 *)((int)a));
        if (func_021D59B4(a, 17) == 127) BTL_SERVER_FLOW_RecheckOpponentAbilityEffects(p, a);
    } else BTL_SERVER_FLOW_RunSickAddedEvent(p, a, b, kind);
    BTL_SERVER_FLOW_EndHandExScope((u32 *)(p + 0x1d74), lock, 7951);
    if (!g) BTL_SERVER_FLOW_ProcDamagedItemReaction(p, a, 3);
}

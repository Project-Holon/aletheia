/*
 * function: BTL_SERVER_FLOW_ProcSkillSwap
 * address: 0x021C3E0C
 * packet: pkt_ov093_021C3E0C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *  func_021C3FAC 0x021C3FAC thumb ov093
 *  func_021D59B4 0x021D59B4 thumb ov093
 *  func_021C3FBC 0x021C3FBC thumb ov093
 *  func_021C3FCC 0x021C3FCC thumb ov093
 *  BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *  BTL_SERVER_CMD_Push 0x021CD4B0 thumb ov093
 *  BTL_SERVER_CMD_PushVariable 0x021CD64C thumb ov093
 *  BTL_SERVER_FLOW_BeginHandExScope 0x021CC8D8 thumb ov093
 *  BTL_SERVER_FLOW_EndHandExScope 0x021CC95C thumb ov093
 *  BTL_SERVER_FLOW_NotifyAbilityChangeEvent 0x021C7B3C thumb ov093
 *  BTL_SERVER_FLOW_NotifyAbilityChangedEvent 0x021C7B7C thumb ov093
 *  BTL_POKEPARAM_SetAbility 0x021D66D0 thumb ov093
 *  HAND_TOKUSEI_SwapAbilityHandlers 0x021D8564 thumb ov093
 *  BTL_POKEPARAM_HasSick 0x021D62C4 thumb ov093
 *  BTL_SERVER_FLOW_ProcDamagedItemReaction 0x021C195C thumb ov093
 *  BTL_SERVER_FLOW_RecheckOpponentAbilityEffects 0x021C3FDC thumb ov093
 */
#include "../include/Obj03191.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u8 pad[5]; u8 a:1,b:1,c:6; } Flag;
extern u8 *func_021C3FAC(u8 *, int);
extern int func_021D59B4(u8 *p, int k);
extern int func_021C3FBC(u16);
extern int func_021C3FCC(u16);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_SERVER_CMD_Push(void *w, volatile u32 id, ...);
extern void BTL_SERVER_CMD_PushVariable(void *w, u8 id, ...);
extern u32 BTL_SERVER_FLOW_BeginHandExScope(void *, int);
extern void BTL_SERVER_FLOW_EndHandExScope(u32 *p, u32 v, int line);
extern void BTL_SERVER_FLOW_NotifyAbilityChangeEvent(u8 *p, u32 a, u16 b, u16 c);
extern void BTL_SERVER_FLOW_NotifyAbilityChangedEvent(u8 *p, unsigned int i);
struct QJ;
extern void BTL_POKEPARAM_SetAbility(struct QJ *p, u32 v);
extern void HAND_TOKUSEI_SwapAbilityHandlers(int a, int b);
struct Unk021D62A8;
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
extern void BTL_SERVER_FLOW_ProcDamagedItemReaction(u8 *p, u8 *q, u32 n);
extern void BTL_SERVER_FLOW_RecheckOpponentAbilityEffects(u8 *, u8 *);
void BTL_SERVER_FLOW_ProcSkillSwap(u8 *p, u8 *a, u8 *c)
{
    u8 *b;
    u32 x, y, ai, bi;
    u32 s, t;
    int line;
    Flag *f;
    b = func_021C3FAC(c, 0);
    x = func_021D59B4(a, 16);
    y = func_021D59B4(b, 16);
    if (x != y && !func_021C3FBC(x) && !func_021C3FCC(y)) {
        ai = BTL_POKEPARAM_GetPokeId(a);
        bi = BTL_POKEPARAM_GetPokeId(b);
        f = *(Flag * *)&((struct Obj03191 *)p)->f4A8;
        if (f->a == 0) f->a = 1;
        BTL_SERVER_CMD_Push(((struct Obj03191 *)p)->fC, 0x4a, ai, bi, (u16)y, (u16)x);
        BTL_SERVER_CMD_PushVariable(((struct Obj03191 *)p)->fC, 0x5b, 0x1fc, ai, 0xffff0000);
        line = 9140;
        s = BTL_SERVER_FLOW_BeginHandExScope(p + 0x1d74, line);
        BTL_SERVER_FLOW_NotifyAbilityChangeEvent(p, ai, x, y);
        BTL_SERVER_FLOW_NotifyAbilityChangeEvent(p, bi, y, x);
        BTL_SERVER_FLOW_EndHandExScope((u32 *)(p + 0x1d74), s, line + 3);
        BTL_POKEPARAM_SetAbility((struct QJ *)a, y);
        BTL_POKEPARAM_SetAbility((struct QJ *)b, x);
        HAND_TOKUSEI_SwapAbilityHandlers((int)a, (int)b);
        BTL_SERVER_CMD_Push(((struct Obj03191 *)p)->fC, 0x58, ai);
        BTL_SERVER_CMD_Push(((struct Obj03191 *)p)->fC, 0x58, bi);
        if (x != y) {
            t = BTL_SERVER_FLOW_BeginHandExScope(p + 0x1d74, line + 16);
            BTL_SERVER_FLOW_NotifyAbilityChangedEvent(p, ai);
            BTL_SERVER_FLOW_NotifyAbilityChangedEvent(p, bi);
            line += 19;
            BTL_SERVER_FLOW_EndHandExScope((u32 *)(p + 0x1d74), t, line);
        }
        if (BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)a, 16) == 0) {
            if (x == 0x67) BTL_SERVER_FLOW_ProcDamagedItemReaction(p, a, 0);
            if (x == 0x7f) BTL_SERVER_FLOW_RecheckOpponentAbilityEffects(p, a);
        }
        if (BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)b, 16) == 0) {
            if (y == 0x67) BTL_SERVER_FLOW_ProcDamagedItemReaction(p, b, 0);
            if (y == 0x7f) BTL_SERVER_FLOW_RecheckOpponentAbilityEffects(p, b);
        }
    } else {
        BTL_SERVER_CMD_PushVariable(((struct Obj03191 *)p)->fC, 0x5a, 0x47, 0xffff0000);
    }
}

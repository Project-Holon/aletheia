/*
 * function: BTL_SERVER_FLOW_ProcHandExTransform
 * address: 0x021CA47C
 * packet: pkt_ov093_021CA47C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_SIDE_GetPokeByIdThunk 0x021B9934 thumb ov093
 *   BTL_POKEPARAM_IsIllusionActive 0x021D6C24 thumb ov093
 *   BTL_POKEPARAM_IsSemiInvulnerable 0x021D5C30 thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   BTL_POKEPARAM_Transform 0x021D6C50 thumb ov093
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTL_SERVER_FLOW_PushAbilityPopupIn 0x021C5A1C thumb ov093
 *   HAND_WAZA_RemoveAllMoveHandlers 0x021E0434 thumb ov093
 *   HAND_TOKUSEI_RemoveAbilityHandlers 0x021D8510 thumb ov093
 *   HAND_TOKUSEI_AddAbilityHandlers 0x021D8484 thumb ov093
 *   BTL_SERVER_CMD_Push 0x021CD4B0 thumb ov093
 *   BTL_SERVER_FLOW_PushMsgRecord 0x021C99A0 thumb ov093
 *   BTL_SERVER_FLOW_PushAbilityPopupOut 0x021C5A34 thumb ov093
 *   BTL_SERVER_FLOW_BeginHandExScope 0x021CC8D8 thumb ov093
 *   BTL_SERVER_FLOW_NotifyAbilityChangedEvent 0x021C7B7C thumb ov093
 *   BTL_SERVER_FLOW_EndHandExScope 0x021CC95C thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Cmd { u32 a:8; u32 id:5; u32 b:10; u32 flag:1; u32 c:8; u8 target; };
extern u8 *BTL_SIDE_GetPokeByIdThunk(char *p, int i);
struct Msg;
struct R4;
struct UtilWork;
extern int BTL_POKEPARAM_IsIllusionActive(struct R4 *p);
extern int BTL_POKEPARAM_IsSemiInvulnerable(struct UtilWork *p);
extern int func_021D59B4(u8 *p, int k);
struct Unk021D6C50;
extern int BTL_POKEPARAM_Transform(struct Unk021D6C50 *a, struct Unk021D6C50 *b);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_SERVER_FLOW_PushAbilityPopupIn(u8 *p, u8 *a);
extern void HAND_WAZA_RemoveAllMoveHandlers(u8 *);
extern void HAND_TOKUSEI_RemoveAbilityHandlers(void *p);
extern void *HAND_TOKUSEI_AddAbilityHandlers(void *);
extern void BTL_SERVER_CMD_Push(void *w, volatile u32 id, ...);
extern int BTL_SERVER_FLOW_PushMsgRecord(void *w, const struct Msg *m);
extern void BTL_SERVER_FLOW_PushAbilityPopupOut(u8 *p, u8 *a);
extern u32 BTL_SERVER_FLOW_BeginHandExScope(void *, int);
extern void BTL_SERVER_FLOW_NotifyAbilityChangedEvent(u8 *p, unsigned int i);
extern void BTL_SERVER_FLOW_EndHandExScope(u32 *p, u32 v, int line);
int BTL_SERVER_FLOW_ProcHandExTransform(u8 *p, struct Cmd *q)
{
    u8 *a = BTL_SIDE_GetPokeByIdThunk(*(char * *)&((struct Obj00003 *)p)->f8, (u8)q->id);
    u8 *b = BTL_SIDE_GetPokeByIdThunk(*(char * *)&((struct Obj00003 *)p)->f8, (u8)q->target);
    u16 k;
    int x, y;
    u32 lock;
    if (!BTL_POKEPARAM_IsIllusionActive((struct R4 *)a) && !BTL_POKEPARAM_IsIllusionActive((struct R4 *)b) && !BTL_POKEPARAM_IsSemiInvulnerable((struct UtilWork *)a)) {
        k = func_021D59B4(a, 16);
        if (BTL_POKEPARAM_Transform((struct Unk021D6C50 *)a, (struct Unk021D6C50 *)b)) {
            x = BTL_POKEPARAM_GetPokeId(a);
            y = BTL_POKEPARAM_GetPokeId(b);
            if (q->flag) BTL_SERVER_FLOW_PushAbilityPopupIn(p, a);
            HAND_WAZA_RemoveAllMoveHandlers(a);
            HAND_TOKUSEI_RemoveAbilityHandlers(a);
            HAND_TOKUSEI_AddAbilityHandlers(a);
            BTL_SERVER_CMD_Push(((struct Obj00003 *)p)->fC, 0x53, x, y);
            BTL_SERVER_FLOW_PushMsgRecord(p, (const struct Msg *)((u8 *)q + 8));
            if (q->flag) BTL_SERVER_FLOW_PushAbilityPopupOut(p, a);
            if (k != func_021D59B4(a, 17)) {
                lock = BTL_SERVER_FLOW_BeginHandExScope(p + 0x1d74, 0x3f0a);
                BTL_SERVER_FLOW_NotifyAbilityChangedEvent(p, x);
                BTL_SERVER_FLOW_EndHandExScope((u32 *)(p + 0x1d74), lock, 0x3f0c);
            }
            return 1;
        }
    }
    return 0;
}

/*
 * function: BTL_SERVER_FLOW_ExecCmdSwapHeldItems
 * address: 0x021C9CC0
 * packet: pkt_ov093_021C9CC0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: truncated accessor results live in u32 locals; u16 locals rotate seven spill offsets.
 * symbols:
 *   BTL_SIDE_GetPokeByIdThunk 0x021B9934 thumb ov093
 *   BTL_POKEPARAM_GetItem 0x021D5B40 thumb ov093
 *   BTL_SERVER_FLOW_BeginHandExScope 0x021CC8D8 thumb ov093
 *   BTL_SERVER_FLOW_EndHandExScope 0x021CC95C thumb ov093
 *   BTL_SERVER_FLOW_QueryHeldItemChangeBlockedEvent 0x021C7A54 thumb ov093
 *   BTL_SERVER_FLOW_NotifyHeldItemChangeBlockedEvent 0x021C7AA0 thumb ov093
 *   BTL_SERVER_FLOW_PushAbilityPopupIn 0x021C5A1C thumb ov093
 *   BTL_SERVER_FLOW_PushAbilityPopupOut 0x021C5A34 thumb ov093
 *   BTL_SERVER_FLOW_PushMsgRecord 0x021C99A0 thumb ov093
 *   BTL_SERVER_FLOW_SetHeldItem 0x021C2250 thumb ov093
 *   BTL_SERVER_FLOW_ProcDamagedItemReaction 0x021C195C thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 low:8,index:5,pad:10,flag:1,high:8; u8 id,pad5[3]; u8 msg[108]; } Ent;
struct Msg;
struct QI;
extern u8 *BTL_SIDE_GetPokeByIdThunk(char *p, int i);
extern u16 BTL_POKEPARAM_GetItem(struct QI *p);
extern u32 BTL_SERVER_FLOW_BeginHandExScope(void *, int);
extern void BTL_SERVER_FLOW_EndHandExScope(u32 *p, u32 v, int line);
extern int BTL_SERVER_FLOW_QueryHeldItemChangeBlockedEvent(u8 *, u8 *, u32);
extern void BTL_SERVER_FLOW_NotifyHeldItemChangeBlockedEvent(u8 *, u8 *);
extern void BTL_SERVER_FLOW_PushAbilityPopupIn(u8 *p, u8 *a);
extern void BTL_SERVER_FLOW_PushAbilityPopupOut(u8 *p, u8 *a);
extern int BTL_SERVER_FLOW_PushMsgRecord(void *w, const struct Msg *m);
extern void BTL_SERVER_FLOW_SetHeldItem(u8 *p, u8 *a, u16 b, u32 c);
extern void BTL_SERVER_FLOW_ProcDamagedItemReaction(u8 *p, u8 *q, u32 n);
int BTL_SERVER_FLOW_ExecCmdSwapHeldItems(u8 *p, const Ent *e)
{
    u8 *a;
    u8 *b;
    u16 x;
    u16 y;
    u32 s;
    u8 f;
    u32 t;
    a = BTL_SIDE_GetPokeByIdThunk(((struct Obj00003 *)p)->f8, (u8)e->id);
    b = BTL_SIDE_GetPokeByIdThunk(((struct Obj00003 *)p)->f8, (u8)e->index);
    x = (u16)(int)BTL_POKEPARAM_GetItem((struct QI *)b);
    y = (u16)(int)BTL_POKEPARAM_GetItem((struct QI *)a);
    s = BTL_SERVER_FLOW_BeginHandExScope(p + 0x1d74, 15671);
    f = BTL_SERVER_FLOW_QueryHeldItemChangeBlockedEvent(p, a, x);
    BTL_SERVER_FLOW_EndHandExScope((u32 *)(p + 0x1d74), s, 15673);
    if (f) {
        t = BTL_SERVER_FLOW_BeginHandExScope(p + 0x1d74, 15676);
        BTL_SERVER_FLOW_NotifyHeldItemChangeBlockedEvent(p, a);
        BTL_SERVER_FLOW_EndHandExScope((u32 *)(p + 0x1d74), t, 15678);
        return 0;
    }
    if (e->flag) BTL_SERVER_FLOW_PushAbilityPopupIn(p, b);
    BTL_SERVER_FLOW_PushMsgRecord(p, (const struct Msg *)e->msg);
    BTL_SERVER_FLOW_PushMsgRecord(p, (const struct Msg *)(e->msg + 36));
    BTL_SERVER_FLOW_PushMsgRecord(p, (const struct Msg *)(e->msg + 72));
    if (e->flag) BTL_SERVER_FLOW_PushAbilityPopupOut(p, b);
    BTL_SERVER_FLOW_SetHeldItem(p, b, y, 0);
    BTL_SERVER_FLOW_SetHeldItem(p, a, x, 0);
    BTL_SERVER_FLOW_ProcDamagedItemReaction(p, b, 0);
    BTL_SERVER_FLOW_ProcDamagedItemReaction(p, a, 0);
    return 1;
}

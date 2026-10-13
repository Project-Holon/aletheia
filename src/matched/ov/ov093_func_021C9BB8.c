/*
 * function: BTL_SERVER_FLOW_ExecCmdChangeHeldItem
 * address: 0x021C9BB8
 * packet: pkt_ov093_021C9BB8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_SIDE_GetPokeByIdThunk 0x021B9934 thumb ov093
 *   BTL_SERVER_FLOW_BeginHandExScope 0x021CC8D8 thumb ov093
 *   BTL_SERVER_FLOW_EndHandExScope 0x021CC95C thumb ov093
 *   BTL_SERVER_FLOW_QueryHeldItemChangeBlockedEvent 0x021C7A54 thumb ov093
 *   BTL_SERVER_FLOW_NotifyHeldItemChangeBlockedEvent 0x021C7AA0 thumb ov093
 *   BTL_SERVER_CMD_Push 0x021CD4B0 thumb ov093
 *   BTL_SERVER_FLOW_PushMsgRecord 0x021C99A0 thumb ov093
 *   BTL_SERVER_FLOW_SetHeldItem 0x021C2250 thumb ov093
 *   BTL_POKEPARAM_ClearConsumedItem 0x021D6738 thumb ov093
 *   BTL_SERVER_FLOW_ProcDamagedItemReaction 0x021C195C thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 low:8,index:5,pad:10,flag:1,high:8; u16 value; u8 id,a,b,c; u8 padA[2]; u8 msg[36]; } Ent;
extern u8 *BTL_SIDE_GetPokeByIdThunk(char *p, int i);
extern u32 BTL_SERVER_FLOW_BeginHandExScope(void *, int);
extern void BTL_SERVER_FLOW_EndHandExScope(u32 *p, u32 v, int line);
extern int BTL_SERVER_FLOW_QueryHeldItemChangeBlockedEvent(u8 *, u8 *, u32);
extern void BTL_SERVER_FLOW_NotifyHeldItemChangeBlockedEvent(u8 *, u8 *);
extern void BTL_SERVER_CMD_Push(void *w, volatile u32 id, ...);
struct Msg;
extern int BTL_SERVER_FLOW_PushMsgRecord(void *w, const struct Msg *m);
extern void BTL_SERVER_FLOW_SetHeldItem(u8 *p, u8 *a, u16 b, u32 c);
extern void BTL_POKEPARAM_ClearConsumedItem(u8 *);
extern void BTL_SERVER_FLOW_ProcDamagedItemReaction(u8 *, u8 *, u32);
int BTL_SERVER_FLOW_ExecCmdChangeHeldItem(u8 *p, const Ent *e)
{
    u8 *a;
    int line;
    u32 s;
    u8 f;
    u32 t;
    a = BTL_SIDE_GetPokeByIdThunk(((struct Obj00003 *)p)->f8, e->id);
    if (e->index != e->id) {
        line = 15615;
        s = BTL_SERVER_FLOW_BeginHandExScope(p + 0x1d74, line);
        f = BTL_SERVER_FLOW_QueryHeldItemChangeBlockedEvent(p, a, e->value);
        BTL_SERVER_FLOW_EndHandExScope((u32 *)(p + 0x1d74), s, line + 2);
        if (f) {
            t = BTL_SERVER_FLOW_BeginHandExScope(p + 0x1d74, line + 6);
            BTL_SERVER_FLOW_NotifyHeldItemChangeBlockedEvent(p, a);
            BTL_SERVER_FLOW_EndHandExScope((u32 *)(p + 0x1d74), t, line + 8);
            return 0;
        }
    }
    if (e->flag) BTL_SERVER_CMD_Push(((struct Obj00003 *)p)->fC, 87, (u8)e->index);
    BTL_SERVER_FLOW_PushMsgRecord(p, (const struct Msg *)e->msg);
    BTL_SERVER_FLOW_SetHeldItem(p, a, e->value, 0);
    if (e->flag) BTL_SERVER_CMD_Push(((struct Obj00003 *)p)->fC, 88, (u8)e->index);
    if (e->a) {
        BTL_POKEPARAM_ClearConsumedItem(a);
        BTL_SERVER_CMD_Push(((struct Obj00003 *)p)->fC, 43, e->id);
    }
    if (e->b) {
        BTL_POKEPARAM_ClearConsumedItem(BTL_SIDE_GetPokeByIdThunk(((struct Obj00003 *)p)->f8, e->c));
        BTL_SERVER_CMD_Push(((struct Obj00003 *)p)->fC, 43, e->c);
    }
    BTL_SERVER_FLOW_ProcDamagedItemReaction(p, a, 0);
    return 1;
}

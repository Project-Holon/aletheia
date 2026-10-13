/*
 * function: BTL_SERVER_FLOW_ExecCmdAddSick
 * address: 0x021C9178
 * packet: pkt_ov093_021C9178
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_SIDE_GetPokeByIdThunk 0x021B9934 thumb ov093
 *   BTL_SERVER_FLOW_HasMsgRecord 0x021C8828 thumb ov093
 *   func_021C9240 0x021C9240 thumb ov093
 *   BTL_POKEPARAM_IsFainted 0x021D5B68 thumb ov093
 *   BTL_SERVER_FLOW_TryApplySick 0x021C27A0 thumb ov093
 *   BTL_SERVER_FLOW_ProcSickAdded 0x021C2910 thumb ov093
 *   BTL_SERVER_FLOW_PushAbilityPopupIn 0x021C5A1C thumb ov093
 *   BTL_SERVER_FLOW_PushAbilityPopupOut 0x021C5A34 thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u32 value; } S;
typedef struct { u32 low:8, index:5, pad:10, flag:1, high:8; u32 kind; S value; u8 a,b,c,id,d; u8 pad11[3]; u8 msg[36]; } Ent;
extern u8 *BTL_SIDE_GetPokeByIdThunk(char *p, int i);
extern u32 BTL_SERVER_FLOW_HasMsgRecord(u8 *p);
extern int func_021C9240(void *, u8);
extern int BTL_POKEPARAM_IsFainted(void *);
extern int BTL_SERVER_FLOW_TryApplySick(u8 *, u8 *, u8 *, u32, S, u8, u32);
extern void BTL_SERVER_FLOW_ProcSickAdded(u8 *, u8 *, u8 *, int, S, int, int, const void *);
extern void BTL_SERVER_FLOW_PushAbilityPopupIn(u8 *p, u8 *a);
extern void BTL_SERVER_FLOW_PushAbilityPopupOut(u8 *p, u8 *a);
int BTL_SERVER_FLOW_ExecCmdAddSick(u8 *p, const Ent *e)
{
    u8 *a;
    u8 f;
    u8 *b;
    if (e->index != 31) a = BTL_SIDE_GetPokeByIdThunk(((struct Obj00003 *)p)->f8, (u8)e->index);
    else a = 0;
    f = (int)BTL_SERVER_FLOW_HasMsgRecord((u8 *)e->msg) == 0 && e->b == 0;
    if (func_021C9240(p + 0x1ab8, e->id)) {
        b = BTL_SIDE_GetPokeByIdThunk(((struct Obj00003 *)p)->f8, (u8)e->id);
        if (!BTL_POKEPARAM_IsFainted(b)) {
            if (!BTL_SERVER_FLOW_TryApplySick(p, b, a, e->kind, e->value, e->d, e->a)) {
                if (e->flag) BTL_SERVER_FLOW_PushAbilityPopupIn(p, a);
                BTL_SERVER_FLOW_ProcSickAdded(p, b, a, e->kind, e->value, f, e->c, e->msg);
                if (e->flag) BTL_SERVER_FLOW_PushAbilityPopupOut(p, a);
                return 1;
            }
        }
    }
    return 0;
}

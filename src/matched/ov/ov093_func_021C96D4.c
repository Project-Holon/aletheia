/*
 * function: BTL_SERVER_FLOW_ExecCmdPushMessage
 * address:  0x021C96D4
 * packet:   pkt_ov093_021C96D4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_SIDE_GetPokeByIdThunk  0x021B9934  thumb  ov093
 *   BTL_SERVER_FLOW_PushAbilityPopupIn  0x021C5A1C  thumb  ov093
 *   BTL_SERVER_FLOW_PushAbilityPopupOut  0x021C5A34  thumb  ov093
 *   BTL_SERVER_FLOW_PushMsgRecord  0x021C99A0  thumb  ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct Cmd {
    u32 a : 8;
    u32 id : 5;
    u32 pad : 10;
    u32 flag : 1;
};

extern u8 *BTL_SIDE_GetPokeByIdThunk(char *p, int i);
extern void BTL_SERVER_FLOW_PushAbilityPopupIn(u8 *p, u8 *a);
extern void BTL_SERVER_FLOW_PushAbilityPopupOut(u8 *p, u8 *a);
struct Msg;
extern int BTL_SERVER_FLOW_PushMsgRecord(void *w, const struct Msg *m);

int BTL_SERVER_FLOW_ExecCmdPushMessage(char *w, struct Cmd *c)
{
    u8 *r = 0;
    int id = c->id;
    if (id != 0x1F) {
        r = BTL_SIDE_GetPokeByIdThunk(*(char * *)&((struct Obj00003 *)w)->f8, (u8)id);
    }
    if (c->flag && r) BTL_SERVER_FLOW_PushAbilityPopupIn((u8 *)w, r);
    BTL_SERVER_FLOW_PushMsgRecord(w, (const struct Msg *)((u8 *)c + 4));
    if (c->flag && r) BTL_SERVER_FLOW_PushAbilityPopupOut((u8 *)w, r);
    return 1;
}

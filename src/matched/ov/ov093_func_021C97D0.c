/*
 * function: BTL_SERVER_FLOW_ExecCmdAdjustValueMessage
 * address:  0x021C97D0
 * packet:   pkt_ov093_021C97D0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_SERVER_FLOW_QueryAdjustedValueEvent  0x021C7BA8  thumb  ov093
 *   func_021C9818  0x021C9818  thumb  ov093
 *   BTL_SERVER_FLOW_PushMsgRecord  0x021C99A0  thumb  ov093
 */
#include "../include/Obj09973.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct Cmd {
    u32 a : 8;
    u32 id : 5;
    u32 pad : 19;
    u32 w4;
    u32 w8;
    u8 b12;
};

extern void BTL_SERVER_FLOW_QueryAdjustedValueEvent(u8 *p, u8 a, u32 b, u32 c, u32 *out);
extern int func_021C9818(u32 b, u32 a, u32 v);
struct Msg;
extern int BTL_SERVER_FLOW_PushMsgRecord(void *w, const struct Msg *m);

int BTL_SERVER_FLOW_ExecCmdAdjustValueMessage(void *w, const struct Cmd *c)
{
    u32 v;
    void *pv;
    v = c->w8;
    pv = &v;
    BTL_SERVER_FLOW_QueryAdjustedValueEvent(w, c->id, c->w4, c->b12, pv);
    if (func_021C9818(c->b12, c->w4, ((struct Obj09973 *)pv)->f0) != 0) {
        BTL_SERVER_FLOW_PushMsgRecord(w, (const struct Msg *)((u8 *)c + 0x10));
        return 1;
    }
    return 0;
}

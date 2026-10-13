/*
 * function: BTL_SERVER_FLOW_ProcMoveSickOnTarget
 * address:  0x021C25A4
 * packet:   pkt_ov093_021C25A4
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SERVER_FLOW_ClearMsgRecord  0x021C8810  thumb  ov093
 *   BTL_SERVER_FLOW_HasMsgRecord  0x021C8828  thumb  ov093
 *   BTL_SERVER_FLOW_PushMsgRecord  0x021C99A0  thumb  ov093
 *   BTL_SERVER_FLOW_QueryMoveSickIdEvent  0x021C264C  thumb  ov093
 *   BTL_SERVER_FLOW_RunMoveSickSelectedEvent  0x021C26A8  thumb  ov093
 *   BTL_SERVER_FLOW_RunMoveSickContEvent  0x021C26FC  thumb  ov093
 *   BTL_SERVER_FLOW_ApplyMoveSick  0x021C2758  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern void BTL_SERVER_FLOW_ClearMsgRecord(u8 *lock);
extern u32 BTL_SERVER_FLOW_HasMsgRecord(u8 *p);
struct Msg;
extern int BTL_SERVER_FLOW_PushMsgRecord(void *w, const struct Msg *m);
extern int BTL_SERVER_FLOW_QueryMoveSickIdEvent(u8 *p, u8 *a, u8 *b, u32 c);
extern void BTL_SERVER_FLOW_RunMoveSickSelectedEvent(u8 *p, u32 a, u8 *b, u8 *c, u32 d);
extern void BTL_SERVER_FLOW_RunMoveSickContEvent(u8 *p, u8 *a, u8 *b, u32 c, u32 *d);
extern int BTL_SERVER_FLOW_ApplyMoveSick(u8 *p, u32 b, u32 a, u32 s0, u32 s1, u32 s2, u32 t);

int BTL_SERVER_FLOW_ProcMoveSickOnTarget(u8 *p, u32 a, u32 b, u32 unused, u32 s0, u32 s1, u32 s2)
{
    int t;
    BTL_SERVER_FLOW_ClearMsgRecord(p + 0x1AE4);
    if (s0 == 0xFFFF) {
        s0 = BTL_SERVER_FLOW_QueryMoveSickIdEvent(p, (u8 *)a, (u8 *)b, (u32)(p + 0x1AE4));
        if (s0 == 0 || s0 == 0xFFFF)
            return 0;
    } else {
        BTL_SERVER_FLOW_RunMoveSickSelectedEvent(p, s0, (u8 *)a, (u8 *)b, (u32)(p + 0x1AE4));
    }
    BTL_SERVER_FLOW_RunMoveSickContEvent(p, (u8 *)a, (u8 *)b, s0, &s1);
    t = BTL_SERVER_FLOW_HasMsgRecord(p + 0x1AE4) ? 0 : 1;
    if (BTL_SERVER_FLOW_ApplyMoveSick(p, b, a, s0, s1, s2, t) != 0) {
        if (t == 0) {
            BTL_SERVER_FLOW_PushMsgRecord(p, (const struct Msg *)(p + 0x1AE4));
            BTL_SERVER_FLOW_ClearMsgRecord(p + 0x1AE4);
        }
        return 1;
    }
    return 0;
}

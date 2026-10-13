/*
 * function: BTL_SERVER_FLOW_PushMsgRecord
 * address:  0x021C99A0
 * packet:   pkt_ov093_021C99A0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_SERVER_FLOW_PushMsgStd  0x021C5DAC  thumb  ov093
 *   BTL_SERVER_FLOW_PushMsgSet  0x021C5EFC  thumb  ov093
 *   BTL_SERVER_FLOW_PushMsgStdSe  0x021C5E48  thumb  ov093
 *   BTL_SERVER_FLOW_PushMsgSetSe  0x021C5F98  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct Msg {
    u16 a;
    u16 kind : 8;
    u16 n : 7;
    u16 flag : 1;
    u8 data[0x1C];
    u32 w20;
};

extern void BTL_SERVER_FLOW_PushMsgStd(u8 *p, u32 a, int n, const int *v);
extern void BTL_SERVER_FLOW_PushMsgSet(u8 *p, u32 a, int n, const int *v);
extern void BTL_SERVER_FLOW_PushMsgStdSe(u8 *p, u32 a, u32 b, int n, int *v);
extern void BTL_SERVER_FLOW_PushMsgSetSe(u8 *p, u32 a, u32 b, int n, int *v);

int BTL_SERVER_FLOW_PushMsgRecord(void *w, const struct Msg *m)
{
    if (!m->flag) {
        switch (m->kind) {
        case 1:
            BTL_SERVER_FLOW_PushMsgStd(w, m->a, m->n, (const int *)m->data);
            return 1;
        case 2:
            BTL_SERVER_FLOW_PushMsgSet(w, m->a, m->n, (const int *)m->data);
            return 1;
        }
    } else {
        u16 x = m->w20;
        switch (m->kind) {
        case 1:
            BTL_SERVER_FLOW_PushMsgStdSe(w, m->a, x, m->n, (int *)m->data);
            return 1;
        case 2:
            BTL_SERVER_FLOW_PushMsgSetSe(w, m->a, x, m->n, (int *)m->data);
            return 1;
        }
    }
    return 0;
}

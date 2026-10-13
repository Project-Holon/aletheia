/*
 * function: BTL_SERVER_FLOW_ProcAbsorbRecovery
 * address:  0x021C20D0
 * packet:   pkt_ov093_021C20D0
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_SERVER_FLOW_ChangeHp  0x021C5B74  thumb  ov093
 *   BTL_POKEPARAM_SetTurnFlag  0x021D5FC0  thumb  ov093
 *   BTL_SERVER_FLOW_PushMsgRecord  0x021C99A0  thumb  ov093
 *   BTL_SERVER_FLOW_ClearMsgRecord  0x021C8810  thumb  ov093
 *   BTL_SERVER_FLOW_ProcDamagedItemReaction  0x021C195C  thumb  ov093
 *   BTL_SERVER_FLOW_ProcFaintedPoke  0x021C4F64  thumb  ov093
 *   BTL_SERVER_FLOW_CheckShowdown  0x021BC2B0  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern void BTL_SERVER_FLOW_ChangeHp(u8 *p, u8 *a, int c, int k);
struct UtilWork;
extern void BTL_POKEPARAM_SetTurnFlag(struct UtilWork *p, u32 n);
struct Msg;
extern int BTL_SERVER_FLOW_PushMsgRecord(void *w, const struct Msg *m);
extern void BTL_SERVER_FLOW_ClearMsgRecord(u8 *l);
extern void BTL_SERVER_FLOW_ProcDamagedItemReaction(u8 *p, u8 *q, u32 n);
extern int BTL_SERVER_FLOW_ProcFaintedPoke(u8 *p, u8 *a);
extern int BTL_SERVER_FLOW_CheckShowdown(u8 *p);

int BTL_SERVER_FLOW_ProcAbsorbRecovery(u8 *p, u8 *a, int c, u8 *l)
{
    int r;
    c = -c;
    if (c != 0) {
        BTL_SERVER_FLOW_ChangeHp(p, a, c, 1);
        BTL_POKEPARAM_SetTurnFlag((struct UtilWork *)a, 2);
        if (l != 0) {
            BTL_SERVER_FLOW_PushMsgRecord(p, (const struct Msg *)l);
            BTL_SERVER_FLOW_ClearMsgRecord(l);
        }
        r = 1;
        BTL_SERVER_FLOW_ProcDamagedItemReaction(p, a, 1);
        if (BTL_SERVER_FLOW_ProcFaintedPoke(p, a) != 0) {
            BTL_SERVER_FLOW_CheckShowdown(p);
            return r;
        }
        return r;
    }
    return 0;
}

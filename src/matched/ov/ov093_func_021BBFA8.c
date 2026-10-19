/*
 * function: BTL_SERVER_FLOW_RunActionOrder
 * address: 0x021BBFA8
 * packet: pkt_ov093_021BBFA8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_ACTION_GetKind 0x021D8454 thumb ov093
 *   BTL_SERVER_FLOW_NotifyRotationEnd 0x021BDC2C thumb ov093
 *   BTL_SERVER_FLOW_ResortActionOrder 0x021BC0E8 thumb ov093
 *   BTL_SERVER_FLOW_ProcAction 0x021BCCE0 thumb ov093
 *   BTL_SERVER_FLOW_ProcFaintRewards 0x021C5200 thumb ov093
 *   BTL_SERVER_FLOW_CheckShowdown 0x021BC2B0 thumb ov093
 *   BTL_SERVER_FLOW_ProcTurnCheck 0x021C446C thumb ov093
 *   func_021BC0D8 0x021BC0D8 thumb ov093
 *   BTL_SERVER_FLOW_IsAnySeenPokeOnField 0x021C8534 thumb ov093
 *   BTL_SERVER_FLOW_CollectChangeRequests 0x021BC4DC thumb ov093
 *   BTL_SERVER_FLOW_ProcClientMemberChange 0x021C6158 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u32 a, b, c; u8 d, f; unsigned short pad; } E;
typedef struct { u8 pad[0x14]; u32 state; u8 pad2[0x76a]; u8 n; u8 pad3[0x5d]; E e[6]; } S;
extern u32 BTL_ACTION_GetKind(u32 *);
extern void BTL_SERVER_FLOW_NotifyRotationEnd(u8 *p);
extern void BTL_SERVER_FLOW_ResortActionOrder(S *, E *, u32);
extern u32 BTL_SERVER_FLOW_ProcAction(S *, E *);
extern int BTL_SERVER_FLOW_ProcFaintRewards(u8 *p);
extern int BTL_SERVER_FLOW_CheckShowdown(u8 *p);
extern int BTL_SERVER_FLOW_ProcTurnCheck(u8 *p);
extern int func_021BC0D8(void *, int);
extern int BTL_SERVER_FLOW_IsAnySeenPokeOnField(u8 *p);
extern int BTL_SERVER_FLOW_CollectChangeRequests(u8 *p, u8 *out);
extern void BTL_SERVER_FLOW_ProcClientMemberChange(u8 *p, u8 *a);
u32 BTL_SERVER_FLOW_RunActionOrder(S *p, u32 i)
{
    u32 previous = 0;
    for (; i < p->n; i++) {
        u32 current = BTL_ACTION_GetKind(&p->e[i].b);
        u8 stop;
        if (previous == 6 && current != 6) {
            BTL_SERVER_FLOW_NotifyRotationEnd((u8 *)p);
            BTL_SERVER_FLOW_ResortActionOrder(p, &p->e[i], p->n - i);
        }
        previous = BTL_SERVER_FLOW_ProcAction(p, &p->e[i]);
        stop = BTL_SERVER_FLOW_ProcFaintRewards((u8 *)p);
        if ((u8)BTL_SERVER_FLOW_CheckShowdown((u8 *)p)) { p->state = 4; return i + 1; }
        if (p->state == 6) return i + 1;
        if (p->state == 1) return i + 1;
        if (stop) { p->state = 3; return i + 1; }
    }
    if (p->state == 0) {
        u8 stop = BTL_SERVER_FLOW_ProcTurnCheck((u8 *)p);
        int present;
        if ((u8)BTL_SERVER_FLOW_CheckShowdown((u8 *)p)) { p->state = 4; return p->n; }
        if (stop) { p->state = 3; return p->n; }
        present = func_021BC0D8((u8 *)p + 0x3e0, 0);
        if (BTL_SERVER_FLOW_IsAnySeenPokeOnField((u8 *)p) || present) {
            BTL_SERVER_FLOW_CollectChangeRequests((u8 *)p, (u8 *)p + 0x4ce);
            BTL_SERVER_FLOW_ProcClientMemberChange((u8 *)p, (u8 *)p + 0x4ce);
            p->state = 2;
            return p->n;
        }
        p->state = 0;
    }
    return p->n;
}

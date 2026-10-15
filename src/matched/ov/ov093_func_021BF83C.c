/*
 * function: BTL_SERVER_FLOW_RemoveImmuneTargets
 * address:  0x021BF83C
 * packet:   pkt_ov093_021BF83C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   RESEARCH_GRAPH_GetEntryValueB  0x021BF894  thumb  ov093
 *   func_021BF8A4  0x021BF8A4  thumb  ov093
 *   func_021BF8B4  0x021BF8B4  thumb  ov093
 *   func_021BF8C4  0x021BF8C4  thumb  ov093
 *   BTL_SERVER_FLOW_CheckNoGuardHit  0x021BF324  thumb  ov093
 *   BTL_SERVER_FLOW_QuerySemiInvulnerableHit  0x021C6948  thumb  ov093
 *   BTL_SERVER_FLOW_PushMoveBlockedMessage  0x021C572C  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern void RESEARCH_GRAPH_GetEntryValueB(int d);
extern u8 *func_021BF8A4(int d);
extern void func_021BF8B4(int d, u8 *x);
extern u8 *func_021BF8C4(int d);
extern int BTL_SERVER_FLOW_CheckNoGuardHit(u8 *p, u8 *a, u8 *b);
extern int BTL_SERVER_FLOW_QuerySemiInvulnerableHit(u8 *p, u8 *a, u8 *b, u32 v);
extern void BTL_SERVER_FLOW_PushMoveBlockedMessage(u8 *p, u8 *x, u32 v);

void BTL_SERVER_FLOW_RemoveImmuneTargets(u8 *p, u16 *b, u8 *c, int d)
{
    u8 *x;
    RESEARCH_GRAPH_GetEntryValueB(d);
    x = func_021BF8A4(d);
    while (x != 0) {
        if (BTL_SERVER_FLOW_CheckNoGuardHit(p, c, x) == 0) {
            if (BTL_SERVER_FLOW_QuerySemiInvulnerableHit(p, c, x, *b) != 0) {
                func_021BF8B4(d, x);
                BTL_SERVER_FLOW_PushMoveBlockedMessage(p, x, *b);
            }
        }
        x = func_021BF8C4(d);
    }
}

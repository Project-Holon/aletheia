/*
 * function: EVENTDATA_SYSTEM_GetConnectRailExitOffset
 * address:  0x021626B0
 * packet:   pkt_ov010_021626B0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled tail-call wrapper over EVENTDATA_SYSTEM_CalcConnectRailExitOffset (a pool word plus bx r3,
 * no prologue); witness for ov021 FIELD_EVENT_CHECK_StartRailConnectEvent.
 *
 * symbols:
 *   EVENTDATA_SYSTEM_CalcConnectRailExitOffset  0x02162BCC  thumb  ov010
 */

typedef unsigned short u16;

struct Box;
struct Q;
extern u16 EVENTDATA_SYSTEM_CalcConnectRailExitOffset(struct Box *b, struct Q *q);

u16 EVENTDATA_SYSTEM_GetConnectRailExitOffset(void *b, void *q)
{
    return EVENTDATA_SYSTEM_CalcConnectRailExitOffset(b, q);
}

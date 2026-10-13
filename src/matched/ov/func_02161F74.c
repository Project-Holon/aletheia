/*
 * function: EVENT_FIELD_PROCLINK_RunReturnSlotsIfOffline
 * address:  0x02161F74
 * packet:   pkt_02161F74
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   EVENT_FIELD_PROCLINK_IsNetConnected  0x0216210C  thumb  ov010
 *   EVENT_FIELD_PROCLINK_RunReturnSlots  0x02162120  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int EVENT_FIELD_PROCLINK_IsNetConnected(int a0);
extern int EVENT_FIELD_PROCLINK_RunReturnSlots();

void EVENT_FIELD_PROCLINK_RunReturnSlotsIfOffline(int a0, int a1, int a2)
{
    int t4;
    int t5;
    int t6;

t5 = a0 + 0;
t4 = a1 + 0;
t6 = a2 + 0;
    a0 = EVENT_FIELD_PROCLINK_IsNetConnected(a0);
loc_02161F80:
    if (a0 != 0) goto loc_02161F8E;
loc_02161F84:
a0 = t5 + 0;
a1 = t4 + 0;
a2 = t6 + 0;
    a0 = EVENT_FIELD_PROCLINK_RunReturnSlots(a0, a1, a2);
loc_02161F8E:
    return;}

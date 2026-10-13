/*
 * function: EVENT_FIELD_PROCLINK_ClearReturnDefaultAndPending
 * address:  0x021620A0
 * packet:   pkt_021620A0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   EVENT_FIELD_PROCLINK_ClearReturnPendingSlot  0x02162358  thumb  ov010
 *   EVENT_FIELD_PROCLINK_ClearReturnDefaultSlot  0x021622F4  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int EVENT_FIELD_PROCLINK_ClearReturnPendingSlot();
extern int EVENT_FIELD_PROCLINK_ClearReturnDefaultSlot();

int EVENT_FIELD_PROCLINK_ClearReturnDefaultAndPending(int a0)
{
    int t4;

t4 = a0 + 0;
    a0 = EVENT_FIELD_PROCLINK_ClearReturnPendingSlot(a0);
loc_021620A8:
a0 = t4 + 0;
    a0 = EVENT_FIELD_PROCLINK_ClearReturnDefaultSlot(a0);
loc_021620AE:
    return a0;}

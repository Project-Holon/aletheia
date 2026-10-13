/*
 * function: EVENT_FIELD_PROCLINK_ClearReturnResultSlot
 * address: 0x02162038
 * packet: pkt_ov010_02162038
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   EVENT_FIELD_PROCLINK_ClearReturnResultSlotSub 0x02162330 thumb ov010
 */
extern void EVENT_FIELD_PROCLINK_ClearReturnResultSlotSub(char *, unsigned);
void EVENT_FIELD_PROCLINK_ClearReturnResultSlot(char *p, int index)
{
    EVENT_FIELD_PROCLINK_ClearReturnResultSlotSub(p, index);
}

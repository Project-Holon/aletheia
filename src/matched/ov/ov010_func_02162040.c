/*
 * function: EVENT_FIELD_PROCLINK_ClearReturnPendingSlotThunk
 * address: 0x02162040
 * packet: pkt_ov010_02162040
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * The full target body overwrites r1/r2 with 0/8 before use; neither
 * caller nor thunk supplies those legacy trailing parameters.
 * symbols:
 *   EVENT_FIELD_PROCLINK_ClearReturnPendingSlot 0x02162358 thumb ov010
 */
extern void EVENT_FIELD_PROCLINK_ClearReturnPendingSlot(int a0);
void EVENT_FIELD_PROCLINK_ClearReturnPendingSlotThunk(char *p)
{
    EVENT_FIELD_PROCLINK_ClearReturnPendingSlot((int)p);
}

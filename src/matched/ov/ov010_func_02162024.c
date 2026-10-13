/*
 * function: EVENT_FIELD_PROCLINK_GetReturnResultSlot
 * address: 0x02162024
 * packet: pkt_ov010_02162024
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   EVENT_FIELD_PROCLINK_GetReturnResultSlotSub 0x021622AC thumb ov010
 */
extern int EVENT_FIELD_PROCLINK_GetReturnResultSlotSub(char *, int, void *);
int EVENT_FIELD_PROCLINK_GetReturnResultSlot(char *p, int index, void *out)
{
    return EVENT_FIELD_PROCLINK_GetReturnResultSlotSub(p, index, out);
}

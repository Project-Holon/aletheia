/*
 * function: EVENT_FIELD_PROCLINK_ClearReturnSlots
 * address:  0x02161F68
 * packet:   pkt_ov010_02161F68
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 */

void func_02082BCC(void *p, int v, int n);

void EVENT_FIELD_PROCLINK_ClearReturnSlots(void *p)
{
    func_02082BCC(p, 0, 0x48);
}

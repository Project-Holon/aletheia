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
 *   MI_CpuFill8  0x02082BCC  arm
 */

void MI_CpuFill8(void *p, int v, int n);

void EVENT_FIELD_PROCLINK_ClearReturnSlots(void *p)
{
    MI_CpuFill8(p, 0, 0x48);
}

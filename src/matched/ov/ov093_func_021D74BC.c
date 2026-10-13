/*
 * function: BTL_EVENT_ClearFactor
 * address:  0x021D74BC
 * packet:   pkt_ov093_021D74BC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 */

void MI_CpuFill8(int, int, int);

void BTL_EVENT_ClearFactor(int a)
{
    MI_CpuFill8(a, 0, 0x3c);
}

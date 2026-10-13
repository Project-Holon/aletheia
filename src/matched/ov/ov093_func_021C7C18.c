/*
 * function: BTL_SERVER_FLOW_ClearEffectivenessRecord
 * address:  0x021C7C18
 * packet:   pkt_021C7C18
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

void MI_CpuFill8(void *p, int v, int n);

void BTL_SERVER_FLOW_ClearEffectivenessRecord(void *p)
{
    MI_CpuFill8(p, 0, 0xc);
}

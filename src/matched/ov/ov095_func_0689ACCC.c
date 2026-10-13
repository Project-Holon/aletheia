/*
 * function: BTLV_SCD_ClearTargetSet
 * address:  0x0689ACCC
 * packet:   pkt_0689ACCC
 * region:   ov095
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

void BTLV_SCD_ClearTargetSet(void *p)
{
    MI_CpuFill8(p, 0, 9);
}

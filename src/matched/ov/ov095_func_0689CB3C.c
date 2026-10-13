/*
 * function: BTL_POKESET_Clear
 * address:  0x0689CB3C
 * packet:   pkt_0689CB3C
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

void BTL_POKESET_Clear(void *p)
{
    MI_CpuFill8(p, 0, 0x48);
}

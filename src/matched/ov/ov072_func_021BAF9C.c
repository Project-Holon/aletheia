/*
 * function: TOWNMAP_ClearScroll
 * address:  0x021BAF9C
 * packet:   pkt_021BAF9C
 * region:   ov072
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

void TOWNMAP_ClearScroll(void *p)
{
    MI_CpuFill8(p, 0, 0x38);
}

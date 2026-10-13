/*
 * function: TOWNMAP_CursorClear
 * address:  0x021BA0D8
 * packet:   pkt_021BA0D8
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

void TOWNMAP_CursorClear(void *p)
{
    MI_CpuFill8(p, 0, 0x18);
}

/*
 * function: TOWNMAP_GRH_InitTouch
 * address:  0x021BB5D4
 * packet:   pkt_021BB5D4
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

void TOWNMAP_GRH_InitTouch(void *p, int heap)
{
    MI_CpuFill8(p, 0, 0x30);
}

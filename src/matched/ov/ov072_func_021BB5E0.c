/*
 * function: TOWNMAP_GRH_ClearTouch
 * address:  0x021BB5E0
 * packet:   pkt_021BB5E0
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

void TOWNMAP_GRH_ClearTouch(void *p)
{
    MI_CpuFill8(p, 0, 0x30);
}

/*
 * function: INTRUDE_FIELD_InitStartParam
 * address:  0x0217BF1C
 * packet:   pkt_ov018_0217BF1C
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 */

void MI_CpuFill8(void *dst, int val, int size);

void INTRUDE_FIELD_InitStartParam(void *p)
{
    MI_CpuFill8(p, 0, 0x10);
}

/*
 * function: INTRUDE_COMM_ResetMemberName
 * address: 0x02175EE8
 * packet: pkt_ov011_02175EE8
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: Two alignment bytes at 02175EFA before EFC.
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 */
typedef unsigned char u8;
extern void MI_CpuFill8(void *, int, int);
void INTRUDE_COMM_ResetMemberName(u8 *p)
{
    MI_CpuFill8(p, 0, 0x14);
    p[0x10] = 4;
}

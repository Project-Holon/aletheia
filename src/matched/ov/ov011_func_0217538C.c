/*
 * function: INTRUDE_COMM_InitRequest
 * address: 0x0217538C
 * packet: pkt_ov011_0217538C
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes at 0x021753B6 precede the owned 021753B8 function.
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   INTRUDE_COMM_NextRequestToken 0x021753B8 thumb ov011
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void MI_CpuFill8(void *, u8, u32);
extern void INTRUDE_COMM_NextRequestToken(u8 *);
void INTRUDE_COMM_InitRequest(u8 *p, int a)
{
    MI_CpuFill8(p + 0x154, 0, 8);
    p[0x154] = a;
    p[0x155] = 4;
    p[0x158] = 0;
    INTRUDE_COMM_NextRequestToken(p);
}

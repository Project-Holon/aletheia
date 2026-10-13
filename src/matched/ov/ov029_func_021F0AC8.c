/*
 * function: C_GEAR_InitTile
 * address: 0x021F0AC8
 * packet: pkt_ov029_021F0AC8
 * region: ov029
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 */
extern void MI_CpuFill8(void *, int, int);
void C_GEAR_InitTile(unsigned char *p, int a, int b)
{
    MI_CpuFill8(p, 0, 8);
    p[6] = a;
    p[7] = b;
}

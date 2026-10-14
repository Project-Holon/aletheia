/*
 * function: GURU2_MAIN_ClearSendBuffer
 * address: 0x021E16AC
 * packet: pkt_ov137_021E16AC
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void MI_CpuFill8(void *, int, unsigned);
char *GURU2_MAIN_ClearSendBuffer(char *p)
{
    MI_CpuFill8(p + 0xb8, 0, 32);
    return p + 0xb8;
}

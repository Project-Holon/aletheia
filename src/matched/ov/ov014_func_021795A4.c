/*
 * function: func_021795A4
 * address: 0x021795A4
 * packet: pkt_ov014_021795A4
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   g_021797A8 0x021797A8 data ov014 a4
 */
typedef unsigned char u8;
extern u8 *g_021797A8;
unsigned short func_021795A4(void)
{
    if (g_021797A8 != 0) return *(unsigned short *)(g_021797A8 + 0x1EA8);
    return 0;
}

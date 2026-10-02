/*
 * function: func_021780E4
 * address: 0x021780E4
 * packet: pkt_ov014_021780E4
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   g_021797A4 0x021797A4 data ov014 a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern u8 *g_021797A4;
void func_021780E4(void)
{
    if (g_021797A4)
        *(u16 *)(g_021797A4 + 0xc6c) = 20;
}

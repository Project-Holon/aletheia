/*
 * function: WIH_SetScanWaitFrames
 * address: 0x02179650
 * packet: pkt_ov014_02179650
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
typedef unsigned short u16;
void WIH_SetScanWaitFrames(u16 v)
{
    *(u16 *)(g_021797A8 + 0x1ec2) = v;
}

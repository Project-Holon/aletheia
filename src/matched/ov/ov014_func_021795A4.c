/*
 * function: WIH_GetOwnAid
 * address: 0x021795A4
 * packet: pkt_ov014_021795A4
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gWihWork 0x021797A8 data ov014 a4
 */
typedef unsigned char u8;
extern u8 *gWihWork;
unsigned short WIH_GetOwnAid(void)
{
    if (gWihWork != 0) return *(unsigned short *)(gWihWork + 0x1EA8);
    return 0;
}

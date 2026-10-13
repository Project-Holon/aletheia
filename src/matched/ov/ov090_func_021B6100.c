/*
 * function: PLIST_COMM_Start
 * address: 0x021B6100
 * packet: pkt_ov090_021B6100
 * region: ov090
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Leaf of ov134 021DCB48; clears byte 0x62. Existing matched follower 021B6108.
 */
typedef unsigned char u8;
void PLIST_COMM_Start(u8 *p)
{
    p[0x62] = 0;
}

/*
 * function: INTRUDE_COMM_NextRequestToken
 * address: 0x021753B8
 * packet: pkt_ov011_021753B8
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
void INTRUDE_COMM_NextRequestToken(u8 *p)
{
    p[0x944]++;
    p[0x159] = p[0x944];
}

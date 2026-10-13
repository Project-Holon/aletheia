/*
 * function: INTRUDE_COMM_SetSessionFinished
 * address: 0x02175BAC
 * packet: pkt_ov011_02175BAC
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: follower 0x02175BBC already filed separately.
 */
typedef unsigned char u8;
void INTRUDE_COMM_SetSessionFinished(u8 *p)
{
    p[0x1A5] |= 8;
}

/*
 * unit: yes
 * function: INTRUDE_COMM_ClearJoinStatus, INTRUDE_COMM_SetJoinStatus
 * address: 0x02175D20
 * packet: pkt_ov011_02175D20
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * extent: store-return follower at 02175D2C, claimed by root for this unit.
 */
typedef unsigned char u8;
void INTRUDE_COMM_ClearJoinStatus(u8 *p)
{
    p[0x1a4] = 0;
}
void INTRUDE_COMM_SetJoinStatus(u8 *p, u8 v)
{
    p[0x1a4] = v;
}

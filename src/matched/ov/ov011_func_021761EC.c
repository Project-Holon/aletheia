/*
 * function: INTRUDE_COMM_TakeJoinReply
 * address: 0x021761EC
 * packet: pkt_ov011_021761EC
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   INTRUDE_COMM_ClearJoinReply 0x02176200 thumb ov011
 */
typedef unsigned char u8;
extern void INTRUDE_COMM_ClearJoinReply(char *p);
u8 INTRUDE_COMM_TakeJoinReply(char *p)
{
    u8 value;
    value = ((u8 *)p)[0x1a3];
    INTRUDE_COMM_ClearJoinReply(p);
    return value;
}

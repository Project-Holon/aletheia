/*
 * function: INTRUDE_CMD_RecvJoinReply
 * address: 0x02173E5C
 * packet: pkt_ov011_02173E5C
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov011/unit_02173CB0.c and filed here.
 *
 * symbols:
 *   INTRUDE_COMM_StoreJoinReply 0x021761C4 thumb ov011
 */

typedef unsigned char u8;
void INTRUDE_COMM_StoreJoinReply(u8 *p, u8 *s);
void INTRUDE_CMD_RecvJoinReply(int a, int b, u8 *c, u8 *p);

void INTRUDE_CMD_RecvJoinReply(int a, int b, u8 *c, u8 *p)
{
    INTRUDE_COMM_StoreJoinReply(p + 0x1ac, c);
}

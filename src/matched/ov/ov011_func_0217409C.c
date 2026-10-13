/*
 * function: INTRUDE_CMD_RecvProposalReply
 * address: 0x0217409C
 * packet: pkt_ov011_0217409C
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
 *   INTRUDE_COMM_SetJoinStatus 0x02175D2C thumb ov011
 */

typedef unsigned char u8;
void INTRUDE_COMM_SetJoinStatus(u8 *p, int v);
void INTRUDE_CMD_RecvProposalReply(int a, int b, int *c, u8 *p);

void INTRUDE_CMD_RecvProposalReply(int a, int b, int *c, u8 *p)
{
    INTRUDE_COMM_SetJoinStatus(p + 0x1ac, *c);
}

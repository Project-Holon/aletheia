/*
 * function: INTRUDE_CMD_RecvEndNotice
 * address: 0x021742DC
 * packet: pkt_ov011_021742DC
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
 *   INTRUDE_COMM_SetNoticeState 0x02175C58 thumb ov011
 */

typedef unsigned char u8;
void INTRUDE_COMM_SetNoticeState(void *a, int b);
void INTRUDE_CMD_RecvEndNotice(int a, int b, int c, u8 *p);

void INTRUDE_CMD_RecvEndNotice(int a, int b, int c, u8 *p)
{
    INTRUDE_COMM_SetNoticeState(p + 0x1ac, 2);
}

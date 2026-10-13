/*
 * function: INTRUDE_CMD_RecvStartNotice
 * address: 0x02174298
 * packet: pkt_ov011_02174298
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
void INTRUDE_CMD_RecvStartNotice(int a, int b, int c, u8 *p);

void INTRUDE_CMD_RecvStartNotice(int a, int b, int c, u8 *p)
{
    INTRUDE_COMM_SetNoticeState(p + 0x1ac, 1);
}

/*
 * function: INTRUDE_CMD_RecvReadyNotice
 * address: 0x02174248
 * packet: pkt_ov011_02174248
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
 *   INTRUDE_COMM_SetSessionReadyBit 0x02175C04 thumb ov011
 */

typedef unsigned char u8;
void INTRUDE_COMM_SetSessionReadyBit(u8 *p, int bit);
void INTRUDE_CMD_RecvReadyNotice(int a, int b, int c, u8 *p);

void INTRUDE_CMD_RecvReadyNotice(int a, int b, int c, u8 *p)
{
    INTRUDE_COMM_SetSessionReadyBit(p + 0x1ac, a);
}

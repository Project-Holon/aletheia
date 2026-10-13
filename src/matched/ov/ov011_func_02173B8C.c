/*
 * function: INTRUDE_COMM_RecvAnswer
 * address: 0x02173B8C
 * packet: pkt_ov011_02173B8C
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov011/unit_02173658.c and filed here.
 *
 * symbols:
 *   INTRUDE_COMM_SetRequestResultAccepted 0x02175508 thumb ov011
 */

typedef unsigned char u8;
void INTRUDE_COMM_SetRequestResultAccepted(int a, int b, int c);
void INTRUDE_COMM_RecvAnswer(int a, int b, u8 *c, int d);

void INTRUDE_COMM_RecvAnswer(int a, int b, u8 *c, int d)
{
    INTRUDE_COMM_SetRequestResultAccepted(d, a, *c);
}

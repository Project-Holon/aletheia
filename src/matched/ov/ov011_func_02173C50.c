/*
 * function: INTRUDE_COMM_RecvReady
 * address: 0x02173C50
 * packet: pkt_ov011_02173C50
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov011/unit_02173658.c and filed here.
 */

typedef unsigned char u8;
void INTRUDE_COMM_RecvReady(int n, int b, int c, u8 *p);

void INTRUDE_COMM_RecvReady(int n, int b, int c, u8 *p) { p[0x924] |= (u8)(1 << n); }

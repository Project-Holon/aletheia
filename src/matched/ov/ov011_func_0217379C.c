/*
 * function: INTRUDE_COMM_RecvRecordRequest
 * address: 0x0217379C
 * packet: pkt_ov011_0217379C
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
void INTRUDE_COMM_RecvRecordRequest(int a, int b, int c, u8 *p);

void INTRUDE_COMM_RecvRecordRequest(int a, int b, int c, u8 *p) { p[0x8fe] = 1; }

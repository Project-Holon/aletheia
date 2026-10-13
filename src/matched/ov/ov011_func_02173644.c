/*
 * function: INTRUDE_COMM_RecvQuit
 * address: 0x02173644
 * packet: pkt_ov011_02173644
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov011/intrude_comm.c and filed here.
 */

typedef unsigned char  u8;

void INTRUDE_COMM_RecvQuit(int a, int b, u8 *p)
{
    p[0x93F] |= 2;
}

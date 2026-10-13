/*
 * function: INTRUDE_COMM_RecvPageRequest
 * address: 0x0217482C
 * packet: pkt_ov011_0217482C
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov011/unit_021743B4.c and filed here.
 */

typedef unsigned char  u8;
void INTRUDE_COMM_RecvPageRequest(int a, int b, const u8 *c, u8 *p);

/*
 * Hidden function (round 5): copies the four bytes at c to the 4-byte record
 * number a at offset 0x8d4 of p. The const source lets both byte pairs load
 * before their stores.
 */
void INTRUDE_COMM_RecvPageRequest(int a, int b, const u8 *c, u8 *p)
{
    u8 *q = p + a * 4;
    q[0x8d4] = c[0];
    q[0x8d5] = c[1];
    q[0x8d6] = c[2];
    q[0x8d7] = c[3];
}

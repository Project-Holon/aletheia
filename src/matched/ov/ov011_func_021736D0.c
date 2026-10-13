/*
 * function: INTRUDE_COMM_GetWorkArea
 * address: 0x021736D0
 * packet: pkt_ov011_021736D0
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
u8 *INTRUDE_COMM_GetWorkArea(int a, u8 *p);

u8 *INTRUDE_COMM_GetWorkArea(int a, u8 *p) { return p + 0x7f0; }

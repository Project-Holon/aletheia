/*
 * function: INTRUDE_COMM_GetStatusRecord
 * address: 0x021736C0
 * packet: pkt_ov011_021736C0
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 *
 * Function with no listing label, matched inside src/game/ov011/unit_02173658.c and filed here.
 */

typedef unsigned char u8;
typedef struct { u8 d[0x4c]; } E_021736C0;
E_021736C0 *INTRUDE_COMM_GetStatusRecord(int i, u8 *p);

E_021736C0 *INTRUDE_COMM_GetStatusRecord(int i, u8 *p) { return (E_021736C0 *)(p + 0x670) + i; }

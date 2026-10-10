/*
 * function: func_021736B0
 * address: 0x021736B0
 * packet: pkt_ov011_021736B0
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
typedef struct { u8 d[0x34]; } E_021736B0;
E_021736B0 *func_021736B0(int i, u8 *p);

E_021736B0 *func_021736B0(int i, u8 *p) { return (E_021736B0 *)(p + 0x754) + i; }

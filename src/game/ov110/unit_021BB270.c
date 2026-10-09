/*
 * file:     unit_021BB270.c
 * function: func_021BB270
 * address: 0x021BB270
 * packet: pkt_ov110_021BB270
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021C37AF 0x021C37AF data a1
 */
typedef unsigned char u8;
extern const u8 d_021C37AF[];
int func_021BB270(int n) {return *(const u8 *)((unsigned)d_021C37AF+n*10);}

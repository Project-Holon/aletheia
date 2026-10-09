/*
 * file:     unit_021BB240.c
 * function: func_021BB240
 * address: 0x021BB240
 * packet: pkt_ov110_021BB240
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021C37AC 0x021C37AC data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern const u8 d_021C37AC[];
u8 func_021BB240(u32 i) { return *(const u8 *)(d_021C37AC+i*10); }

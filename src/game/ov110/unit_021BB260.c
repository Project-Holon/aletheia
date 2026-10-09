/*
 * file:     unit_021BB260.c
 * function: func_021BB260
 * address: 0x021BB260
 * packet: pkt_ov110_021BB260
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021C37AE 0x021C37AE data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern const u8 d_021C37AE[];
u8 func_021BB260(u32 i) { return *(const u8 *)(d_021C37AE+i*10); }

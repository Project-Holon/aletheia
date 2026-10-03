/*
 * function: func_021BB214
 * address: 0x021BB214
 * packet: pkt_ov110_021BB214
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021C37A8 0x021C37A8 data a2
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern const u8 d_021C37A8[];
u16 func_021BB214(u32 i) { return *(const u16 *)(d_021C37A8+i*10); }

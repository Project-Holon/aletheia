/*
 * function: func_021BB764
 * address: 0x021BB764
 * packet: pkt_ov072_021BB764
 * region: ov072
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021BBC28 0x021BBC28 data a4
 */
typedef unsigned int u32;
typedef unsigned char u8;
extern u32 d_021BBC28;
u8 func_021BB764(int unused, u32 i) { return *(u32 *)((u32)&d_021BBC28 + i*40); }

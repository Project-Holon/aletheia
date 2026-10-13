/*
 * function: PMSI_SEARCH_GetKeyKind
 * address: 0x021BB280
 * packet: pkt_ov110_021BB280
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021C37B1 0x021C37B1 data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern const u8 d_021C37B1[];
u8 PMSI_SEARCH_GetKeyKind(u32 i) { return *(const u8 *)(d_021C37B1+i*10); }

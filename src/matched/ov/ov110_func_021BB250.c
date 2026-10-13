/*
 * function: PMSI_SEARCH_GetKeyDown
 * address: 0x021BB250
 * packet: pkt_ov110_021BB250
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021C37AD 0x021C37AD data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern const u8 d_021C37AD[];
u8 PMSI_SEARCH_GetKeyDown(u32 i) { return *(const u8 *)(d_021C37AD+i*10); }

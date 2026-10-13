/*
 * function: PMSI_SEARCH_GetKeyChar
 * address: 0x021BB214
 * packet: pkt_ov110_021BB214
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   sPmsiKanaKeys 0x021C37A8 data a2
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern const u8 sPmsiKanaKeys[];
u16 PMSI_SEARCH_GetKeyChar(u32 i) { return *(const u16 *)(sPmsiKanaKeys+i*10); }

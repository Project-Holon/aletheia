/*
 * function: PMSI_SEARCH_GetKeyRight
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
int PMSI_SEARCH_GetKeyRight(int n) {return *(const u8 *)((unsigned)d_021C37AF+n*10);}

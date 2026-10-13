/*
 * function: PMSI_SEARCH_GetResultWordId
 * address: 0x021BB1E4
 * packet: pkt_ov110_021BB1E4
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:

 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
u16 PMSI_SEARCH_GetResultWordId(u32 p,u32 i) { return *(u16 *)(p+i*2+0x8bc); }

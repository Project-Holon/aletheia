/*
 * function: BEACON_DETAIL_GRA_GetClactUnit
 * address: 0x021BCA38
 * packet: pkt_ov216_021BCA38
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BEACON_DETAIL_GRA_ReadPtr 0x021BCBA0 thumb ov216
 */
typedef unsigned int   u32;
extern u32 BEACON_DETAIL_GRA_ReadPtr(u32 *p);
void *BEACON_DETAIL_GRA_GetClactUnit(char *p){return (void *)BEACON_DETAIL_GRA_ReadPtr((u32 *)(p+4));}

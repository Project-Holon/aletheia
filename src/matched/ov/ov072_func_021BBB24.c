/*
 * function: TOWNMAP_GRH_LoadTownInfo
 * address: 0x021BBB24
 * packet: pkt_ov072_021BBB24
 * region: ov072
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ARC_UTIL_LoadMember 0x0204A1BC arm
 */
extern int ARC_UTIL_LoadMember(int,int,int,int);
int TOWNMAP_GRH_LoadTownInfo(int a) { return ARC_UTIL_LoadMember(0x56,0,0,a); }

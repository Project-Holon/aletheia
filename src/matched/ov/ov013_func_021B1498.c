/*
 * function: VCT_AUDIO_GetPendingCount
 * address: 0x021B1498
 * packet: pkt_ov013_021B1498
 * region: ov013
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT
 * symbols:
 *   gVctPendingCount 0x021B4BA0 data a4
 */
extern int gVctPendingCount[];
int VCT_AUDIO_GetPendingCount(unsigned int i) { return gVctPendingCount[i]; }

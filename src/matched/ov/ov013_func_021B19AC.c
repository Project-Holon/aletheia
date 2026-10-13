/*
 * function: VCT_AUDIO_GetReadyCount
 * address: 0x021B19AC
 * packet: pkt_ov013_021B19AC
 * region: ov013
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT
 * symbols:
 *   gVctReadyCount 0x021B4BB8 data a4
 */
extern int gVctReadyCount[];
int VCT_AUDIO_GetReadyCount(unsigned int i) { return gVctReadyCount[i]; }

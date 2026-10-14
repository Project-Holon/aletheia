/*
 * function: DENDOU_VIEW_GetVramBanks
 * address: 0x021DC924
 * packet: pkt_ov171_021DC924
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   sVramBanks 0x021DEB20 data a4
 */
extern char sVramBanks[];
void *DENDOU_VIEW_GetVramBanks(void){return sVramBanks;}

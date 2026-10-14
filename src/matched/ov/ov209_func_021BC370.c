/*
 * function: ZUKAN_LIST_SetVramBanks
 * address: 0x021BC370
 * packet: pkt_ov209_021BC370
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   d_021BE7D4 0x021BE7D4 data a4
 */
struct DispVram;extern void BG_SYS_SetVramBanks(const struct DispVram *);extern const struct DispVram d_021BE7D4;
void ZUKAN_LIST_SetVramBanks(void){BG_SYS_SetVramBanks(&d_021BE7D4);}

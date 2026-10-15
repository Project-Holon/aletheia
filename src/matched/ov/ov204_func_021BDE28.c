/*
 * function: INTRO_GRAPHIC_UpdateBg
 * address: 0x021BDE28
 * packet: pkt_ov204_021BDE28
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BG_SYS_Update 0x020419E4 arm
 */
extern void BG_SYS_Update(void);
void INTRO_GRAPHIC_UpdateBg(void *a0) { BG_SYS_Update(); }

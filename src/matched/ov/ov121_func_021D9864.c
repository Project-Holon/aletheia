/*
 * function: MYSTERY_GRAPHIC_UpdateBg
 * address: 0x021D9864
 * packet: pkt_ov121_021D9864
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BG_SYS_Update 0x020419E4 arm
 */
extern void BG_SYS_Update(void);
void MYSTERY_GRAPHIC_UpdateBg(void *a0) { BG_SYS_Update(); }

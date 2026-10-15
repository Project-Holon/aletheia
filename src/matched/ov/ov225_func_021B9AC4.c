/*
 * function: MANUAL_GRAPHIC_VBlankBg
 * address: 0x021B9AC4
 * packet: pkt_ov225_021B9AC4
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 *
 * symbols:
 *   BG_SYS_Update  0x020419E4  arm  arm9
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void BG_SYS_Update(void);
void MANUAL_GRAPHIC_VBlankBg(void *a0) { BG_SYS_Update(); }

/*
 * function: BR_GRAPHIC_VBlankBg
 * address: 0x021FC598
 * packet: pkt_ov186_021FC598
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BG_SYS_Update 0x020419E4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void BG_SYS_Update(void);
void BR_GRAPHIC_VBlankBg(void *a0){BG_SYS_Update();}

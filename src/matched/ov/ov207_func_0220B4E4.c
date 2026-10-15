/*
 * function: ZUKAN_TOROKU_GRAPHIC_ResetDisplay
 * address: 0x0220B4E4
 * packet: pkt_ov207_0220B4E4
 * region: ov207
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
void ZUKAN_TOROKU_GRAPHIC_ResetDisplay(void*p){BG_SYS_Update();}

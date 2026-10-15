/*
 * function: NAMEIN_GRAPHIC_ResetBg
 * address: 0x021F4CA8
 * packet: pkt_ov194_021F4CA8
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 *
 * symbols:
 *   BG_SYS_Update  0x020419E4  arm  arm9
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void BG_SYS_Update(void);
void NAMEIN_GRAPHIC_ResetBg(u8 *a0) { BG_SYS_Update(); }

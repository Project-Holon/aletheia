/*
 * function: WF2DMAP_TOUCH_DrawItemHighlight
 * address: 0x021CA25C
 * packet: pkt_ov128_021CA25C
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BG_SYS_FillTileMap 0x020413B0 arm
 *   func_02041B6C 0x02041B6C arm
 */
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
extern void BG_SYS_FillTileMap(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_02041B6C(u32 bit);
void WF2DMAP_TOUCH_DrawItemHighlight(u32 a,u32 b) {BG_SYS_FillTileMap(2,(a>>2)*14+2,(a&3)*4+4,14,4,b);func_02041B6C(2);}

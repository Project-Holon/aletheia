/*
 * function: IRC_RANKING_WriteRowScreen
 * address: 0x021B8B5C
 * packet: pkt_ov106_021B8B5C
 * region: ov106
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BG_SYS_DrawTile 0x02041090 arm
 *   BG_SYS_FillTileMap 0x020413B0 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void BG_SYS_DrawTile(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u8 a5);
extern void BG_SYS_FillTileMap(u32,u8,u8,u8,u8,u8);
void IRC_RANKING_WriteRowScreen(u8 *p, u32 a, int b, u8 c) {
    if(a>=4) p+=192;
    BG_SYS_DrawTile(a,(u32)p,0,(u8)b,32,3);
    BG_SYS_FillTileMap(a,0,b,32,3,c);
}

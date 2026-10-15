/*
 * function: B_PLIST_MAIN_RedrawByMode
 * address: 0x0221025C
 * packet: pkt_ov198_0221025C
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   B_PLIST_DRAW_LayoutActors 0x0220EA68 thumb ov198
 *   B_PLIST_DRAW_DrawModePage 0x0220BE2C thumb ov198
 *   B_PLIST_ANM_UpdateByMode 0x0220B848 thumb ov198
 *   B_PLIST_MAIN_DrawExpBar 0x02210BFC thumb ov198
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void B_PLIST_DRAW_LayoutActors(char *,u32),B_PLIST_ANM_UpdateByMode(u8 *,u32),B_PLIST_MAIN_DrawExpBar(u8 *,int);
extern int B_PLIST_DRAW_DrawModePage(char *,int);
int B_PLIST_MAIN_RedrawByMode(u8 *p) { B_PLIST_DRAW_LayoutActors((char *)p,p[0x2180]);B_PLIST_DRAW_DrawModePage((char *)p,p[0x2180]);B_PLIST_ANM_UpdateByMode(p,p[0x2180]);B_PLIST_MAIN_DrawExpBar(p,p[0x2180]);if(p[0x2180]==2)return 5;return 6; }

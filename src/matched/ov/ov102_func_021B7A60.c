/*
 * unit: yes
 * function: IRC_COMPATIBLE_MENU_ExitBackgrounds, IRC_COMPATIBLE_MENU_BackgroundVBlank
 * address: 0x021B7A60
 * packet: pkt_ov102_021B7A60
 * region: ov102
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: Packed word supplies low/high halfwords, not duplicate low halves. Includes tail-call follower 021B7AAC.
 * symbols:
 * func_02030EAC 0x02030EAC arm
 * BG_SYS_FreeTileRun 0x0203FB44 arm
 * BG_SYS_FreeTiles 0x02040DA8 arm
 * BG_SYS_FreeLayerBuf 0x020403F4 arm
 * BMP_WIN_Exit 0x020450C8 arm
 * BG_SYS_Delete 0x0203F9B4 arm
 * BG_SYS_Update 0x020419E4 arm
 * IRC_COMPATIBLE_MENU_BgLayerIds 0x021B8AEC data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
struct Node;
extern void func_02030EAC(struct Node *n);
typedef unsigned int   u32;
extern void BG_SYS_FreeTileRun(u32 layer, u32 offset, u32 size);
extern void BG_SYS_FreeTiles(unsigned,unsigned,unsigned);
extern void BG_SYS_FreeLayerBuf(u32 i);
extern void BMP_WIN_Exit(void);
extern void BG_SYS_Delete(void);
extern void BG_SYS_Update(void);
extern unsigned IRC_COMPATIBLE_MENU_BgLayerIds[];
void IRC_COMPATIBLE_MENU_ExitBackgrounds(unsigned *p) {
 int i;
 unsigned q;
 func_02030EAC((struct Node *)p[1]);
 q=p[0];
 BG_SYS_FreeTileRun(5,(u16)q,(u16)(q>>16));
 BG_SYS_FreeTiles(5,1,0);
 for(i=0;i<8;i++) BG_SYS_FreeLayerBuf((u8)IRC_COMPATIBLE_MENU_BgLayerIds[i]);
 BMP_WIN_Exit();
 BG_SYS_Delete();
}
void IRC_COMPATIBLE_MENU_BackgroundVBlank(void) { BG_SYS_Update(); }

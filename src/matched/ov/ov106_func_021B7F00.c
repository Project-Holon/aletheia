/*
 * function: IRC_RANKING_GfxExit
 * address: 0x021B7F00
 * packet: pkt_ov106_021B7F00
 * region: ov106
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gIrcRankingBgEntries 0x021B9524 data a4
 *   BMP_WIN_Delete 0x020452E8 arm
 *   BG_SYS_FreeTileRun 0x0203FB44 arm
 *   BG_SYS_FreeTiles 0x02040DA8 arm
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   MI_CpuFill8 0x02082BCC arm
 */

#include "../include/G_BgEntry.h"

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
extern struct BgEntry gIrcRankingBgEntries[];
struct Descriptor;
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void BG_SYS_FreeTileRun(u32 layer, u32 offset, u32 size);
extern void BG_SYS_FreeTiles(u32 idx, u32 count, u32 tile);
extern void BG_SYS_FreeLayerBuf(u32 i);
extern void BMP_WIN_Exit(void);
extern void BG_SYS_Delete(void);
extern void MI_CpuFill8(void *,int,int);
void IRC_RANKING_GfxExit(u32 *p) {
    int i;
    BMP_WIN_Delete((struct Descriptor *)p[3]);
    BG_SYS_FreeTileRun((int)1,(u16)p[1],(u16)(p[1]>>16));
    BG_SYS_FreeTileRun((int)5,(u16)p[2],(u16)(p[2]>>16));
    BG_SYS_FreeTiles(5,1,0);
    BG_SYS_FreeTiles(1,1,0);
    for(i=0;i<8;i++)BG_SYS_FreeLayerBuf((u8)gIrcRankingBgEntries[i].bg);
    BMP_WIN_Exit();BG_SYS_Delete();
    MI_CpuFill8(p,0,16);
}

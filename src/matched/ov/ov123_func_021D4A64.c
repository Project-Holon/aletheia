/*
 * function: GSYNC_MENU_FreeResources
 * address: 0x021D4A64
 * packet: pkt_ov123_021D4A64
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   GSYNC_MENU_DeleteButtonWindows 0x021D4730 thumb ov123
 *   BG_SYS_SetTileUnit 0x02040DA8 arm
 *   BG_SYS_DeleteHalf 0x0203FB44 arm
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 *   STRBUF_Delete 0x02045808 arm
 */
#include "../include/Obj01543.h"
typedef unsigned short u16;
typedef unsigned int u32;
extern void GF_FONT_SetDefaultTextColor(void);
extern void GSYNC_MENU_DeleteButtonWindows(char *);
struct Rec;
struct U16Vec;
extern void BG_SYS_SetTileUnit(u32 idx, u32 count, u32 tile);
extern void BG_SYS_DeleteHalf(u32 layer, u32 offset, u32 size);
extern void BG_SYS_FreeLayerBuf(u32 i);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern u32 GF_FONT_Delete(void *ptr);
extern void STRBUF_Delete(struct U16Vec *vec);
void GSYNC_MENU_FreeResources(char *p)
{
    GF_FONT_SetDefaultTextColor();
    GSYNC_MENU_DeleteButtonWindows(p);
    BG_SYS_SetTileUnit(5, 1, 0);
    BG_SYS_DeleteHalf((int)5, (u16)(((struct Obj01543 *)p)->f3C), (u16)(((struct Obj01543 *)p)->f3C >> 16));
    BG_SYS_FreeLayerBuf(5);
    BG_SYS_FreeLayerBuf(4);
    MSGDATA_Delete(((struct Obj01543 *)p)->f24);
    MSGDATA_Delete(((struct Obj01543 *)p)->f28);
    GF_FONT_Delete(((struct Obj01543 *)p)->f30);
    STRBUF_Delete(((struct Obj01543 *)p)->f38);
}

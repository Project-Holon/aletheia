/*
 * function: MB_COMM_SYS_LoadGraphics
 * address: 0x021EF0F4
 * packet: pkt_ov107_021EF0F4
 * region: ov107
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: 0204B294 own legacy void corrected to live pointer return proved by its 0204CFDC forwarding target; owner sources untouched.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   ARC_UTIL_UploadPaletteFromHandle 0x02049BDC arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_02040588 0x02040588 arm
 *   BG_SYS_FillTileMap 0x020413B0 arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   APP_ICON_GetArchiveId 0x020275E4 thumb
 *   APP_ICON_GetMoveKindPaletteFileId 0x02027614 thumb
 *   APP_ICON_GetMoveKindAnimFileId 0x02027618 thumb
 *   APP_ICON_GetStatusCellFileId 0x0202761C thumb
 *   APP_ICON_GetStatusPaletteFileId 0x02027620 thumb
 *   APP_ICON_GetStatusAnimFileId 0x02027624 thumb
 *   APP_ICON_GetStatusFrameFileId 0x02027628 thumb
 *   APP_ICON_GetStatusDataFileId 0x0202762C thumb
 */
#include "../include/Obj00057.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj;
struct Placement { u16 x,y,z;u8 f6,f7; };
extern void *func_020490F4(u32 id, u32 heap);
typedef signed int     s32;
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void ARC_UTIL_UploadPaletteFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern void BG_SYS_PushTile(u32);
extern void ARC_TOOL_DeleteHandle(void *);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void BG_SYS_FillTileMap(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern struct Obj *CLACT_CreateActor(void *owner,unsigned int i,unsigned int j,unsigned int k,const void *position,unsigned short space,unsigned short heap);
extern void CLACT_SetActorDrawEnable(struct Obj *,u32);
extern u32 APP_ICON_GetArchiveId(void),APP_ICON_GetMoveKindPaletteFileId(void),APP_ICON_GetMoveKindAnimFileId(void),APP_ICON_GetStatusAnimFileId(void),APP_ICON_GetStatusFrameFileId(void),APP_ICON_GetStatusDataFileId(void),APP_ICON_GetStatusCellFileId(u32),APP_ICON_GetStatusPaletteFileId(u32);
void MB_COMM_SYS_LoadGraphics(u8 *p) {
 void *archive;
 u32 first;
 struct Placement placement;
 if(!p[0x28]) {
 archive=func_020490F4(139,((struct Obj00057 *)p)->f0);
 func_02049B68((void *)((u32)archive),1,4,0,0,((struct Obj00057 *)p)->f0);
 func_02049658((void *)((u32)archive),5,7,0,0,0,((struct Obj00057 *)p)->f0);func_020498F4((void *)((u32)archive),9,7,0,0,0,((struct Obj00057 *)p)->f0);
 func_02049B68((void *)((u32)archive),0,0,0,0,((struct Obj00057 *)p)->f0);
 func_02049658((void *)((u32)archive),4,3,0,0,0,((struct Obj00057 *)p)->f0);func_020498F4((void *)((u32)archive),8,3,0,0,0,((struct Obj00057 *)p)->f0);
 ARC_UTIL_UploadPaletteFromHandle((void *)((u32)archive),2,0,288,288,128,((struct Obj00057 *)p)->f0);
 func_02049658((void *)((u32)archive),6,2,0,0,0,((struct Obj00057 *)p)->f0);func_020498F4((void *)((u32)archive),10,2,0,0,0,((struct Obj00057 *)p)->f0);
 ARC_UTIL_UploadPaletteFromHandle((void *)((u32)archive),3,0,416,416,32,((struct Obj00057 *)p)->f0);
 func_02049658((void *)((u32)archive),7,0,0,0,0,((struct Obj00057 *)p)->f0);func_020498F4((void *)((u32)archive),11,0,0,0,0,((struct Obj00057 *)p)->f0);
 BG_SYS_PushTile(2);ARC_TOOL_DeleteHandle(archive);
 } else {
 archive=func_020490F4(34,((struct Obj00057 *)p)->f0);
 func_02049B68((void *)((u32)archive),6,4,0,0,((struct Obj00057 *)p)->f0);
 func_02049658((void *)((u32)archive),15,7,0,0,0,((struct Obj00057 *)p)->f0);func_020498F4((void *)((u32)archive),31,7,0,0,0,((struct Obj00057 *)p)->f0);
 func_02049B68((void *)((u32)archive),6,0,0,0,((struct Obj00057 *)p)->f0);
 func_02049658((void *)((u32)archive),15,3,0,0,0,((struct Obj00057 *)p)->f0);func_020498F4((void *)((u32)archive),31,3,0,0,0,((struct Obj00057 *)p)->f0);
 ARC_TOOL_DeleteHandle(archive);
 archive=func_020490F4(139,((struct Obj00057 *)p)->f0);
 ARC_UTIL_UploadPaletteFromHandle((void *)((u32)archive),2,4,288,288,128,((struct Obj00057 *)p)->f0);
 func_02049658((void *)((u32)archive),6,5,0,0,0,((struct Obj00057 *)p)->f0);func_020498F4((void *)((u32)archive),10,5,0,0,0,((struct Obj00057 *)p)->f0);
 ARC_UTIL_UploadPaletteFromHandle((void *)((u32)archive),3,4,416,416,32,((struct Obj00057 *)p)->f0);
 func_02049658((void *)((u32)archive),7,4,0,0,0,((struct Obj00057 *)p)->f0);func_020498F4((void *)((u32)archive),11,4,0,0,0,((struct Obj00057 *)p)->f0);
 BG_SYS_PushTile(5);func_02040588(5,0);func_02040588(4,0);ARC_TOOL_DeleteHandle(archive);
 }
 archive=func_020490F4(APP_ICON_GetArchiveId(),((struct Obj00057 *)p)->f0);
 func_02049B68((void *)((u32)archive),APP_ICON_GetStatusAnimFileId(),4,256,32,((struct Obj00057 *)p)->f0);
 func_02049658((void *)((u32)archive),APP_ICON_GetStatusFrameFileId(),6,0,0,0,((struct Obj00057 *)p)->f0);func_020498F4((void *)((u32)archive),APP_ICON_GetStatusDataFileId(),6,0,0,0,((struct Obj00057 *)p)->f0);
 BG_SYS_FillTileMap(6,0,21,32,3,8);BG_SYS_PushTile(6);
 *(int *)&((struct Obj00057 *)p)->f70=CLACT_RegisterPaletteEx((void *)((u32)archive),APP_ICON_GetMoveKindPaletteFileId(),1,0,0,3,((struct Obj00057 *)p)->f0);
 *(int *)&((struct Obj00057 *)p)->f74=CLACT_RegisterCharacter((void *)((u32)archive),APP_ICON_GetMoveKindAnimFileId(),0,1,((struct Obj00057 *)p)->f0);
 first=APP_ICON_GetStatusCellFileId(2);
 *(int *)&((struct Obj00057 *)p)->f78=CLACT_RegisterCellAnim((void *)((u32)archive),first,APP_ICON_GetStatusPaletteFileId(2),((struct Obj00057 *)p)->f0);
 ARC_TOOL_DeleteHandle(archive);
 placement.x=232;placement.y=168;placement.z=1;placement.f7=0;placement.f6=0;
 *(struct Obj * *)&((struct Obj00057 *)p)->f7C=CLACT_CreateActor((void *)*(u32 *)&((struct Obj00057 *)p)->f6C,((struct Obj00057 *)p)->f74,((struct Obj00057 *)p)->f70,((struct Obj00057 *)p)->f78,&placement,1,((struct Obj00057 *)p)->f0);
 if(!p[0x28]) {CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct Obj00057 *)p)->f7C,1);return;}
 else {CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct Obj00057 *)p)->f7C,0);return;}
}

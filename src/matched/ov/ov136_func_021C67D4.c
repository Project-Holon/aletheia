/*
 * function: MB_SEQ_RegisterMailActorResources
 * address: 0x021C67D4
 * packet: pkt_ov136_021C67D4
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 021C6882 halfword is alignment padding.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   APP_ICON_GetMoveKindAnimFileId 0x02027618 thumb
 *   APP_ICON_GetMoveKindPaletteFileId 0x02027614 thumb
 *   APP_ICON_GetStatusCellFileId 0x0202761C thumb
 *   APP_ICON_GetStatusPaletteFileId 0x02027620 thumb
 *   APP_ICON_GetArchiveId  0x020275E4  thumb  arm9
 */
#include "../include/Obj05422.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned short u16;
extern u32 APP_ICON_GetArchiveId(void);
extern void *func_020490F4(u32 id, u32 heap);
extern int CLACT_RegisterCharacter(void *, u32, u32, u32, u16);
extern int CLACT_RegisterPalette(void *, u32, u32, u32, u16);
extern int CLACT_RegisterCellAnim(void *, u32, u32, u32);
extern void ARC_TOOL_DeleteHandle(void *);
extern u32 APP_ICON_GetMoveKindAnimFileId(void);
extern u32 APP_ICON_GetMoveKindPaletteFileId(void);
extern u32 APP_ICON_GetStatusCellFileId(u32);
extern u32 APP_ICON_GetStatusPaletteFileId(u32);
void MB_SEQ_RegisterMailActorResources(u8 *p)
{
    void *arc;
    u32 first;
    arc = func_020490F4(155, 102);
    ((struct Obj05422 *)p)->f21C = CLACT_RegisterCharacter(arc, 44, 1, 0, 102);
    ((struct Obj05422 *)p)->f234 = CLACT_RegisterPalette(arc, 47, 0, 0, 102);
    ((struct Obj05422 *)p)->f254 = CLACT_RegisterCellAnim(arc, 45, 46, 102);
    ARC_TOOL_DeleteHandle(arc);
    arc = func_020490F4(APP_ICON_GetArchiveId(), 102);
    ((struct Obj05422 *)p)->f220 = CLACT_RegisterCharacter(arc, APP_ICON_GetMoveKindAnimFileId(), 0, 0, 102);
    ((struct Obj05422 *)p)->f238 = CLACT_RegisterPalette(arc, APP_ICON_GetMoveKindPaletteFileId(), 0, 128, 102);
    first = APP_ICON_GetStatusCellFileId(0);
    ((struct Obj05422 *)p)->f258 = CLACT_RegisterCellAnim(arc, first, APP_ICON_GetStatusPaletteFileId(0), 102);
    ARC_TOOL_DeleteHandle(arc);
}

/*
 * function: MB_SEQ_RegisterSystemActorResources
 * address: 0x021C675C
 * packet: pkt_ov136_021C675C
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   APP_ICON_GetItemPaletteFileId 0x02027698 thumb
 *   APP_ICON_GetItemAnimFileId 0x0202769C thumb
 *   APP_ICON_GetItemFrameFileId 0x020276A0 thumb
 *   POKE_TOOL_GetIconPaletteArcId 0x0201BC3C thumb
 *   APP_ICON_GetArchiveId  0x020275E4  thumb  arm9
 */
#include "../include/Obj14192.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned short u16;
extern u32 APP_ICON_GetArchiveId(void);
extern void *func_020490F4(u32 id, u32 heap);
extern u32 APP_ICON_GetItemPaletteFileId(void);
extern int CLACT_RegisterCharacter(void *, u32, u32, u32, u16);
extern int POKE_TOOL_GetIconPaletteArcId(void);
extern int CLACT_RegisterPalette(void *, u32, u32, u32, u16);
extern u32 APP_ICON_GetItemAnimFileId(u32);
extern u32 APP_ICON_GetItemFrameFileId(u32);
extern int CLACT_RegisterCellAnim(void *, u32, u32, u32);
extern void ARC_TOOL_DeleteHandle(void *);
void MB_SEQ_RegisterSystemActorResources(u8 *p)
{
    void *arc;
    u32 i;
    u32 first;
    arc = func_020490F4(APP_ICON_GetArchiveId(), 102);
    for (i = 0; i <= 2; i++)
        *(u32 *)(p + 0x210 + i * 4) = CLACT_RegisterCharacter(arc, APP_ICON_GetItemPaletteFileId(), 0, 1, 102);
    ((struct Obj14192 *)p)->f230 = CLACT_RegisterPalette(arc, POKE_TOOL_GetIconPaletteArcId(), 1, 0, 102);
    first = APP_ICON_GetItemAnimFileId(0);
    ((struct Obj14192 *)p)->f250 = CLACT_RegisterCellAnim(arc, first, APP_ICON_GetItemFrameFileId(0), 102);
    ARC_TOOL_DeleteHandle(arc);
}

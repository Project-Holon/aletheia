/*
 * function: DENDOU_VIEW_LoadButtonResources
 * address: 0x021DE144
 * packet: pkt_ov171_021DE144
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   APP_ICON_GetArchiveId 0x020275E4 thumb
 *   APP_ICON_GetMoveKindAnimFileId 0x02027618 thumb
 *   APP_ICON_GetMoveKindPaletteFileId 0x02027614 thumb
 *   APP_ICON_GetStatusCellFileId 0x0202761C thumb
 *   APP_ICON_GetStatusPaletteFileId 0x02027620 thumb
 *   func_020490F4 0x020490F4 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 */
#include "../include/Obj01756.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed int     s32;
typedef unsigned int   u32;
extern u32 APP_ICON_GetArchiveId(void);
extern u32 APP_ICON_GetMoveKindAnimFileId(void);
extern u32 APP_ICON_GetMoveKindPaletteFileId(void);
extern u32 APP_ICON_GetStatusCellFileId(u32 a);
extern u32 APP_ICON_GetStatusPaletteFileId(u32 a);
extern void *func_020490F4(u32 id, u32 heap);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterPalette(void *a, u32 b, u32 c, u32 d, u16 g);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void ARC_TOOL_DeleteHandle(u8 *);
void DENDOU_VIEW_LoadButtonResources(char *p)
{
    unsigned i;
    u8 *s;
    int a;
    for (i = 0; i < 13; ++i)
        *(int *)(p + 0xbb4 + i * 4) = -1;
    for (i = 0; i < 13; ++i)
        *(int *)(p + 0xbe8 + i * 4) = -1;
    for (i = 0; i < 13; ++i)
        *(int *)(p + 0xc1c + i * 4) = -1;
    s = func_020490F4(APP_ICON_GetArchiveId(), 0x808c);
    ((struct Obj01756 *)p)->fBE4 = CLACT_RegisterCharacter(s, APP_ICON_GetMoveKindAnimFileId(), 0, 0, 0x8c);
    *(int *)&((struct Obj01756 *)p)->fC18 = CLACT_RegisterPalette(s, APP_ICON_GetMoveKindPaletteFileId(), 0, 0x180, 0x8c);
    a = APP_ICON_GetStatusCellFileId(2);
    ((struct Obj01756 *)p)->fC4C = CLACT_RegisterCellAnim(s, a, APP_ICON_GetStatusPaletteFileId(2), 0x8c);
    ARC_TOOL_DeleteHandle(s);
}

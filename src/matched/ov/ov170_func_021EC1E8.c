/*
 * function: BOX2_SEQ_RegisterBoxCharsB
 * address: 0x021EC1E8
 * packet: pkt_ov170_021EC1E8
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   APP_ICON_GetArchiveId 0x020275E4 thumb
 *   func_020490F4 0x020490F4 arm
 *   APP_ICON_GetMoveKindAnimFileId 0x02027618 thumb
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   APP_ICON_GetMoveKindPaletteFileId 0x02027614 thumb
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   APP_ICON_GetStatusCellFileId 0x0202761C thumb
 *   APP_ICON_GetStatusPaletteFileId 0x02027620 thumb
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 */
#include "../include/Obj02214.h"
typedef unsigned short u16;

extern unsigned APP_ICON_GetArchiveId(void);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern unsigned APP_ICON_GetMoveKindAnimFileId(void);
typedef signed int     s32;
extern s32 CLACT_RegisterCharacter(void *a, unsigned int b, unsigned int c, unsigned int a3, u16 flags);
extern unsigned APP_ICON_GetMoveKindPaletteFileId(void);
extern s32 CLACT_RegisterPalette(void *a, unsigned int b, unsigned int c, unsigned int d, u16 g);
typedef unsigned int   u32;
extern u32 APP_ICON_GetStatusCellFileId(u32 a);
extern u32 APP_ICON_GetStatusPaletteFileId(u32 a);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void ARC_TOOL_DeleteHandle(void *);
void BOX2_SEQ_RegisterBoxCharsB(char *p)
{
    void *h = func_020490F4(APP_ICON_GetArchiveId(), 0x4C);
    ((struct Obj02214 *)p)->fA0F8 = (void *)CLACT_RegisterCharacter(h, APP_ICON_GetMoveKindAnimFileId(), 0, 0, 0x4C);
    ((struct Obj02214 *)p)->fA124 = (void *)CLACT_RegisterPalette(h, APP_ICON_GetMoveKindPaletteFileId(), 0, 0x100, 0x4C);
    ((struct Obj02214 *)p)->fA154 = (void *)CLACT_RegisterCellAnim(h, APP_ICON_GetStatusCellFileId(2), APP_ICON_GetStatusPaletteFileId(2), 0x4C);
    ARC_TOOL_DeleteHandle(h);
}

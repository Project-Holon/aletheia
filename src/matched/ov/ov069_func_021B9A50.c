/*
 * function: BSUBWAY_RECORD_LIST_SetupActors
 * address:  0x021B9A50
 * packet:   pkt_ov069_021B9A50
 * region:   ov069
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   APP_ICON_GetArchiveId  0x020275E4  thumb
 *   func_020490F4  0x020490F4  arm
 *   CLACT_InitSystem  0x0204A48C  arm
 *   gClActorInitParam     0x020A1448  data  a4
 *   sRecordListVramBanks     0x021BA620  data  a4
 *   CLACT_CreateUnit  0x0204B100  arm
 *   BG_SYS_SetMainPlaneVisible  0x020434DC  arm
 *   BG_SYS_SetSubPlaneVisible  0x02043598  arm
 *   CLACT_RegisterCharacter  0x0204A6C8  arm
 *   CLACT_RegisterPalette  0x0204ABF0  arm
 *   CLACT_RegisterCellAnim  0x0204AF28  arm
 *   APP_ICON_GetMoveKindAnimFileId  0x02027618  thumb
 *   APP_ICON_GetMoveKindPaletteFileId  0x02027614  thumb
 *   CLACT_RegisterPaletteEx  0x0204AC18  arm
 *   APP_ICON_GetStatusCellFileId  0x0202761C  thumb
 *   APP_ICON_GetStatusPaletteFileId  0x02027620  thumb
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 */
#include "../include/Obj02418.h"

typedef unsigned char u8;
typedef unsigned int  u32;

typedef unsigned short u16;

extern u8 gClActorInitParam[];
extern u8 sRecordListVramBanks[];
extern u32 APP_ICON_GetArchiveId(void);
extern void *func_020490F4(u32 id, u32 heap);
struct Bank;
struct Cfg;
extern void CLACT_InitSystem(const struct Cfg *cfg, u32 arg, u32 heapId);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
typedef signed int     s32;
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterPalette(void *a, u32 b, u32 c, u32 d, u16 g);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern u32 APP_ICON_GetMoveKindPaletteFileId(void);
extern u32 APP_ICON_GetMoveKindAnimFileId(void);
extern u32 APP_ICON_GetStatusCellFileId(u32);
extern u32 APP_ICON_GetStatusPaletteFileId(u32);
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern void ARC_TOOL_DeleteHandle(void *h);

void BSUBWAY_RECORD_LIST_SetupActors(u8 *p)
{
    void *h;
    u32 t;

    h = func_020490F4(APP_ICON_GetArchiveId(), 0x80);
    CLACT_InitSystem((const struct Cfg *)gClActorInitParam, (u32)sRecordListVramBanks, 0x80);
    ((struct Obj02418 *)p)->f11C = (u32)CLACT_CreateUnit(4, 1, 0x80);
    ((struct Obj02418 *)p)->f120 = (u32)CLACT_CreateUnit(2, 1, 0x80);
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
    ((struct Obj02418 *)p)->f138 = CLACT_RegisterCharacter(((struct Obj02418 *)p)->f0, 7, 1, 2, 0x80);
    ((struct Obj02418 *)p)->f134 = CLACT_RegisterPalette(((struct Obj02418 *)p)->f0, 10, 2, 0, 0x80);
    ((struct Obj02418 *)p)->f13C = CLACT_RegisterCellAnim(((struct Obj02418 *)p)->f0, 8, 9, 0x80);
    ((struct Obj02418 *)p)->f144 = CLACT_RegisterCharacter(h, APP_ICON_GetMoveKindAnimFileId(), 0, 0, 0x80);
    ((struct Obj02418 *)p)->f140 = CLACT_RegisterPaletteEx(h, APP_ICON_GetMoveKindPaletteFileId(), 0, 0x160, 0, 3, 0x80);
    t = APP_ICON_GetStatusCellFileId(0);
    ((struct Obj02418 *)p)->f148 = CLACT_RegisterCellAnim(h, t, APP_ICON_GetStatusPaletteFileId(0), 0x80);
    ARC_TOOL_DeleteHandle(h);
}

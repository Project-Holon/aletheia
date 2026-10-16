/*
 * function: POKELIST_LoadGraphics
 * address:  0x021B7298
 * packet:   pkt_ov091_021B7298
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Graphics setup: loads BG/char/screen/palette data from archive 0x4c, the
 * 0x07 archive and the APP_ICON_GetArchiveId archive into p's handle table
 * (p+0x178..0x1d0), then copies palette RAM 0x050000C0 back to p+0x40.
 * The second-archive loads still pass the first (closed) handle to
 * func_02049B68/02049658/020498F4, as the original does.  The 0x158 store
 * goes through a local: stored directly, the allocator rematerialises the
 * shared 0xc0 offset base instead of reloading its [sp+0xc] spill slot.
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   func_02049B68  0x02049B68  arm
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   ARC_UTIL_LoadPaletteDataFromHandle  0x02049EF4  arm
 *   CLACT_RegisterPaletteEx  0x0204AC18  arm
 *   CLACT_RegisterCharacter  0x0204A6C8  arm
 *   CLACT_RegisterCellAnim  0x0204AF28  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   CLACT_RegisterPaletteCompressed  0x0204ACEC  arm
 *   POKE_TOOL_GetIconPaletteArcId  0x0201BC3C  thumb
 *   POKE_TOOL_GetIconCellArcId  0x0201BC40  thumb
 *   POKE_TOOL_GetIconCellEntryId  0x0201BCB4  thumb
 *   APP_ICON_GetArchiveId  0x020275E4  thumb
 *   APP_ICON_GetStatusAnimFileId  0x02027624  thumb
 *   APP_ICON_GetStatusFrameFileId  0x02027628  thumb
 *   APP_ICON_GetStatusExtraFileId  0x02027630  thumb
 *   BG_SYS_FillTileMap  0x020413B0  arm
 *   APP_ICON_GetNoneFileId  0x02027758  thumb
 *   APP_ICON_GetGearCellFileId  0x0202775C  thumb
 *   APP_ICON_GetGearPaletteFileId  0x02027760  thumb
 *   APP_ICON_GetGearAnimFileId  0x02027764  thumb
 *   APP_ICON_GetMoveKindPaletteFileId  0x02027614  thumb
 *   APP_ICON_GetMoveKindAnimFileId  0x02027618  thumb
 *   APP_ICON_GetStatusCellFileId  0x0202761C  thumb
 *   APP_ICON_GetStatusPaletteFileId  0x02027620  thumb
 *   APP_ICON_GetItemCellFileId  0x02027694  thumb
 *   APP_ICON_GetItemPaletteFileId  0x02027698  thumb
 *   APP_ICON_GetItemAnimFileId  0x0202769C  thumb
 *   APP_ICON_GetItemFrameFileId  0x020276A0  thumb
 *   APP_ICON_GetSealCellFileId  0x020276B4  thumb
 *   APP_ICON_GetSealPaletteFileId  0x020276B8  thumb
 *   APP_ICON_GetSealAnimFileId  0x020276BC  thumb
 *   APP_ICON_GetSealFrameFileId  0x020276C0  thumb
 *   MIi_CpuCopy16  0x02082A60  arm
 */
#include "../include/Obj00047.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_020490F4(u32 id, u32 heap);
typedef signed int     s32;
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void *ARC_UTIL_LoadPaletteDataFromHandle(void *h, u32 a1, u32 a2, void **out, u16 heap);
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void ARC_TOOL_DeleteHandle(void *h);
extern int CLACT_RegisterPaletteCompressed(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern int POKE_TOOL_GetIconPaletteArcId(void);
extern int POKE_TOOL_GetIconCellArcId(void);
extern int POKE_TOOL_GetIconCellEntryId(void);
extern u32 APP_ICON_GetArchiveId(void);
extern u32 APP_ICON_GetStatusAnimFileId(void);
extern u32 APP_ICON_GetStatusFrameFileId(void);
extern u32 APP_ICON_GetStatusExtraFileId(void);
extern void BG_SYS_FillTileMap(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern int APP_ICON_GetNoneFileId(void);
extern int APP_ICON_GetGearCellFileId(int a);
extern int APP_ICON_GetGearPaletteFileId(int a);
extern int APP_ICON_GetGearAnimFileId(int a);
extern u32 APP_ICON_GetMoveKindPaletteFileId(void);
extern u32 APP_ICON_GetMoveKindAnimFileId(void);
extern u32 APP_ICON_GetStatusCellFileId(u32 a);
extern u32 APP_ICON_GetStatusPaletteFileId(u32 a);
extern u32 APP_ICON_GetItemCellFileId(void);
extern u32 APP_ICON_GetItemPaletteFileId(void);
extern u32 APP_ICON_GetItemAnimFileId(u32 a);
extern u32 APP_ICON_GetItemFrameFileId(u32 a);
extern u32 APP_ICON_GetSealCellFileId(void);
extern u32 APP_ICON_GetSealPaletteFileId(void);
extern u32 APP_ICON_GetSealAnimFileId(u32 a);
extern u32 APP_ICON_GetSealFrameFileId(u32 a);
extern void MIi_CpuCopy16(void *srcp, void *destp, unsigned long size);

void POKELIST_LoadGraphics(u8 *p)
{
    void *h;
    void *h2;
    void *t;

    h = func_020490F4(0x4c, ((struct Obj00047 *)p)->f0);
    func_02049B68(h, 6, 0, 0, 0, ((struct Obj00047 *)p)->f0);
    func_02049B68(h, 0, 0, 0x1a0, 0x20, ((struct Obj00047 *)p)->f0);
    func_02049658(h, 0xf, 3, 0, 0, 0, ((struct Obj00047 *)p)->f0);
    func_020498F4(h, 0x14, 3, 0, 0, 0, ((struct Obj00047 *)p)->f0);
    func_02049658(h, 0xc, 2, 0, 0, 0, ((struct Obj00047 *)p)->f0);
    t = ARC_UTIL_LoadPaletteDataFromHandle(h, 0x12, 0, (void **)(p + 0x15c), ((struct Obj00047 *)p)->f0);
    ((struct Obj00047 *)p)->f158 = t;
    func_02049B68(h, 5, 4, 0, 0, ((struct Obj00047 *)p)->f0);
    func_02049658(h, 0xe, 7, 0, 0, 0, ((struct Obj00047 *)p)->f0);
    func_020498F4(h, 0x13, 7, 0, 0, 0, ((struct Obj00047 *)p)->f0);
    *(u32 *)&((struct Obj00047 *)p)->f178 = CLACT_RegisterPaletteEx(h, 4, 0, 0, 0, 3, ((struct Obj00047 *)p)->f0);
    *(u32 *)&((struct Obj00047 *)p)->f198 = CLACT_RegisterCharacter(h, 0xb, 0, 0, ((struct Obj00047 *)p)->f0);
    ((struct Obj00047 *)p)->f19C = CLACT_RegisterCharacter(h, 8, 0, 0, ((struct Obj00047 *)p)->f0);
    *(u32 *)&((struct Obj00047 *)p)->f1B4 = CLACT_RegisterCellAnim(h, 0x17, 0x1a, ((struct Obj00047 *)p)->f0);
    ((struct Obj00047 *)p)->f1B8 = CLACT_RegisterCellAnim(h, 0x16, 0x19, ((struct Obj00047 *)p)->f0);
    ARC_TOOL_DeleteHandle(h);

    h2 = func_020490F4(7, ((struct Obj00047 *)p)->f0);
    ((struct Obj00047 *)p)->f190 = CLACT_RegisterPaletteCompressed(h2, POKE_TOOL_GetIconPaletteArcId(), 0, 0xc0, ((struct Obj00047 *)p)->f0);
    ((struct Obj00047 *)p)->f1D0 = CLACT_RegisterCellAnim(h2, POKE_TOOL_GetIconCellArcId(), POKE_TOOL_GetIconCellEntryId(), ((struct Obj00047 *)p)->f0);
    ARC_TOOL_DeleteHandle(h2);

    h2 = func_020490F4(APP_ICON_GetArchiveId(), ((struct Obj00047 *)p)->f0);
    func_02049B68(h, APP_ICON_GetStatusAnimFileId(), 0, 0x160, 0x20, ((struct Obj00047 *)p)->f0);
    func_02049658(h, APP_ICON_GetStatusFrameFileId(), 1, 0, 0, 0, ((struct Obj00047 *)p)->f0);
    func_020498F4(h, APP_ICON_GetStatusExtraFileId(), 1, 0, 0, 0, ((struct Obj00047 *)p)->f0);
    BG_SYS_FillTileMap(1, 0, 0, 0x40, 0x20, 0xb);
    ((struct Obj00047 *)p)->f18C = CLACT_RegisterPaletteEx(h2, APP_ICON_GetNoneFileId(), 0, 0xa0, 0, 1, ((struct Obj00047 *)p)->f0);
    ((struct Obj00047 *)p)->f1B0 = CLACT_RegisterCharacter(h2, APP_ICON_GetGearCellFileId(2), 0, 0, ((struct Obj00047 *)p)->f0);
    ((struct Obj00047 *)p)->f1CC = CLACT_RegisterCellAnim(h2, APP_ICON_GetGearPaletteFileId(2), APP_ICON_GetGearAnimFileId(2), ((struct Obj00047 *)p)->f0);
    *(u32 *)&((struct Obj00047 *)p)->f17C = CLACT_RegisterPaletteEx(h2, APP_ICON_GetMoveKindPaletteFileId(), 0, 0x120, 0, 3, ((struct Obj00047 *)p)->f0);
    *(u32 *)&((struct Obj00047 *)p)->f1A0 = CLACT_RegisterCharacter(h2, APP_ICON_GetMoveKindAnimFileId(), 0, 0, ((struct Obj00047 *)p)->f0);
    *(u32 *)&((struct Obj00047 *)p)->f1BC = CLACT_RegisterCellAnim(h2, APP_ICON_GetStatusCellFileId(2), APP_ICON_GetStatusPaletteFileId(2), ((struct Obj00047 *)p)->f0);
    ((struct Obj00047 *)p)->f180 = CLACT_RegisterPaletteEx(h2, APP_ICON_GetItemCellFileId(), 0, 0x60, 0, 1, ((struct Obj00047 *)p)->f0);
    ((struct Obj00047 *)p)->f1A4 = CLACT_RegisterCharacter(h2, APP_ICON_GetItemPaletteFileId(), 0, 0, ((struct Obj00047 *)p)->f0);
    ((struct Obj00047 *)p)->f1C0 = CLACT_RegisterCellAnim(h2, APP_ICON_GetItemAnimFileId(2), APP_ICON_GetItemFrameFileId(2), ((struct Obj00047 *)p)->f0);
    ((struct Obj00047 *)p)->f188 = CLACT_RegisterPaletteEx(h2, APP_ICON_GetSealCellFileId(), 0, 0x80, 0, 1, ((struct Obj00047 *)p)->f0);
    ((struct Obj00047 *)p)->f1AC = CLACT_RegisterCharacter(h2, APP_ICON_GetSealPaletteFileId(), 0, 0, ((struct Obj00047 *)p)->f0);
    ((struct Obj00047 *)p)->f1C8 = CLACT_RegisterCellAnim(h2, APP_ICON_GetSealAnimFileId(2), APP_ICON_GetSealFrameFileId(2), ((struct Obj00047 *)p)->f0);
    ARC_TOOL_DeleteHandle(h2);
    MIi_CpuCopy16((void *)0x050000C0, p + 0x40, 0x60);
}

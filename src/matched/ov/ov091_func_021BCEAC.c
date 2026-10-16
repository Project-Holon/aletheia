/*
 * function: PLIST_MENU_LoadResources
 * address: 0x021BCEAC
 * packet: pkt_ov091_021BCEAC
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   ARC_UTIL_UploadPaletteFromHandle 0x02049BDC arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   APP_ICON_GetArchiveId 0x020275E4 thumb
 *   APP_ICON_GetItemCellFileId 0x02027694 thumb
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   APP_ICON_GetItemPaletteFileId 0x02027698 thumb
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   APP_ICON_GetItemAnimFileId 0x0202769C thumb
 *   APP_ICON_GetItemFrameFileId 0x020276A0 thumb
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   APP_ICON_GetStatusAnimFileId 0x02027624 thumb
 *   APP_ICON_GetStatusFrameFileId 0x02027628 thumb
 *   APP_ICON_GetStatusDataFileId 0x0202762C thumb
 *   BG_SYS_FillTileMap 0x020413B0 arm
 *   func_02041B6C 0x02041B6C arm
 *   POKE_TOOL_GetIconPaletteArcId 0x0201BC3C thumb
 *   CLACT_RegisterPaletteCompressed 0x0204ACEC arm
 *   MIi_CpuCopy16 0x02082A60 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_020490F4(u32 id, u32 heap);
typedef signed int     s32;
extern void ARC_UTIL_UploadPaletteFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void ARC_TOOL_DeleteHandle(void *);
extern u32 APP_ICON_GetArchiveId(void);
extern u32 APP_ICON_GetItemCellFileId(void);
extern s32 CLACT_RegisterPalette(void *a, u32 b, u32 c, u32 d, u16 g);
extern u32 APP_ICON_GetItemPaletteFileId(void);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern u32 APP_ICON_GetItemAnimFileId(u32);
extern u32 APP_ICON_GetItemFrameFileId(u32);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern u32 APP_ICON_GetStatusAnimFileId(void);
extern u32 APP_ICON_GetStatusFrameFileId(void);
extern u32 APP_ICON_GetStatusDataFileId(void);
extern void BG_SYS_FillTileMap(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_02041B6C(u32);
extern int POKE_TOOL_GetIconPaletteArcId(void);
extern int CLACT_RegisterPaletteCompressed(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void MIi_CpuCopy16(void *, void *, unsigned long);
#define H (*(u16 *)p)
#define W(o) (*(u32 *)(p + (o)))
#define F(o) (*(int *)(W(0x280) + (o)))
void PLIST_MENU_LoadResources(u8 *p)
{
    void *h, *h2;
    h = func_020490F4(0x4c, H);
    ARC_UTIL_UploadPaletteFromHandle((void *)((u32)h), 1, 4, 0x20, 0x20, 0x20, H);
    func_02049B68(h, 0, 4, 0x1a0, 0x20, H);
    func_02049658((void *)((u32)h), 9, 6, 0, 0, 0, H);
    if (F(0x8c) == 1) {
        switch (F(0x64)) {
        case 1: func_020498F4((void *)((u32)h), 0x11, 6, 0, 0, 0, H); break;
        case 2: func_020498F4((void *)((u32)h), 0x10, 6, 0, 0, 0, H); break;
        }
    }
    ARC_TOOL_DeleteHandle(h);
    h2 = func_020490F4(APP_ICON_GetArchiveId(), H);
    W(0x184) = CLACT_RegisterPalette((void *)h, APP_ICON_GetItemCellFileId(), 1, 0x60, H);
    W(0x1a8) = CLACT_RegisterCharacter((void *)((u32)h), APP_ICON_GetItemPaletteFileId(), 0, 1, H);
    W(0x1c4) = CLACT_RegisterCellAnim((void *)((u32)h), APP_ICON_GetItemAnimFileId(2), APP_ICON_GetItemFrameFileId(2), H);
    if (F(0x90) == 1) {
        func_02049B68(h, APP_ICON_GetStatusAnimFileId(), 4, 0x40, 0x20, H);
        func_02049658((void *)((u32)h), APP_ICON_GetStatusFrameFileId(), 5, 0, 0, 0, H);
        func_020498F4((void *)((u32)h), APP_ICON_GetStatusDataFileId(), 5, 0, 0, 0, H);
        BG_SYS_FillTileMap(5, 0, 0, 0x20, 0x20, 2);
        func_02041B6C(5);
    }
    ARC_TOOL_DeleteHandle(h2);
    h = func_020490F4(7, H);
    W(0x194) = CLACT_RegisterPaletteCompressed((void *)((u32)h), POKE_TOOL_GetIconPaletteArcId(), 1, 0xc0, H);
    ARC_TOOL_DeleteHandle(h);
    MIi_CpuCopy16((void *)0x05000440, p + 0x20e, 0x20);
}

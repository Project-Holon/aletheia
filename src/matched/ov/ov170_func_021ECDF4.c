/*
 * function: BOX2_SEQ_LoadBoxScreen
 * address:  0x021ECDF4
 * packet:   pkt_ov170_021ECDF4
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   APP_ICON_GetArchiveId 0x020275E4 thumb
 *   func_020490F4 0x020490F4 arm
 *   APP_ICON_GetTypeCellFileId 0x020275F8 thumb
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   APP_ICON_GetTypePaletteFileId 0x020275FC thumb
 *   APP_ICON_GetTypeAnimFileId 0x02027600 thumb
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   APP_ICON_GetTouchBarFileId 0x020275E8 thumb
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   APP_ICON_GetEffectCellFileId 0x0202774C thumb
 *   APP_ICON_GetEffectPaletteFileId 0x02027750 thumb
 *   APP_ICON_GetEffectAnimFileId 0x02027754 thumb
 *   APP_ICON_GetBallOpenAnimFileId 0x02027748 thumb
 *   APP_ICON_GetGearExtraFileId 0x0202776C thumb
 *   APP_ICON_GetGearFrameFileId 0x02027770 thumb
 *   APP_ICON_GetGearAnim2FileId 0x02027774 thumb
 *   APP_ICON_GetGearDataFileId 0x02027768 thumb
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *
 * Loads the box screen graphics from the shared archive into the work
 * slots at 0xA094 (seventeen palettes) and 0xA0FC..0xA160 (character,
 * cell and animation resources), then closes the archive.
 */

typedef unsigned short u16;

extern unsigned APP_ICON_GetArchiveId(void);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern unsigned int APP_ICON_GetTypeCellFileId(unsigned int a);
extern signed int CLACT_RegisterCharacter(void *a, unsigned int b, unsigned int c, unsigned int a3, u16 flags);
typedef unsigned int   u32;
extern u32 APP_ICON_GetTypePaletteFileId(u32 a);
extern u32 APP_ICON_GetTypeAnimFileId(u32 a);
extern signed int CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern unsigned APP_ICON_GetTouchBarFileId(void);
typedef signed int     s32;
extern s32 CLACT_RegisterPalette(void *a, u32 b, u32 c, u32 d, u16 g);
extern int APP_ICON_GetEffectCellFileId(int a);
extern int APP_ICON_GetEffectPaletteFileId(int a);
extern int APP_ICON_GetEffectAnimFileId(int a);
extern int APP_ICON_GetBallOpenAnimFileId(void);
extern int APP_ICON_GetGearExtraFileId(int a);
extern int APP_ICON_GetGearFrameFileId(int a);
extern int APP_ICON_GetGearAnim2FileId(int a);
extern int APP_ICON_GetGearDataFileId(void);
extern void ARC_TOOL_DeleteHandle(void *h);

#define SLOT(w, o) (*(void **)((w) + (o)))

void BOX2_SEQ_LoadBoxScreen(char *w)
{
    void *h;
    unsigned i;

    h = func_020490F4(APP_ICON_GetArchiveId(), 0x804C);
    for (i = 0; i < 0x11; i++)
        *(void **)(w + i * 4 + 0xA094) = (void *)CLACT_RegisterCharacter(h, APP_ICON_GetTypeCellFileId((unsigned char)i), (int)0, (int)1, (unsigned)0x4C);
    SLOT(w, 0xA144) = (void *)CLACT_RegisterCellAnim(h, APP_ICON_GetTypePaletteFileId(2), APP_ICON_GetTypeAnimFileId(2), 0x4C);
    SLOT(w, 0xA118) = (void *)CLACT_RegisterPalette(h, APP_ICON_GetTouchBarFileId(), 1, 0, 0x4C);
    SLOT(w, 0xA100) = (void *)CLACT_RegisterCharacter(h, APP_ICON_GetEffectCellFileId(2), (int)0, (int)1, (unsigned)0x4C);
    SLOT(w, 0xA15C) = (void *)CLACT_RegisterCellAnim(h, APP_ICON_GetEffectPaletteFileId(2), APP_ICON_GetEffectAnimFileId(2), 0x4C);
    SLOT(w, 0xA12C) = (void *)CLACT_RegisterPalette(h, APP_ICON_GetBallOpenAnimFileId(), 1, 0xA0, 0x4C);
    SLOT(w, 0xA104) = (void *)CLACT_RegisterCharacter(h, APP_ICON_GetGearExtraFileId(2), (int)0, (int)1, (unsigned)0x4C);
    SLOT(w, 0xA160) = (void *)CLACT_RegisterCellAnim(h, APP_ICON_GetGearFrameFileId(2), APP_ICON_GetGearAnim2FileId(2), 0x4C);
    SLOT(w, 0xA130) = (void *)CLACT_RegisterPalette(h, APP_ICON_GetGearDataFileId(), 1, 0xC0, 0x4C);
    SLOT(w, 0xA0FC) = (void *)CLACT_RegisterCharacter(h, APP_ICON_GetEffectCellFileId(2), (int)0, (int)0, (unsigned)0x4C);
    SLOT(w, 0xA158) = (void *)CLACT_RegisterCellAnim(h, APP_ICON_GetEffectPaletteFileId(2), APP_ICON_GetEffectAnimFileId(2), 0x4C);
    SLOT(w, 0xA128) = (void *)CLACT_RegisterPalette(h, APP_ICON_GetBallOpenAnimFileId(), 0, 0x1A0, 0x4C);
    ARC_TOOL_DeleteHandle(h);
}

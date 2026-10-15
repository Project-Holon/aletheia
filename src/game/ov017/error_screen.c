/*
 * file:     error_screen.c
 * unit:     yes
 * function: ERROR_SCREEN_ShowAndWait, ERROR_SCREEN_Setup, ERROR_SCREEN_LoadBackground, ERROR_SCREEN_PrintMessage, ERROR_SCREEN_Teardown
 * address:  0x021B6100
 * region:   ov017
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0202EB0C  0x0202EB0C  thumb
 *   GFL_USE_PollPowerExit  0x020053EC  thumb
 *   func_02034F5C  0x02034F5C  arm
 *   GXx_SetMasterBrightness_  0x0207D534  arm
 *   func_020808F4  0x020808F4  arm
 *   func_020809A0  0x020809A0  arm
 *   func_0207FDCC  0x0207FDCC  arm
 *   GX_SetGraphicsMode  0x0207D4B0  arm
 *   G2_GetBG1CharPtr  0x0207E24C  arm
 *   func_02082A7C  0x02082A7C  arm
 *   ARC_UTIL_LoadMember  0x0204A1BC  arm
 *   func_02062A4C  0x02062A4C  arm
 *   DWCi_ScreenDC_FlushRange  0x020862F0  arm
 *   MIi_CpuCopy16  0x02082A60  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02062B30  0x02062B30  arm
 *   G2_GetBG1ScrPtr  0x0207DFB4  arm
 *   func_02062AD4  0x02062AD4  arm
 *   func_02062A98  0x02062A98  arm
 *   MIi_CpuClear16  0x02082A48  arm
 *   BMP_CreateFromVram  0x02043754  arm
 *   GF_FONT_Create  0x0201D7EC  thumb
 *   func_02045B38  0x02045B38  arm
 *   func_02045EC0  0x02045EC0  arm
 *   PRINTSYS_PrintColor  0x0201C7D0  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   GF_FONT_Delete  0x0201D83C  thumb
 *   BMP_Delete  0x020437AC  arm
 *   BG_SYS_SetSubVisiblePlanes  0x020435F4  arm
 */
#define REG_BG1CNT_MAIN    (*(volatile u16 *)0x0400000A)
#define REG_BG1HOFS_MAIN   (*(volatile u32 *)0x04000014)
#define REG_BLDCNT_MAIN    (*(volatile u16 *)0x04000050)
#define REG_MASTER_BRIGHT_MAIN ((volatile u16 *)0x0400006C)
#define REG_MASTER_BRIGHT_SUB  ((volatile u16 *)0x0400106C)
#define REG_KEYINPUT       (*(volatile u16 *)0x04000130)
#define REG_EXT_KEYINPUT   (*(volatile u16 *)0x02FFFFA8)
#define PLTT_MAIN_BG       0x05000000
#define REG_DISPCNT_MAIN       (*(volatile u32 *)0x04000000)
struct NitroFileHeader;
struct Bmp;
struct GfFont;
struct MsgBank;
struct Strbuf;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef signed int     s32;

typedef signed short   s16;

/* Character data block of a packed graphics file. */
typedef struct CharData {
    u8 pad00[0x10];
    u32 sizeBytes;
    void *pixels;
} CharData;

/* Screen (tile map) data block of a packed graphics file. */
typedef struct ScreenData {
    u8 pad00[0x8];
    u32 sizeBytes;
    u8 tiles[1];
} ScreenData;

/* Palette data block of a packed graphics file. */
typedef struct PaletteData {
    u8 pad00[0xc];
    void *colors;
} PaletteData;

extern u32 func_0202EB0C(void);
extern void GFL_USE_PollPowerExit(void);
extern void func_02034F5C(void);
extern void GXx_SetMasterBrightness_(volatile u16 *reg, int brightness);
extern int func_020808F4(void);
extern int func_020809A0(void);
extern void func_0207FDCC(int mode);
extern void GX_SetGraphicsMode(int layer, int x, int y);
extern void *G2_GetBG1CharPtr(void);
extern void func_02082A7C(u32 value, void *dst, u32 size);
extern int ARC_UTIL_LoadMember(int arcId, int fileId, int resident, int heapId);
extern signed int func_02062A4C(struct NitroFileHeader *file, void **out);
extern void DWCi_ScreenDC_FlushRange(void *data, u32 size);
extern void MIi_CpuCopy16(void *src, void *dst, u32 size);
extern u32 func_020307B0(void *ptr);
extern int func_02062B30(void *file, void **out);
extern void *G2_GetBG1ScrPtr(void);
extern s32 func_02062AD4(struct NitroFileHeader *file, void **out);
extern s32 func_02062A98(struct NitroFileHeader *file, void **out);
extern void MIi_CpuClear16(int value, u32 dst, u32 size);
extern struct Bmp *BMP_CreateFromVram(void *pixels, u32 width, u32 height, u32 depth, u16 heapId);
extern struct GfFont *GF_FONT_Create(int fontId, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct Strbuf *func_02045EC0(struct MsgBank *bank, u32 index);
extern void PRINTSYS_PrintColor(struct Bmp *bmp, s16 x, s16 y, struct Strbuf *str, struct GfFont *font, u16 color);
extern void STRBUF_Delete(struct Strbuf *str);
extern u32 MSGDATA_Delete(struct MsgBank *bank);
extern u32 GF_FONT_Delete(struct GfFont *font);
extern void BMP_Delete(struct Bmp *bmp);
extern void BG_SYS_SetSubVisiblePlanes(u32 planes);
void ERROR_SCREEN_ShowAndWait(void);
void ERROR_SCREEN_Setup(int messageIndex);
void ERROR_SCREEN_LoadBackground(void);
void ERROR_SCREEN_PrintMessage(int messageIndex);
void ERROR_SCREEN_Teardown(void);


/* Display and key registers touched by the error screen. */
#define REG_DISPCNT_MAIN   (*(volatile u32 *)0x04000000)


/* Held keys, A and B only matter here; the shared (ext) key word is merged in. */
static inline u16 ReadKeys(void)
{
    u16 keys = (u16)(((REG_KEYINPUT | REG_EXT_KEYINPUT) ^ 0x2FFF) & 0x2FFF);
    keys = (u16)(keys & ~((keys & 0x40) << 1) & ~((keys & 0x20) >> 1));
    return keys;
}


/*
 * Error screen entry: show message 0x2A (TWL) or 0x10 (DS) from message
 * file 0xE8, wait until A and B are released, wait for A or B, then tear
 * the screen down.
 */
void ERROR_SCREEN_ShowAndWait(void)
{
    ERROR_SCREEN_Setup(func_0202EB0C() ? 0x2A : 0x10);
    while (ReadKeys() & 3) {
        GFL_USE_PollPowerExit();
        func_02034F5C();
    }
    while (!(ReadKeys() & 3)) {
        GFL_USE_PollPowerExit();
        func_02034F5C();
    }
    ERROR_SCREEN_Teardown();
}


/* Blank both screens, set up BG1 on the main screen, draw the background and message, fade in. */
void ERROR_SCREEN_Setup(int messageIndex)
{
    GXx_SetMasterBrightness_(REG_MASTER_BRIGHT_MAIN, -16);
    GXx_SetMasterBrightness_(REG_MASTER_BRIGHT_SUB, -16);
    func_020808F4();
    func_020809A0();
    func_0207FDCC(4);
    GX_SetGraphicsMode(1, 0, 0);
    REG_DISPCNT_MAIN = (REG_DISPCNT_MAIN & 0xFFFFE0FF) | (1 << 9);
    REG_DISPCNT_MAIN &= 0xFFFF1FFF;
    REG_BG1CNT_MAIN = (REG_BG1CNT_MAIN & 0x43) | 4;
    REG_BG1CNT_MAIN &= 0xFFBF;
    REG_BG1HOFS_MAIN = 0;
    REG_BLDCNT_MAIN = 0;
    ERROR_SCREEN_LoadBackground();
    ERROR_SCREEN_PrintMessage(messageIndex);
    GXx_SetMasterBrightness_(REG_MASTER_BRIGHT_MAIN, 0);
    GXx_SetMasterBrightness_(REG_MASTER_BRIGHT_SUB, 0x10);
}


static inline void CopyToVram(void *src, void *dst, u32 size)
{
    MIi_CpuCopy16(src, dst, size);
}


/*
 * Loads a background from archive 0x16: clears 0x4000 bytes of character
 * VRAM, then unpacks file 1 (characters), file 2 (screen) and file 0
 * (palette, 0x20 bytes to 0x05000000), flushing and copying each and
 * freeing the file buffer after each.
 *
 * The copy goes through an inline wrapper (or a dst local): a plain
 * call argument f(src, g(), p->size) loads the size after g(); the
 * original loads it before g() and keeps it in r5.
 */
void ERROR_SCREEN_LoadBackground(void)
{
    CharData *charData;
    ScreenData *screenData;
    PaletteData *paletteData;
    void *unusedBlock;
    void *file;

    func_02082A7C(0, G2_GetBG1CharPtr(), 0x4000);

    file = (void *)ARC_UTIL_LoadMember(0x16, 1, 0, 1);
    if (func_02062A4C(file, (void **)(&charData))) {
        DWCi_ScreenDC_FlushRange(charData->pixels, charData->sizeBytes);
        CopyToVram(charData->pixels, G2_GetBG1CharPtr(), charData->sizeBytes);
    }
    func_020307B0(file);

    file = (void *)ARC_UTIL_LoadMember(0x16, 2, 0, 1);
    if (func_02062B30(file, (void **)(&screenData))) {
        DWCi_ScreenDC_FlushRange(screenData->tiles, screenData->sizeBytes);
        CopyToVram(screenData->tiles, G2_GetBG1ScrPtr(), screenData->sizeBytes);
    }
    func_020307B0(file);

    file = (void *)ARC_UTIL_LoadMember(0x16, 0, 0, 1);
    func_02062AD4(file, &unusedBlock);
    if (func_02062A98(file, (void **)(&paletteData))) {
        DWCi_ScreenDC_FlushRange(paletteData->colors, 0x20);
        CopyToVram(paletteData->colors, (void *)PLTT_MAIN_BG, 0x20);
    }
    func_020307B0(file);
}


/* Fill the BG1 tile map (30x16 tiles at row 4, column 1) with sequential tiles from 0x20, print the message into the bitmap, release the temporaries. */
void ERROR_SCREEN_PrintMessage(int messageIndex)
{
    u16 *tileMap;
    int col, row;
    u16 tile;
    struct Bmp *bmp;
    struct GfFont *font;
    struct MsgBank *bank;
    struct Strbuf *message;

    tileMap = G2_GetBG1ScrPtr();
    tile = 0x20;
    for (row = 4; row < 20; row++) {
        for (col = 1; col < 31; col++) {
            tileMap[row * 32 + col] = tile;
            tile++;
        }
    }
    MIi_CpuClear16(0x7777, (u32)G2_GetBG1CharPtr() + 0x400, 0x3C00);
    bmp = BMP_CreateFromVram((void *)((u32)G2_GetBG1CharPtr() + 0x400), 30, 16, 32, 1);
    font = GF_FONT_Create(0x17, 0, 0, 0, 1);
    bank = func_02045B38(0, 2, 0xe8, 1);
    message = func_02045EC0(bank, messageIndex);
    PRINTSYS_PrintColor(bmp, 0, 0, message, font, 0x1167);
    STRBUF_Delete(message);
    MSGDATA_Delete(bank);
    GF_FONT_Delete(font);
    BMP_Delete(bmp);
}


/* Error screen teardown: fade out, hide the planes, clear character data, tile map and palette, disable the main BGs. */
void ERROR_SCREEN_Teardown(void)
{
    GXx_SetMasterBrightness_(REG_MASTER_BRIGHT_MAIN, -16);
    GXx_SetMasterBrightness_(REG_MASTER_BRIGHT_SUB, -16);
    BG_SYS_SetSubVisiblePlanes(0);
    MIi_CpuClear16(0, (u32)G2_GetBG1CharPtr(), 0x4000);
    MIi_CpuClear16(0, (u32)G2_GetBG1ScrPtr(), 0x800);
    MIi_CpuClear16(0x7FFF, PLTT_MAIN_BG, 0x20);
    REG_DISPCNT_MAIN &= 0xFFFFE0FF;
    func_020809A0();
    func_020808F4();
    GXx_SetMasterBrightness_(REG_MASTER_BRIGHT_MAIN, 0);
    GXx_SetMasterBrightness_(REG_MASTER_BRIGHT_SUB, 0);
}

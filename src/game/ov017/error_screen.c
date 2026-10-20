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
 *   APP_ENV_IsRunOnTwl  0x0202EB0C  thumb
 *   GFL_USE_PollPowerExit  0x020053EC  thumb
 *   UI_Update  0x02034F5C  arm
 *   GXx_SetMasterBrightness_  0x0207D534  arm
 *   GX_ResetBankForBG  0x020808F4  arm
 *   GX_ResetBankForSubBG  0x020809A0  arm
 *   GX_SetBankForBG  0x0207FDCC  arm
 *   GX_SetGraphicsMode  0x0207D4B0  arm
 *   G2_GetBG1CharPtr  0x0207E24C  arm
 *   MIi_CpuClear32  0x02082A7C  arm
 *   ARC_UTIL_LoadMember  0x0204A1BC  arm
 *   NNS_G2dGetUnpackedCharacterDataEx  0x02062A4C  arm
 *   DC_FlushRange  0x020862F0  arm
 *   MIi_CpuCopy16  0x02082A60  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   NNS_G2dGetUnpackedScreenData  0x02062B30  arm
 *   G2_GetBG1ScrPtr  0x0207DFB4  arm
 *   NNS_G2dGetUnpackedPaletteCompressInfo  0x02062AD4  arm
 *   NNS_G2dGetUnpackedPaletteData  0x02062A98  arm
 *   MIi_CpuClear16  0x02082A48  arm
 *   BMP_CreateFromVram  0x02043754  arm
 *   GF_FONT_Create  0x0201D7EC  thumb
 *   MSGDATA_CreateFromArchive  0x02045B38  arm
 *   MSGDATA_AllocString  0x02045EC0  arm
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
#include "../types.h"
#include "../arm9/nns_g2d_res_types.h"

#include "../arm9/app_env.h"
#include "../arm9/gfl_use.h"
#include "../arm9/ui.h"
#include "../arm9/gx.h"
#include "../arm9/gx_vramcnt.h"
#include "../arm9/gx_bgcnt.h"
#include "../arm9/arc_util.h"
#include "../arm9/nns_g2d_anim_bank.h"
#include "../arm9/os_cache.h"
#include "../arm9/gfl_heap_wrap.h"
#include "../arm9/nns_g2d_load.h"
#include "../arm9/mi_memory.h"
typedef short s16_p07;
#include "../arm9/bmp.h"
#include "../arm9/gf_font.h"
#include "../arm9/msgdata.h"
#include "../arm9/printsys.h"
#include "../arm9/strbuf.h"
#include "../arm9/bg_sys.h"
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
    ERROR_SCREEN_Setup(APP_ENV_IsRunOnTwl() ? 0x2A : 0x10);
    while (ReadKeys() & 3) {
        GFL_USE_PollPowerExit();
        UI_Update();
    }
    while (!(ReadKeys() & 3)) {
        GFL_USE_PollPowerExit();
        UI_Update();
    }
    ERROR_SCREEN_Teardown();
}

/* Blank both screens, set up BG1 on the main screen, draw the background and message, fade in. */
void ERROR_SCREEN_Setup(int messageIndex)
{
    GXx_SetMasterBrightness_(REG_MASTER_BRIGHT_MAIN, -16);
    GXx_SetMasterBrightness_(REG_MASTER_BRIGHT_SUB, -16);
    GX_ResetBankForBG();
    GX_ResetBankForSubBG();
    GX_SetBankForBG(4);
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
    NNSG2dCharacterData *charData;
    NNSG2dScreenData *screenData;
    NNSG2dPaletteData *paletteData;
    void *unusedBlock;
    void *file;

    MIi_CpuClear32(0, G2_GetBG1CharPtr(), 0x4000);

    file = (void *)ARC_UTIL_LoadMember(0x16, 1, 0, 1);
    if (NNS_G2dGetUnpackedCharacterDataEx(file, (void **)(&charData))) {
        DC_FlushRange(charData->pRawData, charData->szByte);
        CopyToVram(charData->pRawData, G2_GetBG1CharPtr(), charData->szByte);
    }
    GFL_HEAP_Free(file);

    file = (void *)ARC_UTIL_LoadMember(0x16, 2, 0, 1);
    if (NNS_G2dGetUnpackedScreenData(file, (void **)(&screenData))) {
        DC_FlushRange(screenData->rawData, screenData->szByte);
        CopyToVram(screenData->rawData, G2_GetBG1ScrPtr(), screenData->szByte);
    }
    GFL_HEAP_Free(file);

    file = (void *)ARC_UTIL_LoadMember(0x16, 0, 0, 1);
    NNS_G2dGetUnpackedPaletteCompressInfo(file, &unusedBlock);
    if (NNS_G2dGetUnpackedPaletteData(file, (void **)(&paletteData))) {
        DC_FlushRange(paletteData->pRawData, 0x20);
        CopyToVram(paletteData->pRawData, (void *)PLTT_MAIN_BG, 0x20);
    }
    GFL_HEAP_Free(file);
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
    MIi_CpuClear16(0x7777, (void *)((uptr)G2_GetBG1CharPtr() + 0x400), 0x3C00);
    bmp = BMP_CreateFromVram((void *)((uptr)G2_GetBG1CharPtr() + 0x400), 30, 16, 32, 1);
    font = GF_FONT_Create(0x17, 0, 0, 0, 1);
    bank = MSGDATA_CreateFromArchive(0, 2, 0xe8, 1);
    message = MSGDATA_AllocString(bank, messageIndex);
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
    MIi_CpuClear16(0, G2_GetBG1CharPtr(), 0x4000);
    MIi_CpuClear16(0, G2_GetBG1ScrPtr(), 0x800);
    MIi_CpuClear16(0x7FFF, (void *)PLTT_MAIN_BG, 0x20);
    REG_DISPCNT_MAIN &= 0xFFFFE0FF;
    GX_ResetBankForSubBG();
    GX_ResetBankForBG();
    GXx_SetMasterBrightness_(REG_MASTER_BRIGHT_MAIN, 0);
    GXx_SetMasterBrightness_(REG_MASTER_BRIGHT_SUB, 0);
}

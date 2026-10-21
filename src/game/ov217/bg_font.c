/*
 * file:     bg_font.c
 * unit:     yes
 * function: BgTextLabel_Create, BgTextLabel_Destroy, BgTextLabel_PrintMessage, BgTextLabel_PrintText, BgTextLabel_SetVisible, BgTextLabel_SetPalette, BgTextLabel_GetCenterOffset
 * address:  0x021C0EF4
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from research_top.c, unit_021BFFC8.c, queue.c, palette_anime.c, PALETTE_ANIME_ReleaseOriginal.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Free 0x020307B0 arm
 *   BgTextLabel_SetPalette  0x021C1038  thumb  ov217
 *   BgTextLabel_Create 0x021C0EF4 thumb ov217
 *   BgTextLabel_PrintMessage 0x021C0F5C thumb ov217
 *   BgTextLabel_Destroy  0x021C0F48  thumb  ov217
 *   BG_SYS_FillTileMap 0x020413B0 arm
 *   BG_SYS_MarkTileDirty 0x02041B6C arm
 *   BgTextLabel_SetVisible  0x021C0FF8  thumb  ov217
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   PRINTSYS_PrintColor 0x0201C7D0 thumb
 *   BgTextLabel_PrintText 0x021C0F78 thumb ov217
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   d_021C4058 0x021C4058 data a1
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   BMP_WIN_SetPalette 0x02045798 arm
 *   BMP_WIN_GetPosX 0x02045758 arm
 *   BMP_WIN_GetPosY 0x02045760 arm
 *   BMP_WIN_GetDispWidth 0x02045748 arm
 *   BMP_WIN_GetDispHeight 0x02045750 arm
 *   BMP_WIN_GetWidth  0x02045738  arm
 *   PRINTSYS_MeasureWidestLine  0x0201D304  thumb
 *   BMP_WIN_Delete  0x020452E8  arm  arm9
 *   _ffix                        0x0209C494  arm
 *   _fflt                        0x0209BDBC  arm
 *   _fmul                        0x0209C77C  arm
 */
#include "research_shared_types.h"

struct BmpWin;
struct BmpPixels;
struct StrObj;

/* Window and colour setup of a text label. */
struct BgTextLabelConfig {
    u8 bgLayer;
    u8 winX;
    u8 winY;
    u8 winWidth;
    u8 winHeight;
    u8 textX;
    u8 textY;
    u8 palette;
    u8 red;
    u8 green;
    u8 blue;
    u8 colorPad;
    u32 centered;
};

/* Text label drawn into its own BMP window, 32 bytes. */
struct BgTextLabel {
    struct BgTextLabelConfig config;
    u32 font;
    u32 msgBank;
    struct BmpWin *window;
    u32 visible;
};

#include "../arm9/gfl_heap_wrap.h"
struct MsgBank;
struct Strbuf;
#include "../arm9/msgdata.h"
struct GfFont;
struct Bmp;
#include "../arm9/strbuf_types.h"
#include "../ov094/btlv_input_shared_types.h"
#include "../ov099/wifi_club_work.h"
extern void PRINTSYS_PrintColor(struct Bmp *bmp, s16 x, s16 y, struct Strbuf *str, struct GfFont *font, u16 color);
#include "../arm9/bmp_win.h"
#include "../arm9/bmp.h"
#include "../arm9/bg_sys.h"
extern u32 PRINTSYS_MeasureWidestLine(struct Strbuf *text, struct GfFont *font, u32 spacing);

struct BgTextLabel *BgTextLabel_Create(const struct BgTextLabelConfig *config, u32 font, u32 msgBank, u32 heapId);
void BgTextLabel_Destroy(struct BgTextLabel *label);
u32 BgTextLabel_PrintMessage(struct BgTextLabel *label, u32 msgIndex);
void BgTextLabel_PrintText(struct BgTextLabel *label, void *text);
void BgTextLabel_SetVisible(struct BgTextLabel *label, int visible);
void BgTextLabel_SetPalette(struct BgTextLabel *label, u8 palette);
int BgTextLabel_GetCenterOffset(struct BgTextLabel *label, void *text);

extern const char d_021C4058[];

/* Creates a label and its BMP window from config. */
struct BgTextLabel *BgTextLabel_Create(const struct BgTextLabelConfig *config, u32 font, u32 msgBank, u32 heapId)
{
    struct BgTextLabel *label = GFL_HEAP_Alloc(heapId, 32, 0, d_021C4058, 55);
    label->config = *config;
    label->font = font;
    label->msgBank = msgBank;
    label->window = (struct BmpWin *)BMP_WIN_Create(config->bgLayer, config->winX, config->winY, config->winWidth, config->winHeight, config->palette, 0);
    label->visible = 1;
    return label;
}

/* Deletes the window, then frees the label. */
void BgTextLabel_Destroy(struct BgTextLabel *label)
{
    BMP_WIN_Delete(label->window);
    GFL_HEAP_Free(label);
}

/* Fetches message msgIndex from the label's message bank and prints it. */
u32 BgTextLabel_PrintMessage(struct BgTextLabel *label, u32 msgIndex)
{
    void *text = MSGDATA_AllocString((struct MsgBank *)label->msgBank, msgIndex);
    BgTextLabel_PrintText(label, text);
    return GFL_HEAP_Free(text);
}

/*
 * textY is written in both arms of the centered if/else: the join value has no known range, so the s16 argument is sign-extended (lsls/asrs) as in the original.
 */
void BgTextLabel_PrintText(struct BgTextLabel *label, void *text)
{
    u16 color;
    void *bmp;
    int textX;
    int textY;
    struct BmpWin *window;
    color = ((label->config.red & 31) << 10) | ((label->config.green & 31) << 5) | (label->config.blue & 31);
    bmp = BMP_WIN_GetBmp(label->window);
    BMP_Clear(bmp, label->config.blue);
    if (label->config.centered != 0) {
        textX = label->config.textX + BgTextLabel_GetCenterOffset(label, text);
        textY = label->config.textY;
    } else {
        textX = label->config.textX;
        textY = label->config.textY;
    }
    PRINTSYS_PrintColor(bmp, textX, textY, text, (void *)label->font, color);
    if (label->visible != 0) {
        window = label->window;
        BMP_WIN_TransferChars(window);
        BMP_WIN_MakeScreen(window);
        BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer(window));
    }
}

/*
 * Shows or hides the window.
 * tail: two zero padding bytes at 0x021C1036, not a follower.
 */
void BgTextLabel_SetVisible(struct BgTextLabel *label, int visible)
{
    if (label->visible == 0 && visible != 0) {
        struct BmpWin *window = label->window;
        BMP_WIN_TransferChars(window);
        BMP_WIN_MakeScreen(window);
        BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer(window));
    } else if (label->visible != 0 && visible == 0) {
        struct BmpWin *window = label->window;
        BMP_WIN_ClearScreen(window);
        BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer(window));
    }
    label->visible = visible;
}

/* Sets the window palette and re-applies it to the background layer. */
void BgTextLabel_SetPalette(struct BgTextLabel *label, u8 palette)
{
    u8 bgLayer;
    u8 x, y, width, height;
    BMP_WIN_SetPalette(label->window, palette);
    bgLayer = BMP_WIN_GetBgLayer(label->window);
    x = BMP_WIN_GetPosX(label->window);
    y = BMP_WIN_GetPosY(label->window);
    width = BMP_WIN_GetDispWidth(label->window);
    height = BMP_WIN_GetDispHeight(label->window);
    BG_SYS_FillTileMap(bgLayer, x, y, width, height, palette);
    if (label->visible != 0) BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer(label->window));
}

/* Horizontal offset that centres text in the window (never negative). */
int BgTextLabel_GetCenterOffset(struct BgTextLabel *label, void *text)
{
    int offset;
    int space;
    space = BMP_WIN_GetWidth(label->window) * 8;
    space = space - PRINTSYS_MeasureWidestLine((struct Strbuf *)text, (struct GfFont *)label->font, 0);
    offset = (int)(0.5f * (float)space);
    if (offset < 0) {
        offset = 0;
    }
    return offset;
}

/*
 * file:     pmsiv_category.c
 * unit:     yes
 * function: PMSIV_CATEGORY_Create, PMSIV_CATEGORY_Delete, PMSIV_CATEGORY_Setup, PMSIV_CATEGORY_MakeCategoryButtons, PMSIV_CATEGORY_MakeKanaWindow, PMSIV_CATEGORY_MakeTitleWindow, PMSIV_CATEGORY_MakeListWindow, PMSIV_CATEGORY_CreateCursor, PMSIV_CATEGORY_SetCursorVisible, PMSIV_CATEGORY_MoveCursor, PMSIV_CATEGORY_StartFadeIn, PMSIV_CATEGORY_IsFadeInDone, PMSIV_CATEGORY_StartClose, PMSIV_CATEGORY_StepClose, PMSIV_CATEGORY_ResetBgScroll, PMSIV_CATEGORY_StartFadeOut, PMSIV_CATEGORY_IsFadeOutDone, PMSIV_CATEGORY_StartBlendOut, PMSIV_CATEGORY_IsBlendOutDone, PMSIV_CATEGORY_StartBlendIn, PMSIV_CATEGORY_IsBlendInDone, PMSIV_CATEGORY_ApplyBgOffset, PMSIV_CATEGORY_RefreshScreens, PMSIV_CATEGORY_IsReady, PMSIV_CATEGORY_DrawTitle, PMSIV_CATEGORY_ShowWordList, PMSIV_CATEGORY_StartListScrollOut, PMSIV_CATEGORY_DrawWordList, PMSIV_CATEGORY_IsListReady, PMSIV_CATEGORY_StartSelectAnim, PMSIV_CATEGORY_IsSelectAnimDone
 * address:  0x021BB290
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Category and kana key picker of the easy-chat input screen: the 12 category buttons, the kana key grid, the title bar and the word list that scrolls in below it.
 *
 * symbols:
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   PMS_INPUT_GetUiInputModePtr 0x021BF6D4 thumb ov110
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   PMSIV_CATEGORY_Create 0x021BB290 thumb ov110
 *   PMSIV_CATEGORY_Setup 0x021BB328 thumb ov110
 *   ARC_UTIL_UploadBgPaletteFromHandle 0x020498F4 arm
 *   ARC_UTIL_UploadBgCharFromHandle 0x02049658 arm
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   PMSIV_CATEGORY_Delete 0x021BB2CC thumb ov110
 *   PMSIV_MENU_SetActiveEntry 0x021BCF7C thumb ov110
 *   PMSIV_CATEGORY_StartFadeIn 0x021BB76C thumb ov110
 *   PMS_INPUT_GetBrowseMode 0x021BF6DC thumb ov110
 *   PMSIV_CATEGORY_DrawTitle 0x021BB958 thumb ov110
 *   PMSIV_CATEGORY_IsFadeInDone 0x021BB784 thumb ov110
 *   PMSIV_CATEGORY_MoveCursor 0x021BB6A0 thumb ov110
 *   PMSIV_CATEGORY_SetCursorVisible 0x021BB658 thumb ov110
 *   PMSIV_CATEGORY_RefreshScreens 0x021BB8D8 thumb ov110
 *   PMSIV_CATEGORY_ApplyBgOffset 0x021BB8B8 thumb ov110
 *   PMSIV_CATEGORY_IsReady 0x021BB954 thumb ov110
 *   PMSIV_CATEGORY_ShowWordList 0x021BB9C0 thumb ov110
 *   PMSIV_CATEGORY_IsListReady 0x021BBB0C thumb ov110
 *   PMSIV_CATEGORY_StartClose 0x021BB7A0 thumb ov110
 *   PMSIV_CATEGORY_StepClose 0x021BB7B8 thumb ov110
 *   PMSIV_CATEGORY_IsSelectAnimDone 0x021BBC10 thumb ov110
 *   PMSIV_CATEGORY_StartBlendOut 0x021BB838 thumb ov110
 *   PMSIV_CATEGORY_IsBlendOutDone 0x021BB854 thumb ov110
 *   PMS_INPUT_GetInitialCount 0x021BF7FC thumb ov110
 *   PMSIV_CATEGORY_StartBlendIn 0x021BB870 thumb ov110
 *   PMSIV_CATEGORY_IsBlendInDone 0x021BB8AC thumb ov110
 *   PMSIV_CATEGORY_ResetBgScroll 0x021BB804 thumb ov110
 *   PMSIV_CATEGORY_StartFadeOut 0x021BB814 thumb ov110
 *   PMSIV_CATEGORY_IsFadeOutDone 0x021BB82C thumb ov110
 *   PMSIV_CATEGORY_StartSelectAnim 0x021BBB84 thumb ov110
 *   ARC_UTIL_UploadBgPaletteAddFromHandleExt 0x020499D4 arm
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BG_SYS_MarkTileDirty 0x02041B6C arm
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   STRBUF_Create 0x020457B0 arm
 *   sPmsivCategoryAllocSite 0x021C3C44 data a1
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   BG_SYS_ChangeScrollImmediate 0x02040618 arm
 *   G2x_SetBlendBrightness_ 0x0207D658 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   sPmsivCategoryLabelIds 0x021C38C4 data ov110 a1
 *   PMS_INPUT_VIEW_GetFont 0x021BAC44 thumb ov110
 *   PMS_INPUT_DATA_GetCategoryWordCount 0x021B999C thumb ov110
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   PRINTSYS_MeasureWidestLine 0x0201D304 thumb
 *   PRINTSYS_Print 0x0201C7A4 thumb
 *   PMSI_SEARCH_GetKeyCount 0x021BB1F4 thumb ov110
 *   PMSI_SEARCH_GetKeyLabel 0x021BB1F8 thumb ov110
 *   PMSI_SEARCH_GetKeyPosition 0x021BB224 thumb ov110
 *   PMS_INPUT_VIEW_GetUiRes 0x021BAC64 thumb ov110
 *   PMS_INPUT_VIEW_CreateActor 0x021BAC78 thumb ov110
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   sPmsivCategoryCursorOrigin 0x021C38D0 data ov110 a2
 *   PMS_INPUT_VIEW_GetMenu 0x021BAC3C thumb ov110
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   PMSIV_FADE_StartBrightness 0x021BC8FC thumb ov110
 *   PMSIV_FADE_IsBrightnessDone 0x021BC93C thumb ov110
 *   PMSIV_BGSCROLL_Start 0x021BC78C thumb ov110
 *   PMSIV_BGSCROLL_Step 0x021BC7DC thumb ov110
 *   PMSIV_FADE_StartBlend 0x021BC868 thumb ov110
 *   PMSIV_FADE_IsBlendDone 0x021BC898 thumb ov110
 *   G2x_SetBlendAlpha_ 0x0207D63C arm
 *   BG_SYS_ChangeScroll 0x02041EE4 arm
 *   PMS_INPUT_SetSearchArg 0x021BF7D4 thumb ov110
 *   BG_SYS_GetScrollY 0x02040804 arm
 *   PMS_INPUT_VIEW_GetPrintQue 0x021BAC4C thumb ov110
 *   PMS_INPUT_GetInitialWord 0x021BF814 thumb ov110
 *   CLACT_GetActorDrawEnable 0x0204B3F4 arm
 *   CLACT_GetActorAnimSeq 0x0204B898 arm
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   _u32_div_f                   0x0209C2B0  arm
 */
#include "pms_input_data_shared_types.h"
#include "pms_input_view_shared_types.h"
#include "pmsiv_category_shared_types.h"
#include "pmsiv_edit_shared_types.h"

#define REG_DISPCNT (*(volatile u32 *)0x04000000)
#define REG_WIN0H (*(volatile u16 *)0x04000040)
#define REG_WIN0V (*(volatile u16 *)0x04000044)
#define REG_WININ (*(volatile u16 *)0x04000048)
#define REG_WINOUT (*(volatile u16 *)0x0400004a)

#define PMSIV_CATEGORY_COUNT 12
#define PMSIV_CATEGORY_HEAP 42
#define PMSIV_CATEGORY_CURSOR_NONE 254


struct PmsivCategory {
    struct PmsInputView *view;
    struct PmsInputState *input;
    struct PmsInputData *wordData;
    u32 unusedWord0C;
    int fadeState;
    u32 unusedWord14;
    struct PmsivFade fade;
    struct PmsivBgScroll scroll;
    struct ClactActor *cursorActor;
    u32 savedCursorVisible;
    int *modeFlag;
    struct BmpWin *categoryWindows[PMSIV_CATEGORY_COUNT];
    struct BmpWin *kanaWindow;
    struct BmpWin *titleWindow;
    struct BmpWin *listWindow;
    struct BmpWin *printWindow;
    u8 printPending;
};

typedef struct { short x, y; } PmsivCategoryScreenPos;

#include "../arm9/gfl_heap_wrap.h"
struct PmsInput;
#include "pms_input.h"
#include "../arm9/arc_tool.h"
#include "../arm9/arc_util.h"
#include "../arm9/bg_sys.h"
struct BmpWin;
struct Bmp;
#include "../arm9/bmp_win.h"
typedef short s16_p07;
#include "../arm9/bmp.h"
struct PmsInput;
#include "../arm9/msgdata.h"
struct Strbuf;
#include "../arm9/strbuf.h"
struct Bmp;
struct PrintQueue;
#ifdef __MWERKS__
#define PRINTSYS_Print PRINTSYS_Print_hdr
#endif
#include "../arm9/printsys.h"
#ifdef __MWERKS__
#undef PRINTSYS_Print
void PRINTSYS_Print(struct Bmp *bmp, s16 x, s16 y, struct Strbuf *str, struct GfFont *font);
#endif
struct ClactActor;
#include "../arm9/clact.h"
struct BmpWin;
#include "../arm9/g2.h"
struct GfFont;
#include "pms_input_view.h"
#include "pms_input_data.h"
#include "../arm9/gf_font.h"
struct GfFont;
#include "pmsi_search.h"
struct PmsivMenu;
#include "pmsiv_menu.h"
#include "pmsiv_tool.h"
struct PrintQue;

struct PmsivCategory *PMSIV_CATEGORY_Create(struct PmsInputView *view, struct PmsInputState *input, struct PmsInputData *wordData);
void PMSIV_CATEGORY_Delete(struct PmsivCategory *p);
void PMSIV_CATEGORY_Setup(struct PmsivCategory *p, void *data);
u8 *PMSIV_CATEGORY_MakeCategoryButtons(struct PmsivCategory *p, u8 *q);
u8 *PMSIV_CATEGORY_MakeKanaWindow(struct PmsivCategory *p, u8 *q);
u8 *PMSIV_CATEGORY_MakeTitleWindow(struct PmsivCategory *p, u8 *q);
void PMSIV_CATEGORY_MakeListWindow(struct PmsivCategory *p);
void PMSIV_CATEGORY_CreateCursor(struct PmsivCategory *p);
void PMSIV_CATEGORY_SetCursorVisible(struct PmsivCategory *p, int enable);
void PMSIV_CATEGORY_MoveCursor(struct PmsivCategory *p, unsigned index);
void PMSIV_CATEGORY_StartFadeIn(struct PmsivCategory *p);
int PMSIV_CATEGORY_IsFadeInDone(struct PmsivCategory *p);
void PMSIV_CATEGORY_StartClose(struct PmsivCategory *p);
int PMSIV_CATEGORY_StepClose(struct PmsivCategory *p);
void PMSIV_CATEGORY_ResetBgScroll(struct PmsivCategory *p);
void PMSIV_CATEGORY_StartFadeOut(struct PmsivCategory *p);
int PMSIV_CATEGORY_IsFadeOutDone(struct PmsivCategory *p);
void PMSIV_CATEGORY_StartBlendOut(struct PmsivCategory *p);
int PMSIV_CATEGORY_IsBlendOutDone(struct PmsivCategory *p);
void PMSIV_CATEGORY_StartBlendIn(struct PmsivCategory *p);
int PMSIV_CATEGORY_IsBlendInDone(struct PmsivCategory *p);
void PMSIV_CATEGORY_ApplyBgOffset(struct PmsivCategory *p);
void PMSIV_CATEGORY_RefreshScreens(struct PmsivCategory *p);
int PMSIV_CATEGORY_IsReady(struct PmsivCategory *p);
void PMSIV_CATEGORY_DrawTitle(struct PmsivCategory *p);
void PMSIV_CATEGORY_ShowWordList(struct PmsivCategory *p, int flag);
void PMSIV_CATEGORY_StartListScrollOut(struct PmsivCategory *p, u32 unused);
void PMSIV_CATEGORY_DrawWordList(struct PmsivCategory *p, unsigned count);
int PMSIV_CATEGORY_IsListReady(struct PmsivCategory *p, int waitForPrint);
void PMSIV_CATEGORY_StartSelectAnim(struct PmsivCategory *p, unsigned index);
int PMSIV_CATEGORY_IsSelectAnimDone(struct PmsivCategory *p);

extern const char sPmsivCategoryAllocSite[];
extern const u8 sPmsivCategoryLabelIds[];
extern const PmsivCategoryScreenPos sPmsivCategoryCursorOrigin;

struct PmsivCategory *PMSIV_CATEGORY_Create(struct PmsInputView *view, struct PmsInputState *input, struct PmsInputData *wordData)
{
    struct PmsivCategory *p;
    p = GFL_HEAP_Alloc(PMSIV_CATEGORY_HEAP, sizeof(struct PmsivCategory), 0, sPmsivCategoryAllocSite, 220);
    p->view = view;
    p->input = input;
    p->wordData = wordData;
    p->unusedWord0C = 0;
    p->unusedWord14 = 0;
    p->cursorActor = 0;
    p->savedCursorVisible = 0;
    p->modeFlag = (int *)PMS_INPUT_GetUiInputModePtr((struct PmsInput *)input);
    return p;
}

/*
 * extent: trailing two-byte zero padding
 */
void PMSIV_CATEGORY_Delete(struct PmsivCategory *p)
{
    u8 i;
    if (p->cursorActor) CLACT_DeleteActor((struct ClactActor *)p->cursorActor);
    for (i = 0; i < PMSIV_CATEGORY_COUNT; i++) if (p->categoryWindows[i]) BMP_WIN_Delete((struct BmpWin *)p->categoryWindows[i]);
    if (p->kanaWindow) BMP_WIN_Delete((struct BmpWin *)p->kanaWindow);
    if (p->titleWindow) BMP_WIN_Delete((struct BmpWin *)p->titleWindow);
    if (p->listWindow) BMP_WIN_Delete((struct BmpWin *)p->listWindow);
    GFL_HEAP_Free(p);
}

static inline void setWindowInside(int layers, int effect)
{
    u32 value;
    value = (REG_WININ & ~0x3f) | (u32)layers;
    if (effect) value |= 0x20;
    REG_WININ = (u16)value;
}

static inline void setWindowOutside(int layers, int effect)
{
    u32 value;
    value = (REG_WINOUT & ~0x3f) | (u32)layers;
    if (effect) value |= 0x20;
    REG_WINOUT = (u16)value;
}

void PMSIV_CATEGORY_Setup(struct PmsivCategory *p, void *data)
{
    u32 bytes, q;
    ARC_UTIL_UploadBgPaletteFromHandle((void *)data, 27, 1, 0, 0, 0, PMSIV_CATEGORY_HEAP);
    bytes = ARC_UTIL_UploadBgCharFromHandle((void *)data, 15, 1, 0, 0, 0, PMSIV_CATEGORY_HEAP);
    q = (u32)PMSIV_CATEGORY_MakeCategoryButtons(p, (u8 *)(bytes / 32));
    q = (u32)PMSIV_CATEGORY_MakeKanaWindow(p, (u8 *)q);
    PMSIV_CATEGORY_MakeTitleWindow(p, (u8 *)q);
    PMSIV_CATEGORY_MakeListWindow(p);
    BG_SYS_ChangeScrollImmediate(1, 0, -4);
    BG_SYS_ChangeScrollImmediate(1, 3, 16);
    PMSIV_CATEGORY_CreateCursor(p);
    G2x_SetBlendBrightness_(0x04000050, 2, -10);
    setWindowInside(31, 1);
    setWindowOutside(29, 1);
    REG_WIN0H = 255;
    REG_WIN0V = 168;
    REG_DISPCNT = (REG_DISPCNT & ~0xe000) | 0x2000;
    BG_SYS_PushTile(1);
}

u8 *PMSIV_CATEGORY_MakeCategoryButtons(struct PmsivCategory *p, u8 *q)
{
    int x, y;
    void *bank;
    u32 font;
    int i;
    void *label;
    struct BmpWin *window;
    u32 width;
    font = (u32)PMS_INPUT_VIEW_GetFont(p->view);
    bank = MSGDATA_CreateFromArchive(0, 2, 145, PMSIV_CATEGORY_HEAP);
    x = 1;
    y = 9;
    for (i = 0; i < PMSIV_CATEGORY_COUNT; i++) {
        if (i != 0 && i % 3 == 0) { x = 1; y += 3; }
        if (PMS_INPUT_DATA_GetCategoryWordCount(p->wordData, i)) {
            label = MSGDATA_AllocString(bank, sPmsivCategoryLabelIds[i]);
            GF_FONT_SetTextColor(1, 2, 15);
        } else {
            label = MSGDATA_AllocString(bank, 13);
            GF_FONT_SetTextColor(3, 4, 15);
        }
        window = BMP_WIN_Create(1, (u8)x, (u8)y, 9, 2, 12, 1);
        BMP_Clear(BMP_WIN_GetBmp(window), 15);
        width = 72 - PRINTSYS_MeasureWidestLine(label, (struct GfFont *)font, 0);
        PRINTSYS_Print(BMP_WIN_GetBmp(window), width >> 1, 0, label, (void *)font);
        BMP_WIN_MakeScreen((struct BmpWin *)window);
        BMP_WIN_TransferChars((struct BmpWin *)window);
        STRBUF_Delete(label);
        p->categoryWindows[i] = window;
        q += 18;
        x += 10;
    }
    MSGDATA_Delete(bank);
    return q;
}

/*
 * extent: trailing two-byte zero padding
 * lever: signed loop counter; string pointer declared before counter.
 */
u8 *PMSIV_CATEGORY_MakeKanaWindow(struct PmsivCategory *p, u8 *q)
{
    u32 keyCount, font;
    struct BmpWin *window;
    void *label;
    int i;
    int x, y;
    font = (u32)PMS_INPUT_VIEW_GetFont(p->view);
    window = BMP_WIN_Create(1, 1, 8, 30, 14, 12, 1);
    label = STRBUF_Create(4, PMSIV_CATEGORY_HEAP);
    BMP_Clear(BMP_WIN_GetBmp(window), 15);
    keyCount = PMSI_SEARCH_GetKeyCount();
    for (i = 0; i < keyCount; i++) {
        PMSI_SEARCH_GetKeyLabel(i, label);
        PMSI_SEARCH_GetKeyPosition(i, &x, &y);
        GF_FONT_SetTextColor(1, 2, 15);
        PRINTSYS_Print(BMP_WIN_GetBmp(window), x + 5, y, label, (void *)font);
    }
    BMP_WIN_TransferChars((struct BmpWin *)window);
    STRBUF_Delete(label);
    p->kanaWindow = window;
    return q + 0x1a4;
}

u8 *PMSIV_CATEGORY_MakeTitleWindow(struct PmsivCategory *p, u8 *q)
{
    struct BmpWin *window;
    window = BMP_WIN_Create(1, 10, 3, 11, 2, 12, 1);
    BMP_Clear(BMP_WIN_GetBmp(window), 1);
    BMP_WIN_TransferChars((struct BmpWin *)window);
    p->titleWindow = window;
    return q + 0x16;
}

void PMSIV_CATEGORY_MakeListWindow(struct PmsivCategory *p)
{
    struct BmpWin *window;
    window = BMP_WIN_Create(6, 1, 1, 30, 22, 0, 1);
    BMP_WIN_MakeScreen((struct BmpWin *)window);
    BG_SYS_PushTile(6);
    BG_SYS_ChangeScrollImmediate(6, 3, -192);
    p->listWindow = window;
}

void PMSIV_CATEGORY_CreateCursor(struct PmsivCategory *p)
{
    struct PmsInputViewSpriteRes setup;
    PMS_INPUT_VIEW_GetUiRes(p->view, &setup, 0, 0);
    p->cursorActor = PMS_INPUT_VIEW_CreateActor(p->view, &setup, 48, 64, 3, 1);
    CLACT_SetActorAnimSeq((struct ClactActor *)p->cursorActor, 4);
    CLACT_SetActorDrawEnable((struct ClactActor *)p->cursorActor, 0);
}

/*
 * extent: two bytes of zero alignment padding after the return.
 */
void PMSIV_CATEGORY_SetCursorVisible(struct PmsivCategory *p, int enable)
{
    if (enable) {
        if (*p->modeFlag == 0) {
            CLACT_SetActorDrawEnable((struct ClactActor *)p->cursorActor, 1);
            if (PMS_INPUT_GetBrowseMode((PmsInput *)p->input) == 0) {
                CLACT_SetActorAnimSeq((struct ClactActor *)p->cursorActor, 4);
            } else {
                CLACT_SetActorAnimSeq((struct ClactActor *)p->cursorActor, 6);
            }
        } else {
            CLACT_SetActorDrawEnable((struct ClactActor *)p->cursorActor, 0);
        }
    } else {
        CLACT_SetActorDrawEnable((struct ClactActor *)p->cursorActor, 0);
    }
}

/*
 * lever: ordered if/else chain, not switch dispatch; template word is 0x012C0190.
 */
void PMSIV_CATEGORY_MoveCursor(struct PmsivCategory *p, unsigned index)
{
    PmsivCategoryScreenPos pos;
    int x, y;
    int animation;
    u8 *kanaCursor;
    pos = sPmsivCategoryCursorOrigin;
    if (PMS_INPUT_GetBrowseMode((struct PmsInput *)p->input) == 0 && index != PMSIV_CATEGORY_CURSOR_NONE) {
        pos.x = 48 + 80 * (index % 3U);
        pos.y = 64 + 24 * (index / 3U);
        animation = 4;
    } else {
        kanaCursor = (unsigned char *)PMS_INPUT_VIEW_GetMenu(p->view);
        animation = 16;
        if (index == 252) {
            if (*p->modeFlag == 0) PMSIV_MENU_SetActiveEntry((struct PmsivMenu *)kanaCursor, 0, 1);
            else PMSIV_MENU_SetActiveEntry((struct PmsivMenu *)kanaCursor, 0, 0);
        } else if (index == 253) {
            if (*p->modeFlag == 0) PMSIV_MENU_SetActiveEntry((struct PmsivMenu *)kanaCursor, 1, 1);
            else PMSIV_MENU_SetActiveEntry((struct PmsivMenu *)kanaCursor, 0, 0);
        } else if (index == PMSIV_CATEGORY_CURSOR_NONE) {
            if (*p->modeFlag == 0) PMSIV_MENU_SetActiveEntry((struct PmsivMenu *)kanaCursor, 2, 1);
            else PMSIV_MENU_SetActiveEntry((struct PmsivMenu *)kanaCursor, 0, 0);
        } else {
            PMSIV_MENU_SetActiveEntry((struct PmsivMenu *)kanaCursor, 0, 0);
            PMSI_SEARCH_GetKeyPosition(index, &x, &y);
            pos.x = x + 18;
            pos.y = y + 56;
            animation = 6;
        }
    }
    CLACT_AddActorSurfacePos((struct ClactActor *)p->cursorActor, (const struct ClactVec2 *)&pos, 0);
    CLACT_SetActorAnimSeq((struct ClactActor *)p->cursorActor, animation);
}

void PMSIV_CATEGORY_StartFadeIn(struct PmsivCategory *p)
{
    p->fadeState = 0;
    PMSIV_FADE_StartBrightness(&p->fade, 2, -10, 0, 16);
}

int PMSIV_CATEGORY_IsFadeInDone(struct PmsivCategory *p)
{
    if (p->fadeState == 0 && PMSIV_FADE_IsBrightnessDone(&p->fade) != 0) return 1;
    return 0;
}

/*
 * extent: two bytes of zero alignment padding after return.
 */
void PMSIV_CATEGORY_StartClose(struct PmsivCategory *p)
{
    p->fadeState = 0;
    PMSIV_BGSCROLL_Start(&p->scroll, 1, 1, 0, 6);
}

/*
 * extent: includes the unlabelled tail-call stub at 0x021BB804.
 */
int PMSIV_CATEGORY_StepClose(struct PmsivCategory *p)
{
    switch (p->fadeState) {
    case 0:
        if (PMSIV_BGSCROLL_Step(&p->scroll)) {
            PMSIV_FADE_StartBrightness(&p->fade, 2, 0, -10, 16);
            ++p->fadeState;
        }
        break;
    case 1:
        return PMSIV_FADE_IsBrightnessDone(&p->fade);
    }
    return 0;
}

void PMSIV_CATEGORY_ResetBgScroll(struct PmsivCategory *p)
{
    BG_SYS_ChangeScrollImmediate(1, 3, 16);
}

/*
 * extent: two-byte alignment padding then existing PMSIV_CATEGORY_IsFadeOutDone.c follower.
 */
void PMSIV_CATEGORY_StartFadeOut(struct PmsivCategory *p)
{
    PMSIV_FADE_StartBrightness(&p->fade, 2, 0, -10, 16);
}

int PMSIV_CATEGORY_IsFadeOutDone(struct PmsivCategory *p)
{
    return PMSIV_FADE_IsBrightnessDone(&p->fade);
}

void PMSIV_CATEGORY_StartBlendOut(struct PmsivCategory *p)
{
    PMSIV_FADE_StartBlend(&p->fade, 2, 63, 124, 0, 12);
}

int PMSIV_CATEGORY_IsBlendOutDone(struct PmsivCategory *p)
{
    if (PMSIV_FADE_IsBlendDone(&p->fade) != 0) {
        BG_SYS_SetPlaneVisible(1, 0);
        return 1;
    }
    return 0;
}

/*
 * extent: includes the unlabelled forwarding stub at 0x021BB8AC.
 */
void PMSIV_CATEGORY_StartBlendIn(struct PmsivCategory *p)
{
    G2x_SetBlendAlpha_((void *)0x04000050, 2, 63, 0, 16);
    BG_SYS_SetPlaneVisible(1, 1);
    PMSIV_FADE_StartBlend(&p->fade, 2, 63, 0, 124, 12);
}

int PMSIV_CATEGORY_IsBlendInDone(struct PmsivCategory *p)
{
    return PMSIV_FADE_IsBlendDone(&p->fade);
}

void PMSIV_CATEGORY_ApplyBgOffset(struct PmsivCategory *p)
{
    int offset;
    if (PMS_INPUT_GetBrowseMode((struct PmsInput *)p->input) == 0) offset = -4;
    else offset = 0;
    BG_SYS_ChangeScroll(1, 0, offset);
}

void PMSIV_CATEGORY_RefreshScreens(struct PmsivCategory *p)
{
    void *handle;
    int i;
    handle = ARC_TOOL_CreateHandle(43, PMSIV_CATEGORY_HEAP);
    if (PMS_INPUT_GetBrowseMode((struct PmsInput *)p->input) == 0) {
        ARC_UTIL_UploadBgPaletteAddFromHandleExt(handle, 27, 1, 0, 0, 0, 0, PMSIV_CATEGORY_HEAP);
        for (i = 0; i < PMSIV_CATEGORY_COUNT; i++) BMP_WIN_MakeScreen((struct BmpWin *)p->categoryWindows[i]);
    } else {
        ARC_UTIL_UploadBgPaletteAddFromHandleExt(handle, 26, 1, 0, 0, 0, 0, PMSIV_CATEGORY_HEAP);
        BMP_WIN_MakeScreen((struct BmpWin *)p->kanaWindow);
        BMP_WIN_MakeScreen((struct BmpWin *)p->titleWindow);
    }
    ARC_TOOL_DeleteHandle(handle);
    BG_SYS_MarkTileDirty(1);
}

int PMSIV_CATEGORY_IsReady(struct PmsivCategory *p)
{
    return 1;
}

void PMSIV_CATEGORY_DrawTitle(struct PmsivCategory *p)
{
    u32 font = (u32)PMS_INPUT_VIEW_GetFont(p->view);
    struct BmpWin *window = p->titleWindow;
    void *title = STRBUF_Create(14, PMSIV_CATEGORY_HEAP);
    PMS_INPUT_SetSearchArg((struct PmsInput *)p->input, title);
    BMP_Clear(BMP_WIN_GetBmp(window), 1);
    GF_FONT_SetTextColor(15, 14, 1);
    PRINTSYS_Print(BMP_WIN_GetBmp(window), 0, 0, title, (void *)font);
    STRBUF_Delete(title);
    BMP_WIN_MakeScreen((struct BmpWin *)window);
    BMP_WIN_TransferChars((struct BmpWin *)window);
    BG_SYS_MarkTileDirty(1);
}

/*
 * prototype-evidence: the legacy source of PMS_INPUT_GetInitialCount says void; this caller reads r0
 * at 0x021BB9CC/0x021BB9CE, so its observed unsigned result is retained.
 */
void PMSIV_CATEGORY_ShowWordList(struct PmsivCategory *p, int flag)
{
    u32 count = PMS_INPUT_GetInitialCount((struct PmsInput *)p->input);
    if (count > 22) count = 22;
    if (flag) PMSIV_CATEGORY_DrawWordList(p, count);
    else PMSIV_CATEGORY_StartListScrollOut(p, count);
}

/*
 * extent: two bytes of zero alignment padding after return.
 * lever: bind the step arithmetic to a local before the outer call; the
 * inline argument form adds a saved register and changes scheduling.
 */
void PMSIV_CATEGORY_StartListScrollOut(struct PmsivCategory *p, u32 unused)
{
    int step = -192 - BG_SYS_GetScrollY(6);
    PMSIV_BGSCROLL_Start(&p->scroll, 6, 1, step, 8);
}

void PMSIV_CATEGORY_DrawWordList(struct PmsivCategory *p, unsigned count)
{
    u32 printQue, font;
    void *word;
    int i, x, height, base;
    printQue = (unsigned int)PMS_INPUT_VIEW_GetPrintQue(p->view);
    font = (u32)PMS_INPUT_VIEW_GetFont(p->view);
    word = STRBUF_Create(15, PMSIV_CATEGORY_HEAP);
    BMP_Clear(BMP_WIN_GetBmp(p->listWindow), 15);
    p->printWindow = p->listWindow;
    p->printPending = 0;
    for (i = 0; i < count; i++) {
        if (i % 2 == 0) x = 8;
        else x = 128;
        PMS_INPUT_GetInitialWord((struct PmsInput *)p->input, i, (int)word);
        PRINTSYS_PrintQueColor((void *)printQue, BMP_WIN_GetBmp(p->printWindow), (short)x, (short)((i / 2) * 16), word, (struct GfFont *)font, 1103);
        p->printPending = 1;
    }
    STRBUF_Delete(word);
    base = BG_SYS_GetScrollY(6) + 192;
    height = ((count + 1) / 2) * 16 + 8;
    if (height > 192) height = 192;
    else if (height < 48) height = 48;
    PMSIV_BGSCROLL_Start(&p->scroll, 6, 1, height - base, 8);
    BMP_WIN_MakeScreen((struct BmpWin *)p->listWindow);
    BG_SYS_MarkTileDirty(6);
    BG_SYS_SetPlaneVisible(6, 1);
}

int PMSIV_CATEGORY_IsListReady(struct PmsivCategory *p, int waitForPrint)
{
    unsigned printQue;
    int printDone;
    int scrollDone;
    printQue = (unsigned int)PMS_INPUT_VIEW_GetPrintQue(p->view);
    printDone = 1;
    if (waitForPrint) {
        if (p->printPending) {
            if (PRINTSYS_QUE_IsExistTarget((struct PrintQueue *)printQue, (void *)((unsigned)BMP_WIN_GetBmp(p->printWindow))) == 0) {
                BMP_WIN_TransferChars((struct BmpWin *)p->printWindow);
                p->printPending = 0;
            }
        }
        printDone = p->printPending == 0 ? 1 : 0;
    }
    scrollDone = PMSIV_BGSCROLL_Step(&p->scroll);
    if (printDone && scrollDone) {
        if (waitForPrint == 0) BG_SYS_SetPlaneVisible(6, 0);
        return 1;
    }
    return 0;
}

void PMSIV_CATEGORY_StartSelectAnim(struct PmsivCategory *p, unsigned index)
{
    PmsivCategoryScreenPos pos;
    int x, y;
    int animation;
    p->savedCursorVisible = CLACT_GetActorDrawEnable((struct ClactActor *)p->cursorActor);
    CLACT_SetActorDrawEnable((struct ClactActor *)p->cursorActor, 1);
    if (PMS_INPUT_GetBrowseMode((struct PmsInput *)p->input) == 0 && index != PMSIV_CATEGORY_CURSOR_NONE) {
        pos.x = 48 + 80 * (index % 3U);
        pos.y = 64 + 24 * (index / 3U);
        animation = 31;
    } else {
        animation = 16;
        switch (index) {
        case 252: case 253: case 254: break;
        default:
            PMSI_SEARCH_GetKeyPosition(index, &x, &y);
            pos.x = x + 18;
            pos.y = y + 56;
            animation = 30;
            break;
        }
    }
    CLACT_AddActorSurfacePos((struct ClactActor *)p->cursorActor, (const struct ClactVec2 *)&pos, 0);
    CLACT_SetActorAnimSeq((struct ClactActor *)p->cursorActor, animation);
}

int PMSIV_CATEGORY_IsSelectAnimDone(struct PmsivCategory *p)
{
    u16 animation = CLACT_GetActorAnimSeq((struct ClactActor *)p->cursorActor);
    if (animation != 31 && animation != 30) return 1;
    if (CLACT_IsActorAnimActive((struct ClactActor *)p->cursorActor) == 0) {
        CLACT_SetActorDrawEnable((struct ClactActor *)p->cursorActor, p->savedCursorVisible);
        CLACT_SetActorAnimSeq((struct ClactActor *)p->cursorActor, PMS_INPUT_GetBrowseMode((PmsInput *)p->input) == 0 ? 4 : 6);
        p->savedCursorVisible = 0;
        return 1;
    }
    return 0;
}

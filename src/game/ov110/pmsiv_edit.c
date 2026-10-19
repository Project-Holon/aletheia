/*
 * file:     pmsiv_edit.c
 * unit:     yes
 * function: PMSIV_EDIT_Create, PMSIV_EDIT_Delete, PMSIV_EDIT_Setup, GX_GetVCount, PMSIV_EDIT_UpdateFramePosition, PMSIV_EDIT_StartPanelScroll, PMSIV_EDIT_StepPanelScroll, PMSIV_EDIT_LoadPalette, PMSIV_EDIT_ApplyPalette, PMSIV_EDIT_InitSlotPositions, PMSIV_EDIT_CreateWordIcons, PMSIV_EDIT_CreateCursors, PMSIV_EDIT_Redraw, PMSIV_EDIT_GetSlotRect, PMSIV_EDIT_DrawFreeText, PMSIV_EDIT_ParserInit, PMSIV_EDIT_ParserFree, PMSIV_EDIT_ParserNext, PMSIV_EDIT_SlotPosToBoxOrigin, PMSIV_EDIT_BoxOriginToSlotPos, PMSIV_EDIT_ClearSlotBox, PMSIV_EDIT_DrawSlotWord, PMSIV_EDIT_SetCursorPressed, PMSIV_EDIT_IsSubScreenLayer, PMSIV_EDIT_GetSlotCount, PMSIV_EDIT_GetSlotWordId, PMSIV_EDIT_ReleaseCursor, PMSIV_EDIT_PressCursor, PMSIV_EDIT_SetCursorsVisible, PMSIV_EDIT_NoopA, PMSIV_EDIT_NoopB, PMSIV_EDIT_PlaceCursorAtSlot, PMSIV_BGSCROLL_Start, PMSIV_BGSCROLL_Step, PMSIV_BGSCROLL_Task, PMSIV_FADE_StartBlend, PMSIV_FADE_IsBlendDone, PMSIV_FADE_BlendTask, PMSIV_FADE_StartBrightness, PMSIV_FADE_IsBrightnessDone, PMSIV_FADE_BrightnessTask
 * address:  0x021BBC5C
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Message editor panel of the easy-chat input screen: the sentence being composed on both screens, word slots, free-text parser, panel scroll and the screen fade helpers.
 *
 * symbols:
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   PMS_INPUT_GetUiInputModePtr 0x021BF6D4 thumb ov110
 *   TCB_DeleteTask 0x02030EAC arm
 *   PMSIV_EDIT_Create 0x021BBC5C thumb ov110
 *   PMSIV_EDIT_Setup 0x021BBD60 thumb ov110
 *   ARC_UTIL_UploadBgPaletteFromHandle 0x020498F4 arm
 *   ARC_UTIL_UploadBgCharFromHandle 0x02049658 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   PMS_INPUT_GetInputMode 0x021BF6D8 thumb ov110
 *   BMP_WIN_Delete 0x020452E8 arm
 *   PMSIV_EDIT_Delete 0x021BBCF0 thumb ov110
 *   PMSIV_EDIT_Redraw 0x021BC23C thumb ov110
 *   PMSIV_EDIT_PlaceCursorAtSlot 0x021BC72C thumb ov110
 *   PMSIV_EDIT_SetCursorsVisible 0x021BC704 thumb ov110
 *   PMSIV_EDIT_NoopA 0x021BC724 thumb ov110
 *   PMSIV_EDIT_NoopB 0x021BC728 thumb ov110
 *   PMSIV_EDIT_ReleaseCursor 0x021BC6EC thumb ov110
 *   PMSIV_EDIT_StartPanelScroll 0x021BBEF4 thumb ov110
 *   PMSIV_EDIT_StepPanelScroll 0x021BBF54 thumb ov110
 *   PMSIV_EDIT_PressCursor 0x021BC6F8 thumb ov110
 *   PMSIV_EDIT_GetSlotCount  0x021BC6DC  thumb  ov110
 *   PMSIV_EDIT_GetSlotWordId  0x021BC6E0  thumb  ov110
 *   PMSIV_EDIT_GetSlotRect  0x021BC320  thumb  ov110
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   STRBUF_Delete 0x02045808 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   BG_SYS_SetFlagField06 0x02041B6C arm
 *   STRBUF_Create 0x020457B0 arm
 *   STRBUF_SetStringN 0x02045994 arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   BG_SYS_FillScrollArea 0x02040618 arm
 *   G2x_SetBlendBrightness_ 0x0207D658 arm
 *   PMS_INPUT_VIEW_GetFont 0x021BAC44 thumb ov110
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   GF_FONT_MeasureWidestLine 0x0201D304 thumb
 *   PRINTSYS_Print 0x0201C7A4 thumb
 *   PMS_INPUT_VIEW_GetUiRes 0x021BAC64 thumb ov110
 *   PMS_INPUT_VIEW_CreateActor 0x021BAC78 thumb ov110
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   PMSIV_FADE_StartBrightness 0x021BC8FC thumb ov110
 *   PMSIV_FADE_IsBrightnessDone 0x021BC93C thumb ov110
 *   PMSIV_BGSCROLL_Start 0x021BC78C thumb ov110
 *   PMSIV_BGSCROLL_Step 0x021BC7DC thumb ov110
 *   PMSIV_FADE_StartBlend 0x021BC868 thumb ov110
 *   PMSIV_FADE_IsBlendDone 0x021BC898 thumb ov110
 *   G2x_SetBlendAlpha_ 0x0207D63C arm
 *   sPmsivEditAllocSite 0x021C3C58 data a1
 *   BMP_CURSOR_Create 0x02020D18 thumb
 *   BGWINFRM_Create 0x0202C9B4 thumb
 *   BGWINFRM_Delete 0x0202CA0C thumb
 *   BMP_CURSOR_Delete 0x02020D3C thumb
 *   PMSIV_EDIT_LoadPalette 0x021BC068 thumb ov110
 *   PMSIV_EDIT_InitSlotPositions 0x021BC120 thumb ov110
 *   PMSIV_EDIT_CreateWordIcons 0x021BC160 thumb ov110
 *   PMSIV_EDIT_CreateCursors 0x021BC1B8 thumb ov110
 *   BGWINFRM_AddFrame 0x0202CA3C thumb
 *   BGWINFRM_SetFrameDataArcHandle 0x0202CB18 thumb
 *   BGWINFRM_PutFrame 0x0202CB4C thumb
 *   BGWINFRM_PutBmpWin 0x0202CEBC thumb
 *   BGWINFRM_ShowFrame 0x0202CC58 thumb
 *   BG_SYS_SetTileEntry 0x02041300 arm
 *   GFL_USE_AddHBlankTask 0x02005624 thumb
 *   GFL_USE_AddMainTask 0x020056A0 thumb
 *   GX_GetVCount 0x021BBE80 thumb ov110
 *   CLACT_GetActorSurfacePosAxis 0x0204B4EC arm
 *   CLACT_SetActorSurfacePosAxis 0x0204B49C arm
 *   ARC_UTIL_UploadPaletteFromHandleWhole 0x02049B68 arm
 *   ARC_UTIL_LoadPaletteBlockFromHandle 0x02049F78 arm
 *   MIi_CpuCopy16 0x02082A60 arm
 *   DC_FlushRange 0x020862F0 arm
 *   PMS_INPUT_GetSentenceType 0x021BF6E4 thumb ov110
 *   GX_LoadBGPltt 0x0207E3D0 arm
 *   GXS_LoadBGPltt 0x0207E468 arm
 *   PMS_INPUT_VIEW_GetCursorRes 0x021BAC50 thumb ov110
 *   CLACT_SetActorBgPriority 0x0204B84C arm
 *   PMS_INPUT_GetWord 0x021BF6F0 thumb ov110
 *   PMS_INPUT_GetSentenceString 0x021BF708 thumb ov110
 *   STRBUF_GetChars 0x02045A90 arm
 *   GF_FONT_GetTagParam 0x0201D670 thumb
 *   GF_FONT_SkipTag 0x0201D688 thumb
 *   BMP_FillRect 0x02043AF4 arm
 *   PMSI_PARAM_IsDecoWord 0x02024508 thumb
 *   PMSI_PARAM_GetDecoId 0x02024520 thumb
 *   BMP_WIN_GetPosX 0x02045758 arm
 *   BMP_WIN_GetPosY 0x02045760 arm
 *   BG_SYS_Get 0x020416D4 arm
 *   PMS_WORD_LoadString 0x02024838 thumb
 *   BG_SYS_GetChannelScrollX 0x02041648 arm
 *   BG_SYS_GetChannelScrollY 0x02041664 arm
 *   PMS_INPUT_VIEW_AddVBlankTask 0x021B9BA4 thumb ov110
 *   _s32_div_f 0x0209C0A4 arm
 */
#include "pms_input_data_shared_types.h"
#include "pms_input_view_shared_types.h"
#include "pmsi_search_shared_types.h"
#include "pmsiv_category_shared_types.h"
#include "pmsiv_edit_shared_types.h"

#define PMSIV_EDIT_HEAP 42
#define PMSIV_EDIT_SLOT_COUNT 2
#define PMSIV_EDIT_SCREEN_COUNT 2
#define PMSIV_EDIT_PALETTE_BYTES 320
#define PMSIV_EDIT_SCROLL_FRAMES 6

enum {
    PMSIV_EDIT_MODE_SINGLE = 0,
    PMSIV_EDIT_MODE_DOUBLE = 1,
    PMSIV_EDIT_MODE_FREE_TEXT = 2,
};

enum {
    PMSIV_EDIT_TOKEN_TEXT = 0,
    PMSIV_EDIT_TOKEN_SLOT = 1,
    PMSIV_EDIT_TOKEN_NEWLINE = 2,
    PMSIV_EDIT_TOKEN_END = 3,
};

#define PMSIV_EDIT_CHAR_SLOT 0xf000
#define PMSIV_EDIT_CHAR_NEWLINE 0xfffe
#define PMSIV_EDIT_CHAR_END 0xffff

typedef struct { short x, y; } ScreenPos;

struct ActorSetup {
    int words[3];
};

/* Unpacked palette resource: the raw colors sit at +0xC. */
struct PaletteData {
    u32 format;
    u32 isExtended;
    u32 sizeBytes;
    void *rawData;
};

/* Splits a sentence template into text runs, word slots and line breaks. */
struct PmsivTextParser {
    struct U16Vec *text;
    u16 *cursor;
    u32 state;
    u16 slotWordId;
};

struct PmsivEdit {
    struct PmsInputView *view;
    struct PmsInputState *input;
    void *param;
    struct Descriptor *windows[PMSIV_EDIT_SCREEN_COUNT];
    struct Obj *cursors[PMSIV_EDIT_SCREEN_COUNT];
    struct Obj *wordIcons[PMSIV_EDIT_SLOT_COUNT][PMSIV_EDIT_SCREEN_COUNT];
    struct MsgBank *messageBank;
    struct U16Vec *text;
    void *bmpCursor;
    ScreenPos slotPos[PMSIV_EDIT_SLOT_COUNT];
    u16 slotWordId[PMSIV_EDIT_SLOT_COUNT];
    int slotCount;
    struct PmsivTextParser parser;
    u8 palette[PMSIV_EDIT_PALETTE_BYTES];
    short scrollOffset;
    short bgOffset;
    u8 scrollStep;
    u8 scrollClosing;
    int *modeFlag;
    void *scrollTask;
    int unusedWord1A8;
    int unusedWord1AC;
    void *frameTask;
    struct WinMgr *frameMgr;
    int frameDirty;
};

typedef volatile unsigned short vu16;

struct WinMgr;

extern u32 GFL_HEAP_Free(void *p);
extern int *PMS_INPUT_GetUiInputModePtr(struct PmsInputState *input);
extern void TCB_DeleteTask(struct Node *n);
extern void ARC_UTIL_UploadBgPaletteFromHandle(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern u32 ARC_UTIL_UploadBgCharFromHandle(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern struct MsgBank *MSGDATA_CreateFromArchive(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 MSGDATA_Delete(struct MsgBank *bank);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *);
extern void BG_SYS_SetFlagField06(unsigned);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void *GFL_HEAP_Alloc(u32, u32, int, const char *, u16);
extern void CLACT_DeleteActor(struct Obj *p);
extern unsigned int BMP_WIN_Delete(struct Descriptor *d);
extern void BG_SYS_FillScrollArea(u32, u32, u32);
extern u32 PMS_INPUT_VIEW_GetFont(struct PmsInputView *view);
extern struct Descriptor *BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern u32 GF_FONT_MeasureWidestLine(struct StrObj *s, u32 a, u32 b);
extern void BMP_WIN_MakeScreen(struct Descriptor *window);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void PMS_INPUT_VIEW_GetUiRes(struct PmsInputView *, struct ActorSetup *, int, int);
extern void G2x_SetBlendAlpha_(void *, int, int, int, int);
extern void *BMP_CURSOR_Create(unsigned);
extern struct WinMgr *BGWINFRM_Create(u32 transMode, u32 frameMax, u32 heap);
extern void BGWINFRM_Delete(struct WinMgr *mgr);
extern void BMP_CURSOR_Delete(void *cursor);
extern void BGWINFRM_AddFrame(struct WinMgr *mgr, u32 idx, u32 bg, u32 w, u32 h);
extern void BGWINFRM_SetFrameDataArcHandle(struct WinMgr *mgr, u32 idx, void *arc, u32 member, u32 alloc);
extern void BGWINFRM_PutFrame(struct WinMgr *mgr, u32 idx, s8 x, s8 y);
extern void BGWINFRM_PutBmpWin(struct WinMgr *mgr, u32 idx, void *a);
extern void BGWINFRM_ShowFrame(struct WinMgr *mgr, u32 idx);
extern void BG_SYS_SetTileEntry(unsigned, int, int, int, u8, u8, u8);
extern void *GFL_USE_AddHBlankTask(u32 a, u32 b, u32 c);
extern void *GFL_USE_AddMainTask(void *, void *, unsigned);
extern short CLACT_GetActorSurfacePosAxis(struct Obj *, u16 surface, unsigned axis);
extern void CLACT_SetActorSurfacePosAxis(struct Obj *, short pos, u16 surface, unsigned axis);
extern void ARC_UTIL_UploadPaletteFromHandleWhole(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void *ARC_UTIL_LoadPaletteBlockFromHandle(void *arc, u32 memberIdx, u32 unpackedOut, u32 flags);
extern void MIi_CpuCopy16(const void *, void *, int);
extern void DC_FlushRange(void *, unsigned);
extern unsigned PMS_INPUT_GetInputMode(struct PmsInputState *input);
extern int PMS_INPUT_GetSentenceType(struct PmsInputState *input);
extern void GX_LoadBGPltt(void *, int, int);
extern void GXS_LoadBGPltt(void *, int, int);
extern void PMS_INPUT_VIEW_GetCursorRes(struct PmsInputView *view, struct ActorSetup *out, int i);
extern void *PMS_INPUT_VIEW_CreateActor(struct PmsInputView *view, struct ActorSetup *setup, int x, int y, int a, int mode);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void CLACT_SetActorBgPriority(struct Obj *, int);
extern u32 PMS_INPUT_GetWord(struct PmsInputState *input, u32 i);
extern struct U16Vec *PMS_INPUT_GetSentenceString(struct PmsInputState *input, u32 heap);
extern void GF_FONT_SetTextColor(u32, u32, u32);
extern void PRINTSYS_Print(void *, short, short, void *, void *);
extern u16 *STRBUF_GetChars(struct U16Vec *vec);
extern void STRBUF_SetStringN(struct U16Vec *, const u16 *, u32);
extern u32 GF_FONT_GetTagParam(const u16 *, u32);
extern u16 *GF_FONT_SkipTag(u16 *);
extern void BMP_FillRect(struct Bmp *b, u32 x, u32 y, u32 w, u32 h, u32 value);
extern u32 PMSI_PARAM_IsDecoWord(u32);
extern u32 PMSI_PARAM_GetDecoId(u32);
extern u8 BMP_WIN_GetPosX(struct Descriptor *);
extern u8 BMP_WIN_GetPosY(struct Descriptor *);
extern void CLACT_AddActorSurfacePos(struct Obj *p, const ScreenPos *delta, u32 which);
extern u8 BG_SYS_Get(u32);
extern void PMS_WORD_LoadString(u32, void *, u32);
extern unsigned int BG_SYS_GetChannelScrollX(u8 channel);
extern u32 BG_SYS_GetChannelScrollY(u8 channel);
extern void *PMS_INPUT_VIEW_AddVBlankTask(void (*fn)(void *, void *), void *arg, int priority);
extern int _s32_div_f(int, int);
extern void G2x_SetBlendBrightness_(u32 addr, int plane, int brightness);

struct PmsivEdit *PMSIV_EDIT_Create(struct PmsInputView *view, struct PmsInputState *input, void *param);
void PMSIV_EDIT_LoadPalette(struct PmsivEdit *p, void *arcHandle);
void PMSIV_EDIT_InitSlotPositions(struct PmsivEdit *p);
void PMSIV_EDIT_CreateWordIcons(struct PmsivEdit *p);
void PMSIV_EDIT_CreateCursors(struct PmsivEdit *p);
void PMSIV_EDIT_Redraw(struct PmsivEdit *p);
void PMSIV_EDIT_Delete(struct PmsivEdit *p);
void PMSIV_EDIT_Setup(struct PmsivEdit *p, u32 arcHandle);

extern const char sPmsivEditAllocSite[];

struct PmsivEdit *PMSIV_EDIT_Create(struct PmsInputView *view, struct PmsInputState *input, void *param)
{
    struct PmsivEdit *p;
    p = GFL_HEAP_Alloc(PMSIV_EDIT_HEAP, sizeof(struct PmsivEdit), 1, sPmsivEditAllocSite, 211);
    p->view = view;
    p->input = input;
    p->param = param;
    p->modeFlag = PMS_INPUT_GetUiInputModePtr(input);
    p->cursors[0] = 0;
    p->cursors[1] = 0;
    p->scrollTask = 0;
    p->text = STRBUF_Create(128, PMSIV_EDIT_HEAP);
    p->messageBank = MSGDATA_CreateFromArchive(0, 2, 146, PMSIV_EDIT_HEAP);
    p->bmpCursor = BMP_CURSOR_Create(PMSIV_EDIT_HEAP);
    p->scrollOffset = 0;
    p->bgOffset = 0;
    p->unusedWord1A8 = 0;
    p->unusedWord1AC = 0;
    p->frameTask = 0;
    p->frameMgr = BGWINFRM_Create(1, 1, PMSIV_EDIT_HEAP);
    return p;
}

void PMSIV_EDIT_Delete(struct PmsivEdit *p)
{
    BGWINFRM_Delete(p->frameMgr);
    if (p->frameTask) TCB_DeleteTask(p->frameTask);
    if (p->scrollTask) TCB_DeleteTask(p->scrollTask);
    if (p->bmpCursor) BMP_CURSOR_Delete(p->bmpCursor);
    if (p->cursors[0]) CLACT_DeleteActor(p->cursors[0]);
    if (p->cursors[1]) CLACT_DeleteActor(p->cursors[1]);
    if (p->messageBank) MSGDATA_Delete(p->messageBank);
    if (p->text) STRBUF_Delete(p->text);
    BMP_WIN_Delete(p->windows[0]);
    BMP_WIN_Delete(p->windows[1]);
    GFL_HEAP_Free(p);
}

/*
 * prototype: legacy 02040618 fourth input is unused by its full 02042360 target; caller sets only r0-r2.
 */
void PMSIV_EDIT_Setup(struct PmsivEdit *p, u32 arcHandle)
{
    PMSIV_EDIT_LoadPalette(p, (void *)arcHandle);
    ARC_UTIL_UploadBgPaletteFromHandle((void *)arcHandle, 25, 0, 0, 0, 0, PMSIV_EDIT_HEAP);
    ARC_UTIL_UploadBgPaletteFromHandle((void *)arcHandle, 25, 4, 0, 0, 0, PMSIV_EDIT_HEAP);
    p->bgOffset = -192;
    BG_SYS_FillScrollArea(4, 3, p->bgOffset);
    ARC_UTIL_UploadBgCharFromHandle((void *)arcHandle, 14, 0, 0, 0, 0, PMSIV_EDIT_HEAP);
    ARC_UTIL_UploadBgCharFromHandle((void *)arcHandle, 14, 4, 0, 0, 0, PMSIV_EDIT_HEAP);
    p->windows[0] = BMP_WIN_Create(0, 3, 1, 28, 4, 0, 1);
    p->windows[1] = BMP_WIN_Create(4, 3, 1, 28, 4, 0, 1);
    BMP_WIN_MakeScreen(p->windows[0]);
    BMP_WIN_MakeScreen(p->windows[1]);
    PMSIV_EDIT_InitSlotPositions(p);
    PMSIV_EDIT_CreateWordIcons(p);
    PMSIV_EDIT_Redraw(p);
    PMSIV_EDIT_CreateCursors(p);
    BGWINFRM_AddFrame(p->frameMgr, 0, 0, 32, 6);
    BGWINFRM_SetFrameDataArcHandle(p->frameMgr, 0, (void *)arcHandle, 25, 0);
    BGWINFRM_PutFrame(p->frameMgr, 0, 0, 0);
    BGWINFRM_PutBmpWin(p->frameMgr, 0, p->windows[0]);
    BGWINFRM_ShowFrame(p->frameMgr, 0);
    p->frameDirty = 0;
}

vu16 GX_GetVCount(void)
{
    return *(vu16 *)0x04000006;
}

struct Cursor;

void PMSIV_EDIT_UpdateFramePosition(void *task, struct PmsivEdit *p);
void PMSIV_EDIT_StartPanelScroll(struct PmsivEdit *p, u8 closing);
int PMSIV_EDIT_StepPanelScroll(struct PmsivEdit *p);
void PMSIV_EDIT_ApplyPalette(struct PmsivEdit *p);
void PMSIV_EDIT_GetSlotRect(struct PmsivEdit *p, unsigned char *rect, int slot);
int PMSIV_EDIT_DrawFreeText(struct PmsivEdit *p, struct Descriptor *window, u8 screen);
void PMSIV_EDIT_ParserInit(struct PmsivTextParser *parser, struct PmsivEdit *p);
void PMSIV_EDIT_ParserFree(struct PmsivTextParser *parser);
int PMSIV_EDIT_ParserNext(struct PmsivTextParser *parser, struct U16Vec *out);
void PMSIV_EDIT_SlotPosToBoxOrigin(const short *pos, short *boxOrigin);
void PMSIV_EDIT_BoxOriginToSlotPos(const short *boxOrigin, short *pos);
void PMSIV_EDIT_ClearSlotBox(struct Descriptor *window, const ScreenPos *pos);
void PMSIV_EDIT_DrawSlotWord(struct PmsivEdit *p, struct Descriptor *window, const ScreenPos *pos, u32 wordId, struct Obj *icon);
void PMSIV_EDIT_SetCursorPressed(struct PmsivEdit *p, int pressed);
u32 PMSIV_EDIT_IsSubScreenLayer(u32 layer);
unsigned int PMSIV_EDIT_GetSlotCount(struct PmsivEdit *p);
u16 PMSIV_EDIT_GetSlotWordId(struct PmsivEdit *p, int slot);
void PMSIV_EDIT_ReleaseCursor(struct PmsivEdit *p);
void PMSIV_EDIT_PressCursor(struct PmsivEdit *p);
void PMSIV_EDIT_SetCursorsVisible(struct PmsivEdit *p, u32 visible);
void PMSIV_EDIT_NoopA(struct PmsivEdit *p);
void PMSIV_EDIT_NoopB(struct PmsivEdit *p);
void PMSIV_EDIT_PlaceCursorAtSlot(struct PmsivEdit *p, int slot);
void PMSIV_BGSCROLL_Start(struct PmsivBgScroll *scroll, int layer, int axis, int step, int frames);
int PMSIV_BGSCROLL_Step(struct PmsivBgScroll *scroll);
void PMSIV_BGSCROLL_Task(void *task, void *arg);
void PMSIV_FADE_StartBlend(struct PmsivFade *fade, int firstPlanes, int secondPlanes, int start, int end, int frames);
int PMSIV_FADE_IsBlendDone(struct PmsivFade *fade);
void PMSIV_FADE_BlendTask(void *task, void *arg);
void PMSIV_FADE_StartBrightness(struct PmsivFade *fade, int plane, int start, int end, int frames);
int PMSIV_FADE_IsBrightnessDone(struct PmsivFade *fade);
void PMSIV_FADE_BrightnessTask(void *task, void *arg);

void PMSIV_EDIT_UpdateFramePosition(void *task, struct PmsivEdit *p)
{
    p->unusedWord1A8 = 0;
    p->unusedWord1AC = 0;
    if (p->frameDirty) {
        BG_SYS_SetTileEntry(0, 0, 0, 0, 32, 6, 17);
        BGWINFRM_PutFrame(p->frameMgr, 0, 0, (s8)(-p->scrollOffset / 8));
        BGWINFRM_ShowFrame(p->frameMgr, 0);
        p->frameDirty = 0;
    }
}

void PMSIV_EDIT_StartPanelScroll(struct PmsivEdit *p, u8 closing)
{
    p->scrollStep = 0;
    p->scrollClosing = closing;
    if (p->scrollTask) TCB_DeleteTask(p->scrollTask);
    p->scrollTask = GFL_USE_AddHBlankTask((u32)GX_GetVCount, (u32)p, 1);
    p->unusedWord1A8 = 0;
    p->unusedWord1AC = 0;
    if (p->frameTask) TCB_DeleteTask(p->frameTask);
    p->frameTask = GFL_USE_AddMainTask(PMSIV_EDIT_UpdateFramePosition, p, 1);
}

/*
 * lever: plain signed-halfword assignments and named coordinate results.
 * prototype: original call truncates space to u16; legacy 02040618 fourth input is unused by 02042360.
 */
int PMSIV_EDIT_StepPanelScroll(struct PmsivEdit *p)
{
    int delta, i, j;
    if (p->scrollStep > 5) return 1;
    if (p->scrollClosing) delta = -8;
    else delta = 8;
    p->bgOffset = p->bgOffset + delta;
    p->scrollOffset = p->scrollOffset + delta;
    BG_SYS_FillScrollArea(4, 3, p->bgOffset);
    for (i = 0; i < PMSIV_EDIT_SCREEN_COUNT; i++) {
        short pos = CLACT_GetActorSurfacePosAxis(p->cursors[i], i, 1) - delta;
        CLACT_SetActorSurfacePosAxis(p->cursors[i], pos, i, 1);
        for (j = 0; j < PMSIV_EDIT_SLOT_COUNT; j++) {
            short pos = CLACT_GetActorSurfacePosAxis(p->wordIcons[j][i], i, 1) - delta;
            CLACT_SetActorSurfacePosAxis(p->wordIcons[j][i], pos, i, 1);
        }
    }
    p->scrollStep++;
    if (p->scrollClosing && p->scrollStep == 7) {
        TCB_DeleteTask(p->scrollTask);
        p->scrollTask = 0;
        TCB_DeleteTask(p->frameTask);
        p->frameTask = 0;
    }
    p->frameDirty = 1;
    return 0;
}

/*
 * extent: two bytes of zero alignment padding after the return.
 */
void PMSIV_EDIT_LoadPalette(struct PmsivEdit *p, void *arcHandle)
{
    struct PaletteData *data;
    void *handle;
    ARC_UTIL_UploadPaletteFromHandleWhole(arcHandle, 3, 0, 0, 448, PMSIV_EDIT_HEAP);
    ARC_UTIL_UploadPaletteFromHandleWhole(arcHandle, 4, 4, 0, 160, PMSIV_EDIT_HEAP);
    handle = ARC_UTIL_LoadPaletteBlockFromHandle(arcHandle, 6, (u32)((void **)&data), PMSIV_EDIT_HEAP);
    MIi_CpuCopy16(data->rawData, p->palette, PMSIV_EDIT_PALETTE_BYTES);
    DC_FlushRange(p->palette, PMSIV_EDIT_PALETTE_BYTES);
    GFL_HEAP_Free(handle);
}

void PMSIV_EDIT_ApplyPalette(struct PmsivEdit *p)
{
    if (PMS_INPUT_GetInputMode(p->input) == PMSIV_EDIT_MODE_FREE_TEXT && (unsigned)PMS_INPUT_GetSentenceType(p->input) < 5) {
        unsigned n = (unsigned)PMS_INPUT_GetSentenceType(p->input) + 1;
        GX_LoadBGPltt(p->palette + n * 32, 0, 32);
        GXS_LoadBGPltt(p->palette + n * 32, 0, 32);
    } else {
        GX_LoadBGPltt(p->palette, 0, 32);
        GXS_LoadBGPltt(p->palette, 0, 32);
    }
}

void PMSIV_EDIT_InitSlotPositions(struct PmsivEdit *p)
{
    switch (PMS_INPUT_GetInputMode(p->input)) {
    case PMSIV_EDIT_MODE_SINGLE: p->slotPos[0].x = 104; p->slotPos[0].y = 16; p->slotCount = 1; break;
    case PMSIV_EDIT_MODE_DOUBLE: p->slotPos[0].x = 48; p->slotPos[0].y = 16; p->slotPos[1].x = 160; p->slotPos[1].y = 16; p->slotCount = 2; break;
    case PMSIV_EDIT_MODE_FREE_TEXT: p->slotCount = 0; break;
    }
}

void PMSIV_EDIT_CreateWordIcons(struct PmsivEdit *p)
{
    struct ActorSetup setup;
    int i, j;
    for (i = 0; i < PMSIV_EDIT_SCREEN_COUNT; i++) {
        PMS_INPUT_VIEW_GetCursorRes(p->view, &setup, i);
        for (j = 0; j < PMSIV_EDIT_SLOT_COUNT; j++) {
            p->wordIcons[j][i] = PMS_INPUT_VIEW_CreateActor(p->view, &setup, (int)0, (int)0, (int)2, i + 1);
            CLACT_SetActorDrawEnable(p->wordIcons[j][i], 0);
        }
    }
}

/*
 * extent: two bytes zero alignment padding after return.
 * lever: coordinate arguments are int; the callee stores low halfwords
 * without caller-side narrowing, including y+192.
 */
void PMSIV_EDIT_CreateCursors(struct PmsivEdit *p)
{
    struct ActorSetup setup;
    ScreenPos pos;
    if (p->slotCount) PMSIV_EDIT_BoxOriginToSlotPos((short *)&p->slotPos[0], (short *)&pos);
    else { pos.x = 128; pos.y = 24; }
    PMS_INPUT_VIEW_GetUiRes(p->view, &setup, 1, 0);
    p->cursors[1] = PMS_INPUT_VIEW_CreateActor(p->view, &setup, pos.x, pos.y + 192, 0, 2);
    CLACT_SetActorAnimSeq(p->cursors[1], 1);
    CLACT_SetActorBgPriority(p->cursors[1], 1);
    PMS_INPUT_VIEW_GetUiRes(p->view, &setup, 0, 0);
    p->cursors[0] = PMS_INPUT_VIEW_CreateActor(p->view, &setup, pos.x, pos.y, 0, 1);
    PMSIV_EDIT_SetCursorPressed(p, 1);
}

/*
 * extent: two bytes zero alignment padding at 0x021BC31E.
 */
void PMSIV_EDIT_Redraw(struct PmsivEdit *p)
{
    int i, j;
    PMSIV_EDIT_ApplyPalette(p);
    for (i = 0; i < PMSIV_EDIT_SCREEN_COUNT; i++) {
        for (j = 0; j < PMSIV_EDIT_SLOT_COUNT; j++) {
            if (p->wordIcons[j][i]) CLACT_SetActorDrawEnable(p->wordIcons[j][i], 0);
        }
        BMP_Clear(BMP_WIN_GetBmp(p->windows[i]), 15);
        switch (PMS_INPUT_GetInputMode(p->input)) {
        case PMSIV_EDIT_MODE_SINGLE:
            PMSIV_EDIT_ClearSlotBox(p->windows[i], &p->slotPos[0]);
            PMSIV_EDIT_DrawSlotWord(p, p->windows[i], &p->slotPos[0], PMS_INPUT_GetWord(p->input, 0), p->wordIcons[0][i]);
            break;
        case PMSIV_EDIT_MODE_DOUBLE:
            PMSIV_EDIT_ClearSlotBox(p->windows[i], &p->slotPos[0]);
            PMSIV_EDIT_ClearSlotBox(p->windows[i], &p->slotPos[1]);
            PMSIV_EDIT_DrawSlotWord(p, p->windows[i], &p->slotPos[0], PMS_INPUT_GetWord(p->input, 0), p->wordIcons[0][i]);
            PMSIV_EDIT_DrawSlotWord(p, p->windows[i], &p->slotPos[1], PMS_INPUT_GetWord(p->input, 1), p->wordIcons[1][i]);
            break;
        case PMSIV_EDIT_MODE_FREE_TEXT:
            p->slotCount = PMSIV_EDIT_DrawFreeText(p, p->windows[i], i);
            break;
        }
        BMP_WIN_TransferChars(p->windows[i]);
    }
    BG_SYS_SetFlagField06(0);
    BG_SYS_SetFlagField06(4);
}

/*
 * Unlabelled Thumb leaf in a .word run.  Extent 0x021BC320..0x021BC340
 * (32 bytes).  Packs the selection rectangle of slot into rect.
 */
void PMSIV_EDIT_GetSlotRect(struct PmsivEdit *p, unsigned char *rect, int slot)
{
    int offset = slot * 4;

    rect[2] = *(short *)((char *)p + offset + 0x38) - 0x18;
    rect[3] = rect[2] + 0x60;
    rect[0] = *(short *)((char *)p + offset + 0x3a);
    rect[1] = rect[0] + 0x10;
}

int PMSIV_EDIT_DrawFreeText(struct PmsivEdit *p, struct Descriptor *window, u8 screen)
{
    struct U16Vec *run;
    u16 wordId;
    int running, slotCount, x, y;
    u32 font;
    run = PMS_INPUT_GetSentenceString(p->input, PMSIV_EDIT_HEAP);
    font = (u32)PMS_INPUT_VIEW_GetFont(p->view);
    running = 1;
    slotCount = 0; y = 0; x = 0;
    PMSIV_EDIT_ParserInit(&p->parser, p);
    do {
        switch (PMSIV_EDIT_ParserNext(&p->parser, run)) {
        case PMSIV_EDIT_TOKEN_TEXT:
            GF_FONT_SetTextColor(1, 2, 15);
            PRINTSYS_Print(BMP_WIN_GetBmp(window), x, y, run, (void *)font);
            x += GF_FONT_MeasureWidestLine((struct StrObj *)run, font, 0);
            break;
        case PMSIV_EDIT_TOKEN_SLOT: {
            wordId = p->parser.slotWordId;
            p->slotWordId[slotCount] = wordId;
            p->slotPos[slotCount].x = x + 50;
            p->slotPos[slotCount].y = y + 8;
            PMSIV_EDIT_ClearSlotBox(window, &p->slotPos[slotCount]);
            PMSIV_EDIT_DrawSlotWord(p, window, &p->slotPos[slotCount], PMS_INPUT_GetWord(p->input, wordId), p->wordIcons[slotCount][screen]);
            slotCount++;
            x += 100;
            break;
        }
        case PMSIV_EDIT_TOKEN_NEWLINE: y += 16; x = 0; break;
        case PMSIV_EDIT_TOKEN_END: running = 0; break;
        }
    } while (running);
    PMSIV_EDIT_ParserFree(&p->parser);
    STRBUF_Delete(run);
    return slotCount;
}

/*
 * extent: two bytes of zero alignment padding after return.
 */
void PMSIV_EDIT_ParserInit(struct PmsivTextParser *parser, struct PmsivEdit *p)
{
    parser->text = PMS_INPUT_GetSentenceString(p->input, PMSIV_EDIT_HEAP);
    parser->cursor = STRBUF_GetChars(parser->text);
    if (*parser->cursor == PMSIV_EDIT_CHAR_SLOT) parser->state = 1;
    else parser->state = 0;
}

void PMSIV_EDIT_ParserFree(struct PmsivTextParser *parser)
{
    STRBUF_Delete(parser->text);
}

int PMSIV_EDIT_ParserNext(struct PmsivTextParser *parser, struct U16Vec *out)
{
    u16 *start;
    int token;
    start = parser->cursor;
    switch (parser->state) {
    case 0:
        while (parser->state == 0) {
            switch (*parser->cursor) {
            case PMSIV_EDIT_CHAR_NEWLINE: parser->state = 2; break;
            case PMSIV_EDIT_CHAR_END: parser->state = 3; break;
            case PMSIV_EDIT_CHAR_SLOT: parser->state = 1; break;
            default: parser->cursor += 1; break;
            }
        }
        STRBUF_SetStringN(out, start, (parser->cursor - start) + 1);
        return PMSIV_EDIT_TOKEN_TEXT;
    case 1:
        parser->slotWordId = GF_FONT_GetTagParam(start, 0);
        parser->cursor = GF_FONT_SkipTag(parser->cursor);
        token = PMSIV_EDIT_TOKEN_SLOT;
        break;
    case 2:
        parser->cursor = start + 1;
        token = PMSIV_EDIT_TOKEN_NEWLINE;
        break;
    case 3:
    default:
        return PMSIV_EDIT_TOKEN_END;
    }
    switch (*parser->cursor) {
    case PMSIV_EDIT_CHAR_NEWLINE: parser->state = 2; break;
    case PMSIV_EDIT_CHAR_END: parser->state = 3; break;
    case PMSIV_EDIT_CHAR_SLOT: parser->state = 1; break;
    default: parser->state = 0; break;
    }
    return token;
}

void PMSIV_EDIT_SlotPosToBoxOrigin(const short *pos, short *boxOrigin)
{
    boxOrigin[0] = pos[0] - 48;
    boxOrigin[1] = pos[1] - 8;
}

void PMSIV_EDIT_BoxOriginToSlotPos(const short *boxOrigin, short *pos)
{
    pos[0] = boxOrigin[0] + 24;
    pos[1] = boxOrigin[1] + 8;
}

void PMSIV_EDIT_ClearSlotBox(struct Descriptor *window, const ScreenPos *pos)
{
    ScreenPos origin;
    PMSIV_EDIT_SlotPosToBoxOrigin((const short *)pos, (short *)&origin);
    BMP_FillRect(BMP_WIN_GetBmp(window), origin.x, origin.y, 0x60, 16, 14);
}

void PMSIV_EDIT_DrawSlotWord(struct PmsivEdit *p, struct Descriptor *window, const ScreenPos *pos, u32 wordId, struct Obj *icon)
{
    ScreenPos origin;
    ScreenPos iconPos;
    u32 font;
    u32 decoIndex;
    u32 surface;
    font = PMS_INPUT_VIEW_GetFont(p->view);
    if (wordId == 0xffff) return;
    PMSIV_EDIT_SlotPosToBoxOrigin((const short *)pos, (short *)&origin);
    if (PMSI_PARAM_IsDecoWord(wordId) != 0) {
        decoIndex = PMSI_PARAM_GetDecoId(wordId) - 1;
        surface = PMSIV_EDIT_IsSubScreenLayer(BMP_WIN_GetBgLayer(window));
        iconPos.x = origin.x + BMP_WIN_GetPosX(window) * 8;
        iconPos.y = origin.y + BMP_WIN_GetPosY(window) * 8;
        if (surface == 1) iconPos.y += 192;
        CLACT_SetActorAnimSeq(icon, decoIndex);
        CLACT_AddActorSurfacePos(icon, &iconPos, (u16)surface);
        CLACT_SetActorDrawEnable(icon, 1);
        CLACT_SetActorBgPriority(icon, (int)(BG_SYS_Get(BMP_WIN_GetBgLayer(window))));
    } else {
        PMS_WORD_LoadString(wordId, p->text, PMSIV_EDIT_HEAP);
        GF_FONT_SetTextColor((u32)3, (u32)4, (u32)14);
        PRINTSYS_Print(BMP_WIN_GetBmp(window), (short)origin.x, (short)origin.y, p->text, (void *)font);
    }
}

void PMSIV_EDIT_SetCursorPressed(struct PmsivEdit *p, int pressed)
{
    if (p->slotCount != 0) {
        if (pressed != 0) CLACT_SetActorAnimSeq(p->cursors[0], 0);
        else CLACT_SetActorAnimSeq(p->cursors[0], 1);
    } else {
        if (pressed != 0) CLACT_SetActorAnimSeq(p->cursors[0], 14);
        else CLACT_SetActorAnimSeq(p->cursors[0], 15);
    }
}

u32 PMSIV_EDIT_IsSubScreenLayer(u32 layer)
{
    if (layer >= 4) return 1;
    return 0;
}

unsigned int PMSIV_EDIT_GetSlotCount(struct PmsivEdit *p)
{
    return p->slotCount;
}

/*
 * Halfword accessor: p + slot*2 + 0x40.
 */
u16 PMSIV_EDIT_GetSlotWordId(struct PmsivEdit *p, int slot)
{
    return p->slotWordId[slot];
}

void PMSIV_EDIT_ReleaseCursor(struct PmsivEdit *p)
{
    PMSIV_EDIT_SetCursorPressed(p, 0);
}

void PMSIV_EDIT_PressCursor(struct PmsivEdit *p)
{
    PMSIV_EDIT_SetCursorPressed(p, 1);
}

void PMSIV_EDIT_SetCursorsVisible(struct PmsivEdit *p, u32 visible)
{
    CLACT_SetActorDrawEnable(p->cursors[0], visible);
    CLACT_SetActorDrawEnable(p->cursors[1], visible);
    PMSIV_EDIT_SetCursorPressed(p, 1);
}

void PMSIV_EDIT_NoopA(struct PmsivEdit *p) { }

void PMSIV_EDIT_NoopB(struct PmsivEdit *p) { }

struct CursorPlacement {
    short rawX, rawY;
    short x, y;
};

void PMSIV_EDIT_PlaceCursorAtSlot(struct PmsivEdit *p, int slot)
{
    struct CursorPlacement t;
    if (p->slotCount != 0) {
        PMSIV_EDIT_BoxOriginToSlotPos((const short *)&p->slotPos[slot], (short *)&t);
        t.x = t.rawX;
        t.y = t.rawY;
    } else {
        t.x = 0x80;
        t.y = 0x18;
    }
    CLACT_AddActorSurfacePos(p->cursors[0], (const ScreenPos *)&t.x, 0);
    t.y += 0xC0;
    CLACT_AddActorSurfacePos(p->cursors[1], (const ScreenPos *)&t.x, 1);
    PMSIV_EDIT_SetCursorPressed(p, 1);
}

void PMSIV_BGSCROLL_Start(struct PmsivBgScroll *scroll, int layer, int axis, int step, int frames)
{
    scroll->layer = layer;
    if (axis == 0) {
        scroll->current = BG_SYS_GetChannelScrollX(layer);
        scroll->axis = 0;
    } else {
        scroll->current = BG_SYS_GetChannelScrollY(layer);
        scroll->axis = 3;
    }
    scroll->target = (scroll->current + step) & 511;
    scroll->current <<= 12;
    scroll->step = (step << 12) / frames;
    scroll->framesLeft = frames;
    scroll->state = 0;
}

int PMSIV_BGSCROLL_Step(struct PmsivBgScroll *scroll)
{
    switch (scroll->state) {
    case 0:
        scroll->task = PMS_INPUT_VIEW_AddVBlankTask(PMSIV_BGSCROLL_Task, scroll, 0);
        ++scroll->state;
        break;
    case 1:
        if (scroll->framesLeft == 0) {
            TCB_DeleteTask(scroll->task);
            ++scroll->state;
            return 1;
        }
        break;
    case 2: return 1;
    }
    return 0;
}

void PMSIV_BGSCROLL_Task(void *task, void *arg)
{
    struct PmsivBgScroll *scroll = arg;
    if (scroll->framesLeft) {
        scroll->current += scroll->step;
        BG_SYS_FillScrollArea((u8)(scroll->layer), (u8)(scroll->axis), (int)(scroll->current >> 12));
        --scroll->framesLeft;
    } else {
        BG_SYS_FillScrollArea((u8)(scroll->layer), (u8)(scroll->axis), (int)(scroll->target));
    }
}

void PMSIV_FADE_StartBlend(struct PmsivFade *fade, int firstPlanes, int secondPlanes, int start, int end, int frames)
{
    fade->planeMask = firstPlanes;
    fade->secondPlaneMask = secondPlanes;
    fade->framesLeft = frames;
    fade->current = start;
    fade->step = _s32_div_f(end - start, frames);
    fade->target = end;
    fade->done = 0;
    fade->task = PMS_INPUT_VIEW_AddVBlankTask(PMSIV_FADE_BlendTask, fade, 0);
}

int PMSIV_FADE_IsBlendDone(struct PmsivFade *fade)
{
    if (fade->done == 0) {
        if (fade->framesLeft == 0) {
            TCB_DeleteTask(fade->task);
            fade->done += 1;
            return 1;
        }
    } else {
        return 1;
    }
    return 0;
}

void PMSIV_FADE_BlendTask(void *task, void *arg)
{
    struct PmsivFade *fade = arg;
    int level;
    if (fade->framesLeft != 0) {
        fade->current += fade->step;
        level = fade->current >> 3;
        fade->framesLeft -= 1;
    } else {
        level = fade->target >> 3;
    }
    if (level > 16) level = 16;
    G2x_SetBlendAlpha_((void *)0x04000050, fade->planeMask, fade->secondPlaneMask, level, 16 - level);
}

/*
 * lever: difference of stored fixed-point fields prevents shift factoring.
 */
void PMSIV_FADE_StartBrightness(struct PmsivFade *fade, int plane, int start, int end, int frames)
{
    G2x_SetBlendBrightness_(0x4000050, plane, start);
    fade->planeMask = plane;
    fade->framesLeft = frames;
    fade->current = start << 12;
    fade->target = end << 12;
    fade->step = (fade->target - fade->current) / frames;
    fade->done = 0;
    fade->task = PMS_INPUT_VIEW_AddVBlankTask(PMSIV_FADE_BrightnessTask, fade, 0);
}

int PMSIV_FADE_IsBrightnessDone(struct PmsivFade *fade)
{
    if (fade->done == 0) {
        if (fade->framesLeft == 0) {
            TCB_DeleteTask(fade->task);
            ++fade->done;
            return 1;
        }
    } else return 1;
    return 0;
}

/*
 * follower: callback PMSIV_FADE_BrightnessTask included in unit; function_starts seed.
 */
void PMSIV_FADE_BrightnessTask(void *task, void *arg)
{
    struct PmsivFade *fade = arg;
    int value;
    if (fade->framesLeft) {
        fade->current += fade->step;
        value = fade->current >> 12;
        --fade->framesLeft;
    } else value = fade->target >> 12;
    G2x_SetBlendBrightness_(0x4000050, fade->planeMask, value);
}

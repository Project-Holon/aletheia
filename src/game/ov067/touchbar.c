/*
 * file:     touchbar.c
 * unit:     yes
 * function: TOUCHBAR_Create, TOUCHBAR_Delete, TOUCHBAR_Update, TOUCHBAR_GetPressedButtonIdIfDone, TOUCHBAR_GetPressedButtonIdIfPressing, TOUCHBAR_IsBusy, TOUCHBAR_SetAllButtonsEnabled, TOUCHBAR_SetAllButtonsVisible, TOUCHBAR_SetAllButtonsBgPriority, TOUCHBAR_SetAllButtonsPriority, TOUCHBAR_SetButtonEnabled, TOUCHBAR_SetButtonVisible, TOUCHBAR_SetButtonSound, TOUCHBAR_SetButtonKeyMask, TOUCHBAR_SetButtonBgPriority, TOUCHBAR_SetButtonToggled, TOUCHBAR_IsButtonToggled, TOUCHBAR_ResetAndEnableButton, TOUCHBAR_FindButton, TOUCHBAR_GetButton, TOUCHBAR_LoadGfx, TOUCHBAR_FreeGfx, TOUCHBAR_GetGfxWord, TOUCHBAR_LoadCharToBg, TOUCHBAR_InitButton, TOUCHBAR_FreeButton, TOUCHBAR_CheckButtonPressed, TOUCHBAR_IsButtonActorIdle, TOUCHBAR_GetButtonId, TOUCHBAR_SetButtonActorVisible, TOUCHBAR_CallSetEnabled, TOUCHBAR_SetButtonSoundId, TOUCHBAR_SetButtonKeys, TOUCHBAR_SetButtonToggle, TOUCHBAR_IsButtonDown, TOUCHBAR_SetButtonActorPriority, TOUCHBAR_SetButtonActorBgPriority, TOUCHBAR_OnPressPlain, TOUCHBAR_OnPressToggle, TOUCHBAR_SetEnabledPlain, TOUCHBAR_SetEnabledToggle, TOUCHBAR_PrintAligned, TOUCHBAR_PrintYesNoCancelLabels, TOUCHBAR_GetStringAlignOffset
 * address:  0x021B62E0
 * region:   ov067
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   func_020307B0 0x020307B0 arm
 *   func_020490F4  0x020490F4  arm
 *   CLACT_RegisterPaletteEx  0x0204AC18  arm
 *   CLACT_RegisterCharacter  0x0204A6C8  arm
 *   CLACT_RegisterCellAnim  0x0204AF28  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_CreateActor  0x0204B294  arm
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   gTouchBarSourceName     0x021B954C  data  a1
 *   APP_ICON_GetArchiveId  0x020275E4  thumb
 *   APP_ICON_GetStatusAnimFileId  0x02027624  thumb
 *   func_02049B68  0x02049B68  arm
 *   APP_ICON_GetStatusFrameFileId  0x02027628  thumb
 *   func_02049740  0x02049740  arm
 *   APP_ICON_GetStatusDataFileId  0x0202762C  thumb
 *   APP_ICON_GetMoveKindPaletteFileId  0x02027614  thumb
 *   APP_ICON_GetMoveKindAnimFileId  0x02027618  thumb
 *   APP_ICON_GetStatusCellFileId  0x0202761C  thumb
 *   APP_ICON_GetStatusPaletteFileId  0x02027620  thumb
 *   BG_SYS_DeleteHalf 0x0203FB44 arm
 *   ARC_UTIL_LoadHandleMember  0x0204A380  arm
 *   NNS_G2dGetUnpackedScreenData  0x02062B30  arm
 *   BG_SYS_GetField16  0x0204169C  arm
 *   BG_SYS_GetBuf  0x0204162C  arm
 *   BG_SYS_DrawTileEx  0x020410D0  arm
 *   BG_SYS_FillTileMap  0x020413B0  arm
 *   BG_SYS_PushTile  0x020409B4  arm
 *   gTouchBarButtonLooks     0x021B942C  data  ov067  a4
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_GetActorDrawEnable  0x0204B3F4  arm
 *   TOUCHPANEL_GetPointTrg  0x02035D20  arm
 *   func_020355D8  0x020355D8  arm
 *   KEY_GetTrg  0x020362DC  arm
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   CLACT_SetActorDrawPriority  0x0204B800  arm
 *   CLACT_SetActorBgPriority  0x0204B84C  arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   PRINTSYS_PrintQueColor  0x0201C724  thumb
 *   func_02045B38  0x02045B38  arm
 *   WORDSET_CreateDefault  0x0201EC64  thumb
 *   STRBUF_Create  0x020457B0  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_0201D304  0x0201D304  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   WORDSET_SetSlotNumber  0x0201EFA4  thumb
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   WORDSET_DeleteStrbufED04  0x0201ED04  thumb
 *   MSGDATA_Delete  0x02045C04  arm
 */

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

#include "touchbar_types.h"

struct BmpData;
struct StrObj;
struct MsgBank;
struct U16Vec;
struct WordSet;
struct Rec;

/* Window the touch bar labels are printed into. */
typedef struct {
    struct BmpData *bitmap;
    u8 redraw;
} TouchBarWindow;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MI_CpuFill8(void *dst, u32 value, u32 size);
extern u32 func_020307B0(void *ptr);
extern void *func_020490F4(u32 arcId, u32 heapId);
extern s32 CLACT_RegisterPaletteEx(void *arc, u32 fileId, u32 screen, u32 offset, u16 count, u16 mode, u32 heapId);
extern s32 CLACT_RegisterCharacter(void *arc, u32 fileId, u32 flags, u32 screen, u32 heapId);
extern s32 CLACT_RegisterCellAnim(void *arc, u32 cellFile, u32 animFile, u32 heapId);
extern void ARC_TOOL_DeleteHandle(void *arc);
extern void CLACT_ReleasePalette(unsigned int plttHandle);
extern void CLACT_ReleaseCharacter(unsigned int charHandle);
extern void CLACT_ReleaseCellAnim(unsigned int animHandle);
extern struct Actor *CLACT_CreateActor(struct Unit *unit, unsigned int charIdx, unsigned int plttIdx, unsigned int cellIdx, const TouchBarActorInit *init, u16 space, u16 heapId);
extern void CLACT_SetActorAnimSeq(struct Actor *actor, u16 animSeq);
extern u32 APP_ICON_GetArchiveId(void);
extern u32 APP_ICON_GetStatusAnimFileId(void);
extern void func_02049B68(void *arc, u32 fileId, u32 bgLayer, u32 offset, u32 size, u32 heapId);
extern u32 APP_ICON_GetStatusFrameFileId(void);
extern u32 func_02049740(void *arc, u32 fileId, u32 bgLayer, u32 offset, u32 size, u32 heapId);
extern u32 APP_ICON_GetStatusDataFileId(void);
extern u32 APP_ICON_GetMoveKindPaletteFileId(void);
extern u32 APP_ICON_GetMoveKindAnimFileId(void);
extern u32 APP_ICON_GetStatusCellFileId(u32 iconSet);
extern u32 APP_ICON_GetStatusPaletteFileId(u32 iconSet);
extern void BG_SYS_DeleteHalf(u32 layer, u32 offset, u32 size);
extern void *ARC_UTIL_LoadHandleMember(void *arc, u32 fileId, u32 loadMode, u32 heapFlags);
extern int NNS_G2dGetUnpackedScreenData(void *file, void **out);
extern u8 BG_SYS_GetField16(int bgLayer);
extern u32 BG_SYS_GetBuf(int bgLayer);
extern void BG_SYS_DrawTileEx(u8 bgLayer, u32 dstX, u32 dstY, u32 dstWidth, u8 dstHeight, u32 src, u8 srcX, u8 srcY, u8 srcWidth, u8 srcHeight);
extern void BG_SYS_FillTileMap(u8 bgLayer, u8 x, u8 y, u8 width, u8 height, u8 plttSlot);
extern void BG_SYS_PushTile(u8 bgLayer);
extern void CLACT_SetActorAutoAnim(struct Actor *actor, u32 enable);
extern void CLACT_DeleteActor(struct Actor *actor);
extern u32 CLACT_GetActorDrawEnable(struct Actor *actor);
extern u32 TOUCHPANEL_GetPointTrg(u32 *outX, u32 *outY);
extern void func_020355D8(u8 usedTouch);
extern u32 KEY_GetTrg(void);
extern u32 CLACT_IsActorAnimActive(struct Actor *actor);
extern void GFL_USE_PlaySeDefaultVolume(u32 soundId);
extern void *BMP_WIN_GetBmp(struct BmpData *bitmap);
extern void PRINTSYS_PrintQueColor(void *textCtx, u32 bitmapBuffer, u32 x, u32 y, u32 str, u32 fontId, u16 color);
extern void CLACT_SetActorDrawEnable(struct Actor *actor, u32 enable);
extern void CLACT_SetActorDrawPriority(struct Actor *actor, u32 priority);
extern void CLACT_SetActorBgPriority(struct Actor *actor, unsigned int bgPriority);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *WORDSET_CreateDefault(u16 heapId);
extern void *STRBUF_Create(u32 size, u16 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 func_0201D304(struct StrObj *str, u32 fontId, u32 spacing);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void WORDSET_SetSlotNumber(struct WordSet *wordSet, u32 slot, u32 value, u32 digits, u32 padMode, u32 flags);
extern void WORDSET_CopyTaggedText(struct WordSet *wordSet, void *dst, void *src);
extern u32 WORDSET_DeleteStrbufED04(struct WordSet *wordSet);
extern u32 MSGDATA_Delete(struct Rec *msgBank);
TouchBar *TOUCHBAR_Create(TouchBarParams *params, u16 heapId);
void TOUCHBAR_Delete(TouchBar *bar);
void TOUCHBAR_Update(TouchBar *bar);
int TOUCHBAR_GetPressedButtonIdIfDone(TouchBar *bar);
int TOUCHBAR_GetPressedButtonIdIfPressing(TouchBar *bar);
int TOUCHBAR_IsBusy(TouchBar *bar);
void TOUCHBAR_SetAllButtonsEnabled(TouchBar *bar, u32 enabled);
void TOUCHBAR_SetAllButtonsVisible(TouchBar *bar, u32 visible);
void TOUCHBAR_SetAllButtonsBgPriority(TouchBar *bar, u32 bgPriority);
void TOUCHBAR_SetAllButtonsPriority(TouchBar *bar, u32 priority);
void TOUCHBAR_SetButtonEnabled(TouchBar *bar, unsigned int buttonId, int enabled);
void TOUCHBAR_SetButtonVisible(TouchBar *bar, unsigned int buttonId, unsigned int visible);
void TOUCHBAR_SetButtonSound(TouchBar *bar, unsigned int buttonId, int soundId);
void TOUCHBAR_SetButtonKeyMask(TouchBar *bar, unsigned int buttonId, int keyMask);
void TOUCHBAR_SetButtonBgPriority(TouchBar *bar, unsigned int buttonId, unsigned int bgPriority);
void TOUCHBAR_SetButtonToggled(TouchBar *bar, unsigned int buttonId, unsigned int toggled);
int TOUCHBAR_IsButtonToggled(TouchBar *bar, int buttonId);
void TOUCHBAR_ResetAndEnableButton(TouchBar *bar, unsigned int buttonId);
TouchBarButton *TOUCHBAR_FindButton(TouchBar *bar, u32 buttonId);
TouchBarButton *TOUCHBAR_GetButton(TouchBar *bar, unsigned int buttonId);
void TOUCHBAR_LoadGfx(TouchBarGfx *gfx, u8 bgLayer, u32 screen, u32 bgPlttTarget, u32 iconSet, u8 bgPlttSlot, u8 actorPlttSlot, u32 skipBgGfx, u32 heapId);
void TOUCHBAR_FreeGfx(TouchBarGfx *gfx);
int TOUCHBAR_GetGfxWord(const TouchBarGfx *gfx, int index);
void TOUCHBAR_LoadCharToBg(void *arc, u32 fileId, u32 bgLayer, u32 tileOffset, u8 srcX, u8 srcY, u8 srcWidth, u8 srcHeight, u8 dstX, u8 dstY, u8 dstWidth, u8 dstHeight, u8 plttSlot, u32 loadMode, u32 heapId);
void TOUCHBAR_InitButton(TouchBarButton *button, struct Unit *actorSys, const TouchBarGfx *gfx, const TouchBarButtonDef *def, u32 screen, u16 heapId);
void TOUCHBAR_FreeButton(TouchBarButton *button);
int TOUCHBAR_CheckButtonPressed(TouchBarButton *button);
int TOUCHBAR_IsButtonActorIdle(TouchBarButton *button);
int TOUCHBAR_GetButtonId(TouchBarButton *button);
void TOUCHBAR_SetButtonActorVisible(TouchBarButton *button, unsigned int visible);
void TOUCHBAR_CallSetEnabled(TouchBarButton *button, int enabled);
void TOUCHBAR_SetButtonSoundId(TouchBarButton *button, int soundId);
void TOUCHBAR_SetButtonKeys(TouchBarButton *button, int keyMask);
void TOUCHBAR_SetButtonToggle(TouchBarButton *button, u32 down);
u32 TOUCHBAR_IsButtonDown(TouchBarButton *button);
void TOUCHBAR_SetButtonActorPriority(TouchBarButton *button, unsigned int priority);
void TOUCHBAR_SetButtonActorBgPriority(TouchBarButton *button, unsigned int bgPriority);
void TOUCHBAR_OnPressPlain(TouchBarButton *button);
void TOUCHBAR_OnPressToggle(TouchBarButton *button);
void TOUCHBAR_SetEnabledPlain(TouchBarButton *button, u32 enabled);
void TOUCHBAR_SetEnabledToggle(TouchBarButton *button, u32 enabled);
void TOUCHBAR_PrintAligned(TouchBarWindow *window, void *textCtx, u16 x, u16 y, u32 str, u32 fontId, u16 color, u32 alignMode);
void TOUCHBAR_PrintYesNoCancelLabels(TouchBarWindow *window, void *textCtx, u32 fontId, u16 x, u16 y, u16 color, u32 firstNumber, u32 secondNumber, u16 heapId);
u16 TOUCHBAR_GetStringAlignOffset(struct StrObj *str, u32 fontId, u32 alignMode);
extern const char gTouchBarSourceName[];
extern TouchBarButtonLook gTouchBarButtonLooks[];


TouchBar *TOUCHBAR_Create(TouchBarParams *params, u16 heapId)
{
    int screen;
    TouchBar *bar;
    int bgPlttTarget;
    u32 size;
    u32 i;

    size = params->count * sizeof(TouchBarButton) + 0x20;
    bar = func_02030734(heapId, size, 0, gTouchBarSourceName, 0x123);
    screen = 0;
    MI_CpuFill8(bar, 0, size);
    bar->buttonCount = params->count;
    bar->state = screen;
    if (params->bgLayer >= 4) {
        screen = 1;
        bgPlttTarget = 4;
    } else {
        bgPlttTarget = screen;
    }
    TOUCHBAR_LoadGfx(&bar->gfx, params->bgLayer, screen, bgPlttTarget, params->iconSet, params->bgPlttSlot, params->actorPlttSlot, params->skipBgGfx, heapId);
    for (i = 0; i < bar->buttonCount; i++) {
        TOUCHBAR_InitButton(&bar->buttons[i], params->actorSys, &bar->gfx, &params->defs[i], screen, heapId);
    }
    return bar;
}


void TOUCHBAR_Delete(TouchBar *bar)
{
    u32 i;
    for (i = 0; i < bar->buttonCount; i++)
        TOUCHBAR_FreeButton(&bar->buttons[i]);
    TOUCHBAR_FreeGfx(&bar->gfx);
    func_020307B0(bar);
}


void TOUCHBAR_Update(TouchBar *bar)
{
    u32 i;

    switch (bar->state) {
    case TOUCHBAR_STATE_IDLE:
        bar->pressedIndex = -1;
        for (i = 0; i < bar->buttonCount; i++) {
            if (TOUCHBAR_CheckButtonPressed(&bar->buttons[i])) {
                bar->pressedIndex = i;
                bar->state = TOUCHBAR_STATE_PRESSED;
                return;
            }
        }
        break;
    case TOUCHBAR_STATE_PRESSED:
        bar->state = TOUCHBAR_STATE_ANIMATING;
    case TOUCHBAR_STATE_ANIMATING:
        if (TOUCHBAR_IsButtonActorIdle(&bar->buttons[bar->pressedIndex])) {
            bar->state = TOUCHBAR_STATE_DONE;
        }
        break;
    case TOUCHBAR_STATE_DONE:
        bar->state = TOUCHBAR_STATE_IDLE;
        break;
    }
}


int TOUCHBAR_GetPressedButtonIdIfDone(TouchBar *bar)
{
    if (bar->state == TOUCHBAR_STATE_DONE && bar->pressedIndex != TOUCHBAR_NO_BUTTON) {
        return TOUCHBAR_GetButtonId(&bar->buttons[bar->pressedIndex]);
    }
    return -1;
}


int TOUCHBAR_GetPressedButtonIdIfPressing(TouchBar *bar)
{
    if (bar->state == TOUCHBAR_STATE_PRESSED && bar->pressedIndex != TOUCHBAR_NO_BUTTON) {
        return TOUCHBAR_GetButtonId(&bar->buttons[bar->pressedIndex]);
    }
    return -1;
}


int TOUCHBAR_IsBusy(TouchBar *bar)
{
    if (bar->state)
        return 1;
    return 0;
}


void TOUCHBAR_SetAllButtonsEnabled(TouchBar *bar, u32 enabled)
{
    u32 i;

    for (i = 0; i < bar->buttonCount; i++) {
        TOUCHBAR_CallSetEnabled(&bar->buttons[i], enabled);
    }
}


void TOUCHBAR_SetAllButtonsVisible(TouchBar *bar, u32 visible)
{
    u32 i;

    for (i = 0; i < bar->buttonCount; i++) {
        TOUCHBAR_SetButtonActorVisible(&bar->buttons[i], visible);
    }
}


void TOUCHBAR_SetAllButtonsBgPriority(TouchBar *bar, u32 bgPriority)
{
    u32 i;

    for (i = 0; i < bar->buttonCount; i++) {
        TOUCHBAR_SetButtonActorBgPriority(&bar->buttons[i], bgPriority);
    }
}


void TOUCHBAR_SetAllButtonsPriority(TouchBar *bar, u32 priority)
{
    u32 i;

    for (i = 0; i < bar->buttonCount; i++) {
        TOUCHBAR_SetButtonActorPriority(&bar->buttons[i], priority);
    }
}


void TOUCHBAR_SetButtonEnabled(TouchBar *bar, unsigned int buttonId, int enabled)
{
    TOUCHBAR_CallSetEnabled(TOUCHBAR_FindButton(bar, buttonId), enabled);
}


void TOUCHBAR_SetButtonVisible(TouchBar *bar, unsigned int buttonId, unsigned int visible)
{
    TOUCHBAR_SetButtonActorVisible(TOUCHBAR_FindButton(bar, buttonId), visible);
}


void TOUCHBAR_SetButtonSound(TouchBar *bar, unsigned int buttonId, int soundId)
{
    TOUCHBAR_SetButtonSoundId(TOUCHBAR_FindButton(bar, buttonId), soundId);
}


void TOUCHBAR_SetButtonKeyMask(TouchBar *bar, unsigned int buttonId, int keyMask)
{
    TOUCHBAR_SetButtonKeys(TOUCHBAR_FindButton(bar, buttonId), keyMask);
}


void TOUCHBAR_SetButtonBgPriority(TouchBar *bar, unsigned int buttonId, unsigned int bgPriority)
{
    TOUCHBAR_SetButtonActorBgPriority(TOUCHBAR_FindButton(bar, buttonId), bgPriority);
}


void TOUCHBAR_SetButtonToggled(TouchBar *bar, unsigned int buttonId, unsigned int toggled)
{
    TOUCHBAR_SetButtonToggle(TOUCHBAR_FindButton(bar, buttonId), toggled);
}


/*
 * Extent includes the unlabelled tail-call follower at 0x021B65B4.
 */
int TOUCHBAR_IsButtonToggled(TouchBar *bar, int buttonId)
{
    return TOUCHBAR_IsButtonDown(TOUCHBAR_GetButton(bar, buttonId));
}


void TOUCHBAR_ResetAndEnableButton(TouchBar *bar, unsigned int buttonId)
{
    bar->state = TOUCHBAR_STATE_IDLE;
    bar->pressedIndex = TOUCHBAR_NO_BUTTON;
    TOUCHBAR_SetButtonEnabled(bar, buttonId, 1);
}


TouchBarButton *TOUCHBAR_FindButton(TouchBar *bar, u32 buttonId)
{
    u32 i;

    for (i = 0; i < bar->buttonCount; i++) {
        if (TOUCHBAR_GetButtonId(&bar->buttons[i]) == buttonId) {
            return (TouchBarButton *)((u8 *)bar->buttons + i * sizeof(TouchBarButton));  /* stand-in: &bar->buttons[i] CSEs with the call argument and is 2 bytes short */
        }
    }
    return 0;
}


/*
 * Tail call to TOUCHBAR_FindButton.
 */
TouchBarButton *TOUCHBAR_GetButton(TouchBar *bar, unsigned int buttonId)
{
    return TOUCHBAR_FindButton(bar, buttonId);
}


void TOUCHBAR_LoadGfx(TouchBarGfx *gfx, u8 bgLayer, u32 screen, u32 bgPlttTarget, u32 iconSet, u8 bgPlttSlot, u8 actorPlttSlot, u32 skipBgGfx, u32 heapId)
{
    void *arc;
    u32 cellFile;

    MI_CpuFill8(gfx, 0, sizeof(TouchBarGfx));
    gfx->bgLayer = bgLayer;
    arc = func_020490F4(APP_ICON_GetArchiveId(), heapId);
    if (skipBgGfx == 0) {
        func_02049B68(arc, APP_ICON_GetStatusAnimFileId(), bgPlttTarget, bgPlttSlot << 5, 0x20, heapId);
        gfx->tileAlloc = func_02049740(arc, APP_ICON_GetStatusFrameFileId(), gfx->bgLayer, 0x800, 0, heapId);
        TOUCHBAR_LoadCharToBg(arc, APP_ICON_GetStatusDataFileId(), gfx->bgLayer, (u16)gfx->tileAlloc,
                      0, 0x15, 0x20, 0x18, 0, 0x15, 0x20, 3, bgPlttSlot, 0, heapId);
    }
    gfx->plttHandle = CLACT_RegisterPaletteEx(arc, APP_ICON_GetMoveKindPaletteFileId(), screen, (u16)(actorPlttSlot << 5), 0, 3, heapId);
    gfx->charHandle = CLACT_RegisterCharacter(arc, APP_ICON_GetMoveKindAnimFileId(), 0, screen, heapId);
    cellFile = APP_ICON_GetStatusCellFileId(iconSet);
    gfx->animHandle = CLACT_RegisterCellAnim(arc, cellFile, APP_ICON_GetStatusPaletteFileId(iconSet), heapId);
    ARC_TOOL_DeleteHandle(arc);
}


void TOUCHBAR_FreeGfx(TouchBarGfx *gfx)
{
    CLACT_ReleaseCellAnim(gfx->animHandle);
    CLACT_ReleaseCharacter(gfx->charHandle);
    CLACT_ReleasePalette(gfx->plttHandle);
    BG_SYS_DeleteHalf(gfx->bgLayer, (u16)gfx->tileAlloc, (u16)(gfx->tileAlloc >> 16));
    MI_CpuFill8(gfx, 0, sizeof(TouchBarGfx));
}


/*
 * Reads word `index` of the resource handle block (0 palette, 1 character,
 * 2 cell animation); the struct is indexed as a word array.
 */
int TOUCHBAR_GetGfxWord(const TouchBarGfx *gfx, int index)
{
    return ((int *)gfx)[index];
}


/*
 * Loads a character-data resource, optionally adds tileOffset to each of its
 * srcWidth * srcHeight u16 cells, then (when BG_SYS_GetBuf(bgLayer) allows)
 * copies it into background bgLayer and loads its palette, and frees the
 * resource.
 * The u8 stack arguments are re-read with ldrb before each call because the
 * callees take them as u8 (widths from BG_SYS_DrawTileEx.c and
 * BG_SYS_FillTileMap.c); with u32 callee parameters dstX..dstWidth stayed in
 * registers and the frame grew (200 bytes against 192). The loop bound is the
 * expression srcWidth * srcHeight and the add is `+=` with the uncast
 * tileOffset: a total local, srcHeight * srcWidth and `cells[i] + (u16)tileOffset`
 * each cost a copy or swapped the loads.
 * The caller passes tileOffset narrowed (cast at the call) and the last
 * argument as a full word, so both are u32 in the prototype; the body reads
 * the low half of the last stack word with ldrh (`*(u16 *)&heapId`).
 */
void TOUCHBAR_LoadCharToBg(void *arc, u32 fileId, u32 bgLayer, u32 tileOffset,
                   u8 srcX, u8 srcY, u8 srcWidth, u8 srcHeight,
                   u8 dstX, u8 dstY, u8 dstWidth, u8 dstHeight,
                   u8 plttSlot, u32 loadMode, u32 heapId)
{
    void *file;
    u8 *data;
    int i;
    u16 *cells;

    file = ARC_UTIL_LoadHandleMember(arc, fileId, loadMode, (u16)((*(u16 *)&heapId & 0x7fff) | 0x8000));
    NNS_G2dGetUnpackedScreenData(file, (void **)(&data));
    if (tileOffset != 0) {
        if (BG_SYS_GetField16((u8)bgLayer) == 0) {
            cells = (u16 *)(data + 0xc);
            for (i = 0; i < srcWidth * srcHeight; i++) {
                cells[i] += tileOffset;
            }
        }
    }
    if ((int)BG_SYS_GetBuf((u8)bgLayer)) {
        BG_SYS_DrawTileEx(bgLayer, dstX, dstY, dstWidth, dstHeight, (u32)(data + 0xc), srcX, srcY, srcWidth, srcHeight);
        BG_SYS_FillTileMap(bgLayer, dstX, dstY, dstWidth, dstHeight, plttSlot);
        BG_SYS_PushTile(bgLayer);
    }
    func_020307B0(file);
}


void TOUCHBAR_InitButton(TouchBarButton *button, struct Unit *actorSys, const TouchBarGfx *gfx, const TouchBarButtonDef *def, u32 screen, u16 heapId)
{
    TouchBarActorInit init;
    u32 charRes;
    u32 plttRes;
    u32 animRes;
    int i;

    MI_CpuFill8(button, 0, sizeof(TouchBarButton));
    button->def = *def;
    button->enabled = 1;
    MI_CpuFill8(&init, 0, sizeof(TouchBarActorInit));
    init.x = def->x;
    init.y = def->y;
    if (def->kind >= TOUCHBAR_KIND_CUSTOM) {
        charRes = def->charRes;
        plttRes = def->plttRes;
        animRes = def->animRes;
        button->style = 0;
    } else {
        charRes = TOUCHBAR_GetGfxWord(gfx, 1);
        plttRes = TOUCHBAR_GetGfxWord(gfx, 0);
        animRes = TOUCHBAR_GetGfxWord(gfx, 2);
        i = def->kind;
        button->def.animIdle = gTouchBarButtonLooks[i].animIdle;
        button->def.animDisabled = gTouchBarButtonLooks[i].animDisabled;
        button->def.animDown = gTouchBarButtonLooks[i].animDown;
        button->def.animDownAlt = gTouchBarButtonLooks[i].animDownAlt;
        button->def.keyMask = gTouchBarButtonLooks[i].keyMask;
        button->def.soundId = gTouchBarButtonLooks[i].soundId;
        button->style = gTouchBarButtonLooks[i].style;
    }
    button->anim = button->def.animIdle;
    init.animSeq = button->anim;
    button->actor = CLACT_CreateActor(actorSys, charRes, plttRes, animRes, &init, screen, heapId);
    CLACT_SetActorAutoAnim(button->actor, 1);
    switch (button->style) {
    case 0:
        button->onPress = TOUCHBAR_OnPressPlain;
        button->setEnabled = TOUCHBAR_SetEnabledPlain;
        break;
    case 1:
        button->onPress = TOUCHBAR_OnPressToggle;
        button->setEnabled = TOUCHBAR_SetEnabledToggle;
        break;
    }
}


/*
 * extent: trailing two-byte alignment padding at 0x021B6932.
 */
void TOUCHBAR_FreeButton(TouchBarButton *button)
{
    CLACT_DeleteActor(button->actor);
    MI_CpuFill8(button, 0, sizeof(TouchBarButton));
}


int TOUCHBAR_CheckButtonPressed(TouchBarButton *button)
{
    u32 touchX;
    u32 touchY;
    int hit = 0;

    if (CLACT_GetActorDrawEnable(button->actor) & button->enabled) {
        if (TOUCHPANEL_GetPointTrg(&touchX, &touchY)) {
            if (touchX - button->def.x <= 0x18 && touchY - button->def.y <= 0x18) {
                hit = 1;
                func_020355D8(1);
            }
        }
        if (button->def.keyMask != 0 && (KEY_GetTrg() & button->def.keyMask)) {
            func_020355D8(0);
            hit = 1;
        }
        if (hit) {
            button->onPress(button);
            return 1;
        }
    }
    return 0;
}


int TOUCHBAR_IsButtonActorIdle(TouchBarButton *button)
{
    if (CLACT_IsActorAnimActive(button->actor) == 0) return 1;
    return 0;
}


/*
 * Getter, ARM9 tail call, indirect call, and two setters.  0x021B69BC is also
 * resident in ov172, so the packet id is region-qualified.
 */
int TOUCHBAR_GetButtonId(TouchBarButton *button)
{
    return button->def.kind;
}


void TOUCHBAR_SetButtonActorVisible(TouchBarButton *button, unsigned int visible)
{
    CLACT_SetActorDrawEnable(button->actor, visible);
}


void TOUCHBAR_CallSetEnabled(TouchBarButton *button, int enabled)
{
    button->setEnabled(button, enabled);
}


void TOUCHBAR_SetButtonSoundId(TouchBarButton *button, int soundId)
{
    button->def.soundId = soundId;
}


void TOUCHBAR_SetButtonKeys(TouchBarButton *button, int keyMask)
{
    button->def.keyMask = keyMask;
}


void TOUCHBAR_SetButtonToggle(TouchBarButton *button, u32 down)
{
    if (down != 0)
        button->anim = button->def.animDown;
    else
        button->anim = button->def.animIdle;
    CLACT_SetActorAnimSeq(button->actor, (u16)button->anim);
}


u32 TOUCHBAR_IsButtonDown(TouchBarButton *button)
{
    int result = 1;
    if (button->anim != button->def.animDown && button->anim != button->def.animDownAlt) result = 0;
    return result;
}


void TOUCHBAR_SetButtonActorPriority(TouchBarButton *button, unsigned int priority)
{
    CLACT_SetActorDrawPriority(button->actor, priority);
}


/*
 * Tail call on the actor pointer loaded from offset 0.
 */
void TOUCHBAR_SetButtonActorBgPriority(TouchBarButton *button, unsigned int bgPriority)
{
    CLACT_SetActorBgPriority(button->actor, bgPriority);
}


/*
 * extent: trailing two-byte alignment padding at 0x021B6A42.
 */
void TOUCHBAR_OnPressPlain(TouchBarButton *button)
{
    button->anim = button->def.animDown;
    CLACT_SetActorAnimSeq(button->actor, button->anim);
    if (button->def.soundId) GFL_USE_PlaySeDefaultVolume(button->def.soundId);
}


void TOUCHBAR_OnPressToggle(TouchBarButton *button)
{
    u32 isDown = TOUCHBAR_IsButtonDown(button);
    int down = 1;

    if (isDown != 0) {
        down = 0;
    }
    TOUCHBAR_SetButtonToggle(button, down);
    if (button->def.soundId != 0) {
        GFL_USE_PlaySeDefaultVolume(button->def.soundId);
    }
}


/*
 * extent: trailing two-byte alignment padding at 0x021B6A96.
 */
void TOUCHBAR_SetEnabledPlain(TouchBarButton *button, u32 enabled)
{
    button->enabled = enabled;
    if (enabled) {
        if (button->anim == button->def.animDown) button->anim = button->def.animIdle;
        CLACT_SetActorAnimSeq(button->actor, button->anim);
    } else {
        CLACT_SetActorAnimSeq(button->actor, button->def.animDisabled);
    }
}


void TOUCHBAR_SetEnabledToggle(TouchBarButton *button, u32 enabled)
{
    button->enabled = enabled;
    if (enabled) {
        if (button->anim == button->def.animDown) {
            button->anim = button->def.animDownAlt;
        } else if (button->anim == button->def.animDisabled) {
            button->anim = button->def.animIdle;
        }
        CLACT_SetActorAnimSeq(button->actor, button->anim);
    } else {
        if (button->anim == button->def.animDownAlt) {
            button->anim = button->def.animDown;
        } else if (button->anim == button->def.animIdle) {
            button->anim = button->def.animDisabled;
        }
        CLACT_SetActorAnimSeq(button->actor, button->def.animDisabled);
    }
}


/*
 * note:     y and x are u16 as the matched caller ov067_func_021B6B2C passes
 *           them; the difference is written back into the parameter
 *           (`x = x - f()`): a separate u16 local swapped window and x
 *           between r4/r5, and `x -= f()` truncates the call result first
 *           (worse).
 */
void TOUCHBAR_PrintAligned(TouchBarWindow *window, void *textCtx, u16 x, u16 y, u32 str, u32 fontId, u16 color, u32 alignMode)
{
    x = x - TOUCHBAR_GetStringAlignOffset((struct StrObj *)str, fontId, alignMode);
    PRINTSYS_PrintQueColor(textCtx, (u32)BMP_WIN_GetBmp(window->bitmap), (short)x, (short)y, str, fontId, color);
    window->redraw = 1;
}


/*
 * note:     the heap id, y and color are reloaded from their stack slots
 *           before every call because the callees take them as u16 (with
 *           u32 callee parameters they stay in registers: 300 bytes);
 *           `x = x - f()` (`-=` truncates the call result first).
 */
void TOUCHBAR_PrintYesNoCancelLabels(TouchBarWindow *window, void *textCtx, u32 fontId, u16 x, u16 y, u16 color, u32 firstNumber, u32 secondNumber, u16 heapId)
{
    void *msgBank;
    void *wordSet;
    void *buf;
    void *str;
    u16 strWidth;

    msgBank = func_02045B38(0, 2, 0xa3, heapId);
    wordSet = WORDSET_CreateDefault(heapId);
    buf = STRBUF_Create(0xa, heapId);
    str = func_02045EC0(msgBank, 0);
    strWidth = func_0201D304(str, fontId, 0);
    TOUCHBAR_PrintAligned(window, textCtx, x, y, (u32)str, fontId, color, 2);
    x = x - TOUCHBAR_GetStringAlignOffset(str, fontId, 2);
    STRBUF_Delete(str);
    str = func_02045EC0(msgBank, 1);
    WORDSET_SetSlotNumber(wordSet, 0, firstNumber, 8, 0, 1);
    WORDSET_CopyTaggedText(wordSet, buf, str);
    TOUCHBAR_PrintAligned(window, textCtx, x, y, (u32)buf, fontId, color, 1);
    STRBUF_Delete(str);
    str = func_02045EC0(msgBank, 2);
    WORDSET_SetSlotNumber(wordSet, 0, secondNumber, 8, 0, 1);
    WORDSET_CopyTaggedText(wordSet, buf, str);
    TOUCHBAR_PrintAligned(window, textCtx, x + strWidth, y, (u32)buf, fontId, color, 0);
    STRBUF_Delete(str);
    STRBUF_Delete(buf);
    WORDSET_DeleteStrbufED04(wordSet);
    MSGDATA_Delete(msgBank);
}


u16 TOUCHBAR_GetStringAlignOffset(struct StrObj *str, u32 fontId, u32 alignMode)
{
    if (alignMode == 1) return func_0201D304(str, fontId, 0);
    if (alignMode == 2) return func_0201D304(str, fontId, 0) >> 1;
    return 0;
}

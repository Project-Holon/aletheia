/*
 * file:     frame_list.c
 * unit:     yes
 * function: FRAME_LIST_Create, FRAME_LIST_Delete, FRAME_LIST_AddItem, FRAME_LIST_CopyMapToBuffer, FRAME_LIST_LoadPalettes, FRAME_LIST_UpdateInit, FRAME_LIST_Update, FRAME_LIST_ClampScroll, FRAME_LIST_Redraw, FRAME_LIST_ReadTouch, FRAME_LIST_ReadKeys, FRAME_LIST_HandleInput, FRAME_LIST_UpdateHoldStage, FRAME_LIST_GetStepFrames, FRAME_LIST_GetScrollRoom, FRAME_LIST_StartScroll, FRAME_LIST_StepScroll, FRAME_LIST_BeginScrollBarDrag, FRAME_LIST_GetScrollBarRow, FRAME_LIST_FindScrollBarEntry, FRAME_LIST_GetScrollBarTop, FRAME_LIST_ClampToScrollBar, FRAME_LIST_StepScrollBarDrag, FRAME_LIST_BeginRowDrag, FRAME_LIST_StepRowDrag, FRAME_LIST_StartJump, FRAME_LIST_StartFlick, FRAME_LIST_ClampBgFrameId, FRAME_LIST_UploadRowTiles, FRAME_LIST_ScrollBgRows, FRAME_LIST_ClearBgRows, FRAME_LIST_GetRowPosition, FRAME_LIST_WrapIndex, FRAME_LIST_DrawRowA, FRAME_LIST_DrawRowB, FRAME_LIST_SetRowPalette, FRAME_LIST_SetCursorHighlight, FRAME_LIST_UpdateWindows, FRAME_LIST_GetPrinter, FRAME_LIST_GetItemValue, FRAME_LIST_GetSelectedIndex, FRAME_LIST_GetCursor, FRAME_LIST_GetScrollPos, FRAME_LIST_CanScrollDown, func_021B93D4, func_021B940C, func_021B941C
 * address:  0x021B7754
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
 *   func_020307B0 0x020307B0 arm
 *   BG_SYS_DrawTileEx  0x020410D0  arm
 *   BG_SYS_FillTileMap  0x020413B0  arm
 *   func_020355D8  0x020355D8  arm
 *   KEY_GetTrg  0x020362DC  arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   ENV_SetResourceSet  0x020307B0  arm
 *   BMP_WIN_Create  0x020450F0  arm
 *   BMP_WIN_Delete  0x020452E8  arm
 *   PRINTSYS_QUE_IsExistTarget  0x0201C6C4  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_020355C4  0x020355C4  arm
 *   gFrameListSourceFile     0x021B9574  data  ov067  a1
 *   PRINTSYS_QUE_CreateEx  0x0201C450  thumb
 *   BLINK_PALANM_Create  0x0202E940  thumb
 *   _s32_div_f     0x0209C0A4  arm
 *   BGWINFRM_Create  0x0202C9B4  thumb
 *   BGWINFRM_AddFrame  0x0202CA3C  thumb
 *   MIi_CpuCopy32  0x02082A90  arm
 *   BGWINFRM_Delete       0x0202CA0C  thumb
 *   func_0202EA20       0x0202EA20  thumb
 *   PRINTSYS_QUE_Delete       0x0201C4C0  thumb
 *   func_02049EF4 0x02049EF4 arm
 *   MIi_CpuCopy16 0x02082A60 arm
 *   BLINK_PALANM_LoadPalettes 0x0202E9AC thumb
 *   PRINTSYS_QUE_IsFinished  0x0201C6B4  thumb
 *   TOUCHPANEL_GetPointCont  0x02035CB8  arm
 *   BLINK_PALANM_Update  0x0202EA40  thumb
 *   BG_SYS_ResetSlot  0x02041EE4  arm
 *   TOUCHPANEL_HitTrg  0x02035C08  arm
 *   KEY_GetCont  0x0203630C  arm
 *   TOUCHPANEL_HitCont 0x02035BA4 arm
 *   gFrameListFlickSteps 0x021B94F8 data a1
 *   COMM_HISTORY_ScaleValue  0x0202EDE4  thumb
 *   COMM_HISTORY_ScaleSpan 0x0202EE0C thumb
 *   gFrameListFlickThresholds     0x021B94FE  data   ov067  a1
 *   BGWINFRM_GetBgFrame  0x0202CF8C  thumb
 *   BUTTON_MAN_CallHandlerById  0x02051B0C  arm
 *   BGWINFRM_SetFrameData  0x0202CAC4  thumb
 *   BGWINFRM_PutBmpWin  0x0202CEBC  thumb
 *   BMP_WIN_GetDispWidth  0x02045748  arm
 *   BMP_WIN_GetDispHeight  0x02045750  arm
 *   BMP_WIN_GetPosX  0x02045758  arm
 *   BMP_WIN_GetPosY  0x02045760  arm
 *   BMP_GetPixels  0x020437D4  arm
 *   BGWINFRM_GetFrameBuffer  0x0202CF84  thumb
 *   BG_SYS_SetTileEntry  0x02041300  arm
 *   BLINK_PALANM_ResetPhase  0x0202EB04  thumb
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb
 */
#include "frame_list_types.h"

struct Bitmap;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *file, u16 line);
extern u32 func_020307B0(void *ptr);
extern void BG_SYS_DrawTileEx(u8 layer, u32 dstX, u32 dstY, u32 width, u8 height, u32 src, u8 srcX, u8 srcY, u8 srcWidth, u8 srcHeight);
extern void BG_SYS_FillTileMap(u8 layer, u8 x, u8 y, u8 width, u8 height, u8 pltt);
extern void func_020355D8(u8 value);
extern u32 KEY_GetTrg(void);
extern void GFL_USE_PlaySeDefaultVolume(u32 seId);
extern struct Bitmap *BMP_WIN_GetBmp(struct BmpWin *win);
extern void ENV_SetResourceSet(void *ptr);
extern struct BmpWin *BMP_WIN_Create(u32 layer, u32 x, u32 y, u32 width, u8 height, u8 pltt, u8 slot);
extern u32 BMP_WIN_Delete(struct BmpWin *win);
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *printer, struct Bitmap *bitmap);
extern void BMP_WIN_TransferChars(struct BmpWin *win);
extern void func_02041B6C(u32 layer);
extern u8 func_020355C4(void);
extern struct PrintSys *PRINTSYS_QUE_CreateEx(u16 size, u32 heapId);
extern struct BlinkPalAnm *BLINK_PALANM_Create(u16 firstColor, u16 colorCount, u32 bgLayer, u16 heapId);
extern struct BgWinFrm *BGWINFRM_Create(u32 kind, u32 frameCount, u32 heapId);
extern void BGWINFRM_AddFrame(struct BgWinFrm *mgr, u32 index, u32 bgLayer, u32 width, u32 height);
extern void MIi_CpuCopy32(const void *src, void *dst, u32 size);
extern void BGWINFRM_Delete(struct BgWinFrm *mgr);
extern u32 func_0202EA20(struct BlinkPalAnm *anim);
extern void PRINTSYS_QUE_Delete(struct PrintSys *printer);
extern void *func_02049EF4(void *source, u32 fileIndex, u32 memberIndex, void **outData, u16 heapId);
extern void MIi_CpuCopy16(const void *src, void *dst, int size);
extern void BLINK_PALANM_LoadPalettes(struct BlinkPalAnm *anim, u8 *src, u32 firstColor, u32 srcOffset, u32 byteSize);
extern u32 PRINTSYS_QUE_IsFinished(const struct PrintSys *printer);
extern u32 TOUCHPANEL_GetPointCont(u32 *outX, u32 *outY);
extern s32 BLINK_PALANM_Update(struct BlinkPalAnm *anim);
extern void BG_SYS_ResetSlot(u32 layer, u32 axis, u32 offset);
extern int TOUCHPANEL_HitTrg(const void *hitRects);
extern unsigned int KEY_GetCont(void);
extern int _s32_div_f(int numerator, int denominator);
extern int TOUCHPANEL_HitCont(const void *hitRects);
extern u32 COMM_HISTORY_ScaleValue(u32 scrollMax, u32 touchY, u32 barX, u32 barY, u32 barPad);
extern u32 COMM_HISTORY_ScaleSpan(u32 scrollMax, u32 index, u32 barX, u32 barY, u32 barPad);
extern u8 BGWINFRM_GetBgFrame(struct BgWinFrm *mgr, u32 index);
extern u8 *BUTTON_MAN_CallHandlerById(int id);
extern void BGWINFRM_SetFrameData(struct BgWinFrm *mgr, u32 index, const void *src);
extern void BGWINFRM_PutBmpWin(struct BgWinFrm *mgr, u32 index, struct BmpWin *win);
extern u8 BMP_WIN_GetDispWidth(struct BmpWin *win);
extern u8 BMP_WIN_GetDispHeight(struct BmpWin *win);
extern u8 BMP_WIN_GetPosX(struct BmpWin *win);
extern u8 BMP_WIN_GetPosY(struct BmpWin *win);
extern void *BMP_GetPixels(const struct Bitmap *bitmap);
extern u32 BGWINFRM_GetFrameBuffer(struct BgWinFrm *mgr, u32 index);
extern void BG_SYS_SetTileEntry(u32 layer, int value, int x, int y, u8 width, u8 height, u8 mode);
extern void BLINK_PALANM_ResetPhase(struct BlinkPalAnm *anim);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *printer);
FrameList *FRAME_LIST_Create(const FrameListParams *params, u32 heapId);
void FRAME_LIST_Delete(FrameList *list);
void FRAME_LIST_AddItem(FrameList *list, unsigned mapIndex, unsigned value);
void FRAME_LIST_CopyMapToBuffer(FrameList *list, void *source, u32 fileIndex, u32 memberIndex, u32 mapSlot);
void FRAME_LIST_LoadPalettes(FrameList *list, u8 *palettes, u32 firstSlot, u32 srcSlot, u32 slotCount);
int FRAME_LIST_UpdateInit(FrameList *list);
int FRAME_LIST_Update(FrameList *list);
void FRAME_LIST_ClampScroll(FrameList *list);
void FRAME_LIST_Redraw(FrameList *list, int play);
int FRAME_LIST_ReadTouch(FrameList *list);
int FRAME_LIST_ReadKeys(FrameList *list);
int FRAME_LIST_HandleInput(FrameList *list);
void FRAME_LIST_UpdateHoldStage(FrameList *list);
u8 FRAME_LIST_GetStepFrames(const FrameList *list, int speed);
int FRAME_LIST_GetScrollRoom(const FrameList *list, int speed);
void FRAME_LIST_StartScroll(FrameList *list, s8 speed, u8 steps, u16 returnState, u32 playSe);
int FRAME_LIST_StepScroll(FrameList *list);
void FRAME_LIST_BeginScrollBarDrag(FrameList *list, int rectIndex);
u32 FRAME_LIST_GetScrollBarRow(FrameList *list);
void FRAME_LIST_FindScrollBarEntry(FrameList *list, u8 *outX, u8 *outY);
int FRAME_LIST_GetScrollBarTop(FrameList *list);
int FRAME_LIST_ClampToScrollBar(FrameList *list, unsigned int touchY);
int FRAME_LIST_StepScrollBarDrag(FrameList *list);
void FRAME_LIST_BeginRowDrag(FrameList *list, int row);
int FRAME_LIST_StepRowDrag(FrameList *list);
int FRAME_LIST_StartJump(FrameList *list, int row);
int FRAME_LIST_StartFlick(FrameList *list);
int FRAME_LIST_ClampBgFrameId(int bgFrame);
void FRAME_LIST_UploadRowTiles(FrameList *list, u32 item, u32 windowIndex);
void FRAME_LIST_ScrollBgRows(FrameList *list, int windowIndex, s8 y);
void FRAME_LIST_ClearBgRows(FrameList *list, u32 layer, s8 y);
signed char FRAME_LIST_GetRowPosition(const FrameList *list, int step);
signed char FRAME_LIST_WrapIndex(signed char index, signed char limit, int step);
void FRAME_LIST_DrawRowA(FrameList *list, int item, s8 y);
void FRAME_LIST_DrawRowB(FrameList *list, int item, s8 y);
void FRAME_LIST_SetRowPalette(FrameList *list, int row, u32 pltt);
void FRAME_LIST_SetCursorHighlight(FrameList *list, u32 newRow, u32 oldRow);
void FRAME_LIST_UpdateWindows(FrameList *list);
struct PrintSys *FRAME_LIST_GetPrinter(FrameList *list);
u32 FRAME_LIST_GetItemValue(FrameList *list, int index);
int FRAME_LIST_GetSelectedIndex(FrameList *list);
int FRAME_LIST_GetCursor(FrameList *list);
int FRAME_LIST_GetScrollPos(FrameList *list);
int FRAME_LIST_CanScrollDown(FrameList *list);
void func_021B93D4(FrameList *list, int row);
void func_021B940C(FrameList *list);
void func_021B941C(FrameList *list);
extern const char gFrameListSourceFile[];
extern const u8 gFrameListFlickSteps[];
extern const u8 gFrameListFlickThresholds[][6];


/*
 * Builds the list object from the caller's parameters: allocates the item and
 * map tables, one background window per visible row (twice that with a second
 * layer), and copies the touch regions. The rowRemainder loop is the compound
 * `-=`: it keeps &list->rowRemainder in a register for the body's load and
 * store, while the test reloads through list.
 */
FrameList *FRAME_LIST_Create(const FrameListParams *params, u32 heapId)
{
    FrameList *list;
    u32 index;
    u32 entryCount;

    list = func_02030734(heapId, sizeof(FrameList), 1, gFrameListSourceFile, 0xf5);
    list->params = *params;
    list->heapId = heapId;
    list->touchY = -1;
    list->prevTouchY = -1;
    list->printer = PRINTSYS_QUE_CreateEx(0x800, heapId);
    list->cursorAnim = BLINK_PALANM_Create(list->params.cursorPltt << 4, 0x10, list->params.bgLayer, list->heapId);
    list->items = func_02030734(list->heapId, list->params.itemCount * 8, 1, gFrameListSourceFile, 0x104);
    if (list->params.mapCount != 0) {
        list->maps = func_02030734(list->heapId, list->params.mapCount * 4, 0, gFrameListSourceFile, 0x109);
        for (index = 0; index < list->params.mapCount; index++)
            list->maps[index] = func_02030734(list->heapId, list->params.tileWidth * list->params.rowHeight * 2, 0, gFrameListSourceFile, 0x10b);
    }
    list->windowCount = 0x18 / list->params.rowHeight + 2;
    list->windowCountHalf = list->windowCount;
    if (list->params.bgLayerB != 0xff)
        list->windowCount = list->windowCount * 2;
    list->frameMgr = BGWINFRM_Create(2, list->windowCount, list->heapId);
    list->windows = func_02030734(list->heapId, list->windowCount * 8, 0, gFrameListSourceFile, 0x117);
    for (index = 0; index < list->windowCount; index++) {
        if (list->params.bgLayerB != 0xff && list->windowCountHalf <= index) {
            BGWINFRM_AddFrame(list->frameMgr, index, list->params.bgLayerB, list->params.tileWidth, list->params.rowHeight);
            list->windows[index].window = BMP_WIN_Create(list->params.bgLayerB, list->params.winX, list->params.winY, list->params.winW, list->params.winH, list->params.winPltt, 1);
        } else {
            BGWINFRM_AddFrame(list->frameMgr, index, list->params.bgLayer, list->params.tileWidth, list->params.rowHeight);
            list->windows[index].window = BMP_WIN_Create(list->params.bgLayer, list->params.winX, list->params.winY, list->params.winW, list->params.winH, list->params.winPltt, 1);
        }
    }
    list->rowRemainder = 0x18;
    do {
        list->rowRemainder -= (s8)list->params.rowHeight;
    } while (list->rowRemainder > 0);
    if (list->params.hitEntries != 0) {
        entryCount = 0;
        for (;;) {
            if (list->params.hitEntries[entryCount].left == 0xff)
                break;
            entryCount++;
        }
        list->hitRects = func_02030734(list->heapId, (entryCount + 1) * 4, 0, gFrameListSourceFile, 0x13e);
        for (index = 0; index < entryCount + 1; index++)
            MIi_CpuCopy32(&list->params.hitEntries[index], &list->hitRects[index], 4);
    }
    return list;
}


void FRAME_LIST_Delete(FrameList *list)
{
    u32 index;

    ENV_SetResourceSet(list->hitRects);
    for (index = 0; index < list->windowCount; index++)
        BMP_WIN_Delete(list->windows[index].window);
    ENV_SetResourceSet(list->windows);
    BGWINFRM_Delete(list->frameMgr);
    if (list->params.mapCount != 0) {
        for (index = 0; index < list->params.mapCount; index++)
            ENV_SetResourceSet(list->maps[index]);
        ENV_SetResourceSet(list->maps);
    }
    ENV_SetResourceSet(list->items);
    func_0202EA20(list->cursorAnim);
    PRINTSYS_QUE_Delete(list->printer);
    ENV_SetResourceSet(list);
}


void FRAME_LIST_AddItem(FrameList *list, unsigned mapIndex, unsigned value)
{
    list->items[list->totalItems].mapIndex = mapIndex;
    list->items[list->totalItems].value = value;
    list->totalItems++;
}


/*
 * Copies map number mapSlot out of a loaded file. func_02049EF4 keeps r3 in
 * r5 and forwards it unchanged to 02062B30, which writes through it, so the
 * out parameter is a full-word pointer. The file has a 0xC byte header.
 */
void FRAME_LIST_CopyMapToBuffer(FrameList *list, void *source, u32 fileIndex, u32 memberIndex, u32 mapSlot)
{
    void *data;
    void *handle;
    handle = func_02049EF4(source, fileIndex, memberIndex, &data, list->heapId);
    MIi_CpuCopy16((u8 *)data + 0xc, list->maps[mapSlot], list->params.tileWidth * list->params.rowHeight * 2);
    func_020307B0(handle);
}

void FRAME_LIST_LoadPalettes(FrameList *list, u8 *palettes, u32 firstSlot, u32 srcSlot, u32 slotCount)
{
    BLINK_PALANM_LoadPalettes(list->cursorAnim, palettes, firstSlot, srcSlot << 4, slotCount << 4);
}


int FRAME_LIST_UpdateInit(FrameList *list)
{
    switch (list->state) {
    case 0:
        FRAME_LIST_ClampScroll(list);
        FRAME_LIST_Redraw(list, 0);
        list->state = list->state + 1;
        break;
    case 1:
        if (PRINTSYS_QUE_IsFinished(list->printer) == 1) {
            list->state = 0;
            return 0;
        }
        break;
    }
    FRAME_LIST_UpdateWindows(list);
    return 1;
}


int FRAME_LIST_Update(FrameList *list)
{
    u32 touchX;
    int result = -1;

    if (TOUCHPANEL_GetPointCont(&touchX, &list->touchY) == 0) {
        list->touchY = -1;
        list->ready = 0;
    }
    switch (list->state) {
    case 0:
        result = FRAME_LIST_HandleInput(list);
        break;
    case 1:
        if (FRAME_LIST_StepScroll(list) == 1)
            result = -10;
        break;
    case 2:
        if (FRAME_LIST_StepScrollBarDrag(list) == 1)
            result = -9;
        break;
    case 3:
        if (FRAME_LIST_StepRowDrag(list) == 1)
            result = -8;
        break;
    case 4:
        if (func_020355C4() == 0 && (KEY_GetTrg() & 1))
            result = list->cursor;
        if (list->repeatDelay == 0)
            list->state = 0;
        else
            list->repeatDelay--;
        break;
    }
    list->prevTouchY = list->touchY;
    BLINK_PALANM_Update(list->cursorAnim);
    FRAME_LIST_UpdateWindows(list);
    return result;
}


void FRAME_LIST_ClampScroll(FrameList *list)
{
    if (list->params.visibleRows > list->totalItems) {
        list->visibleCount = list->totalItems;
    } else {
        list->visibleCount = list->params.visibleRows;
    }
    if (list->totalItems < list->params.visibleRows) {
        list->scrollMax = 0;
    } else {
        list->scrollMax = list->totalItems - list->params.visibleRows;
    }
    if (list->params.initialCursor > list->visibleCount || list->params.initialScroll > list->scrollMax) {
        list->cursor = 0;
        list->scrollPos = 0;
    } else {
        list->cursor = list->params.initialCursor;
        list->scrollPos = list->params.initialScroll;
    }
}


/*
 * Draws the visible rows of both layers and moves the cursor highlight.
 * rowHeight is a u8 read as (s8) in every loop step; the one uncast read in
 * the second layer's start (`firstRow + 0x18 - rowHeight`) is what makes the
 * original load it with ldrb and sign-extend the CSE'd copy for the loop. All
 * four loops are `for (;;) { if (!cond) break; ... }` (top test, unconditional
 * branch back).
 */
void FRAME_LIST_Redraw(FrameList *list, int play)
{
    s16 item;
    s8 rowY;

    BG_SYS_ResetSlot(list->params.bgLayer, 3, 0);
    list->pixelOffset = 0;
    item = list->scrollPos;
    rowY = list->params.firstRow;
    for (;;) {
        if (item == 0 || rowY <= 0)
            break;
        item = item - 1;
        rowY = rowY - (s8)list->params.rowHeight;
    }
    list->ringA = 0;
    for (;;) {
        if (rowY >= 0x18)
            break;
        FRAME_LIST_DrawRowA(list, item, rowY);
        list->ringA++;
        item = item + 1;
        rowY = rowY + (s8)list->params.rowHeight;
    }
    list->ringSizeA = list->ringA;
    if (list->params.bgLayerB == 0xff)
        return;
    BG_SYS_ResetSlot(list->params.bgLayerB, 3, 0);
    rowY = list->params.firstRow + 0x18 - list->params.rowHeight;
    item = list->scrollPos - 1;
    for (;;) {
        if (rowY <= 0)
            break;
        item = item - 1;
        rowY = rowY - (s8)list->params.rowHeight;
    }
    list->ringB = 0;
    for (;;) {
        if (rowY >= 0x18)
            break;
        FRAME_LIST_DrawRowB(list, item, rowY);
        list->ringB++;
        item = item + 1;
        rowY = rowY + (s8)list->params.rowHeight;
    }
    list->ringSizeB = list->ringB;
    FRAME_LIST_SetCursorHighlight(list, (u16)list->cursor, 0xff);
    list->params.ops->onCursor(list->params.userData, list->cursor + list->scrollPos, play);
}


/*
 * The case-8 arm is laid out first in the original (the jump table's last
 * entry is its smallest displacement), so it is written first in the switch.
 */
int FRAME_LIST_ReadTouch(FrameList *list)
{
    int hitIndex;
    u8 savedTouchMode;

    if (list->hitRects == 0)
        return FRAME_LIST_EVENT_NONE;
    hitIndex = TOUCHPANEL_HitTrg(list->hitRects);
    if (hitIndex == -1)
        return FRAME_LIST_EVENT_NONE;
    savedTouchMode = func_020355C4();
    func_020355D8(1);
    switch (list->params.hitEntries[hitIndex].kind) {
    case FRAME_LIST_HIT_ROW_CONFIRM:
        if (hitIndex >= list->visibleCount)
            return FRAME_LIST_EVENT_IGNORED;
        list->prevCursor = list->cursor;
        list->cursor = hitIndex;
        return FRAME_LIST_EVENT_CONFIRM;
    case FRAME_LIST_HIT_ROW:
        if (hitIndex >= list->visibleCount)
            return FRAME_LIST_EVENT_IGNORED;
        list->prevCursor = list->cursor;
        list->cursor = hitIndex;
        return FRAME_LIST_EVENT_ROW_TOUCH;
    case FRAME_LIST_HIT_SCROLL_BAR:
        if (list->totalItems > list->visibleCount) {
            list->tappedRow = hitIndex;
            list->prevCursor = list->cursor;
            return FRAME_LIST_EVENT_SCROLL_BAR;
        }
        func_020355D8(savedTouchMode);
        break;
    case FRAME_LIST_HIT_ARROW_UP:
        if (list->scrollPos != 0) {
            list->holdStage = 0;
            return FRAME_LIST_EVENT_ARROW_UP;
        }
        break;
    case FRAME_LIST_HIT_ARROW_DOWN:
        if (list->scrollPos < list->scrollMax) {
            list->holdStage = 0;
            return FRAME_LIST_EVENT_ARROW_DOWN;
        }
        break;
    case FRAME_LIST_HIT_PAGE_UP:
        if (list->scrollPos != 0)
            return FRAME_LIST_EVENT_PAGE_UP;
        if (list->cursor != 0) {
            list->prevCursor = list->cursor;
            list->cursor = 0;
            return FRAME_LIST_EVENT_CURSOR_TOP;
        }
        break;
    case FRAME_LIST_HIT_PAGE_DOWN:
        if (list->scrollPos < list->scrollMax)
            return FRAME_LIST_EVENT_PAGE_DOWN;
        if (list->cursor < list->visibleCount - 1) {
            list->prevCursor = list->cursor;
            list->cursor = list->visibleCount - 1;
            return FRAME_LIST_EVENT_CURSOR_BOTTOM;
        }
        break;
    case FRAME_LIST_HIT_JUMP_TOP:
        if (list->cursor != 0 || list->scrollPos != 0)
            return FRAME_LIST_EVENT_JUMP_TOP;
        break;
    case FRAME_LIST_HIT_JUMP_BOTTOM:
        if (list->cursor != list->visibleCount - 1 || list->scrollPos != list->scrollMax)
            return FRAME_LIST_EVENT_JUMP_BOTTOM;
        break;
    }
    return FRAME_LIST_EVENT_NONE;
}


/*
 * The d-pad up/down arms re-read cursor after the prevCursor store
 * (`list->cursor--` / `++`); the down arm loads visibleCount before cursor
 * and still compares cursor on the left, which only the named bound
 * `lastRow = list->visibleCount - 1` gives.
 */
int FRAME_LIST_ReadKeys(FrameList *list)
{
    int lastRow;

    if ((KEY_GetTrg() & 0x3f1) && func_020355C4() == 1) {
        func_020355D8(0);
        list->prevCursor = 0xff;
        list->repeatDelay = 8;
        return FRAME_LIST_EVENT_KEY_MODE;
    }
    if (KEY_GetCont() == 0) {
        list->holdFrames = 0;
        list->holdStage = 6;
    }
    if (KEY_GetCont() & 0x40) {
        func_020355D8(0);
        if (list->cursor != 0) {
            list->prevCursor = list->cursor;
            list->cursor--;
            list->repeatDelay = 8;
            return FRAME_LIST_EVENT_CURSOR_STEP;
        }
        if (list->scrollPos != 0) {
            list->repeatDelay = 0;
            FRAME_LIST_UpdateHoldStage(list);
            return FRAME_LIST_EVENT_ARROW_UP;
        }
        return FRAME_LIST_EVENT_NONE;
    }
    if (KEY_GetCont() & 0x80) {
        func_020355D8(0);
        lastRow = list->visibleCount - 1;
        if (list->cursor < lastRow) {
            list->prevCursor = list->cursor;
            list->cursor++;
            list->repeatDelay = 8;
            return FRAME_LIST_EVENT_CURSOR_STEP;
        }
        if (list->scrollPos < list->scrollMax) {
            list->repeatDelay = 0;
            FRAME_LIST_UpdateHoldStage(list);
            return FRAME_LIST_EVENT_ARROW_DOWN;
        }
        return FRAME_LIST_EVENT_NONE;
    }
    if (KEY_GetCont() & 0x20) {
        func_020355D8(0);
        if (list->scrollPos != 0) {
            list->repeatDelay = 4;
            return FRAME_LIST_EVENT_PAGE_UP;
        }
        if (list->cursor != 0) {
            list->prevCursor = list->cursor;
            list->cursor = 0;
            list->repeatDelay = 4;
            return FRAME_LIST_EVENT_CURSOR_TOP;
        }
        return FRAME_LIST_EVENT_NONE;
    }
    if (KEY_GetCont() & 0x10) {
        func_020355D8(0);
        if (list->scrollPos < list->scrollMax) {
            list->repeatDelay = 4;
            return FRAME_LIST_EVENT_PAGE_DOWN;
        }
        if (list->cursor < list->visibleCount - 1) {
            list->prevCursor = list->cursor;
            list->cursor = list->visibleCount - 1;
            list->repeatDelay = 4;
            return FRAME_LIST_EVENT_CURSOR_BOTTOM;
        }
        return FRAME_LIST_EVENT_NONE;
    }
    if (KEY_GetTrg() & 1)
        return FRAME_LIST_EVENT_CONFIRM;
    if (KEY_GetTrg() & 0x200) {
        func_020355D8(0);
        if (list->cursor != 0 || list->scrollPos != 0)
            return FRAME_LIST_EVENT_JUMP_TOP;
        return FRAME_LIST_EVENT_NONE;
    }
    if (KEY_GetTrg() & 0x100) {
        func_020355D8(0);
        if (list->cursor != list->visibleCount - 1 || list->scrollPos != list->scrollMax)
            return FRAME_LIST_EVENT_JUMP_BOTTOM;
        return FRAME_LIST_EVENT_NONE;
    }
    return FRAME_LIST_EVENT_NONE;
}


int FRAME_LIST_HandleInput(FrameList *list)
{
    int event;
    s16 steps;

    if (PRINTSYS_QUE_IsFinished(list->printer) == 0)
        return -1;
    event = FRAME_LIST_ReadTouch(list);
    if (event == FRAME_LIST_EVENT_NONE)
        event = FRAME_LIST_ReadKeys(list);
    switch (event) {
    case FRAME_LIST_EVENT_KEY_MODE:
        GFL_USE_PlaySeDefaultVolume(0x548);
        FRAME_LIST_SetCursorHighlight(list, (u16)list->cursor, (u16)list->prevCursor);
        list->params.ops->onCursor(list->params.userData, list->cursor + list->scrollPos, 1);
        list->state = 4;
        return -12;
    case FRAME_LIST_EVENT_CURSOR_STEP:
        GFL_USE_PlaySeDefaultVolume(0x548);
        FRAME_LIST_SetCursorHighlight(list, (u16)list->cursor, (u16)list->prevCursor);
        list->params.ops->onCursor(list->params.userData, list->cursor + list->scrollPos, 1);
        list->state = 4;
        return -11;
    case FRAME_LIST_EVENT_ARROW_UP:
        FRAME_LIST_StartScroll(list, (s8)(-list->params.stepTable[list->holdStage]), 1, 4, 1);
        return -10;
    case FRAME_LIST_EVENT_ARROW_DOWN:
        FRAME_LIST_StartScroll(list, (s8)list->params.stepTable[list->holdStage], 1, 4, 1);
        return -10;
    case FRAME_LIST_EVENT_PAGE_UP:
        steps = list->visibleCount;
        list->prevCursor = list->cursor;
        if (list->scrollPos - steps < 0) {
            list->cursor = 0;
            steps = list->scrollPos;
        }
        FRAME_LIST_SetCursorHighlight(list, (u16)0xff, (u16)list->prevCursor);
        FRAME_LIST_StartScroll(list, (s8)(-list->params.stepTable[0]), steps, 4, 0);
        GFL_USE_PlaySeDefaultVolume(0x548);
        return -7;
    case FRAME_LIST_EVENT_PAGE_DOWN:
        steps = list->visibleCount;
        list->prevCursor = list->cursor;
        if (list->scrollPos + steps > list->scrollMax) {
            list->cursor = list->visibleCount - 1;
            steps = list->scrollMax - list->scrollPos;
        }
        FRAME_LIST_SetCursorHighlight(list, (u16)0xff, (u16)list->prevCursor);
        FRAME_LIST_StartScroll(list, (s8)list->params.stepTable[0], steps, 4, 0);
        GFL_USE_PlaySeDefaultVolume(0x548);
        return -6;
    case FRAME_LIST_EVENT_CURSOR_TOP:
        GFL_USE_PlaySeDefaultVolume(0x548);
        FRAME_LIST_SetCursorHighlight(list, (u16)list->cursor, (u16)list->prevCursor);
        list->params.ops->onCursor(list->params.userData, list->cursor + list->scrollPos, 1);
        list->state = 4;
        return -5;
    case FRAME_LIST_EVENT_CURSOR_BOTTOM:
        GFL_USE_PlaySeDefaultVolume(0x548);
        FRAME_LIST_SetCursorHighlight(list, (u16)list->cursor, (u16)list->prevCursor);
        list->params.ops->onCursor(list->params.userData, list->cursor + list->scrollPos, 1);
        list->state = 4;
        return -4;
    case FRAME_LIST_EVENT_JUMP_TOP:
        list->cursor = 0;
        list->scrollPos = 0;
        FRAME_LIST_Redraw(list, 1);
        GFL_USE_PlaySeDefaultVolume(0x548);
        return -3;
    case FRAME_LIST_EVENT_JUMP_BOTTOM:
        list->cursor = list->visibleCount - 1;
        list->scrollPos = list->scrollMax;
        FRAME_LIST_Redraw(list, 1);
        GFL_USE_PlaySeDefaultVolume(0x548);
        return -2;
    case FRAME_LIST_EVENT_SCROLL_BAR:
        FRAME_LIST_SetCursorHighlight(list, (u16)0xff, (u16)list->prevCursor);
        FRAME_LIST_BeginScrollBarDrag(list, list->tappedRow);
        GFL_USE_PlaySeDefaultVolume(0x645);
        return -9;
    case FRAME_LIST_EVENT_ROW_TOUCH:
        FRAME_LIST_SetCursorHighlight(list, (u16)0xff, (u16)list->prevCursor);
        list->params.ops->onCursor(list->params.userData, list->cursor + list->scrollPos, 1);
        FRAME_LIST_BeginRowDrag(list, list->cursor);
        GFL_USE_PlaySeDefaultVolume(0x645);
        return -8;
    case FRAME_LIST_EVENT_CONFIRM:
        if (func_020355C4() == 1) {
            FRAME_LIST_SetCursorHighlight(list, (u16)list->cursor, (u16)list->prevCursor);
            list->params.ops->onCursor(list->params.userData, list->cursor + list->scrollPos, 1);
        }
        return list->cursor;
    case FRAME_LIST_EVENT_IGNORED:
    case FRAME_LIST_EVENT_NONE:
        break;
    }
    return -1;
}


void FRAME_LIST_UpdateHoldStage(FrameList *list)
{
    u8 frames;
    if (list->holdFrames < 20) {
        list->holdFrames = list->holdFrames + 1;
    }
    frames = list->holdFrames;
    if (frames == 20) {
        list->holdStage = 0;
    } else if (frames >= 16) {
        list->holdStage = 1;
    } else if (frames >= 12) {
        list->holdStage = 2;
    } else if (frames >= 8) {
        list->holdStage = 3;
    } else if (frames >= 4) {
        list->holdStage = 4;
    } else {
        list->holdStage = 5;
    }
}


/*
 * extent: trailing two-byte alignment padding at 0x021B841A.
 * Zero divisors remain admitted; call the ROM runtime helper directly.
 */
u8 FRAME_LIST_GetStepFrames(const FrameList *list, int speed)
{
    if (speed < 0) speed = (int)(0u - (unsigned int)speed);
    return _s32_div_f(list->params.rowHeight << 3, speed);
}


int FRAME_LIST_GetScrollRoom(const FrameList *list, int speed)
{
    if (speed < 0) return list->scrollPos;
    return list->scrollMax - list->scrollPos;
}


void FRAME_LIST_StartScroll(FrameList *list, s8 speed, u8 steps, u16 returnState, u32 playSe)
{
    list->scrollSpeed = speed;
    list->stepsLeft = steps;
    list->stepFramesLeft = 0;
    list->returnState = returnState;
    list->state = 1;
    list->playScrollSe = playSe;
}


#pragma opt_propagation off


/*
 * Per-frame scroll step. The touch-tap test reads the hit table's kind field
 * through hitBase = hitEntries + 4 and hitOffset = row * 8 under
 * `opt_propagation off`: the original forms base + 4 as its own value and loads
 * with a register offset; every field-access spelling folds the +4 into the
 * load instead.
 * stand-in: hitBase/hitOffset replace `list->params.hitEntries[hitRow].kind`
 * (5 bytes differ with the field form).
 */
int FRAME_LIST_StepScroll(FrameList *list)
{
    int hitRow, room, rowDist, absDelta;
    s8 rowY;
    const u8 *hitBase;
    int hitOffset;

    if (PRINTSYS_QUE_IsFinished(list->printer) == 0) return 1;
    if (list->returnState == 3 && list->flicking == 1) {
        hitRow = TOUCHPANEL_HitCont(list->hitRects);
        if (list->drag == 1) {
            if (list->trigger == 0) {
                if (hitRow == -1) {
                    list->dragDelta = list->dragLastY - list->dragStartY;
                    absDelta = list->dragDelta;
                    if (absDelta < 0) absDelta = -absDelta;
                    if (absDelta >= 16) {
                        list->dragFrames = 0;
                        list->drag = 0;
                        list->trigger = 1;
                    }
                } else if (list->dragFrames != 3) {
                    list->dragStartY = list->touchY;
                    list->dragFrames++;
                }
            }
        } else if (hitRow != -1 && list->params.hitEntries[hitRow].kind == FRAME_LIST_HIT_ROW) {
            list->cursor = hitRow;
            list->drag = 1;
            list->dragFrames = 0;
            list->dragStartY = list->touchY;
            list->dragLastY = list->touchY;
        }
    }
    if (list->stepFramesLeft == 0) {
        if (list->stepsLeft == 0) {
            hitRow = TOUCHPANEL_HitCont(list->hitRects);
            if (hitRow != -1 &&
                (hitOffset = hitRow * 8, hitBase = (const u8 *)list->params.hitEntries + 4, *(u32 *)(hitBase + hitOffset) == 0) &&
                list->ready == 1 && *(u32 *)(hitBase + hitOffset) == 0 &&
                ((list->dragDelta < 0 && list->dragAnchorRow < hitRow) || (list->dragDelta > 0 && list->dragAnchorRow > hitRow))) {
                list->ready = 0;
                room = FRAME_LIST_GetScrollRoom(list, list->scrollSpeed);
                if (room != 0) {
                    rowDist = list->dragAnchorRow - hitRow;
                    if (rowDist < 0) rowDist = -rowDist;
                    list->stepsLeft = rowDist;
                    if (list->stepsLeft > (u32)room) list->stepsLeft = room;
                    list->dragAnchorRow = hitRow;
                } else {
                    list->dragStartY = list->touchY;
                    list->dragLastY = list->touchY;
                    list->drag = 0;
                    FRAME_LIST_SetCursorHighlight(list, (u16)list->cursor, 255);
                    list->state = list->returnState;
                    return 0;
                }
            } else {
                list->dragStartY = list->touchY;
                list->dragLastY = list->touchY;
                list->ready = 0;
                list->drag = 0;
                FRAME_LIST_SetCursorHighlight(list, (u16)list->cursor, 255);
                list->state = list->returnState;
                return 0;
            }
        }
        FRAME_LIST_SetCursorHighlight(list, 255, (u16)list->cursor);
        if (list->returnState == 3) {
            if (list->flicking == 0) {
                if (list->scrollSpeed < 0) list->cursor++;
                else list->cursor--;
            } else {
                if (list->trigger == 1) {
                    if (FRAME_LIST_StartFlick(list) == 1) list->dragFrames = 0;
                    list->trigger = 0;
                }
                if (list->drag == 1 && list->dragFrames == 3) {
                    hitRow = TOUCHPANEL_HitCont(list->hitRects);
                    if (hitRow != -1 && list->params.hitEntries[hitRow].kind == FRAME_LIST_HIT_ROW) list->cursor = hitRow;
                    list->flicking = 0;
                    list->dragAnchorRow = list->cursor;
                    list->drag = 0;
                    list->dragFrames = 0;
                    list->dragStartY = list->touchY;
                    list->dragLastY = list->touchY;
                    list->params.ops->onCursor(list->params.userData, list->cursor+list->scrollPos, 1);
                    list->state = list->returnState;
                    return 0;
                }
                if (list->stepsLeft == 1) {
                    room = FRAME_LIST_GetScrollRoom(list, list->scrollSpeed);
                    list->speedIndex++;
                    if (list->speedIndex != 6) {
                        if (list->scrollSpeed < 0) list->scrollSpeed = -list->params.stepTable[list->speedIndex];
                        else list->scrollSpeed = list->params.stepTable[list->speedIndex];
                        list->stepsLeft = gFrameListFlickSteps[list->speedIndex];
                    }
                    if (list->stepsLeft > (u32)room) list->stepsLeft = room;
                }
            }
        }
        list->stepFramesLeft = FRAME_LIST_GetStepFrames(list, list->scrollSpeed);
        list->stepsLeft--;
        if (list->scrollSpeed < 0) {
            list->scrollPos--;
            rowY = FRAME_LIST_GetRowPosition(list, -1);
            FRAME_LIST_DrawRowA(list, list->scrollPos, rowY);
            list->ringA = FRAME_LIST_WrapIndex(list->ringA, list->ringSizeA, -1);
            rowY = FRAME_LIST_GetRowPosition(list, -1);
            FRAME_LIST_DrawRowB(list, list->scrollPos-list->ringSizeB, list->rowRemainder+rowY);
            list->ringB = FRAME_LIST_WrapIndex(list->ringB, list->ringSizeB, -1);
        } else {
            list->scrollPos++;
            rowY = FRAME_LIST_GetRowPosition(list, 1);
            FRAME_LIST_DrawRowA(list, list->scrollPos+(list->ringSizeA-1), rowY);
            list->ringA = FRAME_LIST_WrapIndex(list->ringA, list->ringSizeA, 1);
            rowY = FRAME_LIST_GetRowPosition(list, 1);
            FRAME_LIST_DrawRowB(list, list->scrollPos-1, list->rowRemainder+rowY);
            list->ringB = FRAME_LIST_WrapIndex(list->ringB, list->ringSizeB, 1);
        }
        list->params.ops->onCursor(list->params.userData, list->cursor+list->scrollPos, 1);
        if (list->playScrollSe == 1) {
            if ((u16)(list->returnState+0xfffe) <= 1) GFL_USE_PlaySeDefaultVolume(0x645);
            else GFL_USE_PlaySeDefaultVolume(0x548);
        }
    }
    list->pixelOffset = list->pixelOffset+list->scrollSpeed;
    BG_SYS_ResetSlot(list->params.bgLayer, 3, list->pixelOffset);
    if (list->params.bgLayerB != 255) BG_SYS_ResetSlot(list->params.bgLayerB, 3, list->pixelOffset);
    list->params.ops->onScroll(list->params.userData, list->scrollSpeed);
    list->stepFramesLeft--;
    return 1;
}


#pragma opt_propagation reset


void FRAME_LIST_BeginScrollBarDrag(FrameList *list, int rectIndex)
{
    u32 touchX;
    struct FrameListHitRect *rect;
    int bound;
    unsigned edge;

    list->scrollBarX = list->hitRects[rectIndex].left;
    rect = list->hitRects + rectIndex;
    list->scrollBarY = rect->top;
    list->scrollBarRect[0] = list->hitRects[rectIndex].left;
    list->scrollBarRect[1] = rect->top;
    list->scrollBarRect[2] = rect->right;
    list->scrollBarRect[3] = rect->bottom;
    edge = list->scrollBarRect[0];
    if (edge >= 0x20)
        edge -= 0x20;
    else
        edge = 0;
    list->scrollBarRect[0] = edge;
    bound = list->scrollBarRect[1] + 0x20;
    if (bound <= 0xbf)
        list->scrollBarRect[1] = bound;
    else
        list->scrollBarRect[1] = 0xbf;
    edge = list->scrollBarRect[2];
    if (edge < 0)
        edge = 0;
    list->scrollBarRect[2] = edge;
    bound = list->scrollBarRect[3];
    if (bound <= 0xff)
        list->scrollBarRect[3] = bound;
    else
        list->scrollBarRect[3] = 0xff;
    list->scrollBarRect[4] = 0xff;
    if (TOUCHPANEL_GetPointCont(&touchX, &list->scrollBarTouchY) == 0)
        list->scrollBarTouchY = -1;
    list->scrollBarDrag = 1;
    list->state = 2;
}


u32 FRAME_LIST_GetScrollBarRow(FrameList *list)
{
    u32 touchX;
    u32 touchY;

    if (TOUCHPANEL_GetPointCont(&touchX, &touchY) == 0)
        touchY = list->scrollBarTouchY;
    list->scrollBarTouchY = -1;
    return COMM_HISTORY_ScaleValue(list->scrollMax, touchY, list->scrollBarX, list->scrollBarY, list->params.scrollBarPad);
}


void FRAME_LIST_FindScrollBarEntry(FrameList *list, u8 *outX, u8 *outY)
{
    u8 index;
    const struct FrameListHitEntry *entries;
    u8 left;
    entries = list->params.hitEntries;
    for (index = 0; ; index++) {
        left = entries[index].left;
        if (left == 0xff) break;
        if (entries[index].kind == FRAME_LIST_HIT_SCROLL_BAR) {
            *outX = left;
            *outY = list->params.hitEntries[index].top;
            return;
        }
    }
}


int FRAME_LIST_GetScrollBarTop(FrameList *list)
{
    u8 barX, barY;
    FRAME_LIST_FindScrollBarEntry(list, &barX, &barY);
    return COMM_HISTORY_ScaleSpan(list->scrollMax, list->scrollPos, barX, barY, list->params.scrollBarPad);
}


int FRAME_LIST_ClampToScrollBar(FrameList *list, unsigned int touchY)
{
    u8 barX, barY;
    u32 touchX, touchYOut;
    unsigned int slotStart, slotEnd;

    if (list->scrollBarDrag == 1) {
        if (TOUCHPANEL_HitCont(&list->scrollBarRect) != -1) {
            TOUCHPANEL_GetPointCont(&touchX, &touchYOut);
            return touchYOut;
        }
        return touchY;
    }
    FRAME_LIST_FindScrollBarEntry(list, &barX, &barY);
    slotStart = COMM_HISTORY_ScaleSpan(list->scrollMax, list->scrollPos, barX, barY, list->params.scrollBarPad);
    if (list->scrollMax == list->scrollPos)
        slotEnd = barY;
    else
        slotEnd = COMM_HISTORY_ScaleSpan(list->scrollMax, list->scrollPos + 1, barX, barY, list->params.scrollBarPad);
    if (touchY >= slotStart && touchY < slotEnd)
        return touchY;
    return slotStart;
}


int FRAME_LIST_StepScrollBarDrag(FrameList *list)
{
    u32 targetPos;
    u32 dist;

    if (PRINTSYS_QUE_IsFinished(list->printer) == 0)
        return 1;
    if (TOUCHPANEL_HitCont(&list->scrollBarRect) == -1 && list->scrollBarTouchY == -1) {
        list->scrollBarDrag = 0;
        list->state = 0;
        return 0;
    }
    targetPos = FRAME_LIST_GetScrollBarRow(list);
    dist = list->scrollPos - targetPos;
    if ((int)dist < 0)
        dist = -dist;
    if (dist > list->ringSizeA)
        dist = list->ringSizeA;
    if (list->scrollPos > targetPos) {
        list->scrollPos = targetPos + dist;
        FRAME_LIST_StartScroll(list, (s8)(-list->params.stepTable[0]), dist, 2, 1);
    } else if (list->scrollPos < targetPos) {
        list->scrollPos = targetPos - dist;
        FRAME_LIST_StartScroll(list, (s8)list->params.stepTable[0], dist, 2, 1);
    }
    return 1;
}


void FRAME_LIST_BeginRowDrag(FrameList *list, int row)
{
    u32 touchY;

    list->dragPhase = 0;
    list->dragAnchorRow = row;
    list->dragFrames = 0;
    touchY = list->touchY;
    list->flicking = 0;
    list->dragStartY = touchY;
    list->dragLastY = touchY;
    list->state = 3;
}


int FRAME_LIST_StepRowDrag(FrameList *list)
{
    int hitRow;

    if (PRINTSYS_QUE_IsFinished(list->printer) == 0)
        return 1;
    hitRow = TOUCHPANEL_HitCont(list->hitRects);
    switch (list->dragPhase) {
    case 0:
        if (hitRow == -1) {
            if (list->dragStartY != -1 && list->dragLastY != -1) {
                list->dragDelta = list->dragLastY - list->dragStartY;
                list->dragFrames = 0;
                if (FRAME_LIST_StartFlick(list) == 1)
                    break;
            }
            list->flicking = 0;
            list->state = 0;
            return 0;
        }
        if (list->params.hitEntries[hitRow].kind != FRAME_LIST_HIT_ROW) {
            if (list->dragStartY != -1 && list->dragLastY != -1) {
                list->dragDelta = list->dragLastY - list->dragStartY;
                list->dragFrames = 0;
                if (FRAME_LIST_StartFlick(list) == 1)
                    break;
            }
            list->flicking = 0;
            list->state = 0;
            return 0;
        }
        if (list->dragAnchorRow != hitRow) {
            list->dragRow = hitRow;
            list->dragDelta = list->dragAnchorRow - hitRow;
            list->dragFrames = 0;
            list->dragPhase = 1;
        }
        list->dragLastY = list->dragStartY;
        list->dragStartY = list->touchY;
        break;
    case 1:
        if (hitRow == -1) {
            list->dragPhase = 0;
            return FRAME_LIST_StartFlick(list);
        }
        if (list->params.hitEntries[hitRow].kind != FRAME_LIST_HIT_ROW) {
            list->dragPhase = 0;
            return FRAME_LIST_StartFlick(list);
        }
        if (list->dragFrames == 5) {
            list->dragFrames = 0;
            list->dragPhase = 0;
            if (FRAME_LIST_StartJump(list, hitRow) == 1)
                list->ready = 1;
        } else {
            list->dragRow = hitRow;
            list->dragStartY = list->touchY;
            list->dragFrames++;
        }
        break;
    }
    return 1;
}


/*
 * Starts a snap scroll by a number of rows after a drag; the speed is picked
 * from the step table by the row distance.
 */
int FRAME_LIST_StartJump(FrameList *list, int row)
{
    int rowDelta;
    s8 speed;
    u32 room;

    rowDelta = list->dragAnchorRow - row;
    if ((rowDelta < 0 && list->dragDelta > 0) || (rowDelta > 0 && list->dragDelta < 0))
        return 0;
    if ((list->dragDelta < 0 && list->scrollPos == 0) || (list->dragDelta > 0 && list->scrollPos == list->scrollMax))
        return 0;
    if (rowDelta < 0)
        rowDelta = -rowDelta;
    if (rowDelta == 0)
        return 0;
    if (rowDelta == 1)
        speed = (s8)list->params.stepTable[3];
    else if (rowDelta == 2)
        speed = (s8)list->params.stepTable[2];
    else if (rowDelta == 3)
        speed = (s8)list->params.stepTable[1];
    else
        speed = (s8)list->params.stepTable[0];
    if (row > list->dragAnchorRow)
        speed *= -1;
    room = FRAME_LIST_GetScrollRoom(list, speed);
    if (room != 0) {
        if (room < rowDelta)
            rowDelta = room;
        FRAME_LIST_StartScroll(list, speed, rowDelta, 3, 1);
        list->dragAnchorRow = row;
        return 1;
    }
    return 0;
}


/*
 * Starts a flick scroll from the drag speed: the step table entry whose
 * threshold the drag distance reaches gives the speed and the step count.
 * FRAME_LIST_StartScroll takes `s8 speed`; with `int` the constant argument is stored
 * after the u8 narrowing of the step count, which differs from the image.
 */
int FRAME_LIST_StartFlick(FrameList *list)
{
    u32 dist;
    s8 speed;
    int room;

    if ((list->dragDelta < 0 && list->dragLastY > list->dragStartY) || (list->dragDelta > 0 && list->dragLastY < list->dragStartY))
        return 0;
    dist = list->dragLastY - list->dragStartY;
    if ((int)dist < 0)
        dist = -dist;
    if (dist == 0)
        return 0;
    for (list->speedIndex = 0; list->speedIndex < 6; list->speedIndex++) {
        if (dist >= gFrameListFlickThresholds[list->dragFrames][list->speedIndex]) {
            speed = (s8)list->params.stepTable[list->speedIndex];
            dist = gFrameListFlickSteps[list->speedIndex];
            break;
        }
    }
    if (list->speedIndex == 6)
        return 0;
    if (list->dragStartY > list->dragLastY)
        speed *= -1;
    room = FRAME_LIST_GetScrollRoom(list, speed);
    if (room != 0) {
        if (room < dist)
            dist = room;
        FRAME_LIST_StartScroll(list, speed, dist, 3, 1);
        list->flicking = 1;
        return 1;
    }
    return 0;
}


int FRAME_LIST_ClampBgFrameId(int bgFrame)
{
    if (bgFrame == 0)
        return 0;
    if (bgFrame == 1)
        return 1;
    if (bgFrame == 2)
        return 2;
    if (bgFrame == 3)
        return 3;
    if (bgFrame == 4)
        return 4;
    if (bgFrame == 5)
        return 5;
    if (bgFrame == 6)
        return 6;
    if (bgFrame == 7)
        return 7;
    return 0;
}


void FRAME_LIST_UploadRowTiles(FrameList *list, u32 item, u32 windowIndex)
{
    u8 *tiles;
    u8 *vramBase;
    void *window;
    u16 *tileMap;
    u8 mapStride;
    u8 winW;
    u8 winH;
    u8 winX;
    u8 winY;
    u8 tileRow;
    u8 tileCol;

    window = list->windows[windowIndex].window;
    tileMap = list->maps[list->items[item].mapIndex];
    vramBase = BUTTON_MAN_CallHandlerById(FRAME_LIST_ClampBgFrameId(BGWINFRM_GetBgFrame(list->frameMgr, windowIndex)));
    BGWINFRM_SetFrameData(list->frameMgr, windowIndex, tileMap);
    BGWINFRM_PutBmpWin(list->frameMgr, windowIndex, window);
    mapStride = list->params.tileWidth;
    winW = BMP_WIN_GetDispWidth(window);
    winH = BMP_WIN_GetDispHeight(window);
    winX = BMP_WIN_GetPosX(window);
    winY = BMP_WIN_GetPosY(window);
    tiles = BMP_GetPixels(BMP_WIN_GetBmp(window));
    for (tileRow = 0; tileRow < winH; tileRow++) {
        for (tileCol = 0; tileCol < winW; tileCol++) {
            MIi_CpuCopy32(vramBase + (tileMap[winX + tileCol + (tileRow + winY) * mapStride] & 0x3ff) * 32,
                          tiles + (tileCol + tileRow * winW) * 32, 0x20);
        }
    }
}


void FRAME_LIST_ScrollBgRows(FrameList *list, int windowIndex, s8 y)
{
    u32 frameBuffer;
    u32 bgFrame;
    u16 tileRow;

    frameBuffer = BGWINFRM_GetFrameBuffer(list->frameMgr, windowIndex);
    bgFrame = BGWINFRM_GetBgFrame(list->frameMgr, windowIndex);
    for (tileRow = 0; tileRow < list->params.rowHeight; tileRow++) {
        if (y < 0)
            y += 0x20;
        else if (y >= 0x20)
            y -= 0x20;
        BG_SYS_DrawTileEx(bgFrame, list->params.tileX, (u8)y, list->params.tileWidth, 1, frameBuffer, 0, tileRow, list->params.tileWidth, list->params.rowHeight);
        y++;
    }
    func_02041B6C((u8)bgFrame);
}


void FRAME_LIST_ClearBgRows(FrameList *list, u32 layer, s8 y)
{
    u32 tileRow;

    for (tileRow = 0; tileRow < list->params.rowHeight; tileRow++) {
        if (y < 0)
            y += 0x20;
        else if (y >= 0x20)
            y -= 0x20;
        BG_SYS_SetTileEntry(layer, 0, list->params.tileX, (u8)y, list->params.tileWidth, 1, 0);
        y++;
    }
    func_02041B6C(layer);
}


signed char FRAME_LIST_GetRowPosition(const FrameList *list, int step)
{
    signed char rowY, rowStep;
    rowY = list->params.firstRow;
    rowStep = (unsigned int)(unsigned char)list->params.rowHeight * (unsigned int)step;
    do { rowY += rowStep; } while (rowY >= 0 && rowY < 24);
    return rowY + list->pixelOffset / 8;
}


signed char FRAME_LIST_WrapIndex(signed char index, signed char limit, int step)
{
    index = (signed char)((unsigned int)index + (unsigned int)step);
    if (index < 0) return limit;
    if (index > limit) return 0;
    return index;
}


void FRAME_LIST_DrawRowA(FrameList *list, int item, s8 y)
{
    if (item >= 0 && item < list->totalItems) {
        FRAME_LIST_UploadRowTiles(list, item, list->ringA);
        FRAME_LIST_ScrollBgRows(list, list->ringA, y);
        list->params.ops->drawRow(list->params.userData, item, &list->windows[list->ringA], y * 8 - list->pixelOffset, 1);
    } else {
        FRAME_LIST_ClearBgRows(list, list->params.bgLayer, y);
    }
}


void FRAME_LIST_DrawRowB(FrameList *list, int item, s8 y)
{
    int windowIndex;

    if (list->params.bgLayerB != 0xff) {
        if (item >= 0) {
            windowIndex = list->ringB + list->windowCountHalf;
            FRAME_LIST_UploadRowTiles(list, item, windowIndex);
            FRAME_LIST_ScrollBgRows(list, windowIndex, y);
            list->params.ops->drawRow(list->params.userData, item, &list->windows[windowIndex], y * 8 - list->pixelOffset, 0);
        } else {
            FRAME_LIST_ClearBgRows(list, list->params.bgLayerB, y);
        }
    }
}


void FRAME_LIST_SetRowPalette(FrameList *list, int row, u32 pltt)
{
    s16 pos = list->pixelOffset / 8 + (list->params.firstRow + row * list->params.rowHeight);
    u16 tileRow = 0;
    for (; tileRow < list->params.rowHeight; tileRow++) {
        if (pos < 0) pos += 32;
        else if (pos >= 32) pos -= 32;
        BG_SYS_FillTileMap(list->params.bgLayer, list->params.tileX, (u8)pos, list->params.tileWidth, 1, (u8)pltt);
        pos++;
    }
    func_02041B6C(list->params.bgLayer);
}


void FRAME_LIST_SetCursorHighlight(FrameList *list, u32 newRow, u32 oldRow)
{
    if (oldRow < list->visibleCount)
        FRAME_LIST_SetRowPalette(list, oldRow, (u16)(list->maps[list->items[list->scrollPos + oldRow].mapIndex][0] >> 12));
    if (newRow < list->visibleCount && func_020355C4() == 0) {
        BLINK_PALANM_ResetPhase(list->cursorAnim);
        FRAME_LIST_SetRowPalette(list, newRow, list->params.cursorPltt);
    }
}


void FRAME_LIST_UpdateWindows(FrameList *list)
{
    u32 windowIndex;

    PRINTSYS_QUE_Main(list->printer);
    for (windowIndex = 0; windowIndex < list->windowCount; windowIndex++) {
        struct FrameListWindow *entry = &list->windows[windowIndex];
        struct PrintSys *printer = list->printer;

        if (entry->busy != 0) {
            if (PRINTSYS_QUE_IsExistTarget(printer, BMP_WIN_GetBmp(entry->window)) == 0) {
                BMP_WIN_TransferChars(entry->window);
                entry->busy = 0;
            }
        }
    }
}

struct PrintSys *FRAME_LIST_GetPrinter(FrameList *list)
{
    return list->printer;
}

u32 FRAME_LIST_GetItemValue(FrameList *list, int index)
{
    return list->items[index].value;
}


/*
 * Returns the item index under the cursor: scroll position plus cursor row.
 */
int FRAME_LIST_GetSelectedIndex(FrameList *list)
{
    return list->cursor + list->scrollPos;
}


/*
 * Returns the scroll position (index of the first visible item).
 */
int FRAME_LIST_GetCursor(FrameList *list)
{
    return list->cursor;
}


int FRAME_LIST_GetScrollPos(FrameList *list)
{
    return list->scrollPos;
}


/*
 * True while the list can still scroll down (scrollPos < scrollMax).
 */
int FRAME_LIST_CanScrollDown(FrameList *list)
{
    return list->scrollPos < list->scrollMax;
}


void func_021B93D4(FrameList *list, int row)
{
    list->prevCursor = list->cursor;
    list->cursor = row;
    FRAME_LIST_SetCursorHighlight(list, (u16)list->cursor, (u16)list->prevCursor);
    list->params.ops->onCursor(list->params.userData, list->cursor + list->scrollPos, 1);
}


void func_021B940C(FrameList *list)
{
    FRAME_LIST_SetCursorHighlight(list, (u16)list->cursor, (u16)0xff);
}


/*
 * Cursor control: SetCursor moves the highlight to a row; ShowCursor and
 * HideCursor tail-call the highlight update with the cursor row as the new or
 * the old row.
 */
void func_021B941C(FrameList *list)
{
    FRAME_LIST_SetCursorHighlight(list, (u16)0xff, (u16)list->cursor);
}

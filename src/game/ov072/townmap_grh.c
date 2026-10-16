/*
 * file:     townmap_grh.c
 * unit:     yes
 * function: TOWNMAP_GRH_InitTextBox, TOWNMAP_GRH_ExitTextBox, TOWNMAP_GRH_PrintTextBoxMessage, TOWNMAP_GRH_ClearTextBox, TOWNMAP_GRH_InitLabel, TOWNMAP_GRH_ExitLabel, TOWNMAP_GRH_UpdateLabel, TOWNMAP_GRH_SetLabelTown, TOWNMAP_GRH_SetLabelVisible, TOWNMAP_GRH_InitTouch, TOWNMAP_GRH_ClearTouch, TOWNMAP_GRH_UpdateTouch, TOWNMAP_GRH_GetTouchDrag, TOWNMAP_GRH_RestartTouchDrag, TOWNMAP_GRH_EmptyTask, TOWNMAP_GRH_Create, TOWNMAP_GRH_Delete, TOWNMAP_GRH_DrawSprites, TOWNMAP_GRH_GetBgId, TOWNMAP_GRH_GetHandle, TOWNMAP_GRH_GetActor, TOWNMAP_GRH_GetResourceIds, TOWNMAP_GRH_ResetDisplay, TOWNMAP_GRH_UpdateTask, TOWNMAP_GRH_InitBgLayers, TOWNMAP_GRH_ExitBgLayers, TOWNMAP_GRH_TransferBgData, TOWNMAP_GRH_InitSprites, TOWNMAP_GRH_ExitSprites, TOWNMAP_GRH_DrawClactSystem, TOWNMAP_GRH_VBlankSprites, TOWNMAP_GRH_GetSpriteActor, TOWNMAP_GRH_GetSpriteHandle, TOWNMAP_GRH_GetSpriteResourceId, TOWNMAP_GRH_LoadTownInfo, TOWNMAP_GRH_FreeTownInfo, TOWNMAP_GRH_GetTownInfoValue, TOWNMAP_GRH_FindRecordIndex
 * address:  0x021BB3E8
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *   GFL_USE_AddMainTask  0x020056A0  thumb
 *   TCB_DeleteTask  0x02030EAC  arm
 *   ARC_TOOL_CreateHandle  0x020490F4  arm
 *   CLACT_RegisterCharacter  0x0204A6C8  arm
 *   CLACT_RegisterCellAnim  0x0204AF28  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   CLACT_CreateActor  0x0204B294  arm
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   CLACT_StopActorAnim  0x0204B974  arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   TOUCHPANEL_GetPointTrg  0x02035D20  arm
 *   CLACT_IsActorAnimActive  0x0204B98C  arm
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   CLACT_StartActorAnim  0x0204B95C  arm
 *   CLACT_AddActorSurfacePos  0x0204B404  arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   CLACT_SetActorBgPriority  0x0204B84C  arm
 *   CLACT_SetActorDrawPriority  0x0204B800  arm
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   BMP_WIN_Create  0x020450F0  arm
 *   STRBUF_Create  0x020457B0  arm
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   ZONEDATA_GetPlaceNameId  0x02013E4C  thumb
 *   func_02045CAC  0x02045CAC  arm
 *   PRINTSYS_Print  0x0201C7A4  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   BG_SYS_SetFlagField06  0x02041B6C  arm
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   TOUCHPANEL_GetPointCont  0x02035CB8  arm
 *   VEC_Subtract  0x0207CA00  arm
 *   VEC_Mag  0x0207CBD0  arm
 *   sTownMapGrhFileName     0x021BBD6C  data  ov072  a1
 *   sTownMapGrhVramBanks     0x021BBBDC  data  ov072
 *   sTownMapGrhBgTable 0x021BBC28 data a4
 *   BG_SYS_ClearGraphicsMemory  0x0204335C  arm
 *   BG_SYS_SetVramBanks  0x020433E0  arm
 *   BMP_SetDisplaySwap  0x0204363C  arm
 *   BG_SYS_ResetSubDisplay  0x0204361C  arm
 *   BG_SYS_ClearMainPlanes  0x020434CC  arm
 *   GF_FONT_InitTextColor  0x0201DD60  thumb
 *   BG_SYS_Create  0x0203F8F4  arm
 *   BMP_WIN_Init  0x02045088  arm
 *   BG_SYS_SetGraphicsMode  0x0203FC28  arm
 *   BG_SYS_InitBgLayer  0x0203FCA0  arm
 *   BG_SYS_SetPlaneVisible  0x02040588  arm
 *   func_02049B68  0x02049B68  arm
 *   ARC_UTIL_UploadBgCharFromHandle  0x02049658  arm
 *   ARC_UTIL_UploadBgPaletteFromHandle  0x020498F4  arm
 *   ARC_UTIL_UploadPaletteFromArchiveWhole  0x02049B40  arm
 *   BG_SYS_Init  0x02040C14  arm
 *   sTownMapGrhDispConfig     0x021BBBCC  data  a4
 *   BG_SYS_SetTileUnit  0x02040DA8  arm
 *   BG_SYS_FreeSlot  0x020414AC  arm
 *   BG_SYS_FreeLayerBuf  0x020403F4  arm
 *   BMP_WIN_Exit  0x020450C8  arm
 *   BG_SYS_Delete  0x0203F9B4  arm
 *   BG_SYS_Update  0x020419E4  arm
 *   CLACT_InitSystem  0x0204A48C  arm
 *   CLACT_CreateUnit  0x0204B100  arm
 *   CLACT_SetUnitDefaultRenderer  0x0204B270  arm
 *   BG_SYS_SetMainPlaneVisible  0x020434DC  arm
 *   BG_SYS_SetSubPlaneVisible  0x02043598  arm
 *   CLACT_RegisterPalette  0x0204ABF0  arm
 *   sTownMapGrhClactInit     0x021BBC0C  data  a4
 *   CLACT_DeleteUnit  0x0204B1CC  arm
 *   CLACT_ExitSystem  0x0204A5AC  arm
 *   CLACT_DrawSystem  0x0204A600  arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   ARC_UTIL_LoadMember 0x0204A1BC arm
 *   TOWNMAP_TownGetField  0x021BA774  thumb
 */
#include "townmap_grh_types.h"

#define REG_BLDCNT      (*(volatile u16 *)0x04000050)
#define REG_DB_BLDCNT   (*(volatile u16 *)0x04001050)
#define REG_DISPCNT     (*(volatile u32 *)0x04000000)
#define REG_DB_DISPCNT  (*(volatile u32 *)0x04001000)
#define DISPCNT_WINDOW_BITS 0xE000

#define TOWNMAP_GRH_BG_COUNT 7

extern void MI_CpuFill8(void *dst, int value, int size);
extern u32 GFL_USE_AddMainTask(void (*task)(void *, void *), void *arg, int priority);
extern void TCB_DeleteTask(u32 task);
extern void *ARC_TOOL_CreateHandle(u32 id, u32 heap);
extern u32 CLACT_RegisterCharacter(void *arc, u32 id, u32 a, u32 b, u32 heap);
extern u32 CLACT_RegisterCellAnim(void *arc, u32 first, u32 second, u32 mode);
extern void ARC_TOOL_DeleteHandle(void *arc);
extern struct ClactActor *CLACT_CreateActor(struct ClactUnit *unit, u32 chr, u32 pal, u32 cell, const SpriteInit *init, u16 drawArea, u16 heap);
extern void CLACT_SetActorAutoAnim(struct ClactActor *actor, u32 value);
extern void CLACT_StopActorAnim(struct ClactActor *actor);
extern void CLACT_DeleteActor(struct ClactActor *actor);
extern void CLACT_ReleaseCellAnim(u32 cellId);
extern void CLACT_ReleaseCharacter(u32 charId);
extern void CLACT_ReleasePalette(u32 palId);
extern u32 TOUCHPANEL_GetPointTrg(u32 *outX, u32 *outY);
extern u32 CLACT_IsActorAnimActive(struct ClactActor *actor);
extern void CLACT_SetActorAnimSeq(struct ClactActor *actor, u16 animSeq);
extern void CLACT_StartActorAnim(struct ClactActor *actor);
extern void CLACT_AddActorSurfacePos(struct ClactActor *actor, const ScreenPos *pos, u32 which);
extern void CLACT_SetActorDrawEnable(struct ClactActor *actor, u32 enable);
extern void CLACT_SetActorBgPriority(struct ClactActor *actor, int value);
extern void CLACT_SetActorDrawPriority(struct ClactActor *actor, u32 priority);
extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 line);
extern u32 GFL_HEAP_Free(void *p);
extern struct BmpWin *BMP_WIN_Create(u32 bgId, u32 x, u32 y, u32 width, u8 height, u8 palette, u8 baseTile);
extern struct StrBuf *STRBUF_Create(u32 capacity, u32 heapId);
extern void STRBUF_Delete(struct StrBuf *text);
extern u32 BMP_WIN_Delete(struct BmpWin *win);
extern struct Bitmap *BMP_WIN_GetBmp(struct BmpWin *win);
extern void BMP_Clear(struct Bitmap *bitmap, u8 value);
extern u32 ZONEDATA_GetPlaceNameId(u32 townId);
extern void func_02045CAC(struct MsgBank *msg, u32 index, struct StrBuf *dest);
extern void PRINTSYS_Print(struct Bitmap *bitmap, s16 x, s16 y, struct StrBuf *text, void *font);
extern void BMP_WIN_TransferChars(struct BmpWin *win);
extern void BMP_WIN_MakeScreen(struct BmpWin *win);
extern u8 BMP_WIN_GetBgLayer(struct BmpWin *win);
extern void BG_SYS_SetFlagField06(u32 bgBit);
extern void BMP_WIN_ClearScreen(struct BmpWin *win);
extern u32 TOUCHPANEL_GetPointCont(u32 *outX, u32 *outY);
extern void VEC_Subtract(const TownMapVec *a, const TownMapVec *b, TownMapVec *out);
extern int VEC_Mag(const TownMapVec *v);
extern void BG_SYS_ClearGraphicsMemory(u32 a);
extern void BG_SYS_SetVramBanks(const struct DispVram *banks);
extern void BMP_SetDisplaySwap(u32 a);
extern void BG_SYS_ResetSubDisplay(void);
extern void BG_SYS_ClearMainPlanes(void);
extern void GF_FONT_InitTextColor(void);
extern void BG_SYS_Create(u16 heap);
extern void BMP_WIN_Init(u16 heap);
extern void BG_SYS_SetGraphicsMode(struct DispConfig *config);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *templ, u32 type);
extern void BG_SYS_SetPlaneVisible(unsigned char which, unsigned char enable);
extern void func_02049B68(void *arc, u32 b, u32 c, u32 d, u32 e, u16 heap);
extern u32 ARC_UTIL_UploadBgCharFromHandle(void *arc, u32 a, u32 b, u32 c, u32 d, u32 e, u16 heap);
extern void ARC_UTIL_UploadBgPaletteFromHandle(void *arc, u32 a, u32 b, u32 c, u32 d, u32 e, u16 heap);
extern void ARC_UTIL_UploadPaletteFromArchiveWhole(u32 a, u32 b, u32 c, u32 d, u32 e, u16 heap);
extern void BG_SYS_Init(u32 layer, u32 value, u32 count, u32 index);
extern void BG_SYS_SetTileUnit(u32 a, u32 b, u32 c);
extern void BG_SYS_FreeSlot(u8 a);
extern void BG_SYS_FreeLayerBuf(u32 i);
extern void BMP_WIN_Exit(void);
extern void BG_SYS_Delete(void);
extern void BG_SYS_Update(void);
extern void CLACT_InitSystem(const TownMapClactInit *init, const struct DispVram *banks, u32 heapId);
extern struct ClactUnit *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void CLACT_SetUnitDefaultRenderer(struct ClactUnit *unit);
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
extern u32 CLACT_RegisterPalette(void *arc, u32 id, u32 a, u32 b, u32 heap);
extern u32 CLACT_DeleteUnit(struct ClactUnit *unit);
extern void CLACT_ExitSystem(void);
extern void CLACT_DrawSystem(int arg);
extern void CLACT_VBlankSystem(void);
extern TownMapInfoRow *ARC_UTIL_LoadMember(int, int, int, int);

/* Siblings in townmap.c. */
extern int TOWNMAP_TownGetField(TownMapTown *town, int field);

extern char sTownMapGrhFileName[];
extern struct DispVram sTownMapGrhVramBanks;
extern struct DispConfig sTownMapGrhDispConfig;
extern TownMapBgEntry sTownMapGrhBgTable[];
extern const TownMapClactInit sTownMapGrhClactInit;

void TOWNMAP_GRH_InitTextBox(TownMapTextBox *box, int bgId, void *font, void *msg, u8 x, u8 y, u8 width, u8 height, u16 heapId);
void TOWNMAP_GRH_ExitTextBox(TownMapTextBox *box);
void TOWNMAP_GRH_PrintTextBoxMessage(TownMapTextBox *box, u32 msgId, int x, int y);
void TOWNMAP_GRH_ClearTextBox(TownMapTextBox *box);
void TOWNMAP_GRH_ResetDisplay(void);
void TOWNMAP_GRH_UpdateTask(void *task, void *gfx);
void TOWNMAP_GRH_InitBgLayers(TownMapGfx *gfx, u16 heapId);
void TOWNMAP_GRH_ExitBgLayers(TownMapGfx *gfx);
void TOWNMAP_GRH_TransferBgData(TownMapGfx *gfx);
void TOWNMAP_GRH_InitSprites(TownMapSprites *sprites, const struct DispVram *banks, u16 heapId);
void TOWNMAP_GRH_ExitSprites(TownMapSprites *sprites);
void TOWNMAP_GRH_DrawClactSystem(int arg);
void TOWNMAP_GRH_VBlankSprites(TownMapSprites *sprites);
struct ClactActor *TOWNMAP_GRH_GetSpriteActor(TownMapSprites *sprites, int n);
unsigned int TOWNMAP_GRH_GetSpriteHandle(TownMapSprites *sprites, int n);
int TOWNMAP_GRH_GetSpriteResourceId(TownMapSprites *sprites, int i);

/* Text box. */
void TOWNMAP_GRH_InitTextBox(TownMapTextBox *box, int bgId, void *font, void *msg, u8 x, u8 y, u8 width, u8 height, u16 heapId)
{
    MI_CpuFill8(box, 0, sizeof(TownMapTextBox));
    box->font = font;
    box->msg = msg;
    box->win = BMP_WIN_Create(bgId, x, y, width, height, 0xe, 0);
    box->text = STRBUF_Create(0xff, heapId);
}

void TOWNMAP_GRH_ExitTextBox(TownMapTextBox *box)
{
    STRBUF_Delete(box->text);
    BMP_WIN_Delete(box->win);
    MI_CpuFill8(box, 0, sizeof(TownMapTextBox));
}

void TOWNMAP_GRH_PrintTextBoxMessage(TownMapTextBox *box, u32 msgId, int x, int y)
{
    struct BmpWin *win;

    BMP_Clear(BMP_WIN_GetBmp(box->win), 0);
    func_02045CAC(box->msg, msgId, box->text);
    PRINTSYS_Print(BMP_WIN_GetBmp(box->win), x, y, box->text, box->font);
    win = box->win;
    BMP_WIN_TransferChars(win);
    BMP_WIN_MakeScreen(win);
    BG_SYS_SetFlagField06(BMP_WIN_GetBgLayer(win));
}

void TOWNMAP_GRH_ClearTextBox(TownMapTextBox *box)
{
    struct BmpWin *win = box->win;

    BMP_WIN_ClearScreen(win);
    BG_SYS_SetFlagField06(BMP_WIN_GetBgLayer(win));
}

/* Hover label. */
void TOWNMAP_GRH_InitLabel(TownMapLabel *label, int bgId, void *font, void *msg, struct ClactActor *marker, u16 heapId)
{
    ScreenPos pos;

    MI_CpuFill8(label, 0, sizeof(TownMapLabel));
    label->marker = marker;
    TOWNMAP_GRH_InitTextBox(&label->box, bgId, font, msg, 0, 0, 0x18, 3, heapId);
    pos.x = 0x80;
    pos.y = 0x60;
    CLACT_AddActorSurfacePos(label->marker, &pos, 0);
    CLACT_SetActorBgPriority(label->marker, 1);
    CLACT_SetActorDrawPriority(label->marker, 1);
    CLACT_SetActorDrawEnable(label->marker, 1);
    CLACT_SetActorAnimSeq(label->marker, 0);
    CLACT_SetActorAutoAnim(label->marker, 1);
    CLACT_StopActorAnim(label->marker);
}

void TOWNMAP_GRH_ExitLabel(TownMapLabel *label)
{
    TOWNMAP_GRH_ExitTextBox(&label->box);
    MI_CpuFill8(label, 0, sizeof(TownMapLabel));
}

void TOWNMAP_GRH_UpdateLabel(TownMapLabel *label)
{
    if (label->requested != 0) {
        label->requested = 0;
        CLACT_SetActorAnimSeq(label->marker, 0);
        CLACT_StartActorAnim(label->marker);
        CLACT_SetActorDrawEnable(label->marker, 1);
        TOWNMAP_GRH_ClearTextBox(&label->box);
        label->animating = 1;
    }
    if (label->animating != 0 && CLACT_IsActorAnimActive(label->marker) == 0) {
        TOWNMAP_GRH_PrintTextBoxMessage(&label->box, ZONEDATA_GetPlaceNameId((u16)TOWNMAP_TownGetField(label->town, 0)), 0x10, 2);
        CLACT_StopActorAnim(label->marker);
        label->animating = 0;
    }
}

void TOWNMAP_GRH_SetLabelTown(TownMapLabel *label, TownMapTown *town)
{
    label->requested = 1;
    label->town = town;
}

void TOWNMAP_GRH_SetLabelVisible(TownMapLabel *label, u32 visible)
{
    CLACT_SetActorDrawEnable(label->marker, visible);
    if (visible == 0) {
        label->requested = 0;
        label->animating = 0;
        TOWNMAP_GRH_ClearTextBox(&label->box);
    }
}

/* Touch drag tracking. */
void TOWNMAP_GRH_InitTouch(TownMapTouch *touch, int heapId)
{
    MI_CpuFill8(touch, 0, sizeof(TownMapTouch));
}

void TOWNMAP_GRH_ClearTouch(TownMapTouch *touch)
{
    MI_CpuFill8(touch, 0, sizeof(TownMapTouch));
}

void TOWNMAP_GRH_UpdateTouch(TownMapTouch *touch)
{
    u32 touchX;
    u32 touchY;

    touch->dragged = 0;
    if (TOUCHPANEL_GetPointTrg(&touchX, &touchY)) {
        if (touchY <= 0xA8) {
            touch->prev.x = touchX << 12;
            touch->prev.y = touchY << 12;
            touch->prev.z = 0;
            touch->cur.x = touchX << 12;
            touch->cur.y = touchY << 12;
            touch->cur.z = 0;
        }
        return;
    }
    if (TOUCHPANEL_GetPointCont(&touchX, &touchY)) {
        if (touchY <= 0xA8) {
            if (touch->reanchor != 0) {
                touch->prev = touch->cur;
                touch->reanchor = 0;
            }
            touch->cur.x = touchX << 12;
            touch->cur.y = touchY << 12;
            touch->cur.z = 0;
            VEC_Subtract(&touch->cur, &touch->prev, &touch->delta);
            if (VEC_Mag(&touch->delta) >= 0x1000) {
                touch->dragged = 1;
            }
        } else {
            touch->prev.x = touchX << 12;
            touch->prev.y = touchY << 12;
            touch->prev.z = 0;
            touch->cur.x = touchX << 12;
            touch->cur.y = touchY << 12;
            touch->cur.z = 0;
        }
    }
}

int TOWNMAP_GRH_GetTouchDrag(TownMapTouch *touch, TownMapVec *delta, u32 *dragState)
{
    if (touch->dragged != 0) {
        if (delta != 0)
            *delta = touch->delta;
        if (dragState != 0)
            *dragState = touch->dragState;
        return 1;
    }
    return 0;
}

void TOWNMAP_GRH_RestartTouchDrag(TownMapTouch *touch)
{
    touch->reanchor = 1;
}

/* Empty per frame task. */
void TOWNMAP_GRH_EmptyTask(void *task, void *arg)
{
}

/* Graphics set. */
TownMapGfx *TOWNMAP_GRH_Create(u16 heapId)
{
    TownMapGfx *gfx;

    gfx = GFL_HEAP_Alloc(heapId, sizeof(TownMapGfx), 0, sTownMapGrhFileName, 0xEC);
    MI_CpuFill8(gfx, 0, sizeof(TownMapGfx));
    TOWNMAP_GRH_ResetDisplay();
    TOWNMAP_GRH_InitBgLayers(gfx, heapId);
    TOWNMAP_GRH_InitSprites(&gfx->sprites, &sTownMapGrhVramBanks, heapId);
    gfx->task = GFL_USE_AddMainTask(TOWNMAP_GRH_UpdateTask, gfx, 1);
    return gfx;
}

void TOWNMAP_GRH_Delete(TownMapGfx *gfx)
{
    TCB_DeleteTask(gfx->task);
    TOWNMAP_GRH_ExitSprites(&gfx->sprites);
    TOWNMAP_GRH_ExitBgLayers(gfx);
    GFL_HEAP_Free(gfx);
}

void TOWNMAP_GRH_DrawSprites(TownMapGfx *gfx)
{
    TOWNMAP_GRH_DrawClactSystem((int)&gfx->sprites);
}

u8 TOWNMAP_GRH_GetBgId(TownMapGfx *gfx, u32 i)
{
    return sTownMapGrhBgTable[i].bgId;
}

unsigned int TOWNMAP_GRH_GetHandle(TownMapGfx *gfx, int n)
{
    return TOWNMAP_GRH_GetSpriteHandle(&gfx->sprites, n);
}

struct ClactActor *TOWNMAP_GRH_GetActor(TownMapGfx *gfx, int n)
{
    return TOWNMAP_GRH_GetSpriteActor(&gfx->sprites, n);
}

void TOWNMAP_GRH_GetResourceIds(TownMapGfx *gfx, int *charId, int *cellId, int *palId)
{
    *charId = TOWNMAP_GRH_GetSpriteResourceId(&gfx->sprites, 0);
    *cellId = TOWNMAP_GRH_GetSpriteResourceId(&gfx->sprites, 1);
    *palId = TOWNMAP_GRH_GetSpriteResourceId(&gfx->sprites, 2);
}

void TOWNMAP_GRH_ResetDisplay(void)
{
    REG_BLDCNT = 0;
    REG_DB_BLDCNT = 0;
    REG_DISPCNT &= ~DISPCNT_WINDOW_BITS;
    REG_DB_DISPCNT &= ~DISPCNT_WINDOW_BITS;
    BG_SYS_ClearGraphicsMemory(0);
    BG_SYS_SetVramBanks(&sTownMapGrhVramBanks);
    BMP_SetDisplaySwap(0);
    BG_SYS_ResetSubDisplay();
    BG_SYS_ClearMainPlanes();
    GF_FONT_InitTextColor();
}

void TOWNMAP_GRH_UpdateTask(void *task, void *gfx)
{
    TOWNMAP_GRH_VBlankSprites(&((TownMapGfx *)gfx)->sprites);
    TOWNMAP_GRH_TransferBgData(gfx);
}

/* Sets up the display layers and uploads the town map graphics. */
void TOWNMAP_GRH_InitBgLayers(TownMapGfx *gfx, u16 heapId)
{
    int i;
    u32 bgId;
    void *arc;

    i = 0;
    MI_CpuFill8(&gfx->bgReady, 0, sizeof(gfx->bgReady));
    BG_SYS_Create(heapId);
    BMP_WIN_Init(heapId);
    BG_SYS_SetGraphicsMode(&sTownMapGrhDispConfig);
    for (; i < TOWNMAP_GRH_BG_COUNT; i++) {
        bgId = sTownMapGrhBgTable[i].bgId;
        BG_SYS_InitBgLayer((u8)bgId, (const struct BgTemplate *)&sTownMapGrhBgTable[i].templ, (u8)sTownMapGrhBgTable[i].mode);
        BG_SYS_SetPlaneVisible(bgId, 1);
    }
    arc = ARC_TOOL_CreateHandle(0x55, heapId);
    func_02049B68(arc, 0, 2, 0x6000, 0x2000, heapId);
    func_02049B68(arc, 0, 2, 0x4000, 0x2000, heapId);
    ARC_UTIL_UploadBgCharFromHandle(arc, 5, 2, 0, 0x10000, 0, heapId);
    ARC_UTIL_UploadBgCharFromHandle(arc, 7, 3, 0, 0x10000, 0, heapId);
    ARC_UTIL_UploadBgPaletteFromHandle(arc, 0x11, 2, 0, 0x800, 0, heapId);
    ARC_UTIL_UploadBgPaletteFromHandle(arc, 0x10, 3, 0, 0x800, 0, heapId);
    func_02049B68(arc, 1, 4, 0, 0, heapId);
    ARC_UTIL_UploadBgCharFromHandle(arc, 6, 5, 0, 0, 0, heapId);
    ARC_UTIL_UploadBgPaletteFromHandle(arc, 0xf, 5, 0, 0, 0, heapId);
    ARC_UTIL_UploadPaletteFromArchiveWhole(0x17, 5, 0, 0x1c0, 0x20, heapId);
    ARC_UTIL_UploadPaletteFromArchiveWhole(0x17, 5, 4, 0x1c0, 0x20, heapId);
    BG_SYS_Init(1, 0, 1, 0);
    ARC_TOOL_DeleteHandle(arc);
}

void TOWNMAP_GRH_ExitBgLayers(TownMapGfx *gfx)
{
    int i;
    u32 bgId;

    BG_SYS_SetTileUnit(1, 1, 0);
    for (i = 0; i < TOWNMAP_GRH_BG_COUNT; i++) {
        bgId = sTownMapGrhBgTable[i].bgId;
        BG_SYS_FreeSlot(bgId);
        BG_SYS_FreeLayerBuf((u8)bgId);
    }
    BMP_WIN_Exit();
    BG_SYS_Delete();
    MI_CpuFill8(&gfx->bgReady, 0, sizeof(gfx->bgReady));
}

void TOWNMAP_GRH_TransferBgData(TownMapGfx *gfx)
{
    BG_SYS_Update();
}

void TOWNMAP_GRH_InitSprites(TownMapSprites *sprites, const struct DispVram *banks, u16 heapId)
{
    int i;
    void *arc;
    TownMapClactInit init;
    SpriteInit actorInit;

    i = 0;
    MI_CpuFill8(sprites, 0, sizeof(TownMapSprites));
    init = sTownMapGrhClactInit;
    CLACT_InitSystem(&init, banks, heapId);
    sprites->unit = CLACT_CreateUnit(0x80, 0, heapId);
    CLACT_SetUnitDefaultRenderer(sprites->unit);
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
    arc = ARC_TOOL_CreateHandle(0x55, heapId);
    sprites->palId = CLACT_RegisterPalette(arc, 2, 0, 0, heapId);
    sprites->charId = CLACT_RegisterCharacter(arc, 8, 0, 0, heapId);
    sprites->cellId = CLACT_RegisterCellAnim(arc, 0xc, 0x13, heapId);
    ARC_TOOL_DeleteHandle(arc);
    MI_CpuFill8(&actorInit, 0, sizeof(SpriteInit));
    for (; i < 4; i++) {
        sprites->actor[i] = CLACT_CreateActor(sprites->unit, sprites->charId, sprites->palId, sprites->cellId, &actorInit, 1, heapId);
    }
    CLACT_SetActorAnimSeq(sprites->actor[0], 0);
    CLACT_SetActorAnimSeq(sprites->actor[1], 4);
    CLACT_SetActorAnimSeq(sprites->actor[2], 5);
    CLACT_SetActorAnimSeq(sprites->actor[3], 6);
    for (i = 0; i < 4; i++) {
        CLACT_SetActorDrawEnable(sprites->actor[i], 0);
    }
}

void TOWNMAP_GRH_ExitSprites(TownMapSprites *sprites)
{
    int i;

    for (i = 0; i < 4; i++) {
        if (sprites->actor[i] != 0) {
            CLACT_DeleteActor(sprites->actor[i]);
        }
    }
    CLACT_ReleaseCellAnim(sprites->cellId);
    CLACT_ReleaseCharacter(sprites->charId);
    CLACT_ReleasePalette(sprites->palId);
    if (sprites->unit != 0) {
        CLACT_DeleteUnit(sprites->unit);
    }
    CLACT_ExitSystem();
    MI_CpuFill8(sprites, 0, sizeof(TownMapSprites));
}

/* Thumb long-branch veneer to CLACT_DrawSystem, declared as an ordinary call. */
void TOWNMAP_GRH_DrawClactSystem(int arg)
{
    CLACT_DrawSystem(arg);
}

void TOWNMAP_GRH_VBlankSprites(TownMapSprites *sprites)
{
    CLACT_VBlankSystem();
}

struct ClactActor *TOWNMAP_GRH_GetSpriteActor(TownMapSprites *sprites, int n)
{
    return sprites->actor[n];
}

unsigned int TOWNMAP_GRH_GetSpriteHandle(TownMapSprites *sprites, int n)
{
    return sprites->handle[n];
}

int TOWNMAP_GRH_GetSpriteResourceId(TownMapSprites *sprites, int i)
{
    return sprites->resourceId[i];
}

TownMapInfoRow *TOWNMAP_GRH_LoadTownInfo(int heapId)
{
    return ARC_UTIL_LoadMember(0x56, 0, 0, heapId);
}

void TOWNMAP_GRH_FreeTownInfo(TownMapInfoRow *info)
{
    GFL_HEAP_Free(info);
}

unsigned short TOWNMAP_GRH_GetTownInfoValue(TownMapInfoRow *info, u16 row, int col)
{
    return info[row].value[col];
}

/* Linear search of the town info table for the row whose first value is id; 0xffff when none. */
int TOWNMAP_GRH_FindRecordIndex(TownMapInfoRow *info, int id)
{
    int rowIndex;
    int firstColumn = 0;

    for (rowIndex = 0; rowIndex < 0x3d; rowIndex++) {
        if (TOWNMAP_GRH_GetTownInfoValue(info, rowIndex, firstColumn) == id)
            return (u16)rowIndex;
    }
    return 0xffff;
}

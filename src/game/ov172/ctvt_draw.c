/*
 * file:     ctvt_draw.c
 * unit:     yes
 * function: CTVT_DRAW_Create, CTVT_DRAW_Free, CTVT_DRAW_Init, CTVT_DRAW_Exit, CTVT_DRAW_Main, CTVT_DRAW_UpdateCanvasMode, CTVT_DRAW_UpdatePanelMode, CTVT_DRAW_UpdateCanvasTouch, CTVT_DRAW_SlidePanel, CTVT_DRAW_UpdateToolButtons, CTVT_DRAW_ShowHelp, CTVT_DRAW_CheckLeave, CTVT_DRAW_ShowMessage, CTVT_DRAW_ClosePickers
 * address:  0x021BA280
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from draw_system.c, ctvt_comm.c, ctvt_draw.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   G2_GetBG2ScrPtr  0x0207E008  arm
 *   COMM_TVT_SYS_GetArc 0x021BE010 thumb ov172
 *   COMM_TVT_SYS_GetHalfRes 0x021BE078 thumb ov172
 *   COMM_TVT_SYS_GetComm 0x021BDFE4 thumb ov172
 *   COMM_TVT_SYS_GetMemberCount 0x021BE054 thumb ov172
 *   G2_GetBG3ScrPtr 0x0207E100 arm
 *   COMM_TVT_SYS_GetCamView 0x021BDFDC thumb ov172
 *   COMM_TVT_SYS_GetSelfSlot 0x021BE0A4 thumb ov172
 *   COMM_TVT_SYS_GetViewSwapped 0x021BE0B4 thumb ov172
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   COMM_TVT_SYS_GetHeapId 0x021BE00C thumb ov172
 *   COMM_TVT_SYS_ClearNameWindows 0x021BE1A4 thumb ov172
 *   COMM_TVT_SYS_HideSlotMarker 0x021BE2E0 thumb ov172
 *   COMM_TVT_SYS_GetSprites 0x021BDFFC thumb ov172
 *   DRAW_SYSTEM_PushStroke 0x021B6E88 thumb ov172
 *   ARC_UTIL_UploadBgPaletteFromHandle 0x020498F4 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   COMM_TVT_SYS_GetResId 0x021BE018 thumb ov172
 *   COMM_TVT_SYS_GetClactUnit 0x021BE024 thumb ov172
 *   BMP_WIN_ClearScreen  0x020456F8  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   BMP_WIN_Delete  0x020452E8  arm
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *   BG_SYS_ClearSlot  0x020414EC  arm
 *   COMM_TVT_SYS_GetReturnedFromChild 0x021BE02C thumb ov172
 *   COMM_TVT_SYS_SetMessageActive 0x021BE0B0 thumb ov172
 *   COMM_TVT_SYS_GetPrintQue 0x021BE044 thumb ov172
 *   CTVT_CAMVIEW_IsShutterIdle 0x021B7590 thumb ov172
 *   CTVT_CAMVIEW_StopCapture 0x021B7578 thumb ov172
 *   WIPE_SYS_Start 0x0202208C thumb
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   KEY_GetTrg 0x020362DC arm
 *   NNS_GfdRegisterNewVramTransferTask 0x02061CA4 arm
 *   COMM_TVT_SYS_ToggleViewSwapped 0x021BE0B8 thumb ov172
 *   CTVT_CAMVIEW_IsLayoutChanging 0x021B77B4 thumb ov172
 *   COMM_TVT_SYS_ToggleHalfRes 0x021BE08C thumb ov172
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   COMM_TVT_SYS_GetFont 0x021BE034 thumb ov172
 *   COMM_TVT_SYS_GetMsgData 0x021BE03C thumb ov172
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_MENUWORK_DrawWindow 0x0201F73C thumb
 *   BMP_MENUWORK_DrawWindowBorder  0x0201F7A8  thumb
 *   COMM_TVT_SYS_GetEndRequested  0x021BE0D0  thumb  ov172
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   TOUCHPANEL_GetPointCont 0x02035CB8 arm
 *   GFL_NET_RestartWithDefaultTimeout  0x0203D34C  arm
 *   CTVT_CAMVIEW_RequestShutterSound1  0x021B7B80  thumb  ov172
 *   CTVT_CAMVIEW_SetCameraEffect  0x021B7B3C  thumb  ov172
 *   CTVT_COMM_StopSession  0x021B8084  thumb  ov172
 *   CTVT_COMM_SendCommand  0x021B8740  thumb  ov172
 *   CTVT_COMM_SetTimingSync  0x021B8B34  thumb  ov172
 *   CTVT_COMM_IsTimingSync  0x021B8B48  thumb  ov172
 *   FX_SinCosTable_     0x020A1B38  data a2
 *   CLACT_GetActorAnimSeq 0x0204B898 arm
 *   CLACT_GetActorDrawEnable  0x0204B3F4  arm
 *   CLACT_RestartActorAnim  0x0204B9A0  arm
 *   CLACT_AddActorSurfacePos  0x0204B404  arm
 *   gCtvtDrawPanelButtonRects     0x021C6FF8  data
 *   gCtvtDrawSizePickerRects     0x021C7014  data
 *   gCtvtDrawPenSizeValues     0x021C6FBC  data
 *   gCtvtDrawPenMarkerPos     0x021C7030  data
 *   gCtvtDrawStampPickerRects     0x021C6FDC  data
 *   gCtvtDrawStampKindValues     0x021C6FC8  data
 *   gCtvtDrawStampMarkerPos     0x021C7034  data
 *   gCtvtDrawPenCursorPos     0x021C7038  data
 *   gCtvtDrawStampCursorPos     0x021C703C  data
 *   TOUCHPANEL_GetCont  0x02035C38  arm
 *   CTVT_COMM_PopStroke  0x021B8BB8  thumb  ov172
 *   CTVT_COMM_AdvanceWriteCursor  0x021B8BFC  thumb  ov172
 *   BG_SYS_ResetSlot 0x02041EE4 arm
 *   CLACT_GetActorSurfacePos 0x0204B454 arm
 *   CLACT_SetActorAnimFrame  0x0204B8C4  arm
 *   gCtvtDrawPenButtonAnimSeq     0x021C6FB2  data
 *   gCtvtDrawPickButtonAnimSeq     0x021C6FB4  data
 *   gCtvtDrawEraserButtonAnimSeq     0x021C6FB6  data
 *   gCtvtDrawStampButtonAnimSeq     0x021C6FB8  data
 *   CTVT_COMM_GetNetMode  0x021B80E4  thumb  ov172
 *   BG_SYS_SetFlagField06  0x02041B6C  arm
 *   BG_SYS_SetPlaneVisible  0x02040588  arm
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   APP_ICON_GetArchiveId 0x020275E4 thumb
 *   APP_ICON_GetStatusDataFileId 0x0202762C thumb
 *   BG_SYS_FillTileMap 0x020413B0 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   COMM_TVT_SYS_GetInputLocked 0x021BE0C8 thumb ov172
 *   BG_SYS_FillScrollArea  0x02040618  arm  arm9
 */
#include "ctvt_types.h"

/* ARM9 library. */
extern void *GFL_HEAP_Alloc(unsigned int heapId, unsigned int size, int clear, const char *site, unsigned short tag);
extern void GFL_HEAP_Free(void *p);
extern void *G2_GetBG2ScrPtr(void);
extern u32 G2_GetBG3ScrPtr(void);
extern s32 NNS_GfdRegisterNewVramTransferTask(u32 dmaNo, u32 dest, u16 *src, s32 size);
extern void ARC_UTIL_UploadBgPaletteFromHandle(struct ArcHandle *arc, u32 a, u32 b, u32 c, u32 d, u32 e, u16 heapId);
extern void BG_SYS_PushTile(u32 layer);
extern void BG_SYS_SetPlaneVisible(u32 which, u8 enable);
extern u32 APP_ICON_GetArchiveId(void);
extern u32 APP_ICON_GetStatusDataFileId(void);
extern struct ArcHandle *ARC_TOOL_CreateHandle(u32 id, u32 heapId);
extern void BG_SYS_ClearSlot(u32 a);
extern u32 func_02049990(struct ArcHandle *arc, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 heapId);
extern void BG_SYS_FillTileMap(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void BG_SYS_FillScrollArea(u32 a, u32 b, u32 c);
extern void ARC_TOOL_DeleteHandle(struct ArcHandle *arc);
extern void BG_SYS_ResetSlot(u32 a, u32 b, u32 c);
extern void BG_SYS_SetFlagField06(u32 layer);
extern void BMP_MENUWORK_DrawWindow(struct BmpWin *win, int a1, int a2, int a3);
extern void BMP_MENUWORK_DrawWindowBorder(struct BmpWin *win, u32 kind);
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 heapId);

/* Cell actors. */
extern struct ClActor *CLACT_CreateActor(struct ClActUnit *unit, u32 charRes, u32 palRes, u32 cellRes, const void *position, u16 space, u16 heapId);
extern void CLACT_DeleteActor(struct ClActor *actor);
extern void CLACT_SetActorAutoAnim(struct ClActor *actor, u32 value);
extern void CLACT_SetActorDrawEnable(struct ClActor *actor, u32 enable);
extern u32 CLACT_GetActorDrawEnable(struct ClActor *actor);
extern u32 CLACT_IsActorAnimActive(struct ClActor *actor);
extern u16 CLACT_GetActorAnimSeq(struct ClActor *actor);
extern void CLACT_SetActorAnimSeq(struct ClActor *actor, u16 seq);
extern void CLACT_SetActorAnimFrame(struct ClActor *actor, u32 frame);
extern void CLACT_RestartActorAnim(struct ClActor *actor);
extern void CLACT_AddActorSurfacePos(struct ClActor *actor, const void *delta, u32 space);
extern void CLACT_GetActorSurfacePos(struct ClActor *actor, void *out, u16 space);

/* Windows and text. */
extern struct BmpWin *BMP_WIN_Create(u32 layer, u32 x, u32 y, u32 w, u8 h, u8 pal, u8 slot);
extern void *BMP_WIN_GetBmp(struct BmpWin *win);
extern void BMP_Clear(void *bmp, u8 value);
extern void BMP_WIN_MakeScreen(struct BmpWin *win);
extern void BMP_WIN_ClearScreen(struct BmpWin *win);
extern u8 BMP_WIN_GetBgLayer(struct BmpWin *win);
extern void BMP_WIN_TransferChars(struct BmpWin *win);
extern u32 BMP_WIN_Delete(struct BmpWin *win);
extern struct StrBuf *MSGDATA_AllocString(struct MsgData *msg, u32 index);
extern void STRBUF_Delete(struct StrBuf *str);
extern void PRINTSYS_PrintQueColor(struct PrintQue *que, void *bmp, short x, u32 y, struct StrBuf *text, u32 font, u32 flags);
extern void PRINTSYS_QUE_Clear(struct PrintQue *que);
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintQue *que, void *bmp);

/* Input, wipe, sound. */
extern int TOUCHPANEL_GetTrg(void);
extern int TOUCHPANEL_GetCont(void);
extern int TOUCHPANEL_HitTrg(const void *rects);
extern u32 TOUCHPANEL_GetPointTrg(u32 *x, u32 *y);
extern u32 TOUCHPANEL_GetPointCont(u32 *x, u32 *y);
extern u32 KEY_GetTrg(void);
extern void WIPE_SYS_Start(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 heapId);
extern u32 WIPE_SYS_EndCheck(void);
extern void GFL_USE_PlaySeDefaultVolume(u32 id);

/* Other ov172 code. */
extern void DRAW_SYSTEM_PushStroke(struct CtvtSprites *sprites, CtvtStroke *stroke);
extern void CTVT_CAMVIEW_SetCameraEffect(CtvtWork *work, CtvtCamView *view, int dir);
extern void CTVT_CAMVIEW_RequestShutterSound1(CtvtWork *work, CtvtCamView *view);
extern void CTVT_CAMVIEW_StopCapture(CtvtWork *work, CtvtCamView *view);
extern int CTVT_CAMVIEW_IsShutterIdle(CtvtWork *work, CtvtCamView *view);
extern u32 CTVT_CAMVIEW_IsLayoutChanging(CtvtWork *work, CtvtCamView *view);
extern u32 CTVT_COMM_GetNetMode(CtvtWork *work, struct CtvtComm *comm);
extern void CTVT_COMM_StopSession(CtvtWork *work, struct CtvtComm *comm);
extern u32 CTVT_COMM_SendCommand(CtvtWork *work, struct CtvtComm *comm, u8 a, u32 b);
extern void CTVT_COMM_SetTimingSync(CtvtWork *work, struct CtvtComm *comm, u32 id);
extern int CTVT_COMM_IsTimingSync(CtvtWork *work, struct CtvtComm *comm, u32 id);
extern CtvtStroke *CTVT_COMM_PopStroke(CtvtWork *work, struct CtvtComm *comm, int *full);
extern void CTVT_COMM_AdvanceWriteCursor(CtvtWork *work, struct CtvtComm *comm);

extern s16 FX_SinCosTable_[];
extern const u8 gCtvtDrawPanelButtonRects[];
extern const u8 gCtvtDrawSizePickerRects[];
extern const u32 gCtvtDrawPenSizeValues[];
extern const u8 gCtvtDrawStampPickerRects[];
extern const u32 gCtvtDrawStampKindValues[];
extern const u8 gCtvtDrawPenButtonAnimSeq[];
extern const u8 gCtvtDrawPickButtonAnimSeq[];
extern const u8 gCtvtDrawEraserButtonAnimSeq[];
extern const u8 gCtvtDrawStampButtonAnimSeq[];

/* Actor creation record: surface position, animation sequence, priority. */
typedef struct CtvtActorDesc { s16 x; s16 y; s16 animSeq; u8 priority; u8 flags; } CtvtActorDesc;

typedef struct CtvtPoint { s16 x; s16 y; } CtvtPoint;
extern const CtvtPoint gCtvtDrawPenMarkerPos;
extern const CtvtPoint gCtvtDrawStampMarkerPos;
extern const CtvtPoint gCtvtDrawPenCursorPos;
extern const CtvtPoint gCtvtDrawStampCursorPos;

/* Draw screen entry points. */
CtvtDrawScene *CTVT_DRAW_Create(CtvtWork *work, u16 heapId);
void CTVT_DRAW_Free(CtvtWork *work, CtvtDrawScene *scene);
void CTVT_DRAW_Init(CtvtWork *work, CtvtDrawScene *scene);
void CTVT_DRAW_Exit(CtvtWork *work, CtvtDrawScene *scene);
int CTVT_DRAW_Main(CtvtWork *work, CtvtDrawScene *scene);
void CTVT_DRAW_UpdateCanvasMode(CtvtWork *work, CtvtDrawScene *scene);
void CTVT_DRAW_UpdatePanelMode(CtvtWork *work, CtvtDrawScene *scene);
void CTVT_DRAW_UpdateCanvasTouch(CtvtWork *work, CtvtDrawScene *scene);
void CTVT_DRAW_SlidePanel(CtvtWork *work, CtvtDrawScene *scene);
void CTVT_DRAW_UpdateToolButtons(CtvtWork *work, CtvtDrawScene *scene);
void CTVT_DRAW_ShowHelp(CtvtWork *work, CtvtDrawScene *scene, int page);
int CTVT_DRAW_CheckLeave(CtvtWork *work, int *out);
void CTVT_DRAW_ShowMessage(CtvtWork *work, CtvtDrawScene *scene, int msgId);
void CTVT_DRAW_ClosePickers(CtvtWork *work, CtvtDrawScene *scene);

#define REG_POWCNT1 (*(volatile u16 *)0x04000304)
#define REG_BG_PLTT_COLOR13 (*(volatile u16 *)0x0500021A)

/* Allocates the drawing board record and sets its pen defaults. */
CtvtDrawScene *CTVT_DRAW_Create(CtvtWork *work, u16 heapId)
{
    CtvtDrawScene *scene = GFL_HEAP_Alloc(heapId, sizeof(CtvtDrawScene), 1, (const char *)0x021C7228, 0xcf);

    scene->penSize = 0;
    scene->stampKind = 3;
    scene->toolMode = 0;
    scene->drawTool = 0;
    scene->penColor = 0x8000;
    return scene;
}

void CTVT_DRAW_Free(CtvtWork *work, CtvtDrawScene *scene)
{
    GFL_HEAP_Free(scene);
}

/* Builds the drawing board screen: loads the graphics, creates the button and picker
 * sprites, opens the title window and clears the state. */
void CTVT_DRAW_Init(CtvtWork *work, CtvtDrawScene *scene)
{
    CtvtActorDesc d;
    u16 heapId;
    u8 i;
    struct ArcHandle *arc;
    struct MsgData *msgData;
    u32 font;
    struct PrintQue *printQue;
    struct StrBuf *text;

    heapId = COMM_TVT_SYS_GetHeapId(work);
    ARC_UTIL_UploadBgPaletteFromHandle(COMM_TVT_SYS_GetArc(work), 0x10, 7, 0, 0, 0, heapId);
    BG_SYS_PushTile(7);
    BG_SYS_SetPlaneVisible(5, 0);
    {
        u32 t = REG_POWCNT1;
        REG_POWCNT1 = t & 0xFFFF7FFF;
    }
    arc = ARC_TOOL_CreateHandle(APP_ICON_GetArchiveId(), heapId);
    BG_SYS_ClearSlot(0);
    func_02049990(arc, APP_ICON_GetStatusDataFileId(), 0, 0x60, 0, 0x600, 0, heapId);
    BG_SYS_FillTileMap(0, 0, 0x15, 0x20, 3, 0);
    BG_SYS_PushTile(0);
    BG_SYS_FillScrollArea(0, 3, 0);
    ARC_TOOL_DeleteHandle(arc);
    d.x = 0x10;
    d.y = 0xcc;
    d.animSeq = 1;
    d.priority = 8;
    d.flags = 0;
    scene->button[0] = CLACT_CreateActor(COMM_TVT_SYS_GetClactUnit(work), COMM_TVT_SYS_GetResId(work, 4), COMM_TVT_SYS_GetResId(work, 0), COMM_TVT_SYS_GetResId(work, 8), &d, 0, heapId);
    d.x = 0x38;
    d.animSeq = 0x3;
    scene->button[1] = CLACT_CreateActor(COMM_TVT_SYS_GetClactUnit(work), COMM_TVT_SYS_GetResId(work, 4), COMM_TVT_SYS_GetResId(work, 0), COMM_TVT_SYS_GetResId(work, 8), &d, 0, heapId);
    d.x = 0x60;
    d.animSeq = 0x5;
    scene->button[2] = CLACT_CreateActor(COMM_TVT_SYS_GetClactUnit(work), COMM_TVT_SYS_GetResId(work, 4), COMM_TVT_SYS_GetResId(work, 0), COMM_TVT_SYS_GetResId(work, 8), &d, 0, heapId);
    d.x = 0x88;
    d.animSeq = 0x7;
    scene->button[3] = CLACT_CreateActor(COMM_TVT_SYS_GetClactUnit(work), COMM_TVT_SYS_GetResId(work, 4), COMM_TVT_SYS_GetResId(work, 0), COMM_TVT_SYS_GetResId(work, 8), &d, 0, heapId);
    d.x = 0xc8;
    if (COMM_TVT_SYS_GetViewSwapped(work) == 1) {
        d.animSeq = 0xc;
    } else {
        d.animSeq = 0xa;
    }
    scene->button[4] = CLACT_CreateActor(COMM_TVT_SYS_GetClactUnit(work), COMM_TVT_SYS_GetResId(work, 4), COMM_TVT_SYS_GetResId(work, 0), COMM_TVT_SYS_GetResId(work, 8), &d, 0, heapId);
    d.x = 0xe0;
    d.y = 0xc0;
    d.animSeq = 0x1;
    scene->button[5] = CLACT_CreateActor(COMM_TVT_SYS_GetClactUnit(work), COMM_TVT_SYS_GetResId(work, 7), COMM_TVT_SYS_GetResId(work, 3), COMM_TVT_SYS_GetResId(work, 10), &d, 0, heapId);
    CLACT_SetActorAutoAnim(scene->button[5], 1);
    for (i = 0; i < 6; i++) {
        CLACT_SetActorDrawEnable(scene->button[i], 1);
    }
    d.x = 0x38;
    d.y = 0x48;
    d.animSeq = 0xe;
    scene->helpIcon[0] = CLACT_CreateActor(COMM_TVT_SYS_GetClactUnit(work), COMM_TVT_SYS_GetResId(work, 5), COMM_TVT_SYS_GetResId(work, 1), COMM_TVT_SYS_GetResId(work, 9), &d, 1, heapId);
    d.y = 0x5c;
    d.animSeq = 0xf;
    scene->helpIcon[1] = CLACT_CreateActor(COMM_TVT_SYS_GetClactUnit(work), COMM_TVT_SYS_GetResId(work, 5), COMM_TVT_SYS_GetResId(work, 1), COMM_TVT_SYS_GetResId(work, 9), &d, 1, heapId);
    d.y = 0x70;
    d.animSeq = 0x10;
    scene->helpIcon[2] = CLACT_CreateActor(COMM_TVT_SYS_GetClactUnit(work), COMM_TVT_SYS_GetResId(work, 5), COMM_TVT_SYS_GetResId(work, 1), COMM_TVT_SYS_GetResId(work, 9), &d, 1, heapId);
    d.y = 0x84;
    d.animSeq = 0x11;
    scene->helpIcon[3] = CLACT_CreateActor(COMM_TVT_SYS_GetClactUnit(work), COMM_TVT_SYS_GetResId(work, 5), COMM_TVT_SYS_GetResId(work, 1), COMM_TVT_SYS_GetResId(work, 9), &d, 1, heapId);
    d.x = 0x2c;
    d.y = 0x8c;
    d.animSeq = 0x1;
    scene->helpIcon[4] = CLACT_CreateActor(COMM_TVT_SYS_GetClactUnit(work), COMM_TVT_SYS_GetResId(work, 6), COMM_TVT_SYS_GetResId(work, 2), COMM_TVT_SYS_GetResId(work, 10), &d, 1, heapId);
    for (i = 0; i < 5; i++) {
        CLACT_SetActorDrawEnable(scene->helpIcon[i], 0);
    }
    d.x = 0x10;
    d.y = 0xa0;
    d.animSeq = 0xf;
    scene->penPicker = CLACT_CreateActor(COMM_TVT_SYS_GetClactUnit(work), COMM_TVT_SYS_GetResId(work, 4), COMM_TVT_SYS_GetResId(work, 0), COMM_TVT_SYS_GetResId(work, 8), &d, 0, heapId);
    CLACT_SetActorDrawEnable(scene->penPicker, 0);
    d.x = 0x88;
    d.y = 0xa0;
    d.animSeq = 0x10;
    scene->stampPicker = CLACT_CreateActor(COMM_TVT_SYS_GetClactUnit(work), COMM_TVT_SYS_GetResId(work, 4), COMM_TVT_SYS_GetResId(work, 0), COMM_TVT_SYS_GetResId(work, 8), &d, 0, heapId);
    CLACT_SetActorDrawEnable(scene->stampPicker, 0);
    d.priority = 0;
    scene->pickMarker = CLACT_CreateActor(COMM_TVT_SYS_GetClactUnit(work), COMM_TVT_SYS_GetResId(work, 4), COMM_TVT_SYS_GetResId(work, 0), COMM_TVT_SYS_GetResId(work, 8), &d, 0, heapId);
    CLACT_SetActorDrawEnable(scene->pickMarker, 0);
    d.animSeq = 0x19;
    d.priority = 2;
    scene->cursor = CLACT_CreateActor(COMM_TVT_SYS_GetClactUnit(work), COMM_TVT_SYS_GetResId(work, 4), COMM_TVT_SYS_GetResId(work, 0), COMM_TVT_SYS_GetResId(work, 8), &d, 0, heapId);
    CLACT_SetActorDrawEnable(scene->cursor, 0);
    CTVT_DRAW_UpdateToolButtons(work, scene);
    scene->helpWin = 0;
    scene->messageWin = 0;
    font = COMM_TVT_SYS_GetFont(work);
    msgData = COMM_TVT_SYS_GetMsgData(work);
    printQue = COMM_TVT_SYS_GetPrintQue(work);
    scene->titleWin = BMP_WIN_Create(4, 3, 1, 0x1c, 2, 0xa, 1);
    BMP_Clear(BMP_WIN_GetBmp(scene->titleWin), 0);
    text = MSGDATA_AllocString(msgData, 0xb);
    PRINTSYS_PrintQueColor(printQue, BMP_WIN_GetBmp(scene->titleWin), 1, 0, text, font, 0x440);
    STRBUF_Delete(text);
    scene->titlePending = 1;
    scene->state = 0;
    scene->panelTarget = 0x18;
    scene->panelPos = 0x18;
    scene->fadePhase = 0;
    scene->penDown = 0;
    scene->uiHandled = 0;
    scene->sizePickerOpen = 0;
    scene->stampPickerOpen = 0;
    scene->helpPending = 0;
    scene->messagePending = 0;
    scene->touchEnabled = 0;
    scene->exitKind = 0;
    scene->cameraHidden = 0;
    REG_BG_PLTT_COLOR13 = scene->penColor & 0x7fff;
    CTVT_DRAW_ShowHelp(work, scene, 0);
    GFL_NET_RestartWithDefaultTimeout(1, heapId);
    COMM_TVT_SYS_HideSlotMarker(work);
}

void CTVT_DRAW_Exit(CtvtWork *work, CtvtDrawScene *scene)
{
    struct BmpWin *win;
    u8 i;
    u16 heapId;

    heapId = COMM_TVT_SYS_GetHeapId(work);
    if (scene->toolMode == 1) {
        scene->toolMode = (scene->drawTool == 0) ? 0 : 3;
    }
    win = 0;
    GFL_NET_RestartWithDefaultTimeout(0, heapId);
    BMP_MENUWORK_DrawWindowBorder(scene->helpWin, 0);
    win = scene->helpWin;
    BMP_WIN_ClearScreen(win);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer(win));
    BMP_WIN_Delete(scene->helpWin);
    win = scene->titleWin;
    BMP_WIN_ClearScreen(win);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer(win));
    BMP_WIN_Delete(scene->titleWin);
    win = scene->messageWin;
    if (win != 0) {
        BMP_WIN_ClearScreen(win);
        BG_SYS_PushTile(BMP_WIN_GetBgLayer(win));
        BMP_WIN_Delete(scene->messageWin);
        scene->messageWin = 0;
    }
    for (i = 0; i < 5; i++) {
        CLACT_DeleteActor(scene->helpIcon[i]);
    }
    for (i = 0; i < 6; i++) {
        CLACT_DeleteActor(scene->button[i]);
    }
    CLACT_DeleteActor(scene->cursor);
    CLACT_DeleteActor(scene->pickMarker);
    CLACT_SetActorDrawEnable(scene->stampPicker, 0);
    CLACT_DeleteActor(scene->stampPicker);
    CLACT_SetActorDrawEnable(scene->penPicker, 0);
    CLACT_DeleteActor(scene->penPicker);
    BG_SYS_ClearSlot(0);
    BG_SYS_PushTile(0);
    BG_SYS_FillScrollArea(0, 3, 0);
    BG_SYS_ClearSlot(6);
    BG_SYS_PushTile(6);
    BG_SYS_SetPlaneVisible(5, 1);
    REG_POWCNT1 |= 0x8000;
    COMM_TVT_SYS_ClearNameWindows(work);
}

/* Per-frame state machine of the drawing board: one switch on the screen state, then
 * the window transfers, the camera view keys, the swap key and the backdrop fade. */
int CTVT_DRAW_Main(CtvtWork *work, CtvtDrawScene *scene)
{
    u16 heapId;
    CtvtCamView *camView;
    int flag;
    int zero;
    u8 i;
    struct PrintQue *printQue;
    u32 sine;
    int visible;
    u32 phase;

    heapId = COMM_TVT_SYS_GetHeapId(work);
    zero = 0;
    scene->uiHandled = zero;
    switch (scene->state) {
    case 0:
        if (COMM_TVT_SYS_GetReturnedFromChild(work) == 1) {
            WIPE_SYS_Start(zero, 1, 1, zero, 6, 1, heapId);
        } else {
            WIPE_SYS_Start(4, 1, 1, zero, 6, 1, heapId);
        }
        scene->state = 1;
        break;
    case 1:
        if (WIPE_SYS_EndCheck() == 1) {
            scene->touchEnabled = 1;
            scene->state = 4;
        }
        break;
    case 2:
        camView = COMM_TVT_SYS_GetCamView(work);
        if (scene->cameraHidden != 0) {
            if (CTVT_CAMVIEW_IsShutterIdle(work, camView) != 1) {
                break;
            }
        }
        WIPE_SYS_Start(0, 0, 0, 0, 6, 1, heapId);
        scene->state = 3;
        scene->touchEnabled = 0;
        break;
    case 3:
        if (WIPE_SYS_EndCheck() == 1) {
            if (scene->exitKind == 0) {
                return 1;
            }
            return 4;
        }
        break;
    case 4:
        if (CTVT_DRAW_CheckLeave(work, &scene->state) == 0) {
            CTVT_DRAW_UpdateCanvasMode(work, scene);
        }
        break;
    case 5:
        if (CTVT_DRAW_CheckLeave(work, &scene->state) == 0) {
            CTVT_DRAW_UpdatePanelMode(work, scene);
        }
        break;
    case 6:
        CTVT_COMM_StopSession(work, COMM_TVT_SYS_GetComm(work));
        CTVT_DRAW_ShowMessage(work, scene, 0x24);
        flag = 1;
        COMM_TVT_SYS_SetMessageActive(work, 1);
        scene->state = 7;
        CTVT_CAMVIEW_RequestShutterSound1(work, COMM_TVT_SYS_GetCamView(work));
        scene->cameraHidden = flag;
        break;
    case 7:
        if (TOUCHPANEL_GetTrg() == 1 || (KEY_GetTrg() & 3) != 0) {
            scene->exitKind = flag = 1;
            scene->state = 2;
            COMM_TVT_SYS_SetMessageActive(work, 1);
            CTVT_CAMVIEW_StopCapture(work, COMM_TVT_SYS_GetCamView(work));
            scene->cameraHidden = flag;
        }
        break;
    case 8:
        if (CTVT_COMM_SendCommand(work, COMM_TVT_SYS_GetComm(work), 10, zero) == 1) {
            scene->state = 9;
        }
        break;
    case 9:
        CTVT_COMM_StopSession(work, COMM_TVT_SYS_GetComm(work));
        CTVT_DRAW_ShowMessage(work, scene, 0x25);
        flag = 1;
        COMM_TVT_SYS_SetMessageActive(work, 1);
        scene->state = 10;
        scene->messageTimer = zero;
        CTVT_CAMVIEW_RequestShutterSound1(work, COMM_TVT_SYS_GetCamView(work));
        scene->cameraHidden = flag;
        break;
    case 10:
        scene->messageTimer = scene->messageTimer + 1;
        if (TOUCHPANEL_GetTrg() == 1 || (KEY_GetTrg() & 3) != 0
            || scene->messageTimer >= 300) {
            scene->state = 11;
        }
        break;
    case 11:
        CTVT_COMM_SetTimingSync(work, COMM_TVT_SYS_GetComm(work), 0x2f);
        scene->state = 12;
        break;
    case 12:
        if (CTVT_COMM_IsTimingSync(work, COMM_TVT_SYS_GetComm(work), 0x2f) == 1) {
            scene->exitKind = flag = 1;
            scene->state = 2;
            COMM_TVT_SYS_SetMessageActive(work, 1);
            CTVT_CAMVIEW_StopCapture(work, COMM_TVT_SYS_GetCamView(work));
            scene->cameraHidden = flag;
        }
        break;
    case 13:
        CTVT_COMM_StopSession(work, COMM_TVT_SYS_GetComm(work));
        CTVT_DRAW_ShowMessage(work, scene, 0x26);
        flag = 1;
        COMM_TVT_SYS_SetMessageActive(work, 1);
        scene->state = 14;
        CTVT_CAMVIEW_RequestShutterSound1(work, COMM_TVT_SYS_GetCamView(work));
        scene->cameraHidden = flag;
        break;
    case 14:
        if (TOUCHPANEL_GetTrg() == 1 || (KEY_GetTrg() & 3) != 0) {
            scene->exitKind = flag = 1;
            scene->state = 2;
            COMM_TVT_SYS_SetMessageActive(work, 1);
            CTVT_CAMVIEW_StopCapture(work, COMM_TVT_SYS_GetCamView(work));
            scene->cameraHidden = flag;
        }
        break;
    }
    CTVT_DRAW_SlidePanel(work, scene);
    if (scene->touchEnabled == 1) {
        CTVT_DRAW_UpdateCanvasTouch(work, scene);
    }
    if (scene->helpPending == 1) {
        printQue = COMM_TVT_SYS_GetPrintQue(work);
        if (PRINTSYS_QUE_IsExistTarget(printQue, BMP_WIN_GetBmp(scene->helpWin)) == 0) {
            BMP_MENUWORK_DrawWindow(scene->helpWin, 2, 0x140, 9);
            BMP_WIN_TransferChars(scene->helpWin);
            BMP_WIN_MakeScreen(scene->helpWin);
            BG_SYS_SetFlagField06(4);
            i = 0;
            scene->helpPending = 0;
            if (scene->helpPage == 1) {
                visible = 1;
                for (i = 0; i < 5; i++) {
                    CLACT_SetActorDrawEnable(scene->helpIcon[i], visible);
                }
            } else {
                visible = i;
                for (i = 0; i < 5; i++) {
                    CLACT_SetActorDrawEnable(scene->helpIcon[i], visible);
                }
            }
        }
    }
    if (scene->titlePending == 1) {
        printQue = COMM_TVT_SYS_GetPrintQue(work);
        if (PRINTSYS_QUE_IsExistTarget(printQue, BMP_WIN_GetBmp(scene->titleWin)) == 0) {
            BMP_WIN_TransferChars(scene->titleWin);
            BMP_WIN_MakeScreen(scene->titleWin);
            BG_SYS_PushTile(4);
            scene->titlePending = 0;
        }
    }
    if (scene->messagePending == 1 && scene->messageWin != 0) {
        printQue = COMM_TVT_SYS_GetPrintQue(work);
        if (PRINTSYS_QUE_IsExistTarget(printQue, BMP_WIN_GetBmp(scene->messageWin)) == 0) {
            BMP_WIN_TransferChars(scene->messageWin);
            BMP_WIN_MakeScreen(scene->messageWin);
            BG_SYS_PushTile(0);
            scene->messagePending = 0;
        }
    }
    if (scene->state <= 5 && COMM_TVT_SYS_GetViewSwapped(work) == 0) {
        camView = COMM_TVT_SYS_GetCamView(work);
        if (KEY_GetTrg() & 0x40) {
            CTVT_CAMVIEW_SetCameraEffect(work, camView, 0);
        }
        if (KEY_GetTrg() & 0x10) {
            CTVT_CAMVIEW_SetCameraEffect(work, camView, 5);
        }
        if (KEY_GetTrg() & 0x80) {
            CTVT_CAMVIEW_SetCameraEffect(work, camView, 1);
        }
        if (KEY_GetTrg() & 0x20) {
            CTVT_CAMVIEW_SetCameraEffect(work, camView, 3);
        }
    }
    if (COMM_TVT_SYS_GetSelfSlot(work) == 0 && (KEY_GetTrg() & 0x200)) {
        if (CTVT_CAMVIEW_IsLayoutChanging(work, COMM_TVT_SYS_GetCamView(work)) == 0) {
            COMM_TVT_SYS_ToggleHalfRes(work);
            GFL_USE_PlaySeDefaultVolume(0x66C);
        }
    }
    phase = *(volatile u16 *)&scene->fadePhase;
    scene->fadePhase = ((s32)(phase + 0x400) >= 0x10000) ? phase - 0xFC00 : *(volatile u16 *)&scene->fadePhase + 0x400;
    sine = FX_SinCosTable_[(scene->fadePhase >> 4) * 2 + 1];
    sine = (s16)((s32)(sine + 0x1000) / 2);
    sine = (u8)(((s32)sine * -9 >> 12) + 0x1c);
    scene->fadeColor = sine | (sine << 5) | (sine << 10);
    NNS_GfdRegisterNewVramTransferTask(0xe, 0xde, &scene->fadeColor, 2);
    return 3;
}

void CTVT_DRAW_UpdateCanvasMode(CtvtWork *work, CtvtDrawScene *scene)
{
    if ((KEY_GetTrg() & 1024) && scene->helpPending == 0) {
        if (CLACT_IsActorAnimActive(scene->button[5]) == 0 ||
            CLACT_GetActorAnimSeq(scene->button[5]) == 1) {
            scene->state = 5;
            scene->panelTarget = 0;
            CTVT_DRAW_ShowHelp(work, scene, 1);
            CLACT_SetActorAnimSeq(scene->button[5], 1);
            GFL_USE_PlaySeDefaultVolume(1644);
        }
    } else if (KEY_GetTrg() & 2) {
        scene->state = 2;
        GFL_USE_PlaySeDefaultVolume(1361);
    }
    if (KEY_GetTrg() & 12) {
        COMM_TVT_SYS_ToggleViewSwapped(work);
        CTVT_DRAW_UpdateToolButtons(work, scene);
        GFL_USE_PlaySeDefaultVolume(1647);
    }
}

void CTVT_DRAW_UpdatePanelMode(CtvtWork *work, CtvtDrawScene *scene)
{
    CtvtPoint penMarkerPos;
    CtvtPoint stampMarkerPos;
    CtvtPoint penCursorPos;
    CtvtPoint stampCursorPos;
    int hitButton;
    int hitItem;

    hitButton = TOUCHPANEL_HitTrg(gCtvtDrawPanelButtonRects);
    if (hitButton == 0 && CLACT_GetActorDrawEnable(scene->pickMarker) == 0) {
        scene->toolMode = 0;
        scene->drawTool = 0;
        CTVT_DRAW_UpdateToolButtons(work, scene);
        scene->uiHandled = 1;
        scene->sizePickerOpen = 1;
        CLACT_SetActorDrawEnable(scene->penPicker, 1);
        CLACT_SetActorAutoAnim(scene->penPicker, 1);
        GFL_USE_PlaySeDefaultVolume(0x66c);
    }
    if (hitButton == 1) {
        scene->toolMode = 1;
        CTVT_DRAW_UpdateToolButtons(work, scene);
        scene->uiHandled = 1;
        GFL_USE_PlaySeDefaultVolume(0x66c);
    }
    if (hitButton == 2) {
        scene->toolMode = 2;
        CTVT_DRAW_UpdateToolButtons(work, scene);
        scene->uiHandled = 1;
        GFL_USE_PlaySeDefaultVolume(0x66c);
    }
    if (hitButton == 3 && CLACT_GetActorDrawEnable(scene->pickMarker) == 0) {
        scene->toolMode = 3;
        scene->drawTool = 1;
        CTVT_DRAW_UpdateToolButtons(work, scene);
        scene->uiHandled = 1;
        scene->stampPickerOpen = 1;
        CLACT_SetActorDrawEnable(scene->stampPicker, 1);
        CLACT_SetActorAutoAnim(scene->stampPicker, 1);
        GFL_USE_PlaySeDefaultVolume(0x66c);
    }
    if (hitButton == 4) {
        COMM_TVT_SYS_ToggleViewSwapped(work);
        CTVT_DRAW_UpdateToolButtons(work, scene);
        scene->uiHandled = 1;
        GFL_USE_PlaySeDefaultVolume(0x66f);
    }
    if (scene->sizePickerOpen == 1) {
        hitItem = TOUCHPANEL_HitTrg(gCtvtDrawSizePickerRects);
        if (hitItem != -1) {
            scene->penSize = gCtvtDrawPenSizeValues[hitItem];
            scene->uiHandled = 1;
            penMarkerPos = gCtvtDrawPenMarkerPos;
            CLACT_SetActorDrawEnable(scene->pickMarker, 1);
            CLACT_RestartActorAnim(scene->pickMarker);
            CLACT_SetActorAutoAnim(scene->pickMarker, 1);
            CLACT_SetActorAnimSeq(scene->pickMarker, (u16)(hitItem + 0x11));
            CLACT_AddActorSurfacePos(scene->pickMarker, &penMarkerPos, 0);
            CLACT_SetActorDrawEnable(scene->cursor, 0);
            GFL_USE_PlaySeDefaultVolume(0x66c);
        }
    }
    if (scene->stampPickerOpen == 1) {
        hitItem = TOUCHPANEL_HitTrg(gCtvtDrawStampPickerRects);
        if (hitItem != -1) {
            scene->stampKind = gCtvtDrawStampKindValues[hitItem];
            scene->uiHandled = 1;
            GFL_USE_PlaySeDefaultVolume(0x66c);
            stampMarkerPos = gCtvtDrawStampMarkerPos;
            CLACT_SetActorDrawEnable(scene->pickMarker, 1);
            CLACT_RestartActorAnim(scene->pickMarker);
            CLACT_SetActorAutoAnim(scene->pickMarker, 1);
            CLACT_SetActorAnimSeq(scene->pickMarker, (u16)(hitItem + 0x14));
            CLACT_AddActorSurfacePos(scene->pickMarker, &stampMarkerPos, 0);
            CLACT_SetActorDrawEnable(scene->cursor, 0);
        }
    }
    if ((KEY_GetTrg() & 0x400) || (KEY_GetTrg() & 2) || hitButton == 5) {
        if (scene->helpPending == 0) {
            scene->state = 4;
            scene->panelTarget = 0x18;
            scene->uiHandled = 1;
            CTVT_DRAW_ShowHelp(work, scene, 0);
            CTVT_DRAW_ClosePickers(work, scene);
            GFL_USE_PlaySeDefaultVolume(0x551);
            CLACT_SetActorAnimSeq(scene->button[5], 9);
        }
    }
    if (KEY_GetTrg() & 0xc) {
        COMM_TVT_SYS_ToggleViewSwapped(work);
        CTVT_DRAW_UpdateToolButtons(work, scene);
        GFL_USE_PlaySeDefaultVolume(0x66f);
    }
    if (CLACT_GetActorDrawEnable(scene->pickMarker) == 1 && CLACT_IsActorAnimActive(scene->pickMarker) == 0) {
        CTVT_DRAW_ClosePickers(work, scene);
    }
    if (scene->sizePickerOpen == 1 && CLACT_IsActorAnimActive(scene->penPicker) == 0 && CLACT_GetActorDrawEnable(scene->cursor) == 0) {
        penCursorPos = gCtvtDrawPenCursorPos;
        switch (scene->penSize) {
        case 1:
            penCursorPos.x = penCursorPos.x + 0x10;
            break;
        case 0:
            penCursorPos.x = penCursorPos.x + 0x20;
            break;
        case 2:
            break;
        }
        CLACT_AddActorSurfacePos(scene->cursor, &penCursorPos, 0);
        CLACT_SetActorDrawEnable(scene->cursor, 1);
    }
    if (scene->stampPickerOpen == 1 && CLACT_IsActorAnimActive(scene->stampPicker) == 0 && CLACT_GetActorDrawEnable(scene->cursor) == 0) {
        stampCursorPos = gCtvtDrawStampCursorPos;
        switch (scene->stampKind) {
        case 3:
            stampCursorPos.x = stampCursorPos.x - 0x20;
            break;
        case 4:
            stampCursorPos.x = stampCursorPos.x - 0x10;
            break;
        case 6:
            stampCursorPos.x = stampCursorPos.x + 0x10;
            break;
        case 7:
            stampCursorPos.x = stampCursorPos.x + 0x20;
            break;
        }
        CLACT_AddActorSurfacePos(scene->cursor, &stampCursorPos, 0);
        CLACT_SetActorDrawEnable(scene->cursor, 1);
    }
}

void CTVT_DRAW_UpdateCanvasTouch(CtvtWork *work, CtvtDrawScene *scene)
{
    u32 x;
    u32 y;
    int full1;
    u32 x2;
    u32 y2;
    int full2;
    struct CtvtSprites *sprites2;
    struct CtvtSprites *sprites1;
    u32 srcRow;
    u16 *bgBuf;
    u32 srcOff;
    u32 dstAddr;
    u32 srcColor;
    u32 dstColor;
    u8 mode;
    u32 unusedBase;
    CtvtStroke *stroke;
    struct CtvtComm *comm;

    TOUCHPANEL_GetPointTrg(&x, &y);
    if (COMM_TVT_SYS_GetInputLocked(work) == 1) {
        return;
    }
    if (TOUCHPANEL_GetCont() == 0) {
        scene->penDown = 0;
    }
    if (TOUCHPANEL_GetTrg() == 1 && scene->uiHandled == 0 && scene->state == 5 && y >= 0xa8) {
        if (scene->toolMode == 1) {
            scene->toolMode = (scene->drawTool == 0) ? 0 : 3;
            CTVT_DRAW_UpdateToolButtons(work, scene);
        }
        CTVT_DRAW_ClosePickers(work, scene);
        return;
    }
    if ((u32)(scene->state - 4) <= 1 && TOUCHPANEL_GetTrg() == 1 && scene->uiHandled == 0 && scene->toolMode == 3) {
        mode = COMM_TVT_SYS_GetMemberCount(work);
        comm = COMM_TVT_SYS_GetComm(work);
        sprites1 = COMM_TVT_SYS_GetSprites(work);
        stroke = CTVT_COMM_PopStroke(work, comm, &full1);
        if (full1 == 0) {
            stroke->x0 = x;
            stroke->y0 = y;
            stroke->x1 = x;
            stroke->y1 = y;
            stroke->kind = scene->stampKind;
            stroke->color = scene->penColor;
            if (mode == 1) {
                DRAW_SYSTEM_PushStroke(sprites1, stroke);
            } else {
                CTVT_COMM_AdvanceWriteCursor(work, comm);
            }
        }
    }
    if (TOUCHPANEL_GetTrg() == 1 && scene->uiHandled == 0) {
        if (scene->toolMode == 1) {
            bgBuf = G2_GetBG2ScrPtr();
            srcOff = y << 9;
            srcRow = (x << 1) + (u32)bgBuf;
            G2_GetBG3ScrPtr();
            if (COMM_TVT_SYS_GetHalfRes(work) == 1) {
                dstAddr = ((y >> 1) << 9) + ((x & ~1) + G2_GetBG3ScrPtr());
            } else {
                dstAddr = (y << 9) + ((x << 1) + G2_GetBG3ScrPtr());
            }
            srcColor = *(u16 *)(srcOff + srcRow);
            if (srcColor & 0x8000) {
                scene->penColor = srcColor;
            } else {
                dstColor = *(u16 *)dstAddr;
                if (dstColor & 0x8000) {
                    scene->penColor = dstColor;
                } else {
                    scene->penColor = 0x8000;
                }
            }
            REG_BG_PLTT_COLOR13 = scene->penColor & 0x7fff;
            scene->toolMode = (scene->drawTool == 0) ? 0 : 3;
            CTVT_DRAW_UpdateToolButtons(work, scene);
            GFL_USE_PlaySeDefaultVolume(0x66d);
        } else {
            scene->penDown = 1;
            scene->lastX = 0xffff;
            scene->lastY = 0xffff;
            CTVT_DRAW_ClosePickers(work, scene);
        }
    }
    if ((scene->toolMode == 0 || scene->toolMode == 2) && scene->penDown == 1) {
        TOUCHPANEL_GetPointCont(&x2, &y2);
        if (scene->penDown == 1) {
            if (scene->lastX != 0xffff && scene->lastY != 0xffff) {
                mode = COMM_TVT_SYS_GetMemberCount(work);
                comm = COMM_TVT_SYS_GetComm(work);
                sprites2 = COMM_TVT_SYS_GetSprites(work);
                stroke = CTVT_COMM_PopStroke(work, comm, &full2);
                if (full2 == 0) {
                    stroke->x0 = scene->lastX;
                    stroke->y0 = scene->lastY;
                    stroke->x1 = x2;
                    stroke->y1 = y2;
                    stroke->kind = scene->penSize;
                    if (scene->toolMode == 2) {
                        stroke->color = 0;
                        stroke->kind = 2;
                    } else {
                        stroke->color = scene->penColor;
                    }
                    if (mode == 1) {
                        DRAW_SYSTEM_PushStroke(sprites2, stroke);
                    } else {
                        CTVT_COMM_AdvanceWriteCursor(work, comm);
                    }
                } else {
                    scene->penDown = 0;
                }
            }
            scene->lastX = x2;
            scene->lastY = y2;
        }
    }
}

void CTVT_DRAW_SlidePanel(CtvtWork *work, CtvtDrawScene *scene)
{
    CtvtPoint pos;
    u8 i;
    int changed = 0;
    if (CLACT_IsActorAnimActive(scene->button[5]) == 0 ||
        CLACT_GetActorAnimSeq(scene->button[5]) == 1) {
        if ((u8)scene->panelTarget < (u8)scene->panelPos) { scene->panelPos -= 24; changed = 1; }
        else if ((u8)scene->panelTarget > (u8)scene->panelPos) { scene->panelPos += 24; changed = 1; }
    }
    if (changed == 1) {
        BG_SYS_ResetSlot(0, 3, 24 - (u8)scene->panelPos);
        for (i = 0; i < 6; i++) {
            CLACT_GetActorSurfacePos(scene->button[i], &pos, 0);
            pos.y = scene->panelPos + 180;
            if (i == 5) pos.y -= 12;
            CLACT_AddActorSurfacePos(scene->button[i], &pos, 0);
        }
    }
}

void CTVT_DRAW_UpdateToolButtons(CtvtWork *work, CtvtDrawScene *scene)
{
    int enabled;

    CLACT_SetActorAnimSeq(scene->button[0], gCtvtDrawPenButtonAnimSeq[scene->toolMode == 0]);
    CLACT_SetActorAnimSeq(scene->button[1], gCtvtDrawPickButtonAnimSeq[scene->toolMode == 1]);
    CLACT_SetActorAnimSeq(scene->button[2], gCtvtDrawEraserButtonAnimSeq[scene->toolMode == 2]);
    CLACT_SetActorAnimSeq(scene->button[3], gCtvtDrawStampButtonAnimSeq[scene->toolMode == 3]);
    enabled = COMM_TVT_SYS_GetViewSwapped(work);
    if (enabled == 1) {
        CLACT_SetActorAnimSeq(scene->button[4], 12);
    } else {
        CLACT_SetActorAnimSeq(scene->button[4], 10);
    }
    if (scene->toolMode != 0 && scene->sizePickerOpen == 1) {
        scene->sizePickerOpen = 0;
        CLACT_SetActorDrawEnable(scene->penPicker, 0);
        CLACT_RestartActorAnim(scene->penPicker);
        CLACT_SetActorAnimFrame(scene->penPicker, 0);
        CLACT_SetActorAutoAnim(scene->penPicker, 0);
        CLACT_SetActorDrawEnable(scene->cursor, 0);
    }
    if (scene->toolMode != 3 && scene->stampPickerOpen == 1) {
        scene->stampPickerOpen = 0;
        CLACT_SetActorDrawEnable(scene->stampPicker, 0);
        CLACT_RestartActorAnim(scene->stampPicker);
        CLACT_SetActorAnimFrame(scene->stampPicker, 0);
        CLACT_SetActorAutoAnim(scene->stampPicker, 0);
        CLACT_SetActorDrawEnable(scene->cursor, 0);
    }
}

void CTVT_DRAW_ShowHelp(CtvtWork *work, CtvtDrawScene *scene, int page)
{
    struct StrBuf *textMsg5Or9;
    struct StrBuf *textMsg4;
    struct StrBuf *textMsg3;
    struct StrBuf *textMsg2;
    struct StrBuf *textMsg1;
    struct StrBuf *textMsg0;
    struct StrBuf *textMsg10;
    struct StrBuf *textMsg8;
    struct StrBuf *textMsg7;
    struct StrBuf *textMsg6;
    struct BmpWin *oldWin;
    struct MsgData *msgData;
    struct PrintQue *printQue;
    u32 font;

    font = COMM_TVT_SYS_GetFont(work);
    msgData = COMM_TVT_SYS_GetMsgData(work);
    printQue = COMM_TVT_SYS_GetPrintQue(work);
    oldWin = scene->helpWin;
    if (oldWin != 0) {
        PRINTSYS_QUE_Clear(printQue);
        BMP_MENUWORK_DrawWindowBorder(scene->helpWin, 2);
        BMP_WIN_ClearScreen(scene->helpWin);
    }
    scene->helpPage = page;
    if (page == 1) {
        scene->helpWin = BMP_WIN_Create(4, 2, 8, 0x1c, 0xd, 0xa, 1);
        BMP_Clear(BMP_WIN_GetBmp(scene->helpWin), 0xf);
        BMP_WIN_TransferChars(scene->helpWin);
        textMsg6 = MSGDATA_AllocString(msgData, 6);
        PRINTSYS_PrintQueColor(printQue, BMP_WIN_GetBmp(scene->helpWin), 0x40, 0x4, textMsg6, font, 0x440);
        STRBUF_Delete(textMsg6);
        textMsg7 = MSGDATA_AllocString(msgData, 7);
        PRINTSYS_PrintQueColor(printQue, BMP_WIN_GetBmp(scene->helpWin), 0x40, 0x18, textMsg7, font, 0x440);
        STRBUF_Delete(textMsg7);
        textMsg8 = MSGDATA_AllocString(msgData, 8);
        PRINTSYS_PrintQueColor(printQue, BMP_WIN_GetBmp(scene->helpWin), 0x40, 0x2c, textMsg8, font, 0x440);
        STRBUF_Delete(textMsg8);
        textMsg10 = MSGDATA_AllocString(msgData, 10);
        PRINTSYS_PrintQueColor(printQue, BMP_WIN_GetBmp(scene->helpWin), 0x40, 0x40, textMsg10, font, 0x440);
        STRBUF_Delete(textMsg10);
        textMsg5Or9 = MSGDATA_AllocString(msgData, 9);
        PRINTSYS_PrintQueColor(printQue, BMP_WIN_GetBmp(scene->helpWin), 0x40, 0x54, textMsg5Or9, font, 0x440);
        STRBUF_Delete(textMsg5Or9);
    } else {
        scene->helpWin = BMP_WIN_Create(4, 2, 0x10, 0x1c, 6, 0xa, 1);
        BMP_Clear(BMP_WIN_GetBmp(scene->helpWin), 0xf);
        BMP_WIN_TransferChars(scene->helpWin);
        textMsg0 = MSGDATA_AllocString(msgData, 0);
        PRINTSYS_PrintQueColor(printQue, BMP_WIN_GetBmp(scene->helpWin), 0x8, 0x0, textMsg0, font, 0x440);
        STRBUF_Delete(textMsg0);
        textMsg1 = MSGDATA_AllocString(msgData, 1);
        PRINTSYS_PrintQueColor(printQue, BMP_WIN_GetBmp(scene->helpWin), 0x8, 0x10, textMsg1, font, 0x440);
        STRBUF_Delete(textMsg1);
        textMsg2 = MSGDATA_AllocString(msgData, 2);
        PRINTSYS_PrintQueColor(printQue, BMP_WIN_GetBmp(scene->helpWin), 0x8, 0x20, textMsg2, font, 0x440);
        STRBUF_Delete(textMsg2);
        textMsg3 = MSGDATA_AllocString(msgData, 3);
        PRINTSYS_PrintQueColor(printQue, BMP_WIN_GetBmp(scene->helpWin), 0x50, 0x0, textMsg3, font, 0x440);
        STRBUF_Delete(textMsg3);
        textMsg4 = MSGDATA_AllocString(msgData, 4);
        PRINTSYS_PrintQueColor(printQue, BMP_WIN_GetBmp(scene->helpWin), 0x50, 0x10, textMsg4, font, 0x440);
        STRBUF_Delete(textMsg4);
        textMsg5Or9 = MSGDATA_AllocString(msgData, 5);
        PRINTSYS_PrintQueColor(printQue, BMP_WIN_GetBmp(scene->helpWin), 0x50, 0x20, textMsg5Or9, font, 0x440);
        STRBUF_Delete(textMsg5Or9);
    }
    scene->helpPending = 1;
    if (oldWin != 0) {
        BMP_WIN_Delete(oldWin);
    }
}

/* Checks for a leave request or a lone member; writes the next screen state to *out. */
int CTVT_DRAW_CheckLeave(CtvtWork *work, int *out)
{
    if (COMM_TVT_SYS_GetEndRequested(work) == 1) {
        int peerState = CTVT_COMM_GetNetMode(work, COMM_TVT_SYS_GetComm(work));

        *out = (peerState == 5) ? 9 : 6;
        return 1;
    }
    if (COMM_TVT_SYS_GetMemberCount(work) <= 1) {
        *out = 0xd;
        return 1;
    }
    return 0;
}

void CTVT_DRAW_ShowMessage(CtvtWork *work, CtvtDrawScene *scene, int msgId)
{
    u32 font = COMM_TVT_SYS_GetFont(work);
    struct MsgData *msgData = COMM_TVT_SYS_GetMsgData(work);
    struct PrintQue *printQue = COMM_TVT_SYS_GetPrintQue(work);
    struct StrBuf *text;
    if (scene->messageWin != 0) BMP_WIN_Delete(scene->messageWin);
    scene->messageWin = BMP_WIN_Create(0, 1, scene->panelTarget == 0 ? 4 : 1, 30, 4, 10, 1);
    PRINTSYS_QUE_Clear(printQue);
    BMP_Clear(BMP_WIN_GetBmp(scene->messageWin), 15);
    text = MSGDATA_AllocString(msgData, msgId);
    PRINTSYS_PrintQueColor(printQue, BMP_WIN_GetBmp(scene->messageWin), 0, 0, text, font, 1088);
    STRBUF_Delete(text);
    BMP_WIN_TransferChars(scene->messageWin);
    BMP_WIN_MakeScreen(scene->messageWin);
    BMP_MENUWORK_DrawWindow(scene->messageWin, 1, 512, 9);
    scene->messagePending = 1;
}

/* Closes the pen size and stamp pickers and hides their sprites. */
void CTVT_DRAW_ClosePickers(CtvtWork *work, CtvtDrawScene *scene)
{
    scene->sizePickerOpen = 0;
    scene->stampPickerOpen = 0;
    CLACT_RestartActorAnim(scene->penPicker);
    CLACT_RestartActorAnim(scene->stampPicker);
    CLACT_RestartActorAnim(scene->pickMarker);
    CLACT_SetActorAnimFrame(scene->penPicker, 0);
    CLACT_SetActorAnimFrame(scene->stampPicker, 0);
    CLACT_SetActorAutoAnim(scene->penPicker, 0);
    CLACT_SetActorAutoAnim(scene->stampPicker, 0);
    CLACT_SetActorDrawEnable(scene->penPicker, 0);
    CLACT_SetActorDrawEnable(scene->stampPicker, 0);
    CLACT_SetActorDrawEnable(scene->pickMarker, 0);
    CLACT_SetActorDrawEnable(scene->cursor, 0);
}

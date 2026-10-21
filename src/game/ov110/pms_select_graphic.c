/*
 * file:     pms_select_graphic.c
 * unit:     yes
 * function: PMS_SELECT_GRAPHIC_ProcInit, PMS_SELECT_GRAPHIC_ProcExit, PMS_SELECT_GRAPHIC_IsPrintDone, PMS_SELECT_GRAPHIC_SetResult, PMS_SELECT_GRAPHIC_ProcMain, PMS_SELECT_GRAPHIC_Setup, PMS_SELECT_GRAPHIC_Teardown, PMS_SELECT_GRAPHIC_CreateBg, PMS_SELECT_GRAPHIC_DeleteBg, PMS_SELECT_GRAPHIC_ColorRowBg, PMS_SELECT_GRAPHIC_BlendBlinkColors, PMS_SELECT_GRAPHIC_UpdateBgBlink, PMS_SELECT_GRAPHIC_ResetBgBlink, PMS_SELECT_GRAPHIC_ColorTitleBg, PMS_SELECT_GRAPHIC_CreateTouchBar, PMS_SELECT_GRAPHIC_DeleteTouchBar, PMS_SELECT_GRAPHIC_UpdateTouchBar, PMS_SELECT_GRAPHIC_OpenRowMenu, PMS_SELECT_GRAPHIC_CloseRowMenu, PMS_SELECT_GRAPHIC_UpdateRowMenu, PMS_SELECT_GRAPHIC_CreateRows, PMS_SELECT_GRAPHIC_DeleteRows, PMS_SELECT_GRAPHIC_UpdateDraw, PMS_SELECT_GRAPHIC_RedrawRows, PMS_SELECT_GRAPHIC_RedrawRowsAfterInput, PMS_SELECT_GRAPHIC_DrawRows, PMS_SELECT_GRAPHIC_PlaceScrollThumb, PMS_SELECT_GRAPHIC_StartThumbDrag, PMS_SELECT_GRAPHIC_GetThumbRow, PMS_SELECT_GRAPHIC_UpdateThumbDrag, PMS_SELECT_GRAPHIC_UpdateInput, PMS_SELECT_GRAPHIC_FlushRowWindows, PMS_SELECT_GRAPHIC_FlushRowWindow, PMS_SELECT_GRAPHIC_DrawNewRow, PMS_SELECT_GRAPHIC_DrawSavedRow, PMS_SELECT_GRAPHIC_GetTouchedRow, PMS_SELECT_GRAPHIC_ShowTouchBar, PMS_SELECT_GRAPHIC_StepList, PMS_SELECT_GRAPHIC_HideTouchBar, PMS_SELECT_GRAPHIC_StepOpenRowMenu, PMS_SELECT_GRAPHIC_StepRowMenu, PMS_SELECT_GRAPHIC_StepCloseRowMenu, PMS_SELECT_GRAPHIC_StepOpenEditScreen, PMS_SELECT_GRAPHIC_StepCloseEditScreen, PMS_SELECT_GRAPHIC_CreateScene, PMS_SELECT_GRAPHIC_DeleteScene, PMS_SELECT_GRAPHIC_UpdateScene, PMS_SELECT_GRAPHIC_GetSceneActorUnit, PMS_SELECT_GRAPHIC_SceneTask, PMS_SELECT_GRAPHIC_InitSceneBgs, PMS_SELECT_GRAPHIC_ExitSceneBgs, PMS_SELECT_GRAPHIC_UpdateSceneNothing, PMS_SELECT_GRAPHIC_TransferSceneBgs, PMS_SELECT_GRAPHIC_InitSceneActors, PMS_SELECT_GRAPHIC_ExitSceneActors, PMS_SELECT_GRAPHIC_DrawSceneActors, PMS_SELECT_GRAPHIC_VBlankSceneActors, PMS_SELECT_GRAPHIC_ReadPointer
 * address:  0x021C0134
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from pms_input.c, pmsiv_wordwin.c, pms_select_graphic.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   GF_OVERLAY_Load 0x02034AC4 arm
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   GFL_NET_RefreshWmIconAtTopRight 0x0203D34C arm
 *   KEY_GetTrg 0x020362DC arm
 *   KEY_GetRepeat 0x0203633C arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   GF_OVERLAY_Unload 0x02034A5C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   PMSI_PARAM_GetSentenceType 0x0202452C thumb
 *   PROCSYS_FreeProcWork 0x020315D4 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   GXx_SetMasterBrightness_ 0x0207D534 arm
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   STRBUF_Delete 0x02045808 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   GF_FONT_Delete  0x0201D83C  thumb  arm9
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb  arm9
 *   PRINTSYS_QUE_Clear  0x0201C6EC  thumb  arm9
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_GetActorDrawEnable 0x0204B3F4 arm
 *   CLACT_SetActorBgPriority 0x0204B84C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   TOUCHPANEL_GetPointCont 0x02035CB8 arm
 *   PMSI_PARAM_IsComplete 0x02024464 thumb
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   ov067_id 0x00000043 data a1
 *   PMS_WORD_GetSaveData 0x02024988 thumb
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   PROCSYS_Create 0x02031324 arm
 *   PMS_SELECT_GRAPHIC_Setup 0x021C0490 thumb ov110
 *   PMS_SELECT_GRAPHIC_Teardown 0x021C05B0 thumb ov110
 *   PROCSYS_Delete 0x0203133C arm
 *   PRINTSYS_QUE_IsFinished 0x0201C6B4 thumb
 *   PMS_DRAW_IsPrintEnd 0x0202DC98 thumb
 *   PMS_SELECT_GRAPHIC_SetResult 0x021C0250 thumb ov110
 *   PMS_SELECT_GRAPHIC_IsPrintDone 0x021C022C thumb ov110
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   TCB_DeleteTask 0x02030EAC arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   CLACT_DrawSystem 0x0204A600 arm
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   BG_SYS_Update 0x020419E4 arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   BG_SYS_ClearGraphicsMemory 0x0204335C arm
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   ARC_UTIL_UploadBgPaletteFromHandle 0x020498F4 arm
 *   ARC_UTIL_UploadBgCharFromHandle 0x02049658 arm
 *   ARC_UTIL_UploadPaletteFromHandle 0x02049BDC arm
 *   NNS_GfdRegisterNewVramTransferTask 0x02061CA4 arm
 *   BG_SYS_FillTileMap 0x020413B0 arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   BG_SYS_MarkTileDirty 0x02041B6C arm
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   GFL_USE_AddMainTask 0x020056A0 thumb
 *   ARC_UTIL_UploadPaletteFromHandleWhole 0x02049B68 arm
 *   ARC_UTIL_UploadPaletteFromArchiveWhole 0x02049B40 arm
 *   FX_SinCosTable_ 0x020A1B38 data
 *   APP_TASKMENU_RES_Create  0x02027F60  thumb  arm9
 *   APP_TASKMENU_RES_Delete  0x02027FD8  thumb  arm9
 *   PROCSYS_Main 0x02031330 arm
 *   PMS_WORD_GetSaveEntry 0x02024910 thumb
 *   FADE_Start 0x0204E720 arm
 *   FADE_IsActive 0x0204E804 arm
 *   UI_GetInputMode 0x020355C4 arm
 *   UI_SCENE_LoadActorGfx 0x021B6208 thumb ov067
 *   UI_SCENE_CreateActor 0x021B629C thumb ov067
 *   UI_SCENE_FreeActorGfx 0x021B6284 thumb ov067
 *   UI_SetInputMode 0x020355D8 arm
 *   ARC_UTIL_RegisterObjCharFromHandle 0x02049740 arm
 *   ARC_UTIL_UploadBgPaletteAddFromHandle 0x02049990 arm
 *   ARC_UTIL_LoadPaletteDataFromHandle 0x02049EF4 arm
 *   BG_SYS_FreeTileRun 0x0203FB44 arm
 *   BG_SYS_DrawTileEx 0x020410D0 arm
 *   gPmsSelectGraphicBlinkColors 0x021C39E0 data a4
 *   TOUCHBAR_Create 0x021B62E0 thumb ov067
 *   TOUCHBAR_SetButtonBgPriority 0x021B6588 thumb ov067
 *   gPmsSelectGraphicScrollBarButton 0x021C39F8 data a4
 *   TOUCHBAR_Delete  0x021B639C  thumb  ov067
 *   TOUCHBAR_Update  0x021B63D0  thumb  ov067
 *   APP_TASKMENU_OpenMenu 0x02027778 thumb
 *   gPmsSelectGraphicMenuTextIds 0x021C3C94 data ov110
 *   PMS_DRAW_Delete 0x0202DC08 thumb
 *   PMS_DRAW_Main 0x0202DBC4 thumb
 *   BG_SYS_ClearLayerEx 0x02041570 arm
 *   PMS_DRAW_IsActive 0x0202DCC4 thumb
 *   PMS_DRAW_Clear 0x0202DC9C thumb
 *   CLACT_GetActorPosAxis 0x0204B560 arm
 *   CLACT_SetActorPosAxis 0x0204B550 arm
 *   PMS_DRAW_SetPrintColor 0x0202DE64 thumb
 *   PMS_DRAW_SetNullColorPalette 0x0202DE5C thumb
 *   PMS_DRAW_Print 0x0202DC48 thumb
 *   TOUCHBAR_SetAllButtonsVisible 0x021B64D0 thumb ov067
 *   TOUCHBAR_GetPressedButtonIdIfPressing 0x021B6470 thumb ov067
 *   TOUCHBAR_GetPressedButtonIdIfDone 0x021B6448 thumb ov067
 *   BRIGHTNESS_Set 0x02023F60 thumb
 *   APP_TASKMENU_IsFinish 0x020279E8 thumb
 *   APP_TASKMENU_GetCursorPos 0x02027A04 thumb
 *   PMSI_PARAM_Create 0x02024044 thumb
 *   PMSI_PARAM_SetSentence 0x02024108 thumb
 *   PROCSYS_Push 0x02031348 arm
 *   gPmsSelectProcData 0x021C39B8 data a4
 *   PMSI_PARAM_CheckModified 0x02024120 thumb
 *   PMSI_PARAM_GetSentence 0x02024134 thumb
 *   PMS_WORD_SetSaveEntry 0x02024918 thumb
 *   PMSI_PARAM_Delete 0x020240FC thumb
 *   BG_SYS_SetLcdSwap 0x0204363C arm
 *   BG_SYS_ResetSubDisplay 0x0204361C arm
 *   GF_FONT_InitTextColor 0x0201DD60 thumb
 *   gPmsSelectGraphicSceneFileName 0x021C3C98 data a1
 *   gPmsSelectGraphicVramBanks 0x021C3A44 data a4
 *   PMS_SELECT_GRAPHIC_ReadPointer  0x021C1848  thumb  ov110
 *   BG_SYS_FreeSlot 0x020414AC arm
 *   gPmsSelectGraphicDispConfig 0x021C3A18 data a4
 *   gPmsSelectGraphicBgRows 0x021C3A74 data a4
 *   CLACT_SetUnitDefaultRenderer 0x0204B270 arm
 *   gPmsSelectGraphicActorInit 0x021C3A28 data a4
 *   PMS_DRAW_Create  0x0202DB0C  thumb  arm9
 *   APP_TASKMENU_CloseMenu  0x02027858  thumb  arm9
 *   APP_TASKMENU_UpdateMenu  0x02027974  thumb  arm9
 *   _u32_div_f                   0x0209C2B0  arm
 */
#include "../types.h"
#include "../sdk_ioreg.h"

#include "../arm9/pms_types.h"
#include "../ov067/ui_scene_types.h"
#include "../ov067/touchbar_types.h"
#include "pms_select_graphic_types.h"

typedef char PmsSelectGraphic_size_check[sizeof(struct PmsSelectGraphic) == 0xB0 ? 1 : -1];
typedef char PmsSelectGraphicBg_size_check[sizeof(struct PmsSelectGraphicBg) == 0x2C ? 1 : -1];

struct Proc;

#define PMS_SELECT_GRAPHIC_HEAP_ID 81

#define REG_MASTER_BRIGHT_A_ADDR REG_MASTER_BRIGHT_ADDR
#define REG_MASTER_BRIGHT_B_ADDR REG_DB_MASTER_BRIGHT_ADDR
#define REG_BLDCNT_A_ADDR REG_BLDCNT_ADDR
#define REG_BLDCNT_B_ADDR REG_DB_BLDCNT_ADDR
#define REG_DISPCNT_A_ADDR REG_DISPCNT_ADDR
#define REG_DISPCNT_B_ADDR REG_DB_DISPCNT_ADDR
#define DISPCNT_WINDOW_ENABLE_MASK 0xe000

/* State numbers of the main step. */
#define PMS_SELECT_GRAPHIC_STATE_FINISHED 16

#include "../arm9/procsys.h"
#include "../arm9/key.h"
extern char ov067_id[];
#include "../arm9/gfl_heap_wrap.h"
#include "../arm9/gx.h"
#include "../arm9/mi_memory.h"
#include "../arm9/gf_overlay.h"
#include "../arm9/gfl_heap.h"
#include "../arm9/gfl_use.h"
#include "../arm9/net.h"
struct TcbTask;
struct TcbTask;
#include "../arm9/tcb_list.h"
struct BmpWin;

                            
#include "../arm9/bmp_win.h"
struct Bmp;
struct Bmp;
typedef short s16_p07;
#include "../arm9/bmp.h"
struct GfFont;
#include "../arm9/gf_font.h"
struct MsgBank;
#include "../arm9/msgdata.h"
struct Strbuf;
#include "../arm9/strbuf.h"
struct PrintQueue;
#include "../arm9/printsys.h"
struct DispVramCfg;
struct SysInit;

/* Actors and the display. */
#include "../arm9/clact.h"
#include "../arm9/bg_sys.h"
struct DispVram;
#include "../arm9/brightness.h"
#include "../arm9/fade.h"
#include "../arm9/ui.h"
#include "../arm9/touchpanel.h"
extern short FX_SinCosTable_[];

/* Archive and palette helpers. */
#include "../arm9/arc_tool.h"
#include "../arm9/arc_util.h"
#include "../arm9/nns_gfd_vram_transfer.h"

/* Overlay 67: scene actors and touch bar. */
#include "../ov067/ui_scene.h"
#ifdef __MWERKS__
#define TOUCHBAR_Create TOUCHBAR_Create_hdr
#endif
#include "../ov067/touchbar.h"
#ifdef __MWERKS__
#undef TOUCHBAR_Create
TouchBar * TOUCHBAR_Create(TouchBarParams *, int);
#endif
struct GFont;
struct TaskMenuRes;

                                                      
#include "../arm9/app_taskmenu.h"
struct TaskMenuInitWork;
struct TaskMenuWork;
struct PmsDraw;
#include "../arm9/pms_draw.h"
struct BeaconDetailGraQuad;
struct WinPanel020071CCCtrl;

/* Easy chat data. */
#include "../arm9/pms_word.h"
struct PmsWord;
#include "../arm9/pmsi_param.h"
struct PmsiParam;

extern void *PMS_SELECT_GRAPHIC_ReadPointer(void **p);

extern unsigned short gPmsSelectGraphicBlinkColors[];
extern const TouchBarButtonDef gPmsSelectGraphicScrollBarButton;
extern const u8 gPmsSelectGraphicMenuTextIds[];
extern const unsigned gPmsSelectProcData[];
extern const char gPmsSelectGraphicSceneFileName[];
extern const unsigned gPmsSelectGraphicVramBanks[];
extern const unsigned gPmsSelectGraphicDispConfig[];
extern const struct PmsSelectGraphicBgRow gPmsSelectGraphicBgRows[];
extern const unsigned gPmsSelectGraphicActorInit[];

int PMS_SELECT_GRAPHIC_ProcMain(void *unused, int *state, void *unused2, struct PmsSelectGraphic *p);
void PMS_SELECT_GRAPHIC_Setup(struct PmsSelectGraphic *p);
void PMS_SELECT_GRAPHIC_Teardown(struct PmsSelectGraphic *p);
void PMS_SELECT_GRAPHIC_CreateBg(struct PmsSelectGraphicBg *bg, u16 heap, u32 font, void *print, void *bank);
void PMS_SELECT_GRAPHIC_DeleteBg(struct PmsSelectGraphicBg *bg);
void PMS_SELECT_GRAPHIC_ColorRowBg(struct PmsSelectGraphicBg *bg, u8 row, u32 pal, int flag);
void PMS_SELECT_GRAPHIC_BlendBlinkColors(u16 *angle, u16 *out, const struct PmsSelectGraphicColorRec *recs, u8 count);
void PMS_SELECT_GRAPHIC_UpdateBgBlink(struct PmsSelectGraphicBg *bg);
void PMS_SELECT_GRAPHIC_ResetBgBlink(struct PmsSelectGraphicBg *bg);
void PMS_SELECT_GRAPHIC_ColorTitleBg(struct PmsSelectGraphicBg *bg, int pal);
TouchBar *PMS_SELECT_GRAPHIC_CreateTouchBar(int unused, void *actorUnit, int heap);
void PMS_SELECT_GRAPHIC_DeleteTouchBar(struct PmsSelectGraphic *p);
void PMS_SELECT_GRAPHIC_UpdateTouchBar(TouchBar *touchBar);
void *PMS_SELECT_GRAPHIC_OpenRowMenu(void *res, void *bank, u16 heapId);
void PMS_SELECT_GRAPHIC_CloseRowMenu(void *menu);
void PMS_SELECT_GRAPHIC_UpdateRowMenu(void *menu);
void PMS_SELECT_GRAPHIC_CreateRows(struct PmsSelectGraphic *p);
void PMS_SELECT_GRAPHIC_DeleteRows(struct PmsSelectGraphic *p);
void PMS_SELECT_GRAPHIC_UpdateDraw(struct PmsSelectGraphic *p);
void PMS_SELECT_GRAPHIC_RedrawRows(struct PmsSelectGraphic *p);
void PMS_SELECT_GRAPHIC_RedrawRowsAfterInput(struct PmsSelectGraphic *p);
void PMS_SELECT_GRAPHIC_DrawRows(struct PmsSelectGraphic *p, int flag);
void PMS_SELECT_GRAPHIC_PlaceScrollThumb(struct PmsSelectGraphic *p, int force);
int PMS_SELECT_GRAPHIC_StartThumbDrag(struct PmsSelectGraphic *p);
void PMS_SELECT_GRAPHIC_GetThumbRow(unsigned y, int count, short *out, short *pos);
int PMS_SELECT_GRAPHIC_UpdateThumbDrag(struct PmsSelectGraphic *p);
int PMS_SELECT_GRAPHIC_UpdateInput(struct PmsSelectGraphic *p);
void PMS_SELECT_GRAPHIC_FlushRowWindows(struct PmsSelectGraphic *p);
int PMS_SELECT_GRAPHIC_FlushRowWindow(void *printQueue, void *window, int *pending);
void PMS_SELECT_GRAPHIC_DrawNewRow(struct PmsSelectGraphic *p, u8 row, int unused, int flag);
void PMS_SELECT_GRAPHIC_DrawSavedRow(struct PmsSelectGraphic *p, u8 row, u8 which, int flag);
int PMS_SELECT_GRAPHIC_GetTouchedRow(void);
int PMS_SELECT_GRAPHIC_ShowTouchBar(void *unused, struct PmsSelectGraphic *p);
int PMS_SELECT_GRAPHIC_StepList(void *unused, struct PmsSelectGraphic *p);
int PMS_SELECT_GRAPHIC_HideTouchBar(void *unused, struct PmsSelectGraphic *p);
int PMS_SELECT_GRAPHIC_StepOpenRowMenu(void *unused, struct PmsSelectGraphic *p);
int PMS_SELECT_GRAPHIC_StepRowMenu(void *unused, struct PmsSelectGraphic *p);
int PMS_SELECT_GRAPHIC_StepCloseRowMenu(void *unused, struct PmsSelectGraphic *p);
int PMS_SELECT_GRAPHIC_StepOpenEditScreen(int *step, struct PmsSelectGraphic *p);
int PMS_SELECT_GRAPHIC_StepCloseEditScreen(int *step, struct PmsSelectGraphic *p);
struct PmsSelectGraphicScene *PMS_SELECT_GRAPHIC_CreateScene(unsigned arg, u16 heap);
void PMS_SELECT_GRAPHIC_DeleteScene(struct PmsSelectGraphicScene *scene);
void PMS_SELECT_GRAPHIC_UpdateScene(struct PmsSelectGraphicScene *scene);
void *PMS_SELECT_GRAPHIC_GetSceneActorUnit(struct PmsSelectGraphicScene *scene);
void PMS_SELECT_GRAPHIC_SceneTask(int taskId, void *work);
void PMS_SELECT_GRAPHIC_InitSceneBgs(struct PmsSelectGraphicScene *scene, u16 heap);
void PMS_SELECT_GRAPHIC_ExitSceneBgs(struct PmsSelectGraphicScene *scene);
void PMS_SELECT_GRAPHIC_UpdateSceneNothing(struct PmsSelectGraphicScene *scene);
void PMS_SELECT_GRAPHIC_TransferSceneBgs(struct PmsSelectGraphicScene *scene);
void PMS_SELECT_GRAPHIC_InitSceneActors(void **unitOut, unsigned vram, unsigned heap);
void PMS_SELECT_GRAPHIC_ExitSceneActors(void **unit);
void PMS_SELECT_GRAPHIC_DrawSceneActors(void *unit);
void PMS_SELECT_GRAPHIC_VBlankSceneActors(void *unit);

/* Process init of the graphic selection screen: heap, work object, font, messages. */
int PMS_SELECT_GRAPHIC_ProcInit(struct Proc *owner, int unused, struct PmsSelectGraphicArgs *args)
{
    struct PmsSelectGraphic *p;
    GF_OVERLAY_Load((uptr)ov067_id);
    GXx_SetMasterBrightness_((void *)REG_MASTER_BRIGHT_A_ADDR, -16);
    GXx_SetMasterBrightness_((void *)REG_MASTER_BRIGHT_B_ADDR, -16);
    GFL_HEAP_CreateChildHeap(1, PMS_SELECT_GRAPHIC_HEAP_ID, 0x1c000);
    p = PROCSYS_AllocProcWork(owner, sizeof(struct PmsSelectGraphic), PMS_SELECT_GRAPHIC_HEAP_ID);
    MI_CpuFill8(p, 0, sizeof(struct PmsSelectGraphic));
    p->heapId = PMS_SELECT_GRAPHIC_HEAP_ID;
    p->pmsSystem = args->pmsSystem;
    p->saveData = PMS_WORD_GetSaveData(args->pmsSystem);
    p->args = args;
    p->font = GF_FONT_Create(23, 0, 0, 0, p->heapId);
    p->msgBank = MSGDATA_CreateFromArchive(0, 2, 146, p->heapId);
    p->printQueue = (void *)PRINTSYS_QUE_Create((u32)p->heapId);
    p->procList = PROCSYS_Create(p->heapId);
    p->prevSelected = 255;
    p->selected = 255;
    PMS_SELECT_GRAPHIC_Setup(p);
    return 1;
}

/* Process exit of the graphic selection screen. */
int PMS_SELECT_GRAPHIC_ProcExit(struct Proc *proc, int unused, int unused2, struct PmsSelectGraphic *p)
{
    PMS_SELECT_GRAPHIC_Teardown(p);
    PROCSYS_Delete(p->procList);
    PRINTSYS_QUE_Clear(p->printQueue);
    PRINTSYS_QUE_Delete(p->printQueue);
    MSGDATA_Delete(p->msgBank);
    GF_FONT_Delete(p->font);
    PROCSYS_FreeProcWork(proc);
    GFL_HEAP_DeleteChecked(PMS_SELECT_GRAPHIC_HEAP_ID);
    GF_OVERLAY_Unload((sptr)ov067_id);
    return 1;
}

/* Whether the print queue and the print of the screen are finished. */
int PMS_SELECT_GRAPHIC_IsPrintDone(struct PmsSelectGraphic *p)
{
    if (PRINTSYS_QUE_IsFinished(p->printQueue) && PMS_DRAW_IsPrintEnd(p->pmsDraw)) return 1;
    return 0;
}

/* Sets the next state of the main step and restarts its sub state. */
void PMS_SELECT_GRAPHIC_SetResult(int *state, struct PmsSelectGraphic *p, int next)
{
    *state = next;
    p->subState = 0;
}

/*
 * ABI: 02031330 tail-forwards the full-word result and object argument of matched 020313EC.
 */
int PMS_SELECT_GRAPHIC_ProcMain(void *unused, int *state, void *unused2, struct PmsSelectGraphic *p)
{
    u32 running;
    void *window;
    running = PROCSYS_Main(p->procList);
    if (running == 1) return 0;
    switch (*state) {
    case 0:
        if (!PMSI_PARAM_IsComplete(PMS_WORD_GetSaveEntry(p->saveData, 0), p->heapId)) {
            p->selected = 0;
            PMS_SELECT_GRAPHIC_SetResult(state, p, 13);
        } else PMS_SELECT_GRAPHIC_SetResult(state, p, 1);
        break;
    case 1:
        if (PMS_SELECT_GRAPHIC_ShowTouchBar(&p->subState, p)) PMS_SELECT_GRAPHIC_SetResult(state, p, 2);
        break;
    case 2:
        FADE_Start(3, 16, 0, 0);
        PMS_SELECT_GRAPHIC_SetResult(state, p, 3);
        break;
    case 3:
        if (!FADE_IsActive()) PMS_SELECT_GRAPHIC_SetResult(state, p, 4);
        break;
    case 4:
        if (PMS_SELECT_GRAPHIC_IsPrintDone(p) && PMS_SELECT_GRAPHIC_StepList(&p->subState, p))
            PMS_SELECT_GRAPHIC_SetResult(state, p, p->nextState);
        break;
    case 5:
        FADE_Start(3, 0, 16, 0);
        PMS_SELECT_GRAPHIC_SetResult(state, p, 6);
        break;
    case 6:
        if (!FADE_IsActive()) PMS_SELECT_GRAPHIC_SetResult(state, p, 7);
        break;
    case 7:
        if (PMS_SELECT_GRAPHIC_HideTouchBar(&p->subState, p)) PMS_SELECT_GRAPHIC_SetResult(state, p, PMS_SELECT_GRAPHIC_STATE_FINISHED);
        break;
    case 8:
        if (PMS_SELECT_GRAPHIC_StepOpenRowMenu(&p->subState, p)) PMS_SELECT_GRAPHIC_SetResult(state, p, 9);
        break;
    case 9:
        if (PMS_SELECT_GRAPHIC_StepRowMenu(&p->subState, p)) PMS_SELECT_GRAPHIC_SetResult(state, p, 10);
        break;
    case 10:
        if (PMS_SELECT_GRAPHIC_StepCloseRowMenu(&p->subState, p)) PMS_SELECT_GRAPHIC_SetResult(state, p, p->nextState);
        break;
    case 11:
        if (PMS_SELECT_GRAPHIC_IsPrintDone(p)) {
            FADE_Start(3, 0, 16, 0);
            PMS_SELECT_GRAPHIC_SetResult(state, p, 12);
        }
        break;
    case 12:
        if (!FADE_IsActive()) PMS_SELECT_GRAPHIC_SetResult(state, p, 13);
        break;
    case 13:
        PMS_SELECT_GRAPHIC_Teardown(p);
        GF_OVERLAY_Unload((sptr)ov067_id);
        PMS_SELECT_GRAPHIC_SetResult(state, p, 14);
        return 0;
    case 14:
        if (PMS_SELECT_GRAPHIC_StepOpenEditScreen(&p->subState, p)) PMS_SELECT_GRAPHIC_SetResult(state, p, 15);
        return 0;
    case 15:
        if (running != 1 && PMS_SELECT_GRAPHIC_StepCloseEditScreen(&p->subState, p)) {
            GF_OVERLAY_Load((uptr)ov067_id);
            PMS_SELECT_GRAPHIC_Setup(p);
            PMS_SELECT_GRAPHIC_SetResult(state, p, 1);
        }
        return 0;
    case PMS_SELECT_GRAPHIC_STATE_FINISHED:
        return 1;
    }
    PRINTSYS_QUE_Main(p->printQueue);
    if (p->bg.titlePending) {
        if (!PRINTSYS_QUE_IsExistTarget(p->printQueue, BMP_WIN_GetBmp(p->bg.titleWindow))) {
            window = p->bg.titleWindow;
            BMP_WIN_TransferChars(window);
            BMP_WIN_MakeScreen(window);
            BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer(window));
            p->bg.titlePending = 0;
        }
    }
    PMS_SELECT_GRAPHIC_FlushRowWindows(p);
    PMS_SELECT_GRAPHIC_UpdateDraw(p);
    PMS_SELECT_GRAPHIC_UpdateScene(p->scene);
    return 0;
}

/*
 * lever: test source byte +95 after copying to +94; bitfield clear and ordered desc stores.
 * prototype: 021C1718 tail-forwards to the returned first-word accessor 021C1848.
 */
void PMS_SELECT_GRAPHIC_Setup(struct PmsSelectGraphic *p)
{
    int enabled;
    void *actorUnit;
    ActorGfxDesc desc;
    p->touchScrolling = 0;
    p->touchBarActive = 1;
    enabled = 1;
    if (UI_GetInputMode() != 1) enabled = 0;
    p->isTouch = enabled;
    p->prevSelected = p->selected;
    if (p->selected == 255) {
        if (enabled) p->topRow = 0;
        else { p->selected = 0; p->topRow = 0; }
    } else {
        if (enabled) p->selected = 255;
    }
    p->scene = PMS_SELECT_GRAPHIC_CreateScene(0, p->heapId);
    actorUnit = PMS_SELECT_GRAPHIC_GetSceneActorUnit(p->scene);
    desc.arcId = 43; desc.charId = 7; desc.plttId = 13; desc.cellId = 35; desc.animId = 41;
    desc.screen = 0; desc.flags = 0;
    desc.plttSlot = 0; desc.charBase = 0; desc.charSize = 5;
    UI_SCENE_LoadActorGfx(&p->actorGfx, &desc, actorUnit, p->heapId);
    p->scrollThumb = UI_SCENE_CreateActor(&p->actorGfx, actorUnit, 240, 16, 16, p->heapId);
    CLACT_SetActorBgPriority(p->scrollThumb, 1);
    CLACT_SetActorAutoAnim(p->scrollThumb, 1);
    PMS_SELECT_GRAPHIC_CreateBg(&p->bg, p->heapId, (uptr)p->font, p->printQueue, p->msgBank);
    PMS_SELECT_GRAPHIC_ResetBgBlink(&p->bg);
    p->bg.decideFrames = 0;
    p->bg.decided = 0;
    p->touchBar = PMS_SELECT_GRAPHIC_CreateTouchBar((sptr)p, PMS_SELECT_GRAPHIC_GetSceneActorUnit(p->scene), p->heapId);
    p->taskMenuRes = APP_TASKMENU_RES_Create(0, 12, (struct GFont *)p->font, (struct PrintQueue *)p->printQueue, p->heapId);
    PMS_SELECT_GRAPHIC_CreateRows(p);
    GFL_NET_RefreshWmIconAtTopRight(1, p->heapId);
}

static inline u8 ClearRowPending(struct PmsSelectGraphic *p, u8 i)
{
    u8 zero;
    zero = i;
    for (; i < PMS_SELECT_GRAPHIC_VISIBLE_ROWS; i++) p->rowPending[i] = zero;
    return zero;
}

void PMS_SELECT_GRAPHIC_Teardown(struct PmsSelectGraphic *p)
{
    u8 zero;
    PRINTSYS_QUE_Clear(p->printQueue);
    zero = ClearRowPending(p, 0);
    p->bg.titlePending = zero;
    UI_SCENE_FreeActorGfx(&p->actorGfx);
    PMS_SELECT_GRAPHIC_DeleteTouchBar(p);
    APP_TASKMENU_RES_Delete(p->taskMenuRes);
    PMS_SELECT_GRAPHIC_DeleteRows(p);
    PMS_SELECT_GRAPHIC_DeleteBg(&p->bg);
    PMS_SELECT_GRAPHIC_DeleteScene(p->scene);
    if (p->isTouch) zero = 1;
    UI_SetInputMode(zero);
}

/*
 * Own callee bodies fix arity and full word payloads; caller0490 loads heap
 *   with ldrh. The original narrows only 49990's fifth argument to u16.
 * No local arrays; palette halfwords initialized before queued two-byte reads.
 * Callback/context pointers retain their full32 bits.
 */
void PMS_SELECT_GRAPHIC_CreateBg(struct PmsSelectGraphicBg *bg, u16 heap, u32 font, void *print, void *bank)
{
    void *h;
    void *str;
    h = ARC_TOOL_CreateHandle((unsigned int)43, heap);
    ARC_UTIL_UploadPaletteFromHandleWhole(h, 0, 0, 0, 288, heap);
    ARC_UTIL_UploadPaletteFromHandleWhole(h, 0, 4, 0, 256, heap);
    ARC_UTIL_UploadPaletteFromArchiveWhole(23, 5, 0, 288, 32, heap);
    bg->palette[0] = 0x7fff;
    NNS_GfdRegisterNewVramTransferTask((void *)15, 316, (uptr)&bg->palette[0], 2);
    bg->palette[1] = 0x7fff;
    NNS_GfdRegisterNewVramTransferTask((void *)15, 314, (uptr)&bg->palette[1], 2);
    ARC_UTIL_UploadBgCharFromHandle(h, 10, 4, 0, 0, 0, heap);
    ARC_UTIL_UploadBgPaletteFromHandle(h, 21, 4, 0, 0, 0, heap);
    bg->tileRange = ARC_UTIL_RegisterObjCharFromHandle(h, 10, 3, 0, 0, heap);
    ARC_UTIL_UploadBgPaletteAddFromHandle(h, 22, 3, 0, (u16)bg->tileRange, 0, 0, heap);
    ARC_UTIL_UploadBgCharFromHandle(h, 11, 2, 0, 0, 0, heap);
    bg->screenMem = ARC_UTIL_LoadPaletteDataFromHandle(h, 23, 0, (void **)&bg->screen, heap);
    ARC_UTIL_UploadPaletteFromHandle(h, 4, 4, 128, 256, 32, heap);
    bg->palette[2] = 0x294b;
    NNS_GfdRegisterNewVramTransferTask((void *)31, 284, (uptr)&bg->palette[2], 2);
    bg->palette[3] = 0x5694;
    NNS_GfdRegisterNewVramTransferTask((void *)31, 286, (uptr)&bg->palette[3], 2);
    ARC_UTIL_UploadBgCharFromHandle(h, 18, 5, 0, 0, 0, heap);
    ARC_UTIL_UploadBgPaletteFromHandle(h, 24, 5, 0, 0, 0, heap);
    BG_SYS_FillTileMap(5, 0, 0, 32, 32, 8);
    bg->titleWindow = BMP_WIN_Create(5, 3, 5, 26, 7, 8, 1);
    BMP_Clear(BMP_WIN_GetBmp(bg->titleWindow), 7);
    str = MSGDATA_AllocString(bank, 21);
    PRINTSYS_PrintQueColor(print, BMP_WIN_GetBmp(bg->titleWindow), 2, 4, str, (struct GfFont *)font, 0x39e7);
    bg->titlePending = 1;
    STRBUF_Delete(str);
    ARC_TOOL_DeleteHandle(h);
}

void PMS_SELECT_GRAPHIC_DeleteBg(struct PmsSelectGraphicBg *bg)
{
    BMP_WIN_Delete(bg->titleWindow);
    BG_SYS_FreeTileRun(3, (u16)bg->tileRange, (u16)(bg->tileRange >> 16));
    GFL_HEAP_Free(bg->screenMem);
}

/* Recolours the row background tiles of one row (palette pal + 2) and uploads them. */
void PMS_SELECT_GRAPHIC_ColorRowBg(struct PmsSelectGraphicBg *bg, u8 row, u32 pal, int flag)
{
    int i;
    int n;
    u16 *hdr = bg->screen;
    u16 *data;
    u32 w;
    u32 h;
    w = (u32)hdr[0] >> 3;
    h = (u32)hdr[1] >> 3;
    data = hdr + 6;
    if (flag)
        pal = 5;
    n = w * h;
    for (i = 0; i < n; i++)
    {
        u32 v = data[i] & 0xFFF;
        data[i] = v + ((pal + 2) << 12);
    }
    BG_SYS_DrawTileEx(2, 0, (u8)(row * 6 + 1), (u8)w, 6, (void *)((u8 *)bg->screen + 12), 0, 0, (u8)w, (u8)h);
    BG_SYS_MarkTileDirty(2);
}

static inline void BlendColor555(u16 *p, int n, u16 a, u16 b)
{
 u8 r,g,blue; int dr,dg,db;
 g=(a&0x3E0)>>5;
 r=a&31;
 blue=(a&0x7C00)>>10;
 db=((u8)((b&0x7C00)>>10)-blue)*n>>12;
 dr=((u8)(b&31)-r)*n>>12;
 dg=((u8)((b&0x3E0)>>5)-g)*n>>12;
 *p=(u8)(r+dr)|((u8)(g+dg)<<5)|((u8)(blue+db)<<10);
}

/*
 * lever: the RGB555 BlendColor555 is a static inline helper (u16 colour params, as ov105 IRC_RESULT_BlendPaletteEntry)
 */
void PMS_SELECT_GRAPHIC_BlendBlinkColors(u16 *angle, u16 *out, const struct PmsSelectGraphicColorRec *recs, u8 count)
{
    u8 i;
    short t;
    int a = *angle;
    if (a + 0x400 >= 0x10000)
        *angle = a - 0xFC00;
    else
        *angle = a + 0x400;
    t = (FX_SinCosTable_[(*angle >> 4) * 2 + 1] + 0x1000) / 2;
    for (i = 0; i < count; i++) {
        BlendColor555(&out[i], t, recs[i].c, recs[i].d);
        NNS_GfdRegisterNewVramTransferTask((void *)15, (recs[i].x << 5) + (recs[i].y << 1), (uptr)(&out[i]), 2);
    }
}

/* Blinks the colours of the decided row for 16 frames, then keeps the pulse going. */
void PMS_SELECT_GRAPHIC_UpdateBgBlink(struct PmsSelectGraphicBg *bg)
{
    int v;
    if (bg->decided) {
        v = 1;
        if (bg->decideFrames < 16) {
            v = (bg->decideFrames / 4) % 2;
            (bg->decideFrames)++;
        }
        if (v) bg->colorPhase = 0xfc00;
        else bg->colorPhase = 0x7c00;
    }
    PMS_SELECT_GRAPHIC_BlendBlinkColors(&bg->colorPhase, bg->blinkColors, (const struct PmsSelectGraphicColorRec *)gPmsSelectGraphicBlinkColors, 3);
}

void PMS_SELECT_GRAPHIC_ResetBgBlink(struct PmsSelectGraphicBg *bg) { bg->colorPhase = 0; }

/* Recolours the title row background (palette pal + 2) and uploads it. */
void PMS_SELECT_GRAPHIC_ColorTitleBg(struct PmsSelectGraphicBg *bg, int pal)
{
    int i = 0;
    u16 *hdr = bg->screen;
    u32 w = (u32)hdr[0] >> 3;
    u32 h = (u32)hdr[1] >> 3;
    u16 *data = hdr + 6;
    int n = w * h;
    for (; i < n; i++)
    {
        u32 v = data[i] & 0xFFF;
        data[i] = v + ((pal + 2) << 12);
    }
    BG_SYS_DrawTileEx(2, 0, 0, (u8)w, 1, (void *)((u8 *)bg->screen + 12), 0, 5, (u8)w, (u8)h);
    BG_SYS_MarkTileDirty(2);
}

TouchBar *PMS_SELECT_GRAPHIC_CreateTouchBar(int unused, void *actorUnit, int heap)
{
    TouchBarParams params = {0};
    TouchBarButtonDef def = gPmsSelectGraphicScrollBarButton;
    TouchBar *out;
    params.count = 1;
    params.bgLayer = 1;
    params.bgPlttSlot = 14;
    params.actorPlttSlot = 5;
    params.iconSet = 1;
    params.defs = &def;
    params.actorSys = actorUnit;
    out = TOUCHBAR_Create(&params, heap);
    TOUCHBAR_SetButtonBgPriority(out, 1, 1);
    return out;
}

/*
 * Resolved by the TOUCHBAR_Delete label in ov067 (thumb); cross-overlay target.
 */
void PMS_SELECT_GRAPHIC_DeleteTouchBar(struct PmsSelectGraphic *p) { TOUCHBAR_Delete(p->touchBar); }

void PMS_SELECT_GRAPHIC_UpdateTouchBar(TouchBar *touchBar) { TOUCHBAR_Update(touchBar); }

/*
 * note: closed by the u16 type of the heapId parameter (stored to the u32
 *   heapId field). The u32 parameter let the scheduler hoist the reload above the items[2].type store.
 */
void *PMS_SELECT_GRAPHIC_OpenRowMenu(void *res, void *bank, u16 heapId)
{
    struct PmsSelectGraphicMenuInit init;
    struct PmsSelectGraphicMenuItem items[3];
    u32 i;
    void *menu;
    for (i = 0; i < 3; i++) {
        items[i].text = MSGDATA_AllocString(bank, gPmsSelectGraphicMenuTextIds[i]);
        items[i].color = 0x39E3;
        items[i].type = 0;
    }
    items[2].type = 1;
    init.heapId = heapId;
    init.itemCount = 3;
    init.items = items;
    init.positionType = 1;
    init.x = 0x20;
    init.y = 0x18;
    init.width = 13;
    init.height = 3;
    menu = APP_TASKMENU_OpenMenu((struct TaskMenuInitWork *)(&init), res);
    for (i = 0; i < 3; i++)
        STRBUF_Delete(items[i].text);
    return menu;
}

void PMS_SELECT_GRAPHIC_CloseRowMenu(void *menu) { APP_TASKMENU_CloseMenu(menu); }

void PMS_SELECT_GRAPHIC_UpdateRowMenu(void *menu) { APP_TASKMENU_UpdateMenu(menu); }

/* Creates the sentence drawing object and the four row windows, counts the saved sentences. */
void PMS_SELECT_GRAPHIC_CreateRows(struct PmsSelectGraphic *p)
{
    int i;
    unsigned v;
    p->pmsDraw = PMS_DRAW_Create((uptr)PMS_SELECT_GRAPHIC_GetSceneActorUnit(p->scene), (int)0, (uptr)p->printQueue, (uptr)p->font, (int)8, (int)4, p->heapId);
    p->filledCount = 0;
    for (i = 0; i < PMS_SELECT_GRAPHIC_MAX_ENTRIES; i++) {
        if (!PMSI_PARAM_IsComplete(PMS_WORD_GetSaveEntry(p->saveData, i), (u16)p->heapId)) break;
        p->filledCount++;
    }
    v = p->filledCount;
    p->rowCount = v;
    if (v < PMS_SELECT_GRAPHIC_MAX_ENTRIES) p->rowCount++;
    CLACT_SetActorDrawEnable(p->scrollThumb, (int)(p->rowCount > 3));
    for (i = 0; i < PMS_SELECT_GRAPHIC_VISIBLE_ROWS; i++) p->rowWindows[i] = BMP_WIN_Create((int)2, (int)2, (u8)(i * 6 + 2), (int)25, (int)4, (int)9, (int)1);
    PMS_SELECT_GRAPHIC_RedrawRows(p);
    PMS_SELECT_GRAPHIC_PlaceScrollThumb(p, 1);
}

void PMS_SELECT_GRAPHIC_DeleteRows(struct PmsSelectGraphic *p)
{
    int i;
    PMS_DRAW_Delete(p->pmsDraw);
    for (i = 0; i < PMS_SELECT_GRAPHIC_VISIBLE_ROWS; i++) BMP_WIN_Delete(p->rowWindows[i]);
}

void PMS_SELECT_GRAPHIC_UpdateDraw(struct PmsSelectGraphic *p) { PMS_DRAW_Main(p->pmsDraw); }

void PMS_SELECT_GRAPHIC_RedrawRows(struct PmsSelectGraphic *p) { PMS_SELECT_GRAPHIC_DrawRows(p, 0); }

void PMS_SELECT_GRAPHIC_RedrawRowsAfterInput(struct PmsSelectGraphic *p) { PMS_SELECT_GRAPHIC_DrawRows(p, 1); PMS_SELECT_GRAPHIC_ResetBgBlink(&p->bg); }

/*
 * Redraws the visible rows. Caller narrows the outgoing index to u8; both row
 *   loops keep the indices 0..3. A named u8 `which` before the comparison and
 *   the call removes duplicate narrowing.
 */
void PMS_SELECT_GRAPHIC_DrawRows(struct PmsSelectGraphic *p, int flag)
{
    int i;
    if (flag && !PMS_DRAW_IsPrintEnd(p->pmsDraw)) return;
    BG_SYS_ClearLayerEx(2, 0);
    if (p->topRow) {
        PMS_SELECT_GRAPHIC_ColorTitleBg(&p->bg, PMSI_PARAM_GetSentenceType(PMS_WORD_GetSaveEntry(p->saveData, (u8)(p->topRow - 1))));
    }
    for (i = 0; i < PMS_SELECT_GRAPHIC_VISIBLE_ROWS; i++) {
        if (PMS_DRAW_IsActive(p->pmsDraw, (u8)i)) PMS_DRAW_Clear(p->pmsDraw, (u8)i, 0);
    }
    for (i = 0; p->topRow + i < p->filledCount && i < PMS_SELECT_GRAPHIC_VISIBLE_ROWS; i++) {
        u8 which;
        which = p->topRow + i;
        PMS_SELECT_GRAPHIC_DrawSavedRow(p, (u8)i, which, which == p->selected);
    }
    if (p->filledCount < PMS_SELECT_GRAPHIC_MAX_ENTRIES && i < PMS_SELECT_GRAPHIC_VISIBLE_ROWS) {
        u8 which;
        which = p->topRow + i;
        PMS_SELECT_GRAPHIC_DrawNewRow(p, (u8)i, 0, which == p->selected);
    }
}

/*
 * Places the scroll bar thumb for the top row. The dead first assignment
 * (`a=t;` before `a=t+16;`) was a stand-in and is gone; the bytes do not change.
 */
void PMS_SELECT_GRAPHIC_PlaceScrollThumb(struct PmsSelectGraphic *p, int force)
{
    int n, index, y, a, b, t;
    short pos;
    if (!CLACT_GetActorDrawEnable(p->scrollThumb)) return;
    n = p->rowCount - 2;
    index = p->topRow;
    if (!force) {
        y = CLACT_GetActorPosAxis(p->scrollThumb, 1);
        t = 137 * index / n;
        a = t + 16;
        b = 137 * (index + 1) / n + 16;
        if (index == 0) { if (y < b) return; }
        else if (index == n - 1) { if (y >= a) return; }
        else { if (a <= y && y < b) return; }
    }
    if (index == 0) pos = 16;
    else if (index == n - 1) pos = 152;
    else {
        t = 137 * (p->topRow) / n;
        pos = t + 16 + 137 / (n * 2);
        if (pos > 152) pos = 152;
    }
    CLACT_SetActorPosAxis(p->scrollThumb, pos, 1);
}

/* Starts a touch drag when the scroll bar is pressed. */
int PMS_SELECT_GRAPHIC_StartThumbDrag(struct PmsSelectGraphic *p)
{
    unsigned x, y;
    if (!CLACT_GetActorDrawEnable(p->scrollThumb)) return 0;
    if (!TOUCHPANEL_GetPointTrg(&x, &y)) return 0;
    if (x >= 240 && x <= 247 && y <= 159 && y >= 8) {
        p->touchScrolling = 1;
        return 1;
    }
    return 0;
}

/* Row index and thumb position for the touched height y. */
void PMS_SELECT_GRAPHIC_GetThumbRow(unsigned y, int count, short *out, short *pos)
{
    int n, i, a, b;
    n = count - 2;
    for (i = 0; i < n; i++) {
        a = 137 * i / n + 16;
        b = (137 * i + 137) / n + 16;
        if (i == 0) { if (y < b) { *out = i; break; } }
        else if (i == n - 1) { if (y >= a) { *out = i; break; } }
        else { if (a <= y && y < b) { *out = i; break; } }
    }
    if (y > 152) y = 152;
    else if (y < 16) y = 16;
    *pos = y;
}

/* Follows the dragged scroll bar; returns 1 when the top row changed. */
int PMS_SELECT_GRAPHIC_UpdateThumbDrag(struct PmsSelectGraphic *p)
{
    unsigned x, y;
    unsigned short index;
    short pos;
    if (!TOUCHPANEL_GetPointCont(&x, &y)) {
        p->touchScrolling = 0;
        return 0;
    }
    PMS_SELECT_GRAPHIC_GetThumbRow(y, p->rowCount, (short *)&index, &pos);
    CLACT_SetActorPosAxis(p->scrollThumb, pos, 1);
    if ((unsigned short)index != p->topRow) {
        p->topRow = index;
        return 1;
    }
    return 0;
}

/*
 * Input of the list: keys, touch on the rows and on the scroll bar. Returns 1 when a row was chosen.
 * lever: byte +99 is a one-bit field; selection bytes retain 255 and the signed touch result retains -1.
 */
int PMS_SELECT_GRAPHIC_UpdateInput(struct PmsSelectGraphic *p)
{
    int result = 0;
    int proceed = 1;
    int active;
    int hit;
    if (!p->touchScrolling) {
        active = 0;
        if (KEY_GetTrg() & ~2) active = 1;
        if (active && p->selected == 255) {
            if (p->prevSelected == 255) p->selected = p->topRow;
            else if (p->topRow <= p->prevSelected && p->prevSelected < p->topRow + 3) p->selected = p->prevSelected;
            else p->selected = p->topRow;
            p->prevSelected = 255;
            proceed = 0;
            p->isTouch = 0;
            GFL_USE_PlaySeDefaultVolume(1352);
            PMS_SELECT_GRAPHIC_RedrawRowsAfterInput(p);
        }
    }
    if (proceed && p->selected != 255 && !p->touchScrolling) {
        if (KEY_GetTrg() & 1) {
            result = 1;
            proceed = 0;
            p->isTouch = 0;
        } else if (KEY_GetRepeat() & 64) {
            if (p->selected != 0) {
                p->prevSelected = p->selected;
                p->selected--;
                if (p->selected + 1 == p->topRow) p->topRow--;
                PMS_SELECT_GRAPHIC_PlaceScrollThumb(p, 0);
                PMS_SELECT_GRAPHIC_RedrawRowsAfterInput(p);
                GFL_USE_PlaySeDefaultVolume(1352);
            }
            proceed = 0;
            p->isTouch = 0;
        } else if (KEY_GetRepeat() & 128) {
            if (p->selected < p->rowCount - 1) {
                p->prevSelected = p->selected;
                p->selected++;
                if (p->selected == p->topRow + 3) p->topRow++;
                PMS_SELECT_GRAPHIC_PlaceScrollThumb(p, 0);
                PMS_SELECT_GRAPHIC_RedrawRowsAfterInput(p);
                GFL_USE_PlaySeDefaultVolume(1352);
            }
            proceed = 0;
            p->isTouch = 0;
        }
    }
    if (proceed) {
        if (p->touchScrolling) {
            if (PMS_SELECT_GRAPHIC_UpdateThumbDrag(p)) {
                PMS_SELECT_GRAPHIC_RedrawRowsAfterInput(p);
                GFL_USE_PlaySeDefaultVolume(1352);
            }
            p->isTouch = 1;
        } else {
            hit = PMS_SELECT_GRAPHIC_GetTouchedRow();
            if (hit != -1 && hit > p->rowCount - 1) hit = -1;
            if (hit != -1) {
                p->prevSelected = p->selected;
                p->selected = p->topRow + hit;
                PMS_SELECT_GRAPHIC_RedrawRowsAfterInput(p);
                result = 1;
                p->isTouch = 1;
            } else {
                if (!p->touchScrolling) PMS_SELECT_GRAPHIC_StartThumbDrag(p);
                if (p->touchScrolling == 1) {
                    if (PMS_SELECT_GRAPHIC_UpdateThumbDrag(p) || p->selected != 255) {
                        p->prevSelected = p->selected;
                        p->selected = 255;
                        PMS_SELECT_GRAPHIC_RedrawRowsAfterInput(p);
                    }
                    GFL_USE_PlaySeDefaultVolume(1352);
                    p->isTouch = 1;
                }
            }
        }
    }
    return result;
}

void PMS_SELECT_GRAPHIC_FlushRowWindows(struct PmsSelectGraphic *p)
{
    int i;
    for (i = 0; i < PMS_SELECT_GRAPHIC_VISIBLE_ROWS; i++)
        PMS_SELECT_GRAPHIC_FlushRowWindow(p->printQueue, p->rowWindows[i], &p->rowPending[i]);
}

/* Transfers a row window to the screen once its text is printed. */
int PMS_SELECT_GRAPHIC_FlushRowWindow(void *printQueue, void *window, int *pending)
{
    void *bmp = BMP_WIN_GetBmp(window);
    if (*pending == 1 && PRINTSYS_QUE_IsExistTarget(printQueue, bmp) == 0) {
        BMP_WIN_TransferChars(window);
        BMP_WIN_MakeScreen(window);
        BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer(window));
        *pending = 0;
        return 1;
    }
    return 0;
}

/* Draws the empty "new" row below the last saved sentence. */
void PMS_SELECT_GRAPHIC_DrawNewRow(struct PmsSelectGraphic *p, u8 row, int unused, int flag)
{
    void *str;
    u16 color;
    str = MSGDATA_AllocString(p->msgBank, 17);
    PMS_SELECT_GRAPHIC_ColorRowBg(&p->bg, row, 6, flag);
    if (flag) {
        BMP_Clear(BMP_WIN_GetBmp(p->rowWindows[row]), 14);
        color = 0x44e;
    } else {
        BMP_Clear(BMP_WIN_GetBmp(p->rowWindows[row]), 13);
        color = 0x44d;
    }
    PRINTSYS_PrintQueColor(p->printQueue, BMP_WIN_GetBmp(p->rowWindows[row]), 0, 0, str, p->font, color);
    STRBUF_Delete(str);
    BMP_WIN_MakeScreen(p->rowWindows[row]);
    BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer(p->rowWindows[row]));
    p->rowPending[row] = 1;
}

/* Draws the saved sentence which in the row window row. */
void PMS_SELECT_GRAPHIC_DrawSavedRow(struct PmsSelectGraphic *p, u8 row, u8 which, int flag)
{
    const struct PmsData *item;
    item = PMS_WORD_GetSaveEntry(p->saveData, which);
    PMS_SELECT_GRAPHIC_ColorRowBg(&p->bg, row, PMSI_PARAM_GetSentenceType(item), flag);
    if (flag) {
        BMP_Clear(BMP_WIN_GetBmp(p->rowWindows[row]), 14);
        PMS_DRAW_SetPrintColor(p->pmsDraw, 0x44e);
        PMS_DRAW_SetNullColorPalette(p->pmsDraw, 14);
    } else {
        BMP_Clear(BMP_WIN_GetBmp(p->rowWindows[row]), 13);
        PMS_DRAW_SetPrintColor(p->pmsDraw, 0x44d);
        PMS_DRAW_SetNullColorPalette(p->pmsDraw, 13);
    }
    if (PMSI_PARAM_IsComplete((struct PmsData *)item, p->heapId) == 1) {
        PMS_DRAW_Print((uptr)p->pmsDraw, (uptr)p->rowWindows[row], (struct BeaconDetailGraQuad *)item, row);
        p->rowPending[row] = 1;
    }
}

/* Row (0 to 2) under the touch, or -1. */
int PMS_SELECT_GRAPHIC_GetTouchedRow(void)
{
    u32 x, y;
    u32 result;
    if (TOUCHPANEL_GetPointTrg(&x, &y) && x < 232 && y >= 8) {
        result = (y / 8 - 1) / 6;
        if (result < 3) return result;
    }
    return -1;
}

int PMS_SELECT_GRAPHIC_ShowTouchBar(void *unused, struct PmsSelectGraphic *p)
{
    TOUCHBAR_SetAllButtonsVisible(p->touchBar, 1);
    return 1;
}

/*
 * Lever: one-bit field at +0x99 gives the original shift pair. Calls in
 * both Boolean arms preserve 355D8's u8 ABI without ternary truncation.
 * Empty switch cases -1 and 7 preserve the original unused comparisons.
 * The original explicitly supplies r0 to the otherwise argument-free
 * 021C0AC0 forwarder; its unused input is retained at this caller.
 */
int PMS_SELECT_GRAPHIC_StepList(void *unused, struct PmsSelectGraphic *p)
{
    int result = -1;
    int done = 0;
    int input;
    PMS_SELECT_GRAPHIC_UpdateBgBlink(&p->bg);
    if (!p->bg.decided) {
        input = 0;
        if (!p->touchScrolling) {
            if (p->isTouch) UI_SetInputMode(1);
            else UI_SetInputMode(0);
            PMS_SELECT_GRAPHIC_UpdateTouchBar(p->touchBar);
            if (TOUCHBAR_GetPressedButtonIdIfPressing(p->touchBar) != -1) p->touchBarActive = 0;
            result = TOUCHBAR_GetPressedButtonIdIfDone(p->touchBar);
            if (result != -1) p->touchBarActive = 1;
            p->isTouch = UI_GetInputMode() == 1;
        }
        switch (result) {
        case -1: break;
        case 1:
            p->args->cancelled = 1;
            p->args->selected = 0;
            p->nextState = 5;
            return 1;
        case 7: break;
        }
        if (p->touchBarActive) input = PMS_SELECT_GRAPHIC_UpdateInput(p);
        if (input) {
            GFL_USE_PlaySeDefaultVolume(1356);
            p->bg.decided = 1;
        }
    } else {
        if (p->bg.decideFrames == 16) done = 1;
    }
    if (done) {
        if (PMSI_PARAM_IsComplete(PMS_WORD_GetSaveEntry(p->saveData, p->selected), p->heapId)) p->nextState = 8;
        else p->nextState = 11;
        return 1;
    }
    return 0;
}

int PMS_SELECT_GRAPHIC_HideTouchBar(void *unused, struct PmsSelectGraphic *p)
{
    TOUCHBAR_SetAllButtonsVisible(p->touchBar, 0);
    return 1;
}

int PMS_SELECT_GRAPHIC_StepOpenRowMenu(void *unused, struct PmsSelectGraphic *p)
{
    if (p->isTouch) UI_SetInputMode(1);
    else UI_SetInputMode(0);
    p->taskMenu = PMS_SELECT_GRAPHIC_OpenRowMenu(p->taskMenuRes, p->msgBank, p->heapId);
    BRIGHTNESS_Set(-8, 30, 1);
    return 1;
}

/* The menu of the chosen row: edit (0), discard (1) or back (2). */
int PMS_SELECT_GRAPHIC_StepRowMenu(void *unused, struct PmsSelectGraphic *p)
{
    PMS_SELECT_GRAPHIC_UpdateRowMenu(p->taskMenu);
    if (APP_TASKMENU_IsFinish(p->taskMenu)) {
        switch (APP_TASKMENU_GetCursorPos(p->taskMenu)) {
        case 0:
            p->nextState = 5;
            p->args->selected = PMS_WORD_GetSaveEntry(p->saveData, p->selected);
            p->args->cancelled = 0;
            break;
        case 1: p->nextState = 11; break;
        case 2: p->nextState = 4; break;
        }
        return 1;
    }
    return 0;
}

int PMS_SELECT_GRAPHIC_StepCloseRowMenu(void *unused, struct PmsSelectGraphic *p)
{
    PMS_SELECT_GRAPHIC_CloseRowMenu(p->taskMenu);
    p->isTouch = UI_GetInputMode() == 1;
    if (p->nextState == 4) {
        BRIGHTNESS_Set(0, 30, 1);
        PMS_SELECT_GRAPHIC_ResetBgBlink(&p->bg);
        p->bg.decideFrames = 0;
        p->bg.decided = 0;
        if (p->isTouch != 0) {
            p->prevSelected = p->selected;
            p->selected = 255;
            PMS_SELECT_GRAPHIC_RedrawRowsAfterInput(p);
        }
    }
    return 1;
}

/* Opens the input screen on the chosen sentence. */
int PMS_SELECT_GRAPHIC_StepOpenEditScreen(int *step, struct PmsSelectGraphic *p)
{
    void *param;
    switch (*step) {
    case 0: ++*step; break;
    case 1:
        param = PMSI_PARAM_Create(2, 0, 0, 1, p->pmsSystem, p->heapId);
        PMSI_PARAM_SetSentence(param, PMS_WORD_GetSaveEntry(p->saveData, p->selected));
        PROCSYS_Push(p->procList, -1, (void *)gPmsSelectProcData, param);
        p->editParam = param;
        return 1;
    }
    return 0;
}

/* Takes the edited sentence back from the input screen. */
int PMS_SELECT_GRAPHIC_StepCloseEditScreen(int *step, struct PmsSelectGraphic *p)
{
    struct PmsData sentence;
    switch (*step) {
    case 0:
        if (PMSI_PARAM_CheckModified(p->editParam)) {
            PMSI_PARAM_GetSentence(p->editParam, &sentence);
            PMS_WORD_SetSaveEntry(p->saveData, p->selected, &sentence);
        }
        PMSI_PARAM_Delete(p->editParam);
        ++*step;
        break;
    case 1: return 1;
    }
    return 0;
}

struct PmsSelectGraphicScene *PMS_SELECT_GRAPHIC_CreateScene(unsigned arg, u16 heap)
{
    struct PmsSelectGraphicScene *scene;
    scene = GFL_HEAP_Alloc(heap, sizeof(struct PmsSelectGraphicScene), 0, gPmsSelectGraphicSceneFileName, 0x151);
    MI_CpuFill8(scene, 0, sizeof(struct PmsSelectGraphicScene));
    *(volatile u16 *)REG_BLDCNT_A_ADDR = 0;
    *(volatile u16 *)REG_BLDCNT_B_ADDR = 0;
    *(volatile unsigned *)REG_DISPCNT_A_ADDR &= ~DISPCNT_WINDOW_ENABLE_MASK;
    *(volatile unsigned *)REG_DISPCNT_B_ADDR &= ~DISPCNT_WINDOW_ENABLE_MASK;
    BG_SYS_ClearGraphicsMemory(0);
    BG_SYS_SetVramBanks((struct DispVram *)gPmsSelectGraphicVramBanks);
    BG_SYS_SetLcdSwap(arg);
    BG_SYS_ResetSubDisplay(); BG_SYS_ClearMainPlanes(); BG_SYS_ClearSubPlanes();
    GF_FONT_InitTextColor();
    PMS_SELECT_GRAPHIC_InitSceneBgs(scene, heap);
    PMS_SELECT_GRAPHIC_InitSceneActors(&scene->actorUnit, (uptr)gPmsSelectGraphicVramBanks, heap);
    scene->drawTask = GFL_USE_AddMainTask((void (*)(struct TcbTask *, void *))PMS_SELECT_GRAPHIC_SceneTask, (void *)scene, 0);
    return scene;
}

/*
 * volatile: hardware registers 0x04000050, 0x04001050, 0x04000000, 0x04001000 re-read at 021C16D6 and 021C16E0.
 */
void PMS_SELECT_GRAPHIC_DeleteScene(struct PmsSelectGraphicScene *scene)
{
    TCB_DeleteTask(scene->drawTask);
    PMS_SELECT_GRAPHIC_ExitSceneActors(&scene->actorUnit);
    PMS_SELECT_GRAPHIC_ExitSceneBgs(scene);
    GF_FONT_SetDefaultTextColor();
    *(volatile u16 *)REG_BLDCNT_A_ADDR = 0;
    *(volatile u16 *)REG_BLDCNT_B_ADDR = 0;
    *(volatile unsigned *)REG_DISPCNT_A_ADDR &= ~DISPCNT_WINDOW_ENABLE_MASK;
    *(volatile unsigned *)REG_DISPCNT_B_ADDR &= ~DISPCNT_WINDOW_ENABLE_MASK;
    MI_CpuFill8(scene, 0, sizeof(struct PmsSelectGraphicScene));
    GFL_HEAP_Free(scene);
}

void PMS_SELECT_GRAPHIC_UpdateScene(struct PmsSelectGraphicScene *scene) { PMS_SELECT_GRAPHIC_DrawSceneActors(&scene->actorUnit); PMS_SELECT_GRAPHIC_UpdateSceneNothing(scene); }

/* The actor unit of the scene. */
void *PMS_SELECT_GRAPHIC_GetSceneActorUnit(struct PmsSelectGraphicScene *scene) { return PMS_SELECT_GRAPHIC_ReadPointer(&scene->actorUnit); }

/* Task of the scene: runs the draw and the vblank part of the actor system. */
void PMS_SELECT_GRAPHIC_SceneTask(int taskId, void *work)
{
    struct PmsSelectGraphicScene *scene = work;
    PMS_SELECT_GRAPHIC_TransferSceneBgs(scene);
    PMS_SELECT_GRAPHIC_VBlankSceneActors(&scene->actorUnit);
}

void PMS_SELECT_GRAPHIC_InitSceneBgs(struct PmsSelectGraphicScene *scene, u16 heap)
{
    unsigned i;
    const struct PmsSelectGraphicBgRow *row;
    unsigned id;
    MI_CpuFill8(scene, 0, 4);
    BG_SYS_Create(heap);
    BMP_WIN_Init(heap);
    BG_SYS_SetGraphicsMode((struct DispConfig *)gPmsSelectGraphicDispConfig);
    for (i = 0; i < 6; i++) {
        row = &gPmsSelectGraphicBgRows[i];
        id = row->id;
        BG_SYS_InitBgLayer((u8)id, (const struct BgTemplate *)row->bg, (u8)row->pal);
        BG_SYS_FreeSlot(id);
        BG_SYS_SetPlaneVisible(id, row->value);
    }
}

/*
 * lever: observed 44-byte table rows use a typed row pointer; integer address
 * arithmetic swaps base/index colours, member access is EXACT.
 */
void PMS_SELECT_GRAPHIC_ExitSceneBgs(struct PmsSelectGraphicScene *scene)
{
    const struct PmsSelectGraphicBgRow *base;
    unsigned long i;
    base = gPmsSelectGraphicBgRows;
    for (i = 0; i < 6; i++) BG_SYS_FreeLayerBuf((u8)base[i].id);
    BMP_WIN_Exit();
    BG_SYS_Delete();
    MI_CpuFill8(scene, 0, 4);
}

void PMS_SELECT_GRAPHIC_UpdateSceneNothing(struct PmsSelectGraphicScene *scene) { }

void PMS_SELECT_GRAPHIC_TransferSceneBgs(struct PmsSelectGraphicScene *scene)
{
    BG_SYS_Update();
}

void PMS_SELECT_GRAPHIC_InitSceneActors(void **unitOut, unsigned vram, unsigned heap)
{
    MI_CpuFill8(unitOut, 0, 4);
    CLACT_InitSystem((const struct ClactSysInit *)gPmsSelectGraphicActorInit, (const struct DispVramCfg *)vram, heap);
    *unitOut = CLACT_CreateUnit(128, 0, heap);
    CLACT_SetUnitDefaultRenderer(*unitOut);
    BG_SYS_SetMainPlaneVisible(16, 1);
    BG_SYS_SetSubPlaneVisible(16, 1);
}

void PMS_SELECT_GRAPHIC_ExitSceneActors(void **unit) { CLACT_DeleteUnit(*unit); CLACT_ExitSystem(); MI_CpuFill8(unit, 0, 4); }

void PMS_SELECT_GRAPHIC_DrawSceneActors(void *unit) { CLACT_DrawSystem(); }

void PMS_SELECT_GRAPHIC_VBlankSceneActors(void *unit)
{
    CLACT_VBlankSystem();
}

void *PMS_SELECT_GRAPHIC_ReadPointer(void **p)
{
    return *p;
}

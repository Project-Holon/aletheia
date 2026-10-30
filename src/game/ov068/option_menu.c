/*
 * file:     option_menu.c
 * unit:     yes
 * function: OPTION_MENU_Init, OPTION_MENU_Exit, OPTION_MENU_Main, OPTION_MENU_InitScreen, OPTION_MENU_ExitScreen, OPTION_MENU_UpdateScreen, OPTION_MENU_GetScreenSpriteActor, OPTION_MENU_GetScreenSpriteUnit, OPTION_MENU_GetScreenWindow, OPTION_MENU_RestartScreenBlink, OPTION_MENU_ScreenTaskMain, OPTION_MENU_InitGfx, OPTION_MENU_ExitGfx, OPTION_MENU_UpdateGfxBlink, OPTION_MENU_GetGfxWindow, OPTION_MENU_CreateLabelWindows, OPTION_MENU_RestartGfxBlink, OPTION_MENU_FlushGfx, BLINK_PALANM_BlendStep, OPTION_MENU_InitSprites, OPTION_MENU_ExitSprites, OPTION_MENU_UpdateSprites, OPTION_MENU_DrawSprites, OPTION_MENU_GetSpriteActor, OPTION_MENU_GetSpriteUnit, OPTION_MENU_InitInput, OPTION_MENU_ExitInput, OPTION_MENU_ReadInput, OPTION_MENU_GetInputCommand, OPTION_MENU_GetInputPoint, OPTION_MENU_InitTextBox, OPTION_MENU_ExitTextBox, OPTION_MENU_PrintText, OPTION_MENU_PrintTextFromBank, OPTION_MENU_IsTextDone, OPTION_MENU_InitButtons, OPTION_MENU_ExitButtons, OPTION_MENU_UpdateButtons, OPTION_MENU_UpdateButtonWindows, OPTION_MENU_GetButtonChoice, OPTION_MENU_IsButtonFinished, OPTION_MENU_ResetButtons, OPTION_MENU_CreateButtonWindows, OPTION_MENU_HasButtonFocusChanged, OPTION_MENU_InitList, OPTION_MENU_ExitList, OPTION_MENU_UpdateList, OPTION_MENU_ClearListHighlight, OPTION_MENU_GetListCursor, OPTION_MENU_GetListSettings, OPTION_MENU_RedrawList, OPTION_MENU_SetListButtonMode, OPTION_MENU_DrawList, OPTION_MENU_ScrollList, OPTION_MENU_SelectChoiceAtTouch, OPTION_MENU_ApplySoundMode, OPTION_MENU_StepSelectedSetting, OPTION_MENU_GetRowAtTouch, OPTION_MENU_ShiftInputTrail, OPTION_MENU_InitMessageBox, OPTION_MENU_ExitMessageBox, OPTION_MENU_UpdateMessageBox, OPTION_MENU_PrintDiscardPrompt, OPTION_MENU_GetMessageBoxAnswer, OPTION_MENU_PrintHelpMessage, OPTION_MENU_PrintMessage, OPTION_MENU_IsMessageDone, OPTION_MENU_InitSettings, OPTION_MENU_ExitSettings, OPTION_MENU_WriteSettings, OPTION_MENU_SelectChoice, OPTION_MENU_StepSetting, OPTION_MENU_IsChoiceSelected, OPTION_MENU_GetTextSpeedWait, OPTION_MENU_TakeChangedSetting, OPTION_MENU_AreSettingsEqual, OPTION_MENU_InitRunner, OPTION_MENU_ExitRunner, OPTION_MENU_UpdateRunner, OPTION_MENU_IsRunnerFinished, OPTION_MENU_SetRunnerState, OPTION_MENU_FinishRunner, OPTION_MENU_StateFadeIn, OPTION_MENU_StateFadeOut, OPTION_MENU_StateMain, OPTION_MENU_StateDiscardPrompt, OPTION_MENU_StateKeepSaved, OPTION_MENU_StateApply, OPTION_MENU_IsPointInRect
 * address:  0x021B95A0
 * region:   ov068
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GF_OVERLAY_Load  0x02034AC4  arm
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm
 *   PROCSYS_AllocProcWork  0x0203159C  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   GF_FONT_Create  0x0201D7EC  thumb
 *   PRINTSYS_QUE_Create  0x0201C440  thumb
 *   APP_TASKMENU_RES_Create  0x02027F60  thumb
 *   MSGDATA_CreateFromArchive  0x02045B38  arm
 *   TCBL_Create  0x0203101C  arm
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   SYSTEM_DATA_GetConfig  0x0200873C  thumb
 *   ov067_id       0x00000043  data
 *   TCBL_Destroy  0x02031140  arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   PROCSYS_FreeProcWork  0x020315D4  arm
 *   GFL_HEAP_DeleteChecked  0x020306F0  arm
 *   GF_OVERLAY_Unload  0x02034A5C  arm
 *   APP_TASKMENU_RES_Delete  0x02027FD8  thumb
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb
 *   GF_FONT_Delete  0x0201D83C  thumb
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb
 *   TCBL_Main  0x020310C4  arm
 *   BG_SYS_ClearGraphicsMemory  0x0204335C  arm
 *   BG_SYS_SetVramBanks  0x020433E0  arm
 *   BG_SYS_SetLcdSwap  0x0204363C  arm
 *   BG_SYS_ResetSubDisplay  0x0204361C  arm
 *   BG_SYS_ClearMainPlanes  0x020434CC  arm
 *   BG_SYS_ClearSubPlanes  0x02043588  arm
 *   GF_FONT_InitTextColor  0x0201DD60  thumb
 *   GF_FONT_SetTextColor  0x0201DD78  thumb
 *   GFL_USE_AddMainTask  0x020056A0  thumb
 *   gOptionMenuDispVram     0x021BB598  data  a4
 *   TCB_DeleteTask  0x02030EAC  arm
 *   GF_FONT_SetDefaultTextColor  0x0201DD68  thumb
 *   MI_CpuCopy8  0x02082D44  arm
 *   BG_SYS_Create  0x0203F8F4  arm
 *   BMP_WIN_Init  0x02045088  arm
 *   BG_SYS_SetGraphicsMode  0x0203FC28  arm
 *   BG_SYS_InitBgLayer  0x0203FCA0  arm
 *   BG_SYS_FreeSlot  0x020414AC  arm
 *   BG_SYS_SetPlaneVisible  0x02040588  arm
 *   BG_SYS_Init  0x02040C14  arm
 *   ARC_TOOL_CreateHandle  0x020490F4  arm
 *   ARC_UTIL_UploadBgCharFromHandle  0x02049658  arm
 *   ARC_UTIL_UploadBgPaletteFromHandle  0x020498F4  arm
 *   ARC_UTIL_UploadPaletteFromHandleWhole  0x02049B68  arm
 *   ARC_UTIL_UploadPaletteFromHandle  0x02049BDC  arm
 *   ARC_UTIL_LoadBgCharDataFromHandle  0x02049DF4  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   ARC_UTIL_LoadPaletteBlockFromArchive  0x02049F34  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   BMP_WIN_Create  0x020450F0  arm
 *   gOptionMenuDispConfig  0x021BB540  data  a4
 *   gOptionMenuBgLayers  0x021BB614  data  a4
 *   BMP_WIN_Delete  0x020452E8  arm
 *   BG_SYS_FreeTiles  0x02040DA8  arm
 *   BG_SYS_FreeLayerBuf  0x020403F4  arm
 *   BMP_WIN_Exit  0x020450C8  arm
 *   BG_SYS_Delete  0x0203F9B4  arm
 *   MSGDATA_AllocString  0x02045EC0  arm
 *   PRINTSYS_MeasureWidestLine  0x0201D304  thumb
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   PRINTSYS_Print  0x0201C7A4  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   BG_SYS_MarkTileDirty  0x02041B6C  arm
 *   STRBUF_Delete  0x02045808  arm
 *   BMP_GetPixels  0x020437D4  arm
 *   MIi_CpuCopy32  0x02082A90  arm
 *   BMP_WIN_GetWidth  0x02045738  arm
 *   PRINTSYS_PrintColor  0x0201C7D0  thumb
 *   gOptionMenuLabels     0x021BB820  data  ov068  a4
 *   BG_SYS_Update  0x020419E4  arm
 *   FX_SinCosTable_     0x020A1B38  data  a2
 *   NNS_GfdRegisterNewVramTransferTask  0x02061CA4  arm
 *   CLACT_InitSystem  0x0204A48C  arm
 *   CLACT_CreateUnit  0x0204B100  arm
 *   CLACT_SetUnitDefaultRenderer  0x0204B270  arm
 *   BG_SYS_SetMainPlaneVisible  0x020434DC  arm
 *   BG_SYS_SetSubPlaneVisible  0x02043598  arm
 *   CLACT_RegisterPalette  0x0204ABF0  arm
 *   CLACT_RegisterCharacter  0x0204A6C8  arm
 *   CLACT_RegisterCellAnim  0x0204AF28  arm
 *   CLACT_CreateActor  0x0204B294  arm
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   CLACT_SetActorPaletteOffset  0x0204B6F4  arm
 *   GFL_NET_GetRunState  0x0203CD98  arm
 *   GFL_NET_RefreshWmIconAtTopRight  0x0203D34C  arm
 *   gClActorInitParam     0x020A1448  data  a4
 *   gOptionMenuChoices     0x021BB704  data  ov068  a4
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *   CLACT_ReleasePalette  0x0204ADA4  arm
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm
 *   CLACT_DeleteUnit  0x0204B1CC  arm
 *   CLACT_ExitSystem  0x0204A5AC  arm
 *   CLACT_SetActorAnimIndex  0x0204B908  arm
 *   CLACT_DrawSystem  0x0204A600  arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   TOUCHPANEL_GetPointTrg  0x02035D20  arm
 *   TOUCHPANEL_GetPointCont  0x02035CB8  arm
 *   KEY_GetTrg  0x020362DC  arm
 *   KEY_GetCont  0x0203630C  arm
 *   UI_GetInputMode  0x020355C4  arm
 *   UI_SetInputMode  0x020355D8  arm
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   STRBUF_Create  0x020457B0  arm
 *   PRINTSYS_CTRL_Init  0x02028470  thumb
 *   BMP_WIN_GetPalette  0x02045778  arm
 *   BMP_MENUWORK_DrawWindow  0x0201F73C  thumb
 *   BG_SYS_PushTile  0x020409B4  arm
 *   PRINTSYS_PrintStreamDelete  0x0201CE48  thumb
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   PRINTSYS_PrintQue  0x0201C6FC  thumb
 *   PRINTSYS_PrintStream  0x0201CCE4  thumb
 *   PRINTSYS_CTRL_Update  0x02028484  thumb
 *   PRINTSYS_QUE_IsExistTarget  0x0201C6C4  thumb
 *   TOUCHBAR_Create  0x021B62E0  thumb  ov067
 *   GAME_DATA_ContainsRecentId  0x02012BF8  thumb
 *   TOUCHBAR_SetButtonToggled  0x021B6598  thumb  ov067
 *   gOptionMenuReturnButtonCells     0x021BB5D4  data  a4
 *   TOUCHBAR_Delete  0x021B639C  thumb
 *   APP_TASKMENU_WIN_Delete  0x02028148  thumb
 *   OPTION_MENU_IsPointInRect  0x021BB508  thumb  ov068
 *   APP_TASKMENU_WIN_SetActive  0x02028218  thumb
 *   APP_TASKMENU_WIN_SetDecide  0x0202822C  thumb
 *   TOUCHBAR_Update  0x021B63D0  thumb  ov067
 *   TOUCHBAR_GetPressedButtonIdIfPressing  0x021B6470  thumb  ov067
 *   TOUCHBAR_GetPressedButtonIdIfDone  0x021B6448  thumb  ov067
 *   TOUCHBAR_IsButtonToggled  0x021B65A8  thumb  ov067
 *   GAME_DATA_SetRecentId  0x02012BE0  thumb
 *   gOptionMenuConfirmRect     0x021BB550  data  a4
 *   gOptionMenuCancelRect     0x021BB560  data  ov068  a4
 *   APP_TASKMENU_WIN_Update  0x02028178  thumb
 *   APP_TASKMENU_WIN_IsFinish  0x02028230  thumb
 *   APP_TASKMENU_WIN_ResetDecide  0x020282A4  thumb
 *   APP_TASKMENU_WIN_Create  0x02027FEC  thumb
 *   BG_SYS_GetScrollY  0x02040804  arm
 *   gOptionMenuSettingRows     0x021BB570  data  a4
 *   BG_SYS_FillTileMap  0x020413B0  arm
 *   CLACT_ChangeActorAnimSeq  0x0204B8A0  arm
 *   gOptionMenuRowPalettes     0x021BB538  data  a1
 *   BG_SYS_ChangeScroll  0x02041EE4  arm
 *   CLACT_AddActorSurfacePos  0x0204B404  arm
 *   GFL_USE_SetStereoOutput  0x02005C28  thumb
 *   APP_TASKMENU_OpenMenu  0x02027778  thumb
 *   APP_TASKMENU_UpdateMenu  0x02027974  thumb
 *   APP_TASKMENU_IsFinish  0x020279E8  thumb
 *   APP_TASKMENU_GetCursorPos  0x02027A04  thumb
 *   APP_TASKMENU_CloseMenu  0x02027858  thumb
 *   G2x_SetBlendBrightness_ 0x0207D658 arm
 *   CONFIG_GetTextSpeed  0x02008374  thumb
 *   CONFIG_GetBattleScene  0x020083AC  thumb
 *   CONFIG_GetBattleStyle  0x020083C8  thumb
 *   CONFIG_GetSoundMode  0x02008390  thumb
 *   CONFIG_GetButtonMode  0x02008428  thumb
 *   CONFIG_SetTextSpeed 0x0200837C thumb
 *   CONFIG_SetBattleScene 0x020083B4 thumb
 *   CONFIG_SetBattleStyle 0x020083D0 thumb
 *   CONFIG_SetSoundMode 0x02008398 thumb
 *   CONFIG_GetTextLanguage 0x020083E4 thumb
 *   CONFIG_SetTextLanguage 0x020083EC thumb
 *   CONFIG_SetButtonMode 0x02008430 thumb
 *   gOptionMenuSettingRowChoiceCount     0x021BB572  data  a2
 *   gOptionMenuSettingRowChoices     0x021BB574  data  a4
 *   gOptionMenuChoiceValues     0x021BB708  data  a4
 *   MSG_SPEED_GetWait  0x02012FFC  thumb
 *   GF_STANDARD_CompareBytes 0x0203EFC8 arm
 *   FADE_Start  0x0204E720  arm
 *   FADE_IsActive  0x0204E804  arm
 *   PRINTSYS_QUE_IsFinished  0x0201C6B4  thumb
 *   SAVE_CONTROL_WouldOverwriteSave  0x020071F0  thumb
 */
#include "../arm9/arc_util.h"
#include "../sdk_ioreg.h"
#include "../arm9/game_data.h"
#include "../arm9/system_data.h"
#include "../arm9/ui.h"
#include "../types.h"

struct ActorInitParam;
struct ClactActor;
struct ClactSysInit;
struct ClactVec2;
struct GfFont;
struct Tcbl;
struct Unit;
#include "option_menu_types.h"

/*
 * Message file and graphic archive indexes of the options menu. The Japanese archive has two
 * more entries in front.
 */
#if LANGUAGE == LANGUAGE_JAPANESE
#define OPTION_MENU_MSG_FILE 0x1e
#define OPTION_ARC_SHIFT 2
#else
#define OPTION_MENU_MSG_FILE 0x1d
#define OPTION_ARC_SHIFT 0
#endif
#define OPTION_ARC_ID(n) ((n) + OPTION_ARC_SHIFT)
#define OPTION_SPR_PLTT OPTION_ARC_ID(6)
#define OPTION_SPR_MAIN_CHAR OPTION_ARC_ID(5)
#define OPTION_SPR_MAIN_CELL OPTION_ARC_ID(4)
#define OPTION_SPR_MAIN_ANIM OPTION_ARC_ID(3)
#define OPTION_SPR_SUB_CHAR OPTION_ARC_ID(0xc)
#define OPTION_SPR_SUB_CELL OPTION_ARC_ID(0xb)
#define OPTION_SPR_SUB_ANIM OPTION_ARC_ID(0xa)

/* Display registers of the main (A) and sub (B) engine. */
#define REG_A_DISPCNT_ADDR REG_DISPCNT_ADDR
#define REG_A_BLDCNT_ADDR  REG_BLDCNT_ADDR
#define REG_B_DISPCNT_ADDR REG_DB_DISPCNT_ADDR
#define REG_B_BLDCNT_ADDR  REG_DB_BLDCNT_ADDR
#define REG_A_DISPCNT (*(volatile u32 *)REG_A_DISPCNT_ADDR)
#define REG_A_BLDCNT  (*(volatile u16 *)REG_A_BLDCNT_ADDR)
#define REG_B_DISPCNT (*(volatile u32 *)REG_B_DISPCNT_ADDR)
#define REG_B_BLDCNT  (*(volatile u16 *)REG_B_BLDCNT_ADDR)
#define DISPCNT_WINDOWS_OFF 0xFFFF1FFF

/* Key bits of the trigger and held masks. */
#define OPTION_KEY_A     0x0001
#define OPTION_KEY_B     0x0002
#define OPTION_KEY_RIGHT 0x0010
#define OPTION_KEY_LEFT  0x0020
#define OPTION_KEY_UP    0x0040
#define OPTION_KEY_DOWN  0x0080
#define OPTION_KEY_Y     0x0400
#define OPTION_KEY_X     0x0800

/* Sound effect ids. */
#define OPTION_SE_CURSOR  0x548
#define OPTION_SE_CONFIRM 0x54c
#define OPTION_SE_CANCEL  0x551
#define OPTION_SE_APPLY   0x558

#include "../arm9/bg_sys.h"

struct ClInitParam;

#include "../arm9/gf_overlay.h"
#include "../arm9/gfl_heap.h"
#include "../arm9/procsys.h"
extern void MI_CpuFill8(void *dst, u32 value, u32 size);
#include "../arm9/gf_font.h"
struct PrintQueue;
#ifdef __MWERKS__
#define PRINTSYS_PrintColor PRINTSYS_PrintColorHeader
#endif
#include "../arm9/printsys.h"
#ifdef __MWERKS__
/* original prototypes: the DS code declares these with other argument or return types than the definitions */
#undef PRINTSYS_PrintColor
extern void PRINTSYS_PrintColor(struct Bmp *bmp, s16 x, s16 y, struct Strbuf *str, struct GfFont *font, u16 color);
#endif
struct GFont;
struct TaskMenuRes;
#include "../arm9/app_taskmenu.h"
#include "../arm9/msgdata.h"
struct TcblSystem;
#include "../arm9/tcbl.h"
#include "../arm9/gamesystem.h"
struct SaveControl;
#ifdef __MWERKS__
#define GFL_HEAP_Free GFL_HEAP_FreeHeader
#endif
#include "../arm9/gfl_heap_wrap.h"
#ifdef __MWERKS__
/* original prototypes: the DS code declares these with other argument or return types than the definitions */
#undef GFL_HEAP_Free
extern void GFL_HEAP_Free(void *p);
#endif
struct TcbTask;
extern struct TcbTask *GFL_USE_AddMainTask(void (*fn)(struct Task *, OptionMenuScreen *), void *work, u32 priority);
struct TcbTask;
#include "../arm9/tcb_list.h"
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern void BMP_WIN_Init(u32 heapId);
#include "../arm9/arc_tool.h"
struct BmpWin;
extern struct BmpWin *BMP_WIN_Create(u32 bgLayer, u32 posX, u32 posY, u8 width, u8 height, u8 palette, u8 allocDir);
extern u32 BMP_WIN_Delete(struct BmpWin *win);
extern void BMP_WIN_Exit(void);
struct Strbuf;
struct Bmp;
extern struct Bmp *BMP_WIN_GetBmp(struct BmpWin *win);
struct Bmp;
extern void BMP_Clear(struct Bmp *bmp, u8 value);
extern void BMP_WIN_TransferChars(struct BmpWin *win);
extern void BMP_WIN_MakeScreen(struct BmpWin *win);
extern u8 BMP_WIN_GetBgLayer(struct BmpWin *win);
#include "../arm9/strbuf.h"
extern void *BMP_GetPixels(struct Bmp *bmp);
extern void MIi_CpuCopy32(u32 a, u32 b, u32 size);
extern u8 BMP_WIN_GetWidth(struct BmpWin *win);
#include "../arm9/nns_gfd_vram_transfer.h"
struct DispVramCfg;
struct SysInit;
#ifdef __MWERKS__
#define CLACT_RegisterPalette CLACT_RegisterPaletteHeader
#define CLACT_RegisterCharacter CLACT_RegisterCharacterHeader
#define CLACT_CreateActor CLACT_CreateActorHeader
#endif
#include "../arm9/clact.h"
#ifdef __MWERKS__
/* original prototypes: the DS code declares these with other argument or return types than the definitions */
#undef CLACT_RegisterPalette
extern s32 CLACT_RegisterPalette(void *arc, int id, int b, int c, int heapId);
#undef CLACT_RegisterCharacter
extern s32 CLACT_RegisterCharacter(void *arc, int id, int b, int c, int heapId);
#undef CLACT_CreateActor
extern struct ClactActor *CLACT_CreateActor(struct Unit *unit, unsigned int charRes, unsigned int plttRes, unsigned int cellRes, struct ActorInitParam *param, int flag, int heapId);
#endif
struct Actor;
#include "../arm9/net.h"
#include "../arm9/touchpanel.h"
#include "../arm9/key.h"
extern void GFL_USE_PlaySeDefaultVolume(u32 id);
struct PrintStreamCtrl;
#include "../arm9/app_keycursor.h"
extern u8 BMP_WIN_GetPalette(struct BmpWin *win);
#include "../arm9/bmp_menuwork.h"
struct TextPrinter;
#include "../ov067/touchbar.h"
extern void GFL_USE_SetStereoOutput(u32 a);
struct TaskMenuInitWork;
struct TaskMenuWork;
#include "../arm9/g2.h"
#include "../arm9/config.h"
#include "../arm9/gf_standard.h"
#include "../arm9/fade.h"
#include "../arm9/save_control.h"
#include "../arm9/msg_speed.h"

int OPTION_MENU_Init(struct Proc *proc, int *seq, OptionMenuArgs *args);
int OPTION_MENU_Exit(struct Proc *proc, int *seq, void *args, OptionMenuWork *work);
int OPTION_MENU_Main(struct Proc *proc, int *seq, void *args, OptionMenuWork *work);
void OPTION_MENU_InitScreen(OptionMenuScreen *screen, u16 heapId);
void OPTION_MENU_ExitScreen(OptionMenuScreen *screen);
void OPTION_MENU_UpdateScreen(OptionMenuScreen *screen);
struct ClactActor *OPTION_MENU_GetScreenSpriteActor(OptionMenuScreen *screen, int index);
struct Unit *OPTION_MENU_GetScreenSpriteUnit(OptionMenuScreen *screen);
struct BmpWindow *OPTION_MENU_GetScreenWindow(OptionMenuScreen *screen, int index);
#if LANGUAGE == LANGUAGE_JAPANESE
void OPTION_MENU_CreateScreenLabels(OptionMenuScreen *screen);
#endif
void OPTION_MENU_RestartScreenBlink(OptionMenuScreen *screen);
void OPTION_MENU_ScreenTaskMain(struct Task *task, OptionMenuScreen *screen);
void OPTION_MENU_InitGfx(OptionMenuGfx *gfx, u16 heapId);
void OPTION_MENU_ExitGfx(OptionMenuGfx *gfx);
void OPTION_MENU_UpdateGfxBlink(OptionMenuGfx *gfx);
struct BmpWindow *OPTION_MENU_GetGfxWindow(OptionMenuGfx *gfx, int index);
void OPTION_MENU_CreateLabelWindows(OptionMenuGfx *gfx);
void OPTION_MENU_RestartGfxBlink(OptionMenuGfx *gfx);
void OPTION_MENU_FlushGfx(OptionMenuGfx *gfx);
void BLINK_PALANM_BlendStep(u16 *outColor, u16 *angle, int step, u32 paletteIndex, u8 slot, u16 color0, u16 color1);
void OPTION_MENU_InitSprites(OptionMenuSprites *sprites, const void *res, u32 heapId);
void OPTION_MENU_ExitSprites(OptionMenuSprites *sprites);
void OPTION_MENU_UpdateSprites(OptionMenuSprites *sprites);
void OPTION_MENU_DrawSprites(OptionMenuSprites *sprites);
struct ClactActor *OPTION_MENU_GetSpriteActor(OptionMenuSprites *sprites, int index);
struct Unit *OPTION_MENU_GetSpriteUnit(OptionMenuSprites *sprites);
void OPTION_MENU_InitInput(OptionMenuInput *input, int heapId);
void OPTION_MENU_ExitInput(OptionMenuInput *input);
void OPTION_MENU_ReadInput(OptionMenuInput *input);
int OPTION_MENU_GetInputCommand(const OptionMenuInput *input);
void OPTION_MENU_GetInputPoint(const OptionMenuInput *input, int which, OptionMenuPoint *out);
void OPTION_MENU_InitTextBox(OptionMenuTextBox *box, struct BmpWindow *window, struct GfFont *font, struct MsgBank *msgBank, struct TaskList *taskList, struct PrintSys *printSys, u16 heapId);
void OPTION_MENU_ExitTextBox(OptionMenuTextBox *box);
void OPTION_MENU_PrintText(OptionMenuTextBox *box, u32 messageId, u32 wait, u32 useStream);
void OPTION_MENU_PrintTextFromBank(OptionMenuTextBox *box, struct MsgBank *msgBank, u32 messageId, u32 wait, u32 useStream);
int OPTION_MENU_IsTextDone(OptionMenuTextBox *box);
void OPTION_MENU_InitButtons(OptionMenuButtons *buttons, struct Unit *unit, struct GfFont *font, struct PrintSys *printSys, struct MsgBank *msgBank, struct TaskMenuRes *menuRes, struct GameData *gameData, u16 heapId);
void OPTION_MENU_ExitButtons(OptionMenuButtons *buttons);
void OPTION_MENU_UpdateButtons(OptionMenuButtons *buttons, const OptionMenuInput *input, const OptionMenuList *list);
void OPTION_MENU_UpdateButtonWindows(OptionMenuButtons *buttons);
int OPTION_MENU_GetButtonChoice(OptionMenuButtons *buttons, int *choice);
u32 OPTION_MENU_IsButtonFinished(OptionMenuButtons *buttons);
void OPTION_MENU_ResetButtons(OptionMenuButtons *buttons);
void OPTION_MENU_CreateButtonWindows(OptionMenuButtons *buttons, u16 heapId);
int OPTION_MENU_HasButtonFocusChanged(OptionMenuButtons *buttons);
void OPTION_MENU_InitList(OptionMenuList *list, u16 mainLayer, u16 subLayer, OptionMenuScreen *screen, const OptionSettings *settings, u32 heapId);
void OPTION_MENU_ExitList(OptionMenuList *list);
void OPTION_MENU_UpdateList(OptionMenuList *list, const OptionMenuInput *input, OptionMenuTextBox *helpText, OptionMenuScreen *screen, OptionMenuButtons *buttons);
void OPTION_MENU_ClearListHighlight(OptionMenuList *list, OptionMenuScreen *screen);
int OPTION_MENU_GetListCursor(const OptionMenuList *list);
void OPTION_MENU_GetListSettings(const OptionMenuList *list, OptionSettings *out);
void OPTION_MENU_RedrawList(OptionMenuList *list, int unused);
void OPTION_MENU_SetListButtonMode(OptionMenuList *list, u8 value);
void OPTION_MENU_DrawList(OptionMenuList *list, int highlight);
void OPTION_MENU_ScrollList(OptionMenuList *list, int delta, int min, int max);
void OPTION_MENU_SelectChoiceAtTouch(OptionMenuList *list, const OptionMenuPoint *touch);
void OPTION_MENU_ApplySoundMode(OptionMenuList *list, u32 soundMode, u32 force);
void OPTION_MENU_StepSelectedSetting(OptionMenuList *list, int delta);
int OPTION_MENU_GetRowAtTouch(OptionMenuList *list, const OptionMenuPoint *touch);
void OPTION_MENU_ShiftInputTrail(OptionMenuList *list);
void OPTION_MENU_InitMessageBox(OptionMenuMessageBox *box, struct BmpWindow *window, struct GfFont *font, struct MsgBank *msgBank, struct TaskList *taskList, struct TaskMenuRes *menuRes, struct PrintSys *printSys, u16 heapId);
void OPTION_MENU_ExitMessageBox(OptionMenuMessageBox *box);
void OPTION_MENU_UpdateMessageBox(OptionMenuMessageBox *box);
void OPTION_MENU_PrintDiscardPrompt(OptionMenuMessageBox *box, u32 wait);
u16 OPTION_MENU_GetMessageBoxAnswer(const OptionMenuMessageBox *box);
void OPTION_MENU_PrintHelpMessage(OptionMenuMessageBox *box, u32 messageId, u32 wait);
void OPTION_MENU_PrintMessage(OptionMenuMessageBox *box, u32 messageId, u32 wait);
int OPTION_MENU_IsMessageDone(OptionMenuMessageBox *box);
void OPTION_MENU_InitSettings(OptionSettings *settings, struct Config *config);
void OPTION_MENU_ExitSettings(OptionSettings *settings);
void OPTION_MENU_WriteSettings(const OptionSettings *settings);
void OPTION_MENU_SelectChoice(OptionSettings *settings, int choiceIndex);
void OPTION_MENU_StepSetting(OptionSettings *settings, int row, int delta);
int OPTION_MENU_IsChoiceSelected(const OptionSettings *settings, int choiceIndex);
u32 OPTION_MENU_GetTextSpeedWait(const OptionSettings *settings);
int OPTION_MENU_TakeChangedSetting(OptionSettings *settings);
int OPTION_MENU_AreSettingsEqual(const OptionSettings *a, const OptionSettings *b);
void OPTION_MENU_InitRunner(OptionMenuRunner *runner, OptionMenuWork *work, OptionMenuStateFn callback);
void OPTION_MENU_ExitRunner(OptionMenuRunner *runner);
void OPTION_MENU_UpdateRunner(OptionMenuRunner *runner);
int OPTION_MENU_IsRunnerFinished(OptionMenuRunner *runner);
void OPTION_MENU_SetRunnerState(OptionMenuRunner *runner, OptionMenuStateFn callback);
void OPTION_MENU_FinishRunner(OptionMenuRunner *runner);
void OPTION_MENU_StateFadeIn(OptionMenuRunner *runner, u32 *state, OptionMenuWork *work);
void OPTION_MENU_StateFadeOut(OptionMenuRunner *runner, u32 *state, OptionMenuWork *work);
void OPTION_MENU_StateMain(OptionMenuRunner *runner, u32 *state, OptionMenuWork *work);
void OPTION_MENU_StateDiscardPrompt(OptionMenuRunner *runner, u32 *state, OptionMenuWork *work);
void OPTION_MENU_StateKeepSaved(OptionMenuRunner *runner, u32 *state, OptionMenuWork *work);
void OPTION_MENU_StateApply(OptionMenuRunner *runner, u32 *state, OptionMenuWork *work);
int OPTION_MENU_IsPointInRect(const OptionMenuRect *rect, const OptionMenuPoint *point);

extern u8 ov067_id[];
extern struct DispVram gOptionMenuDispVram;
extern struct DispConfig gOptionMenuDispConfig;
extern OptionMenuBgLayer gOptionMenuBgLayers[];
#if LANGUAGE == LANGUAGE_JAPANESE
extern const OptionMenuLabel gOptionMenuLabels[];
#else
extern OptionMenuLabel gOptionMenuLabels[];
#endif
extern s16 FX_SinCosTable_[];
extern struct ClInitParam gClActorInitParam;
extern OptionMenuChoice gOptionMenuChoices[];
extern ReturnButtonCells gOptionMenuReturnButtonCells;
extern OptionMenuRect gOptionMenuConfirmRect;
extern OptionMenuRect gOptionMenuCancelRect;
/*
 * The setting row table at 0x021BB570 and the choice table at 0x021BB704 are
 * each reached through several symbols in the original: the offsets 0, 2 and
 * 4 of a row (8 bytes) and the value member (offset 4) of a choice (24 bytes)
 * are separate pool entries, so each stays its own extern.
 */
extern const OptionMenuSettingRow gOptionMenuSettingRows[];
extern u16 gOptionMenuSettingRowChoiceCount[][4];
extern u8 gOptionMenuSettingRowChoices[][8];
extern u32 gOptionMenuChoiceValues[][6];
extern const u8 gOptionMenuRowPalettes[];

/* Proc init: allocates the work and builds every part of the screen. */
int OPTION_MENU_Init(struct Proc *proc, int *seq, OptionMenuArgs *args)
{
    OptionMenuWork *work;
    struct GameData *gameData;

    GF_OVERLAY_Load((uptr)ov067_id);
    GFL_HEAP_CreateChildHeap(1, 0x1c, 0x21000);
    work = PROCSYS_AllocProcWork(proc, sizeof(OptionMenuWork), 0x1c);
    MI_CpuFill8(work, 0, sizeof(OptionMenuWork));
    work->args = args;
    work->args->result = 0;
    OPTION_MENU_InitScreen(&work->screen, 0x1c);
    work->font = GF_FONT_Create(0x17, 0, 0, 0, 0x1c);
    work->printSys = (struct PrintSys *)PRINTSYS_QUE_Create(0x1c);
    work->buttonMenuRes = APP_TASKMENU_RES_Create(0, 0xd, (struct GFont *)work->font, (struct PrintQueue *)work->printSys, 0x1c);
    work->messageMenuRes = APP_TASKMENU_RES_Create(3, 9, (struct GFont *)work->font, (struct PrintQueue *)work->printSys, 0x1c);
    work->msgBank = MSGDATA_CreateFromArchive(0, 2, OPTION_MENU_MSG_FILE, 0x1c);
    work->taskList = (struct TaskList *)TCBL_Create(0x1c, 0x1c, 0x20, 0x20);
    OPTION_MENU_InitSettings(&work->savedSettings, SYSTEM_DATA_GetConfig((struct SaveData *)GAME_DATA_GetSaveControl(GAMESYSTEM_GetGameData(work->args->gameSystem))));
    OPTION_MENU_InitRunner(&work->runner, work, OPTION_MENU_StateFadeIn);
    gameData = GAMESYSTEM_GetGameData(work->args->gameSystem);
    OPTION_MENU_InitButtons(&work->buttons, OPTION_MENU_GetScreenSpriteUnit(&work->screen), work->font, work->printSys, work->msgBank, work->buttonMenuRes, gameData, 0x1c);
    OPTION_MENU_InitList(&work->list, 1, 2, &work->screen, &work->savedSettings, 0x1c);
    OPTION_MENU_InitInput(&work->input, 0x1c);
    OPTION_MENU_InitTextBox(&work->helpText, OPTION_MENU_GetScreenWindow(&work->screen, OPTION_WINDOW_DESCRIPTION), work->font, work->msgBank, work->taskList, work->printSys, 0x1c);
    OPTION_MENU_InitMessageBox(&work->messageBox, OPTION_MENU_GetScreenWindow(&work->screen, OPTION_WINDOW_MESSAGE), work->font, work->msgBank, work->taskList, work->messageMenuRes, work->printSys, 0x1c);
    return 1;
}

int OPTION_MENU_Exit(struct Proc *proc, int *seq, void *args, OptionMenuWork *work)
{
    OPTION_MENU_ExitMessageBox(&work->messageBox);
    OPTION_MENU_ExitTextBox(&work->helpText);
    OPTION_MENU_ExitInput(&work->input);
    OPTION_MENU_ExitList(&work->list);
    OPTION_MENU_ExitButtons(&work->buttons);
    OPTION_MENU_ExitRunner(&work->runner);
    OPTION_MENU_ExitSettings(&work->savedSettings);
    TCBL_Destroy((struct TcblSystem *)work->taskList);
    MSGDATA_Delete(work->msgBank);
    APP_TASKMENU_RES_Delete(work->messageMenuRes);
    APP_TASKMENU_RES_Delete(work->buttonMenuRes);
    PRINTSYS_QUE_Delete((struct PrintQueue *)work->printSys);
    GF_FONT_Delete(work->font);
    OPTION_MENU_ExitScreen(&work->screen);
    PROCSYS_FreeProcWork(proc);
    GFL_HEAP_DeleteChecked(0x1c);
    GF_OVERLAY_Unload((sptr)ov067_id);
    return 1;
}

int OPTION_MENU_Main(struct Proc *proc, int *seq, void *args, OptionMenuWork *work)
{
    OPTION_MENU_UpdateRunner(&work->runner);
    OPTION_MENU_UpdateScreen(&work->screen);
    PRINTSYS_QUE_Main((struct PrintQueue *)work->printSys);
    TCBL_Main((struct TcblSystem *)work->taskList);
    OPTION_MENU_UpdateButtonWindows(&work->buttons);
    if (OPTION_MENU_IsRunnerFinished(&work->runner) != 0)
        return 1;
    return 0;
}

void OPTION_MENU_InitScreen(OptionMenuScreen *screen, u16 heapId)
{
    MI_CpuFill8(screen, 0, sizeof(OptionMenuScreen));
    REG_A_BLDCNT = 0;
    REG_B_BLDCNT = 0;
    REG_A_DISPCNT &= DISPCNT_WINDOWS_OFF;
    REG_B_DISPCNT &= DISPCNT_WINDOWS_OFF;
    BG_SYS_ClearGraphicsMemory(0);
    BG_SYS_SetVramBanks(&gOptionMenuDispVram);
    BG_SYS_SetLcdSwap(0);
    BG_SYS_ResetSubDisplay();
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    GF_FONT_InitTextColor();
    GF_FONT_SetTextColor(0xf, 0xe, 0);
    OPTION_MENU_InitGfx(&screen->gfx, heapId);
    OPTION_MENU_InitSprites(&screen->sprites, &gOptionMenuDispVram, heapId);
    screen->task = (struct Task *)GFL_USE_AddMainTask(OPTION_MENU_ScreenTaskMain, screen, 0);
}

void OPTION_MENU_ExitScreen(OptionMenuScreen *screen)
{
    TCB_DeleteTask((struct TcbTask *)screen->task);
    OPTION_MENU_ExitSprites(&screen->sprites);
    OPTION_MENU_ExitGfx(&screen->gfx);
    GF_FONT_SetDefaultTextColor();
    REG_A_BLDCNT = 0;
    REG_B_BLDCNT = 0;
    REG_A_DISPCNT &= DISPCNT_WINDOWS_OFF;
    REG_B_DISPCNT &= DISPCNT_WINDOWS_OFF;
    MI_CpuFill8(screen, 0, sizeof(OptionMenuScreen));
}

void OPTION_MENU_UpdateScreen(OptionMenuScreen *screen)
{
    OPTION_MENU_UpdateSprites(&screen->sprites);
    OPTION_MENU_UpdateGfxBlink(&screen->gfx);
}

struct ClactActor *OPTION_MENU_GetScreenSpriteActor(OptionMenuScreen *screen, int index)
{
    return OPTION_MENU_GetSpriteActor(&screen->sprites, index);
}

struct Unit *OPTION_MENU_GetScreenSpriteUnit(OptionMenuScreen *screen)
{
    return OPTION_MENU_GetSpriteUnit(&screen->sprites);
}

struct BmpWindow *OPTION_MENU_GetScreenWindow(OptionMenuScreen *screen, int index)
{
    return OPTION_MENU_GetGfxWindow(&screen->gfx, index);
}

#if LANGUAGE == LANGUAGE_JAPANESE
void OPTION_MENU_CreateScreenLabels(OptionMenuScreen *screen)
{
    OPTION_MENU_CreateLabelWindows(&screen->gfx);
}

#endif
void OPTION_MENU_RestartScreenBlink(OptionMenuScreen *screen)
{
    OPTION_MENU_RestartGfxBlink(&screen->gfx);
}

/* Per frame task of the screen: background transfer, then actor drawing. */
void OPTION_MENU_ScreenTaskMain(struct Task *task, OptionMenuScreen *screen)
{
    OPTION_MENU_FlushGfx(&screen->gfx);
    OPTION_MENU_DrawSprites(&screen->sprites);
}

/*
 * note 2026-10-05 (recoup R14): ARC_UTIL_UploadBgCharFromHandle returns u32 (as in ov210 021BC5DC); declared void it
 *   made the build copy the zero from r5 (adds rN,r5,#0) for the register zero arguments after
 *   02049BDC. EXACT in c99 and c with the u32 return.
 */
void OPTION_MENU_InitGfx(OptionMenuGfx *gfx, u16 heapId)
{
    void *arc;
    void *buffer;
    OptionMenuPaletteResource *pltt;
    int i;
    u32 layerId;

    MI_CpuFill8(gfx, 0, sizeof(OptionMenuGfx));
    BG_SYS_Create(heapId);
    BMP_WIN_Init(heapId);
    BG_SYS_SetGraphicsMode(&gOptionMenuDispConfig);
    for (i = 0; i < 6; i++) {
        layerId = gOptionMenuBgLayers[i].layerId;
        BG_SYS_InitBgLayer((u8)layerId, &gOptionMenuBgLayers[i].layout, (u8)gOptionMenuBgLayers[i].mapType);
        BG_SYS_FreeSlot(layerId);
        BG_SYS_SetPlaneVisible(layerId, 1);
    }
    BG_SYS_SetPlaneVisible(3, 0);
    BG_SYS_Init(4, 0, 1, 0);
    BG_SYS_Init(3, 0, 1, 0);
    arc = ARC_TOOL_CreateHandle(0x1b, heapId);
    ARC_UTIL_UploadPaletteFromHandleWhole(arc, OPTION_ARC_ID(1), 0, 0, 0, heapId);
    ARC_UTIL_UploadBgCharFromHandle(arc, OPTION_ARC_ID(0xd), 0, 0, 0, 0, heapId);
    ARC_UTIL_UploadBgPaletteFromHandle(arc, OPTION_ARC_ID(0xe), 0, 0, 0, 0, heapId);
    ARC_UTIL_UploadBgCharFromHandle(arc, OPTION_ARC_ID(0), 2, 0, 0, 0, heapId);
    ARC_UTIL_UploadBgPaletteFromHandle(arc, OPTION_ARC_ID(2), 2, 0, 0, 0, heapId);
    ARC_UTIL_UploadBgCharFromHandle(arc, OPTION_ARC_ID(0x10), 3, 1, 0, 0, heapId);
    ARC_UTIL_UploadPaletteFromHandle(arc, OPTION_ARC_ID(8), 0, 0x80, 0x1e0, 0x20, heapId);
    gfx->screenBuffer = ARC_UTIL_LoadBgCharDataFromHandle((void *)arc, (u32)OPTION_ARC_ID(0xf), (u32)0, (&gfx->screenData), heapId);
    ARC_UTIL_UploadPaletteFromHandleWhole(arc, OPTION_ARC_ID(8), 4, 0, 0, heapId);
    ARC_UTIL_UploadBgCharFromHandle(arc, OPTION_ARC_ID(7), 5, 0, 0, 0, heapId);
    ARC_UTIL_UploadBgPaletteFromHandle(arc, OPTION_ARC_ID(9), 5, 0, 0, 0, heapId);
    ARC_UTIL_UploadBgCharFromHandle(arc, OPTION_ARC_ID(0x10), 4, 1, 0, 0, heapId);
    ARC_TOOL_DeleteHandle(arc);
    buffer = ARC_UTIL_LoadPaletteBlockFromArchive((u32)0x1b, (u32)OPTION_ARC_ID(1), (&pltt), heapId);
    MI_CpuCopy8(pltt->colors + 0xe0, gfx->palette, 0x20);
    GFL_HEAP_Free(buffer);
#if LANGUAGE == LANGUAGE_JAPANESE
    for (i = 0; i < OPTION_WINDOW_LABEL_COUNT; i++) {
        const OptionMenuLabel *label = &gOptionMenuLabels[i];

        gfx->windows[i] = (struct BmpWindow *)BMP_WIN_Create(1, label->x, label->y, label->width, label->height, 0, 1);
    }
#endif
    gfx->windows[OPTION_WINDOW_DESCRIPTION] = (struct BmpWindow *)BMP_WIN_Create(4, 1, 0x13, 0x1e, 4, 4, 1);
    gfx->windows[OPTION_WINDOW_MESSAGE] = (struct BmpWindow *)BMP_WIN_Create(3, 1, 1, 0x1e, 4, 0xf, 1);
    gfx->windows[OPTION_WINDOW_TITLE] = (struct BmpWindow *)BMP_WIN_Create(0, 0, 0, 0x10, 3, 8, 1);
    OPTION_MENU_CreateLabelWindows(gfx);
    BG_SYS_SetPlaneVisible(4, 0);
}

void OPTION_MENU_ExitGfx(OptionMenuGfx *gfx)
{
    int i;

    for (i = 0; i < OPTION_WINDOW_COUNT; i++) {
        if (gfx->windows[i] != 0) {
            BMP_WIN_Delete((struct BmpWin *)gfx->windows[i]);
        }
    }
    GFL_HEAP_Free(gfx->screenBuffer);
    BG_SYS_FreeTiles(4, 1, 0);
    i = 0;
    BG_SYS_FreeTiles(3, 1, 0);
    for (i = 0; i < 6; i++) {
        BG_SYS_FreeLayerBuf((u8)gOptionMenuBgLayers[i].layerId);
    }
    BMP_WIN_Exit();
    BG_SYS_Delete();
    MI_CpuFill8(gfx, 0, sizeof(OptionMenuGfx));
}

/* Cross-fades the highlight colour (palette entries 11 and 12). */
void OPTION_MENU_UpdateGfxBlink(OptionMenuGfx *gfx)
{
    BLINK_PALANM_BlendStep(&gfx->blinkColor, &gfx->blinkAngle, 0x400, 7, 1,
                 gfx->palette[11], gfx->palette[12]);
}

struct BmpWindow *OPTION_MENU_GetGfxWindow(OptionMenuGfx *gfx, int index)
{
    return gfx->windows[index];
}

/*
 * The rounded width goes through a u8 local that is both stored to the
 * table row and passed on (the call reloading the field is 4 bytes longer).
 * PRINTSYS_MeasureWidestLine takes the string first and the font second.
 */
void OPTION_MENU_CreateLabelWindows(OptionMenuGfx *gfx)
{
    struct GfFont *font;
    struct MsgBank *msgBank;
    struct Strbuf *str;
    struct BmpWindow *window;
    u8 *charData;
    int i;
    int x;
#if LANGUAGE != LANGUAGE_JAPANESE
    OptionMenuLabel *label;
    u8 width;
#endif

    font = GF_FONT_Create(0x17, 0, 0, 0, 0x1c);
    msgBank = MSGDATA_CreateFromArchive(0, 2, OPTION_MENU_MSG_FILE, 0x1c);
    for (i = 0; i < OPTION_WINDOW_LABEL_COUNT; i++) {
        x = 0;
        switch (i) {
        case 0:
            x = 7;
            break;
        case 1:
            x = 4;
            break;
        case 2:
            x = 2;
            break;
        }
#if LANGUAGE == LANGUAGE_JAPANESE
        str = MSGDATA_AllocString(msgBank, gOptionMenuLabels[i].messageId);
#else
        label = &gOptionMenuLabels[i];
        str = MSGDATA_AllocString(msgBank, gOptionMenuLabels[i].messageId);
        width = (x + PRINTSYS_MeasureWidestLine(str, font, 0) + 7) >> 3;
        label->width = width;
        gfx->windows[i] = (struct BmpWindow *)BMP_WIN_Create(1, label->x, label->y, width, label->height, 0, 1);
#endif
        BMP_Clear((struct Bmp *)(BMP_WIN_GetBmp((struct BmpWin *)gfx->windows[i])), 0);
        PRINTSYS_Print((struct Bmp *)(BMP_WIN_GetBmp((struct BmpWin *)gfx->windows[i])), x, 0, str, font);
        window = gfx->windows[i];
        BMP_WIN_TransferChars((struct BmpWin *)window);
        BMP_WIN_MakeScreen((struct BmpWin *)window);
        BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer((struct BmpWin *)window));
        STRBUF_Delete(str);
    }
    charData = gfx->screenData->charData;
    MIi_CpuCopy32((uptr)charData, (uptr)BMP_GetPixels((struct Bmp *)(BMP_WIN_GetBmp((struct BmpWin *)gfx->windows[OPTION_WINDOW_TITLE]))), 0x600);
    str = MSGDATA_AllocString(msgBank, 0);
    x = BMP_WIN_GetWidth((struct BmpWin *)gfx->windows[OPTION_WINDOW_TITLE]) * 4;
    x -= PRINTSYS_MeasureWidestLine(str, font, 0) >> 1;
    PRINTSYS_PrintColor((struct Bmp *)(BMP_WIN_GetBmp((struct BmpWin *)gfx->windows[OPTION_WINDOW_TITLE])), x, 4, str, font, 0x3dc1);
    window = gfx->windows[OPTION_WINDOW_TITLE];
    BMP_WIN_TransferChars((struct BmpWin *)window);
    BMP_WIN_MakeScreen((struct BmpWin *)window);
    BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer((struct BmpWin *)window));
    STRBUF_Delete(str);
    MSGDATA_Delete(msgBank);
    GF_FONT_Delete(font);
}

/* Restarts the highlight cross-fade. */
void OPTION_MENU_RestartGfxBlink(OptionMenuGfx *gfx)
{
    gfx->blinkAngle = 0;
}

void OPTION_MENU_FlushGfx(OptionMenuGfx *gfx)
{
    BG_SYS_Update();
}

/*
 * BGR555 cross-fade of one palette entry: advance the u16 phase at *angle by
 * step (wrapping at 0x10000), take weight = (table[phase >> 4 pair, second entry]
 * + 0x1000) / 2 as an s16 from the table at 0x020A1B38, blend each channel
 * of color0 toward color1 by weight >> 12, store to *outColor and hand it to NNS_GfdRegisterNewVramTransferTask.
 * Twin: arm9 BLINK_PALANM_Update (blink_palanm.c).  What closed it: all six
 * channels as u8 locals extracted in mask-then-shift form, the blended
 * channels as s32 with a u8 cast, and the pack `(b << 10) | (r | (g << 5))`
 * (the channel ORed last is evaluated first: blue, red, green).  Shift-then-
 * mask extraction, or the unnested pack, compiles 184 bytes.
 */
void BLINK_PALANM_BlendStep(u16 *outColor, u16 *angle, int step, u32 paletteIndex, u8 slot, u16 color0, u16 color1)
{
    int next;
    s16 weight;
    u8 r0, g0, b0, r1, g1, b1;
    s32 r, g, b;

    next = *angle + step;
    if (next >= 0x10000) {
        *angle = next - 0x10000;
    } else {
        *angle = next;
    }
    weight = (FX_SinCosTable_[((*angle >> 4) << 1) + 1] + 0x1000) / 2;
    r0 = color0 & 0x1f;
    g0 = (color0 & 0x3e0) >> 5;
    b0 = (color0 & 0x7c00) >> 10;
    r1 = color1 & 0x1f;
    g1 = (color1 & 0x3e0) >> 5;
    b1 = (color1 & 0x7c00) >> 10;
    b = (u8)(b0 + (((b1 - b0) * weight) >> 12));
    r = (u8)(r0 + (((r1 - r0) * weight) >> 12));
    g = (u8)(g0 + (((g1 - g0) * weight) >> 12));
    *outColor = (u16)((b << 10) | (r | (g << 5)));
    NNS_GfdRegisterNewVramTransferTask(15, (u32)(paletteIndex * 32 + slot * 2), outColor, 2);
}

void OPTION_MENU_InitSprites(OptionMenuSprites *sprites, const void *res, u32 heapId)
{
    ClActorParam param;
    void *arc;
    int i;

    MI_CpuFill8(sprites, 0, sizeof(OptionMenuSprites));
    CLACT_InitSystem((struct ClactSysInit *)(&gClActorInitParam), (struct DispVramCfg *)res, heapId);
    sprites->unit = CLACT_CreateUnit(0x80, 0, heapId);
    CLACT_SetUnitDefaultRenderer(sprites->unit);
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
    arc = ARC_TOOL_CreateHandle(0x1b, heapId);
    sprites->plttRes = CLACT_RegisterPalette(arc, OPTION_SPR_PLTT, 0, 0, heapId);
    sprites->mainCharRes = CLACT_RegisterCharacter(arc, OPTION_SPR_MAIN_CHAR, 0, 0, heapId);
    sprites->mainCellRes = CLACT_RegisterCellAnim(arc, OPTION_SPR_MAIN_CELL, OPTION_SPR_MAIN_ANIM, heapId);
    sprites->subCharRes = CLACT_RegisterCharacter(arc, OPTION_SPR_SUB_CHAR, 0, 0, heapId);
    sprites->subCellRes = CLACT_RegisterCellAnim(arc, OPTION_SPR_SUB_CELL, OPTION_SPR_SUB_ANIM, heapId);
    ARC_TOOL_DeleteHandle(arc);
    MI_CpuFill8(&param, 0, 8);
    param.bgPriority = 2;
    param.priority = 2;
    for (i = OPTION_ACTOR_CHOICE_FIRST; i < OPTION_ACTOR_CHOICE_FIRST + OPTION_ACTOR_CHOICE_COUNT; i++) {
        param.x = gOptionMenuChoices[i - 2].actorX;
        param.y = gOptionMenuChoices[i - 2].actorY;
        sprites->actors[i] = CLACT_CreateActor(sprites->unit, sprites->mainCharRes, sprites->plttRes, sprites->mainCellRes, (struct ActorInitParam *)(&param), 0, heapId);
        CLACT_SetActorAutoAnim((struct ClactActor *)sprites->actors[i], 0);
    }
    MI_CpuFill8(&param, 0, 8);
    param.x = 0x80;
    param.y = 0x60;
    param.bgPriority = 2;
    param.priority = 1;
    sprites->actors[OPTION_ACTOR_CURSOR] = CLACT_CreateActor(sprites->unit, sprites->subCharRes, sprites->plttRes, sprites->subCellRes, (struct ActorInitParam *)(&param), 0, heapId);
    CLACT_SetActorPaletteOffset((struct ClactActor *)sprites->actors[OPTION_ACTOR_CURSOR], 6, 1);
    if (GFL_NET_GetRunState())
        GFL_NET_RefreshWmIconAtTopRight(1, heapId);
}

void OPTION_MENU_ExitSprites(OptionMenuSprites *sprites)
{
    int i;

    for (i = 0; i < OPTION_ACTOR_COUNT; i++) {
        if (sprites->actors[i] != 0) {
            CLACT_DeleteActor((struct ClactActor *)sprites->actors[i]);
        }
    }
    CLACT_ReleasePalette(sprites->plttRes);
    CLACT_ReleaseCharacter(sprites->mainCharRes);
    CLACT_ReleaseCellAnim(sprites->mainCellRes);
    CLACT_ReleaseCharacter(sprites->subCharRes);
    CLACT_ReleaseCellAnim(sprites->subCellRes);
    CLACT_DeleteUnit(sprites->unit);
    CLACT_ExitSystem();
    MI_CpuFill8(sprites, 0, sizeof(OptionMenuSprites));
}

/* Steps the choice animation frame (wraps after 0x60) and draws the actors. */
void OPTION_MENU_UpdateSprites(OptionMenuSprites *sprites)
{
    int i;
    u16 frame;

    frame = (sprites->animFrame)++;
    if (frame > 0x60) {
        sprites->animFrame = 0;
    }
    for (i = OPTION_ACTOR_CHOICE_FIRST; i < OPTION_ACTOR_CHOICE_FIRST + OPTION_ACTOR_CHOICE_COUNT; i++) {
        CLACT_SetActorAnimIndex((struct ClactActor *)sprites->actors[i], (u16)(sprites->animFrame / 12));
    }
    CLACT_DrawSystem();
}

void OPTION_MENU_DrawSprites(OptionMenuSprites *sprites) { CLACT_VBlankSystem(); }

struct ClactActor *OPTION_MENU_GetSpriteActor(OptionMenuSprites *sprites, int index)
{
    return sprites->actors[index];
}

struct Unit *OPTION_MENU_GetSpriteUnit(OptionMenuSprites *sprites)
{
    return sprites->unit;
}

/*
 * Two identical wrappers around MI_CpuFill8(p, 0, 0x20).
 */
void OPTION_MENU_InitInput(OptionMenuInput *input, int heapId)
{
    MI_CpuFill8(input, 0, sizeof(OptionMenuInput));
}

void OPTION_MENU_ExitInput(OptionMenuInput *input)
{
    MI_CpuFill8(input, 0, sizeof(OptionMenuInput));
}

/*
 * Touch and key input to a command code in input->command.
 */
void OPTION_MENU_ReadInput(OptionMenuInput *input)
{
    int x;
    int y;
    u32 trigger;
    u32 held;
    int dy;

    input->command = OPTION_INPUT_NONE;
    if (TOUCHPANEL_GetPointTrg((u32 *)(&x), (u32 *)(&y))) {
        input->command = OPTION_INPUT_TOUCH;
        input->startX = x;
        input->startY = y;
        input->lastX = x;
        input->lastY = y;
        input->touching = 1;
    } else if (TOUCHPANEL_GetPointCont((u32 *)(&x), (u32 *)(&y)) && input->touching != 0) {
        dy = y - input->startY;
        if (dy < 0)
            dy = -dy;
        if (dy >= 1) {
            input->command = OPTION_INPUT_DRAG;
            input->dragX = x - input->lastX;
            input->dragY = y - input->lastY;
            input->lastX = x;
            input->lastY = y;
        }
    } else {
        input->touching = 0;
    }
    trigger = KEY_GetTrg();
    held = KEY_GetCont();
    if (trigger != 0 && UI_GetInputMode() == 1 && (trigger & (OPTION_KEY_X | OPTION_KEY_Y | OPTION_KEY_B)) == 0) {
        UI_SetInputMode(0);
        input->command = OPTION_INPUT_KEY_ACTIVATE;
        GFL_USE_PlaySeDefaultVolume(OPTION_SE_CURSOR);
        return;
    }
    if (trigger & OPTION_KEY_UP) {
        input->command = OPTION_INPUT_UP;
        return;
    }
    if (trigger & OPTION_KEY_DOWN) {
        input->command = OPTION_INPUT_DOWN;
        return;
    }
    if (trigger & OPTION_KEY_LEFT) {
        input->command = OPTION_INPUT_LEFT;
        return;
    }
    if (trigger & OPTION_KEY_RIGHT) {
        input->command = OPTION_INPUT_RIGHT;
        return;
    }
    if (held & OPTION_KEY_UP) {
        input->command = OPTION_INPUT_HOLD_UP;
        return;
    }
    if (held & OPTION_KEY_DOWN) {
        input->command = OPTION_INPUT_HOLD_DOWN;
        return;
    }
    if (trigger & OPTION_KEY_A) {
        input->command = OPTION_INPUT_CONFIRM;
        return;
    }
    if (trigger & OPTION_KEY_B) {
        UI_SetInputMode(0);
        input->command = OPTION_INPUT_CANCEL;
        return;
    }
    if (trigger & OPTION_KEY_X) {
        UI_SetInputMode(0);
        input->command = OPTION_INPUT_SHORTCUT_X;
        return;
    }
    if (trigger & OPTION_KEY_Y) {
        UI_SetInputMode(0);
        input->command = OPTION_INPUT_SHORTCUT_Y;
    }
}

int OPTION_MENU_GetInputCommand(const OptionMenuInput *input) { return input->command; }

/* which: 0 = touch start, 1 = drag step, 2 = last touch point. */
void OPTION_MENU_GetInputPoint(const OptionMenuInput *input, int which, OptionMenuPoint *out)
{
    if (out == 0)
        return;
    switch (which) {
    case 0:
        out->x = input->startX;
        out->y = input->startY;
        break;
    case 1:
        out->x = input->dragX;
        out->y = input->dragY;
        break;
    case 2:
        out->x = input->lastX;
        out->y = input->lastY;
        break;
    }
}

void OPTION_MENU_InitTextBox(OptionMenuTextBox *box, struct BmpWindow *window, struct GfFont *font, struct MsgBank *msgBank, struct TaskList *taskList, struct PrintSys *printSys, u16 heapId)
{
    struct BmpWindow *printWindow;

    MI_CpuFill8(box, 0, sizeof(OptionMenuTextBox));
    box->fillColor = 4;
    box->window = window;
    box->heapId = heapId;
    box->font = font;
    box->msgBank = msgBank;
    box->buffer = STRBUF_Create(0xff, heapId);
    box->taskList = taskList;
    box->stream = 0;
    box->printSys = printSys;
    box->mode = 0;
    PRINTSYS_CTRL_Init((struct PrintStreamCtrl *)(&box->waitState), 0x406);
    BMP_MENUWORK_DrawWindow((struct BmpWin *)box->window, 2, 1, BMP_WIN_GetPalette((struct BmpWin *)window));
    BMP_Clear((struct Bmp *)(BMP_WIN_GetBmp((struct BmpWin *)box->window)), (u8)box->fillColor);
    printWindow = box->window;
    BMP_WIN_TransferChars((struct BmpWin *)printWindow);
    BMP_WIN_MakeScreen((struct BmpWin *)printWindow);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer((struct BmpWin *)printWindow));
    box->printWindow = box->window;
    box->printing = 0;
}

void OPTION_MENU_ExitTextBox(OptionMenuTextBox *box)
{
    if (box->stream != 0) {
        PRINTSYS_PrintStreamDelete((struct TextPrinter *)box->stream);
        box->stream = 0;
    }
    STRBUF_Delete(box->buffer);
    MI_CpuFill8(box, 0, sizeof(OptionMenuTextBox));
}

void OPTION_MENU_PrintText(OptionMenuTextBox *box, u32 messageId, u32 wait, u32 useStream)
{
    OPTION_MENU_PrintTextFromBank(box, box->msgBank, messageId, wait, useStream);
}

/* useStream 0 prints at once through the print system, otherwise a print stream runs. */
void OPTION_MENU_PrintTextFromBank(OptionMenuTextBox *box, struct MsgBank *msgBank, u32 messageId, u32 wait, u32 useStream)
{
    struct PrintSys *printSys;

    BMP_Clear((struct Bmp *)(BMP_WIN_GetBmp((struct BmpWin *)box->window)), (u8)box->fillColor);
    MSGDATA_ReadString(msgBank, messageId, box->buffer);
    if (box->stream != 0) {
        PRINTSYS_PrintStreamDelete((struct TextPrinter *)box->stream);
        box->stream = 0;
    }
    if (useStream == 0) {
        printSys = box->printSys;
        PRINTSYS_PrintQue((struct PrintQueue *)printSys, (struct Bmp *)(BMP_WIN_GetBmp((struct BmpWin *)box->printWindow)), 0, 0,
                      box->buffer, box->font);
        box->printing = 1;
        box->mode = 2;
        return;
    }
    box->stream = (struct PrintStream *)PRINTSYS_PrintStream((struct BmpWin *)box->window, 0, 0, box->buffer,
                                box->font, wait, (struct Tcbl *)box->taskList, 0,
                                box->heapId, box->fillColor);
    box->mode = 1;
}

/* Returns 1 when nothing is left to print. */
int OPTION_MENU_IsTextDone(OptionMenuTextBox *box)
{
    struct PrintSys *printSys;

    switch (box->mode) {
    case 0:
    default:
        return 1;
    case 2:
        printSys = box->printSys;
        if (box->printing != 0) {
            if (PRINTSYS_QUE_IsExistTarget((struct PrintQueue *)printSys, (struct Bmp *)(BMP_WIN_GetBmp((struct BmpWin *)box->printWindow))) == 0) {
                BMP_WIN_TransferChars((struct BmpWin *)box->printWindow);
                box->printing = 0;
            }
        }
        if (box->printing == 0) {
            return 1;
        }
        return 0;
    case 1:
        return PRINTSYS_CTRL_Update((struct PrintStreamCtrl *)(&box->waitState), (struct TextPrinter *)box->stream);
    }
}

void OPTION_MENU_InitButtons(OptionMenuButtons *buttons, struct Unit *unit, struct GfFont *font, struct PrintSys *printSys, struct MsgBank *msgBank, struct TaskMenuRes *menuRes, struct GameData *gameData, u16 heapId)
{
    ReturnButtonCells cells;
    TouchBarParams request;

    MI_CpuFill8(buttons, 0, sizeof(OptionMenuButtons));
    buttons->choice = OPTION_BUTTON_NONE;
    buttons->font = font;
    buttons->menuRes = menuRes;
    buttons->msgBank = msgBank;
    buttons->printSys = printSys;
    buttons->gameData = gameData;
    cells = gOptionMenuReturnButtonCells;
    MI_CpuFill8(&request, 0, sizeof(request));
    request.defs = cells.def;
    request.count = 2;
    request.actorSys = (struct Unit *)unit;
    request.actorPlttSlot = 8;
    request.skipBgGfx = 1;
    request.iconSet = 2;
    buttons->returnButton = TOUCHBAR_Create(&request, heapId);
    OPTION_MENU_CreateButtonWindows(buttons, heapId);
    if (GAME_DATA_ContainsRecentId(buttons->gameData, 0x18) != 0) {
        TOUCHBAR_SetButtonToggled(buttons->returnButton, 6, 1);
    } else {
        TOUCHBAR_SetButtonToggled(buttons->returnButton, 6, 0);
    }
}

void OPTION_MENU_ExitButtons(OptionMenuButtons *buttons)
{
    int i;

    TOUCHBAR_Delete(buttons->returnButton);
    for (i = 0; i < 2; i++) {
        STRBUF_Delete(buttons->items[i].str);
        APP_TASKMENU_WIN_Delete(buttons->buttons[i]);
    }
    MI_CpuFill8(buttons, 0, sizeof(OptionMenuButtons));
}

/* Handles the confirm and cancel buttons and the return button for one frame. */
void OPTION_MENU_UpdateButtons(OptionMenuButtons *buttons, const OptionMenuInput *input, const OptionMenuList *list)
{
    int command;
    int refresh;
    int cursor;
    int result;
    OptionMenuPoint touch;

    refresh = 0;
    buttons->focusChanged = 0;
    if (buttons->decided != 0)
        command = OPTION_INPUT_NONE;
    else
        command = OPTION_MENU_GetInputCommand(input);
    cursor = OPTION_MENU_GetListCursor(list);
    switch (command) {
    case OPTION_INPUT_NONE:
    case OPTION_INPUT_DRAG:
    case 2:
    case OPTION_INPUT_SHORTCUT_X:
    case OPTION_INPUT_SHORTCUT_Y:
        break;
    case OPTION_INPUT_KEY_ACTIVATE:
        return;
    case OPTION_INPUT_TOUCH:
        OPTION_MENU_GetInputPoint(input, 0, &touch);
        if (OPTION_MENU_IsPointInRect(&gOptionMenuConfirmRect, &touch) && buttons->choice != OPTION_BUTTON_CONFIRM) {
            BG_SYS_SetPlaneVisible(4, 0);
            GFL_USE_PlaySeDefaultVolume(OPTION_SE_CONFIRM);
            buttons->choice = OPTION_BUTTON_CONFIRM;
            buttons->decided = 1;
            buttons->focusChanged = 1;
            if (UI_GetInputMode() == 0)
                UI_SetInputMode(1);
        } else if (OPTION_MENU_IsPointInRect(&gOptionMenuCancelRect, &touch) && buttons->choice != OPTION_BUTTON_CANCEL) {
            BG_SYS_SetPlaneVisible(4, 0);
            GFL_USE_PlaySeDefaultVolume(OPTION_SE_CANCEL);
            buttons->choice = OPTION_BUTTON_CANCEL;
            buttons->decided = 1;
            buttons->focusChanged = 1;
            if (UI_GetInputMode() == 0)
                UI_SetInputMode(1);
        } else if (buttons->choice != OPTION_BUTTON_NONE) {
            buttons->choice = OPTION_BUTTON_NONE;
        }
        refresh = 1;
        break;
    case OPTION_INPUT_UP:
    case OPTION_INPUT_DOWN:
    case OPTION_INPUT_RIGHT:
    case OPTION_INPUT_LEFT:
    case OPTION_INPUT_HOLD_UP:
    case OPTION_INPUT_HOLD_DOWN:
        switch (cursor) {
        case OPTION_CURSOR_CONFIRM:
            buttons->choice = OPTION_BUTTON_CONFIRM;
            break;
        case OPTION_CURSOR_CANCEL:
            buttons->choice = OPTION_BUTTON_CANCEL;
            break;
        default:
            buttons->choice = OPTION_BUTTON_NONE;
            break;
        }
        refresh = 1;
        break;
    case OPTION_INPUT_CONFIRM:
        if (buttons->choice != OPTION_BUTTON_NONE) {
            if (buttons->choice == OPTION_BUTTON_CANCEL)
                GFL_USE_PlaySeDefaultVolume(OPTION_SE_CANCEL);
            else
                GFL_USE_PlaySeDefaultVolume(OPTION_SE_CONFIRM);
            refresh = 1;
            buttons->decided = 1;
        } else {
            buttons->choice = OPTION_BUTTON_CONFIRM;
            GFL_USE_PlaySeDefaultVolume(OPTION_SE_CONFIRM);
            refresh = 1;
            buttons->decided = 1;
        }
        break;
    case OPTION_INPUT_CANCEL:
        GFL_USE_PlaySeDefaultVolume(OPTION_SE_CANCEL);
        refresh = 1;
        buttons->choice = OPTION_BUTTON_CANCEL;
        buttons->decided = 1;
        break;
    }
    if (refresh) {
        if (buttons->choice == OPTION_BUTTON_NONE) {
            APP_TASKMENU_WIN_SetActive(buttons->buttons[0], 0);
            APP_TASKMENU_WIN_SetActive(buttons->buttons[1], 0);
        } else if (buttons->decided != 0) {
            APP_TASKMENU_WIN_SetActive(buttons->buttons[buttons->choice], 0);
            APP_TASKMENU_WIN_SetDecide(buttons->buttons[buttons->choice], 1);
            APP_TASKMENU_WIN_SetActive(buttons->buttons[buttons->choice ^ 1], 0);
        } else {
            APP_TASKMENU_WIN_SetActive(buttons->buttons[buttons->choice], 1);
            APP_TASKMENU_WIN_SetActive(buttons->buttons[buttons->choice ^ 1], 0);
        }
    }
    if (buttons->decided == 0) {
        TOUCHBAR_Update(buttons->returnButton);
        result = TOUCHBAR_GetPressedButtonIdIfPressing(buttons->returnButton);
        if (result != 0) {
            if (result == 6 && UI_GetInputMode() == 1)
                buttons->focusChanged = 1;
        } else {
            if (UI_GetInputMode() == 1)
                buttons->focusChanged = 1;
        }
        result = TOUCHBAR_GetPressedButtonIdIfDone(buttons->returnButton);
        if (result != 0) {
            if (result == 6) {
                if (TOUCHBAR_IsButtonToggled(buttons->returnButton, 6))
                    GAME_DATA_SetRecentId(buttons->gameData, 0x18, 1);
                else
                    GAME_DATA_SetRecentId(buttons->gameData, 0x18, 0);
                buttons->choice = OPTION_BUTTON_NONE;
            }
        } else {
            buttons->choice = OPTION_BUTTON_RETURN;
            buttons->decided = 1;
        }
    }
}

void OPTION_MENU_UpdateButtonWindows(OptionMenuButtons *buttons)
{
    int i;

    for (i = 0; i < 2; i++) {
        APP_TASKMENU_WIN_Update(buttons->buttons[i]);
    }
}

/* Returns whether a button was pressed; the choice goes to *choice if given. */
int OPTION_MENU_GetButtonChoice(OptionMenuButtons *buttons, int *choice)
{
    if (choice != 0)
        *choice = buttons->choice;
    return buttons->decided;
}

/* Returns whether the pressed button finished its animation, and resets the buttons then. */
u32 OPTION_MENU_IsButtonFinished(OptionMenuButtons *buttons)
{
    u32 finished = 0;

    if (buttons->decided != 0) {
        u32 choice = buttons->choice;

        if (choice != OPTION_BUTTON_NONE) {
            finished = APP_TASKMENU_WIN_IsFinish(buttons->buttons[choice]);
            if (finished != 0) {
                OPTION_MENU_ResetButtons(buttons);
            }
        }
    }
    return finished;
}

void OPTION_MENU_ResetButtons(OptionMenuButtons *buttons)
{
    int i;

    for (i = 0; i < 2; i++) {
        APP_TASKMENU_WIN_ResetDecide(buttons->buttons[i]);
        APP_TASKMENU_WIN_SetActive(buttons->buttons[i], 0);
    }
}

void OPTION_MENU_CreateButtonWindows(OptionMenuButtons *buttons, u16 heapId)
{
    int i;

    for (i = 0; i < 2; i++) {
        if (buttons->items[i].str != 0) {
            STRBUF_Delete(buttons->items[i].str);
        }
        buttons->items[i].str = MSGDATA_AllocString(buttons->msgBank, i + 8);
        buttons->items[i].msgColor = 0x39e3;
        buttons->items[i].type = i;
        if (buttons->buttons[i] != 0) {
            APP_TASKMENU_WIN_Delete(buttons->buttons[i]);
        }
        buttons->buttons[i] =
            APP_TASKMENU_WIN_Create(buttons->menuRes, &buttons->items[i], (u8)(i * 9 + 14), 0x15, 9, heapId);
    }
}

/*
 * Unlabelled leaf before OPTION_MENU_InitList; OPTION_MENU_StateMain tests its result.
 */
int OPTION_MENU_HasButtonFocusChanged(OptionMenuButtons *buttons)
{
    return buttons->focusChanged;
}

/*
 * mainLayer/subLayer are u16 parameters (stored with strh); as u32 the strh of the
 * first is scheduled after the struct-copy source load.
 */
void OPTION_MENU_InitList(OptionMenuList *list, u16 mainLayer, u16 subLayer, OptionMenuScreen *screen, const OptionSettings *settings, u32 heapId)
{
    int i;

    MI_CpuFill8(list, 0, sizeof(OptionMenuList));
    list->mainLayer = mainLayer;
    list->subLayer = subLayer;
    list->scrollY = 0x10;
    list->settings = *settings;
    for (i = 0; i < OPTION_ACTOR_CHOICE_COUNT; i++) {
        list->choiceActors[i] = OPTION_MENU_GetScreenSpriteActor(screen, i + OPTION_ACTOR_CHOICE_FIRST);
    }
    OPTION_MENU_ScrollList(list, -8, -192, 192);
    if (UI_GetInputMode() == 1) {
        list->cursor = -1;
        OPTION_MENU_DrawList(list, 0);
        list->redraw = 0;
    } else {
        list->cursor = 0;
        OPTION_MENU_DrawList(list, 1);
        list->redraw = 1;
    }
}

void OPTION_MENU_ExitList(OptionMenuList *list)
{
    MI_CpuFill8(list, 0, sizeof(OptionMenuList));
}

/*
 * The 0/1/2 test on OPTION_MENU_TakeChangedSetting's result is a switch with three empty
 * labels: `r == 0 || r == 1 || r == 2` folds to one unsigned `cmp #2`.
 */
void OPTION_MENU_UpdateList(OptionMenuList *list, const OptionMenuInput *input, OptionMenuTextBox *helpText, OptionMenuScreen *screen, OptionMenuButtons *buttons)
{
    OptionMenuPoint touch;
    int command;
    int useStream;
    u32 wait;
#if LANGUAGE == LANGUAGE_JAPANESE
    int highlight;
#endif

    command = OPTION_MENU_GetInputCommand(input);
    BG_SYS_GetScrollY(list->subLayer);
    switch (command) {
    case OPTION_INPUT_KEY_ACTIVATE:
        list->cursor = list->cursor > OPTION_CURSOR_CANCEL ? OPTION_CURSOR_CANCEL : (list->cursor < 0 ? 0 : list->cursor);
        OPTION_MENU_DrawList(list, 1);
        list->redraw = 1;
        break;
    case OPTION_INPUT_HOLD_UP:
        if ((list->repeatCounter)++ < 10)
            break;
        /* fall through */
    case OPTION_INPUT_UP:
        list->repeatCounter = 0;
        list->cursor = list->cursor == 0 ? OPTION_CURSOR_CANCEL : list->cursor - 1;
        list->redraw = 1;
        GFL_USE_PlaySeDefaultVolume(OPTION_SE_CURSOR);
        OPTION_MENU_DrawList(list, 1);
        OPTION_MENU_RestartScreenBlink(screen);
        break;
    case OPTION_INPUT_HOLD_DOWN:
        if ((list->repeatCounter)++ < 10)
            break;
        /* fall through */
    case OPTION_INPUT_DOWN:
        list->repeatCounter = 0;
        if (list->cursor == OPTION_CURSOR_CANCEL)
            list->cursor = 0;
        else
            (list->cursor)++;
        list->redraw = 1;
        GFL_USE_PlaySeDefaultVolume(OPTION_SE_CURSOR);
        OPTION_MENU_DrawList(list, 1);
        OPTION_MENU_RestartScreenBlink(screen);
        break;
    case OPTION_INPUT_TOUCH:
        OPTION_MENU_GetInputPoint(input, 0, &touch);
        if (touch.y < 0x18 || touch.y > 0xA8)
            break;
        list->cursor = OPTION_MENU_GetRowAtTouch(list, &touch);
        OPTION_MENU_SelectChoiceAtTouch(list, &touch);
        OPTION_MENU_DrawList(list, 0);
        OPTION_MENU_RestartScreenBlink(screen);
        list->redraw = 1;
#if LANGUAGE == LANGUAGE_JAPANESE
        highlight = 0;
#endif
        if (UI_GetInputMode() == 0)
            UI_SetInputMode(1);
        break;
    case OPTION_INPUT_RIGHT:
        if (list->cursor < OPTION_COUNT) {
            GFL_USE_PlaySeDefaultVolume(OPTION_SE_CURSOR);
#if LANGUAGE == LANGUAGE_JAPANESE
            highlight = 1;
#endif
            OPTION_MENU_StepSelectedSetting(list, 1);
            OPTION_MENU_DrawList(list, 1);
            OPTION_MENU_RestartScreenBlink(screen);
        } else if (list->cursor == OPTION_CURSOR_CONFIRM) {
            (list->cursor)++;
            GFL_USE_PlaySeDefaultVolume(OPTION_SE_CURSOR);
            list->cursor = list->cursor > OPTION_CURSOR_CANCEL ? OPTION_CURSOR_CANCEL : (list->cursor < 0 ? 0 : list->cursor);
        }
        break;
    case OPTION_INPUT_LEFT:
        if (list->cursor < OPTION_COUNT) {
            GFL_USE_PlaySeDefaultVolume(OPTION_SE_CURSOR);
            OPTION_MENU_StepSelectedSetting(list, -1);
            OPTION_MENU_DrawList(list, 1);
            OPTION_MENU_RestartScreenBlink(screen);
#if LANGUAGE == LANGUAGE_JAPANESE
            highlight = 1;
#endif
        } else if (list->cursor == OPTION_CURSOR_CANCEL) {
            (list->cursor)--;
            GFL_USE_PlaySeDefaultVolume(OPTION_SE_CURSOR);
            list->cursor = list->cursor > OPTION_CURSOR_CANCEL ? OPTION_CURSOR_CANCEL : (list->cursor < 0 ? 0 : list->cursor);
        }
        break;
    case OPTION_INPUT_SHORTCUT_X:
        OPTION_MENU_DrawList(list, 1);
        break;
    case OPTION_INPUT_CONFIRM:
    case OPTION_INPUT_CANCEL:
        OPTION_MENU_DrawList(list, 0);
        break;
    }
    switch (OPTION_MENU_TakeChangedSetting(&list->settings)) {
#if LANGUAGE == LANGUAGE_JAPANESE
    case OPTION_CHOICE_MOJI_KANA:
    case OPTION_CHOICE_MOJI_KANJI:
        OPTION_MENU_CreateScreenLabels(screen);
        OPTION_MENU_CreateButtonWindows(buttons, 0x1c);
        OPTION_MENU_DrawList(list, highlight);
        list->redraw = 1;
        break;
#endif
    case 0:
    case 1:
    case 2:
        list->redraw = 1;
        break;
    }
    if (list->redraw) {
        if (list->cursor >= 0 && list->cursor < OPTION_COUNT) {
            if (list->cursor == 0) {
                useStream = 1;
                wait = OPTION_MENU_GetTextSpeedWait(&list->settings);
            } else {
                useStream = 0;
                wait = 0;
            }
            BG_SYS_SetPlaneVisible(4, 1);
            OPTION_MENU_PrintText(helpText, gOptionMenuSettingRows[list->cursor].descriptionId, wait, useStream);
        } else {
            BG_SYS_SetPlaneVisible(4, 0);
        }
        list->redraw = 0;
    }
    OPTION_MENU_IsTextDone(helpText);
    OPTION_MENU_ShiftInputTrail(list);
}

void OPTION_MENU_ClearListHighlight(OptionMenuList *list, OptionMenuScreen *screen)
{
    OPTION_MENU_DrawList(list, 0);
    BG_SYS_SetPlaneVisible(4, 0);
    OPTION_MENU_RestartScreenBlink(screen);
}

/*
 * Integer getter at offset 0x4.
 */
int OPTION_MENU_GetListCursor(const OptionMenuList *list)
{
    return list->cursor;
}

void OPTION_MENU_GetListSettings(const OptionMenuList *list, OptionSettings *out)
{
    *out = list->settings;
}

/*
 * Unlabelled tail-call stub after OPTION_MENU_GetListSettings: redraws through
 * OPTION_MENU_DrawList with the stored +0x54 flag.  OPTION_MENU_StateMain passes a second
 * argument (0 or 1) in r1 that this body never reads.
 */
void OPTION_MENU_RedrawList(OptionMenuList *list, int unused)
{
    OPTION_MENU_DrawList(list, list->highlight);
}

void OPTION_MENU_SetListButtonMode(OptionMenuList *list, u8 value)
{
    list->settings.values[OPTION_BUTTON_MODE] = value;
    OPTION_MENU_DrawList(list, list->highlight);
}

/* Redraws the row backgrounds, the label colours and the choice actors. */
void OPTION_MENU_DrawList(OptionMenuList *list, int highlight)
{
    int base;
    u32 k;
    int i;

#if LANGUAGE == LANGUAGE_JAPANESE
    if (list->cursor > OPTION_COUNT)
#else
    if (list->cursor >= OPTION_COUNT)
#endif
        highlight = 0;
    list->highlight = highlight;
    base = ((int)BG_SYS_GetScrollY(list->subLayer) + 0x14) / 0x18;
    BG_SYS_FillTileMap((u8)(list->subLayer), 0, 0, 0x20, 0x20, 5);
    i = 0;
#if LANGUAGE == LANGUAGE_JAPANESE
    for (k = 0; k < 5; k++)
#else
    for (k = 0; k < OPTION_COUNT; k++)
#endif
        BG_SYS_FillTileMap((u8)(list->subLayer), i, (base + k) * 3 + 2, 0x20, 3, gOptionMenuRowPalettes[k]);
    for (i = 0; i < OPTION_ACTOR_CHOICE_COUNT; i++) {
        if (list->cursor == gOptionMenuChoices[i].settingIndex && highlight) {
            if (OPTION_MENU_IsChoiceSelected(&list->settings, i))
                BG_SYS_FillTileMap((u8)(list->mainLayer), gOptionMenuLabels[i].x, gOptionMenuLabels[i].y, gOptionMenuLabels[i].width, gOptionMenuLabels[i].height, 7);
            else
                BG_SYS_FillTileMap((u8)(list->mainLayer), gOptionMenuLabels[i].x, gOptionMenuLabels[i].y, gOptionMenuLabels[i].width, gOptionMenuLabels[i].height, 0xC);
        } else {
            if (OPTION_MENU_IsChoiceSelected(&list->settings, i))
                BG_SYS_FillTileMap((u8)(list->mainLayer), gOptionMenuLabels[i].x, gOptionMenuLabels[i].y, gOptionMenuLabels[i].width, gOptionMenuLabels[i].height, 0);
            else
                BG_SYS_FillTileMap((u8)(list->mainLayer), gOptionMenuLabels[i].x, gOptionMenuLabels[i].y, gOptionMenuLabels[i].width, gOptionMenuLabels[i].height, 3);
        }
    }
    for (i = OPTION_ACTOR_CHOICE_COUNT; i < OPTION_WINDOW_LABEL_COUNT; i++) {
        if (i - OPTION_ACTOR_CHOICE_COUNT == list->cursor && highlight)
            BG_SYS_FillTileMap((u8)(list->mainLayer), gOptionMenuLabels[i].x, gOptionMenuLabels[i].y, gOptionMenuLabels[i].width, gOptionMenuLabels[i].height, 7);
        else
            BG_SYS_FillTileMap((u8)(list->mainLayer), gOptionMenuLabels[i].x, gOptionMenuLabels[i].y, gOptionMenuLabels[i].width, gOptionMenuLabels[i].height, 0);
    }
    if (highlight)
        BG_SYS_FillTileMap((u8)(list->subLayer), 0, list->cursor * 3 + 2, 0x20, 3, 7);
    BG_SYS_MarkTileDirty((u8)(list->subLayer));
    BG_SYS_MarkTileDirty((u8)(list->mainLayer));
    for (i = 0; i < OPTION_ACTOR_CHOICE_COUNT; i++) {
        if (list->cursor == gOptionMenuChoices[i].settingIndex && highlight) {
            if (OPTION_MENU_IsChoiceSelected(&list->settings, i))
                CLACT_ChangeActorAnimSeq((struct ClactActor *)list->choiceActors[i], 3);
            else
                CLACT_ChangeActorAnimSeq((struct ClactActor *)list->choiceActors[i], 2);
        } else {
            if (OPTION_MENU_IsChoiceSelected(&list->settings, i))
                CLACT_ChangeActorAnimSeq((struct ClactActor *)list->choiceActors[i], 0);
            else
                CLACT_ChangeActorAnimSeq((struct ClactActor *)list->choiceActors[i], 1);
        }
    }
}

/*
 * The clamp of the scrollY field is a nested ternary (if/else-if reallocates
 * registers); the first call result goes through a local so the sum is
 * `adds r7, r0, r1`.
 */
void OPTION_MENU_ScrollList(OptionMenuList *list, int delta, int min, int max)
{
    int i;
    int v;
    int t;
    ClPos pos;

    t = BG_SYS_GetScrollY(list->subLayer);
    v = t + delta;
#if LANGUAGE == LANGUAGE_JAPANESE
    v = v > max ? max : (v < min ? min : v);
#else
    if (v > max) {
        v = max;
    } else if (v < min) {
        v = min;
    }
#endif
    BG_SYS_ChangeScroll((u8)list->mainLayer, 3, v + 0x14);
    BG_SYS_ChangeScroll((u8)list->subLayer, 3, v);
    t = list->scrollY - delta;
    list->scrollY = t;
#if LANGUAGE == LANGUAGE_JAPANESE
    if (t > 0x24) {
        t = 0x24;
    } else if (t < 0xc) {
        t = 0xc;
    }
    list->scrollY = t;
#else
    list->scrollY = t > 0x10 - min ? 0x10 - min : (t < 0x10 - max ? 0x10 - max : t);
#endif
    for (i = 0; i < OPTION_ACTOR_CHOICE_COUNT; i++) {
        pos.x = gOptionMenuChoices[i].actorX;
        pos.y = list->scrollY + gOptionMenuChoices[i].actorY;
        CLACT_AddActorSurfacePos((struct ClactActor *)list->choiceActors[i], (struct ClactVec2 *)(&pos), 0);
    }
}

/* Selects the choice under the touch point, if any. */
void OPTION_MENU_SelectChoiceAtTouch(OptionMenuList *list, const OptionMenuPoint *touch)
{
    int i;
    OptionMenuRect rect;
    int x;
    int y;

    for (i = 0; i < OPTION_ACTOR_CHOICE_COUNT; i++) {
        OptionMenuChoice *choice = &gOptionMenuChoices[i];

        y = list->scrollY + choice->rectY;
        x = choice->rectX;
        rect.top = y;
        rect.left = x;
        rect.bottom = y + choice->rectHeight;
        rect.right = x + choice->rectWidth;
        if (y >= 0x18 && y <= 0xa8 && rect.bottom >= 0x18 && rect.bottom <= 0xa8) {
            if (OPTION_MENU_IsPointInRect(&rect, touch)) {
                GFL_USE_PlaySeDefaultVolume(OPTION_SE_CURSOR);
                OPTION_MENU_SelectChoice(&list->settings, i);
                OPTION_MENU_ApplySoundMode(list, (s8)list->settings.values[OPTION_SOUND_MODE], 0);
                return;
            }
        }
    }
}

/* Switches the audio output when the sound row changed (or when forced). */
void OPTION_MENU_ApplySoundMode(OptionMenuList *list, u32 soundMode, u32 force)
{
    if (list->cursor == OPTION_SOUND_MODE || force == 1) {
        if (soundMode == 0) {
            GFL_USE_SetStereoOutput(1);
        } else {
            GFL_USE_SetStereoOutput(0);
        }
    }
}

void OPTION_MENU_StepSelectedSetting(OptionMenuList *list, int delta)
{
    if (list->cursor < OPTION_COUNT) {
        OPTION_MENU_StepSetting(&list->settings, list->cursor, delta);
        OPTION_MENU_ApplySoundMode(list, (s8)list->settings.values[list->cursor], 0);
    }
}

/*
 * Lever: name the call result before addition (commutative operand idiom).
 * Arithmetic: unsigned word addition/subtraction wraps before signed division.
 */
int OPTION_MENU_GetRowAtTouch(OptionMenuList *list, const OptionMenuPoint *touch)
{
    int row;
    row = BG_SYS_GetScrollY(list->subLayer);
    row = (int)((u32)row + touch->y - 16u) / 24;
    if ((u32)row >= OPTION_COUNT) row = list->cursor;
    return row;
}

void OPTION_MENU_ShiftInputTrail(OptionMenuList *list)
{
    list->inputTrail <<= 1;
}

void OPTION_MENU_InitMessageBox(OptionMenuMessageBox *box, struct BmpWindow *window, struct GfFont *font, struct MsgBank *msgBank, struct TaskList *taskList, struct TaskMenuRes *menuRes, struct PrintSys *printSys, u16 heapId)
{
    int i;

    MI_CpuFill8(box, 0, sizeof(OptionMenuMessageBox));
    box->answer = 0;
    box->menuRes = menuRes;
    OPTION_MENU_InitTextBox(&box->text, window, font, msgBank, taskList, printSys, heapId);
    for (i = 0; i < 2; i++) {
        box->items[i].str = MSGDATA_AllocString(msgBank, i + 0x22);
        box->items[i].msgColor = 0x39E3;
        box->items[i].type = 0;
    }
    box->menuTemplate.heapId = heapId;
    box->menuTemplate.itemNum = 2;
    box->menuTemplate.itemWork = box->items;
    box->menuTemplate.posType = 1;
    box->menuTemplate.charPosX = 0x20;
    box->menuTemplate.charPosY = 0xc;
    box->menuTemplate.width = 0xd;
    box->menuTemplate.height = 3;
}

void OPTION_MENU_ExitMessageBox(OptionMenuMessageBox *box)
{
    int i;
    for (i = 0; i < 2; i++) STRBUF_Delete(box->items[i].str);
    OPTION_MENU_ExitTextBox(&box->text);
    MI_CpuFill8(box, 0, sizeof(OptionMenuMessageBox));
}

/* Prints the question, opens the two choice menu, then stores the answer (1 or 2). */
void OPTION_MENU_UpdateMessageBox(OptionMenuMessageBox *box)
{
    switch (box->phase) {
    case 0:
        if (OPTION_MENU_IsTextDone(&box->text) != 0) {
            box->phase = 1;
        }
        break;
    case 1:
        box->menu = (struct TaskMenu *)APP_TASKMENU_OpenMenu(&box->menuTemplate, box->menuRes);
        box->phase = 2;
        break;
    case 2:
        APP_TASKMENU_UpdateMenu((struct TaskMenuWork *)box->menu);
        if (APP_TASKMENU_IsFinish((struct TaskMenuWork *)box->menu) != 0) {
            box->answer = APP_TASKMENU_GetCursorPos((struct TaskMenuWork *)box->menu) + 1;
            box->phase = 3;
            APP_TASKMENU_CloseMenu((struct TaskMenuWork *)box->menu);
        }
        break;
    }
}

void OPTION_MENU_PrintDiscardPrompt(OptionMenuMessageBox *box, u32 wait)
{
    G2x_SetBlendBrightness_(REG_A_BLDCNT_ADDR, 23, 8);
    BG_SYS_SetPlaneVisible(3, 1);
    OPTION_MENU_PrintText(&box->text, 33, wait, 0);
}

/*
 * Unlabelled leaf (halfword getter) found while matching OPTION_MENU_StateDiscardPrompt.
 */
u16 OPTION_MENU_GetMessageBoxAnswer(const OptionMenuMessageBox *box)
{
    return box->answer;
}

void OPTION_MENU_PrintHelpMessage(OptionMenuMessageBox *box, u32 messageId, u32 wait)
{
    struct MsgBank *msgBank;

    G2x_SetBlendBrightness_(REG_A_BLDCNT_ADDR, 0x17, 8);
    BG_SYS_SetPlaneVisible(3, 1);
    msgBank = MSGDATA_CreateFromArchive(0, 3, 0x9e, 0x801C);
    OPTION_MENU_PrintTextFromBank(&box->text, msgBank, messageId, wait, 1);
    MSGDATA_Delete(msgBank);
}

/*
 * Interface: full-width r1 is forwarded through 021BA278 to 021BA28C;
 * the legacy u16 extern has no caller truncation witness here.
 */
void OPTION_MENU_PrintMessage(OptionMenuMessageBox *box, u32 messageId, u32 wait)
{
    G2x_SetBlendBrightness_(REG_A_BLDCNT_ADDR, 23, 8);
    BG_SYS_SetPlaneVisible(3, 1);
    OPTION_MENU_PrintText(&box->text, messageId, wait, 1);
}

int OPTION_MENU_IsMessageDone(OptionMenuMessageBox *box)
{
    if (OPTION_MENU_IsTextDone(&box->text)) {
        REG_A_BLDCNT = 0;
        BG_SYS_SetPlaneVisible(3, 0);
        return 1;
    }
    return 0;
}

/*
 * Byte-correct; blocked by two unwitnessed arm9 leaves (the integrator's):
 *   CONFIG_GetBattleScene (bitfield read, verified EXACT: typedef struct { unsigned short a:7; unsigned short b:1; } S;
 *                  unsigned CONFIG_GetBattleScene(S *p){ return p->b; })
 *   CONFIG_GetBattleStyle (same with a:6, b:1; disasm ldrh; lsls #0x19; lsrs #0x1f)
 *
 * 2026-10-05: body byte-correct. Leaves 020083AC and 020083C8 are now filed
 * EXACT in src/matched/arm9/. Needs shard seeding by the integrator.
 */
void OPTION_MENU_InitSettings(OptionSettings *settings, struct Config *config)
{
    MI_CpuFill8(settings, 0, sizeof(OptionSettings));
    settings->lastChanged = OPTION_NO_CHANGE;
    settings->config = config;
    settings->values[OPTION_TEXT_SPEED] = CONFIG_GetTextSpeed(config);
    settings->values[OPTION_BATTLE_SCENE] = CONFIG_GetBattleScene(config);
    settings->values[OPTION_BATTLE_STYLE] = CONFIG_GetBattleStyle(config);
    settings->values[OPTION_SOUND_MODE] = CONFIG_GetSoundMode(config);
#if LANGUAGE == LANGUAGE_JAPANESE
    settings->values[OPTION_MOJI_MODE] = CONFIG_GetTextLanguage(config);
#endif
    settings->values[OPTION_BUTTON_MODE] = CONFIG_GetButtonMode(config);
}

void OPTION_MENU_ExitSettings(OptionSettings *settings)
{
    MI_CpuFill8(settings, 0, sizeof(OptionSettings));
}

/* Writes the five settings back to the config. */
void OPTION_MENU_WriteSettings(const OptionSettings *settings)
{
    CONFIG_SetTextSpeed(settings->config, settings->values[OPTION_TEXT_SPEED]);
    CONFIG_SetBattleScene(settings->config, settings->values[OPTION_BATTLE_SCENE]);
    CONFIG_SetBattleStyle(settings->config, settings->values[OPTION_BATTLE_STYLE]);
    CONFIG_SetSoundMode(settings->config, settings->values[OPTION_SOUND_MODE]);
#if LANGUAGE == LANGUAGE_JAPANESE
    CONFIG_SetTextLanguage(settings->config, settings->values[OPTION_MOJI_MODE]);
#endif
    CONFIG_SetButtonMode(settings->config, settings->values[OPTION_BUTTON_MODE]);
}

void OPTION_MENU_SelectChoice(OptionSettings *settings, int choiceIndex)
{
    if (settings->values[gOptionMenuChoices[choiceIndex].settingIndex] != gOptionMenuChoices[choiceIndex].value) {
        settings->values[gOptionMenuChoices[choiceIndex].settingIndex] = gOptionMenuChoices[choiceIndex].value;
        settings->lastChanged = choiceIndex;
        OPTION_MENU_WriteSettings(settings);
    }
}

/*
 * The three 0x021BB57x pool words and the two 0x021BB70x words are separate
 * pool entries in the original, so each is its own extern.
 */
void OPTION_MENU_StepSetting(OptionSettings *settings, int row, int delta)
{
    int j;
    int k;
    int count;
    const OptionMenuSettingRow *rowInfo;
    int off = row << 3;
    s8 index;
    int position;
    int choice = -1;

    count = *(u16 *)((u8 *)gOptionMenuSettingRowChoiceCount + off);
    j = 0;
    if (count > 0) {
        do {
            u8 current;
            u32 value;

            rowInfo = (const OptionMenuSettingRow *)((u8 *)gOptionMenuSettingRows + off);
            current = settings->values[row];

            choice = rowInfo->choices[j];
            value = gOptionMenuChoices[choice].value;
            if (value == current) {
                break;
            }
            j++;
        } while (j < rowInfo->choiceCount);
    }
    position = (s8)(choice - gOptionMenuSettingRowChoices[0][(u32)row << 3]);
    position = (s8)(position + delta);
    index = (s8)(position > count - 1 ? count - 1 : (position < 0 ? 0 : position));
    k = ((u8 *)gOptionMenuSettingRowChoices + off)[index];
    if (settings->values[row] != gOptionMenuChoiceValues[k][0]) {
        settings->values[row] = gOptionMenuChoiceValues[k][0];
        settings->lastChanged = k;
        OPTION_MENU_WriteSettings(settings);
    }
}

int OPTION_MENU_IsChoiceSelected(const OptionSettings *settings, int choiceIndex)
{
    if (settings->values[gOptionMenuChoices[choiceIndex].settingIndex] == gOptionMenuChoices[choiceIndex].value) return 1;
    return 0;
}

/*
 * ARM9 tail call (text speed to message wait); the settings argument is not read.
 */
u32 OPTION_MENU_GetTextSpeedWait(const OptionSettings *settings)
{
    return MSG_SPEED_GetWait();
}

/* Returns the index of the setting changed since the last call and clears it. */
int OPTION_MENU_TakeChangedSetting(OptionSettings *settings)
{
    unsigned char old = settings->lastChanged;
    settings->lastChanged = OPTION_NO_CHANGE;
    return old;
}

int OPTION_MENU_AreSettingsEqual(const OptionSettings *a, const OptionSettings *b)
{
    if (GF_STANDARD_CompareBytes(a->values, b->values, OPTION_COUNT) == 0) return 1;
    return 0;
}

void OPTION_MENU_InitRunner(OptionMenuRunner *runner, OptionMenuWork *work, OptionMenuStateFn callback)
{
    MI_CpuFill8(runner, 0, sizeof(OptionMenuRunner));
    runner->work = work;
    OPTION_MENU_SetRunnerState(runner, callback);
}

/*
 * Tail call to MI_CpuFill8(p, 0, 0x10).
 */
void OPTION_MENU_ExitRunner(OptionMenuRunner *runner)
{
    MI_CpuFill8(runner, 0, sizeof(OptionMenuRunner));
}

void OPTION_MENU_UpdateRunner(OptionMenuRunner *runner)
{
    if (runner->finished == 0)
        runner->callback(runner, &runner->state, runner->work);
}

int OPTION_MENU_IsRunnerFinished(OptionMenuRunner *runner)
{
    return runner->finished;
}

/*
 * Getter and two small setters.
 */
void OPTION_MENU_SetRunnerState(OptionMenuRunner *runner, OptionMenuStateFn callback)
{
    runner->callback = callback;
    runner->state = 0;
}

void OPTION_MENU_FinishRunner(OptionMenuRunner *runner)
{
    runner->finished = 1;
}

/* Fade in, then hand over to the main state. */
void OPTION_MENU_StateFadeIn(OptionMenuRunner *runner, u32 *state, OptionMenuWork *work)
{
    switch (*state) {
    case 0:
        FADE_Start(3, 16, 0, 0);
        *state = 1;
        break;
    case 1:
        if (FADE_IsActive() == 0) {
            *state = 2;
        }
        break;
    case 2:
        OPTION_MENU_SetRunnerState(runner, OPTION_MENU_StateMain);
        break;
    }
}

/* Fade out, then finish the runner. */
void OPTION_MENU_StateFadeOut(OptionMenuRunner *runner, u32 *state, OptionMenuWork *work)
{
    switch (*state) {
    case 0:
        FADE_Start(3, 0, 16, 0);
        *state = 1;
        break;
    case 1:
        if (FADE_IsActive() == 0)
            *state = 2;
        break;
    case 2:
        OPTION_MENU_FinishRunner(runner);
        break;
    }
}

/* Main state: input, list, buttons and the help messages. */
void OPTION_MENU_StateMain(OptionMenuRunner *runner, u32 *state, OptionMenuWork *work)
{
    OptionSettings settingsReturn;
    OptionSettings settingsCancel;
    OptionSettings settingsCurrent;
    OptionSettings settingsTextSpeed;
    OptionSettings settingsBattleScene;
    OptionSettings settingsBattleStyle;
    OptionSettings settingsSound;
    int choice;
    int tutorialPending;

    if (PRINTSYS_QUE_IsFinished((struct PrintQueue *)work->printSys) == 0)
        return;
    switch (*state) {
    case 0:
        OPTION_MENU_ReadInput(&work->input);
        if (OPTION_MENU_GetButtonChoice(&work->buttons, 0) == 0)
            OPTION_MENU_UpdateList(&work->list, &work->input, &work->helpText, &work->screen, &work->buttons);
        OPTION_MENU_UpdateButtons(&work->buttons, &work->input, &work->list);
        if (OPTION_MENU_HasButtonFocusChanged(&work->buttons))
            OPTION_MENU_ClearListHighlight(&work->list, &work->screen);
        if (OPTION_MENU_GetButtonChoice(&work->buttons, &choice)) {
            switch (choice) {
            case OPTION_BUTTON_CONFIRM:
                if (OPTION_MENU_IsButtonFinished(&work->buttons))
                    OPTION_MENU_SetRunnerState(runner, OPTION_MENU_StateApply);
                break;
            case OPTION_BUTTON_RETURN:
                work->args->result = 1;
                OPTION_MENU_GetListSettings(&work->list, &settingsReturn);
                if (OPTION_MENU_AreSettingsEqual(&work->savedSettings, &settingsReturn)) {
                    OPTION_MENU_SetRunnerState(runner, OPTION_MENU_StateKeepSaved);
                } else {
                    OPTION_MENU_ResetButtons(&work->buttons);
                    OPTION_MENU_SetRunnerState(runner, OPTION_MENU_StateDiscardPrompt);
                }
                break;
            case OPTION_BUTTON_CANCEL:
                if (OPTION_MENU_IsButtonFinished(&work->buttons)) {
                    OPTION_MENU_GetListSettings(&work->list, &settingsCancel);
                    if (OPTION_MENU_AreSettingsEqual(&work->savedSettings, &settingsCancel)) {
                        OPTION_MENU_SetRunnerState(runner, OPTION_MENU_StateKeepSaved);
                    } else {
                        OPTION_MENU_ResetButtons(&work->buttons);
                        OPTION_MENU_SetRunnerState(runner, OPTION_MENU_StateDiscardPrompt);
                    }
                }
                break;
            }
        }
        tutorialPending = SAVE_CONTROL_WouldOverwriteSave(GAME_DATA_GetSaveControl(GAMESYSTEM_GetGameData(work->args->gameSystem)));
        OPTION_MENU_GetListSettings(&work->list, &settingsCurrent);
        if (settingsCurrent.values[OPTION_BUTTON_MODE] == 0 && tutorialPending != 0)
            *state = 1;
        break;
    case 1:
        OPTION_MENU_GetListSettings(&work->list, &settingsTextSpeed);
        OPTION_MENU_PrintMessage(&work->messageBox, 0x20, OPTION_MENU_GetTextSpeedWait(&settingsTextSpeed));
        OPTION_MENU_SetListButtonMode(&work->list, 1);
        *state = 5;
        break;
    case 2:
        OPTION_MENU_GetListSettings(&work->list, &settingsBattleScene);
        OPTION_MENU_PrintHelpMessage(&work->messageBox, 0x16, OPTION_MENU_GetTextSpeedWait(&settingsBattleScene));
        OPTION_MENU_RedrawList(&work->list, 0);
        *state = 5;
        break;
    case 3:
        OPTION_MENU_GetListSettings(&work->list, &settingsBattleStyle);
        OPTION_MENU_PrintHelpMessage(&work->messageBox, 0x16, OPTION_MENU_GetTextSpeedWait(&settingsBattleStyle));
        OPTION_MENU_RedrawList(&work->list, 0);
        *state = 5;
        break;
    case 4:
        OPTION_MENU_GetListSettings(&work->list, &settingsSound);
        OPTION_MENU_PrintMessage(&work->messageBox, 0x24, OPTION_MENU_GetTextSpeedWait(&settingsSound));
        OPTION_MENU_RedrawList(&work->list, 1);
        *state = 5;
        break;
    case 5:
        if (OPTION_MENU_IsMessageDone(&work->messageBox))
            *state = 0;
        break;
    }
}

/* Asks whether to discard the changes: answer 1 applies them, answer 2 reverts. */
void OPTION_MENU_StateDiscardPrompt(OptionMenuRunner *runner, u32 *state, OptionMenuWork *work)
{
    OptionSettings settings;
    u16 answer;

    switch (*state) {
    case 0:
        OPTION_MENU_GetListSettings(&work->list, &settings);
        OPTION_MENU_PrintDiscardPrompt(&work->messageBox, OPTION_MENU_GetTextSpeedWait(&settings));
        BG_SYS_SetPlaneVisible(4, 0);
        *state = 1;
        break;
    case 1:
        answer = OPTION_MENU_GetMessageBoxAnswer(&work->messageBox);
        switch (answer) {
        case 1:
            *state = 2;
            break;
        case 2:
            *state = 3;
            break;
        }
        break;
    case 2:
        OPTION_MENU_SetRunnerState(runner, OPTION_MENU_StateApply);
        break;
    case 3:
        OPTION_MENU_SetRunnerState(runner, OPTION_MENU_StateKeepSaved);
        break;
    }
    OPTION_MENU_UpdateMessageBox(&work->messageBox);
}

/* Keeps the saved settings and leaves. */
void OPTION_MENU_StateKeepSaved(OptionMenuRunner *runner, u32 *state, OptionMenuWork *work)
{
    OPTION_MENU_WriteSettings(&work->savedSettings);
    OPTION_MENU_ApplySoundMode(&work->list, (s8)work->savedSettings.values[OPTION_SOUND_MODE], 1);
    OPTION_MENU_SetRunnerState(runner, OPTION_MENU_StateFadeOut);
}

/* Writes the edited settings and leaves. */
void OPTION_MENU_StateApply(OptionMenuRunner *runner, u32 *state, OptionMenuWork *work)
{
    OptionSettings settings;

    OPTION_MENU_GetListSettings(&work->list, &settings);
    OPTION_MENU_WriteSettings(&settings);
    GFL_USE_PlaySeDefaultVolume(OPTION_SE_APPLY);
    OPTION_MENU_SetRunnerState(runner, OPTION_MENU_StateFadeOut);
}

/* Inclusive rectangle hit test (unsigned range compare per axis). */
int OPTION_MENU_IsPointInRect(const OptionMenuRect *rect, const OptionMenuPoint *point)
{
    u32 inX = ((u32)point->x - (u32)rect->left) <= ((u32)rect->right - (u32)rect->left);
    u32 inY = ((u32)point->y - (u32)rect->top) <= ((u32)rect->bottom - (u32)rect->top);
    return inX & inY;
}

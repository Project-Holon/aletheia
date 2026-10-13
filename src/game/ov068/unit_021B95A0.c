/*
 * file:     unit_021B95A0.c
 * unit:     yes
 * function: OPTION_MENU_Init, OPTION_MENU_Exit, OPTION_MENU_Main, OPTION_MENU_InitScreen, OPTION_MENU_ExitScreen, OPTION_MENU_UpdateScreen, func_021B9944, func_021B9950, func_021B995C, func_021B9964, OPTION_MENU_ScreenTaskMain, OPTION_MENU_InitGfx, OPTION_MENU_ExitGfx, OPTION_MENU_UpdateGfxBlink, OPTION_MENU_GetGfxWindow, OPTION_MENU_CreateLabelWindows, OPTION_MENU_RestartGfxBlink, OPTION_MENU_FlushGfx, BLINK_PALANM_BlendStep, OPTION_MENU_InitSprites, OPTION_MENU_ExitSprites, OPTION_MENU_UpdateSprites, OPTION_MENU_DrawSprites, OPTION_MENU_GetSpriteActor, OPTION_MENU_GetSpriteUnit, OPTION_MENU_InitInput, OPTION_MENU_ExitInput, OPTION_MENU_ReadInput, OPTION_MENU_GetInputCommand, OPTION_MENU_GetInputPoint, OPTION_MENU_InitTextBox, OPTION_MENU_ExitTextBox, OPTION_MENU_PrintText, OPTION_MENU_PrintTextFromBank, OPTION_MENU_IsTextDone, OPTION_MENU_InitButtons, OPTION_MENU_ExitButtons, OPTION_MENU_UpdateButtons, OPTION_MENU_UpdateButtonWindows, OPTION_MENU_GetButtonChoice, OPTION_MENU_IsButtonFinished, OPTION_MENU_ResetButtons, OPTION_MENU_CreateButtonWindows, OPTION_MENU_HasButtonFocusChanged, OPTION_MENU_InitList, OPTION_MENU_ExitList, OPTION_MENU_UpdateList, OPTION_MENU_ClearListHighlight, OPTION_MENU_GetListCursor, OPTION_MENU_GetListSettings, OPTION_MENU_RedrawList, OPTION_MENU_SetListButtonMode, OPTION_MENU_DrawList, OPTION_MENU_ScrollList, OPTION_MENU_SelectChoiceAtTouch, OPTION_MENU_ApplySoundMode, OPTION_MENU_StepSelectedSetting, OPTION_MENU_GetRowAtTouch, OPTION_MENU_ShiftInputTrail, OPTION_MENU_InitMessageBox, OPTION_MENU_ExitMessageBox, OPTION_MENU_UpdateMessageBox, OPTION_MENU_PrintDiscardPrompt, OPTION_MENU_GetMessageBoxAnswer, OPTION_MENU_PrintHelpMessage, OPTION_MENU_PrintMessage, OPTION_MENU_IsMessageDone, OPTION_MENU_InitSettings, OPTION_MENU_ExitSettings, OPTION_MENU_WriteSettings, OPTION_MENU_SelectChoice, OPTION_MENU_StepSetting, OPTION_MENU_IsChoiceSelected, func_021BB0D0, func_021BB0D8, OPTION_MENU_AreSettingsEqual, OPTION_MENU_InitRunner, OPTION_MENU_ExitRunner, OPTION_MENU_UpdateRunner, func_021BB134, func_021BB138, func_021BB140, OPTION_MENU_StateFadeIn, OPTION_MENU_StateFadeOut, OPTION_MENU_StateMain, OPTION_MENU_StateDiscardPrompt, OPTION_MENU_StateKeepSaved, OPTION_MENU_StateApply, OPTION_MENU_IsPointInRect
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
 *   func_02034AC4  0x02034AC4  arm
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm
 *   PROCSYS_AllocProcWork  0x0203159C  arm
 *   func_02082BCC  0x02082BCC  arm
 *   GF_FONT_Create  0x0201D7EC  thumb
 *   func_0201C440  0x0201C440  thumb
 *   APP_TASKMENU_RES_Create  0x02027F60  thumb
 *   func_02045B38  0x02045B38  arm
 *   TCBL_Create  0x0203101C  arm
 *   func_020120F4  0x020120F4  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_0200873C  0x0200873C  thumb
 *   ov067_id       0x00000043  data
 *   TCBL_Destroy  0x02031140  arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   func_020315D4  0x020315D4  arm
 *   func_020306F0  0x020306F0  arm
 *   func_02034A5C  0x02034A5C  arm
 *   APP_TASKMENU_RES_Delete  0x02027FD8  thumb
 *   func_0201C4C0  0x0201C4C0  thumb
 *   GF_FONT_Delete  0x0201D83C  thumb
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb
 *   TCBL_Main  0x020310C4  arm
 *   BG_SYS_ClearGraphicsMemory  0x0204335C  arm
 *   BG_SYS_SetVramBanks  0x020433E0  arm
 *   func_0204363C  0x0204363C  arm
 *   BG_SYS_ResetSubDisplay  0x0204361C  arm
 *   BG_SYS_ClearMainPlanes  0x020434CC  arm
 *   BG_SYS_ClearSubPlanes  0x02043588  arm
 *   func_0201DD60  0x0201DD60  thumb
 *   GF_FONT_SetTextColor  0x0201DD78  thumb
 *   func_020056A0  0x020056A0  thumb
 *   gOptionMenuDispVram     0x021BB598  data  a4
 *   func_02030EAC  0x02030EAC  arm
 *   func_0201DD68  0x0201DD68  thumb
 *   func_02082D44  0x02082D44  arm
 *   func_0203F8F4  0x0203F8F4  arm
 *   BMP_WIN_Init  0x02045088  arm
 *   func_0203FC28  0x0203FC28  arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_020414AC  0x020414AC  arm
 *   func_02040588  0x02040588  arm
 *   func_02040C14  0x02040C14  arm
 *   func_020490F4  0x020490F4  arm
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   func_02049B68  0x02049B68  arm
 *   ARC_UTIL_UploadPaletteFromHandle  0x02049BDC  arm
 *   func_02049DF4  0x02049DF4  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   func_02049F34  0x02049F34  arm
 *   func_020307B0  0x020307B0  arm
 *   BMP_WIN_Create  0x020450F0  arm
 *   gOptionMenuDispConfig  0x021BB540  data  a4
 *   gOptionMenuBgLayers  0x021BB614  data  a4
 *   func_020452E8  0x020452E8  arm
 *   func_02040DA8  0x02040DA8  arm
 *   func_020403F4  0x020403F4  arm
 *   BMP_WIN_Exit  0x020450C8  arm
 *   func_0203F9B4  0x0203F9B4  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_0201D304  0x0201D304  thumb
 *   func_02045770  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   PRINTSYS_Print  0x0201C7A4  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 *   STRBUF_Delete  0x02045808  arm
 *   BMP_GetPixels  0x020437D4  arm
 *   func_02082A90  0x02082A90  arm
 *   func_02045738  0x02045738  arm
 *   PRINTSYS_PrintColor  0x0201C7D0  thumb
 *   gOptionMenuLabels     0x021BB820  data  ov068  a4
 *   func_020419E4  0x020419E4  arm
 *   d_020A1B38     0x020A1B38  data  a2
 *   func_02061CA4  0x02061CA4  arm
 *   CLACT_InitSystem  0x0204A48C  arm
 *   CLACT_CreateUnit  0x0204B100  arm
 *   CLACT_SetUnitDefaultRenderer  0x0204B270  arm
 *   func_020434DC  0x020434DC  arm
 *   BG_SYS_SetSubPlaneVisible  0x02043598  arm
 *   CLACT_RegisterPalette  0x0204ABF0  arm
 *   CLACT_RegisterCharacter  0x0204A6C8  arm
 *   CLACT_RegisterCellAnim  0x0204AF28  arm
 *   CLACT_CreateActor  0x0204B294  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B6F4  0x0204B6F4  arm
 *   GFL_NET_GetRunState  0x0203CD98  arm
 *   GFL_NET_RestartWithDefaultTimeout  0x0203D34C  arm
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
 *   func_02035D20  0x02035D20  arm
 *   TOUCHPANEL_GetPointCont  0x02035CB8  arm
 *   func_020362DC  0x020362DC  arm
 *   func_0203630C  0x0203630C  arm
 *   func_020355C4  0x020355C4  arm
 *   func_020355D8  0x020355D8  arm
 *   func_020061E4  0x020061E4  thumb
 *   STRBUF_Create  0x020457B0  arm
 *   func_02028470  0x02028470  thumb
 *   BMP_WIN_GetPalette  0x02045778  arm
 *   func_0201F73C  0x0201F73C  thumb
 *   func_020409B4  0x020409B4  arm
 *   func_0201CE48  0x0201CE48  thumb
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201C6FC  0x0201C6FC  thumb
 *   PRINTSYS_PrintStream  0x0201CCE4  thumb
 *   func_02028484  0x02028484  thumb
 *   func_0201C6C4  0x0201C6C4  thumb
 *   TOUCHBAR_Create  0x021B62E0  thumb  ov067
 *   GAME_DATA_CheckSaveFlag  0x02012BF8  thumb
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
 *   func_021B65A8  0x021B65A8  thumb  ov067
 *   GAME_DATA_SetSaveFlag  0x02012BE0  thumb
 *   gOptionMenuConfirmRect     0x021BB550  data  a4
 *   func_020061E4_2  0x020061E4  thumb
 *   gOptionMenuCancelRect     0x021BB560  data  ov068  a4
 *   APP_TASKMENU_WIN_Update  0x02028178  thumb
 *   APP_TASKMENU_WIN_IsFinish  0x02028230  thumb
 *   APP_TASKMENU_WIN_ResetDecide  0x020282A4  thumb
 *   APP_TASKMENU_WIN_Create  0x02027FEC  thumb
 *   func_02040804  0x02040804  arm
 *   gOptionMenuSettingRows     0x021BB570  data  a4
 *   func_020413B0  0x020413B0  arm
 *   CLACT_ChangeActorAnimSeq  0x0204B8A0  arm
 *   gOptionMenuRowPalettes     0x021BB538  data  a1
 *   func_02041EE4  0x02041EE4  arm
 *   func_0204B404  0x0204B404  arm
 *   GFL_USE_SetStereoOutput  0x02005C28  thumb
 *   APP_TASKMENU_OpenMenu  0x02027778  thumb
 *   APP_TASKMENU_UpdateMenu  0x02027974  thumb
 *   APP_TASKMENU_IsFinish  0x020279E8  thumb
 *   APP_TASKMENU_GetCursorPos  0x02027A04  thumb
 *   APP_TASKMENU_CloseMenu  0x02027858  thumb
 *   func_0207D658 0x0207D658 arm
 *   CONFIG_GetTextSpeed  0x02008374  thumb
 *   CONFIG_GetBattleScene  0x020083AC  thumb
 *   CONFIG_GetBattleStyle  0x020083C8  thumb
 *   CONFIG_GetSoundMode  0x02008390  thumb
 *   CONFIG_GetButtonMode  0x02008428  thumb
 *   CONFIG_SetTextSpeed 0x0200837C thumb
 *   CONFIG_SetBattleScene 0x020083B4 thumb
 *   CONFIG_SetBattleStyle 0x020083D0 thumb
 *   CONFIG_SetSoundMode 0x02008398 thumb
 *   CONFIG_SetButtonMode 0x02008430 thumb
 *   gOptionMenuSettingRowChoiceCount     0x021BB572  data  a2
 *   gOptionMenuSettingRowChoices     0x021BB574  data  a4
 *   gOptionMenuChoiceValues     0x021BB708  data  a4
 *   func_02012FFC  0x02012FFC  thumb
 *   func_0203EFC8 0x0203EFC8 arm
 *   FADE_Start  0x0204E720  arm
 *   FADE_IsActive  0x0204E804  arm
 *   func_0201C6B4  0x0201C6B4  thumb
 *   func_020071F0  0x020071F0  thumb
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

#include "unit_021B95A0_types.h"

/* Display registers of the main (A) and sub (B) engine. */
#define REG_A_DISPCNT_ADDR 0x04000000
#define REG_A_BLDCNT_ADDR  0x04000050
#define REG_B_DISPCNT_ADDR 0x04001000
#define REG_B_BLDCNT_ADDR  0x04001050
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

struct DispVram;
struct DispConfig;
struct ClInitParam;

extern int func_02034AC4(s32 handle);
extern void GFL_HEAP_CreateChildHeap(u32 a, u32 b, u32 c);
extern void *PROCSYS_AllocProcWork(struct Proc *proc, u32 size, u32 heapId);
extern void func_02082BCC(void *dst, u32 value, u32 size);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern struct PrintSys *func_0201C440(u32 heapId);
extern struct TaskMenuRes *APP_TASKMENU_RES_Create(u16 type, u16 style, struct GfFont *font, struct PrintSys *printSys, u16 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct TaskList *TCBL_Create(u16 heapId, u16 tag, u32 count, u32 workSize);
extern struct GameData *func_020120F4(const struct GameSystem *gameSystem);
extern struct SaveData *GAME_DATA_GetSaveControl(struct GameData *gameData);
extern struct Config *func_0200873C(struct SaveData *saveData);
extern void TCBL_Destroy(struct TaskList *taskList);
extern u32 MSGDATA_Delete(struct MsgBank *msgBank);
extern void func_020315D4(struct Proc *proc);
extern void func_020306F0(unsigned int heapId);
extern void func_02034A5C(int a);
extern u32 APP_TASKMENU_RES_Delete(struct TaskMenuRes *menuRes);
extern void func_0201C4C0(struct PrintSys *printSys);
extern u32 GF_FONT_Delete(struct GfFont *font);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *printSys);
extern void TCBL_Main(struct TaskList *taskList);
extern void BG_SYS_ClearGraphicsMemory(u32 keep);
extern void BG_SYS_SetVramBanks(const struct DispVram *config);
extern void func_0204363C(u32 v);
extern void BG_SYS_ResetSubDisplay(void);
extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
extern void func_0201DD60(void);
extern void GF_FONT_SetTextColor(u32 r, u32 g, u32 b);
extern struct Task *func_020056A0(void (*fn)(struct Task *, OptionMenuScreen *), OptionMenuScreen *arg, u32 priority);
extern void func_02030EAC(struct Task *task);
extern void func_0201DD68(void);
extern void func_02082D44(const void *src, void *dst, u32 size);
extern void func_0203F8F4(u16 heapId);
extern void BMP_WIN_Init(u16 heapId);
extern void func_0203FC28(struct DispConfig *config);
extern void func_0203FCA0(u32 bgId, const BgTemplate *layout, u32 type);
extern void func_020414AC(u8 id);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02040C14(u32 a, u32 b, u32 c, u32 d);
extern void *func_020490F4(u32 id, u32 heapId);
extern u32 func_02049658(void *arc, u32 b, u32 c, u32 d, u32 e, u32 f, u16 heapId);
extern void func_020498F4(void *arc, u32 b, u32 c, u32 d, u32 e, u32 f, u16 heapId);
extern void func_02049B68(void *arc, u32 b, u32 c, u32 d, u32 e, u16 heapId);
extern void ARC_UTIL_UploadPaletteFromHandle(void *arc, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 heapId);
extern void *func_02049DF4(void *arc, u32 id, u32 b, ScreenData **out, u16 heapId);
extern void ARC_TOOL_DeleteHandle(void *arc);
extern void *func_02049F34(u32 arcId, u32 id, PaletteResource **out, u32 heapId);
extern void func_020307B0(void *p);
extern struct BmpWindow *BMP_WIN_Create(u32 layer, u32 x, u32 y, u32 width, u8 height, u8 palette, u8 slot);
extern u32 func_020452E8(struct BmpWindow *window);
extern void func_02040DA8(u32 a, u32 b, u32 c);
extern void func_020403F4(u32 a);
extern void BMP_WIN_Exit(void);
extern void func_0203F9B4(void);
extern struct StringBuf *func_02045EC0(struct MsgBank *msgBank, u32 index);
extern u32 func_0201D304(struct StringBuf *str, struct GfFont *font, u32 a);
extern struct Bitmap *func_02045770(struct BmpWindow *window);
extern void BMP_Clear(struct Bitmap *bitmap, u8 value);
extern void PRINTSYS_Print(struct Bitmap *bitmap, s16 x, s16 y, struct StringBuf *str, struct GfFont *font);
extern void PRINTSYS_PrintColor(struct Bitmap *bitmap, s16 x, s16 y, struct StringBuf *str, struct GfFont *font, u16 color);
extern void BMP_WIN_TransferChars(struct BmpWindow *window);
extern void BMP_WIN_MakeScreen(struct BmpWindow *window);
extern u8 func_02045730(struct BmpWindow *window);
extern void func_02041B6C(u32 a);
extern void STRBUF_Delete(struct StringBuf *str);
extern void *BMP_GetPixels(const struct Bitmap *bitmap);
extern void func_02082A90(u32 a, u32 b, u32 size);
extern u8 func_02045738(struct BmpWindow *window);
extern s32 func_02061CA4(u32 kind, u32 offset, const void *src, s32 size);
extern void CLACT_InitSystem(const struct ClInitParam *param, const void *res, u32 heapId);
extern struct ClUnit *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void CLACT_SetUnitDefaultRenderer(struct ClUnit *unit);
extern void func_020434DC(u32 a, u32 b);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
extern struct ClRes *CLACT_RegisterPalette(void *arc, int id, int b, int c, int heapId);
extern struct ClRes *CLACT_RegisterCharacter(void *arc, int id, int b, int c, int heapId);
extern struct ClRes *CLACT_RegisterCellAnim(void *arc, u32 first, u32 second, u32 heapId);
extern struct ClActor *CLACT_CreateActor(struct ClUnit *unit, struct ClRes *charRes, struct ClRes *plttRes, struct ClRes *cellRes, ClActorParam *param, int flag, int heapId);
extern void func_0204B92C(struct ClActor *actor, u32 v);
extern void func_0204B6F4(struct ClActor *actor, u32 v, u32 flag);
extern int GFL_NET_GetRunState(void);
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);
extern void CLACT_DeleteActor(struct ClActor *actor);
extern void CLACT_ReleasePalette(struct ClRes *res);
extern void CLACT_ReleaseCharacter(struct ClRes *res);
extern void CLACT_ReleaseCellAnim(struct ClRes *res);
extern u32 CLACT_DeleteUnit(struct ClUnit *unit);
extern void CLACT_ExitSystem(void);
extern void CLACT_SetActorAnimIndex(struct ClActor *actor, int index);
extern void CLACT_DrawSystem(void);
extern void CLACT_VBlankSystem(void);
extern u32 func_02035D20(int *x, int *y);
extern u32 TOUCHPANEL_GetPointCont(int *x, int *y);
extern u32 func_020362DC(void);
extern unsigned int func_0203630C(void);
extern u8 func_020355C4(void);
extern void func_020355D8(u8 v);
extern void func_020061E4(u32 id);
extern struct StringBuf *STRBUF_Create(u32 capacity, u32 heapId);
extern void func_02028470(PrintWaitState *waitState, u32 v);
extern u8 BMP_WIN_GetPalette(struct BmpWindow *window);
extern void func_0201F73C(struct BmpWindow *window, int a1, int a2, int palette);
extern void func_020409B4(u32 index);
extern void func_0201CE48(struct PrintStream *stream);
extern void func_02045CAC(struct MsgBank *msgBank, u32 index, struct StringBuf *dest);
extern void func_0201C6FC(struct PrintSys *printSys, struct Bitmap *bitmap, u32 x, u32 y, struct StringBuf *str, struct GfFont *font);
extern struct PrintStream *PRINTSYS_PrintStream(struct BmpWindow *window, u32 x, u32 y, struct StringBuf *buffer,
                                         struct GfFont *font, u32 wait, struct TaskList *taskList,
                                         u32 zero, u16 heapId, u16 fillColor);
extern s32 func_02028484(PrintWaitState *waitState, struct PrintStream *stream);
extern u32 func_0201C6C4(struct PrintSys *printSys, struct Bitmap *bitmap);
extern struct ReturnButton *TOUCHBAR_Create(ReturnButtonRequest *request, u16 heapId);
extern int GAME_DATA_CheckSaveFlag(struct GameData *gameData, int flag);
extern void TOUCHBAR_SetButtonToggled(struct ReturnButton *button, unsigned int id, unsigned int v);
extern void TOUCHBAR_Delete(struct ReturnButton *button);
extern void APP_TASKMENU_WIN_Delete(struct TaskMenuWin *win);
/* stand-in: second name for func_020061E4 with an int parameter; with the u32 prototype the
   conditional sound id compiles 4 bytes smaller than the original (OPTION_MENU_UpdateButtons). */
extern void func_020061E4_2(int id);
extern void APP_TASKMENU_WIN_SetActive(struct TaskMenuWin *win, u32 a);
extern void APP_TASKMENU_WIN_SetDecide(struct TaskMenuWin *win, int v);
extern void TOUCHBAR_Update(struct ReturnButton *button);
extern int TOUCHBAR_GetPressedButtonIdIfPressing(struct ReturnButton *button);
extern int TOUCHBAR_GetPressedButtonIdIfDone(struct ReturnButton *button);
extern int func_021B65A8(struct ReturnButton *button, int id);
extern void GAME_DATA_SetSaveFlag(struct GameData *gameData, u32 a, u32 b);
extern void APP_TASKMENU_WIN_Update(struct TaskMenuWin *win);
extern u32 APP_TASKMENU_WIN_IsFinish(struct TaskMenuWin *win);
extern void APP_TASKMENU_WIN_ResetDecide(struct TaskMenuWin *win);
extern struct TaskMenuWin *APP_TASKMENU_WIN_Create(struct TaskMenuRes *res, TaskMenuItem *item, u8 y, u32 width, u32 height, u32 heapId);
extern u32 func_02040804(u32 layer);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void CLACT_ChangeActorAnimSeq(struct ClActor *actor, u16 v);
extern void func_02041EE4(u32 index, u32 a, u32 b);
extern void func_0204B404(struct ClActor *actor, const ClPos *delta, u32 which);
extern void GFL_USE_SetStereoOutput(u32 a);
extern struct TaskMenu *APP_TASKMENU_OpenMenu(TaskMenuTemplate *tmpl, struct TaskMenuRes *res);
extern void APP_TASKMENU_UpdateMenu(struct TaskMenu *menu);
extern u32 APP_TASKMENU_IsFinish(struct TaskMenu *menu);
extern u8 APP_TASKMENU_GetCursorPos(const struct TaskMenu *menu);
extern void APP_TASKMENU_CloseMenu(struct TaskMenu *menu);
extern void func_0207D658(u32, int, int);
extern unsigned int CONFIG_GetTextSpeed(struct Config *config);
extern u32 CONFIG_GetBattleScene(struct Config *config);
extern u32 CONFIG_GetBattleStyle(struct Config *config);
extern unsigned int CONFIG_GetSoundMode(struct Config *config);
extern int CONFIG_GetButtonMode(struct Config *config);
extern void CONFIG_SetTextSpeed(struct Config *config, unsigned int value);
extern void CONFIG_SetBattleScene(struct Config *config, unsigned int value);
extern void CONFIG_SetBattleStyle(struct Config *config, unsigned int value);
extern void CONFIG_SetSoundMode(struct Config *config, unsigned int value);
extern void CONFIG_SetButtonMode(struct Config *config, unsigned int value);
extern int func_0203EFC8(const u8 *, const u8 *, u32);
extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);
extern int FADE_IsActive(void);
extern u32 func_0201C6B4(const struct PrintSys *printSys);
extern int func_020071F0(struct SaveData *saveData);
extern void func_020419E4(void);
extern signed char func_02012FFC(void);

int OPTION_MENU_Init(struct Proc *proc, int *seq, OptionMenuArgs *args);
int OPTION_MENU_Exit(struct Proc *proc, int *seq, void *args, OptionMenuWork *work);
int OPTION_MENU_Main(struct Proc *proc, int *seq, void *args, OptionMenuWork *work);
void OPTION_MENU_InitScreen(OptionMenuScreen *screen, u16 heapId);
void OPTION_MENU_ExitScreen(OptionMenuScreen *screen);
void OPTION_MENU_UpdateScreen(OptionMenuScreen *screen);
struct ClActor *func_021B9944(OptionMenuScreen *screen, int index);
struct ClUnit *func_021B9950(OptionMenuScreen *screen);
struct BmpWindow *func_021B995C(OptionMenuScreen *screen, int index);
void func_021B9964(OptionMenuScreen *screen);
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
struct ClActor *OPTION_MENU_GetSpriteActor(OptionMenuSprites *sprites, int index);
struct ClUnit *OPTION_MENU_GetSpriteUnit(OptionMenuSprites *sprites);
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
void OPTION_MENU_InitButtons(OptionMenuButtons *buttons, struct ClUnit *unit, struct GfFont *font, struct PrintSys *printSys, struct MsgBank *msgBank, struct TaskMenuRes *menuRes, struct GameData *gameData, u16 heapId);
void OPTION_MENU_ExitButtons(OptionMenuButtons *buttons);
void OPTION_MENU_UpdateButtons(OptionMenuButtons *buttons, const OptionMenuInput *input, const OptionMenuList *list);
void OPTION_MENU_UpdateButtonWindows(OptionMenuButtons *buttons);
int OPTION_MENU_GetButtonChoice(OptionMenuButtons *buttons, int *choice);
u32 OPTION_MENU_IsButtonFinished(OptionMenuButtons *buttons);
void OPTION_MENU_ResetButtons(OptionMenuButtons *buttons);
void OPTION_MENU_CreateButtonWindows(OptionMenuButtons *buttons, u32 heapId);
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
u32 func_021BB0D0(const OptionSettings *settings);
int func_021BB0D8(OptionSettings *settings);
int OPTION_MENU_AreSettingsEqual(const OptionSettings *a, const OptionSettings *b);
void OPTION_MENU_InitRunner(OptionMenuRunner *runner, OptionMenuWork *work, OptionMenuStateFn callback);
void OPTION_MENU_ExitRunner(OptionMenuRunner *runner);
void OPTION_MENU_UpdateRunner(OptionMenuRunner *runner);
int func_021BB134(OptionMenuRunner *runner);
void func_021BB138(OptionMenuRunner *runner, OptionMenuStateFn callback);
void func_021BB140(OptionMenuRunner *runner);
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
extern OptionMenuLabel gOptionMenuLabels[];
extern s16 d_020A1B38[];
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

    func_02034AC4((u32)ov067_id);
    GFL_HEAP_CreateChildHeap(1, 0x1c, 0x21000);
    work = PROCSYS_AllocProcWork(proc, sizeof(OptionMenuWork), 0x1c);
    func_02082BCC(work, 0, sizeof(OptionMenuWork));
    work->args = args;
    work->args->result = 0;
    OPTION_MENU_InitScreen(&work->screen, 0x1c);
    work->font = GF_FONT_Create(0x17, 0, 0, 0, 0x1c);
    work->printSys = func_0201C440(0x1c);
    work->buttonMenuRes = APP_TASKMENU_RES_Create(0, 0xd, work->font, work->printSys, 0x1c);
    work->messageMenuRes = APP_TASKMENU_RES_Create(3, 9, work->font, work->printSys, 0x1c);
    work->msgBank = func_02045B38(0, 2, 0x1d, 0x1c);
    work->taskList = TCBL_Create(0x1c, 0x1c, 0x20, 0x20);
    OPTION_MENU_InitSettings(&work->savedSettings, func_0200873C(GAME_DATA_GetSaveControl(func_020120F4(work->args->gameSystem))));
    OPTION_MENU_InitRunner(&work->runner, work, OPTION_MENU_StateFadeIn);
    gameData = func_020120F4(work->args->gameSystem);
    OPTION_MENU_InitButtons(&work->buttons, func_021B9950(&work->screen), work->font, work->printSys, work->msgBank, work->buttonMenuRes, gameData, 0x1c);
    OPTION_MENU_InitList(&work->list, 1, 2, &work->screen, &work->savedSettings, 0x1c);
    OPTION_MENU_InitInput(&work->input, 0x1c);
    OPTION_MENU_InitTextBox(&work->helpText, func_021B995C(&work->screen, OPTION_WINDOW_DESCRIPTION), work->font, work->msgBank, work->taskList, work->printSys, 0x1c);
    OPTION_MENU_InitMessageBox(&work->messageBox, func_021B995C(&work->screen, OPTION_WINDOW_MESSAGE), work->font, work->msgBank, work->taskList, work->messageMenuRes, work->printSys, 0x1c);
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
    TCBL_Destroy(work->taskList);
    MSGDATA_Delete(work->msgBank);
    APP_TASKMENU_RES_Delete(work->messageMenuRes);
    APP_TASKMENU_RES_Delete(work->buttonMenuRes);
    func_0201C4C0(work->printSys);
    GF_FONT_Delete(work->font);
    OPTION_MENU_ExitScreen(&work->screen);
    func_020315D4(proc);
    func_020306F0(0x1c);
    func_02034A5C((int)ov067_id);
    return 1;
}

int OPTION_MENU_Main(struct Proc *proc, int *seq, void *args, OptionMenuWork *work)
{
    OPTION_MENU_UpdateRunner(&work->runner);
    OPTION_MENU_UpdateScreen(&work->screen);
    PRINTSYS_QUE_Main(work->printSys);
    TCBL_Main(work->taskList);
    OPTION_MENU_UpdateButtonWindows(&work->buttons);
    if (func_021BB134(&work->runner) != 0)
        return 1;
    return 0;
}

void OPTION_MENU_InitScreen(OptionMenuScreen *screen, u16 heapId)
{
    func_02082BCC(screen, 0, sizeof(OptionMenuScreen));
    REG_A_BLDCNT = 0;
    REG_B_BLDCNT = 0;
    REG_A_DISPCNT &= DISPCNT_WINDOWS_OFF;
    REG_B_DISPCNT &= DISPCNT_WINDOWS_OFF;
    BG_SYS_ClearGraphicsMemory(0);
    BG_SYS_SetVramBanks(&gOptionMenuDispVram);
    func_0204363C(0);
    BG_SYS_ResetSubDisplay();
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    func_0201DD60();
    GF_FONT_SetTextColor(0xf, 0xe, 0);
    OPTION_MENU_InitGfx(&screen->gfx, heapId);
    OPTION_MENU_InitSprites(&screen->sprites, &gOptionMenuDispVram, heapId);
    screen->task = func_020056A0(OPTION_MENU_ScreenTaskMain, screen, 0);
}

void OPTION_MENU_ExitScreen(OptionMenuScreen *screen)
{
    func_02030EAC(screen->task);
    OPTION_MENU_ExitSprites(&screen->sprites);
    OPTION_MENU_ExitGfx(&screen->gfx);
    func_0201DD68();
    REG_A_BLDCNT = 0;
    REG_B_BLDCNT = 0;
    REG_A_DISPCNT &= DISPCNT_WINDOWS_OFF;
    REG_B_DISPCNT &= DISPCNT_WINDOWS_OFF;
    func_02082BCC(screen, 0, sizeof(OptionMenuScreen));
}

void OPTION_MENU_UpdateScreen(OptionMenuScreen *screen)
{
    OPTION_MENU_UpdateSprites(&screen->sprites);
    OPTION_MENU_UpdateGfxBlink(&screen->gfx);
}

struct ClActor *func_021B9944(OptionMenuScreen *screen, int index)
{
    return OPTION_MENU_GetSpriteActor(&screen->sprites, index);
}

struct ClUnit *func_021B9950(OptionMenuScreen *screen)
{
    return OPTION_MENU_GetSpriteUnit(&screen->sprites);
}

struct BmpWindow *func_021B995C(OptionMenuScreen *screen, int index)
{
    return OPTION_MENU_GetGfxWindow(&screen->gfx, index);
}

void func_021B9964(OptionMenuScreen *screen)
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
 * note 2026-10-05 (recoup R14): func_02049658 returns u32 (as in ov210 021BC5DC); declared void it
 *   made the build copy the zero from r5 (adds rN,r5,#0) for the register zero arguments after
 *   02049BDC. EXACT in c99 and c with the u32 return.
 */
void OPTION_MENU_InitGfx(OptionMenuGfx *gfx, u16 heapId)
{
    void *arc;
    void *buffer;
    PaletteResource *pltt;
    int i;
    u32 layerId;

    func_02082BCC(gfx, 0, sizeof(OptionMenuGfx));
    func_0203F8F4(heapId);
    BMP_WIN_Init(heapId);
    func_0203FC28(&gOptionMenuDispConfig);
    for (i = 0; i < 6; i++) {
        layerId = gOptionMenuBgLayers[i].layerId;
        func_0203FCA0((u8)layerId, &gOptionMenuBgLayers[i].layout, (u8)gOptionMenuBgLayers[i].mapType);
        func_020414AC(layerId);
        func_02040588(layerId, 1);
    }
    func_02040588(3, 0);
    func_02040C14(4, 0, 1, 0);
    func_02040C14(3, 0, 1, 0);
    arc = func_020490F4(0x1b, heapId);
    func_02049B68(arc, 1, 0, 0, 0, heapId);
    func_02049658(arc, 0xd, 0, 0, 0, 0, heapId);
    func_020498F4(arc, 0xe, 0, 0, 0, 0, heapId);
    func_02049658(arc, 0, 2, 0, 0, 0, heapId);
    func_020498F4(arc, 2, 2, 0, 0, 0, heapId);
    func_02049658(arc, 0x10, 3, 1, 0, 0, heapId);
    ARC_UTIL_UploadPaletteFromHandle(arc, 8, 0, 0x80, 0x1e0, 0x20, heapId);
    gfx->screenBuffer = func_02049DF4(arc, 0xf, 0, &gfx->screenData, heapId);
    func_02049B68(arc, 8, 4, 0, 0, heapId);
    func_02049658(arc, 7, 5, 0, 0, 0, heapId);
    func_020498F4(arc, 9, 5, 0, 0, 0, heapId);
    func_02049658(arc, 0x10, 4, 1, 0, 0, heapId);
    ARC_TOOL_DeleteHandle(arc);
    buffer = func_02049F34(0x1b, 1, &pltt, heapId);
    func_02082D44(pltt->colors + 0xe0, gfx->palette, 0x20);
    func_020307B0(buffer);
    gfx->windows[OPTION_WINDOW_DESCRIPTION] = BMP_WIN_Create(4, 1, 0x13, 0x1e, 4, 4, 1);
    gfx->windows[OPTION_WINDOW_MESSAGE] = BMP_WIN_Create(3, 1, 1, 0x1e, 4, 0xf, 1);
    gfx->windows[OPTION_WINDOW_TITLE] = BMP_WIN_Create(0, 0, 0, 0x10, 3, 8, 1);
    OPTION_MENU_CreateLabelWindows(gfx);
    func_02040588(4, 0);
}

void OPTION_MENU_ExitGfx(OptionMenuGfx *gfx)
{
    int i;

    for (i = 0; i < OPTION_WINDOW_COUNT; i++) {
        if (gfx->windows[i] != 0) {
            func_020452E8(gfx->windows[i]);
        }
    }
    func_020307B0(gfx->screenBuffer);
    func_02040DA8(4, 1, 0);
    i = 0;
    func_02040DA8(3, 1, 0);
    for (i = 0; i < 6; i++) {
        func_020403F4((u8)gOptionMenuBgLayers[i].layerId);
    }
    BMP_WIN_Exit();
    func_0203F9B4();
    func_02082BCC(gfx, 0, sizeof(OptionMenuGfx));
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
 * func_0201D304 takes the string first and the font second.
 */
void OPTION_MENU_CreateLabelWindows(OptionMenuGfx *gfx)
{
    struct GfFont *font;
    struct MsgBank *msgBank;
    struct StringBuf *str;
    struct BmpWindow *window;
    u8 *charData;
    int i;
    int x;
    OptionMenuLabel *label;
    u8 width;

    font = GF_FONT_Create(0x17, 0, 0, 0, 0x1c);
    msgBank = func_02045B38(0, 2, 0x1d, 0x1c);
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
        label = &gOptionMenuLabels[i];
        str = func_02045EC0(msgBank, gOptionMenuLabels[i].messageId);
        width = (x + func_0201D304(str, font, 0) + 7) >> 3;
        label->width = width;
        gfx->windows[i] = BMP_WIN_Create(1, label->x, label->y, width, label->height, 0, 1);
        BMP_Clear(func_02045770(gfx->windows[i]), 0);
        PRINTSYS_Print(func_02045770(gfx->windows[i]), x, 0, str, font);
        window = gfx->windows[i];
        BMP_WIN_TransferChars(window);
        BMP_WIN_MakeScreen(window);
        func_02041B6C(func_02045730(window));
        STRBUF_Delete(str);
    }
    charData = gfx->screenData->charData;
    func_02082A90((u32)charData, (u32)BMP_GetPixels(func_02045770(gfx->windows[OPTION_WINDOW_TITLE])), 0x600);
    str = func_02045EC0(msgBank, 0);
    x = func_02045738(gfx->windows[OPTION_WINDOW_TITLE]) * 4;
    x -= func_0201D304(str, font, 0) >> 1;
    PRINTSYS_PrintColor(func_02045770(gfx->windows[OPTION_WINDOW_TITLE]), x, 4, str, font, 0x3dc1);
    window = gfx->windows[OPTION_WINDOW_TITLE];
    BMP_WIN_TransferChars(window);
    BMP_WIN_MakeScreen(window);
    func_02041B6C(func_02045730(window));
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
    func_020419E4();
}

/*
 * BGR555 cross-fade of one palette entry: advance the u16 phase at *angle by
 * step (wrapping at 0x10000), take weight = (table[phase >> 4 pair, second entry]
 * + 0x1000) / 2 as an s16 from the table at 0x020A1B38, blend each channel
 * of color0 toward color1 by weight >> 12, store to *outColor and hand it to func_02061CA4.
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
    weight = (d_020A1B38[((*angle >> 4) << 1) + 1] + 0x1000) / 2;
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
    func_02061CA4(15, paletteIndex * 32 + slot * 2, outColor, 2);
}

void OPTION_MENU_InitSprites(OptionMenuSprites *sprites, const void *res, u32 heapId)
{
    ClActorParam param;
    void *arc;
    int i;

    func_02082BCC(sprites, 0, 0x54);
    CLACT_InitSystem(&gClActorInitParam, res, heapId);
    sprites->unit = CLACT_CreateUnit(0x80, 0, heapId);
    CLACT_SetUnitDefaultRenderer(sprites->unit);
    func_020434DC(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
    arc = func_020490F4(0x1b, heapId);
    sprites->plttRes = CLACT_RegisterPalette(arc, 6, 0, 0, heapId);
    sprites->mainCharRes = CLACT_RegisterCharacter(arc, 5, 0, 0, heapId);
    sprites->mainCellRes = CLACT_RegisterCellAnim(arc, 4, 3, heapId);
    sprites->subCharRes = CLACT_RegisterCharacter(arc, 0xc, 0, 0, heapId);
    sprites->subCellRes = CLACT_RegisterCellAnim(arc, 0xb, 0xa, heapId);
    ARC_TOOL_DeleteHandle(arc);
    func_02082BCC(&param, 0, 8);
    param.bgPriority = 2;
    param.priority = 2;
    for (i = OPTION_ACTOR_CHOICE_FIRST; i < OPTION_ACTOR_CHOICE_FIRST + OPTION_ACTOR_CHOICE_COUNT; i++) {
        param.x = gOptionMenuChoices[i - 2].actorX;
        param.y = gOptionMenuChoices[i - 2].actorY;
        sprites->actors[i] = CLACT_CreateActor(sprites->unit, sprites->mainCharRes, sprites->plttRes, sprites->mainCellRes, &param, 0, heapId);
        func_0204B92C(sprites->actors[i], 0);
    }
    func_02082BCC(&param, 0, 8);
    param.x = 0x80;
    param.y = 0x60;
    param.bgPriority = 2;
    param.priority = 1;
    sprites->actors[OPTION_ACTOR_CURSOR] = CLACT_CreateActor(sprites->unit, sprites->subCharRes, sprites->plttRes, sprites->subCellRes, &param, 0, heapId);
    func_0204B6F4(sprites->actors[OPTION_ACTOR_CURSOR], 6, 1);
    if (GFL_NET_GetRunState())
        GFL_NET_RestartWithDefaultTimeout(1, heapId);
}

void OPTION_MENU_ExitSprites(OptionMenuSprites *sprites)
{
    int i;

    for (i = 0; i < OPTION_ACTOR_COUNT; i++) {
        if (sprites->actors[i] != 0) {
            CLACT_DeleteActor(sprites->actors[i]);
        }
    }
    CLACT_ReleasePalette(sprites->plttRes);
    CLACT_ReleaseCharacter(sprites->mainCharRes);
    CLACT_ReleaseCellAnim(sprites->mainCellRes);
    CLACT_ReleaseCharacter(sprites->subCharRes);
    CLACT_ReleaseCellAnim(sprites->subCellRes);
    CLACT_DeleteUnit(sprites->unit);
    CLACT_ExitSystem();
    func_02082BCC(sprites, 0, 0x54);
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
        CLACT_SetActorAnimIndex(sprites->actors[i], (u16)(sprites->animFrame / 12));
    }
    CLACT_DrawSystem();
}

void OPTION_MENU_DrawSprites(OptionMenuSprites *sprites) { CLACT_VBlankSystem(); }

struct ClActor *OPTION_MENU_GetSpriteActor(OptionMenuSprites *sprites, int index)
{
    return sprites->actors[index];
}

struct ClUnit *OPTION_MENU_GetSpriteUnit(OptionMenuSprites *sprites)
{
    return sprites->unit;
}

/*
 * Two identical wrappers around func_02082BCC(p, 0, 0x20).
 */
void OPTION_MENU_InitInput(OptionMenuInput *input, int heapId)
{
    func_02082BCC(input, 0, 0x20);
}

void OPTION_MENU_ExitInput(OptionMenuInput *input)
{
    func_02082BCC(input, 0, 0x20);
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
    if (func_02035D20(&x, &y)) {
        input->command = OPTION_INPUT_TOUCH;
        input->startX = x;
        input->startY = y;
        input->lastX = x;
        input->lastY = y;
        input->touching = 1;
    } else if (TOUCHPANEL_GetPointCont(&x, &y) && input->touching != 0) {
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
    trigger = func_020362DC();
    held = func_0203630C();
    if (trigger != 0 && func_020355C4() == 1 && (trigger & (OPTION_KEY_X | OPTION_KEY_Y | OPTION_KEY_B)) == 0) {
        func_020355D8(0);
        input->command = OPTION_INPUT_KEY_ACTIVATE;
        func_020061E4(OPTION_SE_CURSOR);
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
        func_020355D8(0);
        input->command = OPTION_INPUT_CANCEL;
        return;
    }
    if (trigger & OPTION_KEY_X) {
        func_020355D8(0);
        input->command = OPTION_INPUT_SHORTCUT_X;
        return;
    }
    if (trigger & OPTION_KEY_Y) {
        func_020355D8(0);
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

    func_02082BCC(box, 0, sizeof(OptionMenuTextBox));
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
    func_02028470(&box->waitState, 0x406);
    func_0201F73C(box->window, 2, 1, BMP_WIN_GetPalette(window));
    BMP_Clear(func_02045770(box->window), (u8)box->fillColor);
    printWindow = box->window;
    BMP_WIN_TransferChars(printWindow);
    BMP_WIN_MakeScreen(printWindow);
    func_020409B4(func_02045730(printWindow));
    box->printWindow = box->window;
    box->printing = 0;
}

void OPTION_MENU_ExitTextBox(OptionMenuTextBox *box)
{
    if (box->stream != 0) {
        func_0201CE48(box->stream);
        box->stream = 0;
    }
    STRBUF_Delete(box->buffer);
    func_02082BCC(box, 0, sizeof(OptionMenuTextBox));
}

void OPTION_MENU_PrintText(OptionMenuTextBox *box, u32 messageId, u32 wait, u32 useStream)
{
    OPTION_MENU_PrintTextFromBank(box, box->msgBank, messageId, wait, useStream);
}

/* useStream 0 prints at once through the print system, otherwise a print stream runs. */
void OPTION_MENU_PrintTextFromBank(OptionMenuTextBox *box, struct MsgBank *msgBank, u32 messageId, u32 wait, u32 useStream)
{
    struct PrintSys *printSys;

    BMP_Clear(func_02045770(box->window), (u8)box->fillColor);
    func_02045CAC(msgBank, messageId, box->buffer);
    if (box->stream != 0) {
        func_0201CE48(box->stream);
        box->stream = 0;
    }
    if (useStream == 0) {
        printSys = box->printSys;
        func_0201C6FC(printSys, func_02045770(box->printWindow), 0, 0,
                      box->buffer, box->font);
        box->printing = 1;
        box->mode = 2;
        return;
    }
    box->stream = PRINTSYS_PrintStream(box->window, 0, 0, box->buffer,
                                box->font, wait, box->taskList, 0,
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
            if (func_0201C6C4(printSys, func_02045770(box->printWindow)) == 0) {
                BMP_WIN_TransferChars(box->printWindow);
                box->printing = 0;
            }
        }
        if (box->printing == 0) {
            return 1;
        }
        return 0;
    case 1:
        return func_02028484(&box->waitState, box->stream);
    }
}

void OPTION_MENU_InitButtons(OptionMenuButtons *buttons, struct ClUnit *unit, struct GfFont *font, struct PrintSys *printSys, struct MsgBank *msgBank, struct TaskMenuRes *menuRes, struct GameData *gameData, u16 heapId)
{
    ReturnButtonCells cells;
    ReturnButtonRequest request;

    func_02082BCC(buttons, 0, sizeof(OptionMenuButtons));
    buttons->choice = OPTION_BUTTON_NONE;
    buttons->font = font;
    buttons->menuRes = menuRes;
    buttons->msgBank = msgBank;
    buttons->printSys = printSys;
    buttons->gameData = gameData;
    cells = gOptionMenuReturnButtonCells;
    func_02082BCC(&request, 0, 0x20);
    request.cells = &cells;
    request.cellCount = 2;
    request.unit = unit;
    request.size = 8;
    request.enabled = 1;
    request.priority = 2;
    buttons->returnButton = TOUCHBAR_Create(&request, heapId);
    OPTION_MENU_CreateButtonWindows(buttons, heapId);
    if (GAME_DATA_CheckSaveFlag(buttons->gameData, 0x18) != 0) {
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
        STRBUF_Delete(buttons->items[i].label);
        APP_TASKMENU_WIN_Delete(buttons->buttons[i]);
    }
    func_02082BCC(buttons, 0, sizeof(OptionMenuButtons));
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
            func_02040588(4, 0);
            func_020061E4(OPTION_SE_CONFIRM);
            buttons->choice = OPTION_BUTTON_CONFIRM;
            buttons->decided = 1;
            buttons->focusChanged = 1;
            if (func_020355C4() == 0)
                func_020355D8(1);
        } else if (OPTION_MENU_IsPointInRect(&gOptionMenuCancelRect, &touch) && buttons->choice != OPTION_BUTTON_CANCEL) {
            func_02040588(4, 0);
            func_020061E4(OPTION_SE_CANCEL);
            buttons->choice = OPTION_BUTTON_CANCEL;
            buttons->decided = 1;
            buttons->focusChanged = 1;
            if (func_020355C4() == 0)
                func_020355D8(1);
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
            func_020061E4_2(buttons->choice == OPTION_BUTTON_CANCEL ? OPTION_SE_CANCEL : OPTION_SE_CONFIRM);
        } else {
            buttons->choice = OPTION_BUTTON_CONFIRM;
            func_020061E4(OPTION_SE_CONFIRM);
        }
        refresh = 1;
        buttons->decided = 1;
        break;
    case OPTION_INPUT_CANCEL:
        func_020061E4(OPTION_SE_CANCEL);
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
            if (result == 6 && func_020355C4() == 1)
                buttons->focusChanged = 1;
        } else {
            if (func_020355C4() == 1)
                buttons->focusChanged = 1;
        }
        result = TOUCHBAR_GetPressedButtonIdIfDone(buttons->returnButton);
        if (result != 0) {
            if (result == 6) {
                if (func_021B65A8(buttons->returnButton, 6))
                    GAME_DATA_SetSaveFlag(buttons->gameData, 0x18, 1);
                else
                    GAME_DATA_SetSaveFlag(buttons->gameData, 0x18, 0);
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

void OPTION_MENU_CreateButtonWindows(OptionMenuButtons *buttons, u32 heapId)
{
    int i;

    for (i = 0; i < 2; i++) {
        if (buttons->items[i].label != 0) {
            STRBUF_Delete(buttons->items[i].label);
        }
        buttons->items[i].label = func_02045EC0(buttons->msgBank, i + 8);
        buttons->items[i].color = 0x39e3;
        buttons->items[i].value = i;
        if (buttons->buttons[i] != 0) {
            APP_TASKMENU_WIN_Delete(buttons->buttons[i]);
        }
        buttons->buttons[i] =
            APP_TASKMENU_WIN_Create(buttons->menuRes, &buttons->items[i], i * 9 + 14, 0x15, 9, heapId);
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

    func_02082BCC(list, 0, sizeof(OptionMenuList));
    list->mainLayer = mainLayer;
    list->subLayer = subLayer;
    list->scrollY = 0x10;
    list->settings = *settings;
    for (i = 0; i < OPTION_ACTOR_CHOICE_COUNT; i++) {
        list->choiceActors[i] = func_021B9944(screen, i + OPTION_ACTOR_CHOICE_FIRST);
    }
    OPTION_MENU_ScrollList(list, -8, -192, 192);
    if (func_020355C4() == 1) {
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
    func_02082BCC(list, 0, sizeof(OptionMenuList));
}

/*
 * The 0/1/2 test on func_021BB0D8's result is a switch with three empty
 * labels: `r == 0 || r == 1 || r == 2` folds to one unsigned `cmp #2`.
 */
void OPTION_MENU_UpdateList(OptionMenuList *list, const OptionMenuInput *input, OptionMenuTextBox *helpText, OptionMenuScreen *screen, OptionMenuButtons *buttons)
{
    OptionMenuPoint touch;
    int command;
    int useStream;
    u32 wait;

    command = OPTION_MENU_GetInputCommand(input);
    func_02040804(list->subLayer);
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
        func_020061E4(OPTION_SE_CURSOR);
        OPTION_MENU_DrawList(list, 1);
        func_021B9964(screen);
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
        func_020061E4(OPTION_SE_CURSOR);
        OPTION_MENU_DrawList(list, 1);
        func_021B9964(screen);
        break;
    case OPTION_INPUT_TOUCH:
        OPTION_MENU_GetInputPoint(input, 0, &touch);
        if (touch.y < 0x18 || touch.y > 0xA8)
            break;
        list->cursor = OPTION_MENU_GetRowAtTouch(list, &touch);
        OPTION_MENU_SelectChoiceAtTouch(list, &touch);
        OPTION_MENU_DrawList(list, 0);
        func_021B9964(screen);
        list->redraw = 1;
        if (func_020355C4() == 0)
            func_020355D8(1);
        break;
    case OPTION_INPUT_RIGHT:
        if (list->cursor < OPTION_COUNT) {
            func_020061E4(OPTION_SE_CURSOR);
            OPTION_MENU_StepSelectedSetting(list, 1);
            OPTION_MENU_DrawList(list, 1);
            func_021B9964(screen);
        } else if (list->cursor == OPTION_CURSOR_CONFIRM) {
            (list->cursor)++;
            func_020061E4(OPTION_SE_CURSOR);
            list->cursor = list->cursor > OPTION_CURSOR_CANCEL ? OPTION_CURSOR_CANCEL : (list->cursor < 0 ? 0 : list->cursor);
        }
        break;
    case OPTION_INPUT_LEFT:
        if (list->cursor < OPTION_COUNT) {
            func_020061E4(OPTION_SE_CURSOR);
            OPTION_MENU_StepSelectedSetting(list, -1);
            OPTION_MENU_DrawList(list, 1);
            func_021B9964(screen);
        } else if (list->cursor == OPTION_CURSOR_CANCEL) {
            (list->cursor)--;
            func_020061E4(OPTION_SE_CURSOR);
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
    switch (func_021BB0D8(&list->settings)) {
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
                wait = func_021BB0D0(&list->settings);
            } else {
                useStream = 0;
                wait = 0;
            }
            func_02040588(4, 1);
            OPTION_MENU_PrintText(helpText, gOptionMenuSettingRows[list->cursor].descriptionId, wait, useStream);
        } else {
            func_02040588(4, 0);
        }
        list->redraw = 0;
    }
    OPTION_MENU_IsTextDone(helpText);
    OPTION_MENU_ShiftInputTrail(list);
}

void OPTION_MENU_ClearListHighlight(OptionMenuList *list, OptionMenuScreen *screen)
{
    OPTION_MENU_DrawList(list, 0);
    func_02040588(4, 0);
    func_021B9964(screen);
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

    if (list->cursor >= OPTION_COUNT)
        highlight = 0;
    list->highlight = highlight;
    base = ((int)func_02040804(list->subLayer) + 0x14) / 0x18;
    func_020413B0((u8)(list->subLayer), 0, 0, 0x20, 0x20, 5);
    i = 0;
    for (k = 0; k < OPTION_COUNT; k++)
        func_020413B0((u8)(list->subLayer), i, (base + k) * 3 + 2, 0x20, 3, gOptionMenuRowPalettes[k]);
    for (i = 0; i < OPTION_ACTOR_CHOICE_COUNT; i++) {
        if (list->cursor == gOptionMenuChoices[i].settingIndex && highlight) {
            if (OPTION_MENU_IsChoiceSelected(&list->settings, i))
                func_020413B0((u8)(list->mainLayer), gOptionMenuLabels[i].x, gOptionMenuLabels[i].y, gOptionMenuLabels[i].width, gOptionMenuLabels[i].height, 7);
            else
                func_020413B0((u8)(list->mainLayer), gOptionMenuLabels[i].x, gOptionMenuLabels[i].y, gOptionMenuLabels[i].width, gOptionMenuLabels[i].height, 0xC);
        } else {
            if (OPTION_MENU_IsChoiceSelected(&list->settings, i))
                func_020413B0((u8)(list->mainLayer), gOptionMenuLabels[i].x, gOptionMenuLabels[i].y, gOptionMenuLabels[i].width, gOptionMenuLabels[i].height, 0);
            else
                func_020413B0((u8)(list->mainLayer), gOptionMenuLabels[i].x, gOptionMenuLabels[i].y, gOptionMenuLabels[i].width, gOptionMenuLabels[i].height, 3);
        }
    }
    for (i = OPTION_ACTOR_CHOICE_COUNT; i < OPTION_WINDOW_LABEL_COUNT; i++) {
        if (i - OPTION_ACTOR_CHOICE_COUNT == list->cursor && highlight)
            func_020413B0((u8)(list->mainLayer), gOptionMenuLabels[i].x, gOptionMenuLabels[i].y, gOptionMenuLabels[i].width, gOptionMenuLabels[i].height, 7);
        else
            func_020413B0((u8)(list->mainLayer), gOptionMenuLabels[i].x, gOptionMenuLabels[i].y, gOptionMenuLabels[i].width, gOptionMenuLabels[i].height, 0);
    }
    if (highlight)
        func_020413B0((u8)(list->subLayer), 0, list->cursor * 3 + 2, 0x20, 3, 7);
    func_02041B6C((u8)(list->subLayer));
    func_02041B6C((u8)(list->mainLayer));
    for (i = 0; i < OPTION_ACTOR_CHOICE_COUNT; i++) {
        if (list->cursor == gOptionMenuChoices[i].settingIndex && highlight) {
            if (OPTION_MENU_IsChoiceSelected(&list->settings, i))
                CLACT_ChangeActorAnimSeq(list->choiceActors[i], 3);
            else
                CLACT_ChangeActorAnimSeq(list->choiceActors[i], 2);
        } else {
            if (OPTION_MENU_IsChoiceSelected(&list->settings, i))
                CLACT_ChangeActorAnimSeq(list->choiceActors[i], 0);
            else
                CLACT_ChangeActorAnimSeq(list->choiceActors[i], 1);
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

    t = func_02040804(list->subLayer);
    v = t + delta;
    if (v > max) {
        v = max;
    } else if (v < min) {
        v = min;
    }
    func_02041EE4((u8)list->mainLayer, 3, v + 0x14);
    func_02041EE4((u8)list->subLayer, 3, v);
    t = list->scrollY - delta;
    list->scrollY = t;
    list->scrollY = t > 0x10 - min ? 0x10 - min : (t < 0x10 - max ? 0x10 - max : t);
    for (i = 0; i < OPTION_ACTOR_CHOICE_COUNT; i++) {
        pos.x = gOptionMenuChoices[i].actorX;
        pos.y = list->scrollY + gOptionMenuChoices[i].actorY;
        func_0204B404(list->choiceActors[i], &pos, 0);
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
                func_020061E4(OPTION_SE_CURSOR);
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
    row = func_02040804(list->subLayer);
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

    func_02082BCC(box, 0, sizeof(OptionMenuMessageBox));
    box->answer = 0;
    box->menuRes = menuRes;
    OPTION_MENU_InitTextBox(&box->text, window, font, msgBank, taskList, printSys, heapId);
    for (i = 0; i < 2; i++) {
        box->items[i].label = func_02045EC0(msgBank, i + 0x22);
        box->items[i].color = 0x39E3;
        box->items[i].value = 0;
    }
    box->menuTemplate.heapId = heapId;
    box->menuTemplate.itemCount = 2;
    box->menuTemplate.items = box->items;
    box->menuTemplate.cursorType = 1;
    box->menuTemplate.tileOffset = 0x20;
    box->menuTemplate.cursorPalette = 0xc;
    box->menuTemplate.windowPalette = 0xd;
    box->menuTemplate.textColor = 3;
}

void OPTION_MENU_ExitMessageBox(OptionMenuMessageBox *box)
{
    int i;
    for (i = 0; i < 2; i++) STRBUF_Delete(box->items[i].label);
    OPTION_MENU_ExitTextBox(&box->text);
    func_02082BCC(box, 0, sizeof(OptionMenuMessageBox));
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
        box->menu = APP_TASKMENU_OpenMenu(&box->menuTemplate, box->menuRes);
        box->phase = 2;
        break;
    case 2:
        APP_TASKMENU_UpdateMenu(box->menu);
        if (APP_TASKMENU_IsFinish(box->menu) != 0) {
            box->answer = APP_TASKMENU_GetCursorPos(box->menu) + 1;
            box->phase = 3;
            APP_TASKMENU_CloseMenu(box->menu);
        }
        break;
    }
}

void OPTION_MENU_PrintDiscardPrompt(OptionMenuMessageBox *box, u32 wait)
{
    func_0207D658(REG_A_BLDCNT_ADDR, 23, 8);
    func_02040588(3, 1);
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

    func_0207D658(REG_A_BLDCNT_ADDR, 0x17, 8);
    func_02040588(3, 1);
    msgBank = func_02045B38(0, 3, 0x9e, 0x801C);
    OPTION_MENU_PrintTextFromBank(&box->text, msgBank, messageId, wait, 1);
    MSGDATA_Delete(msgBank);
}

/*
 * Interface: full-width r1 is forwarded through 021BA278 to 021BA28C;
 * the legacy u16 extern has no caller truncation witness here.
 */
void OPTION_MENU_PrintMessage(OptionMenuMessageBox *box, u32 messageId, u32 wait)
{
    func_0207D658(REG_A_BLDCNT_ADDR, 23, 8);
    func_02040588(3, 1);
    OPTION_MENU_PrintText(&box->text, messageId, wait, 1);
}

int OPTION_MENU_IsMessageDone(OptionMenuMessageBox *box)
{
    if (OPTION_MENU_IsTextDone(&box->text)) {
        REG_A_BLDCNT = 0;
        func_02040588(3, 0);
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
    func_02082BCC(settings, 0, sizeof(OptionSettings));
    settings->lastChanged = OPTION_NO_CHANGE;
    settings->config = config;
    settings->values[OPTION_TEXT_SPEED] = CONFIG_GetTextSpeed(config);
    settings->values[OPTION_BATTLE_SCENE] = CONFIG_GetBattleScene(config);
    settings->values[OPTION_BATTLE_STYLE] = CONFIG_GetBattleStyle(config);
    settings->values[OPTION_SOUND_MODE] = CONFIG_GetSoundMode(config);
    settings->values[OPTION_BUTTON_MODE] = CONFIG_GetButtonMode(config);
}

void OPTION_MENU_ExitSettings(OptionSettings *settings)
{
    func_02082BCC(settings, 0, sizeof(OptionSettings));
}

/* Writes the five settings back to the config. */
void OPTION_MENU_WriteSettings(const OptionSettings *settings)
{
    CONFIG_SetTextSpeed(settings->config, settings->values[OPTION_TEXT_SPEED]);
    CONFIG_SetBattleScene(settings->config, settings->values[OPTION_BATTLE_SCENE]);
    CONFIG_SetBattleStyle(settings->config, settings->values[OPTION_BATTLE_STYLE]);
    CONFIG_SetSoundMode(settings->config, settings->values[OPTION_SOUND_MODE]);
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
u32 func_021BB0D0(const OptionSettings *settings)
{
    func_02012FFC();
}

/* Returns the index of the setting changed since the last call and clears it. */
int func_021BB0D8(OptionSettings *settings)
{
    unsigned char old = settings->lastChanged;
    settings->lastChanged = OPTION_NO_CHANGE;
    return old;
}

int OPTION_MENU_AreSettingsEqual(const OptionSettings *a, const OptionSettings *b)
{
    if (func_0203EFC8(a->values, b->values, OPTION_COUNT) == 0) return 1;
    return 0;
}

void OPTION_MENU_InitRunner(OptionMenuRunner *runner, OptionMenuWork *work, OptionMenuStateFn callback)
{
    func_02082BCC(runner, 0, 16);
    runner->work = work;
    func_021BB138(runner, callback);
}

/*
 * Tail call to func_02082BCC(p, 0, 0x10).
 */
void OPTION_MENU_ExitRunner(OptionMenuRunner *runner)
{
    func_02082BCC(runner, 0, 0x10);
}

void OPTION_MENU_UpdateRunner(OptionMenuRunner *runner)
{
    if (runner->finished == 0)
        runner->callback(runner, &runner->state, runner->work);
}

int func_021BB134(OptionMenuRunner *runner)
{
    return runner->finished;
}

/*
 * Getter and two small setters.
 */
void func_021BB138(OptionMenuRunner *runner, OptionMenuStateFn callback)
{
    runner->callback = callback;
    runner->state = 0;
}

void func_021BB140(OptionMenuRunner *runner)
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
        func_021BB138(runner, OPTION_MENU_StateMain);
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
        func_021BB140(runner);
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

    if (func_0201C6B4(work->printSys) == 0)
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
                    func_021BB138(runner, OPTION_MENU_StateApply);
                break;
            case OPTION_BUTTON_RETURN:
                work->args->result = 1;
                OPTION_MENU_GetListSettings(&work->list, &settingsReturn);
                if (OPTION_MENU_AreSettingsEqual(&work->savedSettings, &settingsReturn)) {
                    func_021BB138(runner, OPTION_MENU_StateKeepSaved);
                } else {
                    OPTION_MENU_ResetButtons(&work->buttons);
                    func_021BB138(runner, OPTION_MENU_StateDiscardPrompt);
                }
                break;
            case OPTION_BUTTON_CANCEL:
                if (OPTION_MENU_IsButtonFinished(&work->buttons)) {
                    OPTION_MENU_GetListSettings(&work->list, &settingsCancel);
                    if (OPTION_MENU_AreSettingsEqual(&work->savedSettings, &settingsCancel)) {
                        func_021BB138(runner, OPTION_MENU_StateKeepSaved);
                    } else {
                        OPTION_MENU_ResetButtons(&work->buttons);
                        func_021BB138(runner, OPTION_MENU_StateDiscardPrompt);
                    }
                }
                break;
            }
        }
        tutorialPending = func_020071F0(GAME_DATA_GetSaveControl(func_020120F4(work->args->gameSystem)));
        OPTION_MENU_GetListSettings(&work->list, &settingsCurrent);
        if (settingsCurrent.values[OPTION_BUTTON_MODE] == 0 && tutorialPending != 0)
            *state = 1;
        break;
    case 1:
        OPTION_MENU_GetListSettings(&work->list, &settingsTextSpeed);
        OPTION_MENU_PrintMessage(&work->messageBox, 0x20, func_021BB0D0(&settingsTextSpeed));
        OPTION_MENU_SetListButtonMode(&work->list, 1);
        *state = 5;
        break;
    case 2:
        OPTION_MENU_GetListSettings(&work->list, &settingsBattleScene);
        OPTION_MENU_PrintHelpMessage(&work->messageBox, 0x16, func_021BB0D0(&settingsBattleScene));
        OPTION_MENU_RedrawList(&work->list, 0);
        *state = 5;
        break;
    case 3:
        OPTION_MENU_GetListSettings(&work->list, &settingsBattleStyle);
        OPTION_MENU_PrintHelpMessage(&work->messageBox, 0x16, func_021BB0D0(&settingsBattleStyle));
        OPTION_MENU_RedrawList(&work->list, 0);
        *state = 5;
        break;
    case 4:
        OPTION_MENU_GetListSettings(&work->list, &settingsSound);
        OPTION_MENU_PrintMessage(&work->messageBox, 0x24, func_021BB0D0(&settingsSound));
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
        OPTION_MENU_PrintDiscardPrompt(&work->messageBox, func_021BB0D0(&settings));
        func_02040588(4, 0);
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
        func_021BB138(runner, OPTION_MENU_StateApply);
        break;
    case 3:
        func_021BB138(runner, OPTION_MENU_StateKeepSaved);
        break;
    }
    OPTION_MENU_UpdateMessageBox(&work->messageBox);
}

/* Keeps the saved settings and leaves. */
void OPTION_MENU_StateKeepSaved(OptionMenuRunner *runner, u32 *state, OptionMenuWork *work)
{
    OPTION_MENU_WriteSettings(&work->savedSettings);
    OPTION_MENU_ApplySoundMode(&work->list, (s8)work->savedSettings.values[OPTION_SOUND_MODE], 1);
    func_021BB138(runner, OPTION_MENU_StateFadeOut);
}

/* Writes the edited settings and leaves. */
void OPTION_MENU_StateApply(OptionMenuRunner *runner, u32 *state, OptionMenuWork *work)
{
    OptionSettings settings;

    OPTION_MENU_GetListSettings(&work->list, &settings);
    OPTION_MENU_WriteSettings(&settings);
    func_020061E4(OPTION_SE_APPLY);
    func_021BB138(runner, OPTION_MENU_StateFadeOut);
}

/* Inclusive rectangle hit test (unsigned range compare per axis). */
int OPTION_MENU_IsPointInRect(const OptionMenuRect *rect, const OptionMenuPoint *point)
{
    u32 inX = ((u32)point->x - (u32)rect->left) <= ((u32)rect->right - (u32)rect->left);
    u32 inY = ((u32)point->y - (u32)rect->top) <= ((u32)rect->bottom - (u32)rect->top);
    return inX & inY;
}

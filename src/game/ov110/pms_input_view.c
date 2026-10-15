/*
 * file:     pms_input_view.c
 * unit:     yes
 * function: PMS_INPUT_VIEW_Create, PMS_INPUT_VIEW_Delete, PMS_INPUT_VIEW_AddVBlankTask, PMS_INPUT_VIEW_MainTask, PMS_INPUT_VIEW_VBlankTask, PMS_INPUT_VIEW_StartTask, PMS_INPUT_VIEW_IsIdle, PMS_INPUT_VIEW_IsTaskNotRunning, PMS_INPUT_VIEW_EndTask, PMS_INPUT_VIEW_TaskInit, PMS_INPUT_VIEW_RegisterSpriteResources, PMS_INPUT_VIEW_TaskExit, PMS_INPUT_VIEW_InitDisplay, PMS_INPUT_VIEW_TaskFadeIn, PMS_INPUT_VIEW_TaskActivateEdit, PMS_INPUT_VIEW_TaskUpdateEditFocus, PMS_INPUT_VIEW_TaskUpdateCategoryFocus, PMS_INPUT_VIEW_TaskUpdateWordwinFocus, PMS_INPUT_VIEW_TaskPickMenuItemDecided, PMS_INPUT_VIEW_TaskPickMenuItem, PMS_INPUT_VIEW_TaskLeaveMenu, PMS_INPUT_VIEW_TaskShowCategory, PMS_INPUT_VIEW_TaskRefreshCategory, PMS_INPUT_VIEW_TaskMenuToCategory, PMS_INPUT_VIEW_TaskCategoryToMenu, PMS_INPUT_VIEW_TaskCategoryToWordwin, PMS_INPUT_VIEW_TaskWordwinToCategory, PMS_INPUT_VIEW_TaskWordwinToEdit, PMS_INPUT_VIEW_TaskCloseWordwin, PMS_INPUT_VIEW_TaskSetEditCursor, PMS_INPUT_VIEW_TaskSetMenuActive, PMS_INPUT_VIEW_TaskSetCategoryPosition, PMS_INPUT_VIEW_TaskSetWordwinCursor, PMS_INPUT_VIEW_TaskScrollWordwin, PMS_INPUT_VIEW_TaskSetMenuDecide, PMS_INPUT_VIEW_TaskEndOnly1, PMS_INPUT_VIEW_TaskResetEditCursor, PMS_INPUT_VIEW_TaskEndOnly2, PMS_INPUT_VIEW_TaskEndOnly3, PMS_INPUT_VIEW_TaskEndOnly4, PMS_INPUT_VIEW_TaskEndOnly5, PMS_INPUT_VIEW_TaskRefreshCategoryMenu, PMS_INPUT_VIEW_TaskSetWordwinScroll, PMS_INPUT_VIEW_TaskUpdateMenuDecide, PMS_INPUT_VIEW_TaskSetCategoryScroll, PMS_INPUT_VIEW_TaskSetWordwinPage, PMS_INPUT_VIEW_GetEditValue, PMS_INPUT_VIEW_GetEditEntry, PMS_INPUT_VIEW_SetEditText, PMS_INPUT_VIEW_GetMenuResult, PMS_INPUT_VIEW_SetMenuItemMode, PMS_INPUT_VIEW_GetMenu, PMS_INPUT_VIEW_GetClactUnit, PMS_INPUT_VIEW_GetFont, PMS_INPUT_VIEW_GetPrintQue, PMS_INPUT_VIEW_GetCursorRes, PMS_INPUT_VIEW_GetUiRes, PMS_INPUT_VIEW_CreateActor, PMS_INPUT_VIEW_CompareWordwinPosition, PMS_INPUT_VIEW_SetWordwinScrollOffset, PMS_INPUT_VIEW_GetWordwinItem, PMS_INPUT_VIEW_LoadBgPalette, PMS_INPUT_VIEW_PrintHelpMessage, PMS_INPUT_VIEW_FlushHelpText, PMS_INPUT_VIEW_UpdateEditFocus, PMS_INPUT_VIEW_UpdateCategoryFocus, PMS_INPUT_VIEW_UpdateWordwinFocus
 * address:  0x021B9A50
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from pms_input_view.c, unit_021BB224.c, unit_021BB240.c, unit_021BB250.c, unit_021BB260.c, unit_021BB270.c, pmsiv_category.c, unit_021BBE80.c, pmsiv_menu.c, pmsiv_wordwin.c, pms_select_graphic.c, ov110_func_021C1848.c by tools/splitfile.py.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_020307B0 0x020307B0 arm
 *   gPmsInputViewHeapSite 0x021C3C20 data a4
 *   gClActorInitParam 0x020A1448 data a4
 *   gPmsInputVramBanks 0x021C3714 data a4
 *   PMS_INPUT_GetUiInputModePtr 0x021BF6D4 thumb ov110
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   GXx_SetMasterBrightness_ 0x0207D534 arm
 *   PMS_INPUT_GetTasks 0x021BF7D0 thumb ov110
 *   func_02030DA8 0x02030DA8 arm
 *   func_020490F4 0x020490F4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_02030EAC 0x02030EAC arm
 *   PMSIV_MENU_Delete 0x021BCA30 thumb ov110
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   CLACT_DrawSystem 0x0204A600 arm
 *   PMSIV_MENU_Update 0x021BCA84 thumb ov110
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   BG_SYS_Update 0x020419E4 arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   gPmsInputViewTaskTable 0x021C3B94 data a4
 *   TCBL_GetTaskUserData 0x02030EE8 arm
 *   BG_SYS_ClearGraphicsMemory 0x0204335C arm
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   PMSIV_EDIT_Create 0x021BBC5C thumb ov110
 *   PMSIV_EDIT_Setup 0x021BBD60 thumb ov110
 *   PMSIV_CATEGORY_Create 0x021BB290 thumb ov110
 *   PMSIV_CATEGORY_Setup 0x021BB328 thumb ov110
 *   PMSIV_WORDWIN_Create 0x021BF844 thumb ov110
 *   PMSIV_WORDWIN_Setup 0x021BF8F4 thumb ov110
 *   func_020498F4 0x020498F4 arm
 *   func_02049658 0x02049658 arm
 *   func_02040588 0x02040588 arm
 *   ARC_UTIL_UploadPaletteFromHandle 0x02049BDC arm
 *   func_02061CA4 0x02061CA4 arm
 *   BG_SYS_FillTileMap 0x020413B0 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   PMS_INPUT_HasInitialSentence 0x021BF7C4 thumb ov110
 *   PMS_INPUT_GetInputMode 0x021BF6D8 thumb ov110
 *   PMSIV_MENU_Create 0x021BC990 thumb ov110
 *   PMSIV_MENU_ShowEditEntries 0x021BCB50 thumb ov110
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   GX_DispOn 0x0207D46C arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   PMSIV_EDIT_Delete 0x021BBCF0 thumb ov110
 *   PMSIV_CATEGORY_Delete 0x021BB2CC thumb ov110
 *   PMSIV_WORDWIN_Delete 0x021BF8BC thumb ov110
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   gPmsInputDispConfig 0x021C3604 data a4
 *   gPmsInputBgTemplate0 0x021C3694 data a4
 *   gPmsInputBgTemplate1 0x021C36B4 data a4
 *   gPmsInputBgTemplate2 0x021C3674 data a4
 *   gPmsInputBgTemplate3 0x021C3614 data a4
 *   gPmsInputBgTemplate4 0x021C36F4 data a4
 *   gPmsInputBgTemplate5 0x021C36D4 data a4
 *   gPmsInputBgTemplate6 0x021C3654 data a4
 *   gPmsInputBgTemplate7 0x021C3634 data a4
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_ClearSlot 0x020414EC arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   PRINTSYS_QUE_CreateEx 0x0201C450 thumb
 *   PMSIV_EDIT_Redraw 0x021BC23C thumb ov110
 *   PMS_INPUT_GetWordSlot 0x021BF714 thumb ov110
 *   PMSIV_EDIT_PlaceCursorAtSlot 0x021BC72C thumb ov110
 *   PMSIV_MENU_UpdateItemHighlight 0x021BCCA8 thumb ov110
 *   PMSIV_MENU_UpdateEntryPalette 0x021BCD44 thumb ov110
 *   PMSIV_EDIT_SetCursorsVisible 0x021BC704 thumb ov110
 *   PMSIV_EDIT_NoopA 0x021BC724 thumb ov110
 *   PMS_INPUT_GetCancelSelected 0x021BF71C thumb ov110
 *   PMSIV_MENU_SetActiveEntry 0x021BCF7C thumb ov110
 *   PMSIV_EDIT_NoopB 0x021BC728 thumb ov110
 *   PMS_INPUT_ResetSearch 0x021BF7E0 thumb ov110
 *   PMSIV_MENU_ShowWordEntries 0x021BCC58 thumb ov110
 *   PMSIV_EDIT_ReleaseCursor 0x021BC6EC thumb ov110
 *   PMSIV_CATEGORY_StartFadeIn 0x021BB76C thumb ov110
 *   PMSIV_EDIT_StartPanelScroll 0x021BBEF4 thumb ov110
 *   PMS_INPUT_GetBrowseMode 0x021BF6DC thumb ov110
 *   PMSIV_CATEGORY_DrawTitle 0x021BB958 thumb ov110
 *   PMSIV_CATEGORY_IsFadeInDone 0x021BB784 thumb ov110
 *   PMSIV_EDIT_StepPanelScroll 0x021BBF54 thumb ov110
 *   PMS_INPUT_GetCursorPos 0x021BF724 thumb ov110
 *   PMSIV_CATEGORY_MoveCursor 0x021BB6A0 thumb ov110
 *   PMSIV_CATEGORY_SetCursorVisible 0x021BB658 thumb ov110
 *   PMSIV_CATEGORY_RefreshScreens 0x021BB8D8 thumb ov110
 *   PMSIV_CATEGORY_ApplyBgOffset 0x021BB8B8 thumb ov110
 *   PMSIV_CATEGORY_IsReady 0x021BB954 thumb ov110
 *   PMSIV_MENU_StartPress 0x021BCEE4 thumb ov110
 *   PMSIV_CATEGORY_ShowWordList 0x021BB9C0 thumb ov110
 *   PMSIV_CATEGORY_IsListReady 0x021BBB0C thumb ov110
 *   PMSIV_MENU_IsPressDone 0x021BCF38 thumb ov110
 *   PMSIV_MENU_FinishPress 0x021BCF70 thumb ov110
 *   PMSIV_MENU_PressBackButton 0x021BD000 thumb ov110
 *   PMSIV_MENU_IsBackButtonDone 0x021BD028 thumb ov110
 *   PMSIV_CATEGORY_StartClose 0x021BB7A0 thumb ov110
 *   PMSIV_CATEGORY_StepClose 0x021BB7B8 thumb ov110
 *   PMSIV_EDIT_PressCursor 0x021BC6F8 thumb ov110
 *   PMSIV_CATEGORY_IsSelectAnimDone 0x021BBC10 thumb ov110
 *   PMSIV_CATEGORY_StartBlendOut 0x021BB838 thumb ov110
 *   PMSIV_CATEGORY_IsBlendOutDone 0x021BB854 thumb ov110
 *   PMSIV_MENU_ShowOnlyBackButton 0x021BCC88 thumb ov110
 *   PMSIV_WORDWIN_DrawList 0x021BF9F0 thumb ov110
 *   PMSIV_WORDWIN_StartOpen 0x021BFAA0 thumb ov110
 *   PMSIV_WORDWIN_IsOpen 0x021BFB58 thumb ov110
 *   PMS_INPUT_GetCursorCell 0x021BF784 thumb ov110
 *   PMSIV_WORDWIN_SetCursorCell 0x021BFC64 thumb ov110
 *   PMS_INPUT_GetTopRow 0x021BF7AC thumb ov110
 *   PMS_INPUT_GetMaxTopRow 0x021BF7B8 thumb ov110
 *   PMSIV_WORDWIN_SetThumbRow 0x021BFDB0 thumb ov110
 *   PMSIV_WORDWIN_SetVisible 0x021BFC20 thumb ov110
 *   PMS_INPUT_GetInitialCount 0x021BF7FC thumb ov110
 *   PMSIV_WORDWIN_StartClose 0x021BFB7C thumb ov110
 *   PMSIV_WORDWIN_FinishClose 0x021BFBA0 thumb ov110
 *   PMSIV_CATEGORY_StartBlendIn 0x021BB870 thumb ov110
 *   PMSIV_CATEGORY_IsBlendInDone 0x021BB8AC thumb ov110
 *   PMSIV_WORDWIN_IsPickAnimDone 0x021C00FC thumb ov110
 *   PMSIV_CATEGORY_ResetBgScroll 0x021BB804 thumb ov110
 *   PMSIV_CATEGORY_StartFadeOut 0x021BB814 thumb ov110
 *   PMSIV_CATEGORY_IsFadeOutDone 0x021BB82C thumb ov110
 *   PMS_INPUT_GetScrollDelta 0x021BF7A0 thumb ov110
 *   PMSIV_WORDWIN_Scroll 0x021BFCA4 thumb ov110
 *   PMSIV_WORDWIN_UpdateScroll 0x021BFD60 thumb ov110
 *   PMSIV_MENU_SetDecideEntry 0x021BCFBC thumb ov110
 *   PMSIV_MENU_UpdateEntryPalettes 0x021BCD80 thumb ov110
 *   PMSIV_WORDWIN_DrawListFrom 0x021BFA40 thumb ov110
 *   PMS_INPUT_GetSavedCursorPos 0x021BF72C thumb ov110
 *   PMSIV_CATEGORY_StartSelectAnim 0x021BBB84 thumb ov110
 *   PMSIV_WORDWIN_StartPickAnim 0x021C00AC thumb ov110
 *   PMSIV_EDIT_GetSlotCount  0x021BC6DC  thumb  ov110
 *   PMSIV_EDIT_GetSlotWordId  0x021BC6E0  thumb  ov110
 *   PMSIV_EDIT_GetSlotRect  0x021BC320  thumb  ov110
 *   PMSIV_MENU_IsEntryFinished 0x021BCFF0 thumb ov110
 *   PMSIV_MENU_SelectItem 0x021BCF18 thumb ov110
 *   OS_DisableInterrupts 0x02087988 arm
 *   OS_RestoreInterrupts 0x0208799C arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_SetActorAutoAnimSpeed 0x0204B954 arm
 *   PMSIV_WORDWIN_GetThumb 0x021BFD94 thumb ov110
 *   PMSIV_WORDWIN_SetThumbY  0x021BFE24  thumb  ov110
 *   PMSIV_WORDWIN_GetThumbRow  0x021BFE60  thumb  ov110
 *   ARC_UTIL_UploadBgPaletteAddFromHandleExt 0x020499D4 arm
 *   gPmsInputHelpMessageIds 0x021C3744 data ov110 a4
 *   func_02045B38 0x02045B38 arm
 *   func_02045EC0 0x02045EC0 arm
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   GF_FONT_Delete  0x0201D83C  thumb  arm9
 *   WIPE_SYS_Start  0x0202208C  thumb  arm9
 *   WIPE_SYS_EndCheck  0x020221A4  thumb  arm9
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb  arm9
 *   PRINTSYS_QUE_Clear  0x0201C6EC  thumb  arm9
 *   PMS_INPUT_VIEW_GetFont 0x021BAC44 thumb ov110
 *   PMS_INPUT_VIEW_GetUiRes 0x021BAC64 thumb ov110
 *   PMS_INPUT_VIEW_CreateActor 0x021BAC78 thumb ov110
 *   PMS_INPUT_VIEW_GetMenu 0x021BAC3C thumb ov110
 *   PMS_INPUT_VIEW_GetPrintQue 0x021BAC4C thumb ov110
 *   func_020056A0 0x020056A0 thumb
 *   PMS_INPUT_VIEW_GetCursorRes 0x021BAC50 thumb ov110
 *   PMS_INPUT_VIEW_AddVBlankTask 0x021B9BA4 thumb ov110
 *   PMS_INPUT_VIEW_GetClactUnit 0x021BAC40 thumb ov110
 *   PMS_INPUT_VIEW_StartTask 0x021B9BEC thumb ov110
 *   PMS_INPUT_VIEW_IsIdle 0x021B9C74 thumb ov110
 *   PMS_INPUT_VIEW_GetEditValue 0x021BABE8 thumb ov110
 *   PMS_INPUT_VIEW_Create 0x021B9A50 thumb ov110
 *   PMS_INPUT_VIEW_Delete 0x021B9B20 thumb ov110
 *   PMS_INPUT_VIEW_UpdateEditFocus 0x021BAE24 thumb ov110
 *   PMS_INPUT_VIEW_UpdateCategoryFocus 0x021BAE94 thumb ov110
 *   PMS_INPUT_VIEW_UpdateWordwinFocus 0x021BAED0 thumb ov110
 *   PMS_INPUT_VIEW_SetEditText 0x021BAC00 thumb ov110
 *   PMS_INPUT_VIEW_SetMenuItemMode 0x021BAC30 thumb ov110
 *   PMS_INPUT_VIEW_IsTaskNotRunning 0x021B9C90 thumb ov110
 *   PMS_INPUT_VIEW_CompareWordwinPosition 0x021BACDC thumb ov110
 *   PMS_INPUT_VIEW_SetWordwinScrollOffset 0x021BAD14 thumb ov110
 *   PMS_INPUT_VIEW_GetWordwinItem 0x021BAD20 thumb ov110
 *   PMS_INPUT_VIEW_GetEditEntry 0x021BABF4 thumb ov110
 *   PMS_INPUT_VIEW_GetMenuResult 0x021BAC0C thumb ov110
 *   PMS_INPUT_VIEW_LoadBgPalette 0x021BAD2C thumb ov110
 */

#include "pms_input_view_shared_types.h"

#define REG_DISPCNT_MAIN (*(volatile u32 *)0x04000000)
#define REG_DISPCNT_SUB (*(volatile u32 *)0x04001000)
#define REG_BLDCNT_MAIN (*(volatile u16 *)0x04000050)
#define REG_BLDCNT_SUB (*(volatile u16 *)0x04001050)
#define REG_MASTER_BRIGHT_MAIN ((volatile u16 *)0x0400006C)
#define REG_MASTER_BRIGHT_SUB ((volatile u16 *)0x0400106C)
#define REG_POWCNT1 (*(volatile u16 *)0x04000304)

#define PMS_INPUT_VIEW_HEAP_ID 42
#define PMS_INPUT_VIEW_TASK_COUNT 35

struct TcbTask;
struct ClactActor;
struct MsgData;
struct Strbuf;
struct Bmp;

typedef void (*ViewTaskFunc)(void *tcb, struct PmsInputViewTask *task);

typedef struct { ViewTaskFunc entries[PMS_INPUT_VIEW_TASK_COUNT]; } ViewTaskTable;

typedef enum { GX_DISP_SELECT_SUB_MAIN=0, GX_DISP_SELECT_MAIN_SUB=1 } GXDispSelect;

struct ScreenPos { short x, y; };

typedef struct { u32 values[6]; } HelpMessageTable;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern u32 *PMS_INPUT_GetUiInputModePtr(struct PmsInput *input);
extern void CLACT_InitSystem(const void *initParam, const void *vramBanks, u32 heapId);
extern struct ClactUnit *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void BG_SYS_Create(u16 heapId);
extern void BMP_WIN_Init(u16 heapId);
extern void GXx_SetMasterBrightness_(volatile u16 *reg, int brightness);
extern u32 PMS_INPUT_GetTasks(struct PmsInput *input);
extern void *func_02030DA8(u32 tcbList, ViewTaskFunc func, void *work, int priority);
extern void *func_020490F4(u32 id, u32 heapId);
extern void ARC_TOOL_DeleteHandle(void *handle);
extern void func_02030EAC(void *tcb);
extern void PMSIV_MENU_Delete(struct PmsivMenu *menu);
extern unsigned int CLACT_DeleteUnit(struct ClactUnit *unit);
extern void CLACT_ReleasePalette(unsigned int);
extern void CLACT_ReleaseCharacter(unsigned int);
extern void CLACT_ReleaseCellAnim(unsigned int);
extern void CLACT_ExitSystem(void);
extern void BMP_WIN_Exit(void);
extern void BG_SYS_Delete(void);
extern void *func_020056A0(void (*fn)(void *, void *), void *work, int priority);
extern void CLACT_DrawSystem(void);
extern void PMSIV_MENU_Update(struct PmsivMenu *menu);
extern unsigned int PRINTSYS_QUE_Main(struct PrintQue *queue);
extern void BG_SYS_Update(void);
extern void CLACT_VBlankSystem(void);
extern struct PmsInputViewTask *TCBL_GetTaskUserData(void *tcb);
extern void BG_SYS_ClearGraphicsMemory(unsigned);
extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
extern struct PmsivEdit *PMSIV_EDIT_Create(struct PmsInputView *view, struct PmsInput *input, struct PmsInputData *wordData);
extern void PMSIV_EDIT_Setup(struct PmsivEdit *edit, void *arcHandle);
extern struct PmsivCategory *PMSIV_CATEGORY_Create(struct PmsInputView *view, struct PmsInput *input, struct PmsInputData *wordData);
extern void PMSIV_CATEGORY_Setup(struct PmsivCategory *category, void *arcHandle);
extern struct PmsivWordwin *PMSIV_WORDWIN_Create(struct PmsInputView *view, struct PmsInput *input, struct PmsInputData *wordData);
extern void PMSIV_WORDWIN_Setup(struct PmsivWordwin *wordwin);
extern void func_020498F4(void *handle, u32 fileId, u32 bgId, u32 offset, u32 size, u32 flags, u16 heapId);
extern u32 func_02049658(void *handle, u32 fileId, u32 bgId, u32 offset, u32 size, u32 flags, u16 heapId);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void ARC_UTIL_UploadPaletteFromHandle(void *handle, u32 fileId, u32 paletteType, u32 offset, u32 size, u32 flags, u16 heapId);
extern int func_02061CA4(u32 target, u32 offset, const void *data, int size);
extern void BG_SYS_FillTileMap(u8 bgId, u8 x, u8 y, u8 width, u8 height, u8 paletteBank);
extern struct BmpWin *BMP_WIN_Create(u32, u32, u32, u32, u8, u8, u8);
extern struct Bmp *BMP_WIN_GetBmp(struct BmpWin *win);
extern void BMP_Clear(struct Bmp *bmp, u8 value);
extern u32 PMS_INPUT_HasInitialSentence(struct PmsInput *input);
extern u32 PMS_INPUT_GetInputMode(struct PmsInput *input);
extern struct PmsivMenu *PMSIV_MENU_Create(struct PmsInputView *view, struct PmsInput *input, struct PmsInputData *wordData);
extern void PMSIV_MENU_ShowEditEntries(struct PmsivMenu *menu);
extern void BG_SYS_SetMainPlaneVisible(u32,u32);
extern void BG_SYS_SetSubPlaneVisible(u32,u32);
extern void GX_DispOn(void);
extern signed int CLACT_RegisterPalette(void *handle, unsigned int fileId, unsigned int screen, unsigned int offset, u16 heapId);
extern int CLACT_RegisterCharacter(void *handle, u32 fileId, u32 compressed, u32 screen, u16 heapId);
extern int CLACT_RegisterCellAnim(void *handle, u32 cellFileId, u32 animFileId, u32 heapId);
extern void WIPE_SYS_Start(void *,u32,u32,u32,u32,u32,u32);
extern u32 WIPE_SYS_EndCheck(void);
extern u32 BMP_WIN_Delete(struct BmpWin *win);
extern void PMSIV_EDIT_Delete(struct PmsivEdit *edit);
extern void PMSIV_CATEGORY_Delete(struct PmsivCategory *category);
extern void PMSIV_WORDWIN_Delete(struct PmsivWordwin *wordwin);
extern u32 GF_FONT_Delete(struct GfFont *font);
extern void PRINTSYS_QUE_Clear(struct PrintQue *queue);
extern void PRINTSYS_QUE_Delete(struct PrintQue *queue);
extern void BG_SYS_FreeLayerBuf(u32 i);
extern void BG_SYS_SetVramBanks(const void *vramBanks);
extern void BG_SYS_SetGraphicsMode(const void *dispConfig);
extern void BG_SYS_InitBgLayer(u32 bgId, const void *bgTemplate, u32 type);
extern void BG_SYS_ClearSlot(u32 i);
extern struct GfFont *GF_FONT_Create(int, int, int, int, u32 heapId);
extern struct PrintQue *PRINTSYS_QUE_CreateEx(u16, u32);
extern void PMSIV_EDIT_Redraw(struct PmsivEdit *edit);
extern u16 PMS_INPUT_GetWordSlot(struct PmsInput *input);
extern void PMSIV_EDIT_PlaceCursorAtSlot(struct PmsivEdit *edit, int i);
extern void PMSIV_MENU_UpdateItemHighlight(struct PmsivMenu *menu);
extern void PMSIV_MENU_UpdateEntryPalette(struct PmsivMenu *menu);
extern void PMSIV_EDIT_SetCursorsVisible(struct PmsivEdit *edit, u32 flag);
extern void PMSIV_EDIT_NoopA(struct PmsivEdit *edit);
extern u16 PMS_INPUT_GetCancelSelected(struct PmsInput *input);
extern void PMSIV_MENU_SetActiveEntry(struct PmsivMenu *menu, int n, int v);
extern void PMSIV_EDIT_NoopB(struct PmsivEdit *edit);
extern void PMS_INPUT_ResetSearch(struct PmsInput *input);
extern void PMSIV_MENU_ShowWordEntries(struct PmsivMenu *menu);
extern void PMSIV_EDIT_ReleaseCursor(struct PmsivEdit *edit);
extern void PMSIV_CATEGORY_StartFadeIn(struct PmsivCategory *category);
extern void PMSIV_EDIT_StartPanelScroll(struct PmsivEdit *edit, u8 value);
extern u8 PMS_INPUT_GetBrowseMode(struct PmsInput *input);
extern void PMSIV_CATEGORY_DrawTitle(struct PmsivCategory *category);
extern int PMSIV_CATEGORY_IsFadeInDone(struct PmsivCategory *category);
extern int PMSIV_EDIT_StepPanelScroll(struct PmsivEdit *edit);
extern u16 PMS_INPUT_GetCursorPos(struct PmsInput *input);
extern void PMSIV_CATEGORY_MoveCursor(struct PmsivCategory *category, unsigned int n);
extern void PMSIV_CATEGORY_SetCursorVisible(struct PmsivCategory *category, int n);
extern void PMSIV_CATEGORY_RefreshScreens(struct PmsivCategory *category);
extern void PMSIV_CATEGORY_ApplyBgOffset(struct PmsivCategory *category);
extern int PMSIV_CATEGORY_IsReady(struct PmsivCategory *category);
extern void PMSIV_MENU_StartPress(struct PmsivMenu *menu, u32 mode);
extern void PMSIV_CATEGORY_ShowWordList(struct PmsivCategory *category, int n);
extern int PMSIV_CATEGORY_IsListReady(struct PmsivCategory *category, int n);
extern int PMSIV_MENU_IsPressDone(struct PmsivMenu *menu, u32 mode);
extern void PMSIV_MENU_FinishPress(struct PmsivMenu *menu, int n);
extern int PMSIV_MENU_PressBackButton(struct PmsivMenu *menu);
extern int PMSIV_MENU_IsBackButtonDone(struct PmsivMenu *menu);
extern void PMSIV_CATEGORY_StartClose(struct PmsivCategory *category);
extern int PMSIV_CATEGORY_StepClose(struct PmsivCategory *category);
extern void PMSIV_EDIT_PressCursor(struct PmsivEdit *edit);
extern int PMSIV_CATEGORY_IsSelectAnimDone(struct PmsivCategory *category);
extern void PMSIV_CATEGORY_StartBlendOut(struct PmsivCategory *category);
extern int PMSIV_CATEGORY_IsBlendOutDone(struct PmsivCategory *category);
extern void PMSIV_MENU_ShowOnlyBackButton(struct PmsivMenu *menu);
extern void PMSIV_WORDWIN_DrawList(struct PmsivWordwin *wordwin);
extern void PMSIV_WORDWIN_StartOpen(struct PmsivWordwin *wordwin);
extern int PMSIV_WORDWIN_IsOpen(struct PmsivWordwin *wordwin);
extern unsigned PMS_INPUT_GetCursorCell(struct PmsInput *input);
extern void PMSIV_WORDWIN_SetCursorCell(struct PmsivWordwin *wordwin, unsigned n);
extern unsigned PMS_INPUT_GetTopRow(struct PmsInput *input);
extern unsigned PMS_INPUT_GetMaxTopRow(struct PmsInput *input);
extern void PMSIV_WORDWIN_SetThumbRow(struct PmsivWordwin *wordwin, unsigned scrollPos, unsigned cursorPos);
extern void PMSIV_WORDWIN_SetVisible(struct PmsivWordwin *wordwin, unsigned n);
extern u8 PMS_INPUT_GetInitialCount(struct PmsInput *input);
extern void PMSIV_WORDWIN_StartClose(struct PmsivWordwin *wordwin);
extern int PMSIV_WORDWIN_FinishClose(struct PmsivWordwin *wordwin);
extern void PMSIV_CATEGORY_StartBlendIn(struct PmsivCategory *category);
extern int PMSIV_CATEGORY_IsBlendInDone(struct PmsivCategory *category);
extern int PMSIV_WORDWIN_IsPickAnimDone(struct PmsivWordwin *wordwin);
extern void PMSIV_CATEGORY_ResetBgScroll(struct PmsivCategory *category);
extern void PMSIV_CATEGORY_StartFadeOut(struct PmsivCategory *category);
extern int PMSIV_CATEGORY_IsFadeOutDone(struct PmsivCategory *category);
extern int PMS_INPUT_GetScrollDelta(struct PmsInput *input);
extern void PMSIV_WORDWIN_Scroll(struct PmsivWordwin *wordwin, int n);
extern int PMSIV_WORDWIN_UpdateScroll(struct PmsivWordwin *wordwin);
extern void PMSIV_MENU_SetDecideEntry(struct PmsivMenu *menu, u32 index, int value);
extern void PMSIV_MENU_UpdateEntryPalettes(struct PmsivMenu *menu);
extern void PMSIV_WORDWIN_DrawListFrom(struct PmsivWordwin *wordwin, unsigned n);
extern u16 PMS_INPUT_GetSavedCursorPos(struct PmsInput *input);
extern void PMSIV_CATEGORY_StartSelectAnim(struct PmsivCategory *category, unsigned n);
extern void PMSIV_WORDWIN_StartPickAnim(struct PmsivWordwin *wordwin, unsigned n);
extern unsigned int PMSIV_EDIT_GetSlotCount(struct PmsivEdit *edit);
extern u16 PMSIV_EDIT_GetSlotWordId(struct PmsivEdit *edit, int i);
extern void PMSIV_EDIT_GetSlotRect(struct PmsivEdit *edit, const void *src, int n);
extern u32 PMSIV_MENU_IsEntryFinished(struct PmsivMenu *menu, u32 index);
extern void PMSIV_MENU_SelectItem(struct PmsivMenu *menu, int mode);
extern int OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(int state);
extern struct ClactActor *CLACT_CreateActor(void *unit, unsigned int, unsigned int, unsigned int, const void *setup, u16, u16);
extern void CLACT_SetActorAutoAnim(struct ClactActor *, u32);
extern void CLACT_SetActorAutoAnimSpeed(struct ClactActor *actor, u32 v);
extern u32 PMSIV_WORDWIN_GetThumb(struct PmsivWordwin *wordwin, struct ScreenPos *out);
extern void PMSIV_WORDWIN_SetThumbY(struct PmsivWordwin *wordwin, int y);
extern unsigned PMSIV_WORDWIN_GetThumbRow(struct PmsivWordwin *wordwin, unsigned n);
extern u32 ARC_UTIL_UploadBgPaletteAddFromHandleExt(void *handle, u32 fileId, u32 bgType, u32 flags, u32 offset, u32 size, u32 shift, u16 heapId);
extern struct MsgData *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgData *msgData, u32 index);
extern void PRINTSYS_PrintQueColor(struct PrintQue *queue, struct Bmp *bmp, u32 x, u32 y, void *str, struct GfFont *font, u16 color);
extern void STRBUF_Delete(void *str);
extern u32 MSGDATA_Delete(struct MsgData *msgData);
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintQue *queue, struct Bmp *bmp);
extern void BMP_WIN_TransferChars(struct BmpWin *win);
extern void BMP_WIN_MakeScreen(struct BmpWin *win);
extern u8 BMP_WIN_GetBgLayer(struct BmpWin *win);
extern void func_02041B6C(unsigned);

extern const char gPmsInputViewHeapSite[];
extern const u8 gClActorInitParam[];
extern const u8 gPmsInputVramBanks[];
extern const ViewTaskTable gPmsInputViewTaskTable;
extern u8 gPmsInputDispConfig[];
extern const u8 gPmsInputBgTemplate0[],gPmsInputBgTemplate1[],gPmsInputBgTemplate2[],gPmsInputBgTemplate3[];
extern const u8 gPmsInputBgTemplate4[],gPmsInputBgTemplate5[],gPmsInputBgTemplate6[],gPmsInputBgTemplate7[];
extern const HelpMessageTable gPmsInputHelpMessageIds;

void *PMS_INPUT_VIEW_Create(struct PmsInput *input, struct PmsInputData *wordData);
void PMS_INPUT_VIEW_Delete(struct PmsInputView *view);
void *PMS_INPUT_VIEW_AddVBlankTask(void (*fn)(void *, void *), void *work, int priority);
void PMS_INPUT_VIEW_MainTask(void *tcb, void *work);
void PMS_INPUT_VIEW_VBlankTask(void *tcb, void *work);
void PMS_INPUT_VIEW_StartTask(struct PmsInputView *view, int id);
int PMS_INPUT_VIEW_IsIdle(struct PmsInputView *view);
int PMS_INPUT_VIEW_IsTaskNotRunning(struct PmsInputView *view, int id);
void PMS_INPUT_VIEW_EndTask(struct PmsInputViewTask *task);
void PMS_INPUT_VIEW_RegisterSpriteResources(struct PmsInputViewTask *task, void *archive);
void PMS_INPUT_VIEW_InitDisplay(struct PmsInputViewTask *task);
void PMS_INPUT_VIEW_LoadBgPalette(struct PmsInputView *view, int variant);
void PMS_INPUT_VIEW_PrintHelpMessage(struct PmsInputViewTask *task, int index);
void PMS_INPUT_VIEW_FlushHelpText(struct PmsInputView *view);
void PMS_INPUT_VIEW_UpdateEditFocus(struct PmsInputView *view, struct PmsInput *input, struct PmsInputData *wordData);
void PMS_INPUT_VIEW_UpdateCategoryFocus(struct PmsInputView *view, struct PmsInput *input, struct PmsInputData *wordData);
void PMS_INPUT_VIEW_UpdateWordwinFocus(struct PmsInputView *view, struct PmsInput *input, struct PmsInputData *wordData);

void *PMS_INPUT_VIEW_Create(struct PmsInput *input, struct PmsInputData *wordData) {
    struct PmsInputView *view;
    int i;
    view=func_02030734(PMS_INPUT_VIEW_HEAP_ID,sizeof(struct PmsInputView),0,gPmsInputViewHeapSite,0xdf);
    if(view!=0) {
        view->menu=0;
        view->printQue=0;
        view->input=input;
        view->wordData=wordData;
        view->uiInputMode=PMS_INPUT_GetUiInputModePtr(input);
        CLACT_InitSystem(gClActorInitParam,gPmsInputVramBanks,PMS_INPUT_VIEW_HEAP_ID);
        view->clactUnit=CLACT_CreateUnit(128,0,PMS_INPUT_VIEW_HEAP_ID);
        BG_SYS_Create(PMS_INPUT_VIEW_HEAP_ID);
        BMP_WIN_Init(PMS_INPUT_VIEW_HEAP_ID);
        GXx_SetMasterBrightness_(REG_MASTER_BRIGHT_MAIN,-16);
        GXx_SetMasterBrightness_(REG_MASTER_BRIGHT_SUB,-16);
        view->mainTask=func_02030DA8(PMS_INPUT_GetTasks(input),(ViewTaskFunc)PMS_INPUT_VIEW_MainTask,view,2);
        view->vblankTask=PMS_INPUT_VIEW_AddVBlankTask(PMS_INPUT_VIEW_VBlankTask,view,1);
        for(i=0;i<PMS_INPUT_VIEW_TASK_SLOTS;++i) view->eventTasks[i]=0;
        view->helpTextPending=0;
        view->inWordPick=0;
        view->paletteChanged=0;
        view->paletteVariant=0;
        view->arcHandle=func_020490F4(43,PMS_INPUT_VIEW_HEAP_ID);
    }
    return view;
}

void PMS_INPUT_VIEW_Delete(struct PmsInputView *view) {
    int i, j;
    if (view) {
        ARC_TOOL_DeleteHandle(view->arcHandle);
        for (i=0; i<PMS_INPUT_VIEW_TASK_SLOTS; ++i) {
            void *r = view->eventTasks[i];
            if (r) func_02030EAC(r);
        }
        func_02030EAC(view->mainTask);
        func_02030EAC(view->vblankTask);
        PMSIV_MENU_Delete(view->menu);
        CLACT_DeleteUnit(view->clactUnit);
        for (j=0; j<PMS_INPUT_VIEW_SCREEN_COUNT; ++j) {
            CLACT_ReleasePalette(view->uiRes[j].palette);
            CLACT_ReleaseCharacter(view->uiRes[j].character);
            CLACT_ReleaseCellAnim(view->uiRes[j].cellAnim);
            CLACT_ReleasePalette(view->cursorRes[j].palette);
            CLACT_ReleaseCharacter(view->cursorRes[j].character);
            CLACT_ReleaseCellAnim(view->cursorRes[j].cellAnim);
        }
        CLACT_ExitSystem();
        BMP_WIN_Exit();
        BG_SYS_Delete();
        func_020307B0(view);
    }
}

void *PMS_INPUT_VIEW_AddVBlankTask(void (*fn)(void *, void *), void *work, int priority) { return func_020056A0(fn, work, priority); }

void PMS_INPUT_VIEW_MainTask(void *tcb, void *work) {
    struct PmsInputView *view = work;
    CLACT_DrawSystem();
    if(view->menu) PMSIV_MENU_Update(view->menu);
    if(view->printQue) {
        PRINTSYS_QUE_Main(view->printQue);
        PMS_INPUT_VIEW_FlushHelpText(view);
    }
}

void PMS_INPUT_VIEW_VBlankTask(void *tcb, void *work) {
    struct PmsInputView *view = work;
    if(view->paletteChanged) view->paletteChanged=0;
    BG_SYS_Update();
    CLACT_VBlankSystem();
}

void PMS_INPUT_VIEW_StartTask(struct PmsInputView *view, int id) {
    ViewTaskTable table;
    int i;
    struct PmsInputViewTask *task;
    table = gPmsInputViewTaskTable;
    if (id >= PMS_INPUT_VIEW_TASK_COUNT) return;
    task = func_02030734(PMS_INPUT_VIEW_HEAP_ID, sizeof(struct PmsInputViewTask), 0, gPmsInputViewHeapSite, 493);
    if (!task) return;
    task->state = 0;
    task->id = id;
    task->view = view;
    task->input = view->input;
    task->wordData = view->wordData;
    for (i=0; i<PMS_INPUT_VIEW_TASK_SLOTS; ++i) {
        if (!view->eventTasks[i]) {
            task->slot = i;
            view->eventTasks[i] = func_02030DA8(PMS_INPUT_GetTasks(view->input), table.entries[id], task, 1);
            return;
        }
    }
}

int PMS_INPUT_VIEW_IsIdle(struct PmsInputView *view) {
    int i;
    for(i=0;i<PMS_INPUT_VIEW_TASK_SLOTS;i++) if(view->eventTasks[i]) return 0;
    return 1;
}

int PMS_INPUT_VIEW_IsTaskNotRunning(struct PmsInputView *view, int id) {
    int i;
    int value;
    for(i=0;i<PMS_INPUT_VIEW_TASK_SLOTS;i++)
        if(view->eventTasks[i]) {
            value=TCBL_GetTaskUserData(view->eventTasks[i])->id;
            if(value==id) return 0;
        }
    return 1;
}

void PMS_INPUT_VIEW_EndTask(struct PmsInputViewTask *task)
{
    func_02030EAC(task->view->eventTasks[task->slot]);
    task->view->eventTasks[task->slot] = 0;
    func_020307B0(task);
}

void PMS_INPUT_VIEW_TaskInit(void *tcb, struct PmsInputViewTask *task) {
    void *h;
    REG_BLDCNT_MAIN=0;
    REG_BLDCNT_SUB=0;
    REG_DISPCNT_MAIN &= ~0xe000;
    REG_DISPCNT_SUB &= ~0xe000;
    BG_SYS_ClearGraphicsMemory(0);
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    REG_DISPCNT_MAIN &= ~0x1f00;
    REG_DISPCNT_SUB &= ~0x1f00;
    h=func_020490F4(43,42);
    PMS_INPUT_VIEW_InitDisplay(task);
    PMS_INPUT_VIEW_RegisterSpriteResources(task,h);
    task->view->edit=PMSIV_EDIT_Create(task->view,task->input,task->wordData);
    PMSIV_EDIT_Setup(task->view->edit,h);
    task->view->category=PMSIV_CATEGORY_Create(task->view,task->input,task->wordData);
    PMSIV_CATEGORY_Setup(task->view->category,h);
    task->view->wordwin=PMSIV_WORDWIN_Create(task->view,task->input,task->wordData);
    PMSIV_WORDWIN_Setup(task->view->wordwin);
    func_020498F4(h,30,5,0,0,0,42);
    func_02049658(h,18,5,0,0,0,42);
    func_020498F4(h,31,6,0,0,0,42);
    func_02049658(h,18,6,0,0,0,42);
    func_02040588(6,0);
    ARC_UTIL_UploadPaletteFromHandle(h,4,4,128,160,32,42);
    task->view->helpBgColor[0]=0x294b;
    func_02061CA4(31,188,&task->view->helpBgColor[0],2);
    task->view->helpBgColor[1]=0x5694;
    func_02061CA4(31,190,&task->view->helpBgColor[1],2);
    func_02049658(h,18,7,0,0,0,42);
    func_020498F4(h,24,7,0,0,0,42);
    BG_SYS_FillTileMap(7,0,0,32,32,5);
    task->view->helpWin=BMP_WIN_Create(7,3,5,26,7,5,1);
    BMP_Clear(BMP_WIN_GetBmp(task->view->helpWin),7);
    task->view->helpTextPending=0;
    if(PMS_INPUT_HasInitialSentence(task->input) || PMS_INPUT_GetInputMode(task->input)!=2) PMS_INPUT_VIEW_PrintHelpMessage(task,1);
    else PMS_INPUT_VIEW_PrintHelpMessage(task,0);
    PMS_INPUT_VIEW_LoadBgPalette(task->view,0);
    task->view->menu=PMSIV_MENU_Create(task->view,task->input,task->wordData);
    PMSIV_MENU_ShowEditEntries(task->view->menu);
    func_02040588(0,1);
    BG_SYS_SetMainPlaneVisible(16,1);
    BG_SYS_SetSubPlaneVisible(16,1);
    GX_DispOn();
    func_02049658(h,16,3,0,0,0,42);
    func_02049658(h,17,3,96,0,0,42);
    ARC_TOOL_DeleteHandle(h);
    PMS_INPUT_VIEW_EndTask(task);
}

void PMS_INPUT_VIEW_RegisterSpriteResources(struct PmsInputViewTask *task, void *archive) {
    struct PmsInputView *view = task->view;
    int i;
    for (i=0; i<PMS_INPUT_VIEW_SCREEN_COUNT; ++i) {
        view->uiRes[i].palette = CLACT_RegisterPalette(archive, 7, i, 0, 42);
        view->uiRes[i].character = CLACT_RegisterCharacter(archive, 19, 0, i, 42);
        view->uiRes[i].cellAnim = CLACT_RegisterCellAnim(archive, 36, 42, 42);
        view->cursorRes[i].palette = CLACT_RegisterPalette(archive, 1, i, 224, 42);
        view->cursorRes[i].character = CLACT_RegisterCharacter(archive, 46, 0, i, 42);
        view->cursorRes[i].cellAnim = CLACT_RegisterCellAnim(archive, 34, 40, 42);
    }
}

/*
 * volatile: 0x021BA058 reads hardware register 0x04000304 before updating it.
 */
void PMS_INPUT_VIEW_TaskExit(void *tcb, struct PmsInputViewTask *task) {
    struct PmsInputView *view = task->view;
    switch (task->state) {
    case 0:
        WIPE_SYS_Start(0,0,0,0,5,1,42);
        ++task->state;
        break;
    case 1:
        if (WIPE_SYS_EndCheck()) {
            BMP_WIN_Delete(task->view->helpWin);
            PMSIV_EDIT_Delete(task->view->edit);
            PMSIV_CATEGORY_Delete(task->view->category);
            PMSIV_WORDWIN_Delete(task->view->wordwin);
            GF_FONT_Delete(view->font);
            PRINTSYS_QUE_Clear(view->printQue);
            PRINTSYS_QUE_Delete(view->printQue);
            view->printQue = 0;
            BG_SYS_FreeLayerBuf(0);
            BG_SYS_FreeLayerBuf(1);
            BG_SYS_FreeLayerBuf(2);
            BG_SYS_FreeLayerBuf(3);
            BG_SYS_FreeLayerBuf(4);
            BG_SYS_FreeLayerBuf(5);
            BG_SYS_FreeLayerBuf(6);
            REG_POWCNT1 |= 0x8000;
            PMS_INPUT_VIEW_EndTask(task);
        }
        break;
    }
}

static inline void GX_SetDispSelect(GXDispSelect sel) {
    REG_POWCNT1=(u16)((REG_POWCNT1 & ~0x8000) | (sel<<15));
}

/*
 * lever: GX_SetDispSelect's enum inline keeps the 0xFFFF7FFF pool mask;
 *   a direct halfword &= expression emits 0x00007FFF (two bytes differ).
 * abi: original A0E0..A0EC truncates i separately before both calls;
 *   narrow first extern parameters retain those explicit u8 argument values.
 * volatile: hardware halfword at 04000304 is read/modified at A078..A07E.
 */
void PMS_INPUT_VIEW_InitDisplay(struct PmsInputViewTask *task) {
    struct PmsInputView *view=task->view;
    int i;
    GX_SetDispSelect(GX_DISP_SELECT_SUB_MAIN);
    BG_SYS_SetVramBanks(gPmsInputVramBanks);
    BG_SYS_SetGraphicsMode(gPmsInputDispConfig);
    BG_SYS_InitBgLayer(0,gPmsInputBgTemplate0,0);
    BG_SYS_InitBgLayer(1,gPmsInputBgTemplate1,0);
    BG_SYS_InitBgLayer(2,gPmsInputBgTemplate2,0);
    BG_SYS_InitBgLayer(3,gPmsInputBgTemplate3,0);
    BG_SYS_InitBgLayer(4,gPmsInputBgTemplate4,0);
    BG_SYS_InitBgLayer(5,gPmsInputBgTemplate5,0);
    BG_SYS_InitBgLayer(6,gPmsInputBgTemplate6,0);
    BG_SYS_InitBgLayer(7,gPmsInputBgTemplate7,0);
    for(i=0;i<=7;++i) {
        BG_SYS_ClearSlot((u8)i);
        func_02040588((u8)i,1);
    }
    view->font=GF_FONT_Create(23,0,0,0,42);
    view->printQue=PRINTSYS_QUE_CreateEx(0x500,42);
}

void PMS_INPUT_VIEW_TaskFadeIn(void *tcb, struct PmsInputViewTask *task) {
    switch (task->state) {
    case 0:
        WIPE_SYS_Start(0, 1, 1, 0, 5, 1, 42);
        ++task->state;
        break;
    case 1:
        if (WIPE_SYS_EndCheck()) ++task->state;
        break;
    default:
        PMS_INPUT_VIEW_EndTask(task);
        break;
    }
}

void PMS_INPUT_VIEW_TaskActivateEdit(void *tcb, struct PmsInputViewTask *task)
{
    struct PmsInputView *view;
    view = task->view;
    view->inWordPick = 0;
    PMSIV_EDIT_Redraw(view->edit);
    PMSIV_EDIT_PlaceCursorAtSlot(view->edit, PMS_INPUT_GetWordSlot(task->input));
    PMSIV_MENU_UpdateItemHighlight(view->menu);
    PMSIV_MENU_UpdateEntryPalette(view->menu);
    PMS_INPUT_VIEW_EndTask(task);
}

void PMS_INPUT_VIEW_TaskUpdateEditFocus(void *tcb, struct PmsInputViewTask *task)
{
    PMS_INPUT_VIEW_UpdateEditFocus(task->view, task->input, task->wordData);
    PMS_INPUT_VIEW_EndTask(task);
}

/*
 * extent: trailing two-byte zero alignment padding.
 */
void PMS_INPUT_VIEW_TaskUpdateCategoryFocus(void *tcb, struct PmsInputViewTask *task)
{
    PMS_INPUT_VIEW_UpdateCategoryFocus(task->view, task->input, task->wordData);
    PMS_INPUT_VIEW_EndTask(task);
}

void PMS_INPUT_VIEW_TaskUpdateWordwinFocus(void *tcb, struct PmsInputViewTask *task)
{
    PMS_INPUT_VIEW_UpdateWordwinFocus(task->view, task->input, task->wordData);
    PMS_INPUT_VIEW_EndTask(task);
}

void PMS_INPUT_VIEW_TaskPickMenuItemDecided(void *tcb, struct PmsInputViewTask *task)
{
    struct PmsInputView *view;
    view = task->view;
    view->inWordPick = 1;
    PMSIV_EDIT_SetCursorsVisible(view->edit, 0);
    PMSIV_EDIT_NoopA(view->edit);
    PMSIV_MENU_SetActiveEntry(view->menu, (u8)PMS_INPUT_GetCancelSelected(view->input), 1);
    PMS_INPUT_VIEW_EndTask(task);
}

void PMS_INPUT_VIEW_TaskPickMenuItem(void *tcb, struct PmsInputViewTask *task)
{
    struct PmsInputView *view;
    view = task->view;
    view->inWordPick = 1;
    PMSIV_EDIT_SetCursorsVisible(view->edit, 0);
    PMSIV_EDIT_NoopA(view->edit);
    PMSIV_MENU_SetActiveEntry(view->menu, (u8)PMS_INPUT_GetCancelSelected(view->input), 0);
    PMS_INPUT_VIEW_EndTask(task);
}

void PMS_INPUT_VIEW_TaskLeaveMenu(void *tcb, struct PmsInputViewTask *task) {
    struct PmsInputView *view = task->view;
    view->inWordPick = 0;
    PMSIV_MENU_SetActiveEntry(view->menu, (u8)PMS_INPUT_GetCancelSelected(view->input), 0);
    PMSIV_EDIT_NoopB(view->edit);
    PMSIV_EDIT_SetCursorsVisible(view->edit, 1);
    PMSIV_EDIT_PlaceCursorAtSlot(view->edit, PMS_INPUT_GetWordSlot(task->input));
    PMS_INPUT_VIEW_EndTask(task);
}

void PMS_INPUT_VIEW_TaskShowCategory(void *tcb, struct PmsInputViewTask *task) {
    struct PmsInputView *view = task->view;
    int categoryDone, editDone;
    switch (task->state) {
    case 0:
        PMSIV_EDIT_SetCursorsVisible(view->edit, 1);
        PMSIV_EDIT_PlaceCursorAtSlot(view->edit, PMS_INPUT_GetWordSlot(task->input));
        ++task->state;
        break;
    case 1:
        PMS_INPUT_ResetSearch(task->input);
        PMSIV_MENU_ShowWordEntries(view->menu);
        PMSIV_EDIT_ReleaseCursor(view->edit);
        PMSIV_EDIT_NoopA(view->edit);
        PMSIV_CATEGORY_StartFadeIn(view->category);
        PMSIV_EDIT_StartPanelScroll(view->edit, 0);
        if (PMS_INPUT_GetBrowseMode(task->input) == 1) PMSIV_CATEGORY_DrawTitle(view->category);
        if (PMS_INPUT_GetBrowseMode(task->input) == 0) PMS_INPUT_VIEW_PrintHelpMessage(task, 2);
        else PMS_INPUT_VIEW_PrintHelpMessage(task, 4);
        ++task->state;
        break;
    case 2:
        categoryDone = PMSIV_CATEGORY_IsFadeInDone(view->category);
        editDone = PMSIV_EDIT_StepPanelScroll(view->edit);
        if (categoryDone && editDone) {
            PMSIV_CATEGORY_MoveCursor(view->category, PMS_INPUT_GetCursorPos(view->input));
            PMSIV_CATEGORY_SetCursorVisible(view->category, 1);
            PMS_INPUT_VIEW_EndTask(task);
        }
        break;
    }
}

void PMS_INPUT_VIEW_TaskRefreshCategory(void *tcb, struct PmsInputViewTask *task) {
    struct PmsInputView *view = task->view;
    switch (task->state) {
    case 0:
        ++task->state;
    case 1:
        PMSIV_MENU_ShowWordEntries(view->menu);
        PMSIV_CATEGORY_RefreshScreens(view->category);
        PMSIV_CATEGORY_ApplyBgOffset(view->category);
        if (PMS_INPUT_GetBrowseMode(task->input) == 1) PMSIV_CATEGORY_DrawTitle(view->category);
        ++task->state;
        break;
    case 2:
        if (PMSIV_CATEGORY_IsReady(view->category)) PMS_INPUT_VIEW_EndTask(task);
        break;
    }
}

/*
 * abi: CF70 forwards its legacy third argument only to CE48, whose full
 *   body ignores it and calls D0F8(task,7,0); original A448 sets only r0/r1.
 */
void PMS_INPUT_VIEW_TaskMenuToCategory(void *tcb, struct PmsInputViewTask *task) {
    struct PmsInputView *view=task->view;
    int categoryReady,menuReady;
    switch(task->state) {
    case 0:
        PMSIV_MENU_StartPress(view->menu,1);
        PMSIV_CATEGORY_ShowWordList(view->category,0);
        ++task->state;
        break;
    case 1:
        categoryReady=PMSIV_CATEGORY_IsListReady(view->category,0);
        menuReady=PMSIV_MENU_IsPressDone(view->menu,1);
        if(categoryReady && menuReady) {
            PMSIV_MENU_FinishPress(view->menu,1);
            PMS_INPUT_ResetSearch(task->input);
            PMSIV_MENU_ShowWordEntries(view->menu);
            PMSIV_CATEGORY_SetCursorVisible(view->category,0);
            PMSIV_CATEGORY_RefreshScreens(view->category);
            PMSIV_CATEGORY_ApplyBgOffset(view->category);
            if(PMS_INPUT_GetBrowseMode(task->input)==1) PMSIV_CATEGORY_DrawTitle(view->category);
            if(PMS_INPUT_GetBrowseMode(task->input)==0) PMS_INPUT_VIEW_PrintHelpMessage(task,2);
            else PMS_INPUT_VIEW_PrintHelpMessage(task,4);
            ++task->state;
        }
        break;
    case 2:
        if(PMSIV_CATEGORY_IsReady(view->category)) ++task->state;
        break;
    case 3:
        PMSIV_CATEGORY_MoveCursor(view->category,PMS_INPUT_GetCursorPos(view->input));
        PMSIV_CATEGORY_SetCursorVisible(view->category,1);
        PMS_INPUT_VIEW_EndTask(task);
        break;
    }
}

void PMS_INPUT_VIEW_TaskCategoryToMenu(void *tcb, struct PmsInputViewTask *task) {
    struct PmsInputView *view=task->view;
    int categoryReady,menuReady;
    switch(task->state) {
    case 0:
        if(PMS_INPUT_GetBrowseMode(task->input)==1) {
            PMSIV_MENU_StartPress(view->menu,0);
            PMSIV_CATEGORY_ShowWordList(view->category,0);
        } else PMSIV_MENU_PressBackButton(view->menu);
        ++task->state;
        break;
    case 1:
        if(PMS_INPUT_GetBrowseMode(task->input)==1) {
            categoryReady=PMSIV_CATEGORY_IsListReady(view->category,0);
            menuReady=PMSIV_MENU_IsPressDone(view->menu,0);
        } else {
            categoryReady=PMSIV_MENU_IsBackButtonDone(view->menu);
            menuReady=1;
        }
        if(categoryReady && menuReady) ++task->state;
        break;
    case 2:
        PMSIV_MENU_ShowEditEntries((view->menu));
        PMSIV_CATEGORY_SetCursorVisible(view->category,0);
        PMSIV_CATEGORY_StartClose(view->category);
        PMSIV_EDIT_StartPanelScroll(view->edit,1);
        if(PMS_INPUT_HasInitialSentence(task->input) || PMS_INPUT_GetInputMode(task->input)!=2) PMS_INPUT_VIEW_PrintHelpMessage(task,1);
        else PMS_INPUT_VIEW_PrintHelpMessage(task,0);
        ++task->state;
        break;
    case 3:
        categoryReady=PMSIV_CATEGORY_StepClose(view->category);
        menuReady=PMSIV_EDIT_StepPanelScroll(view->edit);
        if(categoryReady && menuReady) {
            PMSIV_EDIT_NoopB(view->edit);
            PMSIV_EDIT_PressCursor(view->edit);
            view->inWordPick=0;
            PMS_INPUT_VIEW_EndTask(task);
        }
        break;
    }
}

void PMS_INPUT_VIEW_TaskCategoryToWordwin(void *tcb, struct PmsInputViewTask *task) {
    struct PmsInputView *view=task->view;
    int categoryReady,categoryShown;
    switch(task->state) {
    case 0:
        ++task->state;
        break;
    case 1:
        if(PMSIV_CATEGORY_IsSelectAnimDone(view->category)) {
            PMSIV_CATEGORY_SetCursorVisible(view->category,0);
            PMSIV_MENU_StartPress(view->menu,3);
            ++task->state;
        }
        break;
    case 2:
        if(PMSIV_MENU_IsPressDone(view->menu,3)) {
            PMSIV_CATEGORY_StartBlendOut(view->category);
            PMSIV_CATEGORY_ShowWordList(view->category,0);
            ++task->state;
        }
        break;
    case 3:
        categoryReady=PMSIV_CATEGORY_IsListReady(view->category,0);
        categoryShown=PMSIV_CATEGORY_IsBlendOutDone(view->category);
        if(categoryReady && categoryShown) {
            PMSIV_MENU_ShowOnlyBackButton(view->menu);
            PMSIV_WORDWIN_DrawList(view->wordwin);
            PMSIV_WORDWIN_StartOpen(view->wordwin);
            if(PMS_INPUT_GetBrowseMode(task->input)==0) PMS_INPUT_VIEW_PrintHelpMessage(task,3);
            else PMS_INPUT_VIEW_PrintHelpMessage(task,5);
            ++task->state;
        }
        break;
    case 4:
        if(PMSIV_WORDWIN_IsOpen(view->wordwin)) {
            unsigned scrollPos;
            PMSIV_WORDWIN_SetCursorCell(view->wordwin,PMS_INPUT_GetCursorCell(view->input));
            scrollPos=PMS_INPUT_GetTopRow(view->input);
            PMSIV_WORDWIN_SetThumbRow(view->wordwin,scrollPos,PMS_INPUT_GetMaxTopRow(view->input));
            PMSIV_WORDWIN_SetVisible(view->wordwin,1);
            PMS_INPUT_VIEW_EndTask(task);
        }
        break;
    }
}

void PMS_INPUT_VIEW_TaskWordwinToCategory(void *tcb, struct PmsInputViewTask *task)
{
    struct PmsInputView *view;
    int categoryHidden, categoryReady, activeFlag;
    u32 confirmEnabled;
    view = task->view;
    confirmEnabled = PMS_INPUT_GetInitialCount(task->input);
    switch (task->state) {
    case 0:
        PMSIV_MENU_PressBackButton(view->menu);
        ++task->state;
        break;
    case 1:
        if (PMSIV_MENU_IsBackButtonDone(view->menu)) ++task->state;
        break;
    case 2:
        PMSIV_MENU_ShowWordEntries(view->menu);
        ++task->state;
        break;
    case 3:
        PMSIV_WORDWIN_SetVisible(view->wordwin, 0);
        PMSIV_WORDWIN_StartClose(view->wordwin);
        ++task->state;
        break;
    case 4:
        if (PMSIV_WORDWIN_FinishClose(view->wordwin)) {
            PMSIV_CATEGORY_ApplyBgOffset(view->category);
            ++task->state;
        }
        break;
    case 5:
        PMS_INPUT_VIEW_LoadBgPalette(task->view, 0);
        activeFlag = 0;
        PMSIV_CATEGORY_StartBlendIn(view->category);
        if (PMS_INPUT_GetBrowseMode(task->input) == 0) {
            activeFlag = 0;
            PMSIV_CATEGORY_ShowWordList(view->category, activeFlag);
        } else {
            if (confirmEnabled) activeFlag = 1;
            PMSIV_CATEGORY_ShowWordList(view->category, activeFlag);
        }
        if (PMS_INPUT_GetBrowseMode(task->input) == 0) PMS_INPUT_VIEW_PrintHelpMessage(task, 2);
        else PMS_INPUT_VIEW_PrintHelpMessage(task, 4);
        ++task->state;
        break;
    case 6:
        categoryHidden = PMSIV_CATEGORY_IsBlendInDone(view->category);
        categoryReady = PMSIV_CATEGORY_IsListReady(view->category, confirmEnabled != 0);
        if (categoryHidden && categoryReady) {
            PMSIV_CATEGORY_MoveCursor(view->category, PMS_INPUT_GetCursorPos(view->input));
            PMSIV_CATEGORY_SetCursorVisible(view->category, 1);
            PMS_INPUT_VIEW_EndTask(task);
        }
        break;
    }
}

void PMS_INPUT_VIEW_TaskWordwinToEdit(void *tcb, struct PmsInputViewTask *task)
{
    struct PmsInputView *view;
    int wordwinDone, editDone;
    view = task->view;
    switch (task->state) {
    case 0:
        ++task->state;
        break;
    case 1:
        if (PMSIV_WORDWIN_IsPickAnimDone(view->wordwin)) {
            PMSIV_MENU_ShowEditEntries((view->menu));
            PMSIV_WORDWIN_SetVisible(view->wordwin, 0);
            PMSIV_WORDWIN_StartClose(view->wordwin);
            PMSIV_EDIT_StartPanelScroll(view->edit, 1);
            ++task->state;
        }
        break;
    case 2:
        wordwinDone = PMSIV_WORDWIN_FinishClose(view->wordwin);
        editDone = PMSIV_EDIT_StepPanelScroll(view->edit);
        if (wordwinDone && editDone) {
            PMSIV_CATEGORY_ResetBgScroll(view->category);
            PMS_INPUT_VIEW_LoadBgPalette(task->view, 0);
            PMSIV_CATEGORY_StartBlendIn(view->category);
            if (PMS_INPUT_HasInitialSentence(task->input) || PMS_INPUT_GetInputMode(task->input) != 2) PMS_INPUT_VIEW_PrintHelpMessage(task, 1);
            else PMS_INPUT_VIEW_PrintHelpMessage(task, 0);
            ++task->state;
        }
        break;
    case 3:
        if (PMSIV_CATEGORY_IsBlendInDone(view->category)) {
            PMSIV_CATEGORY_StartFadeOut(view->category);
            ++task->state;
        }
        break;
    case 4:
        if (PMSIV_CATEGORY_IsFadeOutDone(view->category)) {
            PMSIV_EDIT_Redraw(view->edit);
            PMSIV_EDIT_SetCursorsVisible(view->edit, 1);
            PMSIV_EDIT_NoopB(view->edit);
            PMSIV_EDIT_PressCursor(view->edit);
            view->inWordPick = 0;
            PMS_INPUT_VIEW_EndTask(task);
        }
        break;
    }
}

void PMS_INPUT_VIEW_TaskCloseWordwin(void *tcb, struct PmsInputViewTask *task) {
    struct PmsInputView *view;
    view=task->view;
    switch(task->state) {
    case 0:
        PMSIV_WORDWIN_SetVisible(view->wordwin,0);
        PMSIV_WORDWIN_StartClose(view->wordwin);
        ++task->state; break;
    case 1:
        if(PMSIV_WORDWIN_FinishClose(view->wordwin)) {
            PMSIV_CATEGORY_ResetBgScroll(view->category);
            PMS_INPUT_VIEW_LoadBgPalette(task->view,0);
            PMSIV_CATEGORY_StartBlendIn(view->category);
            ++task->state;
        } break;
    case 2:
        if(PMSIV_CATEGORY_IsBlendInDone(view->category)) {
            PMSIV_CATEGORY_StartFadeOut(view->category);
            ++task->state;
        } break;
    case 3:
        if(PMSIV_CATEGORY_IsFadeOutDone(view->category)) {
            PMSIV_EDIT_Redraw(view->edit);
            PMSIV_EDIT_SetCursorsVisible(view->edit,0);
            PMS_INPUT_VIEW_EndTask(task);
        } break;
    }
}

void PMS_INPUT_VIEW_TaskSetEditCursor(void *tcb, struct PmsInputViewTask *task)
{
    struct PmsInputView *view;
    view = task->view;
    PMSIV_EDIT_PlaceCursorAtSlot(view->edit, PMS_INPUT_GetWordSlot(view->input));
    PMS_INPUT_VIEW_EndTask(task);
}

void PMS_INPUT_VIEW_TaskSetMenuActive(void *tcb, struct PmsInputViewTask *task)
{
    struct PmsInputView *view;
    view = task->view;
    PMSIV_MENU_SetActiveEntry(view->menu, (u8)PMS_INPUT_GetCancelSelected(view->input), 1);
    PMS_INPUT_VIEW_EndTask(task);
}

void PMS_INPUT_VIEW_TaskSetCategoryPosition(void *tcb, struct PmsInputViewTask *task)
{
    struct PmsInputView *view;
    view = task->view;
    PMSIV_CATEGORY_MoveCursor(view->category, PMS_INPUT_GetCursorPos(view->input));
    PMS_INPUT_VIEW_EndTask(task);
}

void PMS_INPUT_VIEW_TaskSetWordwinCursor(void *tcb, struct PmsInputViewTask *task)
{
    struct PmsInputView *view;
    view = task->view;
    PMSIV_WORDWIN_SetCursorCell(view->wordwin, PMS_INPUT_GetCursorCell(view->input));
    PMS_INPUT_VIEW_EndTask(task);
}

void PMS_INPUT_VIEW_TaskScrollWordwin(void *tcb, struct PmsInputViewTask *task)
{
    struct PmsInputView *view;
    view = task->view;
    switch (task->state) {
    case 0:
        PMSIV_WORDWIN_Scroll(view->wordwin, PMS_INPUT_GetScrollDelta(view->input));
        (task->state)++;
        break;
    case 1:
        if (PMSIV_WORDWIN_UpdateScroll(view->wordwin)) PMS_INPUT_VIEW_EndTask(task);
        break;
    }
}

void PMS_INPUT_VIEW_TaskSetMenuDecide(void *tcb, struct PmsInputViewTask *task)
{
    struct PmsInputView *view;
    view=task->view;
    PMSIV_MENU_SetDecideEntry(view->menu,(u8)PMS_INPUT_GetCancelSelected(task->input),1);
    PMS_INPUT_VIEW_EndTask(task);
}

void PMS_INPUT_VIEW_TaskEndOnly1(void *tcb, struct PmsInputViewTask *task)
{
    PMS_INPUT_VIEW_EndTask(task);
}

void PMS_INPUT_VIEW_TaskResetEditCursor(void *tcb, struct PmsInputViewTask *task) {
    struct PmsInputView *view;
    view=task->view;
    if(view->inWordPick!=1) PMSIV_EDIT_PressCursor(view->edit);
    PMS_INPUT_VIEW_EndTask(task);
}

void PMS_INPUT_VIEW_TaskEndOnly2(void *tcb, struct PmsInputViewTask *task)
{
    PMS_INPUT_VIEW_EndTask(task);
}

void PMS_INPUT_VIEW_TaskEndOnly3(void *tcb, struct PmsInputViewTask *task)
{
    PMS_INPUT_VIEW_EndTask(task);
}

void PMS_INPUT_VIEW_TaskEndOnly4(void *tcb, struct PmsInputViewTask *task)
{
    PMS_INPUT_VIEW_EndTask(task);
}

void PMS_INPUT_VIEW_TaskEndOnly5(void *tcb, struct PmsInputViewTask *task)
{
    PMS_INPUT_VIEW_EndTask(task);
}

void PMS_INPUT_VIEW_TaskRefreshCategoryMenu(void *tcb, struct PmsInputViewTask *task) {
    struct PmsInputView *view;
    u32 confirmEnabled;
    view=task->view;
    confirmEnabled=PMS_INPUT_GetInitialCount(task->input);
    switch(task->state) {
    case 0:
        PMSIV_MENU_UpdateEntryPalettes(view->menu);
        PMSIV_CATEGORY_DrawTitle(view->category);
        PMSIV_CATEGORY_ShowWordList(view->category,confirmEnabled!=0);
        ++task->state;
        break;
    case 1:
        if(PMSIV_CATEGORY_IsListReady(view->category,confirmEnabled!=0)) ++task->state;
        break;
    case 2:
        PMS_INPUT_VIEW_EndTask(task);
        break;
    }
}

void PMS_INPUT_VIEW_TaskSetWordwinScroll(void *tcb, struct PmsInputViewTask *task)
{
    struct PmsInputView *view;
    view=task->view;
    PMSIV_WORDWIN_DrawListFrom(view->wordwin,PMS_INPUT_GetTopRow(view->input));
    PMS_INPUT_VIEW_EndTask(task);
}

void PMS_INPUT_VIEW_TaskUpdateMenuDecide(void *tcb, struct PmsInputViewTask *task) {
    struct PmsInputView *view;
    view=task->view;
    switch(task->state) {
    case 0:
        PMSIV_MENU_StartPress(view->menu,2);
        ++task->state;
        break;
    case 1:
        if(PMSIV_MENU_IsPressDone(view->menu,2)) {
            if(*view->uiInputMode==0 && PMS_INPUT_GetCursorPos(view->input)==253 && PMS_INPUT_GetSavedCursorPos(view->input)==253)
                PMSIV_MENU_SetActiveEntry(view->menu,1,1);
            else PMSIV_MENU_SetActiveEntry(view->menu,0,0);
            PMS_INPUT_VIEW_EndTask(task);
        }
        break;
    }
}

void PMS_INPUT_VIEW_TaskSetCategoryScroll(void *tcb, struct PmsInputViewTask *task)
{
    struct PmsInputView *view;
    view=task->view;
    switch(task->state) {
    case 0:
        PMSIV_CATEGORY_StartSelectAnim(view->category,PMS_INPUT_GetCursorPos(view->input));
        (task->state)++;
        break;
    case 1:
        if(PMSIV_CATEGORY_IsSelectAnimDone(view->category)) PMS_INPUT_VIEW_EndTask(task);
        break;
    }
}

void PMS_INPUT_VIEW_TaskSetWordwinPage(void *tcb, struct PmsInputViewTask *task)
{
    struct PmsInputView *view;
    view=task->view;
    switch(task->state) {
    case 0:
        PMSIV_WORDWIN_StartPickAnim(view->wordwin,PMS_INPUT_GetCursorCell(view->input));
        (task->state)++;
        break;
    case 1:
        if(PMSIV_WORDWIN_IsPickAnimDone(view->wordwin)) PMS_INPUT_VIEW_EndTask(task);
        break;
    }
}

int PMS_INPUT_VIEW_GetEditValue(struct PmsInputView *view)
{
    return PMSIV_EDIT_GetSlotCount(view->edit);
}

int PMS_INPUT_VIEW_GetEditEntry(struct PmsInputView *view, int i)
{
    return PMSIV_EDIT_GetSlotWordId(view->edit, i);
}

void PMS_INPUT_VIEW_SetEditText(struct PmsInputView *view, const void *src, u8 n)
{
    PMSIV_EDIT_GetSlotRect(view->edit, src, n);
}

int PMS_INPUT_VIEW_GetMenuResult(struct PmsInputView *view)
{
    if((int)PMSIV_MENU_IsEntryFinished(view->menu,(u8)PMS_INPUT_GetCancelSelected(view->input))) return 1;
    return -1;
}

void PMS_INPUT_VIEW_SetMenuItemMode(struct PmsInputView *view,int mode)
{
    PMSIV_MENU_SelectItem(view->menu,mode);
}

struct PmsivMenu *PMS_INPUT_VIEW_GetMenu(struct PmsInputView *view)
{
    return view->menu;
}

struct ClactUnit *PMS_INPUT_VIEW_GetClactUnit(struct PmsInputView *view)
{
    return view->clactUnit;
}

struct GfFont *PMS_INPUT_VIEW_GetFont(struct PmsInputView *view)
{
    return view->font;
}

struct PrintQue *PMS_INPUT_VIEW_GetPrintQue(struct PmsInputView *view)
{
    return view->printQue;
}

void PMS_INPUT_VIEW_GetCursorRes(struct PmsInputView *view, struct PmsInputViewSpriteRes *out, int screen)
{
    *out = view->cursorRes[screen];
}

void PMS_INPUT_VIEW_GetUiRes(struct PmsInputView *view, struct PmsInputViewSpriteRes *out, unsigned screen)
{
    *out = view->uiRes[screen];
}

/*
 * note 2026-10-05 (wD6 lane14): closed by `if (mode == 2) f = 1; else f = z;`:
 * the zero z merges into the u16 flag only in the else arm, so the narrowing
 * is emitted at the join into its own register (r4), as in the original.
 */
struct ClactActor *PMS_INPUT_VIEW_CreateActor(struct PmsInputView *view, const struct PmsInputViewSpriteRes *res, short x, short y, u32 priority, int mode)
{
    struct ClactActorSetup setup;
    struct ClactActor *actor;
    u16 f;
    int z;
    int s;
    setup.x = x;
    setup.y = y;
    setup.priority = priority;
    z = 0;
    setup.mode = z;
    setup.z = z;
    if (mode == 2)
        f = 1;
    else
        f = z;
    s = OS_DisableInterrupts();
    actor = CLACT_CreateActor(view->clactUnit, res->character, res->palette, res->cellAnim, &setup, f, PMS_INPUT_VIEW_HEAP_ID);
    OS_RestoreInterrupts(s);
    if (actor) {
        CLACT_SetActorAutoAnim(actor, 1);
        CLACT_SetActorAutoAnimSpeed(actor, 1 << 12);
    }
    return actor;
}

int PMS_INPUT_VIEW_CompareWordwinPosition(struct PmsInputView *view, int unused, unsigned n)
{
    struct ScreenPos pos;
    if(PMSIV_WORDWIN_GetThumb(view->wordwin, &pos)==0) return 3;
    if(n<(unsigned)pos.y) return 1;
    if(n>(unsigned)pos.y) return 2;
    if(n==(unsigned)pos.y) return 0;
    return 3;
}

void PMS_INPUT_VIEW_SetWordwinScrollOffset(struct PmsInputView *view, u32 v)
{
    PMSIV_WORDWIN_SetThumbY(view->wordwin, v);
}

unsigned PMS_INPUT_VIEW_GetWordwinItem(struct PmsInputView *view, unsigned n)
{
    return PMSIV_WORDWIN_GetThumbRow(view->wordwin, n);
}

void PMS_INPUT_VIEW_LoadBgPalette(struct PmsInputView *view,int variant)
{
    int paletteId, offset;
    if(variant) {
        paletteId=29;
        offset=96;
    } else {
        paletteId=28;
        offset=0;
    }
    ARC_UTIL_UploadBgPaletteAddFromHandleExt(view->arcHandle,paletteId,3,0,offset,0,0,PMS_INPUT_VIEW_HEAP_ID);
    view->paletteChanged=1;
    view->paletteVariant=variant;
}

void PMS_INPUT_VIEW_PrintHelpMessage(struct PmsInputViewTask *task,int index)
{
    HelpMessageTable table;
    void *msgData,*str;
    struct PmsInputView *view;
    table=gPmsInputHelpMessageIds;
    BMP_Clear(BMP_WIN_GetBmp(task->view->helpWin),7);
    msgData=func_02045B38(0,2,146,PMS_INPUT_VIEW_HEAP_ID);
    str=func_02045EC0(msgData,table.values[index]);
    view=task->view;
    PRINTSYS_PrintQueColor(task->view->printQue,BMP_WIN_GetBmp(view->helpWin),2,4,str,view->font,0x39e7);
    task->view->helpTextPending=1;
    STRBUF_Delete(str);
    MSGDATA_Delete(msgData);
}

void PMS_INPUT_VIEW_FlushHelpText(struct PmsInputView *view)
{
    struct BmpWin *win;
    if(view->helpTextPending!=0 && PRINTSYS_QUE_IsExistTarget(view->printQue,BMP_WIN_GetBmp(view->helpWin))==0) {
        win=view->helpWin;
        BMP_WIN_TransferChars(win);
        BMP_WIN_MakeScreen(win);
        func_02041B6C(BMP_WIN_GetBgLayer(win));
        view->helpTextPending=0;
    }
}

/*
 * extent: trailing two-byte zero padding
 */
void PMS_INPUT_VIEW_UpdateEditFocus(struct PmsInputView *view, struct PmsInput *input, struct PmsInputData *wordData)
{
    if(*view->uiInputMode==1) {
        PMSIV_EDIT_SetCursorsVisible(view->edit,0);
        PMSIV_MENU_SetActiveEntry(view->menu,(u8)PMS_INPUT_GetCancelSelected(view->input),0);
    } else if(view->inWordPick==1) {
        PMSIV_EDIT_SetCursorsVisible(view->edit,0);
        PMSIV_MENU_SetActiveEntry(view->menu,(u8)PMS_INPUT_GetCancelSelected(view->input),1);
    } else {
        PMSIV_EDIT_SetCursorsVisible(view->edit,1);
        PMSIV_MENU_SetActiveEntry(view->menu,(u8)PMS_INPUT_GetCancelSelected(view->input),0);
    }
}

void PMS_INPUT_VIEW_UpdateCategoryFocus(struct PmsInputView *view, struct PmsInput *input, struct PmsInputData *wordData)
{
    PMSIV_CATEGORY_SetCursorVisible(view->category,1);
    if(*view->uiInputMode==1) {
        if(PMS_INPUT_GetBrowseMode(input)==1) PMSIV_MENU_SetActiveEntry(view->menu,0,0);
    } else {
        PMSIV_CATEGORY_MoveCursor(view->category,PMS_INPUT_GetCursorPos(view->input));
    }
}

void PMS_INPUT_VIEW_UpdateWordwinFocus(struct PmsInputView *view, struct PmsInput *input, struct PmsInputData *wordData)
{
    PMSIV_WORDWIN_SetVisible(view->wordwin, 1);
}

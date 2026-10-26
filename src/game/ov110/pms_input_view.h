#ifndef GAME_OV110_PMS_INPUT_VIEW_H
#define GAME_OV110_PMS_INPUT_VIEW_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of pms_input_view.c, prototypes copied from their definitions. */

struct PmsInput;
struct PmsInputData;
struct PmsInputView;
struct PmsInputViewTask;
struct PmsivMenu;
struct Unit;
struct GfFont;
struct PrintQue;
struct PmsInputViewSpriteRes;
struct ClactActor;

#include "../types.h"
#include "../arm9/tcb_list.h"

struct TcbTask;

void *PMS_INPUT_VIEW_Create(struct PmsInput *input, struct PmsInputData *wordData);
void PMS_INPUT_VIEW_Delete(struct PmsInputView *view);
void *PMS_INPUT_VIEW_AddVBlankTask(TcbFunc fn, void *work, int priority);
void PMS_INPUT_VIEW_MainTask(struct TcbTask *tcb, void *work);
void PMS_INPUT_VIEW_VBlankTask(struct TcbTask *tcb, void *work);
void PMS_INPUT_VIEW_StartTask(struct PmsInputView *view, int id);
int PMS_INPUT_VIEW_IsIdle(struct PmsInputView *view);
int PMS_INPUT_VIEW_IsTaskNotRunning(struct PmsInputView *view, int id);
void PMS_INPUT_VIEW_EndTask(struct PmsInputViewTask *task);
void PMS_INPUT_VIEW_TaskInit(void *tcb, struct PmsInputViewTask *task);
void PMS_INPUT_VIEW_RegisterSpriteResources(struct PmsInputViewTask *task, void *archive);
void PMS_INPUT_VIEW_TaskExit(void *tcb, struct PmsInputViewTask *task);
void PMS_INPUT_VIEW_InitDisplay(struct PmsInputViewTask *task);
void PMS_INPUT_VIEW_TaskFadeIn(void *tcb, struct PmsInputViewTask *task);
void PMS_INPUT_VIEW_TaskActivateEdit(void *tcb, struct PmsInputViewTask *task);
void PMS_INPUT_VIEW_TaskUpdateEditFocus(void *tcb, struct PmsInputViewTask *task);
void PMS_INPUT_VIEW_TaskUpdateCategoryFocus(void *tcb, struct PmsInputViewTask *task);
void PMS_INPUT_VIEW_TaskUpdateWordwinFocus(void *tcb, struct PmsInputViewTask *task);
void PMS_INPUT_VIEW_TaskPickMenuItemDecided(void *tcb, struct PmsInputViewTask *task);
void PMS_INPUT_VIEW_TaskPickMenuItem(void *tcb, struct PmsInputViewTask *task);
void PMS_INPUT_VIEW_TaskLeaveMenu(void *tcb, struct PmsInputViewTask *task);
void PMS_INPUT_VIEW_TaskShowCategory(void *tcb, struct PmsInputViewTask *task);
void PMS_INPUT_VIEW_TaskRefreshCategory(void *tcb, struct PmsInputViewTask *task);
void PMS_INPUT_VIEW_TaskMenuToCategory(void *tcb, struct PmsInputViewTask *task);
void PMS_INPUT_VIEW_TaskCategoryToMenu(void *tcb, struct PmsInputViewTask *task);
void PMS_INPUT_VIEW_TaskCategoryToWordwin(void *tcb, struct PmsInputViewTask *task);
void PMS_INPUT_VIEW_TaskWordwinToCategory(void *tcb, struct PmsInputViewTask *task);
void PMS_INPUT_VIEW_TaskWordwinToEdit(void *tcb, struct PmsInputViewTask *task);
void PMS_INPUT_VIEW_TaskCloseWordwin(void *tcb, struct PmsInputViewTask *task);
void PMS_INPUT_VIEW_TaskSetEditCursor(void *tcb, struct PmsInputViewTask *task);
void PMS_INPUT_VIEW_TaskSetMenuActive(void *tcb, struct PmsInputViewTask *task);
void PMS_INPUT_VIEW_TaskSetCategoryPosition(void *tcb, struct PmsInputViewTask *task);
void PMS_INPUT_VIEW_TaskSetWordwinCursor(void *tcb, struct PmsInputViewTask *task);
void PMS_INPUT_VIEW_TaskScrollWordwin(void *tcb, struct PmsInputViewTask *task);
void PMS_INPUT_VIEW_TaskSetMenuDecide(void *tcb, struct PmsInputViewTask *task);
void PMS_INPUT_VIEW_TaskEndOnly1(void *tcb, struct PmsInputViewTask *task);
void PMS_INPUT_VIEW_TaskResetEditCursor(void *tcb, struct PmsInputViewTask *task);
void PMS_INPUT_VIEW_TaskEndOnly2(void *tcb, struct PmsInputViewTask *task);
void PMS_INPUT_VIEW_TaskEndOnly3(void *tcb, struct PmsInputViewTask *task);
void PMS_INPUT_VIEW_TaskEndOnly4(void *tcb, struct PmsInputViewTask *task);
void PMS_INPUT_VIEW_TaskEndOnly5(void *tcb, struct PmsInputViewTask *task);
void PMS_INPUT_VIEW_TaskRefreshCategoryMenu(void *tcb, struct PmsInputViewTask *task);
void PMS_INPUT_VIEW_TaskSetWordwinScroll(void *tcb, struct PmsInputViewTask *task);
void PMS_INPUT_VIEW_TaskUpdateMenuDecide(void *tcb, struct PmsInputViewTask *task);
void PMS_INPUT_VIEW_TaskSetCategoryScroll(void *tcb, struct PmsInputViewTask *task);
void PMS_INPUT_VIEW_TaskSetWordwinPage(void *tcb, struct PmsInputViewTask *task);
int PMS_INPUT_VIEW_GetEditValue(struct PmsInputView *view);
int PMS_INPUT_VIEW_GetEditEntry(struct PmsInputView *view, int i);
void PMS_INPUT_VIEW_SetEditText(struct PmsInputView *view, const void *src, u8 n);
int PMS_INPUT_VIEW_GetMenuResult(struct PmsInputView *view);
void PMS_INPUT_VIEW_SetMenuItemMode(struct PmsInputView *view,int mode);
struct PmsivMenu *PMS_INPUT_VIEW_GetMenu(struct PmsInputView *view);
struct Unit *PMS_INPUT_VIEW_GetClactUnit(struct PmsInputView *view);
struct GfFont *PMS_INPUT_VIEW_GetFont(struct PmsInputView *view);
struct PrintQue *PMS_INPUT_VIEW_GetPrintQue(struct PmsInputView *view);
void PMS_INPUT_VIEW_GetCursorRes(struct PmsInputView *view, struct PmsInputViewSpriteRes *out, int screen);
void PMS_INPUT_VIEW_GetUiRes(struct PmsInputView *view, struct PmsInputViewSpriteRes *out, unsigned screen, int unused);
struct ClactActor *PMS_INPUT_VIEW_CreateActor(struct PmsInputView *view, const struct PmsInputViewSpriteRes *res, int x, int y, u32 priority, int mode);
int PMS_INPUT_VIEW_CompareWordwinPosition(struct PmsInputView *view, int unused, unsigned n);
void PMS_INPUT_VIEW_SetWordwinScrollOffset(struct PmsInputView *view, u32 v);
unsigned PMS_INPUT_VIEW_GetWordwinItem(struct PmsInputView *view, unsigned n);
void PMS_INPUT_VIEW_LoadBgPalette(struct PmsInputView *view,int variant);
void PMS_INPUT_VIEW_PrintHelpMessage(struct PmsInputViewTask *task,int index);
void PMS_INPUT_VIEW_FlushHelpText(struct PmsInputView *view);
void PMS_INPUT_VIEW_UpdateEditFocus(struct PmsInputView *view, struct PmsInput *input, struct PmsInputData *wordData);
void PMS_INPUT_VIEW_UpdateCategoryFocus(struct PmsInputView *view, struct PmsInput *input, struct PmsInputData *wordData);
void PMS_INPUT_VIEW_UpdateWordwinFocus(struct PmsInputView *view, struct PmsInput *input, struct PmsInputData *wordData);
/* END mkheaders: generated region */

#endif

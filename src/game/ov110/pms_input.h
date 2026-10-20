#ifndef GAME_OV110_PMS_INPUT_H
#define GAME_OV110_PMS_INPUT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of pms_input.c, prototypes copied from their definitions. */

struct Proc;
struct PmsiParam;
struct PmsInput;
struct PmsSentenceCursor;
struct PmsData;
struct PmsWordListCursor;
struct PmsInputView;
struct PmsExitState;
struct TcbSystem;

#include "../ov110/pms_input_types.h"
#include "../types.h"

int PMS_INPUT_ProcInit(struct Proc *proc, int *seq, struct PmsiParam *param, void *work);
int PMS_INPUT_ProcMain(struct Proc *proc, int unused, int args, struct PmsInput *input);
void PMS_INPUT_OnButton(int value, unsigned int event, struct PmsInput *input);
int PMS_INPUT_ProcExit(struct Proc *proc, int unused, int args, struct PmsInput *input);
struct PmsInput *PMS_INPUT_Create(struct Proc *proc, struct PmsiParam *param);
void PMS_INPUT_InitSentenceCursor(struct PmsSentenceCursor *cursor, const struct PmsData *sentence);
void PMS_INPUT_NextSentence(struct PmsSentenceCursor *cursor, struct PmsData *sentence);
void PMS_INPUT_PrevSentence(struct PmsSentenceCursor *cursor, struct PmsData *sentence);
void PMS_INPUT_SelectSentenceType(struct PmsSentenceCursor *cursor, struct PmsData *sentence, int type);
void PMS_INPUT_Destroy(struct PmsInput *input, struct Proc *proc);
void PMS_INPUT_SetHandler(struct PmsInput *input, PmsInputHandler handler);
int PMS_INPUT_CheckUiSwitch(struct PmsInput *input, unsigned int *state);
void PMS_INPUT_OpenWordList(struct PmsInput *input);
int PMS_INPUT_HandleMenu(struct PmsInput *input, unsigned int *state);
int PMS_INPUT_UiSwitchMenu(struct PmsInput *input, unsigned int *state);
int PMS_INPUT_UiSwitchBrowse(struct PmsInput *input, unsigned int *state);
int PMS_INPUT_UiSwitchWordList(struct PmsInput *input, unsigned int *state);
int PMS_INPUT_HandleSingleWordMenuButtons(struct PmsInput *input, unsigned int *state);
int PMS_INPUT_HitSingleWordButtons(struct PmsInput *input);
int PMS_INPUT_HitDoubleWordButtons(struct PmsInput *input);
int PMS_INPUT_HitSentenceButtons(struct PmsInput *input);
int PMS_INPUT_HitSentenceTypeTab(struct PmsInput *input);
int PMS_INPUT_HandleWordMenuTouch(struct PmsInput *input, unsigned int *state);
int PMS_INPUT_HandleSingleWordMenu(struct PmsInput *input, unsigned int *state);
int PMS_INPUT_HandleDoubleWordMenuButtons(struct PmsInput *input, unsigned int *state);
int PMS_INPUT_HandleDoubleWordMenu(struct PmsInput *input, unsigned int *state);
int PMS_INPUT_HandleSentenceMenuButtons(struct PmsInput *input, unsigned int *state);
int PMS_INPUT_HandleSentenceMenuTouch(struct PmsInput *input, unsigned int *state);
int PMS_INPUT_HandleSentenceMenu(struct PmsInput *input, unsigned int *state);
int PMS_INPUT_HandleConfirmButtons(struct PmsInput *input, unsigned int *state);
int PMS_INPUT_HandleBrowse(struct PmsInput *input, unsigned int *state);
void PMS_INPUT_HandleBrowseKeys(struct PmsInput *input, unsigned int *state);
int PMS_INPUT_HitBrowseTopButtons(struct PmsInput *input);
int PMS_INPUT_HitBackButton(void);
int PMS_INPUT_HitCategoryCell(struct PmsInput *input);
int PMS_INPUT_HitInitialButtons(struct PmsInput *input);
int PMS_INPUT_HitInitialCell(struct PmsInput *input);
void PMS_INPUT_HandleBrowseTouch(struct PmsInput *input, unsigned int *state);
void PMS_INPUT_HandleBrowseInput(struct PmsInput *input, unsigned int *state);
int PMS_INPUT_CategoryHasWords(struct PmsInput *input);
int PMS_INPUT_MoveCursor(struct PmsInput *input);
int PMS_INPUT_MoveCategoryCursor(PmsInput *input);
int PMS_INPUT_MoveInitialCursor(PmsInput *input);
void PMS_INPUT_InitWordList(struct PmsWordListCursor *list, PmsInput *input);
u32 PMS_WORDLIST_GetCellOffset(struct PmsWordListCursor *list);
unsigned PMS_WORDLIST_GetSelectedIndex(struct PmsWordListCursor *list);
u32 PMS_WORDLIST_GetScrollDelta(struct PmsWordListCursor *list);
u16 PMS_WORDLIST_GetTopRow(struct PmsWordListCursor *list);
u16 PMS_WORDLIST_GetMaxTopRow(struct PmsWordListCursor *list);
int PMS_INPUT_HandleWordList(PmsInput *input, unsigned int *state);
void PMS_INPUT_HandleWordListKeys(PmsInput *input, unsigned int *state);
int PMS_INPUT_HitWordList(PmsInput *input);
int PMS_INPUT_HitScrollBarDrag(PmsInput *input);
void PMS_INPUT_HandleWordListTouch(PmsInput *input, unsigned int *state);
void PMS_INPUT_HandleWordListInput(PmsInput *input, unsigned int *state);
int PMS_WORDLIST_MoveByKeys(struct PmsWordListCursor *list, u32 keys);
int PMS_WORDLIST_PageUp(struct PmsWordListCursor *list);
u32 PMS_WORDLIST_PageDown(struct PmsWordListCursor *list);
int PMS_WORDLIST_JumpUp(struct PmsInputView *view,struct PmsWordListCursor *list);
int PMS_WORDLIST_JumpDown(struct PmsInputView *view,struct PmsWordListCursor *list);
int PMS_WORDLIST_DragTo(struct PmsInputView *view,struct PmsWordListCursor *list);
int PMS_INPUT_PickWord(PmsInput *input);
int PMS_INPUT_HandleFinish(PmsInput *input, unsigned int *state);
void PMS_INPUT_SetSubHandler(PmsInput *input, PmsInputSubHandler subHandler);
void PMS_INPUT_ClearSubHandler(PmsInput *input);
void PMS_INPUT_SubHandleOpen(PmsInput *input, unsigned int *state);
void PMS_INPUT_SubHandleConfirm(PmsInput *input, unsigned int *state);
void PMS_INPUT_SubHandleCancel(PmsInput *input, unsigned int *state);
int PMS_INPUT_IsComplete(PmsInput *input);
void PMS_INPUT_SetExitState(struct PmsExitState *exitState, u8 requested, u8 cancelled);
unsigned int *PMS_INPUT_GetUiInputModePtr(PmsInput *input);
u32 PMS_INPUT_GetInputMode(PmsInput *input);
u8 PMS_INPUT_GetBrowseMode(PmsInput *input);
int PMS_INPUT_GetSentenceType(PmsInput *input);
u32 PMS_INPUT_GetWord(PmsInput *input,u32 i);
void *PMS_INPUT_GetSentenceString(PmsInput *input, u32 heapId);
u16 PMS_INPUT_GetWordSlot(PmsInput *input);
u16 PMS_INPUT_GetCancelSelected(PmsInput *input);
u16 PMS_INPUT_GetCursorPos(PmsInput *input);
u16 PMS_INPUT_GetSavedCursorPos(PmsInput *input);
u32 PMS_INPUT_GetListItemCount(PmsInput *input);
void PMS_INPUT_GetListWord(PmsInput *input,u32 a,int b);
u32 PMS_INPUT_GetCursorCell(PmsInput *input);
int PMS_INPUT_GetScrollDelta(PmsInput *input);
unsigned PMS_INPUT_GetTopRow(PmsInput *input);
unsigned PMS_INPUT_GetMaxTopRow(PmsInput *input);
u32 PMS_INPUT_HasInitialSentence(PmsInput *input);
struct TcbSystem *PMS_INPUT_GetTasks(PmsInput *input);
void PMS_INPUT_SetSearchArg(PmsInput *input, void *arg);
void PMS_INPUT_ResetSearch(PmsInput *input);
void PMS_INPUT_GetScrollRange(const PmsInput *input, u16 *topRow, u16 *maxTopRow);
u8 PMS_INPUT_GetInitialCount(PmsInput *input);
int PMS_INPUT_GetSearchState(PmsInput *input);
void PMS_INPUT_GetInitialWord(PmsInput *input,u32 a,int b);
int PMS_INPUT_CanConfirm(PmsInput *input);
void PMS_INPUT_ResetCursor(PmsInput *input);
/* END mkheaders: generated region */

#endif

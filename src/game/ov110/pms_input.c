/*
 * file:     pms_input.c
 * unit:     yes
 * function: PMS_INPUT_ProcInit, PMS_INPUT_ProcMain, PMS_INPUT_OnButton, PMS_INPUT_ProcExit, PMS_INPUT_Create, PMS_INPUT_InitSentenceCursor, PMS_INPUT_NextSentence, PMS_INPUT_PrevSentence, PMS_INPUT_SelectSentenceType, PMS_INPUT_Destroy, PMS_INPUT_SetHandler, PMS_INPUT_CheckUiSwitch, PMS_INPUT_OpenWordList, PMS_INPUT_HandleMenu, PMS_INPUT_UiSwitchMenu, PMS_INPUT_UiSwitchBrowse, PMS_INPUT_UiSwitchWordList, PMS_INPUT_HandleSingleWordMenuButtons, PMS_INPUT_HitSingleWordButtons, PMS_INPUT_HitDoubleWordButtons, PMS_INPUT_HitSentenceButtons, PMS_INPUT_HitSentenceTypeTab, PMS_INPUT_HandleWordMenuTouch, PMS_INPUT_HandleSingleWordMenu, PMS_INPUT_HandleDoubleWordMenuButtons, PMS_INPUT_HandleDoubleWordMenu, PMS_INPUT_HandleSentenceMenuButtons, PMS_INPUT_HandleSentenceMenuTouch, PMS_INPUT_HandleSentenceMenu, PMS_INPUT_HandleConfirmButtons, PMS_INPUT_HandleBrowse, PMS_INPUT_HandleBrowseKeys, PMS_INPUT_HitBrowseTopButtons, PMS_INPUT_HitBackButton, PMS_INPUT_HitCategoryCell, PMS_INPUT_HitInitialButtons, PMS_INPUT_HitInitialCell, PMS_INPUT_HandleBrowseTouch, PMS_INPUT_HandleBrowseInput, PMS_INPUT_CategoryHasWords, PMS_INPUT_MoveCursor, PMS_INPUT_MoveCategoryCursor, PMS_INPUT_MoveInitialCursor, PMS_INPUT_InitWordList, PMS_WORDLIST_GetCellOffset, PMS_WORDLIST_GetSelectedIndex, PMS_WORDLIST_GetScrollDelta, PMS_WORDLIST_GetTopRow, PMS_WORDLIST_GetMaxTopRow, PMS_INPUT_HandleWordList, PMS_INPUT_HandleWordListKeys, PMS_INPUT_HitWordList, PMS_INPUT_HitScrollBarDrag, PMS_INPUT_HandleWordListTouch, PMS_INPUT_HandleWordListInput, PMS_WORDLIST_MoveByKeys, PMS_WORDLIST_PageUp, PMS_WORDLIST_PageDown, PMS_WORDLIST_JumpUp, PMS_WORDLIST_JumpDown, PMS_WORDLIST_DragTo, PMS_INPUT_PickWord, PMS_INPUT_HandleFinish, PMS_INPUT_SetSubHandler, PMS_INPUT_ClearSubHandler, PMS_INPUT_SubHandleOpen, PMS_INPUT_SubHandleConfirm, PMS_INPUT_SubHandleCancel, PMS_INPUT_IsComplete, PMS_INPUT_SetExitState, PMS_INPUT_GetUiInputModePtr, PMS_INPUT_GetInputMode, PMS_INPUT_GetBrowseMode, PMS_INPUT_GetSentenceType, PMS_INPUT_GetWord, PMS_INPUT_GetSentenceString, PMS_INPUT_GetWordSlot, PMS_INPUT_GetCancelSelected, PMS_INPUT_GetCursorPos, PMS_INPUT_GetSavedCursorPos, PMS_INPUT_GetListItemCount, PMS_INPUT_GetListWord, PMS_INPUT_GetCursorCell, PMS_INPUT_GetScrollDelta, PMS_INPUT_GetTopRow, PMS_INPUT_GetMaxTopRow, PMS_INPUT_HasInitialSentence, PMS_INPUT_GetTasks, PMS_INPUT_SetSearchArg, PMS_INPUT_ResetSearch, PMS_INPUT_GetScrollRange, PMS_INPUT_GetInitialCount, PMS_INPUT_GetSearchState, PMS_INPUT_GetInitialWord, PMS_INPUT_CanConfirm, PMS_INPUT_ResetCursor
 * address:  0x021BD484
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
 *   PMS_INPUT_DATA_GetCategoryWordCount 0x021B999C thumb ov110
 *   PMSI_SEARCH_GetKeyCount 0x021BB1F4 thumb ov110
 *   PMSI_SEARCH_GetKeyPosition 0x021BB224 thumb ov110
 *   GF_OVERLAY_Load 0x02034AC4 arm
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PMS_INPUT_VIEW_StartTask 0x021B9BEC thumb ov110
 *   PMS_INPUT_VIEW_IsIdle 0x021B9C74 thumb ov110
 *   PMS_INPUT_VIEW_GetEditValue 0x021BABE8 thumb ov110
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   TCB_Main 0x02030D28 arm
 *   KEY_GetTrg 0x020362DC arm
 *   KEY_GetCont 0x0203630C arm
 *   KEY_GetRepeat 0x0203633C arm
 *   BUTTON_MAN_UpdateSlots 0x02051C88 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   GF_OVERLAY_Unload 0x02034A5C arm
 *   ov067_id 0x00000043 data
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   PMSI_PARAM_GetInputMode 0x02024144 thumb
 *   PMSI_PARAM_GetUiInputMode 0x0202421C thumb
 *   PMSI_PARAM_GetResult 0x02024168 thumb
 *   TCB_GetTaskOffset 0x02030CB0 arm
 *   TCB_Init 0x02030CBC arm
 *   PMS_INPUT_DATA_Create 0x021B95A0 thumb ov110
 *   PMS_INPUT_VIEW_Create 0x021B9A50 thumb ov110
 *   BUTTON_MAN_Create 0x02051B84 arm
 *   PMSI_SEARCH_Create 0x021BAEDC thumb ov110
 *   PMS_INPUT_SetSubHandler 0x021BF4F8 thumb ov110
 *   PMS_INPUT_SubHandleOpen 0x021BF508 thumb ov110
 *   gPmsInputButtonRects 0x021C3908 data a1
 *   gPmsInputFileName 0x021C3C78 data a1
 *   PMSI_PARAM_GetSentenceType 0x0202452C thumb
 *   PMSI_PARAM_GetSentenceCount 0x02024584 thumb
 *   PMSI_PARAM_GetSentenceId 0x02024530 thumb
 *   PMSI_PARAM_SetSentenceId 0x02024598 thumb
 *   PMSI_PARAM_SetUiInputMode 0x02024224 thumb
 *   BUTTON_MAN_Delete 0x02051C6C arm
 *   PMS_INPUT_VIEW_Delete 0x021B9B20 thumb ov110
 *   TCB_Noop 0x02030DA4 arm
 *   PMS_INPUT_DATA_Delete 0x021B95F4 thumb ov110
 *   PMSI_SEARCH_Delete 0x021BAF4C thumb ov110
 *   PROCSYS_FreeProcWork 0x020315D4 arm
 *   PMS_INPUT_HandleWordList 0x021BEDEC thumb ov110
 *   PMS_INPUT_VIEW_UpdateEditFocus 0x021BAE24 thumb ov110
 *   PMS_INPUT_VIEW_UpdateCategoryFocus 0x021BAE94 thumb ov110
 *   PMS_INPUT_VIEW_UpdateWordwinFocus 0x021BAED0 thumb ov110
 *   TOUCHPANEL_GetCont 0x02035C38 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   PMS_INPUT_InitWordList 0x021BED84 thumb ov110
 *   gPmsInputMenuHandlers 0x021C3920 data a4
 *   PMS_INPUT_SubHandleConfirm 0x021BF53C thumb ov110
 *   PMS_INPUT_SubHandleCancel 0x021BF608 thumb ov110
 *   PMS_INPUT_ResetCursor 0x021BF82C thumb ov110
 *   PMS_INPUT_IsComplete 0x021BF680 thumb ov110
 *   gPmsInputSingleWordButtonHits 0x021C3938 data ov110 a1
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   gPmsInputDoubleWordButtonHits 0x021C3948 data ov110 a1
 *   gPmsInputSlotRectTemplate 0x021C38F0 data a1
 *   gPmsInputSentenceButtonHits 0x021C395C data a1
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   TOUCHPANEL_HitPoint 0x02035D40 arm
 *   PMSI_PARAM_HasInitialSentence 0x02024158 thumb
 *   PMS_INPUT_VIEW_SetEditText 0x021BAC00 thumb ov110
 *   PMS_INPUT_VIEW_SetMenuItemMode 0x021BAC30 thumb ov110
 *   PMS_INPUT_VIEW_IsTaskNotRunning 0x021B9C90 thumb ov110
 *   PMSI_SEARCH_Run 0x021BB054 thumb ov110
 *   PMSI_SEARCH_PopKey 0x021BAFAC thumb ov110
 *   PMSI_SEARCH_PushKey 0x021BAF7C thumb ov110
 *   gPmsInputBrowseTopButtonHits 0x021C392C data a1
 *   gPmsInputBackButtonHit 0x021C3918 data a1
 *   gPmsInputCategoryCellTemplate 0x021C39B0 data a1
 *   gPmsInputInitialButtonHits 0x021C39C4 data a1
 *   gPmsInputInitialCellTemplate 0x021C38F8 data a1
 *   gPmsInputCursorMoveFns 0x021C3910 data a4
 *   PMS_INPUT_SetHandler 0x021BD7A0 thumb ov110
 *   PMS_INPUT_HandleBrowse 0x021BE4C0 thumb ov110
 *   PMS_INPUT_HandleMenu 0x021BD894 thumb ov110
 *   PMS_INPUT_HitBackButton 0x021BE7F0 thumb ov110
 *   PMS_INPUT_CheckUiSwitch 0x021BD808 thumb ov110
 *   PMS_INPUT_GetUiInputModePtr 0x021BF6D4 thumb ov110
 *   PMS_INPUT_GetTasks 0x021BF7D0 thumb ov110
 *   PMS_INPUT_HasInitialSentence 0x021BF7C4 thumb ov110
 *   PMS_INPUT_GetInputMode 0x021BF6D8 thumb ov110
 *   PMS_INPUT_GetWordSlot 0x021BF714 thumb ov110
 *   PMS_INPUT_GetCancelSelected 0x021BF71C thumb ov110
 *   PMS_INPUT_ResetSearch 0x021BF7E0 thumb ov110
 *   PMS_INPUT_GetBrowseMode 0x021BF6DC thumb ov110
 *   PMS_INPUT_GetCursorPos 0x021BF724 thumb ov110
 *   PMS_INPUT_GetCursorCell 0x021BF784 thumb ov110
 *   PMS_INPUT_GetTopRow 0x021BF7AC thumb ov110
 *   PMS_INPUT_GetMaxTopRow 0x021BF7B8 thumb ov110
 *   PMS_INPUT_GetInitialCount 0x021BF7FC thumb ov110
 *   PMS_INPUT_GetScrollDelta 0x021BF7A0 thumb ov110
 *   PMS_INPUT_GetSavedCursorPos 0x021BF72C thumb ov110
 *   PMS_INPUT_SetSearchArg 0x021BF7D4 thumb ov110
 *   PMS_INPUT_GetInitialWord 0x021BF814 thumb ov110
 *   PMS_INPUT_GetSentenceType 0x021BF6E4 thumb ov110
 *   PMS_INPUT_GetWord 0x021BF6F0 thumb ov110
 *   PMS_INPUT_GetSentenceString 0x021BF708 thumb ov110
 *   PMS_INPUT_CanConfirm 0x021BF824 thumb ov110
 *   PMS_INPUT_GetSearchState 0x021BF808 thumb ov110
 *   gPmsInputCategoryCursorMap 0x021C3978 data a1
 *   PMSI_SEARCH_GetKeyUp 0x021BB240 thumb ov110
 *   PMSI_SEARCH_GetKeyDown 0x021BB250 thumb ov110
 *   PMSI_SEARCH_GetKeyLeft 0x021BB260 thumb ov110
 *   PMSI_SEARCH_GetKeyRight 0x021BB270 thumb ov110
 *   PMSI_SEARCH_GetKeyKind 0x021BB280 thumb ov110
 *   gPmsInputWordCellTemplate 0x021C39A8 data a1
 *   gPmsInputWordListButtonHits 0x021C3900 data a1
 *   PMS_INPUT_VIEW_CompareWordwinPosition 0x021BACDC thumb ov110
 *   PMS_INPUT_VIEW_SetWordwinScrollOffset 0x021BAD14 thumb ov110
 *   TOUCHPANEL_GetPointCont 0x02035CB8 arm
 *   PMS_INPUT_VIEW_GetWordwinItem 0x021BAD20 thumb ov110
 *   PMS_INPUT_DATA_GetCategoryWordId 0x021B99C4 thumb ov110
 *   PMSI_SEARCH_GetResultWordId 0x021BB1E4 thumb ov110
 *   PMS_INPUT_VIEW_GetEditEntry 0x021BABF4 thumb ov110
 *   PMSI_PARAM_SetWordAt 0x020245A0 thumb
 *   PMS_INPUT_VIEW_GetMenuResult 0x021BAC0C thumb ov110
 *   PMSI_PARAM_ClearUnusedWords 0x020245AC thumb
 *   PMSI_PARAM_SetResult 0x020241E0 thumb
 *   PMSI_PARAM_IsComplete 0x02024464 thumb
 *   PMSI_PARAM_GetWordRaw 0x020244F0 thumb
 *   PMSI_SEARCH_HasResults 0x021BB1C0 thumb ov110
 *   PMS_INPUT_DATA_GetCategoryWordString 0x021B99A4 thumb ov110
 *   PMSI_SEARCH_GetResultString 0x021BB1CC thumb ov110
 *   PMSI_SEARCH_BuildInputText  0x021BB00C  thumb  ov110
 *   PMSI_SEARCH_ClearInput 0x021BAFE4 thumb ov110
 *   PMSI_SEARCH_GetInputCount  0x021BAFDC  thumb  ov110
 *   PMSI_PARAM_GetSourceString  0x0202441C  thumb  arm9
 */
#include "pms_input_types.h"
#include "pmsiv_wordwin_types.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct Proc;

extern void *GFL_HEAP_Alloc(unsigned heapId, unsigned size, int clear, const char *site, u16 tag);

extern u32 GFL_HEAP_Free(void *mem);

extern int GF_OVERLAY_Load(int overlayId);

extern void GF_OVERLAY_Unload(int overlayId);

extern void GFL_HEAP_CreateChildHeap(unsigned int parent, unsigned int heapId, unsigned int size);

extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);

extern void GFL_HEAP_DeleteChecked(u32 heapId);

extern void PROCSYS_FreeProcWork(struct Proc *proc);

extern void *PROCSYS_AllocProcWork(struct Proc *proc, u32 size, u32 heapId);

extern u32 TCB_GetTaskOffset(u32 taskCount);

extern struct TcbSystem *TCB_Init(u32 taskCount, void *buf);

extern void TCB_Main(struct TcbSystem *tasks);

extern void TCB_Noop(struct TcbSystem *tasks);

extern u32 KEY_GetTrg(void);

extern unsigned int KEY_GetCont(void);

extern unsigned int KEY_GetRepeat(void);

extern int TOUCHPANEL_GetCont(void);

extern int TOUCHPANEL_GetTrg(void);

extern int TOUCHPANEL_HitTrg(const struct PmsTouchRect *table);

extern unsigned int TOUCHPANEL_GetPointTrg(unsigned int *x, unsigned int *y);

extern unsigned int TOUCHPANEL_HitPoint(const struct PmsTouchBox *table, unsigned int x, unsigned int y);

extern void GFL_USE_PlaySeDefaultVolume(u32 seId);

extern void *BUTTON_MAN_Create(const u8 *rects, void (*callback)(int, unsigned int, PmsInput *), PmsInput *arg, int heapId);

extern int BUTTON_MAN_UpdateSlots(void *buttonMan);

extern void BUTTON_MAN_Delete(void *buttonMan);

extern u32 PMSI_PARAM_GetInputMode(const struct PmsiParam *param);

extern u32 PMSI_PARAM_GetUiInputMode(const struct PmsiParam *param);

extern void PMSI_PARAM_SetUiInputMode(struct PmsiParam *param, u32 uiInputMode);

extern void PMSI_PARAM_GetResult(const struct PmsiParam *param, u16 *outWords, u16 *outSentence);

extern u32 PMSI_PARAM_HasInitialSentence(const struct PmsiParam *param);

extern int PMSI_PARAM_GetSentenceType(const struct PmsData *sentence);

extern unsigned int PMSI_PARAM_GetSentenceId(const struct PmsData *sentence);

extern u8 PMSI_PARAM_GetSentenceCount(u32 sentenceType);

extern void PMSI_PARAM_SetSentenceId(struct PmsData *sentence, int sentenceType, int sentenceId);

extern void PMS_INPUT_VIEW_StartTask(struct PmsInputView *view, int command);

extern int PMS_INPUT_VIEW_IsIdle(struct PmsInputView *view);

extern int PMS_INPUT_VIEW_IsTaskNotRunning(struct PmsInputView *view, int command);

extern int PMS_INPUT_VIEW_GetEditValue(struct PmsInputView *view);

extern void PMS_INPUT_VIEW_SetEditText(struct PmsInputView *view, struct PmsTouchBox *out, u8 slot);

extern void PMS_INPUT_VIEW_SetMenuItemMode(struct PmsInputView *view, int direction);

extern int PMS_INPUT_VIEW_UpdateEditFocus(struct PmsInputView *view, PmsInput *input, struct PmsInputData *data);

extern int PMS_INPUT_VIEW_UpdateCategoryFocus(struct PmsInputView *view, PmsInput *input, struct PmsInputData *data);

extern int PMS_INPUT_VIEW_UpdateWordwinFocus(struct PmsInputView *view, PmsInput *input, struct PmsInputData *data);

extern struct PmsInputData *PMS_INPUT_DATA_Create(u32 heapId, struct PmsiParam *param);

extern void PMS_INPUT_DATA_Delete(struct PmsInputData *data);

extern struct PmsInputView *PMS_INPUT_VIEW_Create(PmsInput *input, struct PmsInputData *data);

extern void PMS_INPUT_VIEW_Delete(struct PmsInputView *view);

extern u32 PMS_INPUT_DATA_GetCategoryWordCount(struct PmsInputData *data, int category);

extern struct PmsInputSearch *PMSI_SEARCH_Create(PmsInput *input, struct PmsInputData *data, u16 heapId);

extern void PMSI_SEARCH_Delete(struct PmsInputSearch *search);

extern int PMSI_SEARCH_PopKey(struct PmsInputSearch *search);

extern int PMSI_SEARCH_Run(struct PmsInputSearch *search);

extern void PMSI_SEARCH_PushKey(struct PmsInputSearch *search, int index);

extern int PMSI_SEARCH_GetKeyCount(void);

extern void PMSI_SEARCH_GetKeyPosition(int index, int *outX, int *outY);

/* pmsiv_wordwin.c */
extern void PMS_INPUT_InitWordList(struct PmsWordListCursor *cursor, PmsInput *input);

extern int PMS_INPUT_HandleWordList(PmsInput *input, unsigned int *state);

extern void PMS_INPUT_SetSubHandler(PmsInput *input, PmsInputSubHandler subHandler);

extern void PMS_INPUT_SubHandleOpen(PmsInput *input, unsigned int *state);

extern void PMS_INPUT_SubHandleConfirm(PmsInput *input, unsigned int *state);

extern void PMS_INPUT_SubHandleCancel(PmsInput *input, unsigned int *state);

extern int PMS_INPUT_IsComplete(PmsInput *input);

extern void PMS_INPUT_ResetCursor(PmsInput *input);

extern char ov067_id[];

extern const u8 gPmsInputButtonRects[];

extern const char gPmsInputFileName[];

extern const struct PmsTouchRect gPmsInputSingleWordButtonHits[];

extern const struct PmsTouchRect gPmsInputDoubleWordButtonHits[];

extern const struct PmsTouchBox gPmsInputSlotRectTemplate;

extern const struct PmsTouchRect gPmsInputSentenceButtonHits[];

extern const struct PmsTouchRect gPmsInputBrowseTopButtonHits[];

extern const struct PmsTouchRect gPmsInputBackButtonHit[];

extern const struct PmsTouchBox gPmsInputCategoryCellTemplate;

extern const struct PmsTouchBox3 gPmsInputInitialButtonHits;

extern const struct PmsTouchBox gPmsInputInitialCellTemplate;

extern PmsInputHandler const gPmsInputMenuHandlers[];

extern int (*const gPmsInputCursorMoveFns[])(PmsInput *input);

int PMS_INPUT_ProcInit(struct Proc *proc, int *seq, struct PmsiParam *param, void *work);

int PMS_INPUT_ProcMain(struct Proc *proc, int unused, int args, PmsInput *input);

void PMS_INPUT_OnButton(int value, unsigned int event, PmsInput *input);

int PMS_INPUT_ProcExit(struct Proc *proc, int unused, int args, PmsInput *input);

PmsInput *PMS_INPUT_Create(struct Proc *proc, struct PmsiParam *param);

void PMS_INPUT_InitSentenceCursor(struct PmsSentenceCursor *cursor, const struct PmsData *sentence);

void PMS_INPUT_Destroy(PmsInput *input, struct Proc *proc);

void PMS_INPUT_SetHandler(PmsInput *input, PmsInputHandler handler);

int PMS_INPUT_CheckUiSwitch(PmsInput *input, unsigned int *state);

void PMS_INPUT_OpenWordList(PmsInput *input);

int PMS_INPUT_HandleMenu(PmsInput *input, unsigned int *state);

int PMS_INPUT_UiSwitchMenu(PmsInput *input, unsigned int *state);

int PMS_INPUT_UiSwitchBrowse(PmsInput *input, unsigned int *state);

int PMS_INPUT_UiSwitchWordList(PmsInput *input, unsigned int *state);

int PMS_INPUT_HandleConfirmButtons(PmsInput *input, unsigned int *state);

int PMS_INPUT_HandleBrowse(PmsInput *input, unsigned int *state);

void PMS_INPUT_HandleBrowseInput(PmsInput *input, unsigned int *state);

int PMS_INPUT_CategoryHasWords(PmsInput *input);

int PMS_INPUT_MoveCursor(PmsInput *input);

/* Process init: loads the screen, creates the work object and enters the menu handler once the view is up. */
int PMS_INPUT_ProcInit(struct Proc *proc, int *seq, struct PmsiParam *param, void *work)
{
    struct PmsInput *input;
    switch (*seq) {
    case 0:
        GF_OVERLAY_Load((int)ov067_id);
        GFL_HEAP_CreateChildHeap(1, 41, 0x18000);
        GFL_HEAP_CreateChildHeap(1, 42, 0x32000);
        input = PMS_INPUT_Create(proc, param);
        PMS_INPUT_VIEW_StartTask(input->view, 0);
        ++*seq;
        break;
    case 1:
        input = work;
        if (PMS_INPUT_VIEW_IsIdle(input->view)) {
            if (input->inputMode == PMS_INPUT_MODE_SENTENCE) input->wordSlotCount = PMS_INPUT_VIEW_GetEditValue(input->view);
            else input->wordSlotCount = 0;
            PMS_INPUT_VIEW_StartTask(input->view, 4);
            ++*seq;
        }
        break;
    case 2:
        input = work;
        if (PMS_INPUT_VIEW_IsIdle(input->view)) {
            PMS_INPUT_SetHandler(input, PMS_INPUT_HandleMenu);
            GFL_NET_RestartWithDefaultTimeout(1, 42);
            return 1;
        }
        break;
    }
    TCB_Main(input->tasks);
    return 0;
}

/* Process main: reads the keys and runs the sub handler if one is active, else the main handler. */
int PMS_INPUT_ProcMain(struct Proc *proc, int unused, int args, struct PmsInput *input)
{
    int result;
    int keys;
    keys = KEY_GetTrg(); input->keyTrg = keys;
    keys = KEY_GetCont(); input->keyCont = keys;
    keys = KEY_GetRepeat(); input->keyRepeat = keys;
    BUTTON_MAN_UpdateSlots(input->buttonMan);
    if (input->subHandler) {
        input->subHandler(input, &input->subState);
        result = 0;
    } else result = input->handler(input, &input->handlerState);
    TCB_Main(input->tasks);
    return result;
}

/* Touch button callback: records which button was hit. */
void PMS_INPUT_OnButton(int value, unsigned int event, struct PmsInput *input)
{
    switch (event) {
    case 0: input->lastButton = value; break;
    case 1:
    case 3: input->lastButton = 1; break;
    case 2: break;
    default: input->lastButton = 1; break;
    }
}

/* Process exit: destroys the work object and frees the two heaps. */
int PMS_INPUT_ProcExit(struct Proc *proc, int unused, int args, struct PmsInput *input)
{
    PMS_INPUT_Destroy(input, proc);
    GFL_HEAP_DeleteChecked(41);
    GFL_HEAP_DeleteChecked(42);
    GF_OVERLAY_Unload((int)ov067_id);
    return 1;
}

/* Allocates the work object and creates the data, view and search objects. */
struct PmsInput *PMS_INPUT_Create(struct Proc *proc, struct PmsiParam *param)
{
    struct PmsInput *input;
    void *taskBuf;
    input = PROCSYS_AllocProcWork(proc, 128, 41);
    input->param = param;
    input->inputMode = PMSI_PARAM_GetInputMode(param);
    input->uiInputMode = PMSI_PARAM_GetUiInputMode(input->param);
    PMSI_PARAM_GetResult(input->param, input->words, (u16 *)&input->sentence);
    if (input->inputMode == PMS_INPUT_MODE_SENTENCE) PMS_INPUT_InitSentenceCursor(&input->sentenceCursor, &input->sentence);
    taskBuf = GFL_HEAP_Alloc(41, TCB_GetTaskOffset(5), 0, gPmsInputFileName, 579);
    input->taskBuf = taskBuf;
    input->tasks = TCB_Init(5, taskBuf);
    input->data = PMS_INPUT_DATA_Create(41, input->param);
    input->view = PMS_INPUT_VIEW_Create(input, input->data);
    input->buttonMan = BUTTON_MAN_Create(gPmsInputButtonRects, PMS_INPUT_OnButton, input, 41);
    input->browseMode = PMS_BROWSE_CATEGORY;
    input->subHandler = 0;
    input->subState = 0;
    input->wordSlot = 0;
    input->cancelSelected = 0;
    input->lastButton = 1;
    input->search = PMSI_SEARCH_Create(input, input->data, 41);
    PMS_INPUT_SetSubHandler(input, PMS_INPUT_SubHandleOpen);
    return input;
}

/* Starts the sentence cursor on the sentence the caller passed in. */
void PMS_INPUT_InitSentenceCursor(struct PmsSentenceCursor *cursor, const struct PmsData *sentence)
{
    cursor->type = PMSI_PARAM_GetSentenceType(sentence);
    cursor->count = PMSI_PARAM_GetSentenceCount(cursor->type);
    cursor->index = PMSI_PARAM_GetSentenceId(sentence);
}

/* Moves the cursor to the next sentence, wrapping to the next sentence type. */
void PMS_INPUT_NextSentence(struct PmsSentenceCursor *cursor, struct PmsData *sentence)
{
    cursor->index++;
    if (cursor->index >= cursor->count) {
        cursor->index = 0;
        cursor->type++;
        if (cursor->type >= 5) cursor->type = 0;
        cursor->count = PMSI_PARAM_GetSentenceCount(cursor->type);
    }
    PMSI_PARAM_SetSentenceId(sentence, cursor->type, cursor->index);
}

/* Moves the cursor to the previous sentence, wrapping to the previous sentence type. */
void PMS_INPUT_PrevSentence(struct PmsSentenceCursor *cursor, struct PmsData *sentence)
{
    cursor->index--;
    if (cursor->index < 0) {
        cursor->type--;
        if (cursor->type < 0) cursor->type = 4;
        cursor->count = PMSI_PARAM_GetSentenceCount(cursor->type);
        cursor->index = cursor->count - 1;
    }
    PMSI_PARAM_SetSentenceId(sentence, cursor->type, cursor->index);
}

/* Selects the first sentence of a sentence type. */
void PMS_INPUT_SelectSentenceType(struct PmsSentenceCursor *cursor, struct PmsData *sentence, int type)
{
    cursor->index = 0;
    cursor->type = type;
    cursor->count = PMSI_PARAM_GetSentenceCount(cursor->type);
    PMSI_PARAM_SetSentenceId(sentence, cursor->type, cursor->index);
}

/* Frees everything the work object owns and ends the process. */
void PMS_INPUT_Destroy(struct PmsInput *input, struct Proc *proc)
{
    PMSI_PARAM_SetUiInputMode(input->param, input->uiInputMode);
    BUTTON_MAN_Delete(input->buttonMan);
    PMS_INPUT_VIEW_Delete(input->view);
    TCB_Noop(input->tasks);
    GFL_HEAP_Free(input->taskBuf);
    PMS_INPUT_DATA_Delete(input->data);
    PMSI_SEARCH_Delete(input->search);
    PROCSYS_FreeProcWork(proc);
}

/* Sets the main handler and the function that redraws the view when the input device changes. */
void PMS_INPUT_SetHandler(struct PmsInput *input, PmsInputHandler handler)
{
    input->handler = handler;
    input->handlerState = 0;
    if (handler == PMS_INPUT_HandleMenu) { PMS_INPUT_VIEW_UpdateEditFocus(input->view, input, input->data); input->uiSwitchFn = PMS_INPUT_UiSwitchMenu; }
    else if (handler == PMS_INPUT_HandleBrowse) { PMS_INPUT_VIEW_UpdateCategoryFocus(input->view, input, input->data); input->uiSwitchFn = PMS_INPUT_UiSwitchBrowse; }
    else if (handler == PMS_INPUT_HandleWordList) { PMS_INPUT_VIEW_UpdateWordwinFocus(input->view, input, input->data); input->uiSwitchFn = PMS_INPUT_UiSwitchWordList; }
    else input->uiSwitchFn = 0;
}

/* Switches between button and touch operation when the other device is used. Returns 1 on a switch. */
int PMS_INPUT_CheckUiSwitch(struct PmsInput *input, unsigned int *state)
{
    PmsInputUiSwitchFn switchFn;
    if (input->uiInputMode == 1) {
        if (TOUCHPANEL_GetCont()) return 0;
        if (KEY_GetCont()) { switchFn = input->uiSwitchFn; input->uiInputMode = 0; if (switchFn) switchFn(input, state); return 1; }
    } else {
        if (KEY_GetCont()) return 0;
        if (TOUCHPANEL_GetCont()) { switchFn = input->uiSwitchFn; input->uiInputMode = 1; if (switchFn) switchFn(input, state); return 1; }
    }
    return 0;
}

/* Opens the word list window. */
void PMS_INPUT_OpenWordList(struct PmsInput *input)
{
    GFL_USE_PlaySeDefaultVolume(PMS_SE_OK);
    PMS_INPUT_InitWordList(&input->wordList, input);
    input->returnHandler = PMS_INPUT_HandleWordList;
    PMS_INPUT_VIEW_StartTask(input->view, 12);
}

/* Runs the menu handler for the current input mode. */
int PMS_INPUT_HandleMenu(struct PmsInput *input, unsigned int *state) { return gPmsInputMenuHandlers[input->inputMode](input, state); }

/* Redraws the menu view after the input device changed. */
int PMS_INPUT_UiSwitchMenu(struct PmsInput *input, unsigned int *state) { return PMS_INPUT_VIEW_UpdateEditFocus(input->view, input, input->data); }

/* Redraws the browse view after the input device changed. */
int PMS_INPUT_UiSwitchBrowse(struct PmsInput *input, unsigned int *state) { return PMS_INPUT_VIEW_UpdateCategoryFocus(input->view, input, input->data); }

/* Redraws the word list view after the input device changed. */
int PMS_INPUT_UiSwitchWordList(struct PmsInput *input, unsigned int *state) { return PMS_INPUT_VIEW_UpdateWordwinFocus(input->view, input, input->data); }

/* Single word menu, button operation. */
int PMS_INPUT_HandleSingleWordMenuButtons(struct PmsInput *input, unsigned int *state) {
    switch(*state) {
    case 0:
        if(PMS_INPUT_VIEW_IsIdle(input->view)) {
            if(input->keyTrg&PMS_KEY_UP) {
                GFL_USE_PlaySeDefaultVolume(PMS_SE_MOVE); input->cancelSelected=1;
                PMS_INPUT_VIEW_StartTask(input->view,7); *state=1;
            } else if(input->keyTrg&(PMS_KEY_START|PMS_KEY_DOWN)) {
                GFL_USE_PlaySeDefaultVolume(PMS_SE_MOVE); input->cancelSelected=0;
                PMS_INPUT_VIEW_StartTask(input->view,7); *state=1;
            } else if(input->keyTrg&PMS_KEY_B) {
                GFL_USE_PlaySeDefaultVolume(PMS_SE_CANCEL); PMS_INPUT_SetSubHandler(input,PMS_INPUT_SubHandleCancel);
            } else if(input->keyTrg&PMS_KEY_A) {
                GFL_USE_PlaySeDefaultVolume(PMS_SE_OK); PMS_INPUT_ResetCursor(input);
                PMS_INPUT_VIEW_StartTask(input->view,10); *state=5;
            }
        }
        break;
    case 1:
        if(PMS_INPUT_VIEW_IsIdle(input->view)) {
            if(input->keyTrg&PMS_KEY_UP) {
                GFL_USE_PlaySeDefaultVolume(PMS_SE_MOVE);
                if(input->cancelSelected) { input->cancelSelected^=1; PMS_INPUT_VIEW_StartTask(input->view,17); }
                else { PMS_INPUT_VIEW_StartTask(input->view,9); *state=0; }
            } else if(input->keyTrg&PMS_KEY_DOWN) {
                GFL_USE_PlaySeDefaultVolume(PMS_SE_MOVE);
                if(input->cancelSelected) { PMS_INPUT_VIEW_StartTask(input->view,9); *state=0; }
                else { input->cancelSelected^=1; PMS_INPUT_VIEW_StartTask(input->view,17); }
            } else if(input->keyTrg&PMS_KEY_START) {
                GFL_USE_PlaySeDefaultVolume(PMS_SE_MOVE); input->cancelSelected=0; PMS_INPUT_VIEW_StartTask(input->view,17);
            } else if(input->keyTrg&PMS_KEY_A) {
                if(input->cancelSelected==0) {
                    if(PMS_INPUT_IsComplete(input)) GFL_USE_PlaySeDefaultVolume(PMS_SE_OK); else GFL_USE_PlaySeDefaultVolume(PMS_SE_ERROR);
                    *state=2;
                } else { GFL_USE_PlaySeDefaultVolume(PMS_SE_CANCEL); *state=3; }
            } else if(input->keyTrg&PMS_KEY_B) { GFL_USE_PlaySeDefaultVolume(PMS_SE_CANCEL); *state=3; }
        }
        break;
    case 2: *state=4; PMS_INPUT_SetSubHandler(input,PMS_INPUT_SubHandleConfirm); break;
    case 3: *state=4; PMS_INPUT_SetSubHandler(input,PMS_INPUT_SubHandleCancel); break;
    case 4: *state=1; break;
    case 6: if(PMS_INPUT_VIEW_IsIdle(input->view)) PMS_INPUT_SetHandler(input,PMS_INPUT_HandleConfirmButtons); break;
    case 5: if(PMS_INPUT_VIEW_IsIdle(input->view)) PMS_INPUT_SetHandler(input,PMS_INPUT_HandleBrowse); break;
    }
    return 0;
}

/* Touch hit test of the single word menu buttons. */
int PMS_INPUT_HitSingleWordButtons(struct PmsInput *input)
{
    return TOUCHPANEL_HitTrg(gPmsInputSingleWordButtonHits);
}

/* Touch hit test of the two word menu buttons. */
int PMS_INPUT_HitDoubleWordButtons(struct PmsInput *input)
{
    return TOUCHPANEL_HitTrg(gPmsInputDoubleWordButtonHits);
}

/* Touch hit test of the sentence menu: buttons first, then the word slots. */
int PMS_INPUT_HitSentenceButtons(struct PmsInput *input)
{
    unsigned int x, y;
    struct PmsTouchBox slot = gPmsInputSlotRectTemplate;
    int i, count, result;
    if (!TOUCHPANEL_GetTrg()) return -1;
    result = TOUCHPANEL_HitTrg(gPmsInputSentenceButtonHits);
    if (result != -1) {
        if (PMSI_PARAM_HasInitialSentence(input->param)) { if ((unsigned)(result - 2) <= 3) result = -1; return result; }
        return result;
    }
    count = PMS_INPUT_VIEW_GetEditValue(input->view);
    TOUCHPANEL_GetPointTrg(&x, &y);
    for (i = 0; i < count; i++) {
        PMS_INPUT_VIEW_SetEditText(input->view, &slot, i);
        if (TOUCHPANEL_HitPoint(&slot, x, y) != -1) return i + 6;
    }
    return -1;
}

/* Touch hit test of the sentence type tabs. Returns the tab or -1. */
int PMS_INPUT_HitSentenceTypeTab(struct PmsInput *input)
{
    u32 x, y;
    int result;
    if (PMSI_PARAM_HasInitialSentence(input->param)) return -1;
    if (!TOUCHPANEL_GetPointTrg(&x, &y)) return -1;
    if (y > 168) { result = x / 24U - 1; if (result >= 0 && result < 5) return result; }
    return -1;
}

/* Word menu (single and two words), touch operation. */
int PMS_INPUT_HandleWordMenuTouch(struct PmsInput *input, unsigned int *state)
{
    int hit;
    switch(*state) {
    case 0:
    case 1:
        if(input->inputMode==0) hit=PMS_INPUT_HitSingleWordButtons(input);
        else hit=PMS_INPUT_HitDoubleWordButtons(input);
        switch(hit) {
        case 0:
            if(PMS_INPUT_IsComplete(input)) GFL_USE_PlaySeDefaultVolume(PMS_SE_OK);
            else GFL_USE_PlaySeDefaultVolume(PMS_SE_ERROR);
            *state=2;
            break;
        case 1:
            GFL_USE_PlaySeDefaultVolume(PMS_SE_CANCEL);
            *state=3;
            break;
        case 2:
        case 3:
            GFL_USE_PlaySeDefaultVolume(PMS_SE_OK);
            PMS_INPUT_ResetCursor(input);
            input->wordSlot=hit-2;
            PMS_INPUT_VIEW_StartTask(input->view,10);
            *state=5;
            break;
        }
        break;
    case 2: *state=4; PMS_INPUT_SetSubHandler(input,PMS_INPUT_SubHandleConfirm); break;
    case 3: *state=4; PMS_INPUT_SetSubHandler(input,PMS_INPUT_SubHandleCancel); break;
    case 4: *state=0; break;
    case 5:
        if(PMS_INPUT_VIEW_IsIdle(input->view)) PMS_INPUT_SetHandler(input,PMS_INPUT_HandleBrowse);
        break;
    }
    return 0;
}

/* Single word menu: picks the button or touch handler. */
int PMS_INPUT_HandleSingleWordMenu(struct PmsInput *input, unsigned int *state) {
 int result;
 if(*state<=1 && PMS_INPUT_CheckUiSwitch(input,state) && !input->uiInputMode) { GFL_USE_PlaySeDefaultVolume(PMS_SE_MOVE); return 0; }
 if(input->uiInputMode==0) { result=PMS_INPUT_HandleSingleWordMenuButtons(input,state); }
 else { result=PMS_INPUT_HandleWordMenuTouch(input,state); }
 return result;
}

/* Two word menu, button operation. */
int PMS_INPUT_HandleDoubleWordMenuButtons(struct PmsInput *input, unsigned int *state)
{
    switch(*state) {
    case 0:
        if(PMS_INPUT_VIEW_IsIdle(input->view)) {
            if(input->keyTrg&PMS_KEY_UP) {
                GFL_USE_PlaySeDefaultVolume(PMS_SE_MOVE);
                input->cancelSelected=1;
                PMS_INPUT_VIEW_StartTask(input->view,7);
                *state=1;
            } else if(input->keyTrg&(PMS_KEY_START|PMS_KEY_DOWN)) {
                GFL_USE_PlaySeDefaultVolume(PMS_SE_MOVE);
                input->cancelSelected=0;
                PMS_INPUT_VIEW_StartTask(input->view,7);
                *state=1;
            } else if(input->keyTrg&PMS_KEY_LEFT) {
                if(input->wordSlot!=0) {
                    GFL_USE_PlaySeDefaultVolume(PMS_SE_MOVE);
                    input->wordSlot=0;
                    PMS_INPUT_VIEW_StartTask(input->view,16);
                }
            } else if(input->keyTrg&PMS_KEY_RIGHT) {
                if(input->wordSlot==0) {
                    GFL_USE_PlaySeDefaultVolume(PMS_SE_MOVE);
                    input->wordSlot=1;
                    PMS_INPUT_VIEW_StartTask(input->view,16);
                }
            } else if(input->keyTrg&PMS_KEY_B) {
                GFL_USE_PlaySeDefaultVolume(PMS_SE_CANCEL);
                PMS_INPUT_SetSubHandler(input,PMS_INPUT_SubHandleCancel);
            } else if(input->keyTrg&PMS_KEY_A) {
                GFL_USE_PlaySeDefaultVolume(PMS_SE_OK);
                PMS_INPUT_ResetCursor(input);
                PMS_INPUT_VIEW_StartTask(input->view,10);
                *state=5;
            }
        }
        break;
    case 1:
        if(PMS_INPUT_VIEW_IsIdle(input->view)) {
            if(input->keyTrg&PMS_KEY_UP) {
                GFL_USE_PlaySeDefaultVolume(PMS_SE_MOVE);
                if(input->cancelSelected) { input->cancelSelected^=1; PMS_INPUT_VIEW_StartTask(input->view,17); }
                else { PMS_INPUT_VIEW_StartTask(input->view,9); *state=0; }
            } else if(input->keyTrg&PMS_KEY_DOWN) {
                GFL_USE_PlaySeDefaultVolume(PMS_SE_MOVE);
                if(input->cancelSelected) { PMS_INPUT_VIEW_StartTask(input->view,9); *state=0; }
                else { input->cancelSelected^=1; PMS_INPUT_VIEW_StartTask(input->view,17); }
            } else if(input->keyTrg&PMS_KEY_START) {
                GFL_USE_PlaySeDefaultVolume(PMS_SE_MOVE); input->cancelSelected=0; PMS_INPUT_VIEW_StartTask(input->view,17);
            } else if(input->keyTrg&PMS_KEY_A) {
                if(input->cancelSelected==0) {
                    if(PMS_INPUT_IsComplete(input)) GFL_USE_PlaySeDefaultVolume(PMS_SE_OK);
                    else GFL_USE_PlaySeDefaultVolume(PMS_SE_ERROR);
                    *state=2;
                } else { GFL_USE_PlaySeDefaultVolume(PMS_SE_CANCEL); *state=3; }
            } else if(input->keyTrg&PMS_KEY_B) { GFL_USE_PlaySeDefaultVolume(PMS_SE_CANCEL); *state=3; }
        }
        break;
    case 2: *state=4; PMS_INPUT_SetSubHandler(input,PMS_INPUT_SubHandleConfirm); break;
    case 3: *state=4; PMS_INPUT_SetSubHandler(input,PMS_INPUT_SubHandleCancel); break;
    case 4: *state=1; break;
    case 6: if(PMS_INPUT_VIEW_IsIdle(input->view)) PMS_INPUT_SetHandler(input,PMS_INPUT_HandleConfirmButtons); break;
    case 5: if(PMS_INPUT_VIEW_IsIdle(input->view)) PMS_INPUT_SetHandler(input,PMS_INPUT_HandleBrowse); break;
    }
    return 0;
}

/* Two word menu: picks the button or touch handler. */
int PMS_INPUT_HandleDoubleWordMenu(struct PmsInput *input, unsigned int *state) {
 if(*state<=1 && PMS_INPUT_CheckUiSwitch(input,state) && !input->uiInputMode) { GFL_USE_PlaySeDefaultVolume(PMS_SE_MOVE); return 0; }
 if(input->uiInputMode==0) { return PMS_INPUT_HandleDoubleWordMenuButtons(input,state); }
 else { return PMS_INPUT_HandleWordMenuTouch(input,state); }
}

/* Sentence menu, button operation. */
int PMS_INPUT_HandleSentenceMenuButtons(struct PmsInput *input, unsigned int *state)
{
    int keys;
    int accept;
    int index;
    switch(*state) {
    case 0:
        input->wordSlotCount=PMS_INPUT_VIEW_GetEditValue(input->view);
        *state=1;
    case 1:
        if(PMSI_PARAM_HasInitialSentence(input->param)) {
            if(input->keyRepeat&PMS_KEY_LEFT) break;
            if(input->keyRepeat&PMS_KEY_RIGHT) break;
        }
        keys=input->keyTrg;
        if(keys&PMS_KEY_UP) {
            GFL_USE_PlaySeDefaultVolume(PMS_SE_MOVE);
            if(input->wordSlot==0) {
                input->cancelSelected=1;
                PMS_INPUT_VIEW_StartTask(input->view,7);
                *state=2;
            } else if(input->wordSlotCount>1 && input->wordSlot!=0) {
                (input->wordSlot)--;
                PMS_INPUT_VIEW_StartTask(input->view,16);
            }
        } else if(keys&PMS_KEY_DOWN) {
            GFL_USE_PlaySeDefaultVolume(PMS_SE_MOVE);
            if(input->wordSlotCount>1 && input->wordSlot<input->wordSlotCount-1) {
                (input->wordSlot)++;
                PMS_INPUT_VIEW_StartTask(input->view,16);
            } else {
                input->cancelSelected=0;
                PMS_INPUT_VIEW_StartTask(input->view,7);
                *state=2;
            }
        } else if((keys&PMS_KEY_START) || ((accept=keys&PMS_KEY_A) && input->wordSlotCount==0)) {
            GFL_USE_PlaySeDefaultVolume(PMS_SE_MOVE);
            input->cancelSelected=0;
            PMS_INPUT_VIEW_StartTask(input->view,7);
            *state=2;
        } else if(input->keyRepeat&PMS_KEY_LEFT) {
            GFL_USE_PlaySeDefaultVolume(PMS_SE_PAGE);
            input->wordSlot=0;
            PMS_INPUT_PrevSentence(&input->sentenceCursor,&input->sentence);
            PMS_INPUT_VIEW_StartTask(input->view,3);
            PMS_INPUT_VIEW_SetMenuItemMode(input->view,0);
            *state=3;
        } else if(input->keyRepeat&PMS_KEY_RIGHT) {
            GFL_USE_PlaySeDefaultVolume(PMS_SE_PAGE);
            input->wordSlot=0;
            PMS_INPUT_NextSentence(&input->sentenceCursor,&input->sentence);
            PMS_INPUT_VIEW_StartTask(input->view,3);
            PMS_INPUT_VIEW_SetMenuItemMode(input->view,1);
            *state=3;
        } else if(keys&PMS_KEY_B) {
            GFL_USE_PlaySeDefaultVolume(PMS_SE_CANCEL);
            PMS_INPUT_SetSubHandler(input,PMS_INPUT_SubHandleCancel);
        } else if(accept) {
            GFL_USE_PlaySeDefaultVolume(PMS_SE_OK);
            PMS_INPUT_ResetCursor(input);
            PMS_INPUT_VIEW_StartTask(input->view,10);
            *state=8;
        }
        break;
    case 3: if(PMS_INPUT_VIEW_IsTaskNotRunning(input->view,3)) *state=0; break;
    case 2:
        if(PMS_INPUT_VIEW_IsIdle(input->view)) {
            if(input->keyTrg&PMS_KEY_UP) {
                GFL_USE_PlaySeDefaultVolume(PMS_SE_MOVE);
                if(input->cancelSelected) { input->cancelSelected^=1; PMS_INPUT_VIEW_StartTask(input->view,17); }
                else {
                    index=input->wordSlotCount-1;
                    if(input->wordSlotCount==0) index=0;
                    input->wordSlot=index;
                    PMS_INPUT_VIEW_StartTask(input->view,9); *state=0;
                }
            } else if(input->keyTrg&PMS_KEY_DOWN) {
                GFL_USE_PlaySeDefaultVolume(PMS_SE_MOVE);
                if(input->cancelSelected) { input->wordSlot=0; PMS_INPUT_VIEW_StartTask(input->view,9); *state=0; }
                else { input->cancelSelected^=1; PMS_INPUT_VIEW_StartTask(input->view,17); }
            } else if(input->keyTrg&PMS_KEY_START) {
                GFL_USE_PlaySeDefaultVolume(PMS_SE_MOVE); input->cancelSelected=0; PMS_INPUT_VIEW_StartTask(input->view,17);
            } else if(input->keyTrg&PMS_KEY_A) {
                if(input->cancelSelected==0) {
                    if(PMS_INPUT_IsComplete(input)) GFL_USE_PlaySeDefaultVolume(PMS_SE_OK);
                    else GFL_USE_PlaySeDefaultVolume(PMS_SE_ERROR);
                    *state=4;
                } else { GFL_USE_PlaySeDefaultVolume(PMS_SE_CANCEL); *state=5; }
            } else if(input->keyTrg&PMS_KEY_B) { GFL_USE_PlaySeDefaultVolume(PMS_SE_CANCEL); *state=5; }
        }
        break;
    case 4: *state=6; PMS_INPUT_SetSubHandler(input,PMS_INPUT_SubHandleConfirm); break;
    case 5: *state=6; PMS_INPUT_SetSubHandler(input,PMS_INPUT_SubHandleCancel); break;
    case 6: *state=2; break;
    case 7: if(PMS_INPUT_VIEW_IsIdle(input->view)) PMS_INPUT_SetHandler(input,PMS_INPUT_HandleConfirmButtons); break;
    case 8: if(PMS_INPUT_VIEW_IsIdle(input->view)) PMS_INPUT_SetHandler(input,PMS_INPUT_HandleBrowse); break;
    }
    return 0;
}

/* Sentence menu, touch operation. */
int PMS_INPUT_HandleSentenceMenuTouch(struct PmsInput *input, unsigned int *state)
{
    int hit;
    int index;
    switch(*state) {
    case 0:
        input->wordSlotCount=PMS_INPUT_VIEW_GetEditValue(input->view);
        *state=1;
    case 1:
    case 2:
        index=PMS_INPUT_HitSentenceTypeTab(input);
        if(index>-1) {
            input->wordSlot=0;
            PMS_INPUT_SelectSentenceType(&input->sentenceCursor,&input->sentence,index);
            PMS_INPUT_VIEW_StartTask(input->view,3);
            GFL_USE_PlaySeDefaultVolume(PMS_SE_MOVE);
            *state=3;
        } else {
            hit=PMS_INPUT_HitSentenceButtons(input);
            switch(hit) {
            case 0:
                if(PMS_INPUT_IsComplete(input)) GFL_USE_PlaySeDefaultVolume(PMS_SE_OK);
                else GFL_USE_PlaySeDefaultVolume(PMS_SE_ERROR);
                input->cancelSelected=0;
                PMS_INPUT_VIEW_StartTask(input->view,8);
                *state=hit+4;
                break;
            case 1:
                GFL_USE_PlaySeDefaultVolume(PMS_SE_CANCEL);
                input->cancelSelected=1;
                PMS_INPUT_VIEW_StartTask(input->view,8);
                *state=hit+4;
                break;
            case 2:
            case 4:
                GFL_USE_PlaySeDefaultVolume(PMS_SE_PAGE);
                input->wordSlot=0;
                PMS_INPUT_PrevSentence(&input->sentenceCursor,&input->sentence);
                PMS_INPUT_VIEW_StartTask(input->view,3);
                PMS_INPUT_VIEW_SetMenuItemMode(input->view,0);
                *state=3;
                break;
            case 3:
            case 5:
                GFL_USE_PlaySeDefaultVolume(PMS_SE_PAGE);
                input->wordSlot=0;
                PMS_INPUT_NextSentence(&input->sentenceCursor,&input->sentence);
                PMS_INPUT_VIEW_StartTask(input->view,3);
                PMS_INPUT_VIEW_SetMenuItemMode(input->view,1);
                *state=3;
                break;
            case 6:
            case 7:
                GFL_USE_PlaySeDefaultVolume(PMS_SE_OK);
                PMS_INPUT_ResetCursor(input);
                input->wordSlot=hit-6;
                PMS_INPUT_VIEW_StartTask(input->view,10);
                *state=8;
                break;
            }
        }
        break;
    case 3: if(PMS_INPUT_VIEW_IsTaskNotRunning(input->view,3)) *state=0; break;
    case 4: *state=6; PMS_INPUT_SetSubHandler(input,PMS_INPUT_SubHandleConfirm); break;
    case 5: *state=6; PMS_INPUT_SetSubHandler(input,PMS_INPUT_SubHandleCancel); break;
    case 6: *state=2; break;
    case 7: if(PMS_INPUT_VIEW_IsIdle(input->view)) PMS_INPUT_SetHandler(input,PMS_INPUT_HandleConfirmButtons); break;
    case 8: if(PMS_INPUT_VIEW_IsIdle(input->view)) PMS_INPUT_SetHandler(input,PMS_INPUT_HandleBrowse); break;
    }
    return 0;
}

/* Sentence menu: picks the button or touch handler. */
int PMS_INPUT_HandleSentenceMenu(struct PmsInput *input, unsigned int *state) {
 if(*state<=2 && PMS_INPUT_CheckUiSwitch(input,state) && !input->uiInputMode) { GFL_USE_PlaySeDefaultVolume(PMS_SE_MOVE); return 0; }
 if(input->uiInputMode==0) { return PMS_INPUT_HandleSentenceMenuButtons(input,state); }
 else { return PMS_INPUT_HandleSentenceMenuTouch(input,state); }
}

/* Confirm and cancel buttons after the word list or browse screen was left. */
int PMS_INPUT_HandleConfirmButtons(struct PmsInput *input, unsigned int *state) {
    switch(*state) {
    case 0:
        if(PMS_INPUT_VIEW_IsIdle(input->view)) {
            if(input->keyTrg&PMS_KEY_UP) {
                GFL_USE_PlaySeDefaultVolume(PMS_SE_MOVE);
                if(input->cancelSelected) { input->cancelSelected^=1; PMS_INPUT_VIEW_StartTask(input->view,17); }
                else { PMS_INPUT_VIEW_StartTask(input->view,9); *state=0; }
            } else if(input->keyTrg&PMS_KEY_DOWN) {
                GFL_USE_PlaySeDefaultVolume(PMS_SE_MOVE);
                if(input->cancelSelected) { PMS_INPUT_VIEW_StartTask(input->view,9); *state=0; }
                else { input->cancelSelected^=1; PMS_INPUT_VIEW_StartTask(input->view,17); }
            } else if(input->keyTrg&PMS_KEY_START) {
                GFL_USE_PlaySeDefaultVolume(PMS_SE_MOVE); input->cancelSelected=0; PMS_INPUT_VIEW_StartTask(input->view,17);
            } else if(input->keyTrg&PMS_KEY_A) {
                GFL_USE_PlaySeDefaultVolume(PMS_SE_OK);
                if(input->cancelSelected==0) *state=1; else *state=2;
            } else if(input->keyTrg&PMS_KEY_B) { GFL_USE_PlaySeDefaultVolume(PMS_SE_OK); *state=2; }
        }
        break;
    case 1: *state=3; PMS_INPUT_SetSubHandler(input,PMS_INPUT_SubHandleConfirm); break;
    case 2: *state=4; PMS_INPUT_SetSubHandler(input,PMS_INPUT_SubHandleCancel); break;
    case 3:
    case 4: *state=0; break;
    case 5: if(PMS_INPUT_VIEW_IsIdle(input->view)) PMS_INPUT_SetHandler(input,PMS_INPUT_HandleMenu); break;
    }
    return 0;
}

/* Browse screen (categories and initial letters): view transitions and input. */
int PMS_INPUT_HandleBrowse(struct PmsInput *input, unsigned int *state) {
 switch(*state) {
 case 0:
  if(PMS_INPUT_VIEW_IsTaskNotRunning(input->view,18) && PMS_INPUT_VIEW_IsTaskNotRunning(input->view,33) && PMS_INPUT_VIEW_IsTaskNotRunning(input->view,32)) PMS_INPUT_HandleBrowseInput(input,state);
  break;
 case 1:
  if(PMS_INPUT_VIEW_IsTaskNotRunning(input->view,32)) {
   if(input->savedCursorPos!=253) { input->cursorPos=input->savedCursorPos; PMS_INPUT_VIEW_StartTask(input->view,18); }
   *state=0;
  }
  break;
 case 2:
  if(PMS_INPUT_VIEW_IsIdle(input->view)) { if(input->returnHandler==PMS_INPUT_HandleMenu) PMS_INPUT_VIEW_StartTask(input->view,4); *state=3; }
  break;
 case 3:
  if(PMS_INPUT_VIEW_IsIdle(input->view)) PMS_INPUT_SetHandler(input,input->returnHandler);
  break;
 case 4:
  if(PMS_INPUT_VIEW_IsTaskNotRunning(input->view,25)) *state=0;
  break;
 }
 return 0;
}

/* Browse screen, button operation. */
void PMS_INPUT_HandleBrowseKeys(struct PmsInput *input, unsigned int *state)
{
    if((input->keyTrg&PMS_KEY_START) && input->browseMode==1) {
        input->cursorPos=252;
        if(PMSI_SEARCH_Run(input->search)) {
            PMS_INPUT_OpenWordList(input);
            *state=2;
            return;
        }
        GFL_USE_PlaySeDefaultVolume(PMS_SE_ERROR);
        PMS_INPUT_VIEW_StartTask(input->view,18);
        return;
    }
    if(input->lastButton==0 || (input->keyTrg&PMS_KEY_SELECT)) {
        GFL_USE_PlaySeDefaultVolume(PMS_SE_TAB);
        input->browseMode^=1;
        PMS_INPUT_ResetCursor(input);
        PMS_INPUT_VIEW_StartTask(input->view,25);
        *state=4;
        return;
    }
    if(input->keyTrg&PMS_KEY_B) {
        if(input->browseMode==1 && PMSI_SEARCH_PopKey(input->search)) {
            input->savedCursorPos=input->cursorPos;
            *state=1;
            if(input->cursorPos!=253) {
                input->cursorPos=253;
                PMS_INPUT_VIEW_StartTask(input->view,18);
            }
            GFL_USE_PlaySeDefaultVolume(PMS_SE_SELECT_INITIAL);
            PMS_INPUT_VIEW_StartTask(input->view,32);
            PMSI_SEARCH_Run(input->search);
            PMS_INPUT_VIEW_StartTask(input->view,30);
            return;
        }
        if(input->browseMode==1 && input->cursorPos!=254) {
            input->cursorPos=254;
            PMS_INPUT_VIEW_StartTask(input->view,18);
        }
        GFL_USE_PlaySeDefaultVolume(PMS_SE_CANCEL);
        PMS_INPUT_VIEW_StartTask(input->view,11);
        input->returnHandler=PMS_INPUT_HandleMenu;
        *state=2;
        return;
    }
    if(input->keyTrg&PMS_KEY_A) {
        if(input->cursorPos==252) {
            if(PMSI_SEARCH_Run(input->search)) {
                PMS_INPUT_OpenWordList(input);
                *state=2;
                return;
            }
            GFL_USE_PlaySeDefaultVolume(PMS_SE_ERROR);
            return;
        } else if(input->cursorPos==253) {
            if(input->browseMode==1 && PMSI_SEARCH_PopKey(input->search)) {
                input->savedCursorPos=input->cursorPos;
                *state=1;
                GFL_USE_PlaySeDefaultVolume(PMS_SE_SELECT_INITIAL);
                PMS_INPUT_VIEW_StartTask(input->view,32);
                PMSI_SEARCH_Run(input->search);
                PMS_INPUT_VIEW_StartTask(input->view,30);
                return;
            }
            GFL_USE_PlaySeDefaultVolume(PMS_SE_ERROR);
            return;
        } else if(input->cursorPos==254) {
            GFL_USE_PlaySeDefaultVolume(PMS_SE_CANCEL);
            PMS_INPUT_VIEW_StartTask(input->view,11);
            input->returnHandler=PMS_INPUT_HandleMenu;
            *state=2;
            return;
        } else if(input->browseMode==0) {
            PMS_INPUT_VIEW_StartTask(input->view,33);
            if(PMS_INPUT_CategoryHasWords(input)) {
                PMS_INPUT_OpenWordList(input);
                *state=2;
                return;
            }
            GFL_USE_PlaySeDefaultVolume(PMS_SE_ERROR);
            return;
        } else {
            PMSI_SEARCH_PushKey(input->search,input->cursorPos);
            GFL_USE_PlaySeDefaultVolume(PMS_SE_OK);
            PMSI_SEARCH_Run(input->search);
            PMS_INPUT_VIEW_StartTask(input->view,30);
            PMS_INPUT_VIEW_StartTask(input->view,33);
            return;
        }
    }
    if(PMS_INPUT_MoveCursor(input)) {
        GFL_USE_PlaySeDefaultVolume(PMS_SE_MOVE);
        PMS_INPUT_VIEW_StartTask(input->view,18);
    }
}

/* Touch hit test of the two top buttons of the browse screen. */
int PMS_INPUT_HitBrowseTopButtons(struct PmsInput *input)
{
    int hit = TOUCHPANEL_HitTrg(gPmsInputBrowseTopButtonHits);
    if (hit == -1) return 0;
    switch (hit) {
    case 0: return 1;
    case 1: if (input->lastButton == 0) return 2; break;
    }
    return 0;
}

/* Touch hit test of the back button. */
int PMS_INPUT_HitBackButton(void) { return TOUCHPANEL_HitTrg(gPmsInputBackButtonHit); }

/* Touch hit test of the 4 by 3 category cells. Returns the cell or -1. */
int PMS_INPUT_HitCategoryCell(struct PmsInput *input)
{
    unsigned int x, y;
    struct PmsTouchBox cell = gPmsInputCategoryCellTemplate;
    int row, col;
    if (!TOUCHPANEL_GetTrg()) return -1;
    TOUCHPANEL_GetPointTrg(&x, &y);
    for (row = 0; row < 4; row++) {
        cell.rect.top = 24 * row + 56; cell.rect.bottom = cell.rect.top + 16;
        for (col = 0; col < 3; col++) {
            cell.rect.left = 80 * col + 12; cell.rect.right = cell.rect.left + 72;
            if (TOUCHPANEL_HitPoint(&cell, x, y) != -1) return col + 3 * row;
        }
    }
    return -1;
}

/* Touch hit test of the buttons next to the initial letter list. */
int PMS_INPUT_HitInitialButtons(struct PmsInput *input) { struct PmsTouchBox3 buttons = gPmsInputInitialButtonHits; return TOUCHPANEL_HitTrg(buttons.rects); }

/* Touch hit test of the initial letter cells. Returns the cell or -1. */
int PMS_INPUT_HitInitialCell(struct PmsInput *input)
{
    struct PmsTouchBox cell;
    int x, y;
    struct PmsTouchBox base;
    int i, count;
    count = PMSI_SEARCH_GetKeyCount();
    i = 0;
    if (count > 0) {
        base = gPmsInputInitialCellTemplate;
        do {
            cell = base;
            PMSI_SEARCH_GetKeyPosition(i, &x, &y);
            cell.rect.top = y + 48; cell.rect.bottom = y + 64; cell.rect.left = x + 8; cell.rect.right = x + 24;
            if (TOUCHPANEL_HitTrg(&cell.rect) != -1) return i;
            i++;
        } while (i < count);
    }
    return -1;
}

/* Browse screen, touch operation. */
void PMS_INPUT_HandleBrowseTouch(struct PmsInput *input, unsigned int *state)
{
    int r;
    switch(PMS_INPUT_HitBrowseTopButtons(input)) {
    case 1:
        GFL_USE_PlaySeDefaultVolume(PMS_SE_CANCEL);
        PMS_INPUT_VIEW_StartTask(input->view,11);
        input->returnHandler=PMS_INPUT_HandleMenu;
        *state=2;
        return;
    case 2:
        GFL_USE_PlaySeDefaultVolume(PMS_SE_TAB);
        input->browseMode^=1;
        PMS_INPUT_ResetCursor(input);
        PMS_INPUT_VIEW_StartTask(input->view,25);
        *state=4;
        return;
    }
    if(input->browseMode==0) {
        r=PMS_INPUT_HitCategoryCell(input);
        if(r>=0) {
            input->cursorPos=r;
            PMS_INPUT_VIEW_StartTask(input->view,33);
            if(r>=12 || !PMS_INPUT_DATA_GetCategoryWordCount(input->data,input->cursorPos)) {
                GFL_USE_PlaySeDefaultVolume(PMS_SE_ERROR);
                return;
            }
            PMS_INPUT_OpenWordList(input);
            *state=2;
            return;
        }
    } else {
        r=PMS_INPUT_HitInitialCell(input);
        if(r>-1) {
            input->cursorPos=r;
            PMSI_SEARCH_PushKey(input->search,input->cursorPos);
            PMSI_SEARCH_Run(input->search);
            PMS_INPUT_VIEW_StartTask(input->view,30);
            GFL_USE_PlaySeDefaultVolume(PMS_SE_OK);
            PMS_INPUT_VIEW_StartTask(input->view,33);
            return;
        }
        switch(PMS_INPUT_HitInitialButtons(input)) {
        case 0:
            input->cursorPos=252;
            if(PMSI_SEARCH_Run(input->search)) {
                PMS_INPUT_OpenWordList(input);
                *state=2;
                return;
            } else {
                GFL_USE_PlaySeDefaultVolume(PMS_SE_ERROR);
                return;
            }
        case 1:
            input->cursorPos=253;
            if(PMSI_SEARCH_PopKey(input->search)) {
                input->savedCursorPos=input->cursorPos;
                *state=1;
                GFL_USE_PlaySeDefaultVolume(PMS_SE_SELECT_INITIAL);
                PMS_INPUT_VIEW_StartTask(input->view,32);
                PMSI_SEARCH_Run(input->search);
                PMS_INPUT_VIEW_StartTask(input->view,30);
                return;
            } else {
                GFL_USE_PlaySeDefaultVolume(PMS_SE_ERROR);
                return;
            }
        case 2:
            input->cursorPos=254;
            GFL_USE_PlaySeDefaultVolume(PMS_SE_CANCEL);
            PMS_INPUT_VIEW_StartTask(input->view,11);
            input->returnHandler=PMS_INPUT_HandleMenu;
            *state=2;
            break;
        case -1:
            break;
        }
    }
}

/* Browse screen: checks the device switch, then runs the key or touch input. */
void PMS_INPUT_HandleBrowseInput(struct PmsInput *input, unsigned int *state) {
    if(PMS_INPUT_CheckUiSwitch(input,state)) {
        if(input->browseMode==0) {
            if(input->uiInputMode==0 && !(KEY_GetTrg()&PMS_KEY_B)) { GFL_USE_PlaySeDefaultVolume(PMS_SE_MOVE); return; }
        } else {
            if(input->uiInputMode==0) { GFL_USE_PlaySeDefaultVolume(PMS_SE_MOVE); return; }
        }
    }
    if(PMS_INPUT_VIEW_IsTaskNotRunning(input->view,30)) {
        if(input->uiInputMode==0) PMS_INPUT_HandleBrowseKeys(input,state);
        else PMS_INPUT_HandleBrowseTouch(input,state);
    }
}

/* Whether the category under the cursor has words. */
int PMS_INPUT_CategoryHasWords(struct PmsInput *input) { if (PMS_INPUT_DATA_GetCategoryWordCount(input->data, input->cursorPos) != 0) return 1; return 0; }

/* Moves the browse cursor by the pressed direction key. */
int PMS_INPUT_MoveCursor(struct PmsInput *input) { return gPmsInputCursorMoveFns[input->browseMode](input); }


extern u8 PMSI_SEARCH_GetKeyUp(u32 i);

extern u8 PMSI_SEARCH_GetKeyDown(u32 i);

extern u8 PMSI_SEARCH_GetKeyLeft(u32 i);

extern int PMSI_SEARCH_GetKeyRight(int n);

extern u8 PMSI_SEARCH_GetKeyKind(u32 i);


extern u32 TOUCHPANEL_GetPointCont(u32 *outA, u32 *outB);

extern unsigned PMS_INPUT_VIEW_GetWordwinItem(struct PmsInputView *view, unsigned maxTopRow);

extern void PMS_INPUT_VIEW_SetWordwinScrollOffset(struct PmsInputView *view, u32 y);

extern int PMS_INPUT_VIEW_CompareWordwinPosition(struct PmsInputView *view, int x, unsigned y);

extern int PMS_INPUT_VIEW_GetMenuResult(struct PmsInputView *view);

extern int PMS_INPUT_VIEW_GetEditEntry(struct PmsInputView *view, int slot);

extern unsigned short PMS_INPUT_DATA_GetCategoryWordId(struct PmsInputData *data, unsigned int category, unsigned int index);

extern u16 PMSI_SEARCH_GetResultWordId(struct PmsInputSearch *search, u32 index);

extern u8 PMSI_SEARCH_HasResults(struct PmsInputSearch *search);

extern void PMS_INPUT_DATA_GetCategoryWordString(struct PmsInputData *data, u32 category, u32 index, int buf);

extern int PMSI_SEARCH_GetResultString(struct PmsInputSearch *search, u8 index, int buf);

extern void PMSI_SEARCH_BuildInputText(struct PmsInputSearch *search, void *arg);

extern void PMSI_SEARCH_ClearInput(struct PmsInputSearch *search);

extern u8 PMSI_SEARCH_GetInputCount(struct PmsInputSearch *search);

extern void PMSI_PARAM_SetWordAt(struct PmsData *sentence, unsigned index, u16 word);

extern void PMSI_PARAM_ClearUnusedWords(struct PmsData *sentence, u16 heapId);

extern void PMSI_PARAM_SetResult(struct PmsiParam *param, const u16 *words, const struct PmsData *sentence);

extern int PMSI_PARAM_IsComplete(struct PmsData *sentence, u16 heapId);

extern u16 PMSI_PARAM_GetWordRaw(const struct PmsData *sentence, u32 index);

extern void *PMSI_PARAM_GetSourceString(const struct PmsData *sentence, u32 heapId);






extern int PMS_INPUT_HitBackButton(void);

extern const u8 gPmsInputCategoryCursorMap[][4];

extern const struct PmsTouchBox gPmsInputWordCellTemplate;

extern const struct PmsTouchRect gPmsInputWordListButtonHits[];

int PMS_INPUT_MoveCategoryCursor(PmsInput *input);

int PMS_INPUT_MoveInitialCursor(PmsInput *input);


u32 PMS_WORDLIST_GetCellOffset(struct PmsWordListCursor *list);

unsigned PMS_WORDLIST_GetSelectedIndex(struct PmsWordListCursor *list);

u32 PMS_WORDLIST_GetScrollDelta(struct PmsWordListCursor *list);

u16 PMS_WORDLIST_GetTopRow(struct PmsWordListCursor *list);

u16 PMS_WORDLIST_GetMaxTopRow(struct PmsWordListCursor *list);


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


void PMS_INPUT_ClearSubHandler(PmsInput *input);





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


/* Moves the category cursor by the repeating direction key. Returns 1 when it moved. */
int PMS_INPUT_MoveCategoryCursor(PmsInput *input) {
    u16 v=input->cursorPos;
    u16 n=v;
    if(v==254) n=12;
    if(v!=254) {
        input->prevCursorPos=v;
        if(input->keyRepeat&PMS_KEY_UP) { input->cursorPos=gPmsInputCategoryCursorMap[n][0]; return 1; }
        if(input->keyRepeat&PMS_KEY_DOWN) { input->cursorPos=gPmsInputCategoryCursorMap[n][1]; return 1; }
        if(input->keyRepeat&PMS_KEY_LEFT) { input->cursorPos=gPmsInputCategoryCursorMap[n][2]; return 1; }
        if(input->keyRepeat&PMS_KEY_RIGHT) { input->cursorPos=gPmsInputCategoryCursorMap[n][3]; return 1; }
    } else {
        input->prevCursorPos=254;
        if(input->keyRepeat&PMS_KEY_UP) { input->cursorPos=11; return 1; }
        if(input->keyRepeat&PMS_KEY_DOWN) { input->cursorPos=2; return 1; }
    }
    return 0;
}

/* Moves the cursor over the initial letter cells and the three side buttons by the direction key. */
int PMS_INPUT_MoveInitialCursor(PmsInput *input) {
    int x=input->cursorPos;
    int y;
    if(x!=254 && x!=252 && x!=253) {
        y=255;
        if(input->keyRepeat&PMS_KEY_UP) y=PMSI_SEARCH_GetKeyUp(x);
        else if(input->keyRepeat&PMS_KEY_DOWN) y=PMSI_SEARCH_GetKeyDown(x);
        else if(input->keyRepeat&PMS_KEY_RIGHT) y=PMSI_SEARCH_GetKeyRight(x);
        else if(input->keyRepeat&PMS_KEY_LEFT) y=PMSI_SEARCH_GetKeyLeft(x);
        if(y!=255) { input->prevCursorPos=input->cursorPos; input->cursorPos=y; return 1; }
    } else if(input->keyRepeat&PMS_KEY_UP) {
        if(input->prevCursorPos<=26) y=PMSI_SEARCH_GetKeyKind(input->prevCursorPos); else y=255;
        if(input->cursorPos==252) {
            if(y>=20 && y<=23) { input->cursorPos=y; goto end64; }
            else { input->cursorPos=22; goto end64; }
        } else if(input->cursorPos==253) {
            if(y==24 || y==25 || y==16) { input->cursorPos=y; goto end64; }
            else { input->cursorPos=25; goto end64; }
        } else {
            if(y==17 || y==18 || y==26) { input->cursorPos=y; goto end64; }
            else { input->cursorPos=26; goto end64; }
        }
end64: return 1;
    } else if(input->keyRepeat&PMS_KEY_DOWN) {
        if(input->prevCursorPos<=26) y=PMSI_SEARCH_GetKeyKind(input->prevCursorPos); else y=255;
        if(input->cursorPos==252) {
            if(y>=0 && y<=3) { input->cursorPos=y; goto end128; }
            else { input->cursorPos=2; goto end128; }
        } else if(input->cursorPos==253) {
            if(y>=4 && y<=6) { input->cursorPos=y; goto end128; }
            else { input->cursorPos=5; goto end128; }
        } else {
            if(y>=7 && y<=9) { input->cursorPos=y; goto end128; }
            else { input->cursorPos=8; goto end128; }
        }
end128: return 1;
    } else if(input->keyRepeat&PMS_KEY_LEFT) {
        switch(x) {
        case 254: input->cursorPos=253; break;
        case 253: input->cursorPos=252; break;
        case 252: input->cursorPos=254; break;
        }
        return 1;
    } else if(input->keyRepeat&PMS_KEY_RIGHT) {
        switch(x) {
        case 254: input->cursorPos=252; break;
        case 253: input->cursorPos=254; break;
        case 252: input->cursorPos=253; break;
        }
        return 1;
    }
    return 0;
}

/* Resets the word list cursor for the list of the current category or initial letter. */
void PMS_INPUT_InitWordList(struct PmsWordListCursor *list, PmsInput *input) {
    list->topRow=0; list->column=0; list->row=0;
    list->itemCount=PMS_INPUT_GetListItemCount(input);
    list->scrollDelta=0;
    list->barFocused=0; list->touchedIndex=65535;
    if (list->itemCount>14) list->maxTopRow=(list->itemCount-14)/2+(list->itemCount&1);
    else list->maxTopRow=0;
}

/* Offset of the cursor cell from the first visible entry. */
u32 PMS_WORDLIST_GetCellOffset(struct PmsWordListCursor *list) { return list->column + list->row * 2; }

/* Index of the entry under the cursor. */
unsigned PMS_WORDLIST_GetSelectedIndex(struct PmsWordListCursor *list) { return list->topRow*2+PMS_WORDLIST_GetCellOffset(list); }

/* Rows the list scrolled in the last move. */
u32 PMS_WORDLIST_GetScrollDelta(struct PmsWordListCursor *list)
{
    return list->scrollDelta;
}

/* First visible row. */
u16 PMS_WORDLIST_GetTopRow(struct PmsWordListCursor *list) { return list->topRow; }

/* Last possible first visible row. */
u16 PMS_WORDLIST_GetMaxTopRow(struct PmsWordListCursor *list) { return list->maxTopRow; }

/* Word list handler: waits for the view effects between moves. */
int PMS_INPUT_HandleWordList(PmsInput *input, unsigned int *state) {
    switch(*state) {
    case 0: PMS_INPUT_HandleWordListInput(input,state); break;
    case 1: if(PMS_INPUT_VIEW_IsTaskNotRunning(input->view,20)) *state=0; break;
    case 2: if(PMS_INPUT_VIEW_IsTaskNotRunning(input->view,20)) { PMS_INPUT_VIEW_StartTask(input->view,19); *state=0; } break;
    case 3: if(PMS_INPUT_VIEW_IsTaskNotRunning(input->view,31)) *state=0; break;
    case 4: if(PMS_INPUT_VIEW_IsIdle(input->view)) { PMS_INPUT_SetHandler(input,input->returnHandler); *state=0; } break;
    }
    return 0;
}

/* Word list, button operation. */
void PMS_INPUT_HandleWordListKeys(PmsInput *input, unsigned int *state) {
    switch(PMS_WORDLIST_MoveByKeys(&input->wordList,input->keyRepeat)) {
    case 1: GFL_USE_PlaySeDefaultVolume(PMS_SE_MOVE); PMS_INPUT_VIEW_StartTask(input->view,19); return;
    case 2: GFL_USE_PlaySeDefaultVolume(PMS_SE_MOVE); PMS_INPUT_VIEW_StartTask(input->view,20); *state=1; return;
    case 3: GFL_USE_PlaySeDefaultVolume(PMS_SE_MOVE); PMS_INPUT_VIEW_StartTask(input->view,20); PMS_INPUT_VIEW_StartTask(input->view,19); *state=2; return;
    }
    if(input->keyTrg&PMS_KEY_B) {
        GFL_USE_PlaySeDefaultVolume(PMS_SE_CANCEL); PMS_INPUT_VIEW_StartTask(input->view,13);
        input->returnHandler=PMS_INPUT_HandleBrowse; *state=4; return;
    } else if(input->keyTrg&PMS_KEY_A) {
        if(input->wordList.barFocused!=0) {
            GFL_USE_PlaySeDefaultVolume(PMS_SE_CANCEL); PMS_INPUT_VIEW_StartTask(input->view,13);
            input->returnHandler=PMS_INPUT_HandleBrowse; *state=4; return;
        } else {
            GFL_USE_PlaySeDefaultVolume(PMS_SE_OK); input->wordList.touchedIndex=65535;
            PMS_INPUT_PickWord(input);
            PMS_INPUT_VIEW_StartTask(input->view,34); PMS_INPUT_VIEW_StartTask(input->view,14);
            input->returnHandler=PMS_INPUT_HandleMenu; *state=4;
        }
    }
}

/* Touch hit test of the scroll bar and the word cells. Returns a list result. */
int PMS_INPUT_HitWordList(PmsInput *input)
{
    u32 x, y;
    struct PmsTouchBox box = gPmsInputWordCellTemplate;
    int outer, inner, stop;
    u16 index;
    if (TOUCHPANEL_HitTrg(gPmsInputWordListButtonHits) == 0) {
        TOUCHPANEL_GetPointTrg(&x, &y);
        switch (PMS_INPUT_VIEW_CompareWordwinPosition(input->view, x, y)) {
        case 0:
            input->scrollBarGrabbed = 1;
            GFL_USE_PlaySeDefaultVolume(PMS_SE_MOVE);
            return 0;
        case 1:
            input->scrollBarGrabbed = 1;
            PMS_INPUT_VIEW_SetWordwinScrollOffset(input->view, y);
            return PMS_WORDLIST_JumpUp(input->view, &input->wordList);
        case 2:
            input->scrollBarGrabbed = 1;
            PMS_INPUT_VIEW_SetWordwinScrollOffset(input->view, y);
            return PMS_WORDLIST_JumpDown(input->view, &input->wordList);
        case 3:
            break;
        }
    }
    TOUCHPANEL_GetPointTrg(&x, &y);
    index = input->wordList.topRow * 2;
    stop = 0;
    for (outer = 0; outer < 6; outer++) {
        box.rect.top = 24 * outer + 13;
        box.rect.bottom = box.rect.top + 22;
        for (inner = 0; inner < 2; inner++) {
            box.rect.left = 112 * inner + 16;
            box.rect.right = box.rect.left + 102;
            if (TOUCHPANEL_HitPoint(&box, x, y) != (u32)-1) {
                input->wordList.touchedIndex = index;
                input->wordList.column = inner;
                input->wordList.row = outer;
                return 5;
            }
            index++;
            if (index >= input->wordList.itemCount - 2) {
                stop = 1;
                break;
            }
        }
        if (stop) break;
    }
    return 0;
}

/* Continues a scroll bar drag. Returns 1 while the drag goes on. */
int PMS_INPUT_HitScrollBarDrag(PmsInput *input) {
 unsigned x,y;
 if(TOUCHPANEL_GetPointCont(&x,&y)==1 && input->scrollBarGrabbed==1) { PMS_INPUT_VIEW_SetWordwinScrollOffset(input->view,y); return 1; }
 input->scrollBarGrabbed=0;
 return 0;
}

/* Word list, touch operation. */
void PMS_INPUT_HandleWordListTouch(PmsInput *input, unsigned int *state)
{
    if (!PMS_INPUT_HitBackButton()) {
        GFL_USE_PlaySeDefaultVolume(PMS_SE_CANCEL);
        PMS_INPUT_VIEW_StartTask(input->view, 13);
        input->returnHandler = PMS_INPUT_HandleBrowse;
        *state = 4;
        return;
    }
    if (PMS_INPUT_HitScrollBarDrag(input) == 1) {
        switch (PMS_WORDLIST_DragTo(input->view, &input->wordList)) {
        case 2:
            PMS_INPUT_VIEW_StartTask(input->view, 31);
            *state = 3;
            break;
        case 3:
            PMS_INPUT_VIEW_StartTask(input->view, 31);
            PMS_INPUT_VIEW_StartTask(input->view, 19);
            *state = 3;
            break;
        }
        return;
    }
    switch (PMS_INPUT_HitWordList(input)) {
    case 0: break;
    case 5:
        GFL_USE_PlaySeDefaultVolume(PMS_SE_OK);
        PMS_INPUT_PickWord(input);
        input->returnHandler = PMS_INPUT_HandleMenu;
        PMS_INPUT_VIEW_StartTask(input->view, 34);
        PMS_INPUT_VIEW_StartTask(input->view, 14);
        *state = 4;
        break;
    case 1:
        GFL_USE_PlaySeDefaultVolume(PMS_SE_MOVE);
        PMS_INPUT_VIEW_StartTask(input->view, 19);
        break;
    case 2:
        GFL_USE_PlaySeDefaultVolume(PMS_SE_MOVE);
        PMS_INPUT_VIEW_StartTask(input->view, 31);
        *state = 3;
        break;
    case 3:
        GFL_USE_PlaySeDefaultVolume(PMS_SE_MOVE);
        PMS_INPUT_VIEW_StartTask(input->view, 20);
        PMS_INPUT_VIEW_StartTask(input->view, 19);
        *state = 2;
        break;
    case 4: break;
    }
}

/* Word list: checks the device switch, then runs the key or touch input. */
void PMS_INPUT_HandleWordListInput(PmsInput *input, unsigned int *state) {
    if(PMS_INPUT_CheckUiSwitch(input,state) && input->uiInputMode==0 && !(KEY_GetTrg()&PMS_KEY_B)) { GFL_USE_PlaySeDefaultVolume(PMS_SE_MOVE); return; }
    if(input->uiInputMode==0) PMS_INPUT_HandleWordListKeys(input,state);
    else PMS_INPUT_HandleWordListTouch(input,state);
}

/* Moves the list cursor by the pressed keys. Returns a list result. */
int PMS_WORDLIST_MoveByKeys(struct PmsWordListCursor *list, u32 keys)
{
    u32 r;
    if (keys & PMS_KEY_DOWN) {
        if (list->barFocused != 0)
            return 4;
        if (list->row < 5) {
            list->row++;
            r = PMS_WORDLIST_GetSelectedIndex(list);
            if (r < (u32)list->itemCount - 2)
                return 1;
            if (r == (u32)list->itemCount - 2) {
                if (r & 1) {
                    list->column = 0;
                    return 1;
                }
                list->row--;
                return 4;
            }
            list->row--;
            return 4;
        }
        if (list->topRow < list->maxTopRow) {
            list->scrollDelta = 1;
            list->topRow = list->topRow + 1;
            r = PMS_WORDLIST_GetSelectedIndex(list);
            if (r < (u32)list->itemCount - 2)
                return 2;
            list->column = 0;
            return 3;
        }
        return 4;
    }
    if (keys & PMS_KEY_UP) {
        if (list->barFocused != 0) {
            list->barFocused = 0;
            return 1;
        }
        if (list->row != 0) {
            list->row--;
            return 1;
        }
        if (list->topRow != 0) {
            list->scrollDelta = -1;
            list->topRow = list->topRow - 1;
            return 2;
        }
        return 4;
    }
    if (keys & PMS_KEY_LEFT) {
        if (list->column == 1) {
            list->column ^= 1;
            r = PMS_WORDLIST_GetSelectedIndex(list);
            if (r < (u32)list->itemCount - 2)
                return 1;
            list->column ^= 1;
        }
        return 4;
    }
    if (keys & PMS_KEY_RIGHT) {
        if (list->column == 0) {
            list->column ^= 1;
            r = PMS_WORDLIST_GetSelectedIndex(list);
            if (r < (u32)list->itemCount - 2)
                return 1;
            list->column ^= 1;
        }
        return 4;
    }
    if (keys & PMS_KEY_L)
        return PMS_WORDLIST_PageUp(list);
    if (keys & PMS_KEY_R)
        return PMS_WORDLIST_PageDown(list);
    return 0;
}

/* Scrolls the list up by one page. */
int PMS_WORDLIST_PageUp(struct PmsWordListCursor *list) {
 if(list->topRow!=0) {
  if(list->topRow>=6) { list->topRow-=6; list->scrollDelta=-6; }
  else { list->scrollDelta=-list->topRow; list->topRow=0; }
  return 2;
 }
 return 4;
}

/* Scrolls the list down by one page. */
u32 PMS_WORDLIST_PageDown(struct PmsWordListCursor *list) {
    if (list->topRow<list->maxTopRow) {
        if (list->topRow+6<=list->maxTopRow) { list->scrollDelta=6; list->topRow+=6; }
        else { list->scrollDelta=list->maxTopRow-list->topRow; list->topRow=list->maxTopRow; }
        if((int)PMS_WORDLIST_GetSelectedIndex(list)<list->itemCount-2) return 2;
        list->column=0; return 3;
    }
    return 4;
}

/* Jumps to the scroll bar position above the thumb. */
int PMS_WORDLIST_JumpUp(struct PmsInputView *view,struct PmsWordListCursor *list) {
 if(list->topRow!=0) {
  list->topRow=PMS_INPUT_VIEW_GetWordwinItem(view,list->maxTopRow);
  list->scrollDelta=0;
  if((int)PMS_WORDLIST_GetSelectedIndex(list)<list->itemCount-2) return 2;
  list->column=0; return 3;
 }
 return 4;
}

/* Jumps to the scroll bar position below the thumb. */
int PMS_WORDLIST_JumpDown(struct PmsInputView *view,struct PmsWordListCursor *list) {
 if(list->topRow<list->maxTopRow) {
  list->topRow=PMS_INPUT_VIEW_GetWordwinItem(view,list->maxTopRow);
  list->scrollDelta=0;
  if((int)PMS_WORDLIST_GetSelectedIndex(list)<list->itemCount-2) return 2;
  list->column=0; return 3;
 }
 return 4;
}

/* Moves the list to the scroll bar thumb position. */
int PMS_WORDLIST_DragTo(struct PmsInputView *view,struct PmsWordListCursor *list) {
 u16 n=list->topRow;
 list->topRow=PMS_INPUT_VIEW_GetWordwinItem(view,list->maxTopRow);
 list->scrollDelta=0;
 if(n!=list->topRow) GFL_USE_PlaySeDefaultVolume(PMS_SE_MOVE);
 if((int)PMS_WORDLIST_GetSelectedIndex(list)<list->itemCount-2) return 2;
 list->column=0; return 3;
}

/* Stores the picked word in the result. Returns whether the input is complete. */
int PMS_INPUT_PickWord(PmsInput *input)
{
    int index = input->wordList.touchedIndex;
    u16 word;
    if (index == 65535) index = PMS_WORDLIST_GetSelectedIndex(&input->wordList);
    if (input->browseMode == 0) word = PMS_INPUT_DATA_GetCategoryWordId(input->data, input->cursorPos, index);
    else word = PMSI_SEARCH_GetResultWordId(input->search, index);
    switch (input->inputMode) {
    case 0: input->words[0] = word; break;
    case 1: input->words[input->wordSlot] = word; break;
    case 2: PMSI_PARAM_SetWordAt(&input->sentence, PMS_INPUT_VIEW_GetEditEntry(input->view, input->wordSlot), word); break;
    }
    return PMS_INPUT_IsComplete(input);
}

/* Closes the view and ends the process handler when it is done. */
int PMS_INPUT_HandleFinish(PmsInput *input, unsigned int *state) {
 switch(*state) {
 case 0: PMS_INPUT_VIEW_StartTask(input->view,1); ++*state; break;
 case 1: if(PMS_INPUT_VIEW_IsIdle(input->view)!=0) return 1; break;
 }
 return 0;
}

/* Starts a sub handler. */
void PMS_INPUT_SetSubHandler(PmsInput *input, PmsInputSubHandler subHandler) { input->subHandler = subHandler; input->subState = 0; }

/* Ends the sub handler. */
void PMS_INPUT_ClearSubHandler(PmsInput *input) { input->subHandler = 0; }

/* Sub handler that plays the opening view effect. */
void PMS_INPUT_SubHandleOpen(PmsInput *input, unsigned int *state) {
 switch(*state) {
 case 0: PMS_INPUT_VIEW_StartTask(input->view,2); ++*state; break;
 case 1: if(PMS_INPUT_VIEW_IsIdle(input->view)!=0) PMS_INPUT_ClearSubHandler(input); break;
 }
}

/* Sub handler for the confirm button. */
void PMS_INPUT_SubHandleConfirm(PmsInput *input, unsigned int *state)
{
    switch (*state) {
    case 0:
        if (PMS_INPUT_VIEW_IsIdle(input->view)) {
            if (PMS_INPUT_IsComplete(input)) {
                PMS_INPUT_SetExitState(&input->exitState, 1, 0);
                input->cancelSelected = 0;
                PMS_INPUT_VIEW_StartTask(input->view, 21);
                *state = 1;
            } else *state = 3;
        }
        break;
    case 1:
        switch (PMS_INPUT_VIEW_GetMenuResult(input->view)) {
        case 0:
            PMS_INPUT_VIEW_StartTask(input->view, 23);
            *state = 3;
            break;
        case 1:
            if (input->inputMode == 2) PMSI_PARAM_ClearUnusedWords(&input->sentence, 42);
            PMSI_PARAM_SetResult(input->param, input->words, &input->sentence);
            PMS_INPUT_SetHandler(input, PMS_INPUT_HandleFinish);
            *state = 3;
            break;
        }
        break;
    case 2:
        if (input->keyTrg & (PMS_KEY_A|PMS_KEY_B|PMS_KEY_RIGHT|PMS_KEY_LEFT|PMS_KEY_UP|PMS_KEY_DOWN)) *state = 3;
        break;
    case 3:
        if (PMS_INPUT_VIEW_IsIdle(input->view)) PMS_INPUT_ClearSubHandler(input);
        break;
    }
}

/* Sub handler for the cancel button. */
void PMS_INPUT_SubHandleCancel(PmsInput *input, unsigned int *state) {
    switch(*state) {
    case 0: PMS_INPUT_SetExitState(&input->exitState, 1, 1); input->cancelSelected=1; PMS_INPUT_VIEW_StartTask(input->view,21); *state=1; break;
    case 1:
        switch(PMS_INPUT_VIEW_GetMenuResult(input->view)) {
        case 0: PMS_INPUT_VIEW_StartTask(input->view,23); *state=2; break;
        case 1: PMS_INPUT_SetHandler(input, PMS_INPUT_HandleFinish); *state=2; break;
        }
        break;
    case 2: if(PMS_INPUT_VIEW_IsIdle(input->view)) PMS_INPUT_ClearSubHandler(input); break;
    }
}

/* Whether all words of the input are set. */
int PMS_INPUT_IsComplete(PmsInput *input) {
    switch(input->inputMode) {
    case 0: if(input->words[0]!=65535) return 1; else return 0;
    case 1: if(input->words[0]!=65535 && input->words[1]!=65535) return 1; else return 0;
    case 2: return PMSI_PARAM_IsComplete(&input->sentence, 42);
    }
    return 0;
}

/* Sets the exit state flags. */
void PMS_INPUT_SetExitState(struct PmsExitState *exitState, u8 requested, u8 cancelled) { exitState->cancelled = cancelled; exitState->requested = requested; }

/* Address of the input device flag. */
unsigned int *PMS_INPUT_GetUiInputModePtr(PmsInput *input) { return &input->uiInputMode; }

/* Input mode: one word, two words or a sentence. */
u32 PMS_INPUT_GetInputMode(PmsInput *input) { return input->inputMode; }

/* Browse mode: categories or initial letters. */
u8 PMS_INPUT_GetBrowseMode(PmsInput *input) { return input->browseMode; }

/* Sentence type of the current sentence. */
int PMS_INPUT_GetSentenceType(PmsInput *input) { return PMSI_PARAM_GetSentenceType(&input->sentence); }

/* Word number of one word slot. */
u32 PMS_INPUT_GetWord(PmsInput *input,u32 i) {
    if(input->inputMode==2) return PMSI_PARAM_GetWordRaw(&input->sentence, i);
    return input->words[i];
}

/* Builds the string of the current sentence. */
void *PMS_INPUT_GetSentenceString(PmsInput *input, u32 heapId) { return PMSI_PARAM_GetSourceString(&input->sentence, heapId); }

/* Word slot being edited. */
u16 PMS_INPUT_GetWordSlot(PmsInput *input) { return input->wordSlot; }

/* Whether the cancel button is selected. */
u16 PMS_INPUT_GetCancelSelected(PmsInput *input) { return input->cancelSelected; }

/* Cursor position on the browse screen. */
u16 PMS_INPUT_GetCursorPos(PmsInput *input) { return input->cursorPos; }

/* Saved cursor position of the browse screen. */
u16 PMS_INPUT_GetSavedCursorPos(PmsInput *input) { return input->savedCursorPos; }

/* Number of cells of the word list, with the two cells before the first word. */
u32 PMS_INPUT_GetListItemCount(PmsInput *input) {
    if(input->browseMode==0) return PMS_INPUT_DATA_GetCategoryWordCount(input->data,input->cursorPos)+2;
    else return PMSI_SEARCH_HasResults(input->search)+2;
}

/* Writes the text of one list word to a buffer. */
void PMS_INPUT_GetListWord(PmsInput *input,u32 a,int b) {
    if(input->browseMode==0) PMS_INPUT_DATA_GetCategoryWordString(input->data,input->cursorPos,a,b);
    else PMSI_SEARCH_GetResultString(input->search,a,b);
}

/* Cell under the list cursor, or -1 when the cursor is on the bar. */
u32 PMS_INPUT_GetCursorCell(PmsInput *input) {
    if(input->wordList.barFocused!=0) return -1;
    return PMS_WORDLIST_GetCellOffset(&input->wordList);
}

/* Rows the list scrolled in the last move. */
int PMS_INPUT_GetScrollDelta(PmsInput *input) { return PMS_WORDLIST_GetScrollDelta(&input->wordList); }

/* First visible row of the list. */
unsigned PMS_INPUT_GetTopRow(PmsInput *input) { return PMS_WORDLIST_GetTopRow(&input->wordList); }

/* Last possible first visible row of the list. */
unsigned PMS_INPUT_GetMaxTopRow(PmsInput *input) { return PMS_WORDLIST_GetMaxTopRow(&input->wordList); }

/* Whether the caller passed a sentence to start from. */
u32 PMS_INPUT_HasInitialSentence(PmsInput *input) { return PMSI_PARAM_HasInitialSentence(input->param); }

/* Task list of the screen. */
struct TcbSystem *PMS_INPUT_GetTasks(PmsInput *input) { return input->tasks; }

/* Passes a value to the initial letter search. */
void PMS_INPUT_SetSearchArg(PmsInput *input, void *arg) { PMSI_SEARCH_BuildInputText(input->search, arg); }

/* Resets the initial letter search. */
void PMS_INPUT_ResetSearch(PmsInput *input) { PMSI_SEARCH_ClearInput(input->search); }

/* Reads the first visible row and the last possible one. */
void PMS_INPUT_GetScrollRange(const PmsInput *input, u16 *topRow, u16 *maxTopRow) {
    *topRow=input->wordList.topRow;
    *maxTopRow=input->wordList.maxTopRow;
}

/* Number of words of the selected initial letter. */
u8 PMS_INPUT_GetInitialCount(PmsInput *input) { return PMSI_SEARCH_HasResults(input->search); }

/* State of the initial letter search. */
int PMS_INPUT_GetSearchState(PmsInput *input) { return PMSI_SEARCH_GetInputCount(input->search); }

/* Writes the text of one word of the selected initial letter to a buffer. */
void PMS_INPUT_GetInitialWord(PmsInput *input,u32 a,int b) { PMSI_SEARCH_GetResultString(input->search,a,b); }

/* Whether the input can be confirmed. */
int PMS_INPUT_CanConfirm(PmsInput *input) { return PMS_INPUT_IsComplete(input); }

/* Puts the browse cursor back to the first cell. */
void PMS_INPUT_ResetCursor(PmsInput *input) {
    input->cursorPos=0;
    input->prevCursorPos=255;
    input->savedCursorPos=253;
}

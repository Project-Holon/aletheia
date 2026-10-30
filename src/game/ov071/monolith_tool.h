#ifndef GAME_OV071_MONOLITH_TOOL_H
#define GAME_OV071_MONOLITH_TOOL_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of monolith_tool.c, prototypes copied from their definitions. */

struct Proc;
struct Actor;
struct TaskMenuRes;

#include "../ov071/monolith_tool_types.h"
#include "../types.h"

struct TcbTask;

int MONOLITH_TOOL_Init(struct Proc *ctx, int unused, MonolithToolSetup *setup);
int MONOLITH_TOOL_Main(int a, int *seq, void **pwk, MonolithToolWork *work);
int MONOLITH_TOOL_Exit(struct Proc *a, int b, int c, MonolithToolWork *work);
void MONOLITH_TOOL_InitDisplay(void);
void MONOLITH_TOOL_DeleteBg(void);
void MONOLITH_TOOL_InitBmpWin(void);
void MONOLITH_TOOL_ExitBmpWin(void);
unsigned int MONOLITH_TOOL_InitPalAnm(MonolithToolWork *work);
void MONOLITH_TOOL_FreePalAnm(MonolithToolWork *work);
void MONOLITH_TOOL_InitBackgrounds(void);
void MONOLITH_TOOL_FreeBackgrounds(void);
void MONOLITH_TOOL_LoadGraphics(MonolithToolWork *work, MonolithToolWork *work2);
void MONOLITH_TOOL_FreeSubBgChar(MonolithToolWork *work);
void MONOLITH_TOOL_InitText(MonolithToolWork *work);
void MONOLITH_TOOL_FreeText(MonolithToolWork *work);
void MONOLITH_TOOL_InitActors(MonolithToolWork *work);
void MONOLITH_TOOL_FreeActors(MonolithToolWork *work);
void MONOLITH_TOOL_LoadActorResources(MonolithToolWork *work);
void MONOLITH_TOOL_FreeActorResources(MonolithToolWork *work);
void MONOLITH_TOOL_VBlankTask(struct TcbTask *unused, void *workArg);
void MONOLITH_TOOL_LoadSlotRecords(MonolithToolWork *work, MonolithToolSetup *setup);
void MONOLITH_TOOL_CreateButton(MonolithToolWork *work, MonolithToolButton *button, int resIndex, int sizeClass, int x, int y, int msgId, void *wordSet);
void MONOLITH_TOOL_FreeButton(MonolithToolButton *button);
void MONOLITH_TOOL_SetButtonVisible(MonolithToolButton *button, int visible);
int MONOLITH_TOOL_IsButtonUploaded(MonolithToolWork *work, MonolithToolButton *button);
void MONOLITH_TOOL_HighlightButtonPulse(MonolithToolProcArgs *args, MonolithToolButton *button, int count, int selected, int slot);
void MONOLITH_TOOL_HighlightButtonFlash(MonolithToolProcArgs *args, MonolithToolButton *button, int count, int selected, int slot);
void MONOLITH_TOOL_SetButtonPulse(MonolithToolProcArgs *args, int pulse, int slot);
void MONOLITH_TOOL_SetButtonFlash(MonolithToolProcArgs *args, int slot);
void MONOLITH_TOOL_ResetHighlights(MonolithToolProcArgs *args);
u8 MONOLITH_TOOL_GetHighlightMode(MonolithToolProcArgs *args, int slot);
void MONOLITH_TOOL_UpdateHighlight(MonolithToolProcArgs *args, int slot);
void MONOLITH_TOOL_SetHighlightMode(MonolithToolProcArgs *args, int mode, int slot);
int MONOLITH_TOOL_GetHighlightColorA(unsigned int x);
int MONOLITH_TOOL_GetHighlightColorB(unsigned int x);
int MONOLITH_TOOL_GetHighlightColorCount(int slot);
void MONOLITH_TOOL_CreateLabel(MonolithToolWork *work, MonolithToolLabel *label, int resIndex, int x, int y, int widthTiles, int heightTiles, int msgId, void *wordSet);
void MONOLITH_TOOL_FreeLabel(MonolithToolLabel *label);
int MONOLITH_TOOL_UpdateLabel(MonolithToolWork *work, MonolithToolLabel *label);
void *MONOLITH_TOOL_GetTitleSpecies(MonolithToolProcArgs *args);
MonolithCounts *MONOLITH_TOOL_GetSlotIconStates(MonolithToolProcArgs *args);
int MONOLITH_TOOL_CreateSlotIcon(MonolithToolWork *work, MonolithCounts *counts, int slot, const int *pos, int resIndex);
void MONOLITH_TOOL_DeleteSlotIcon(void *p);
void MONOLITH_TOOL_UpdateSlotIconState(void *p, MonolithCounts *counts, int i);
struct ClactActor *MONOLITH_TOOL_CreateCursor(MonolithToolWork *work, const int *pos, int resIndex);
void MONOLITH_TOOL_DeleteCursor(void *p);
void MONOLITH_TOOL_CreateBlink(MonolithToolWork *work, MonolithToolBlink *blink);
void MONOLITH_TOOL_DeleteBlink(MonolithToolBlink *blink);
void MONOLITH_TOOL_UpdateBlink(MonolithToolBlink *p);
void MONOLITH_TOOL_StartBlink(MonolithToolBlink *blink);
int MONOLITH_TOOL_IsBlinkActive(MonolithToolBlink *blink);
struct Actor *MONOLITH_TOOL_CreateActorAt(MonolithToolWork *work, int x, int y, int animSeq);
void MONOLITH_TOOL_DeleteActorAt(void *p);
void MONOLITH_TOOL_Noop(void *a);
struct TaskMenuRes *MONOLITH_TOOL_CreateTaskMenuRes(MonolithToolWork *p, int a, u16 heap);
void MONOLITH_TOOL_DeleteTaskMenuRes(void *p);
void *MONOLITH_TOOL_OpenTaskMenu(MonolithToolWork *work, void *res, u32 heap);
void MONOLITH_TOOL_CloseTaskMenu(void *menu);
int MONOLITH_TOOL_UpdateTaskMenu(MonolithToolWork *work, int unused, void *menu, int *outConfirmed);
void MONOLITH_TOOL_DrawSlotCounts(void *a, int flag, int bg);
/* END mkheaders: generated region */

#endif

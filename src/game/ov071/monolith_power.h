#ifndef GAME_OV071_MONOLITH_POWER_H
#define GAME_OV071_MONOLITH_POWER_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of monolith_power.c, prototypes copied from their definitions. */

struct Proc;
struct Actor;
struct TaskMenuRes;

#include "../ov071/monolith_tool_types.h"
#include "../types.h"

struct TcbTask;

int MONOLITH_TOOL_LIST_Init(struct Proc *proc, int *state, MonolithToolProcArgs *args, MonolithListWork *work);
int MONOLITH_TOOL_LIST_Main(int unused, int *state, MonolithToolProcArgs *args, MonolithListWork *work);
int MONOLITH_TOOL_LIST_Exit(void *proc, void *unused, MonolithToolProcArgs *args, MonolithListWork *work);
void MONOLITH_TOOL_LIST_InitBackgrounds(void);
void MONOLITH_TOOL_LIST_FreeBackgrounds(void);
void MONOLITH_TOOL_LIST_LoadGraphics(MonolithListWork *work, MonolithToolWork *toolWork);
void MONOLITH_TOOL_LIST_FreeBgChar(MonolithListWork *work);
void MONOLITH_TOOL_LIST_InitWindows(MonolithListWork *work, MonolithToolWork *toolWork);
void MONOLITH_TOOL_LIST_FreeWindows(MonolithListWork *work);
void MONOLITH_TOOL_LIST_DrawTitle(MonolithToolProcArgs *args, MonolithListWork *work);
void MONOLITH_TOOL_LIST_ShowMessage(MonolithListWork *work, MonolithToolWork *toolWork, u32 msgId);
void MONOLITH_TOOL_LIST_ShowFormattedMessage(MonolithListWork *work, MonolithToolWork *toolWork, u32 msgId);
int MONOLITH_TOOL_LIST_IsMessageDone(MonolithToolWork *toolWork, MonolithListWork *work);
void MONOLITH_TOOL_LIST_HideMessage(MonolithListWork *work);
void MONOLITH_TOOL_LIST_FitBackground(MonolithListWork *work);
void MONOLITH_TOOL_LIST_BuildEntryList(MonolithToolProcArgs *args, MonolithListWork *work, MonolithToolWork *toolWork);
void MONOLITH_TOOL_LIST_FreeEntryBitmaps(MonolithListWork *work);
int MONOLITH_TOOL_LIST_DrawEntryNames(MonolithListWork *work, MonolithToolWork *toolWork);
void MONOLITH_TOOL_CreateRowGrids(MonolithListWork *work, MonolithToolWork *toolWork);
void MONOLITH_TOOL_DeleteRowGrids(MonolithListWork *work);
void MONOLITH_TOOL_CreateBackButton(MonolithToolProcArgs *args, MonolithListWork *work);
void MONOLITH_TOOL_LIST_FreeBackButton(MonolithListWork *work);
void MONOLITH_TOOL_LIST_UpdateBackButton(MonolithToolWork *toolWork, MonolithListWork *work);
void MONOLITH_TOOL_CreateMarker(MonolithToolProcArgs *args, MonolithListWork *work);
void MONOLITH_TOOL_DeleteMarker(MonolithListWork *work);
void MONOLITH_TOOL_UpdateMarker(MonolithListWork *work);
void MONOLITH_TOOL_CreateScrollArrows(MonolithToolProcArgs *args, MonolithListWork *work);
void MONOLITH_TOOL_DeleteScrollArrows(MonolithListWork *work);
void MONOLITH_TOOL_UpdateScrollArrows(MonolithListWork *work);
int MONOLITH_TOOL_ProcessListInput(MonolithToolProcArgs *args, MonolithListWork *work);
int MONOLITH_TOOL_SetCursor(MonolithListWork *work, int index, int inputMode);
void MONOLITH_TOOL_SetRowHighlight(MonolithListWork *work, int index, int palette);
void MONOLITH_TOOL_SetRowHighlightSelected(MonolithListWork *work, int index);
void MONOLITH_TOOL_SetRowHighlightNormal(MonolithListWork *work, int index);
void MONOLITH_TOOL_ClearPrevHighlight(MonolithListWork *work);
void MONOLITH_TOOL_ApplyCursorChange(MonolithToolProcArgs *args, MonolithListWork *work);
int MONOLITH_TOOL_ScrollBy(MonolithListWork *work, int delta);
void MONOLITH_TOOL_UpdateBgScroll(MonolithListWork *work);
void MONOLITH_TOOL_UpdateRows(MonolithListWork *work);
void MONOLITH_TOOL_TaskUploadRows(struct TcbTask *task, void *workArg);
int MONOLITH_TOOL_GetRowAtY(MonolithListWork *work, unsigned y);
int MONOLITH_TOOL_InitInfoScreen(struct Proc *proc, int *state, MonolithToolProcArgs *args, MonolithInfoWork *work);
int MONOLITH_TOOL_MainInfoScreen(struct Proc *proc, int *state, MonolithToolProcArgs *args, MonolithInfoWork *work);
int MONOLITH_TOOL_ExitInfoScreen(struct Proc *proc, int *state, MonolithToolProcArgs *args, MonolithInfoWork *work);
void MONOLITH_TOOL_SetupInfoBgs(void);
void MONOLITH_TOOL_HideInfoBgs(void);
void MONOLITH_TOOL_LoadInfoPalette(MonolithToolWork *toolWork);
void MONOLITH_TOOL_CreateInfoWindows(MonolithToolWork *toolWork, MonolithInfoWork *work);
void MONOLITH_TOOL_DeleteInfoWindows(MonolithInfoWork *work);
void MONOLITH_TOOL_DrawInfoHeader(MonolithToolWork *toolWork, MonolithInfoWork *work);
void MONOLITH_TOOL_DrawActiveEntry(MonolithToolProcArgs *args, MonolithToolWork *toolWork, MonolithInfoWork *work);
void MONOLITH_TOOL_DrawSelectedEntry(MonolithToolProcArgs *args, MonolithToolWork *toolWork, MonolithInfoWork *work);
/* END mkheaders: generated region */

#endif

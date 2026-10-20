#ifndef GAME_OV094_BTLV_INPUT_H
#define GAME_OV094_BTLV_INPUT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of btlv_input.c, prototypes copied from their definitions. */

struct TcbTask;
struct StrObj;
struct Slots;
struct BtlvInputPartyInfo;
struct BtlvInputSection;
typedef struct Slots Slots;
typedef struct BtlvInputPartyInfo BtlvInputPartyInfo;
typedef struct BtlvInputSection BtlvInputSection;

#include "../ov094/btlv_input_shared_types.h"
#include "../types.h"

BtlvInput *BTLV_INPUT_CreateDefault(int infoWinParam, int battleType, int palAnm, int font, int cursorVisible, u16 heap);
BtlvInput *BTLV_INPUT_CreateWithMode(int infoWinParam, int battleType, int seMode, int palAnm, int font, int cursorVisible, int visibilityMode, u16 heap);
BtlvInput *BTLV_INPUT_Create(int infoWinParam, int battleType, int seMode, int palAnm, int font, int cursorVisible, int visibilityMode, int infoWinEnabled, u16 heap);
void BTLV_INPUT_Delete(BtlvInput *input);
void BTLV_INPUT_UpdateInfoWindow(BtlvInput *input);
void BTLV_INPUT_InfoWindowTask(struct TcbTask *unused, void *arg);
void BTLV_INPUT_LoadScreenResources(BtlvInput *input);
void BTLV_INPUT_ReleaseScreenResources(BtlvInput *input);
void BTLV_INPUT_InitBgLayers(BtlvInput *input);
void BTLV_INPUT_ReleaseBgLayers(void);
void BTLV_INPUT_StartPaletteFadeTask(BtlvInput *input, int flag);
void BTLV_INPUT_StartScreenFadeTask(BtlvInput *input);
int BTLV_INPUT_IsScreenBusy(BtlvInput *input);
void BTLV_INPUT_ChangeScreen(BtlvInput *input, int mode, void *arg);
int BTLV_INPUT_ProcessTouchInput(BtlvInput *input, BtlvInputTouchTable *table, int neighbours);
int BTLV_INPUT_StepFingerDemo(BtlvInput *input);
int BTLV_INPUT_ProcessKeyInput(BtlvInput *input, u8 *key, int *out);
int BTLV_INPUT_IsInputBlocked(BtlvInput *input);
int BTLV_INPUT_GetScreen(BtlvInput *input);
void BTLV_INPUT_LoadCommonGraphics(BtlvInput *input);
void BTLV_INPUT_ActionScreenOpenTask(struct TcbTask *task, void *arg);
void BTLV_INPUT_WazaScreenOpenTask(struct TcbTask *task, void *arg);
void BTLV_INPUT_WazaScreenOpenInstantTask(struct TcbTask *task, void *arg);
void BTLV_INPUT_ActionScreenOpenInstantTask(struct TcbTask *task, void *arg);
void BTLV_INPUT_TargetScreenOpenTask(struct TcbTask *task, void *arg);
void BTLV_INPUT_WazaScreenCloseTask(struct TcbTask *task, void *arg);
void BTLV_INPUT_WaitScreenOpenTask(struct TcbTask *task, void *arg);
void BTLV_INPUT_WaitScreenOpenInstantTask(struct TcbTask *task, void *arg);
void BTLV_INPUT_MessageScreenOpenTask(struct TcbTask *task, void *arg);
void BTLV_INPUT_ListScreenOpenTask(struct TcbTask *task, void *arg);
void BTLV_INPUT_SelectScreenOpenTask(struct TcbTask *task, void *arg);
void BTLV_INPUT_ConfirmScreenOpenTask(struct TcbTask *task, void *arg);
void BTLV_INPUT_ListScreenOpenInstantTask(struct TcbTask *task, void *arg);
void BTLV_INPUT_ScreenResetTask(struct TcbTask *task, void *arg);
void BTLV_INPUT_TaskEndClearBusyBit(void *task);
void BTLV_INPUT_StartBgScrollTask(BtlvInput *input, int startScale, int goalScale, int step, int scrollY);
void BTLV_INPUT_BgScrollTaskMain(struct TcbTask *task, void *arg);
void BTLV_INPUT_BgScrollTaskEnd(void *task);
void BTLV_INPUT_StartBgWipeTask(BtlvInput *input, int x, int y, int dy, int count);
void BTLV_INPUT_BgWipeTaskMain(struct TcbTask *task, void *arg);
void BTLV_INPUT_BgWipeTaskEnd(void *task);
void BTLV_INPUT_StartPaletteCycleTask(BtlvInput *input, int unused, int palSet);
void BTLV_INPUT_PaletteCycleTaskMain(struct TcbTask *task, void *arg);
void BTLV_INPUT_PaletteCycleTaskEnd(void *task);
void BTLV_INPUT_CreateCursorActors(BtlvInput *input, int rowIndex, int animIndex);
void BTLV_INPUT_CursorActorTaskMain(struct TcbTask *task, void *arg);
void BTLV_INPUT_CursorActorTaskEnd(void *task);
void BTLV_INPUT_StartPaletteFlashTask(BtlvInput *input, int kind);
void BTLV_INPUT_PaletteFlashTaskMain(struct TcbTask *task, void *arg);
void BTLV_INPUT_PaletteFlashTaskEnd(void *task);
void BTLV_INPUT_StartBgScrollOffsetTask(BtlvInput *input, int bg, int scrollX, int scrollY, int bg4, int bg5, int bg6, int bg7);
void BTLV_INPUT_BgScrollOffsetTaskMain(struct TcbTask *task, void *arg);
void BTLV_INPUT_WaitFadeTaskMain(struct TcbTask *task, void *arg);
void BTLV_INPUT_WaitFadeTaskEnd(void *task);
void BTLV_INPUT_CursorMoveTaskMain(struct TcbTask *task, void *arg);
void BTLV_INPUT_CursorMoveTaskEnd(void *task);
void BTLV_INPUT_StartScreenTransition(BtlvInput *input, int screen);
void BTLV_INPUT_VisibilityTaskMain(struct TcbTask *task, void *arg);
void BTLV_INPUT_WindowOpenTaskMain(struct TcbTask *task, void *arg);
void BTLV_INPUT_WindowCloseTaskMain(struct TcbTask *task, void *arg);
void BTLV_INPUT_GetTextBlockSize(struct StrObj *str, int font, int *outCount, int *outCapacity);
void BTLV_INPUT_DrawWazaButtons(BtlvInput *input, const Slots *slots);
void BTLV_INPUT_DrawMessageText(BtlvInput *input, const int *text);
void BTLV_INPUT_InitButtonState(BtlvInput *input);
void BTLV_INPUT_DrawSelectScreenText(BtlvInput *input, const int *params);
void BTLV_INPUT_ClearButtonState(BtlvInput *input);
int BTLV_INPUT_GetPpTextColor(int index, int count);
void BTLV_INPUT_CreateActionButtons(BtlvInput *input, BtlvInputPartyInfo *info);
void BTLV_INPUT_DeleteActionButtonActors(BtlvInput *input);
void BTLV_INPUT_SetActionUnitVisible(BtlvInput *input, int visible);
void BTLV_INPUT_CreateStatusIcons(BtlvInput *input, int statusKind);
void BTLV_INPUT_DeleteStatusIcons(BtlvInput *input);
void BTLV_INPUT_CreateWazaCursorActors(BtlvInput *input, int mode);
void BTLV_INPUT_DeleteWazaCursorActors(BtlvInput *input);
void BTLV_INPUT_CreateTargetActors(BtlvInput *input);
void BTLV_INPUT_DeleteTargetActors(BtlvInput *input);
void BTLV_INPUT_DeleteWazaActors(BtlvInput *input);
void BTLV_INPUT_CreateBackActor(BtlvInput *input);
void BTLV_INPUT_DeleteBackActor(BtlvInput *input);
int BTLV_INPUT_ProcessKeyRepeat(BtlvInput *input);
int BTLV_INPUT_SetSelection(BtlvInput *input, int choice, int colour);
void BTLV_INPUT_ButtonFlashTaskMain(struct TcbTask *task, void *arg);
void BTLV_INPUT_ButtonFlashTaskEnd(void *task);
void BTLV_INPUT_DrawRunButtonText(BtlvInput *input, char *runInfo);
void BTLV_INPUT_PrepareCommandSelect(BtlvInput *input);
void BTLV_INPUT_ClearSlotEvents(BtlvInput *input);
void BTLV_INPUT_RegisterTask(BtlvInput *input, int taskFunc, int taskEnd);
int BTLV_INPUT_FindTask(BtlvInput *input, int task);
void BTLV_INPUT_DeleteTask(BtlvInput *input, void *task);
int BTLV_INPUT_AllocTaskSlot(BtlvInput *input);
void BTLV_INPUT_DeleteAllTasks(BtlvInput *input);
int BTLV_INPUT_IsWazaSelectable(BtlvInput *input, const BtlvInputSection *section, int i);
void BTLV_INPUT_UpdateWazaRow(BtlvInput *input);
void BTLV_INPUT_BlendWindowPalette(BtlvInput *input);
void BTLV_INPUT_RestoreWindowPalette(BtlvInput *input);
int BTLV_INPUT_GetMessageBoxMode(BtlvInput *input);
void BTLV_INPUT_PlayConfirmSe(BtlvInput *input);
void BTLV_INPUT_PlayCancelSe(BtlvInput *input);
void BTLV_INPUT_PlaySelectSe(BtlvInput *input);
void BTLV_INPUT_PlayCursorSe(BtlvInput *input);
void BTLV_INPUT_PlayPageSe(BtlvInput *input);
void BTLV_INPUT_PlayOpenSe(BtlvInput *input);
void BTLV_INPUT_PlayBackSe(BtlvInput *input);
/* END mkheaders: generated region */

#endif

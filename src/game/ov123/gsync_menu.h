#ifndef GAME_OV123_GSYNC_MENU_H
#define GAME_OV123_GSYNC_MENU_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of gsync_menu.c, prototypes copied from their definitions. */

struct ButtonWinDef;
typedef struct ButtonWinDef ButtonWinDef;

#include "../ov123/gsync_menu_types.h"
#include "../ov123/gsync_menu_types.h"
#include "../types.h"

void GSYNC_MENU_SetStateFunc(GsyncMenuStateFunc *slot, GsyncMenuStateFunc func);
void GSYNC_MENU_ChangeState(GsyncMenuWork *work, GsyncMenuStateFunc func, int lineNo);
void GSYNC_MENU_InitBgLayers(GsyncMenuWork *work);
void GSYNC_MENU_RestartTimeIcon(GsyncMenuWork *work);
void GSYNC_MENU_AddPaletteEntries(u16 *palette, const u16 *add, int rowCount);
void GSYNC_MENU_StateStartFadeOut(GsyncMenuWork *work);
void GSYNC_MENU_StateWaitMenuSelect(GsyncMenuWork *work);
void GSYNC_MENU_StateOpenYesNoAfterMessage(GsyncMenuWork *work);
void GSYNC_MENU_OnButtonAnimEnd(void *param, u32 frame);
void GSYNC_MENU_NoOp(struct GsyncMenuWork *unused0);
void GSYNC_MENU_CreateButtonWindows(int count, u32 *messageIds, GsyncMenuWork *work, ButtonWinDef *defs, u32 *centerX, u32 *centerY);
void GSYNC_MENU_DeleteButtonWindows(GsyncMenuWork *work);
void GSYNC_MENU_RunButtonCallback(u32 buttonIndex, s32 event, void *work);
void GSYNC_MENU_CreateActors(GsyncMenuWork *work);
void GSYNC_MENU_LoadResources(GsyncMenuWork *work);
void GSYNC_MENU_StateSetupButtons(GsyncMenuWork *work);
void GSYNC_MENU_FreeResources(GsyncMenuWork *work);
void GSYNC_MENU_StateWaitFadeOut(GsyncMenuWork *work);
void GSYNC_MENU_StateWaitTouchAfterMessage(GsyncMenuWork *work);
void GSYNC_MENU_StatePlayButtonAnim(GsyncMenuWork *work);
int GSYNC_MENU_OnButtonPressed(int button, GsyncMenuWork *work);
void GSYNC_MENU_SetCursorAnimIfChanged(GsyncMenuWork *work, int animSeq);
void GSYNC_MENU_UpdateCursorAnimFromKeys(GsyncMenuWork *work);
void GSYNC_MENU_StateButtonsActive(GsyncMenuWork *work);
void GSYNC_MENU_FadePaletteSlot(GsyncMenuWork *work, int palSlot, int rowCount);
void GSYNC_MENU_SetPaletteFade(GsyncMenuWork *work, int enable);
void GSYNC_MENU_OpenYesNoMenu(GsyncMenuWork *work);
void GSYNC_MENU_HideMessage(GsyncMenuWork *work);
void GSYNC_MENU_DeleteMessageWindow(GsyncMenuWork *work);
int GSYNC_MENU_UpdateMessageStream(GsyncMenuWork *work);
void GSYNC_MENU_PrintMessage(GsyncMenuWork *work, int lineCount, int stream);
void GSYNC_MENU_PrintMessageNoStream(GsyncMenuWork *work);
void GSYNC_MENU_StatePrintConfirmMessage(GsyncMenuWork *work);
void GSYNC_MENU_StateSaveFinish(GsyncMenuWork *work);
void GSYNC_MENU_StateSaveStart(GsyncMenuWork *work);
void GSYNC_MENU_StateConfirmSelect(GsyncMenuWork *work);
void GSYNC_MENU_StateOpenConfirmMenu(GsyncMenuWork *work);
void GSYNC_MENU_VBlank(struct TcbTask * unused0, void * unused1);
int GSYNC_MENU_ProcInit(void *proc, int seq, GsyncProcParam *param);
int GSYNC_MENU_ProcMain(int unused0, int unused1, int unused2, GsyncMenuWork *work);
int GSYNC_MENU_ProcExit(void *proc, int seq, GsyncProcParam *param, GsyncMenuWork *work);
/* END mkheaders: generated region */

#endif

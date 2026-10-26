#ifndef GAME_OV123_PDWACC_STATE_H
#define GAME_OV123_PDWACC_STATE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of pdwacc_state.c, prototypes copied from their definitions. */

#include "../ov123/pdwacc_disp_types.h"

int PDWACC_STATE_HandleHttpError(PdwaccProc *proc, int resultCode);
void PDWACC_STATE_SetState(PdwaccProc *proc, PdwaccStateFunc state, int line);
void PDWACC_STATE_ChangeState(PdwaccProc *proc, PdwaccStateFunc state, int line);
void PDWACC_STATE_StateWaitFade(PdwaccProc *proc);
void PDWACC_STATE_StateFadeOutBgm(PdwaccProc *proc);
void PDWACC_STATE_StateWaitInputStream(PdwaccProc *proc);
void PDWACC_STATE_StateSaveMainWait(PdwaccProc *proc);
void PDWACC_STATE_StateSaveStart(PdwaccProc *proc);
void PDWACC_STATE_StateRestartTimeIcon(PdwaccProc *proc);
void PDWACC_STATE_StateWaitInputClearWindow(PdwaccProc *proc);
void PDWACC_STATE_StateWaitInputPrintNumbers(PdwaccProc *proc);
void PDWACC_STATE_StatePrintNumbersMessage(PdwaccProc *proc);
void PDWACC_STATE_StateWaitInput(PdwaccProc *proc);
void PDWACC_STATE_StatePrintError(PdwaccProc *proc);
void PDWACC_STATE_StateWaitStreamThenSendRequest(PdwaccProc *proc);
void PDWACC_STATE_StateTimeIconMessage(PdwaccProc *proc);
void PDWACC_STATE_StateConfirmMenuSelect(PdwaccProc *proc);
void PDWACC_STATE_StateOpenConfirmMenu(PdwaccProc *proc);
void PDWACC_STATE_StatePrintIntroMessage(PdwaccProc *proc);
void PDWACC_STATE_StateReceiveResponse(PdwaccProc *proc);
void PDWACC_STATE_StateSendRequest(PdwaccProc *proc);
void PDWACC_STATE_StateWaitFadeClearNumbers(PdwaccProc *proc);
void PDWACC_STATE_StatePrintResultMessage(PdwaccProc *proc);
void PDWACC_STATE_DestroyHttpConnection(void *arg, u32 errorCode, u32 errorType, int dwcError);
int PDWACC_STATE_ProcInit(void *procSys,int unused,PdwaccProcParam *param);
int PDWACC_STATE_ProcMain(int unused0,int unused1,PdwaccProcParam *param,PdwaccProc *proc);
int PDWACC_STATE_ProcExit(void *procHandle, int unused0, int unused1, PdwaccProc *proc);
/* END mkheaders: generated region */

#endif

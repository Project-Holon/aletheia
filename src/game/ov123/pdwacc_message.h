#ifndef GAME_OV123_PDWACC_MESSAGE_H
#define GAME_OV123_PDWACC_MESSAGE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of pdwacc_message.c, prototypes copied from their definitions. */

#include "../ov123/pdwacc_message_types.h"
#include "../types.h"

void PDWACC_MESSAGE_DeleteButtonManager(PdwaccMessageWork *work);
PdwaccMessageWork *PDWACC_MESSAGE_InitSystem(u32 heap, u32 bank);
void PDWACC_MESSAGE_UpdateSystem(PdwaccMessageWork *work);
void PDWACC_MESSAGE_ExitSystem(PdwaccMessageWork *work);
void PDWACC_MESSAGE_PrintStream(PdwaccMessageWork *work, int msgId);
void PDWACC_MESSAGE_RestartTimeIcon(PdwaccMessageWork *work);
int PDWACC_MESSAGE_UpdateStream(PdwaccMessageWork *work);
void PDWACC_MESSAGE_ClearStream(PdwaccMessageWork *work);
void *PDWACC_MESSAGE_OpenYesNoMenu(PdwaccMessageWork *work, int layout);
void PDWACC_MESSAGE_PrintInWindow(PdwaccMessageWork *work, int msgId);
void PDWACC_MESSAGE_ClearWindow(PdwaccMessageWork *work);
void PDWACC_MESSAGE_FormatNumber(int value, void *buf);
void PDWACC_MESSAGE_PrintNumberWindows(PdwaccMessageWork *work, int value, int unused);
void PDWACC_MESSAGE_DeleteNumberWindows(PdwaccMessageWork *work);
/* END mkheaders: generated region */

#endif

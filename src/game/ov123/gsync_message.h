#ifndef GAME_OV123_GSYNC_MESSAGE_H
#define GAME_OV123_GSYNC_MESSAGE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of gsync_message.c, prototypes copied from their definitions. */

struct TaskMenuWork;

#include "../ov123/gsync_message_types.h"
#include "../types.h"

void GSYNC_MESSAGE_DeleteButtonManager(GsyncMessageWork *work);
GsyncMessageWork *GSYNC_MESSAGE_InitSystem(u32 heap, u32 msgBank);
void GSYNC_MESSAGE_UpdateSystem(GsyncMessageWork *work);
void GSYNC_MESSAGE_ExitSystem(GsyncMessageWork *work);
void GSYNC_MESSAGE_PrintStream(GsyncMessageWork *work, int instant);
void GSYNC_MESSAGE_PrintStreamId(GsyncMessageWork *work, int msgId);
void GSYNC_MESSAGE_SetMonName(GsyncMessageWork *work, int msgId, int digits, void *mon);
int GSYNC_MESSAGE_UpdateStream(GsyncMessageWork *work);
void GSYNC_MESSAGE_ClearStream(GsyncMessageWork *work);
struct TaskMenuWork *GSYNC_MESSAGE_OpenYesNoMenu(GsyncMessageWork *work, int layout);
int GSYNC_MESSAGE_PrintId(GsyncMessageWork *work, int msgId);
void GSYNC_MESSAGE_PrintInWindow(GsyncMessageWork *work, int top, int height);
void GSYNC_MESSAGE_PrintInSubWindow(GsyncMessageWork *work);
void GSYNC_MESSAGE_ClearWindow(GsyncMessageWork *work);
void GSYNC_MESSAGE_RestartTimeIcon(GsyncMessageWork *work);
void GSYNC_MESSAGE_PrintDefault(GsyncMessageWork *work, int value);
/* END mkheaders: generated region */

#endif

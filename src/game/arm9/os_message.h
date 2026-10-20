#ifndef GAME_ARM9_OS_MESSAGE_H
#define GAME_ARM9_OS_MESSAGE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of os_message.c, prototypes copied from their definitions. */

#include "../sdk_os.h"
#include "../sdk_os.h"
#include "../types.h"

void OS_InitMessageQueue(OSMessageQueue *mq, OSMessage *msgArray, s32 msgCount);
BOOL OS_SendMessage(OSMessageQueue *mq, OSMessage msg, s32 flags);
BOOL OS_ReceiveMessage(OSMessageQueue *mq, OSMessage *msg, s32 flags);
BOOL OS_JamMessage(OSMessageQueue *mq, OSMessage msg, s32 flags);
BOOL OS_ReadMessage(OSMessageQueue *mq, OSMessage *msg, s32 flags);
/* END mkheaders: generated region */

#endif

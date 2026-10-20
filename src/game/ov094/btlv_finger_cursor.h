#ifndef GAME_OV094_BTLV_FINGER_CURSOR_H
#define GAME_OV094_BTLV_FINGER_CURSOR_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of btlv_finger_cursor.c, prototypes copied from their definitions. */

struct BtlvFingerCursor;
struct TcbTask;
typedef struct BtlvFingerCursor BtlvFingerCursor;

#include "../types.h"

BtlvFingerCursor *BTLV_FINGER_CURSOR_Create(void *palAnmSlots, u32 palSlot, u16 heapId);
void BTLV_FINGER_CURSOR_Delete(BtlvFingerCursor *cursor);
int BTLV_FINGER_CURSOR_Start(BtlvFingerCursor *cursor, int x, int y, u32 startDelay, u32 loopCount, u32 hideTimer);
void BTLV_FINGER_CURSOR_DeleteActor(BtlvFingerCursor *cursor);
int BTLV_FINGER_CURSOR_IsActive(BtlvFingerCursor *cursor);
void BTLV_FINGER_CURSOR_AnimCallback(BtlvFingerCursor *cursor);
void BTLV_FINGER_CURSOR_TaskHideAfterDelay(struct TcbTask *task, void *work);
/* END mkheaders: generated region */

#endif

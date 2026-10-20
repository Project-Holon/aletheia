#ifndef GAME_OV094_BTLV_TIMER_H
#define GAME_OV094_BTLV_TIMER_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of btlv_timer.c, prototypes copied from their definitions. */

struct TcbTask;

#include "../ov094/btlv_timer_shared_types.h"
#include "../types.h"

BtlvTimer *BTLV_TIMER_Create(u16 heapId);
void BTLV_TIMER_Delete(BtlvTimer *timer);
void BTLV_TIMER_Start(BtlvTimer *timer, int secondsPlayer, int secondsEnemy);
void BTLV_TIMER_DeleteActors(BtlvTimer *timer);
void BTLV_TIMER_SetVisible(BtlvTimer *timer, int side, int visible, int restart);
int BTLV_TIMER_IsExpired(BtlvTimer *timer, int side);
void BTLV_TIMER_Redraw(BtlvTimer *timer, int side);
void BTLV_TIMER_TickTask(struct TcbTask *tcb, void *timerArg);
/* END mkheaders: generated region */

#endif

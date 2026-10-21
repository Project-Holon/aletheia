#ifndef GAME_OV094_BTLV_BG_H
#define GAME_OV094_BTLV_BG_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of btlv_bg.c, prototypes copied from their definitions. */

struct TcbTask;

#include "../ov094/btlv_bg_types.h"
#include "../types.h"
#include "../sdk_fx.h"
#include "../sdk_fx.h"

BtlvBg *BTLV_BG_Create(void *taskSystem, u16 heapId);
void BTLV_BG_Delete(BtlvBg *bg);
void BTLV_BG_SetScroll(BtlvBg *bg, u32 scrollX, u32 scrollY);
void BTLV_BG_StartScroll(BtlvBg *bg, int flipFlags, u32 mode, int x, int y, int frames, int phaseFrames, int cycleFrames);
unsigned int BTLV_BG_IsScrolling(BtlvBg *bg);
void BTLV_BG_StartScrollJob(BtlvBg *bg, u32 mode, VecFx32 *origin, VecFx32 *amount, int frames, int phaseFrames, int cycleFrames, void (*onTick)(struct TcbTask *, void *));
void BTLV_BG_ScrollTask(struct TcbTask *task, void *arg);
void BTLV_BG_OnScrollJobEnd(void *task);
void BTLV_BG_ApplyScrollTask(struct TcbTask *task, void *work);
/* END mkheaders: generated region */

#endif

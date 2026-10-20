#ifndef GAME_OV094_BTLV_CLACT_H
#define GAME_OV094_BTLV_CLACT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of btlv_clact.c, prototypes copied from their definitions. */

struct TcbTask;

#include "../ov094/btlv_clact_shared_types.h"
#include "../types.h"
#include "../sdk_fx.h"

BtlvClact *BTLV_CLACT_Create(void *owner, u16 heap);
void BTLV_CLACT_Delete(BtlvClact *clact);
void BTLV_CLACT_Draw(void *unused);
int BTLV_CLACT_LoadActorSimple(BtlvClact *clact, int archiveId, int firstFile, s16 x, s16 y, int scaleX, int scaleY);
int BTLV_CLACT_LoadActor(BtlvClact *clact, u32 archiveId, int charFile, u32 palFile, int cellFile, int animFile, s16 x, s16 y, u32 scaleX, u32 scaleY);
void BTLV_CLACT_ReleaseActor(BtlvClact *clact, int slot);
void BTLV_CLACT_StartPosTween(BtlvClact *clact, int slot, int mode, s16 *offset, int frames, int waitTicks, int repeats);
void BTLV_CLACT_StartScaleTween(BtlvClact *clact, int slot, int mode, VecFx32 *scaleEnd, int frames, int waitTicks, int repeats);
void BTLV_CLACT_SetActorAnimSeq(BtlvClact *clact, int slot, int seq);
void BTLV_CLACT_RequestPaletteFade(BtlvClact *clact, int slot, u8 startLevel, u8 targetLevel, s8 step, u16 color);
void BTLV_CLACT_StartMoveTask(BtlvClact *clact, int slot, u32 mode, VecFx32 *start, VecFx32 *end, int frames, int waitTicks, int repeats, void (*taskMain)(struct TcbTask *, void *), void (*taskEnd)(void *));
void BTLV_CLACT_MoveTaskMain(struct TcbTask *task, void *work);
void BTLV_CLACT_MoveTaskEnd(void *task);
void BTLV_CLACT_MoveTaskMainWide(struct TcbTask *task, void *work);
void BTLV_CLACT_MoveTaskEndWide(void *task);
/* END mkheaders: generated region */

#endif

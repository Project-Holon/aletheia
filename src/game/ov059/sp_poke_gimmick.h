#ifndef GAME_OV059_SP_POKE_GIMMICK_H
#define GAME_OV059_SP_POKE_GIMMICK_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of sp_poke_gimmick.c, prototypes copied from their definitions. */

struct FieldMap;
struct GameEvent;
struct GameSystem;

#include "../sdk_fx.h"
#include "../sdk_fx.h"
#include "../types.h"

void SP_POKE_GIMMICK_LoadModelScene(struct FieldMap *fieldMap);
void SP_POKE_GIMMICK_ExitPairA(struct FieldMap *fieldMap);
void SP_POKE_GIMMICK_UpdatePairA(struct FieldMap *fieldMap);
void SP_POKE_GIMMICK_InitPairB(struct FieldMap *fieldMap);
void SP_POKE_GIMMICK_ExitPairB(struct FieldMap *fieldMap);
void SP_POKE_GIMMICK_UpdatePairB(struct FieldMap *fieldMap);
void SP_POKE_GIMMICK_Init(struct FieldMap *fieldMap);
void SP_POKE_GIMMICK_Exit(struct FieldMap *fieldMap);
void SP_POKE_GIMMICK_Update(struct FieldMap *fieldMap);
struct GameEvent *SP_POKE_GIMMICK_StartMove(struct GameSystem *gameSystem, int side, VecFx32 *from, const VecFx32 *to, fx32 bump, int frames);
void SP_POKE_GIMMICK_ShowAndPlay(struct GameSystem *gameSystem, int side, VecFx32 *pos);
struct GameEvent *SP_POKE_GIMMICK_StartWaitAnimeProgress(struct GameSystem *gameSystem, int side);
struct GameEvent *SP_POKE_GIMMICK_StartWaitAnimeEnd(struct GameSystem *gameSystem, int side);
int SP_POKE_GIMMICK_MoveEventMain(struct GameEvent *event, int *seq, void *eventWork);
int SP_POKE_GIMMICK_WaitAnimeProgressEventMain(struct GameEvent *event, int *seq, void *eventWork);
int SP_POKE_GIMMICK_WaitAnimeEndEventMain(struct GameEvent *event, int *seq, void *eventWork);
struct GameEvent *SP_POKE_GIMMICK_StartSwapNpc(struct GameSystem *gameSystem, VecFx32 *pos, u16 removeObjectId, u16 addObjectId);
int SP_POKE_GIMMICK_SwapNpcEventMain(struct GameEvent *event, int *seq, void *eventWork);
/* END mkheaders: generated region */

#endif

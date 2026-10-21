#ifndef GAME_OV168_MICTEST_H
#define GAME_OV168_MICTEST_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of mictest.c, prototypes copied from their definitions. */

struct MictestWork;
struct MictestState;
struct TcbTask;
typedef struct MictestWork MictestWork;
typedef struct MictestState MictestState;

#include "../types.h"

int MICTEST_Exit(struct Proc *a, int b, int c, MictestWork *p);
int MICTEST_Main(int a, int b, int c, MictestWork *p);
void MICTEST_RunStepMachine(MictestState *p);
MictestWork *MICTEST_GetOwner(MictestState *p);
int MICTEST_IsStepDone(MictestState *p);
void MICTEST_MarkStepDone(MictestState *p);
void MICTEST_StepWipeIn(MictestState *self, int *state);
void MICTEST_StepRecord(MictestState *self, int *state);
void MICTEST_StepWaitAnim(MictestState *self, int *state);
void MICTEST_StepWipeOut(MictestState *self, int *state);
void MICTEST_StepFinish(MictestState *self, int *state);
void MICTEST_ResetDisplay(int unused);
void MICTEST_ClearDisplay(void);
void MICTEST_SetupVramBanks(void);
void MICTEST_VBlank(struct TcbTask *unused, void *work_);
void MICTEST_InitActorSystem(int unused, u32 heap);
void MICTEST_ExitActorSystem(MictestWork *unused);
void MICTEST_UpdateActors(MictestWork *p);
void MICTEST_CreateActors(MictestWork *p, u16 heap);
void MICTEST_DeleteUnit(MictestWork *p);
void MICTEST_ActorVBlank(void *unused);
void MICTEST_OnMicEvent(int event, MictestWork *p);
int MICTEST_LevelToAnim(u8 level);
int MICTEST_AreAllSpritesIdle(MictestWork *p);
int MICTEST_SpawnSprite(MictestWork *p, int unused, s16 x, s16 y, void *owner);
void MICTEST_UpdateSpriteTask(struct TcbTask *task, void *work);
void MICTEST_DeleteSpriteTasks(MictestWork *p);
int MICTEST_TouchHit(void);
int MICTEST_CheckTouchOrKey(void);
/* END mkheaders: generated region */

#endif

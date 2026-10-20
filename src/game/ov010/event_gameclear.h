#ifndef GAME_OV010_EVENT_GAMECLEAR_H
#define GAME_OV010_EVENT_GAMECLEAR_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of event_gameclear.c, prototypes copied from their definitions. */

struct GameEvent;
struct GameSystem;
struct GameClearWork;
typedef struct GameClearWork GameClearWork;

#include "../types.h"

int EVENT_GAMECLEAR_Main(struct GameEvent *event, u32 *seq, void *workArg);
struct GameEvent *EVENT_GAMECLEAR_Create(struct GameSystem *gameSystem, int mode);
void EVENT_GAMECLEAR_InitHallOfFameParam(GameClearWork *work);
int EVENT_GAMECLEAR_InitStaffRollParam(GameClearWork *work);
void EVENT_GAMECLEAR_InitStepSequence(GameClearWork *work);
int EVENT_GAMECLEAR_GetCommExitKind(void);
void EVENT_GAMECLEAR_AdvanceStep(GameClearWork *work, u32 *seq);
void EVENT_GAMECLEAR_SetGatePoints(GameClearWork *work);
/* END mkheaders: generated region */

#endif

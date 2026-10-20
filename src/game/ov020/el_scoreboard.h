#ifndef GAME_OV020_EL_SCOREBOARD_H
#define GAME_OV020_EL_SCOREBOARD_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of el_scoreboard.c, prototypes copied from their definitions. */

struct Strbuf;

#include "../ov020/el_scoreboard_types.h"
#include "../types.h"

ElLamp *EL_SCOREBOARD_CreateLamp(void *archive, const char *texName, const char *plttName, struct Strbuf *text, u16 xPos, u16 yPos, u16 heapId);
void EL_SCOREBOARD_DeleteLamp(ElLamp *lamp);
void EL_SCOREBOARD_TickLamp(ElLamp *lamp);
void EL_SCOREBOARD_AnimateLampPalette(ElLampPaletteRef *paletteRef, int tick);
int EL_SCOREBOARD_EventMain(void *eventTask, int *state, ElScoreboardWork *work);
void *EL_SCOREBOARD_StartOnField(void *gameSystem, void *fieldMap, u8 shownSeason, u8 targetSeason);
void *EL_SCOREBOARD_StartOnFieldWithCallback(void *gameSystem, void *fieldMap, u8 shownSeason, u8 targetSeason, ElScoreboardCallback finishCallback, int finishCallbackArg);
void *EL_SCOREBOARD_StartStandalone(void *gameSystem, u8 shownSeason, u8 targetSeason);
void EL_SCOREBOARD_SetupDisplay(ElScoreboardWork *work);
void EL_SCOREBOARD_SetupSharedDisplay(ElScoreboardWork *work);
void EL_SCOREBOARD_SetupStandaloneDisplay(ElScoreboardWork *work);
void EL_SCOREBOARD_TeardownDisplay(ElScoreboardWork *work);
void EL_SCOREBOARD_TeardownSharedDisplay(ElScoreboardWork *work);
void EL_SCOREBOARD_TeardownStandaloneDisplay(ElScoreboardWork *work);
void EL_SCOREBOARD_LoadSeasonGraphics(int season, int heapId);
void EL_SCOREBOARD_UpdateFade(ElScoreboardWork *work, int state);
void EL_SCOREBOARD_UpdateFadeShared(const ElScoreboardWork *work, int state);
void EL_SCOREBOARD_UpdateFadeStandalone(ElScoreboardWork *work, int state);
int EL_SCOREBOARD_GetNextState(ElScoreboardWork *work, int state);
void EL_SCOREBOARD_EnterState(ElScoreboardWork *work, int *statePtr, int state);
void EL_SCOREBOARD_AdvanceState(ElScoreboardWork *work, int *statePtr);
void EL_SCOREBOARD_OnStart(ElScoreboardWork *work);
void EL_SCOREBOARD_OnFinish(ElScoreboardWork *work);
u32 EL_SCOREBOARD_GetMode(ElScoreboardWork *work);
u32 EL_SCOREBOARD_IsFinishRequested(ElScoreboardWork *work);
void EL_SCOREBOARD_RequestFinish(ElScoreboardWork *work);
int EL_SCOREBOARD_IsStateDone(ElScoreboardWork *work);
int EL_SCOREBOARD_GetFadeInDuration(ElScoreboardWork *work);
int EL_SCOREBOARD_GetFadeOutDuration(ElScoreboardWork *work);
int EL_SCOREBOARD_GetHoldDuration(ElScoreboardWork *work);
void EL_SCOREBOARD_CallFinishCallback(ElScoreboardWork *work);
/* END mkheaders: generated region */

#endif

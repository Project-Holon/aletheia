#ifndef GAME_OV118_POKEMONTRADE_DEMO_UP_H
#define GAME_OV118_POKEMONTRADE_DEMO_UP_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of pokemontrade_demo_up.c, prototypes copied from their definitions. */

struct MyStatus;

#include "../ov119/pokemontrade_types.h"
#include "../types.h"

void POKETRADE_DEMO_UP_StepStartPlayback(TradeWork *work);
void POKETRADE_DEMO_UP_PrintMessage(TradeWork *work);
void POKETRADE_DEMO_UP_StepMessage(TradeWork *work);
void POKETRADE_DEMO_UP_StepEndScene(TradeWork *work);
void POKETRADE_DEMO_UP_UpdateEmitterA(void *obj, int on);
void POKETRADE_DEMO_UP_SetupEmitterA(void *emitter);
void POKETRADE_DEMO_UP_UpdateEmitterB(void *obj, int on);
void POKETRADE_DEMO_UP_SetupEmitterB(void *emitter);
void POKETRADE_DEMO_UP_StepStartCompare(TradeWork *work);
void POKETRADE_DEMO_UP_StepSetup(TradeWork *work);
void POKETRADE_DEMO_UP_StepParticleSystems(TradeWork *work);
void POKETRADE_DEMO_UP_StepAddUnit(TradeWork *work);
void POKETRADE_DEMO_UP_UpdateScene(TradeWork *work);
void POKETRADE_DEMO_UP_CompareSideMon(TradeWork *work, u8 *outSame, u8 *outFlag, struct MyStatus *key, int enemy);
void POKETRADE_DEMO_UP_CreateUnitActor(TradeWork *work);
void POKETRADE_DEMO_UP_LoadUnitResources(TradeWork *work);
void POKETRADE_DEMO_UP_ReleaseUnit(TradeWork *work);
int POKETRADE_DEMO_UP_PassThrough(int value);
void POKETRADE_DEMO_UP_SetFrame(TradeWork *work, u32 frame);
void POKETRADE_DEMO_UP_SetFinishFlag(TradeWork *work);
void POKETRADE_DEMO_UP_StepReleaseUnit(TradeWork *work);
void POKETRADE_DEMO_UP_DeleteSlide(TradeWork *work, int idx);
void POKETRADE_DEMO_UP_SetMonSlide(TradeWork *work, int idx);
void POKETRADE_DEMO_UP_ResetMonSlide(TradeWork *work, int idx);
void POKETRADE_DEMO_UP_UpdateEmitterC(void *obj, int on);
void POKETRADE_DEMO_UP_SetupEmitterC(void *emitter);
void POKETRADE_DEMO_UP_UpdateEmitterD(void *obj, int on);
void POKETRADE_DEMO_UP_SetupEmitterD(void *emitter);
void POKETRADE_DEMO_UP_StepStartDownScene(TradeWork *work);
/* END mkheaders: generated region */

#endif

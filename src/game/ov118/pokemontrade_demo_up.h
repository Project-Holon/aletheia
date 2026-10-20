#ifndef GAME_OV118_POKEMONTRADE_DEMO_UP_H
#define GAME_OV118_POKEMONTRADE_DEMO_UP_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of pokemontrade_demo_up.c, prototypes copied from their definitions. */

#include "../types.h"

void POKETRADE_DEMO_UP_StepStartPlayback(u8 *work);
void POKETRADE_DEMO_UP_PrintMessage(u8 *work);
void POKETRADE_DEMO_UP_StepMessage(u8 *work);
void POKETRADE_DEMO_UP_StepEndScene(void *work);
void POKETRADE_DEMO_UP_UpdateEmitterA(void *obj, int on);
void POKETRADE_DEMO_UP_SetupEmitterA(void *emitter);
void POKETRADE_DEMO_UP_UpdateEmitterB(void *obj, int on);
void POKETRADE_DEMO_UP_SetupEmitterB(void *emitter);
void POKETRADE_DEMO_UP_StepStartCompare(u8 *work);
void POKETRADE_DEMO_UP_StepSetup(u8 *work);
void POKETRADE_DEMO_UP_StepParticleSystems(u8 *work);
void POKETRADE_DEMO_UP_StepAddUnit(u8 *work);
void POKETRADE_DEMO_UP_UpdateScene(u8 *work);
void POKETRADE_DEMO_UP_CompareSideMon(u8 *work, u8 *outSame, u8 *outFlag, u32 key, int enemy);
void POKETRADE_DEMO_UP_CreateUnitActor(void *work);
void POKETRADE_DEMO_UP_LoadUnitResources(void *work);
void POKETRADE_DEMO_UP_ReleaseUnit(void *work);
int POKETRADE_DEMO_UP_PassThrough(int value);
void POKETRADE_DEMO_UP_SetFrame(u8 *work, u32 frame);
void POKETRADE_DEMO_UP_SetFinishFlag(u8 *work);
void POKETRADE_DEMO_UP_StepReleaseUnit(void *work);
void POKETRADE_DEMO_UP_DeleteSlide(u8 *work, int idx);
void POKETRADE_DEMO_UP_SetMonSlide(u8 *work, int idx);
void POKETRADE_DEMO_UP_ResetMonSlide(u8 *work, int idx);
void POKETRADE_DEMO_UP_UpdateEmitterC(void *obj, int on);
void POKETRADE_DEMO_UP_SetupEmitterC(void *emitter);
void POKETRADE_DEMO_UP_UpdateEmitterD(void *obj, int on);
void POKETRADE_DEMO_UP_SetupEmitterD(void *emitter);
void POKETRADE_DEMO_UP_StepStartDownScene(u8 *work);
/* END mkheaders: generated region */

#endif

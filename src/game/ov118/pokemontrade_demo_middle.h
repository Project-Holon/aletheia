#ifndef GAME_OV118_POKEMONTRADE_DEMO_MIDDLE_H
#define GAME_OV118_POKEMONTRADE_DEMO_MIDDLE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of pokemontrade_demo_middle.c, prototypes copied from their definitions. */

#include "../types.h"

void POKETRADE_DEMO_MIDDLE_StepStartPlayback(u8 *work);
void POKETRADE_DEMO_MIDDLE_PrintMessage(u8 *work);
void POKETRADE_DEMO_MIDDLE_StepMessage(u8 *work);
void POKETRADE_DEMO_MIDDLE_StepEndScene(void *work);
void POKETRADE_DEMO_MIDDLE_DeleteSlide(void *work, int idx);
void POKETRADE_DEMO_MIDDLE_CreateOfferSlide(void *work, int idx);
void POKETRADE_DEMO_MIDDLE_ResetMonSlide(void *work, int idx);
void POKETRADE_DEMO_MIDDLE_UpdateEmitterA(void *obj, int on);
void POKETRADE_DEMO_MIDDLE_SetupEmitterA(void *emitter);
void POKETRADE_DEMO_MIDDLE_UpdateEmitterB(void *obj, int on);
void POKETRADE_DEMO_MIDDLE_SetupEmitterB(void *emitter);
void POKETRADE_DEMO_MIDDLE_StepStartCompare(u8 *work);
void POKETRADE_DEMO_MIDDLE_StepSetup(u8 *work);
void POKETRADE_DEMO_MIDDLE_StepParticleSystems(u8 *work);
void POKETRADE_DEMO_MIDDLE_StepAddUnit(u8 *work);
void POKETRADE_DEMO_MIDDLE_UpdateScene(u8 *work);
/* END mkheaders: generated region */

#endif

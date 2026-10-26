#ifndef GAME_OV118_POKEMONTRADE_DEMO_MIDDLE_H
#define GAME_OV118_POKEMONTRADE_DEMO_MIDDLE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of pokemontrade_demo_middle.c, prototypes copied from their definitions. */

#include "../ov119/pokemontrade_types.h"

void POKETRADE_DEMO_MIDDLE_StepStartPlayback(TradeWork *work);
void POKETRADE_DEMO_MIDDLE_PrintMessage(TradeWork *work);
void POKETRADE_DEMO_MIDDLE_StepMessage(TradeWork *work);
void POKETRADE_DEMO_MIDDLE_StepEndScene(TradeWork *work);
void POKETRADE_DEMO_MIDDLE_DeleteSlide(TradeWork *work, int idx);
void POKETRADE_DEMO_MIDDLE_CreateOfferSlide(TradeWork *work, int idx);
void POKETRADE_DEMO_MIDDLE_ResetMonSlide(TradeWork *work, int idx);
void POKETRADE_DEMO_MIDDLE_UpdateEmitterA(void *obj, int on);
void POKETRADE_DEMO_MIDDLE_SetupEmitterA(void *emitter);
void POKETRADE_DEMO_MIDDLE_UpdateEmitterB(void *obj, int on);
void POKETRADE_DEMO_MIDDLE_SetupEmitterB(void *emitter);
void POKETRADE_DEMO_MIDDLE_StepStartCompare(TradeWork *work);
void POKETRADE_DEMO_MIDDLE_StepSetup(TradeWork *work);
void POKETRADE_DEMO_MIDDLE_StepParticleSystems(TradeWork *work);
void POKETRADE_DEMO_MIDDLE_StepAddUnit(TradeWork *work);
void POKETRADE_DEMO_MIDDLE_UpdateScene(TradeWork *work);
/* END mkheaders: generated region */

#endif

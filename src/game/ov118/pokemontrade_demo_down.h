#ifndef GAME_OV118_POKEMONTRADE_DEMO_DOWN_H
#define GAME_OV118_POKEMONTRADE_DEMO_DOWN_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of pokemontrade_demo_down.c, prototypes copied from their definitions. */

struct MyStatus;

#include "../ov119/pokemontrade_types.h"
#include "../types.h"

void POKETRADE_DEMO_DOWN_StepSetup(TradeWork *work);
void POKETRADE_DEMO_DOWN_StepSetupParticles(TradeWork *work);
void POKETRADE_DEMO_DOWN_StepPlaySe(TradeWork *work);
void POKETRADE_DEMO_DOWN_UpdateScene(TradeWork *work);
void POKETRADE_DEMO_DOWN_StepFade(s8 *fade);
void POKETRADE_DEMO_DOWN_CompareSideMon(TradeWork *work, u8 *outSame, u8 *outFlag, struct MyStatus *key, int enemy);
void POKETRADE_DEMO_DOWN_CreateUnitActor(TradeWork *work);
void POKETRADE_DEMO_DOWN_LoadUnitResources(TradeWork *work);
void POKETRADE_DEMO_DOWN_ReleaseUnit(TradeWork *work);
int POKETRADE_DEMO_DOWN_PassThrough(int value);
void POKETRADE_DEMO_DOWN_SetFrame(TradeWork *work, u32 frame);
void POKETRADE_DEMO_DOWN_SetFinishFlag(TradeWork *work);
void POKETRADE_DEMO_DOWN_StepStartPlayback(TradeWork *work);
void POKETRADE_DEMO_DOWN_StepWaitSync(TradeWork *work);
/* END mkheaders: generated region */

#endif

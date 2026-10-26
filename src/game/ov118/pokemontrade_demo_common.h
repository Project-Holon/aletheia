#ifndef GAME_OV118_POKEMONTRADE_DEMO_COMMON_H
#define GAME_OV118_POKEMONTRADE_DEMO_COMMON_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of pokemontrade_demo_common.c, prototypes copied from their definitions. */

struct MyStatus;

#include "../types.h"
#include "../ov119/pokemontrade_types.h"

void POKETRADE_DEMO_COMMON_StepFade(s8 *fade);
void POKETRADE_DEMO_COMMON_CompareSideMon(TradeWork *work, u8 *outSame, u8 *outFlag, struct MyStatus *key, int enemy);
void POKETRADE_DEMO_COMMON_ShowUnitActor(TradeWork *work);
void POKETRADE_DEMO_COMMON_LoadUnitResources(TradeWork *work);
void POKETRADE_DEMO_COMMON_ReleaseUnit(TradeWork *work);
int POKETRADE_DEMO_COMMON_PassThrough(int value);
void POKETRADE_DEMO_COMMON_SetFrame(TradeWork *work, u32 frame);
void POKETRADE_DEMO_COMMON_SetFinishFlag(TradeWork *work);
void POKETRADE_DEMO_COMMON_StepCompareMons(TradeWork *work);
void POKETRADE_DEMO_COMMON_StepWaitSync(TradeWork *work);
void POKETRADE_DEMO_COMMON_StepStartSlides(TradeWork *work);
void POKETRADE_DEMO_COMMON_StepBeginPlayback(TradeWork *work);
/* END mkheaders: generated region */

#endif

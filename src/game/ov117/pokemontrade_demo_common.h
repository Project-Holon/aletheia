#ifndef GAME_OV117_POKEMONTRADE_DEMO_COMMON_H
#define GAME_OV117_POKEMONTRADE_DEMO_COMMON_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of pokemontrade_demo_common.c, prototypes copied from their definitions. */

struct MyStatus;

#include "../types.h"
#include "../ov119/pokemontrade_types.h"

void POKETRADE_DEMO_COMMON_StepFade(s8 *fade);
void POKETRADE_DEMO_COMMON_CompareSideMon(TradeWork *p, u8 *outSame, u8 *outFlag, struct MyStatus *key, int enemy);
void POKETRADE_DEMO_COMMON_ShowUnitActor(TradeWork *p);
void POKETRADE_DEMO_COMMON_LoadUnitResources(TradeWork *p);
void POKETRADE_DEMO_COMMON_ReleaseUnit(TradeWork *p);
int POKETRADE_DEMO_COMMON_PassThrough(int a);
void POKETRADE_DEMO_COMMON_SetFrame(TradeWork *p, u32 v);
void POKETRADE_DEMO_COMMON_SetFinishFlag(TradeWork *p);
void POKETRADE_DEMO_COMMON_StepCompareMons(TradeWork *p);
void POKETRADE_DEMO_COMMON_StepWaitSync(TradeWork *p);
void POKETRADE_DEMO_COMMON_StepStartSlides(TradeWork *p);
/* END mkheaders: generated region */

#endif

#ifndef GAME_OV118_POKEMONTRADE_DEMO_COMMON_H
#define GAME_OV118_POKEMONTRADE_DEMO_COMMON_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of pokemontrade_demo_common.c, prototypes copied from their definitions. */

#include "../types.h"

void POKETRADE_DEMO_COMMON_StepFade(s8 *fade);
void POKETRADE_DEMO_COMMON_CompareSideMon(u8 *work, u8 *outSame, u8 *outFlag, struct MyStatus *key, int enemy);
void POKETRADE_DEMO_COMMON_ShowUnitActor(void *work);
void POKETRADE_DEMO_COMMON_LoadUnitResources(void *work);
void POKETRADE_DEMO_COMMON_ReleaseUnit(void *work);
int POKETRADE_DEMO_COMMON_PassThrough(int value);
void POKETRADE_DEMO_COMMON_SetFrame(u8 *work, u32 frame);
void POKETRADE_DEMO_COMMON_SetFinishFlag(u8 *work);
void POKETRADE_DEMO_COMMON_StepCompareMons(u8 *work);
void POKETRADE_DEMO_COMMON_StepWaitSync(u8 *work);
void POKETRADE_DEMO_COMMON_StepStartSlides(u8 *work);
void POKETRADE_DEMO_COMMON_StepBeginPlayback(u8 *work);
/* END mkheaders: generated region */

#endif

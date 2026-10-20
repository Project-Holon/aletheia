#ifndef GAME_OV118_POKEMONTRADE_DEMO_DOWN_H
#define GAME_OV118_POKEMONTRADE_DEMO_DOWN_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of pokemontrade_demo_down.c, prototypes copied from their definitions. */

#include "../types.h"

void POKETRADE_DEMO_DOWN_StepSetup(u8 *work);
void POKETRADE_DEMO_DOWN_StepSetupParticles(u8 *work);
void POKETRADE_DEMO_DOWN_StepPlaySe(u8 *work);
void POKETRADE_DEMO_DOWN_UpdateScene(u8 *work);
void POKETRADE_DEMO_DOWN_StepFade(s8 *fade);
void POKETRADE_DEMO_DOWN_CompareSideMon(u8 *work, u8 *outSame, u8 *outFlag, u32 key, int enemy);
void POKETRADE_DEMO_DOWN_CreateUnitActor(void *work);
void POKETRADE_DEMO_DOWN_LoadUnitResources(void *work);
void POKETRADE_DEMO_DOWN_ReleaseUnit(void *work);
int POKETRADE_DEMO_DOWN_PassThrough(int value);
void POKETRADE_DEMO_DOWN_SetFrame(u8 *work, u32 frame);
void POKETRADE_DEMO_DOWN_SetFinishFlag(u8 *work);
void POKETRADE_DEMO_DOWN_StepStartPlayback(u8 *work);
void POKETRADE_DEMO_DOWN_StepWaitSync(u8 *work);
/* END mkheaders: generated region */

#endif

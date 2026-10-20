#ifndef GAME_OV117_POKEMONTRADE_IRCDEMO_H
#define GAME_OV117_POKEMONTRADE_IRCDEMO_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of pokemontrade_ircdemo.c, prototypes copied from their definitions. */

#include "../types.h"

void POKETRADE_IRCDEMO_StepStartPlayback(u8 *p);
void POKETRADE_IRCDEMO_PrintMessage(u8 *p);
void POKETRADE_IRCDEMO_StepMessage(u8 *p);
void POKETRADE_IRCDEMO_StepEndScene(void *p);
void POKETRADE_IRCDEMO_SetMonSlide(void *obj, void *p);
void POKETRADE_IRCDEMO_CreateOfferSlide(u8 *p, int idx);
void POKETRADE_IRCDEMO_StepStartCompare(u8 *p);
void POKETRADE_IRCDEMO_StepSetup(u8 *p);
void POKETRADE_IRCDEMO_UpdateScene(u8 *p);
/* END mkheaders: generated region */

#endif

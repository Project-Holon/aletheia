#ifndef GAME_OV117_POKEMONTRADE_IRCDEMO_H
#define GAME_OV117_POKEMONTRADE_IRCDEMO_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of pokemontrade_ircdemo.c, prototypes copied from their definitions. */

#include "../ov119/pokemontrade_types.h"

void POKETRADE_IRCDEMO_StepStartPlayback(TradeWork *p);
void POKETRADE_IRCDEMO_PrintMessage(TradeWork *p);
void POKETRADE_IRCDEMO_StepMessage(TradeWork *p);
void POKETRADE_IRCDEMO_StepEndScene(TradeWork *p);
void POKETRADE_IRCDEMO_SetMonSlide(void *obj, TradeWork *p);
void POKETRADE_IRCDEMO_CreateOfferSlide(TradeWork *p, int idx);
void POKETRADE_IRCDEMO_StepStartCompare(TradeWork *p);
void POKETRADE_IRCDEMO_StepSetup(TradeWork *p);
void POKETRADE_IRCDEMO_UpdateScene(TradeWork *p);
/* END mkheaders: generated region */

#endif

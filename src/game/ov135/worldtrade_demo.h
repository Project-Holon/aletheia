#ifndef GAME_OV135_WORLDTRADE_DEMO_H
#define GAME_OV135_WORLDTRADE_DEMO_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of worldtrade_demo.c, prototypes copied from their definitions. */

#include "../ov135/worldtrade_types.h"

int WORLDTRADE_DEMO_Init(WorldtradeWork *p);
int WORLDTRADE_DEMO_EvolveStep(WorldtradeWork *p);
int WORLDTRADE_DEMO_Exit(WorldtradeWork *p);
TradePartnerInfo *WORLDTRADE_DEMO_CreateMyStatusFromEntry(WorldtradeEntry *ent);
WorldtradeEntry *WORLDTRADE_DEMO_GetSlotRecord(WorldtradeWork *p, int kind);
void WORLDTRADE_DEMO_InitSlotRecord(WorldtradeWork *p);
/* END mkheaders: generated region */

#endif

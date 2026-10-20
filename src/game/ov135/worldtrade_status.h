#ifndef GAME_OV135_WORLDTRADE_STATUS_H
#define GAME_OV135_WORLDTRADE_STATUS_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of worldtrade_status.c, prototypes copied from their definitions. */

#include "../ov135/worldtrade_types.h"
#include "../types.h"

void WORLDTRADE_STATUS_Open(WorldtradeWork *p);
u32 WORLDTRADE_STATUS_WaitIdle(WorldtradeWork *p);
u32 WORLDTRADE_STATUS_Close(WorldtradeWork *p);
/* END mkheaders: generated region */

#endif

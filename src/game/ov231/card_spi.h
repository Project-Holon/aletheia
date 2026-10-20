#ifndef GAME_OV231_CARD_SPI_H
#define GAME_OV231_CARD_SPI_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of card_spi.c, prototypes copied from their definitions. */

#include "../types.h"

int CARD_SPI_RunCommand(void);
void CARD_SPI_WaitNotBusy(void);
void CARD_SPI_SetControl(u16 v);
int CARD_SPI_CheckCardId(void);
/* END mkheaders: generated region */

#endif

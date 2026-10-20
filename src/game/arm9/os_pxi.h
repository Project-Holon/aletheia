#ifndef GAME_ARM9_OS_PXI_H
#define GAME_ARM9_OS_PXI_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of os_pxi.c, prototypes copied from their definitions. */

#include "../types.h"

BOOL OS_IsResetOccurred(void);
void OSi_CommonCallback(int tag, u32 data, BOOL err);
void OSi_SendToPxi(u16 data);
/* END mkheaders: generated region */

#endif

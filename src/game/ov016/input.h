#ifndef GAME_OV016_INPUT_H
#define GAME_OV016_INPUT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of input.c, prototypes copied from their definitions. */

#include "../types.h"
#include "../ov016/dwcutil_types.h"

void DWCi_IPTlInit(void);
void DWCi_IPTlEnd(void);
void DWCi_IPTlUpdate(void);
int DWCi_IPTlCheckTrigger(unsigned int f);
int DWCi_IPTlCheckRepeat(unsigned int f);
int DWCi_IPTlCheckRelease(unsigned int f);
int DWCi_TPlCheck(u16 *a);
int DWCi_TPlCheckTrigger(u16 *a);
int DWCi_TPlCheckRepeat(u16 *a);
int DWCi_TPlCheckRelease(u16 *a);
int DWCi_TPlCheckATrigger(const AREA *a);
int DWCi_TPlGet(COORD *c);
void DWCi_IPTlCheckFold(void);
/* END mkheaders: generated region */

#endif

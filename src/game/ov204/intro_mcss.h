#ifndef GAME_OV204_INTRO_MCSS_H
#define GAME_OV204_INTRO_MCSS_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of intro_mcss.c, prototypes copied from their definitions. */

#include "../types.h"

void *INTRO_MCSS_Create(unsigned int heap, int kind);
void INTRO_MCSS_Delete(u8 *p);
void INTRO_MCSS_Main(u8 *p);
void INTRO_MCSS_AddSlot(char *p, unsigned int a, unsigned int b, unsigned int c, void *d, unsigned char i);
/* END mkheaders: generated region */

#endif

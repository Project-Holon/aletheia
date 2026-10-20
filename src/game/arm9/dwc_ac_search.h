#ifndef GAME_ARM9_DWC_AC_SEARCH_H
#define GAME_ARM9_DWC_AC_SEARCH_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of dwc_ac_search.c, prototypes copied from their definitions. */

#include "../types.h"

u8 DWCi_AC_SearchAP(void);
void DWCi_AC_SetStealthChannel(unsigned short channel);
void DWCi_AC_SearchReStart(u8 phase);
s8 GetStartChannel(int lap);
s8 GetNextAroundChannel(s8 now_ch);
s8 GetNextStealthChannel(void);
/* END mkheaders: generated region */

#endif

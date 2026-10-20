#ifndef GAME_ARM9_DWC_AC_ERROR_H
#define GAME_ARM9_DWC_AC_ERROR_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of dwc_ac_error.c, prototypes copied from their definitions. */

#include "../types.h"

u8 DWCi_AC_Error(void);
int DWCi_AC_GetResult(void);
int GetProgramaError(int err);
int GetIrregularError(void);
/* END mkheaders: generated region */

#endif

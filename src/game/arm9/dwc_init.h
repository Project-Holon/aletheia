#ifndef GAME_ARM9_DWC_INIT_H
#define GAME_ARM9_DWC_INIT_H

#include "../arm9/dwc_memfunc.h"

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of dwc_init.c, prototypes copied from their definitions. */

#include "../types.h"
#include "../arm9/dwc_memfunc.h"
#include "../arm9/dwc_memfunc.h"

int DWC_InitForProduction(const char *gameName, u32 gameCode, DWCiMemAlloc alloc, DWCiMemFree free);
int DWCi_Init(int authserver, const char *gameName, u32 gameCode, DWCiMemAlloc alloc, DWCiMemFree free);
u32 DWCi_GetGamecode(void);
void DWCi_Np_SetInitFlag(int initialized);
/* END mkheaders: generated region */

#endif

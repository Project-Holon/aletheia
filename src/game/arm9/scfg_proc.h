#ifndef GAME_ARM9_SCFG_PROC_H
#define GAME_ARM9_SCFG_PROC_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of scfg_proc.c, prototypes copied from their definitions. */

#include "../types.h"

void SCFG_Init(void);
void SCFG_SetCpuSpeed(int cpuSpeed);
void SCFGi_CommonCallback(int tag, u32 pxiData, BOOL err);
/* END mkheaders: generated region */

#endif

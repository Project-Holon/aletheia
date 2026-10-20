#ifndef GAME_ARM9_FS_API_H
#define GAME_ARM9_FS_API_H

#include "../arm9/fx_mtx22.h"

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of fs_api.c, prototypes copied from their definitions. */

#include "../sdk_fx.h"

void FS_Init(unsigned long default_dma_no);
int FS_IsAvailable(void);
void MTX_Identity22_(MtxFx22 *pDst);
/* END mkheaders: generated region */

#endif

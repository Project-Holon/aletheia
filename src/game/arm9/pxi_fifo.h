#ifndef GAME_ARM9_PXI_FIFO_H
#define GAME_ARM9_PXI_FIFO_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of pxi_fifo.c, prototypes copied from their definitions. */

#include "../types.h"

void PXI_Init(void);
void PXI_InitFifo(void);
BOOL PXI_IsCallbackReady(int fifotag, int proc);
int PXI_SendWordByFifo(int fifotag, u32 data, BOOL err);
void PXIi_HandlerRecvFifoNotEmpty(void);
/* END mkheaders: generated region */

#endif

#ifndef GAME_ARM9_DOUBLE3DDISP_H
#define GAME_ARM9_DOUBLE3DDISP_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of double3Ddisp.c, prototypes copied from their definitions. */

#include "../types.h"

void DOUBLE3DDISP_Init(u32 heap);
void DOUBLE3DDISP_InitOam(void);
int DOUBLE3DDISP_Exit(void);
u32 DOUBLE3DDISP_GetMode(void);
void DOUBLE3DDISP_SetDrawDone(void);
void DOUBLE3DDISP_Delete(void);
void DOUBLE3DDISP_SetupGraphics(void);
void DOUBLE3DDISP_SetupGraphicsSubObj(void);
/* END mkheaders: generated region */

#endif

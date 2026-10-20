#ifndef GAME_ARM9_GX_LOAD3D_H
#define GAME_ARM9_GX_LOAD3D_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of gx_load3d.c, prototypes copied from their definitions. */

#include "../types.h"

void GX_BeginLoadTex(void);
void GX_LoadTex(void *pSrc, u32 destSlotAddr, u32 szByte);
void GX_EndLoadTex(void);
void GX_BeginLoadTexPltt(void);
void GX_LoadTexPltt(void *pSrc, u32 destSlotAddr, u32 szByte);
void GX_EndLoadTexPltt(void);
void GX_BeginLoadClearImage(void);
void GX_LoadClearImageColor(void *pSrc, u32 szByte);
void GX_LoadClearImageDepth(void *pSrc, u32 szByte);
void GX_EndLoadClearImage(void);
/* END mkheaders: generated region */

#endif

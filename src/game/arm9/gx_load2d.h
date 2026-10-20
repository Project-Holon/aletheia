#ifndef GAME_ARM9_GX_LOAD2D_H
#define GAME_ARM9_GX_LOAD2D_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of gx_load2d.c, prototypes copied from their definitions. */

#include "../types.h"

void GX_LoadBGPltt(const void *pSrc, u32 offset, u32 szByte);
void GXS_LoadBGPltt(const void *pSrc, u32 offset, u32 szByte);
void GX_LoadOBJPltt(const void *pSrc, u32 offset, u32 szByte);
void GXS_LoadOBJPltt(const void *pSrc, u32 offset, u32 szByte);
void GX_LoadOAM(const void *pSrc, u32 offset, u32 szByte);
void GXS_LoadOAM(const void *pSrc, u32 offset, u32 szByte);
void GX_LoadOBJ(const void *pSrc, u32 offset, u32 szByte);
void GXS_LoadOBJ(const void *pSrc, u32 offset, u32 szByte);
void GX_LoadBG0Scr(const void *pSrc, u32 offset, u32 szByte);
void GXS_LoadBG0Scr(const void *pSrc, u32 offset, u32 szByte);
void GX_LoadBG1Scr(const void *pSrc, u32 offset, u32 szByte);
void GXS_LoadBG1Scr(const void *pSrc, u32 offset, u32 szByte);
void GX_LoadBG2Scr(const void *pSrc, u32 offset, u32 szByte);
void GXS_LoadBG2Scr(const void *pSrc, u32 offset, u32 szByte);
void GX_LoadBG3Scr(const void *pSrc, u32 offset, u32 szByte);
void GXS_LoadBG3Scr(const void *pSrc, u32 offset, u32 szByte);
void GX_LoadBG0Char(const void *pSrc, u32 offset, u32 szByte);
void GXS_LoadBG0Char(const void *pSrc, u32 offset, u32 szByte);
void GX_LoadBG1Char(const void *pSrc, u32 offset, u32 szByte);
void GXS_LoadBG1Char(const void *pSrc, u32 offset, u32 szByte);
void GX_LoadBG2Char(const void *pSrc, u32 offset, u32 szByte);
void GXS_LoadBG2Char(const void *pSrc, u32 offset, u32 szByte);
void GX_LoadBG3Char(const void *pSrc, u32 offset, u32 szByte);
void GXS_LoadBG3Char(const void *pSrc, u32 offset, u32 szByte);
void GX_BeginLoadBGExtPltt(void);
void GX_LoadBGExtPltt(const void *pSrc, u32 destSlotAddr, u32 szByte);
void GX_EndLoadBGExtPltt(void);
void GX_BeginLoadOBJExtPltt(void);
void GX_LoadOBJExtPltt(const void *pSrc, u32 destSlotAddr, u32 szByte);
void GX_EndLoadOBJExtPltt(void);
void *GXS_BeginLoadBGExtPltt(void);
void GXS_LoadBGExtPltt(const void *pSrc, u32 destSlotAddr, u32 szByte);
void GXS_EndLoadBGExtPltt(void);
void *GXS_BeginLoadOBJExtPltt(void);
void GXS_LoadOBJExtPltt(const void *pSrc, u32 destSlotAddr, u32 szByte);
void GXS_EndLoadOBJExtPltt(void);
/* END mkheaders: generated region */

#endif

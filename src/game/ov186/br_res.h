#ifndef GAME_OV186_BR_RES_H
#define GAME_OV186_BR_RES_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of br_res.c, prototypes copied from their definitions. */

struct BrRes;

#include "../types.h"

void *BR_RES_Create(unsigned palSet,unsigned useCustomSet,u16 heapId);
void BR_RES_Delete(struct BrRes *res);
void BR_RES_LoadBgGraphics(void *unusedCtx,unsigned kind,unsigned short heapId);
void BR_RES_ApplyBgSet(void *unusedA, unsigned palSet);
void BR_RES_LoadSprite(struct BrRes *res, u32 spriteIndex, u32 heapId);
void BR_RES_ReleaseSprite(struct BrRes *res,unsigned spriteIndex);
int BR_RES_GetSprite(struct BrRes *res,unsigned spriteIndex,void *outSprite);
void BR_RES_LoadUiPalette(struct BrRes *res,unsigned screen,unsigned heapId);
void BR_RES_ReleaseUiPalette(struct BrRes *res, int screen);
void *BR_RES_GetFont(struct BrRes *res);
void *BR_RES_GetMsgData(struct BrRes *res);
void *BR_RES_GetWordSet(struct BrRes *res);
int BR_RES_GetCurrentSetParam(struct BrRes *res);
void BR_RES_SetPalSet(struct BrRes *res,int palSet);
int BR_RES_GetPalSet(struct BrRes *res);
void BR_RES_LoadFadePalettes(struct BrRes *res,void *fade,unsigned short heapId);
unsigned short BR_RES_GetPaletteFileId(unsigned palSet);
unsigned short BR_RES_GetCharFileId(unsigned palSet);
unsigned short BR_RES_GetScreenFileId(unsigned palSet);
u16 BR_RES_GetSetParam(u32 palSet);
/* END mkheaders: generated region */

#endif

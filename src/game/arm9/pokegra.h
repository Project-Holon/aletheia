#ifndef GAME_ARM9_POKEGRA_H
#define GAME_ARM9_POKEGRA_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of pokegra.c, prototypes copied from their definitions. */

#include "../types.h"
#include "../arm9/nns_g2d_res_types.h"

int POKEGRA_GetArcID(void);
s32 POKEGRA_GetCgrArcIndex(u32 arcId, u32 monsNo, u32 formNo, u32 sex, u32 rare, u32 dir, u32 egg);
s32 POKEGRA_GetCbrArcIndex(u32 arcId, u32 monsNo, u32 formNo, u32 sex, u32 rare, u32 dir, u32 egg);
s32 POKEGRA_GetPalArcIndex(u32 arcId, u32 monsNo, u32 formNo, u32 sex, u32 rare, u32 dir, u32 egg);
s32 POKEGRA_GetCelArcIndex(u32 arcId, u32 monsNo, u32 formNo, u32 sex, u32 rare, u32 dir, u32 egg);
s32 POKEGRA_GetAnmArcIndex(u32 arcId, u32 monsNo, u32 formNo, u32 sex, u32 rare, u32 dir, u32 egg);
s32 POKEGRA_GetMCelArcIndex(u32 arcId, u32 monsNo, u32 formNo, u32 sex, u32 rare, u32 dir, u32 egg);
s32 POKEGRA_GetMAnmArcIndex(u32 arcId, u32 monsNo, u32 formNo, u32 sex, u32 rare, u32 dir, u32 egg);
s32 POKEGRA_GetNcecArcIndex(u32 arcId, u32 monsNo, u32 formNo, u32 sex, u32 rare, u32 dir, u32 egg);
void POKEGRA_ConvertCharTo2D(void *charData, u32 heapId);
void POKEGRA_ConvertCharTo1D(u32 *charData, u32 heapId);
void POKEGRA_DrawSpindaSpots(NNSG2dCharacterData *charData, u32 personality);
void POKEGRA_CalcArcIndex(void *arcId, u32 monsNo, s32 formNo, s32 sex, u32 rare, u32 dir, u32 egg, u32 *outIndex, u32 *outDirOffset, u32 *outSex, u32 *outRare, u32 **outFormPalIndex, u32 isCgr);
u32 POKEGRA_GetTrainerArcID(void *isBack);
u32 POKEGRA_GetTrainerCgrArcIndex(u32 trType, u32 flags);
u32 POKEGRA_GetTrainerCbrArcIndex(u32 trType, u32 flags);
u32 POKEGRA_GetTrainerPalArcIndex(u32 trType, u32 flags);
u32 POKEGRA_GetTrainerCelArcIndex(u32 trType, u32 flags);
u32 POKEGRA_GetTrainerAnmArcIndex(u32 trType, u32 flags);
u32 POKEGRA_GetTrainerMCelArcIndex(u32 trType, u32 flags);
u32 POKEGRA_GetTrainerMAnmArcIndex(u32 trType, u32 flags);
u32 POKEGRA_GetTrainerNcecArcIndex(u32 trType, u32 flags);
void *POKEGRA_LoadCharDataPP(u32 *outCharData, void *pp, u32 dir, u16 heapId);
void *POKEGRA_LoadCharData(u32 *outCharData, u32 monsNo, u32 formNo, u32 sex, u32 rare, u32 dir, u32 egg, u32 personality, volatile u16 heapId);
void *POKEGRA_OpenHandle(u32 heapId);
int POKEGRA_RegisterPalette(u32 handle, int monsNo, int formNo, int sex, u32 rare, int dir, int egg, int drawType, unsigned short palOffset, unsigned short heapId);
u32 POKEGRA_RegisterCgr(u32 handle, u32 monsNo, u32 formNo, u32 sex, volatile u32 rare, volatile u32 dir, volatile u32 egg, volatile u32 personality, volatile u32 drawType, volatile u16 heapId);
u32 POKEGRA_RegisterCellAnim(u32 monsNo, u32 formNo, u32 sex, u32 rare, volatile u32 dir, volatile u32 egg, volatile u32 mapping, volatile u32 unusedArg, volatile u16 heapId);
int POKEGRA_RegisterPalettePP(int handle, void *pp, int dir, int drawType, unsigned short palOffset, unsigned short heapId);
int POKEGRA_RegisterCgrPP(int handle, void *pp, int dir, int drawType, unsigned short heapId);
u32 POKEGRA_RegisterCellAnimPP(void *pp, u32 dir, u32 mapping, u32 unusedArg, u16 heapId);
void *POKEGRA_OpenTrainerHandle(u32 heapId);
s32 POKEGRA_RegisterTrainerPalette(u8 *handle, u32 trType, u32 drawType, u32 palOffset, u16 heapId);
s32 POKEGRA_RegisterTrainerCgr(u8 *handle, u32 trType, u32 drawType, u32 heapId);
s32 POKEGRA_RegisterTrainerCellAnim(u32 unusedArg, u32 mapping, u32 drawType, u16 heapId);
void POKEGRA_LoadTrainerGraphics(void *handle, u32 trType, void *charDst, void *palDst, volatile u16 heapId);
/* END mkheaders: generated region */

#endif

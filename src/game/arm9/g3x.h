#ifndef GAME_ARM9_G3X_H
#define GAME_ARM9_G3X_H

#include "../sdk_gx.h"

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of g3x.c, prototypes copied from their definitions. */

#include "../types.h"
#include "../sdk_fx.h"

void G3X_Init(void);
void G3X_Reset(void);
void G3X_ClearFifo(void);
void G3X_InitMtxStack(void);
void G3X_ResetMtxStack(void);
void G3X_SetFog(BOOL enable, GXFogBlend fogMode, GXFogSlope fogSlope, int fogOffset);
int G3X_GetClipMtx(MtxFx44 *m);
int G3X_GetVectorMtx(MtxFx33 *m);
void G3X_SetEdgeColorTable(const void *src);
void G3X_SetFogTable(const void *src);
void G3X_SetClearColor(u16 rgb, int alpha, int depth, int polygonID, BOOL fog);
void G3X_InitTable(void);
int G3X_GetMtxStackLevelPV(s32 *level);
int G3X_GetMtxStackLevelPJ(s32 *level);
void G3X_SetDisp1DotDepth(fx32 w);
int G3X_GetBoxTestResult(s32 *in);
void GXi_NopClearFifo128_(void *pDest);
/* END mkheaders: generated region */

#endif

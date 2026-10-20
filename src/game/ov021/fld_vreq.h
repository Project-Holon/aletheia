#ifndef GAME_OV021_FLD_VREQ_H
#define GAME_OV021_FLD_VREQ_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of fld_vreq.c, prototypes copied from their definitions. */

struct FldVReq;
typedef struct FldVReq FldVReq;

#include "../types.h"

FldVReq *FLD_VREQ_Create(u32 heapId);
void FLD_VREQ_Delete(FldVReq *vreq);
void FLD_VREQ_VBlank(FldVReq *vreq);
void FLD_VREQ_SetBgVisible(FldVReq *vreq, int frame, u8 visible);
void FLD_VREQ_SetSubMasterBrightness(FldVReq *vreq, u8 brightness);
void FLD_VREQ_SetMainBlendAlpha(FldVReq *vreq, u32 plane1, u32 plane2, u32 ev1, u32 ev2);
void FLD_VREQ_SetMainBlendBrightnessExt(FldVReq *vreq, int plane1, int plane2, int ev1, int ev2, int brightness);
void FLD_VREQ_SetMainBlendAlphaEv(FldVReq *vreq, int ev1, int ev2);
void FLD_VREQ_SetSubBlendAlpha(FldVReq *vreq, u32 plane1, u32 plane2, u32 ev1, u32 ev2);
void FLD_VREQ_ApplyBlendNone(void *params, int isMain);
void FLD_VREQ_ApplyBlendAlpha(int *params, int isMain);
void FLD_VREQ_ApplyBlendBrightness(u32 *params, int isMain);
void FLD_VREQ_ApplyBlendControl(const int *params, int isMain);
void FLD_VREQ_ApplyBlendAlphaEv(u32 *params, int isMain);
void FLD_VREQ_ApplyChangeBlendBrightness(u32 *params, int isMain);
/* END mkheaders: generated region */

#endif

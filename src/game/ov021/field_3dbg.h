#ifndef GAME_OV021_FIELD_3DBG_H
#define GAME_OV021_FIELD_3DBG_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of field_3dbg.c, prototypes copied from their definitions. */

struct ProjectionMtx;
typedef struct ProjectionMtx ProjectionMtx;

#include "../ov021/field_3dbg_types.h"
#include "../ov021/field_3dbg_types.h"
#include "../types.h"

Field3dbgBillboard *FIELD_3DBG_CreateBillboard(const Field3dbgBillboardDesc *desc, u32 heapId);
int FIELD_3DBG_DeleteBillboard(Field3dbgBillboard *billboard);
void FIELD_3DBG_DrawBillboard(Field3dbgBillboard *billboard);
void FIELD_3DBG_ReleaseBillboardTextureVram(Field3dbgBillboard *billboard);
void FIELD_3DBG_FreeBillboardTexture(Field3dbgBillboard *billboard);
int FIELD_3DBG_LoadBillboardTexture(Field3dbgBillboard *billboard, void *archive, const Field3dbgTextureDesc *desc, u32 heapId);
void FIELD_3DBG_SetBillboardVisible(Field3dbgBillboard *billboard, u32 isVisible);
void FIELD_3DBG_SetBillboardPolygonId(Field3dbgBillboard *billboard, u8 polygonId);
void FIELD_3DBG_SetBillboardTexOffsetX(Field3dbgBillboard *billboard, fx32 texOffsetX);
void FIELD_3DBG_SetBillboardTexOffsetY(Field3dbgBillboard *billboard, fx32 texOffsetY);
void FIELD_3DBG_SetBillboardScaleX(Field3dbgBillboard *billboard, fx32 scaleX);
void FIELD_3DBG_SetBillboardScaleY(Field3dbgBillboard *billboard, fx32 scaleY);
void FIELD_3DBG_LoadTexture(Field3dbgTexture *tex, void *archive, const Field3dbgTextureDesc *desc, u32 heapId);
int FIELD_3DBG_FreeTexture(Field3dbgTexture *tex);
void FIELD_3DBG_ReleaseTextureVram(Field3dbgTexture *tex);
u32 FIELD_3DBG_IsTextureLoaded(Field3dbgTexture *tex);
void FIELD_3DBG_CalcQuadGeometry(Field3dbgQuadGeometry *out, const Field3dbgBillboard *in, const Field3dbgTexture *texture, const ProjectionMtx *proj);
void FIELD_3DBG_DrawQuad(const Field3dbgQuadGeometry *geom);
void FIELD_3DBG_SetPolygonAttr(Field3dbgBillboard *billboard);
void FIELD_3DBG_SetTextureParams(Field3dbgBillboard *billboard);
/* END mkheaders: generated region */

#endif

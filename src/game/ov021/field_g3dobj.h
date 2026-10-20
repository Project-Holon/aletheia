#ifndef GAME_OV021_FIELD_G3DOBJ_H
#define GAME_OV021_FIELD_G3DOBJ_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of field_g3dobj.c, prototypes copied from their definitions. */

#include "../ov021/field_g3dobj_types.h"
#include "../types.h"
#include "../sdk_fx.h"

FieldG3dObjCtrl *FIELD_G3DOBJ_Create(u32 heapId, u32 resCount, u32 objCount);
void FIELD_G3DOBJ_Delete(FieldG3dObjCtrl *ctrl);
void FIELD_G3DOBJ_Update(FieldG3dObjCtrl *ctrl);
void FIELD_G3DOBJ_DrawAll(FieldG3dObjCtrl *ctrl);
void FIELD_G3DOBJ_SetPalTable(FieldG3dObjCtrl *ctrl, const u8 *palTable);
u16 FIELD_G3DOBJ_AddResource(FieldG3dObjCtrl *ctrl, FieldG3dObjResDesc *desc, int mode, const u8 *palTable);
int FIELD_G3DOBJ_AddResourceDefaultPal(FieldG3dObjCtrl *ctrl, FieldG3dObjResDesc *desc, int mode);
void FIELD_G3DOBJ_DeleteResource(FieldG3dObjCtrl *ctrl, int resIdx);
u16 FIELD_G3DOBJ_AddObject(FieldG3dObjCtrl *ctrl, u16 resIdx, u16 modelIdx, VecFx32 *pos);
void FIELD_G3DOBJ_DeleteObject(FieldG3dObjCtrl *ctrl, int objIdx);
VecFx32 *FIELD_G3DOBJ_GetObjectTrans(FieldG3dObjCtrl *ctrl, int objIdx);
void FIELD_G3DOBJ_SetObjectTrans(FieldG3dObjCtrl *ctrl, int objIdx, VecFx32 *pos);
void FIELD_G3DOBJ_SetObjectHidden(FieldG3dObjCtrl *ctrl, int objIdx, int hidden);
int FIELD_G3DOBJ_IncAnimeFrame(FieldG3dObjCtrl *ctrl, int objIdx, int speed);
int FIELD_G3DOBJ_LoopAnimeFrame(FieldG3dObjCtrl *ctrl, int objIdx, int speed);
void FIELD_G3DOBJ_SetAnimeFrame(FieldG3dObjCtrl *ctrl, int objIdx, int animeIdx, s32 frame);
int FIELD_G3DOBJ_GetAnimeFrame(FieldG3dObjCtrl *ctrl, int objIdx, int animeIdx);
void FIELD_G3DOBJ_SetObjectManualDraw(FieldG3dObjCtrl *ctrl, int objIdx, int manualDraw);
void FIELD_G3DOBJ_DrawObject(FieldG3dObjCtrl *ctrl, int objIdx);
void FIELD_G3DOBJ_SetObjectRedrawFlag(FieldG3dObjCtrl *ctrl, int objIdx, int redrawFlag);
int FIELD_G3DOBJ_GetObjectRedrawFlag(FieldG3dObjCtrl *ctrl, int objIdx);
void FIELD_G3DOBJ_TransferResourceTexture(FieldG3dObjRes *res);
void FIELD_G3DOBJ_LoadResource(FieldG3dObjRes *res, int heapId, FieldG3dObjResDesc *desc, int mode, const u8 *palTable);
void FIELD_G3DOBJ_FreeResource(FieldG3dObjRes *res);
void FIELD_G3DOBJ_CreateObject(FieldG3dObj *obj, FieldG3dObjRes *res, u16 resIdx, u16 modelIdx, u32 heapId, VecFx32 *pos, int initDefaults);
void FIELD_G3DOBJ_DestroyObject(FieldG3dObj *obj, FieldG3dObjRes *res);
void FIELD_G3DOBJ_InitResDesc(FieldG3dObjResDesc *desc);
void FIELD_G3DOBJ_SetResDescModel(FieldG3dObjResDesc *desc, u32 arc, u32 file);
void FIELD_G3DOBJ_SetResDescAnimeArc(FieldG3dObjResDesc *desc, u32 arc);
void FIELD_G3DOBJ_AddResDescAnimeFile(FieldG3dObjResDesc *desc, u16 file);
/* END mkheaders: generated region */

#endif
